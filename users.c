#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "users.h"

struct user_t* read_users() {
	FILE* f = fopen("users.csv", "r");
	struct user_t* users = calloc(1, sizeof(struct user_t));
	int g = in_users();
	char string[100];
	int i = 0;
	while (i < g) {
		fgets(string, 100, f);
		strcpy(users[i].log, strtok(string, ";"));
		strcpy(users[i].pass, strtok(NULL, ";"));
		strcpy(users[i].bk, strtok(NULL, ";"));
		strcpy(users[i].st, strtok(NULL, "\n"));
		i++;
		users = realloc(users, (i + 1) * sizeof(struct user_t));
	}
	fclose(f);
	return users;
}

struct user_t avtoriz(struct user_t* users) {
	struct user_t using;
	int dostup = 0;
	strcpy(using.bk, "");
	strcpy(using.st, "");
	while (dostup == 0) {
		printf("Enter LOGIN:\n");
		scanf("%s", using.log);
		int z = 0;
		int n = in_users();
		for (int i = 0; i < n; i++) {
			if (strcmp(using.log, users[i].log) == 0) {
				z = i;
			}
		}
		printf("Enter PASSWORD: \n");
		scanf("%s", using.pass);
		if (strcmp(using.pass, users[z].pass) == 0) {
			dostup = 1;
			strcpy(using.bk, users[z].bk);
			strcpy(using.st, users[z].st);
		}
		else {
			printf("Wrong PASSWORD\n");
		}
	}
	return using;
}

int in_users() {
	int st = 0;
	FILE* f = fopen("users.csv", "r");
	while (!feof(f)) {
		if (fgetc(f) == '\n')
			st++;
	}
	fclose(f);
	return ++st;
}