#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include "library.h"
using namespace std;

// Book类成员函数实现
void Book::setInfo(int id_, const char* name_, const char* author_, int total_, int available_)
{
    id = id_;
    strcpy(name, name_);
    strcpy(author, author_);
    total = total_;
    available = available_;
}

int Book::getId()
{
    return id;
}
char* Book::getName()
{
    return name;
}
char* Book::getAuthor()
{
    return author;
}
int Book::getTotal()
{
    return total;
}
int Book::getAvailable()
{
    return available;
}
void Book::setAvailable(int num)
{
    available = num;
}

// Library类实现
Library::Library()
{
    bookCount = 0;
}

void Library::showMenu()
{
    cout << "\n=====图书管理系统=====" << endl;
    cout << "1.新增图书" << endl;
    cout << "2.显示所有图书" << endl;
    cout << "3.修改图书" << endl;
    cout << "4.删除图书" << endl;
    cout << "5.借书" << endl;
    cout << "6.还书" << endl;
    cout << "7.加载数据" << endl;
    cout << "8.保存数据" << endl;
    cout << "0.退出系统" << endl;
    cout << "======================" << endl;
    cout << "请输入选择：";
}

int Library::findBookById(int id)
{
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].getId() == id)
        {
            return i;
        }
    }
    return -1;
}

void Library::addBook()
{
    if (bookCount >= MAX_BOOKS)
    {
        cout << "图书数量已达上限！" << endl;
        return;
    }
    int id, total;
    char name[50], author[30];
    cout << "输入图书ID：";
    cin >> id;
    cout << "输入书名：";
    cin >> name;
    cout << "输入作者：";
    cin >> author;
    cout << "输入图书总数量：";
    cin >> total;
    books[bookCount].setInfo(id, name, author, total, total);
    bookCount++;
    cout << "图书添加成功！" << endl;
}

void Library::showAllBooks()
{
    cout << "\nID\t书名\t作者\t总数\t可借" << endl;
    for (int i = 0; i < bookCount; i++)
    {
        cout << books[i].getId() << "\t"
            << books[i].getName() << "\t"
            << books[i].getAuthor() << "\t"
            << books[i].getTotal() << "\t"
            << books[i].getAvailable() << endl;
    }
}

void Library::modifyBook()
{
    int id;
    cout << "输入要修改图书ID：";
    cin >> id;
    int pos = findBookById(id);
    if (pos == -1)
    {
        cout << "未找到该图书！" << endl;
        return;
    }
    char name[50], author[30];
    int total;
    cout << "输入新书名：";
    cin >> name;
    cout << "输入新作者：";
    cin >> author;
    cout << "输入新总数：";
    cin >> total;
    books[pos].setInfo(id, name, author, total, books[pos].getAvailable());
    cout << "修改成功！" << endl;
}

void Library::deleteBook()
{
    int id;
    cout << "输入要删除图书ID：";
    cin >> id;
    int pos = findBookById(id);
    if (pos == -1)
    {
        cout << "图书不存在！" << endl;
        return;
    }
    //后面图书前移覆盖
    for (int i = pos; i < bookCount - 1; i++)
    {
        books[i] = books[i + 1];
    }
    bookCount--;
    cout << "删除成功！" << endl;
}

void Library::borrowBook()
{
    int id;
    cout << "输入借书ID：";
    cin >> id;
    int pos = findBookById(id);
    if (pos == -1)
    {
        cout << "图书不存在！" << endl;
        return;
    }
    if (books[pos].getAvailable() <= 0)
    {
        cout << "暂无可借图书！" << endl;
        return;
    }
    books[pos].setAvailable(books[pos].getAvailable() - 1);
    cout << "借书成功！" << endl;
}

void Library::returnBook()
{
    int id;
    cout << "输入还书ID：";
    cin >> id;
    int pos = findBookById(id);
    if (pos == -1)
    {
        cout << "图书不存在！" << endl;
        return;
    }
    if (books[pos].getAvailable() >= books[pos].getTotal())
    {
        cout << "无需还书！" << endl;
        return;
    }
    books[pos].setAvailable(books[pos].getAvailable() + 1);
    cout << "还书成功！" << endl;
}

void Library::loadData()
{
    ifstream fin(DATA_FILE, ios::binary);
    if (!fin.is_open())
    {
        cout << "打开文件失败！" << endl;
        return;
    }
    fin.read((char*)&bookCount, sizeof(int));
    fin.read((char*)books, sizeof(Book) * bookCount);
    fin.close();
    cout << "数据加载完成！" << endl;
}

void Library::saveData()
{
    ofstream fout(DATA_FILE, ios::binary);
    if (!fout.is_open())
    {
        cout << "文件打开失败！" << endl;
        return;
    }
    fout.write((char*)&bookCount, sizeof(int));
    fout.write((char*)books, sizeof(Book) * bookCount);
    fout.close();
    cout << "保存成功！" << endl;
}

