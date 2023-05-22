#ifndef BOOK_H
#define BOOK_H

#include<stdio.h>
#include"Member.h"

#define LEN_TITLE 100
#define LEN_AUTHOR 100
#define LEN_DATES 100
#define LEN_PUBLISHER 100
#define LEN_NAME 100
#define BOOK_FILENAME "Book.txt"

typedef struct
{
    unsigned int no;
    char title[LEN_TITLE];
    char author[LEN_AUTHOR];
    char end_date[LEN_DATES];
    char publisher[LEN_PUBLISHER];
    char name[LEN_NAME];
    int status;
}Book;

int data_num;
int idx_book, no;

void DisplayBook(Book ** data_book);
void AddBook(Book ** data_book);
void DeleteBook(Book ** data_book);
void ModifyBook(Book ** data_book);
void SearchBook(Book ** data_book);
void LoanBook(Book ** ,Member ** member_data);
void ReturnBook(Book ** data_book,Member **member_data);
void InputBook(Book **data_book, int index);
void SaveBook(Book **data_book);

#endif
