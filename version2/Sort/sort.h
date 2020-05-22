#ifndef SORT
#define SORT

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void swap(int *, int, int);
void print_arr(int *, int);
bool less_than(int, int);
bool greater_than(int, int);

void insert_sort(int *, int, bool (*) (int, int));
void bin_sort(int *, int, bool (*) (int, int));
void shell_sort(int *, int, bool (*) (int, int));

void bubble_sort(int *, int, bool (*) (int, int));
void quick_sort(int *, int, int, bool (*) (int, int));
int partition(int *, int, int, bool (*) (int, int));

#endif
