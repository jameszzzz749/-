#include <iostream>
#include "library.h"
using namespace std;

int main()
{
    // 创建图书馆对象
    Library lib;
    int choice;

    while (true)
    {
        lib.showMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            lib.addBook();
            break;
        case 2:
            lib.showAllBooks();
            break;
        case 3:
            lib.modifyBook();
            break;
        case 4:
            lib.deleteBook();
            break;
        case 5:
            lib.borrowBook();
            break;
        case 6:
            lib.returnBook();
            break;
        case 7:
            lib.loadData();
            break;
        case 8:
            lib.saveData();
            break;
        case 0:
            cout << "系统退出，再见！" << endl;
            return 0;
        default:
            cout << "输入选项无效，请重新输入！" << endl;
        }
        cout << "\n按回车继续...";
        cin.get();
        cin.get();
    }
    return 0;
}
