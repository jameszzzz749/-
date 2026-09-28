#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_BOOKS 100
#define DATA_FILE "library.dat"

// 图书结构体
struct Book
{
    int id;
    char name[50];
    char author[30];
    int total;
    int available;
};

// 函数声明
void showMenu();
void addBook();
void showAllBooks();
void modifyBook();
void deleteBook();
void borrowBook();
void returnBook();
void loadData();
void saveData();

// 辅助函数
int findBookById(int id);

#endif
