#include "bookmanager.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int bookManager_menu();
void boolManager_add(BookManager* pthis);
void boolManager_find(BookManager* pthis);
void boolManager_alter(BookManager* pthis);
void boolManager_remove(BookManager* pthis);
void boolManager_quit(BookManager* pthis);

//枚举
enum MenuOption
{
	Quit,
	Add,
	Find,
	Alter,
	Remove,
};

BookManager* bookManager_alloc()
{
	BookManager* bm = calloc(1, sizeof(BookManager));
	assert(bm != NULL);

	return bm;
}

void bookManager_free(BookManager* pthis)
{
	free(pthis);
}

void bookManager_run(BookManager* pthis)
{
	pthis->isRunning = true;
	while(pthis->isRunning)
	{
		switch (bookManager_menu())
		{
		case Quit:
			boolManager_quit(pthis);
			break;
		case Add:
			boolManager_add(pthis);
			break;
		case Find:
			boolManager_find(pthis);
			break;
		case Alter:
			boolManager_alter(pthis);
			break;
		case Remove:
			boolManager_remove(pthis);
			break;

		}
		system("pause");
		system("cls");
	}
}

//菜单
int bookManager_menu()
{
	printf("图书管理系统\n");
	printf("功能列表选择\n");
	printf("1.添加图书\n");
	printf("2.查看图书\n");
	printf("3.修改图书\n");
	printf("4.删除图书\n");
	printf("0.退出系统\n");
	printf("select>");
	int op = -1;
	scanf("%d",&op);
	return op;
}

void boolManager_add(BookManager* pthis)
{
	printf("add\n");
}
void boolManager_find(BookManager* pthis)
{
	printf("find\n");
}
void boolManager_alter(BookManager* pthis)
{
	printf("alter\n");
}
void boolManager_remove(BookManager* pthis)
{
	printf("remove\n");
}
void boolManager_quit(BookManager* pthis)
{
	printf("quit\n");
}