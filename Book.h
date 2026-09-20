#pragma once
#include <stdint.h>

typedef struct Book
{
	uint64_t id;
	char name[64];
	char author[64];
	float price;
}Book;

Book *book_alloc();
Book* book_alloc(uint64_t id, const char* name, const char* author, float price);
void book_free(Book* pthis);

void book_print(Book* pthis)
{
	printf("%11u %s %s %f\n", pthis->id, pthis->name, pthis->author, pthis->price);
}