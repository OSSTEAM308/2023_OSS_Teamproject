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


    *data_member = new_member;
    printf("Member added successfully!\n");
}

void SearchMember(Member **data_member) {
    
    printf("Search Member\n");
}

void DeleteMember(Member **data_member) {
  
    printf("Delete Member\n");
}

void DisplayMember(Member **data_member) {
   
    printf("Display Member\n");
}
