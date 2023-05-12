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
 
void addBook(Book ** book_data)
{
    idx++;
    data_num++;
    book_data[idx] = (Book *)malloc(sizeof(Book));
    getchar();

    printf("번호 : ");
    fgets(book_data[idx]->no, LEN_NAME, stdin);
    book_data[idx]->name[strlen(book_data[idx]->name) - 1] = '\0';

    printf("번호 : ");
    fgets(book_data[idx]->book_dataNum, LEN_book_data, stdin);
    book_data[idx]->book_dataNum[strlen(book_data[idx]->book_dataNum) - 1] = '\0';

    printf("관계 : ");
    fgets(book_data[idx]->relationship, LEN_REL, stdin);
    book_data[idx]->relationship[strlen(book_data[idx]->relationship) - 1] = '\0';

    printf("년생 : ");
    fgets(book_data[idx]->birth, LEN_BIRTH, stdin);
    book_data[idx]->birth[strlen(book_data[idx]->birth) - 1] = '\0';

    book_data[idx]->num = no++;
}

void deletebook_data(Data **book_data)
{
    readbook_data(book_data);
    int num,flag=0;
    printf("\n삭제할 번호 -> ");
    scanf("%d", &num);

    for (int i = 0; i <= idx;i++)
    {
        if(book_data[i]->num == num && book_data[i]->status != -1)
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

void searchbook_data(Data **book_data)
{
    char temp[LEN_NAME];
    printf("\n찾을 사람의 이름 -> ");
    getchar();
    fgets(temp,sizeof(temp), stdin);
    temp[strlen(temp) - 1] = '\0';
   
    printf("번호  이름      핸드폰번호  관계    년생\n");
    printf("---------------------------------------------------------------------\n");
    int flag = 0;
    for (int i = 0; i <= idx;i++)
    {
        if(strstr(book_data[i]->name,temp) && book_data[i]->status != -1)
        {
            flag++;
            printf("%d    %s       %s  %s  %s\n",book_data[i]->num, book_data[i]->name, book_data[i]->book_dataNum, book_data[i]->relationship, book_data[i]->birth);
        }
    }

    if(flag ==0)
        printf("해당 데이터를 찾을수 없습니다\n");
}
