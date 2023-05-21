#include <stdio.h>
#include <stdlib.h>
#include "Book.h"
#include "Member.h"

#define MAX_BOOKDATA 100

int main() {
    int choice;
    Book *book_data[MAX_BOOKDATA];
    Member *member_data = (Member*)calloc(1, sizeof(Member));

    while (1) {
        printf("\nLibrary Management System\n");
        printf("0. Exit\n");
        printf("1. Display book list\n");
        printf("2. Add a book\n");
        printf("3. Delete a book\n");
        printf("4. Edit a book\n");
        printf("5. Search a book\n");
        printf("6. Loan a book\n");
        printf("7. Return a book\n");
        printf("8. Savedata book\n");
        printf("9. Display member list\n");
        printf("10. Add a member\n");
        printf("11. Delete a member\n");
        printf("12. Search a member\n");
        printf("13. Savedata member\n");
        printf("Enter your choice (1-13): ");

        scanf("%d", &choice);
        printf("\n");

        if(choice == 0)
        {
            printf("Thank you for using the library management system.\n");
            break;
        }
              
        switch (choice) {
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
                SaveBookdata(book_data);
                break;
            case 9:
                DisplayMember(&member_data);
                break;
            case 10:
                AddMember(&member_data);
                break;
            case 11:
                DeleteMember(&member_data);
                break;
            case 12:
                SearchMember(&member_data);
                break;
            case 13:
                SaveMemberdata(&member_data);
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 12.\n");
                break;
        }
    }

    return 0;
}