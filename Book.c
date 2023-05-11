#include<stdio.h>
#include"Book.h"


void DisplayBook(Book ** book_data)
{
    printf("번호  이름      핸드폰번호  관계    년생\n");
    printf("---------------------------------------------------------------------\n");
    int flag = 0;
    if(data_num == 0)
            printf("no Data\n");
    else
    {
        for(int i=0;i<=idx;i++)
        {
            if(phone[i]->status != -1)
            {
                printf("%d    %s       %s  %s  %s\n",phone[i]->num, phone[i]->name, phone[i]->phoneNum, phone[i]->relationship, phone[i]->birth);
                flag++;
            }           
        }
    }
    printf("-> %d data\n", data_num);
}