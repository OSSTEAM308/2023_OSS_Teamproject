#ifndef MEMBER_H
#define MEMBER_H

typedef struct {
    char name[100];
    unsigned int age;
    char Loan[100];
} Member;

void AddMember(Member **data_member);
void SearchMember(Member **data_member);
void DeleteMember(Member **data_member);
void DisplayMember(Member **data_member);

#endif
