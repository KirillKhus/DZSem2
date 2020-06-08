#define _CRT_SECURE_NO_WARNINGS
#include "students.h"

const char* students_path = "students.csv";

student_t read_student() {
    student_t student;
    printf("Enter ID: ");
    scanf("%s", student.ID); 
    printf("Enter FAMILIA: ");
    scanf("%s", student.FAMILIA); 
    printf("Enter NAME: ");
    scanf("%s", student.NAME); 
    printf("Enter OTCHESTVO: ");
    scanf("%s", student.OTCHESTVO); 
    printf("Enter FAKULTET: ");
    scanf("%s", student.FAKULTET);
    printf("Enter SPECIALNOST: ");
    scanf("%s", student.SPECIALNOST); 
    return student; 
}

void print_student_head() {
    printf("________________________________________________________________________________________________________________________\n");
    printf("|-----ID-----|-----FAMILIA------|-------NAME--------|----OTCHESTVO-----|-FAKULTET--|-------------SPECIALNOST-----------|\n");
    printf("________________________________________________________________________________________________________________________\n");
}

void print_student(student_t student) {
    printf("| %10s ", student.ID);
    printf("| %16s ", student.FAMILIA);
    printf("| %17s ", student.NAME);
    printf("| %16s ", student.OTCHESTVO);
    printf("| %9s ", student.FAKULTET);
    printf("| %33s ", student.SPECIALNOST);
    printf("|\n");
}

void print_student_foot() {
    printf("________________________________________________________________________________________________________________________\n");
}

int get_index_by_ID(student_t* students, int n, char* ID) {
    for (int i = 0; i < n; i++)
        if (!strcmp(ID, students[i].ID))
            return i;
    return -1; 
}

void delete_by_ID(student_t* students, int* n) {
    if (n == 0) { 
        printf("No student\n");
        return; 
    }
    char ID[10];
    printf("Enter ID: ");
    scanf("%s", ID);
    int i = get_index_by_ID(students, *n, ID); 
    if (i == -1) {
        printf("No student '%s'\n", ID);
        return; 
    }
    (*n)--;
    for (; i < *n; i++)
        students[i] = students[i + 1];
}

void change_students(student_t* students, int n) {
    if (n == 0) {
        printf("No student\n");
        return; 
    }
    char ID[16];
    printf("Enter ID: ");
    scanf("%s", ID);
    int index = get_index_by_ID(students, n, ID);
    if (index == -1) {
        printf("No student\n");
        return;
    }
    printf("Enter new data:\n");
    students[index] = read_student();
}

void print_by_ID(student_t* students, int n) {
    if (n == 0) {
        printf("No student\n");
        return;
    }
    char ID[16];
    printf("Enter ID: ");
    scanf("%s", ID);
    int index = get_index_by_ID(students, n, ID);
    if (index == -1) {
        printf("No student\n");
        return;
    }
    print_student_head();
    print_student(students[index]); 
    print_student_foot();
}

void save_students(student_t* students, int n) {
    FILE* f = fopen(students_path, "w");
    for (int i = 0; i < n; i++) {
        fprintf(f, "%s;", students[i].ID);
        fprintf(f, "%s;", students[i].FAMILIA);
        fprintf(f, "%s;", students[i].NAME);
        fprintf(f, "%s;", students[i].OTCHESTVO);
        fprintf(f, "%s;", students[i].FAKULTET);
        fprintf(f, "%s", students[i].SPECIALNOST);
        if (i < n - 1)
            fprintf(f, "\n");
    }
    fclose(f);
}

student_t* add_student(student_t* students, int* n) {
    student_t student = read_student(); 
    if (get_index_by_ID(students, *n, student.ID) != -1) {
        printf("Student exists with this ID\n"); 
        return students;
    }
    students = (student_t*)realloc(students, (*n + 1) * sizeof(student_t)); 
    printf("Success\n");
    students[(*n)++] = student;
    return students;
}

student_t* load_students(int* n) {
    FILE* f = fopen(students_path, "r"); 
    if (!f) { 
        *n = 0; 
        return NULL; 
    }
    student_t* students = (student_t*)malloc(sizeof(student_t)); 
    *n = 0; 
    while (!feof(f)) {
        fscanf(f, "%[^;]%*c", students[*n].ID);
        fscanf(f, "%[^;]%*c", students[*n].FAMILIA);
        fscanf(f, "%[^;]%*c", students[*n].NAME);
        fscanf(f, "%[^;]%*c", students[*n].OTCHESTVO);
        fscanf(f, "%[^;]%*c", students[*n].FAKULTET);
        fscanf(f, "%[^\n]", students[*n].SPECIALNOST);
        *n = *n + 1; 
        students = (student_t*)realloc(students, (*n + 1) * sizeof(student_t));
    }
    fclose(f); 
    return students; 
}
