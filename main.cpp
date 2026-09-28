#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include "library.h"
using namespace std;

int main()
{
    system("chcp 936 >nul");  // VS控制台简体中文GBK，解决乱码
    loadData();
    int choice;

    while (true)
    {
        showMenu();
        cout << "请输入您的选择：";
        cin >> choice;

        switch (choice)
        {
        case 1: addBook(); break;
        case 2: showAllBooks(); break;
        case 3: modifyBook(); break;
        case 4: deleteBook(); break;
        case 5: borrowBook(); break;
        case 6: returnBook(); break;
        case 7:
            saveData();
            cout << "数据已保存，感谢使用图书馆管理系统！\n";
            return 0;
        default:
            cout << "输入无效，请重新选择！\n";
        }

        cout << "\n按回车键继续...";
        cin.get();
        cin.get();
        system("cls");
    }
    return 0;
}
