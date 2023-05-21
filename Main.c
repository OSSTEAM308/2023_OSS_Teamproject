#include <stdio.h>
#include <stdlib.h>
#include "Book.h"
#include "Member.h"

#define MAX_BOOKDATA 100
#define MAX_MEMBERDATA 100

#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "Book.h"

#define MAX_MEMBERS 100
#define MAX_BOOKDATA 100

void loaddata(Member **data_member, Book **book_data) {
    FILE *member_file = fopen("memberdata.txt", "r");
    if (member_file == NULL) {
        printf("Error opening memberdata.txt file.\n");
        return;
    }

    int num_members = 0;
    while (!feof(member_file) && num_members < MAX_MEMBERS) {
        Member *new_member = (Member *)malloc(sizeof(Member));
        if (fscanf(member_file, "%[^,],%u\n", new_member->name, &(new_member->age)) == 2) {
            data_member[num_members] = new_member;
            num_members++;
        } else {
            free(new_member);
        }
    }

    fclose(member_file);

    FILE *book_file = fopen("bookdata.txt", "r");
    if (book_file == NULL) {
        printf("Error opening bookdata.txt file.\n");
        return;
    }

    int num_books = 0;
    while (!feof(book_file) && num_books < MAX_BOOKDATA) {
        Book *new_book = (Book *)malloc(sizeof(Book));
        if (fscanf(book_file, "%d\n", &(new_book->no)) == 1
            && fgets(new_book->title, LEN_TITLE, book_file) != NULL
            && fgets(new_book->author, LEN_AUTHOR, book_file) != NULL
            && fgets(new_book->end_date, LEN_DATES, book_file) != NULL
            && fgets(new_book->publisher, LEN_PUBLISHER, book_file) != NULL
            && fscanf(book_file, "%d\n", &(new_book->status)) == 1) {
            book_data[num_books] = new_book;
            num_books++;
        } else {
            free(new_book);
        }
    }

    fclose(book_file);

    printf("Member data loaded successfully. Total members: %d\n", num_members);
    printf("Book data loaded successfully. Total books: %d\n", num_books);
}

int main()
{
    int choice;
    Book *book_data[MAX_BOOKDATA];
    Member *member_data [MAX_MEMBERDATA];

    loaddata(member_data, book_data);

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
                DisplayMember(member_data);
                break;
            case 10:
                AddMember(member_data);
                break;
            case 11:
                DeleteMember(member_data);
                break;
            case 12:
                SearchMember(member_data);
                break;
            case 13:
                SaveMemberdata(member_data);
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 12.\n");
                break;
        }
    }
    return 0;
}