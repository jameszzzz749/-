#define _CRT_SECURE_NO_WARNINGS  // 关闭VS安全警告
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

// 全局变量：仅本文件内可访问
static Book books[MAX_BOOKS];
static int bookCount = 0;

// 内部辅助函数：按编号查找图书，返回下标，找不到返回-1
static int findBookById(int id) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            return i;
        }
    }
    return -1;
}

// 显示主菜单
void showMenu() {
    printf("========== 图书馆管理系统 ==========\n");
    printf("          1. 添加图书\n");
    printf("          2. 显示所有图书\n");
    printf("          3. 修改图书信息\n");
    printf("          4. 删除图书\n");
    printf("          5. 借书\n");
    printf("          6. 还书\n");
    printf("          7. 退出系统\n");
    printf("====================================\n");
}

// 添加图书
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("图书库已满，无法添加更多图书！\n");
        return;
    }

    Book b;
    printf("请输入图书编号：");
    scanf("%d", &b.id);

    if (findBookById(b.id) != -1) {
        printf("该编号的图书已存在！\n");
        return;
    }

    printf("请输入书名：");
    scanf("%s", b.name);
    printf("请输入作者：");
    scanf("%s", b.author);
    printf("请输入总数量：");
    scanf("%d", &b.total);
    b.available = b.total;  // 初始可借数量=总数量

    books[bookCount++] = b;
    saveData();
    printf("图书添加成功！\n");
}

// 显示所有图书
void showAllBooks() {
    if (bookCount == 0) {
        printf("当前书库暂无图书！\n");
        return;
    }

    printf("\n%-8s %-20s %-15s %-8s %-8s\n",
        "编号", "书名", "作者", "总数", "可借");
    printf("---------------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%-8d %-20s %-15s %-8d %-8d\n",
            books[i].id, books[i].name, books[i].author,
            books[i].total, books[i].available);
    }
}

// 修改图书信息
void modifyBook() {
    int id;
    printf("请输入要修改的图书编号：");
    scanf("%d", &id);

    int index = findBookById(id);
    if (index == -1) {
        printf("未找到对应编号的图书！\n");
        return;
    }

    printf("当前信息：书名=%s  作者=%s  总数=%d\n",
        books[index].name, books[index].author, books[index].total);

    printf("请输入新书名：");
    scanf("%s", books[index].name);
    printf("请输入新作者：");
    scanf("%s", books[index].author);
    printf("请输入新总数量：");
    scanf("%d", &books[index].total);

    // 保证可借数量不超过总数
    if (books[index].available > books[index].total) {
        books[index].available = books[index].total;
    }

    saveData();
    printf("图书信息修改成功！\n");
}

// 删除图书
void deleteBook() {
    int id;
    printf("请输入要删除的图书编号：");
    scanf("%d", &id);

    int index = findBookById(id);
    if (index == -1) {
        printf("未找到对应编号的图书！\n");
        return;
    }

    // 后续元素前移覆盖
    for (int i = index; i < bookCount - 1; i++) {
        books[i] = books[i + 1];
    }
    bookCount--;
    saveData();
    printf("图书删除成功！\n");
}

// 借书
void borrowBook() {
    int id;
    printf("请输入要借阅的图书编号：");
    scanf("%d", &id);

    int index = findBookById(id);
    if (index == -1) {
        printf("未找到对应编号的图书！\n");
        return;
    }

    if (books[index].available <= 0) {
        printf("抱歉，该书已全部借出，暂无库存！\n");
        return;
    }

    books[index].available--;
    saveData();
    printf("借书成功！《%s》剩余可借 %d 本\n",
        books[index].name, books[index].available);
}

// 还书
void returnBook() {
    int id;
    printf("请输入要归还的图书编号：");
    scanf("%d", &id);

    int index = findBookById(id);
    if (index == -1) {
        printf("未找到对应编号的图书！\n");
        return;
    }

    if (books[index].available >= books[index].total) {
        printf("该书已全部归还，无需重复操作！\n");
        return;
    }

    books[index].available++;
    saveData();
    printf("还书成功！《%s》当前可借 %d 本\n",
        books[index].name, books[index].available);
}

// 保存数据到文件
void saveData() {
    FILE* fp = fopen(DATA_FILE, "wb");
    if (fp == NULL) {
        printf("保存数据文件失败！\n");
        return;
    }
    fwrite(&bookCount, sizeof(int), 1, fp);
    fwrite(books, sizeof(Book), bookCount, fp);
    fclose(fp);
}

// 从文件加载数据
void loadData() {
    FILE* fp = fopen(DATA_FILE, "rb");
    if (fp == NULL) {
        return;
    }
    fread(&bookCount, sizeof(int), 1, fp);
    fread(books, sizeof(Book), bookCount, fp);
    fclose(fp);
}