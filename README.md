# 2023_OSS_Teamproject
![image](https://user-images.githubusercontent.com/126431882/236813899-379b5916-a5e6-469a-9703-97ac5ba57304.png)


### :pushpin: miniproject 주제<br>
- 도서관을 편리하게 이용할 수 있도록 도와주는 프로그램

### :pushpin: miniproject 소개<br>
- 책의 대출과 반납, 회원관리 등을 간편하게 만들어줍니다.
- 간단한 검색을 통해 이용할 수 있습니다.
- 시간 제약 없이 언제나 이용할 수 있습니다.

### :pushpin: project 에 포함시킬 대략적인 기능<br>
-데이터 저장 (txt)<br>
-책 목록보기<br> 
-책 추가<br> 
-책 삭제<br> 
-책 수정<br> 
-책 검색<br> 
-책 대출<br> 
-책 반납<br> 
-회원 목록보기<br> 
-회원 등록<br> 
-회원 삭제<br> 

### :pushpin: 프로그램 사용 함수<br>
```
// Book_function
void DisplayBook(Book ** data_book);
void AddBook(Book ** data_book);
void DeleteBook(Book ** data_book);
void ModifyBook(Book ** data_book);
void SearchBook(Book ** data_book);
void LoanBook(Book ** ,Member ** member_data);
void ReturnBook(Book ** data_book,Member **member_data);
void InputBook(Book **data_book, int index);
void SaveBook(Book **data_book);

// Member_function
void AddMember(Member **data_member);
void SearchMember(Member **data_member);
void DeleteMember(Member **data_member);
void DisplayMember(Member **data_member);
void SaveBookData(Member **data_member);
void SaveMemberData(Member **data_member); 

// Load_function
int LoadBook(Book **book_data);
int LoadMember(Member **member_data);
```

### :pushpin: 개발환경 및 언어<br>
- git/github<br>
- C / Visual Studio Code

### :pushpin: 팀소개 및 역할<br>
오택준<br>
- Repo Owner
- WIKI 관리
- 책 관련 c파일,헤더파일 구현
- 컨밴션 확인

변동현<br>
- Contributer
- main함수와 회원 관련 c파일,헤더파일 구현
- 최종 프로그램 테스트


