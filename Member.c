#include "Member.h"
#include <stdio.h>
#include <string.h>

void AddMember(Member **data_member) {
    Member *new_member = (Member *)malloc(sizeof(Member));

    printf("Enter member name: ");
    fgets(new_member->name, sizeof(new_member->name), stdin);
    new_member->name[strcspn(new_member->name, "\n")] = '\0';

    printf("Enter member age: ");
    scanf("%u", &(new_member->age));
    getchar(); // Consume newline character

    // Additional code for initializing loan details or any other member-specific data
    // ...

    *data_member = new_member;
    printf("Member added successfully!\n");
}

void SearchMember(Member **data_member) {
    // Implement member search logic
    // ...
    printf("Search Member\n");
}

void DeleteMember(Member **data_member) {
    // Implement member deletion logic
    // ...
    printf("Delete Member\n");
}

void DisplayMember(Member **data_member) {
    // Implement member display logic
    // ...
    printf("Display Member\n");
}
