#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include "library.h"
using namespace std;

static Book books[MAX_BOOKS];
static int bookCount = 0;

int findBookById(int id)
{
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void showMenu()
{
    cout << "========== 图书馆管理系统 ==========\n";
    cout << "          1. 添加图书\n";
    cout << "          2. 显示所有图书\n";
    cout << "          3. 修改图书信息\n";
    cout << "          4. 删除图书\n";
    cout << "          5. 借书\n";
    cout << "          6. 还书\n";
    cout << "          7. 退出系统\n";
    cout << "====================================\n";
}

void addBook()
{
    if (bookCount >= MAX_BOOKS)
    {
        cout << "图书库已满，无法添加更多图书！\n";
        return;
    }

    Book b;
    cout << "请输入图书编号：";
    cin >> b.id;

    if (findBookById(b.id) != -1)
    {
        cout << "该编号的图书已存在！\n";
        return;
    }

    cout << "请输入书名：";
    cin >> b.name;
    cout << "请输入作者：";
    cin >> b.author;
    cout << "请输入总数量：";
    cin >> b.total;
    b.available = b.total;

    books[bookCount++] = b;
    saveData();
    cout << "图书添加成功！\n";
}

void showAllBooks()
{
    if (bookCount == 0)
    {
        cout << "当前书库暂无图书！\n";
        return;
    }

    cout << "\n编号\t书名\t\t作者\t总数\t可借\n";
    cout << "---------------------------------------------\n";
    for (int i = 0; i < bookCount; i++)
    {
        cout << books[i].id << "\t"
            << books[i].name << "\t\t"
            << books[i].author << "\t"
            << books[i].total << "\t"
            << books[i].available << endl;
    }
}

void modifyBook()
{
    int id;
    cout << "请输入要修改的图书编号：";
    cin >> id;

    int index = findBookById(id);
    if (index == -1)
    {
        cout << "未找到对应编号的图书！\n";
        return;
    }

    cout << "当前信息：书名=" << books[index].name
        << "  作者=" << books[index].author
        << "  总数=" << books[index].total << endl;

    cout << "请输入新书名：";
    cin >> books[index].name;
    cout << "请输入新作者：";
    cin >> books[index].author;
    cout << "请输入新总数量：";
    cin >> books[index].total;

    if (books[index].available > books[index].total)
    {
        books[index].available = books[index].total;
    }
    saveData();
    cout << "图书信息修改成功！\n";
}

void deleteBook()
{
    int id;
    cout << "请输入要删除的图书编号：";
    cin >> id;

    int index = findBookById(id);
    if (index == -1)
    {
        cout << "未找到对应编号的图书！\n";
        return;
    }

    // 数组前移覆盖
    for (int i = index; i < bookCount - 1; i++)
    {
        books[i] = books[i + 1];
    }
    bookCount--;
    saveData();
    cout << "图书删除成功！\n";
}

void borrowBook()
{
    int id;
    cout << "请输入要借阅的图书编号：";
    cin >> id;

    int index = findBookById(id);
    if (index == -1)
    {
        cout << "未找到对应编号的图书！\n";
        return;
    }

    if (books[index].available <= 0)
    {
        cout << "抱歉，该书已全部借出，暂无库存！\n";
        return;
    }

    books[index].available--;
    saveData();
    cout << "借书成功！《" << books[index].name << "》剩余可借 " << books[index].available << " 本\n";
}

void returnBook()
{
    int id;
    cout << "请输入要归还的图书编号：";
    cin >> id;

    int index = findBookById(id);
    if (index == -1)
    {
        cout << "未找到对应编号的图书！\n";
        return;
    }

    if (books[index].available >= books[index].total)
    {
        cout << "该书已全部归还，无需重复操作！\n";
        return;
    }

    books[index].available++;
    saveData();
    cout << "还书成功！《" << books[index].name << "》当前可借 " << books[index].available << " 本\n";
}

// 保存二进制文件
void saveData()
{
    ofstream ofs(DATA_FILE, ios::binary);
    if (!ofs.is_open())
    {
        cout << "保存数据文件失败！\n";
        return;
    }
    ofs.write((char*)&bookCount, sizeof(int));
    ofs.write((char*)books, sizeof(Book) * bookCount);
    ofs.close();
}

// 加载二进制文件
void loadData()
{
    ifstream ifs(DATA_FILE, ios::binary);
    if (!ifs.is_open())
    {
        return;
    }
    ifs.read((char*)&bookCount, sizeof(int));
    ifs.read((char*)books, sizeof(Book) * bookCount);
    ifs.close();
}
