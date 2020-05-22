#ifndef STRING
#define STRING

#include<cstdio>
#include<cstdlib>

#define MaxSize 100

typedef struct
{
	char data [MaxSize];
	int length;
}SqString;

//basic operation
void create_string(SqString **, char *);
void init_string(SqString **);
void destroy_string(SqString *);
void print_string(SqString *);
int string_length(SqString *);
void strcpy(SqString *, SqString *);
bool string_equal(SqString *, SqString *);
SqString *concat(SqString *, SqString *);
SqString *substr(SqString *, int, int);
SqString *insstr(SqString *, int, SqString *);
SqString *delstr(SqString *, int, int);
SqString *repstr(SqString *, int, int, SqString *);

//algorithm
void get_next(SqString *, int *);
int KMP(SqString *, SqString *, int, int *);
int count_appear(SqString *, SqString *);

#endif
