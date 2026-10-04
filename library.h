#ifndef LIBRARY_H
#define LIBRARY_H
#define MAX_BOOKS 100
#define DATA_FILE "library.dat"
#include <cstring>
#include <fstream>

// 图书类 Book
class Book
{
private:
    int id;
    char name[50];
    char author[30];
    int total;
    int available;
public:
    // 设置图书信息
    void setInfo(int id_, const char* name_, const char* author_, int total_, int available_);
    // 获取成员
    int getId();
    char* getName();
    char* getAuthor();
    int getTotal();
    int getAvailable();
    void setAvailable(int num);
};

// 图书馆管理类 Library
class Library
{
private:
    Book books[MAX_BOOKS];
    int bookCount;
public:
    Library();  //构造函数
    void showMenu();
    void addBook();
    void showAllBooks();
    void modifyBook();
    void deleteBook();
    void borrowBook();
    void returnBook();
    void loadData();
    void saveData();
    int findBookById(int id);
};

#endif
