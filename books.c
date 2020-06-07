#define _CRT_SECURE_NO_WARNINGS
#include "books.h"

const char* book_nm = "books.csv"; 

book_t read_book() {
    book_t book; 
    printf("Enter ISBN: ");
    scanf("%s", book.ISBN); 
    printf("Enter ABTOP: ");
    scanf("%s", book.ABTOP); 
    printf("Enter HA3BAHNE: ");
    scanf("%s", book.HA3BAHNE); 
    printf("Enter BCEGO: ");
    scanf("%d", &book.BCEGO); 
    printf("Enter DOCTYPHO: ");
    scanf("%d", &book.DOCTYPHO);
    return book; 
}

void print_book_head() {
    printf("__________________________________________________________________________________________________________________________\n");
    printf("|------ISBN-------|-----------------ABTOP--------------------|-------------HA3BAHNE-------------|---BCEGO---|--DOCTYPHO--|\n");
    printf("__________________________________________________________________________________________________________________________\n");
}

void print_book(book_t book) {
    printf("| %15s ", book.ISBN);
    printf("| %40s ", book.ABTOP);
    printf("| %32s ", book.HA3BAHNE);
    printf("| %9d ", book.BCEGO);
    printf("| %10d ", book.DOCTYPHO);
    printf("|\n");
}

void print_book_foot() {
    printf("__________________________________________________________________________________________________________________________\n");
}

void print_books(book_t* books, int n) {
    if (n == 0) { 
        printf("No books\n"); 
        return; 
    }

    // אכדמנטעל ״וככא
    for (int k = n / 2; k > 0; k /= 2) {
        for (int i = k; i < n; i++) {
            book_t tmp = books[i]; 
            int j = i;
            while (j >= k && strcmp(tmp.ISBN, books[j - k].ISBN) < 0) {
                books[j] = books[j - k];
                j -= k;
            }
            books[j] = tmp;
        }
    }
    print_book_head(); 
    for (int i = 0; i < n; i++)
        print_book(books[i]);
    print_book_foot();
}

int get_by_ISBN(book_t* books, int n, char* ISBN) {
    for (int i = 0; i < n; i++)
        if (!strcmp(ISBN, books[i].ISBN))
            return i;
    return -1;
}

void print_by_ISBN(book_t* books, int n) {
    char ISBN[10];
    printf("ISBN: ");
    scanf("%s", ISBN);
    int index = get_by_ISBN(books, n, ISBN);
    if (index == -1) {
        printf("No book with this ISBN '%s'\n", ISBN); 
        return;
    }
    print_book_head(); 
    print_book(books[index]); 
    print_book_foot();
}

void delete_by_ISBN(book_t* books, int* n) {
    if (n == 0) { 
        printf("No book\n");
        return; 
    }
    char ISBN[16];
    printf("Enter ISBN: ");
    scanf("%s", ISBN);
    int i = get_by_ISBN(books, *n, ISBN); 
    if (i == -1) {
        printf("No book with ISBN '%s'\n", ISBN); 
        return; 
    }
    (*n)--;
    for (; i < *n; i++)
        books[i] = books[i + 1];
}

void save_books(book_t* books, int n) {
    FILE* f = fopen(book_nm, "w"); 

    for (int i = 0; i < n; i++) {
        fprintf(f, "%s;%s;%s;%d;%d", books[i].ISBN, books[i].ABTOP, books[i].HA3BAHNE, books[i].BCEGO, books[i].DOCTYPHO);
        if (i < n - 1)
            fprintf(f, "\n");
    }
    fclose(f); 
}

book_t* add_book(book_t* books, int* n) {
    book_t book = read_book(); 
    if (get_by_ISBN(books, *n, book.ISBN) != -1) { 
        printf("Book exists with this ISBN\n"); 
        return books; 
    }
    books = (book_t*)realloc(books, (*n + 1) * sizeof(book_t)); 
    printf("Success\n");
    books[(*n)++] = book; 

    return books; 
}

book_t* load_books(int* n) {
    FILE* f = fopen(book_nm, "r"); 
    if (!f) { 
        *n = 0;
        return NULL; 
    }
    book_t* books = (book_t*)malloc(sizeof(book_t)); 
    *n = 0; 
    while (!feof(f)) {
        fscanf(f, "%[^;]%*c", books[*n].ISBN);
        fscanf(f, "%[^;]%*c", books[*n].ABTOP);
        fscanf(f, "%[^;]%*c", books[*n].HA3BAHNE);
        fscanf(f, "%d%*c", &books[*n].BCEGO);
        fscanf(f, "%d%*c", &books[*n].DOCTYPHO);
        *n = *n + 1; 
        books = (book_t*)realloc(books, (*n + 1) * sizeof(book_t)); 
    }
    fclose(f); 
    return books; 
}