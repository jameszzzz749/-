#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_BOOKS 100      // 最大图书数量
#define DATA_FILE "library.dat"  // 数据保存文件名

// 图书信息结构体
typedef struct {
    int id;             // 图书编号
    char name[50];      // 书名
    char author[30];    // 作者
    int total;          // 总馆藏数量
    int available;      // 当前可借数量
} Book;

// 功能函数声明
void showMenu();       // 显示主菜单
void addBook();        // 添加图书
void showAllBooks();   // 显示所有图书
void modifyBook();     // 修改图书信息
void deleteBook();     // 删除图书
void borrowBook();     // 借书
void returnBook();     // 还书
void loadData();       // 从文件加载数据
void saveData();       // 保存数据到文件

#endif