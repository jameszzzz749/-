#define _CRT_SECURE_NO_WARNINGS  // 关闭VS安全警告
#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main() {
    system("chcp 936 >nul");
    loadData();  // 启动时加载历史数据
    int choice;

    while (1) {
        showMenu();
        printf("请输入您的选择：");
        scanf("%d", &choice);

        switch (choice) {
        case 1: addBook(); break;
        case 2: showAllBooks(); break;
        case 3: modifyBook(); break;
        case 4: deleteBook(); break;
        case 5: borrowBook(); break;
        case 6: returnBook(); break;
        case 7:
            saveData();
            printf("数据已保存，感谢使用图书馆管理系统！\n");
            return 0;
        default:
            printf("输入无效，请重新选择！\n");
        }

        printf("\n按回车键继续...");
        getchar(); getchar();  // 暂停等待
        system("cls");         // 清屏（Windows）
    }
    return 0;
}