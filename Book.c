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
                printf("%d    %s       %s  %s  %s\n",book_data[i]->no, book_data[i]->book_title, book_data[i]->author, book_data[i]->publisher, book_data[i]->end_date);
                flag++;
            }           
        }
    }
    printf("-> %d data\n", data_num);
}