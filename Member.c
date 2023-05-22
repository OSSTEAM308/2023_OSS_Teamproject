#include "Member.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100

void AddMember(Member **data_member)
 {
    if (num_members >= MAX_MEMBERS) 
    {
        printf("Maximum number of members reached.\n");
        return;
    }
    
    getchar();
    Member *new_member = (Member *)malloc(sizeof(Member));
    
    printf("Enter member name: ");
    fgets(new_member->name, sizeof(new_member->name), stdin);
    new_member->name[strcspn(new_member->name, "\n")] = '\0';
    
    printf("Enter member age: ");
    scanf("%u", &(new_member->age));
    getchar(); // Consume newline character
    
    data_member[num_members] = new_member;
    num_members++;

    printf("Member added successfully!\n");
}

void SearchMember(Member **data_member) 
{
    char search_name[100];
    
    printf("Enter member name to search: ");
    getchar();
    fgets(search_name, sizeof(search_name), stdin);
    search_name[strlen(search_name) - 1] = '\0';

    int found = 0;

    for (int i = 0; i < num_members; i++) 
    {
        if(strstr(data_member[i]->name,search_name) && data_member[i]->status != -1)
        {
            printf("Member found\n");
            printf("Name: %s ", data_member[i]->name);
            printf("Age: %u ", data_member[i]->age);
            printf("Loaned book: %s \n", data_member[i]->loan);
            found = 1;
            break;
        }
    }
    
    if (!found) 
        printf("Member not found.\n");
}

void DeleteMember(Member **data_member)
{
    char delete_name[100];
    getchar();

    printf("Enter member name to delete: ");
    fgets(delete_name, sizeof(delete_name), stdin);
    delete_name[strcspn(delete_name, "\n")] = '\0';
    
    int found = 0;
    for (int i = 0; i < num_members; i++)
    {
        if (strcmp((data_member[i])->name, delete_name) == 0) 
        {
            data_member[i]->status = -1;
            found = 1;
            printf("Member deleted successfully.\n");
            break;
        }
    }
    
    if (!found) 
        printf("Member not found.\n");
}

void DisplayMember(Member **data_member)
{
    printf("Member List:\n");
    printf("--------------------------------------------------------------\n");
    printf("Name\t\tAge\t\tbooks on loan\n");
    printf("--------------------------------------------------------------\n");
    
    for (int i = 0; i < num_members; i++) 
    {
        if(data_member[i]->status != -1)
            printf("%s\t\t%u\t\t%s\n", data_member[i]->name, data_member[i]->age,data_member[i]->loan);
    }
    
    printf("--------------------------------------------------------------\n");
}

void SaveMemberData(Member **data_member) 
{
    FILE *file = fopen(MEMBER_FILENAME, "w");
    if (file == NULL) 
    {
        printf("Error opening file.\n");
        return;
    }
    
    for (int i = 0; i < num_members; i++) 
    {
        if(data_member[i]->status != -1)
        {
            fprintf(file, "%s %u ", data_member[i]->name, data_member[i]->age);
            if(strlen(data_member[i]->loan) < 1)
                fprintf(file, "x\n");
            else
                fprintf(file, "%s\n", data_member[i]->loan);
        }
            
    }
    fclose(file);
    printf("Member data saved successfully.\n");
}