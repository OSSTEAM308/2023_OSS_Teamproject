#include <stdio.h>
#include <stdlib.h>
#include "Book.h"
#include "Member.h"

#define MAX_BOOKDATA 100

int main() 
{
    int choice;
    Book *book_data[MAX_BOOKDATA];
    Member *data_member = NULL;

    while (1) 
    {
        printf("\nLibrary Management System\n");
        printf("1. Display book list\n");
        printf("2. Add a book\n");
        printf("3. Delete a book\n");
        printf("4. Edit a book\n");
        printf("5. Search a book\n");
        printf("6. Loan a book\n");
        printf("7. Return a book\n");
        printf("8. Display member list\n");
        printf("9. Add a member\n");
        printf("10. Delete a member\n");
        printf("11. Search a member\n");
        printf("12. Exit\n");
        printf("Enter your choice (1-12): ");

        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                DisplayBook(book_data);
                break;
            case 2:
                AddBook(book_data);
                break;
            case 3:
                DeleteBook(book_data);
                break;
            case 4:
                ModifyBook(book_data);
                break;
            case 5:
                SearchBook(book_data);
                break;
            case 6:
                LoanBook(book_data);
                break;
            case 7:
                ReturnBook(book_data);
                break;
            case 8:
                DisplayMember(data_member);
                break;
            case 9:
                AddMember(&data_member);
                break;
            case 10:
                DeleteMember(&data_member);
                break;
            case 11:
                SearchMember(data_member);
                break;
            case 12:
                SaveMemberdata(data_member);
                printf("Thank you for using the library management system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 12.\n");
        }
    }

    return 0;
}



