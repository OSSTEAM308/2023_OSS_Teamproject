#ifndef BOOK_H
#define BOOK_H

#include<stdio.h>

#define LEN_TITLE 100
#define LEN_AUTHOR 100
#define LEN_DATES 100
#define LEN_PUBLISHER 100

typedef struct
{
    unsigned int no;
    char title[LEN_TITLE];
    char author[LEN_AUTHOR];
    char end_date[LEN_DATES];
    char publisher[LEN_PUBLISHER];
    int status;
}Book;

int data_num;
int idx, no;

void DisplayBook(Book ** data_book);
void AddBook(Book ** data_book);
void DeleteBook(Book ** data_book);
void ModifyBook(Book ** data_book);
void SearchBook(Book ** data_book);
void LoanBook(Book ** data_book);
void ReturnBook(Book ** data_book);
void InputBook(Book **data_book, int index);

#endif