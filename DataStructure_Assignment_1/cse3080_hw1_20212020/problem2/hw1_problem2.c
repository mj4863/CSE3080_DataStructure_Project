#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 10000000

char str[STRING_SIZE];
char pat[STRING_SIZE];
int failure[STRING_SIZE];
int cnt = 0;

void fail(char* str) {
	int i, n = strlen(str);
	failure[0] = -1;
	for (int j = 1; j < n; j++) {
		i = failure[j - 1];
		while ((str[j] != str[i + 1]) && (i >= 0)) i = failure[i];
		if (str[j] == str[i + 1]) failure[j] = i + 1;
		else failure[j] = -1;
	}
}

void pmatch(char* string, char* pat) {
	int i = 0, j = 0;
	int lens = strlen(string);
	int lenp = strlen(pat);
	while (i < lens) {
		while (i < lens && j < lenp) {
			if (string[i] == pat[j]) {
				i++;
				j++;
			}
			else if (j == 0) i++;
			else j = failure[j - 1] + 1;
		}
		if (j == lenp) {
			cnt++;
			j = failure[j - 1] + 1;
		}
	}
}

int main() {

	FILE* pFile = fopen("string.txt", "r");
	FILE* fp = fopen("result.txt", "w");

	if (pFile != NULL) {

		while (fgets(str, STRING_SIZE, pFile) != NULL) {
			for (int i = 0; i < strlen(str); i++) {
				if (str[i] == '\n') {
					str[i] = 0;
				}
			}
			int len = strlen(str);
			if (!len) {
				fprintf(fp, "%d\n", 0);
				continue;
			}
			fail(str);
			for (int i = 0; i < strlen(str); i++) {
				if (failure[i] == 0 && i + failure[len - 1] == len - 1) {
					strncpy(pat, str, i);
					pat[i] = 0;
					pmatch(str, pat);
					break;
				}
			}
			if (!cnt) {
				fprintf(fp, "%d\n", 1);
			}
			else {
				fprintf(fp, "%d\n", cnt);
				cnt = 0;
			}
		}

		fclose(pFile);
		fclose(fp);
	}
	else {
		printf("The string file does not exist.");
		return 1;
	}

	return 0;
}