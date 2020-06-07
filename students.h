#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student_t {
    char ID[10]; 
    char FAMILIA[16];
    char NAME[16]; 
    char OTCHESTVO[16]; 
    char FAKULTET[5]; 
    char SPECIALNOST[40]; 
}
student_t;
student_t read_student(); 
void print_student(student_t student); 
void delete_by_ID(student_t* students, int* n); 
void change_students(student_t* students, int n); 
void print_by_ID(student_t* students, int n); 
void save_students(student_t* students, int n); 
student_t* add_student(student_t* students, int* n);
student_t* load_students(int* n);