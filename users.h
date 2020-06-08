#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user_t {
	char log[16];
	char pass[16];
	char bk[5];
	char st[5];
};
struct user_t* read_users();
struct user_t avtoriz(struct user_t* users);
int in_users();
