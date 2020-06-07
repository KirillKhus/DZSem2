#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book_t {
    char ISBN[10]; 
    char ABTOP[40]; 
    char HA3BAHNE[40]; 
    int BCEGO; 
    int DOCTYPHO; 
} 
book_t;

book_t read_book(); 
void print_book(book_t book); 
void print_books(book_t* books, int n); 
void print_by_ISBN(book_t* books, int n); 
void delete_by_ISBN(book_t* books, int* n); 
void save_books(book_t* books, int n); 
book_t* add_book(book_t* books, int* n);
book_t* load_books(int* n); 