#include<stdio.h>
#include<time.h>
#include"Book.h"

void DisplayBook(Book ** book_data)
{  
    printf("no    Title    author     publisher     end_date\n");
    printf("---------------------------------------------------------------------\n");
    int flag = 0;
    if(data_num == 0)
            printf("no Data\n");
    else
    {
        for(int i=0;i<=idx;i++)
        {
            if(book_data[i]->status != -1)
            {
                printf("%6d%9s%10s%14s%s\n",book_data[i]->no, book_data[i]->title, book_data[i]->author, book_data[i]->publisher, book_data[i]->end_date);
                flag++;
            }           
        }
    }
    printf("-> %d data\n", data_num);
}
 
void AddBook(Book ** book_data)
{
    idx++;
    data_num++;
    book_data[idx] = (Book *)malloc(sizeof(Book));
    getchar();

    InputBook(book_data,idx);
    book_data[idx]->no = no++;
}

void DeleteBook(Book **book_data)
{
    DisplayBook(book_data);

    int num,flag=0;

    printf("\nDelete No -> ");
    scanf("%d", &num);

    for (int i = 0; i <= idx;i++)
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
   
    printf("no    Title    author     publisher     end_date\n");
    printf("---------------------------------------------------------------------\n");
    int flag = 0;
    for (int i = 0; i <= idx;i++)
    {
        if(strstr(book_data[i]->title,temp) && book_data[i]->status != -1)
        {
            flag++;
            printf("%6d%9s%10s%14s%s\n",book_data[i]->no, book_data[i]->title, book_data[i]->author, book_data[i]->publisher, book_data[i]->end_date);
        }
    }

    if(flag ==0)
        printf("No data\n");
}

int ModifyBook(Book ** book_data)
{
    DisplayBook(book_data);

    int num,flag=0;
    printf("\n No? (cancel : 0) ");
    scanf("%d",&num);

    for (int i = 0; i <= idx; i++)
    {
        if(book_data[i]->no == num && book_data[i]->status != -1)
        {
            flag++;
            data_num--;
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

    printf("Publisher : ");
    fgets(book_data[index]->publisher, LEN_PUBLISHER, stdin);
    book_data[index]->publisher[strlen(book_data[index]->publisher) - 1] = '\0';

    printf("End_date : ");
    fgets(book_data[index]->end_date, LEN_DATES, stdin);
    book_data[index]->end_date[strlen(book_data[index]->end_date) - 1] = '\0';
}



void LoanBook(Book **data_book) {
    char book_name[LEN_TITLE];
    printf("Enter the book name: ");
    getchar();
    fgets(book_name, LEN_TITLE, stdin);
    book_name[strlen(book_name) - 1] = '\0';

    int flag = 0;
    for (int i = 0; i <= idx; i++) {
        if (strcmp(data_book[i]->title, book_name) == 0 && data_book[i]->status != -1) {
            flag = 1;
            time_t now = time(NULL);
            struct tm *t = localtime(&now);
            t->tm_mday += 7;
            mktime(t);
            strftime(data_book[i]->end_date, LEN_DATES, "%Y-%m-%d", t);
            printf("Book \"%s\" has been successfully borrowed. Return date: %s\n", book_name, data_book[i]->end_date);
            break;
        }
    }

    if (flag == 0)
        printf("Book \"%s\" is not available for borrowing.\n", book_name);
}

void ReturnBook(Book **data_book) {
    char book_name[LEN_TITLE];
    printf("Enter the book name to return: ");
    getchar();
    fgets(book_name, LEN_TITLE, stdin);
    book_name[strlen(book_name) - 1] = '\0';

    int flag = 0;
    for (int i = 0; i <= idx; i++) {
        if (strcmp(data_book[i]->title, book_name) == 0 && data_book[i]->status != -1) {
            flag = 1;
            data_book[i]->end_date[0] = '\0';  // Clear the end_date
            printf("Book \"%s\" has been successfully returned.\n", book_name);
            break;
        }
    }

    if (flag == 0)
        printf("Invalid input or book \"%s\" is not available for return.\n", book_name);
}