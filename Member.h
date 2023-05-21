#ifndef MEMBER_H
#define MEMBER_H

#include<stdio.h>
#define MEMBER_FILENAME "Member.txt"

typedef struct {
    char name[100];
    unsigned int age;
    char Loan[100];
    int status;
} Member;

int num_members;

void AddMember(Member **data_member);
void SearchMember(Member **data_member);
void DeleteMember(Member **data_member);
void DisplayMember(Member **data_member);
void SaveBookData(Member **data_member);
void SaveMemberData(Member **data_member);

#endif