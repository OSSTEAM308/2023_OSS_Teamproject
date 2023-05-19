#include <stdlib.h>

// 책 관련 함수 선언
void DisplayBook();
void AddBook();
void DeleteBook();
void EditBook();
void SearchBook();
void LoanBook();
void ReturnBook();

// 회원 관련 함수 선언
void DisplayMember();
void AddMember();
void DeleteMember();
void SearchMember();

int main() 
{
    int choice;

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
            DisplayBook();
            break;
        case 2:
            AddBook();
            break;
        case 3:
            DeleteBook();
            break;
        case 4:
            EditBook();
            break;
        case 5:
            SearchBook();
            break;
        case 6:
            LoanBook();
            break;
        case 7:
            ReturnBook();
            break;
        case 8:
            DisplayMember();
            break;
        case 9:
            AddMember();
            break;
        case 10:
            DeleteMember();
            break;
        case 11:
            SearchMember();
            break;
        case 12:
            printf("Thank you for using the library management system.\n");
            exit(0);
        default:
            printf("Invalid choice. Please enter a number between 1 and 12.\n");
        }
    }

    return 0;
}

