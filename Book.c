#include<stdio.h>
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
                printf("%d    %s       %s  %s  %s\n",book_data[i]->no, book_data[i]->title, book_data[i]->author, book_data[i]->publisher, book_data[i]->end_date);
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

    printf("Title : ");
    fgets(book_data[idx]->title, LEN_TITLE, stdin);
    book_data[idx]->title[strlen(book_data[idx]->title) - 1] = '\0';

    printf("Author : ");
    fgets(book_data[idx]->author, LEN_AUTHOR, stdin);
    book_data[idx]->author[strlen(book_data[idx]->author) - 1] = '\0';

    printf("Publisher : ");
    fgets(book_data[idx]->publisher, LEN_PUBLISHER, stdin);
    book_data[idx]->publisher[strlen(book_data[idx]->publisher) - 1] = '\0';

    printf("Publisher : ");
    fgets(book_data[idx]->publisher, LEN_PUBLISHER, stdin);
    book_data[idx]->publisher[strlen(book_data[idx]->publisher) - 1] = '\0';

    printf("End_date : ");
    fgets(book_data[idx]->end_date, LEN_DATES, stdin);
    book_data[idx]->end_date[strlen(book_data[idx]->end_date) - 1] = '\0';

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
            printf("삭제완료\n");
        }
    }

    if(flag ==0)
        printf("없는 번호\n");
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
             printf("%d    %s       %s  %s  %s\n",book_data[i]->no, book_data[i]->title, book_data[i]->author, book_data[i]->publisher, book_data[i]->end_date);
        }
    }

    if(flag ==0)
        printf("No Data\n");
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
            (fun)
        }
    }
    if(flag == 0)
     printf("해당번호는 없는 번호입니다.\n");
}      

