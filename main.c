#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "books.h"
#include "students.h"
#include "users.h"

void book_menu() {
    int n, punkt;
    book_t* books = load_books(&n); 
    do {
        printf("Menu\n");
        printf("1  Add book\n");
        printf("2  Delete by ISBN\n");
        printf("3  Print books by ISBN\n");
        printf("4  Print books\n");
        printf("5  Quit\n");
        printf("\n");
        scanf("%d%*c", &punkt);
        while (punkt < 1 || punkt > 5) {
            printf("Error: wrong number\n");
            scanf("%d%*c", &punkt); 
        }
        switch (punkt) {
        case 1:
            books = add_book(books, &n); 
            break;
        case 2:
            delete_by_ISBN(books, &n);
            break;
        case 3:
            print_by_ISBN(books, n);
            break;
        case 4:
            print_books(books, n);
            break;
        }
        printf("\n");
    } while (punkt != 5);
    save_books(books, n); 
    free(books); 
}

void students_menu() {
    int n, punkt;
    student_t* students = load_students(&n);
    do {
        printf("Menu\n");
        printf("1  Add student\n");
        printf("2  Delete by id\n");
        printf("3  Change by id\n");
        printf("4  Print by id\n");
        printf("5  Quit\n");
        printf("\n");
        scanf("%d%*c", &punkt); 
        while (punkt < 1 || punkt > 5) {
            printf("Error: wrong number\n");
            scanf("%d%*c", &punkt); 
        }
        switch (punkt) {
        case 1:
            students = add_student(students, &n); 
            break;
        case 2:
            delete_by_ID(students, &n);
            break;
        case 3:
            change_students(students, n);  
            break;
        case 4:
            print_by_ID(students, n);
            break;
        }
        printf("\n");
    } while (punkt != 5); 
    save_students(students, n); 
    free(students); 
}

int main() {
    struct user_t* users = read_users();
    struct user_t stok = avtoriz(users);
    int n = 0;
    if ((strcmp(stok.bk, "1") == 0) && (strcmp(stok.st, "1") == 0)) {
        while (n != 3) {
            printf("Menu:\n");
            printf("1  Book\n");
            printf("2  Student\n");
            printf("3  Quit\n");
            printf("\n");
            scanf("%d", &n);
            while (n < 1 || n > 3) {
                printf("Error: wrong number\n");
                scanf("%d%*c", &n);
            }
            switch (n) {
            case 1:
                book_menu();
               break;
            case 2:
                students_menu();
                break;
            }
        }
    }
    else if ((strcmp(stok.bk, "1") != 0) && (strcmp(stok.st, "1") == 0)) {
        while (n != 2) {
            printf("Menu:\n");
            printf("1  Student\n");
            printf("2  Quit\n");
            printf("\n");
            scanf("%d", &n);
            while (n < 1 || n > 3) {
                printf("Error: wrong number\n");
                scanf("%d%*c", &n);
            }
             switch (n) {
             case 1:
                 students_menu();
                 break;
            }
        }
    }
    else if ((strcmp(stok.bk, "1") == 0) && (strcmp(stok.st, "1") != 0)) {
        while (n != 2) {
            printf("Menu:\n");
            printf("1  Books\n");
            printf("2  Quit\n");
            printf("\n");
            scanf("%d", &n);
            while (n < 1 || n > 3) {
                printf("Error: wrong number\n");
                scanf("%d%*c", &n);
            }
            switch (n) {
            case 1:
                book_menu();
                break;
            }
        }
    }
    free(users);
    return 0;
}