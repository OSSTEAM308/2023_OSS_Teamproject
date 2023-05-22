#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"Book.h"
#include"Member.h"

void DisplayBook(Book ** book_data)
{  
    printf("no    Title             Author     Publisher     End_date     Name(loaned)\n");
    printf("---------------------------------------------------------------------\n");
    int flag = 0;
    if(data_num == 0)
            printf("no Data\n");
    else
    {
        for(int i=0;i<=idx_book-1;i++)
        {
            if(book_data[i]->status != -1)
            {
                printf("%-6d%-18s%-11s%-14s%-13s%s\n",book_data[i]->no, book_data[i]->title, book_data[i]->author, book_data[i]->publisher, book_data[i]->end_date,book_data[i]->name);
                flag++;
            }           
        }
    }
    printf("-> %d data\n", data_num);
}
 
void AddBook(Book ** book_data)
{
    book_data[idx_book] = (Book *)malloc(sizeof(Book));
    getchar();
    strcpy(book_data[idx_book]->name, "");

    InputBook(book_data,idx_book);
    book_data[idx_book]->no = ++no;
    idx_book++;
    data_num++;
}

void DeleteBook(Book **book_data)
{
    DisplayBook(book_data);

    int num,flag=0;

    printf("\nDelete No (cancel 0)-> ");
    scanf("%d", &num);

    if(num == 0)
    {
        printf("Cancel\n");
        return;
    }

    for (int i = 0; i <= idx_book-1;i++)
    {
        if(book_data[i]->no == num && book_data[i]->status != -1)
        {
            flag++;
            book_data[i]->status = -1;
            data_num--;
            printf("Delete\n");
        }
    }

    if(flag ==0)
        printf("No data\n");
}

void SearchBook(Book **book_data)
{
    char temp[LEN_TITLE];
    printf("\nBook title -> ");
    getchar();
    fgets(temp,sizeof(temp), stdin);
    temp[strlen(temp) - 1] = '\0';
   
    printf("no    Title             Author     Publisher     End_date     Name(loaned)\n");
    printf("---------------------------------------------------------------------\n");
    int flag = 0;
    for (int i = 0; i <= idx_book-1;i++)
    {
        if(strstr(book_data[i]->title,temp) && book_data[i]->status != -1)
        {
            flag++;
            printf("%-6d%-18s%-11s%-14s%-13s%s\n",book_data[i]->no, book_data[i]->title, book_data[i]->author, book_data[i]->publisher, book_data[i]->end_date,book_data[i]->name);
        }
    }

    if(flag ==0)
        printf("No data\n");
}

void ModifyBook(Book ** book_data)
{
    DisplayBook(book_data);

    int num,flag=0;
    printf("\nNo? (cancel : 0) : ");
    scanf("%d",&num);
    getchar();
    //strcpy(book_data[idx]->name, "");

    if(num == 0)
    {
        printf("Cancel\n");
        return;
    }
    
    for (int i = 0; i <= idx_book-1; i++)
    {
        if((book_data[i]->no == num) && (book_data[i]->status != -1))
        {
            flag++;
            InputBook(book_data, i);
            break;
        }
    }
    if(flag == 0)
     printf("No data\n");
}      

void InputBook(Book ** book_data,int index)
{
    printf("Title : ");
    fgets(book_data[index]->title, LEN_TITLE, stdin);
    book_data[index]->title[strlen(book_data[index]->title) - 1] = '\0';

    printf("Author : ");
    fgets(book_data[index]->author, LEN_AUTHOR, stdin);
    book_data[index]->author[strlen(book_data[index]->author) - 1] = '\0';

    printf("Publisher : ");
    fgets(book_data[index]->publisher, LEN_PUBLISHER, stdin);
    book_data[index]->publisher[strlen(book_data[index]->publisher) - 1] = '\0';
}

void LoanBook(Book **data_book,Member **member_data) 
{
    char book_name[LEN_TITLE];
    printf("Enter the book name: ");
    getchar();
    fgets(book_name, LEN_TITLE, stdin);
    book_name[strlen(book_name) - 1] = '\0';

    int flag = 0;
    int member_idx = -1;  
    for (int i = 0; i <= idx_book-1; i++)
    {
        if (strcmp(data_book[i]->title, book_name) == 0 && data_book[i]->status != -1) {
            flag = 1;

            if((strlen(data_book[i]->end_date) > 1))
            {
                printf("Book already Loan\n");
                return;
            }
            
            char member_name[100];
            printf("Enter the name of the borrowing user: ");
            fgets(member_name, 100, stdin);
            member_name[strlen(member_name) - 1] = '\0';
            
            for (int j = 0; j < idx_member; j++) 
            {
                if (strcmp(member_data[j]->name, member_name) == 0) {
                    member_idx = j;
                    break;
                }
            }

            if (member_idx == -1) 
            {
                printf("Member \"%s\" does not exist. Unable to borrow the book.\n", member_name);
                return;  
            }

            strcpy(member_data[member_idx]->loan,data_book[i]->title);
            strcpy(data_book[i]->name, member_data[member_idx]->name);

            time_t now = time(NULL);
            struct tm *t = localtime(&now);
            t->tm_mday += 7;
            mktime(t);
            strftime(data_book[i]->end_date, LEN_DATES, "%Y-%m-%d", t);
            printf("Book \"%s\" has been successfully borrowed by %s. Return date: %s\n", book_name, member_name, data_book[i]->end_date);
            break;
        }
    }
    if (flag == 0)
        printf("Book \"%s\" is not available for borrowing.\n", book_name);
}

void ReturnBook(Book **data_book,Member **member_data)
{
    char book_name[LEN_TITLE];
    printf("Enter the book name to return: ");
    getchar();
    fgets(book_name, LEN_TITLE, stdin);
    book_name[strlen(book_name) - 1] = '\0';

    int flag = 0;
    for (int i = 0; i <= idx_book-1; i++) 
    {
        if (strcmp(data_book[i]->title, book_name) == 0 && data_book[i]->status != -1 && strlen(data_book[i]->end_date) > 2) 
        {
            flag = 1;
            data_book[i]->end_date[0] = '\0';  // Clear  end_date
            data_book[i]->name[0] = '\0';
             for (int j = 0; j < idx_member; j++) 
             {
                if (strcmp(member_data[j]->loan, book_name) == 0) 
                {
                    member_data[j]->loan[0] = '\0';
                    break;
                }
            }
            printf("Book \"%s\" has been successfully returned.\n", book_name);
            break;
        }
    }
    if (flag == 0)
        printf("Invalid input or book \"%s\" is not available for return.\n", book_name);
}


void SaveBook(Book **data_book)
{
    FILE *file = fopen(BOOK_FILENAME, "w");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < idx_book; i++)
    {
        if (data_book[i]->status != -1)
        {
            fprintf(file, "%d ", data_book[i]->no);
            fprintf(file, "%s ", data_book[i]->title);
            fprintf(file, "%s ", data_book[i]->author);
            fprintf(file, "%s ", data_book[i]->publisher);
            if(strlen(data_book[i]->end_date) < 1)
            {
                fprintf(file, "x ", data_book[i]->end_date);
                fprintf(file, "x\n", data_book[i]->name);
            }
            else
            {
                fprintf(file, "%s ", data_book[i]->end_date);
                fprintf(file, "%s\n", data_book[i]->name);
            }
        }
    }
    fclose(file);
    printf("Data saved successfully.\n");
}
