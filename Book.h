#include<stdio.h>

typedef struct
{
    unsigned int no;
    char book_name[100];
    char author[100];
    char end_date[100];
    char publisher[100];
}Book;

void DisplayBook(Book * data_book);
void AddBook(Book * data_book);
void DeleteBook(Book * data_book);
void EditBook(Book * data_book);
void SearchBook(Book * data_book);
void LoanBook(Book * data_book);
void ReturnBook(Book * data_book);
