#include "Member.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100

void AddMember(Member **data_member) {
    if (num_members >= MAX_MEMBERS) {
        printf("Maximum number of members reached.\n");
        return;
    }
    
    Member *new_member = (Member *)malloc(sizeof(Member));
    
    printf("Enter member name: ");
    fgets(new_member->name, sizeof(new_member->name), stdin);
    new_member->name[strcspn(new_member->name, "\n")] = '\0';
    
    printf("Enter member age: ");
    scanf("%u", &(new_member->age));
    getchar(); // Consume newline character
    
    *data_member = new_member;
    num_members++;
    
    printf("Member added successfully!\n");
}

void SearchMember(Member **data_member) {
    char search_name[100];
    
    printf("Enter member name to search: ");
    fgets(search_name, sizeof(search_name), stdin);
    search_name[strcspn(search_name, "\n")] = '\0';
    
    int found = 0;
    for (int i = 0; i < num_members; i++) {
        if (strcmp((*data_member)->name, search_name) == 0) {
            printf("Member found:\n");
            printf("Name: %s\n", (*data_member)->name);
            printf("Age: %u\n", (*data_member)->age);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Member not found.\n");
    }
}

void DeleteMember(Member **data_member) {
    char delete_name[100];
    
    printf("Enter member name to delete: ");
    fgets(delete_name, sizeof(delete_name), stdin);
    delete_name[strcspn(delete_name, "\n")] = '\0';
    
    int found = 0;
    for (int i = 0; i < num_members; i++) {
        if (strcmp((*data_member)->name, delete_name) == 0) {
            free(*data_member);
            *data_member = NULL;
            found = 1;
            num_members--;
            printf("Member deleted successfully.\n");
            break;
        }
    }
    
    if (!found) {
        printf("Member not found.\n");
    }
}

void DisplayMember(Member **data_member) {
    printf("Member List:\n");
    printf("-------------------------------\n");
    printf("Name\t\tAge\n");
    printf("-------------------------------\n");
    
    for (int i = 0; i < num_members; i++) {
        printf("%s\t\t%u\n", (*data_member)->name, (*data_member)->age);
    }
    
    printf("-------------------------------\n");
}
