#ifndef SORT
#define SORT

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void swap(int *, int, int);
void print_arr(int *, int);
bool less_than(int, int);
bool greater_than(int, int);

void insert_sort(int *, int, bool (*)(int, int));

#endif
