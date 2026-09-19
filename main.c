#include <stdio.h>
#include "bookmanager.h"

int main(int argc,char* argv[]) 
{
	BookManager* bm = bookManager_alloc();
	bookManager_run(bm);
	bookManager_free(bm);
	return 0;
}