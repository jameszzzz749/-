#pragma once
#include <stdbool.h>
typedef struct BookManager 
{
	bool isRunning;//是否运行
}BookManager;

//创建
BookManager* bookManager_alloc();

//销毁
void bookManager_free(BookManager* pthis);

//运行
void bookManager_run(BookManager* pthis);