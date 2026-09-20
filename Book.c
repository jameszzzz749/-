#include "Book.h"

#include <malloc.h>
#include <assert.h>
#include <string.h>

Book* book_alloc()
{
	Book* book = calloc(1, sizeof(Book));
	assert(book != NULL);
	return book;
}

Book* book_alloc2(uint64_t id, const char* name, const char* author, float price)
{
	Book* book = book_alloc();
	book->id = id;
	strcpy(book->name , name);
	strcpy(book->author , author);
	book->price = price;
	return book;
}

void book_free(Book* pthis)
{
	free(pthis);
}

void book_print(Book* pthis)
{
	printf("%11u\t %s\t %s\t %f\n", pthis->id, pthis->name, pthis->author, pthis->price);
}
