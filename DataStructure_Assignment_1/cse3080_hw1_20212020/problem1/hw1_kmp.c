#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 10000000
#define PATTERN_SIZE 3000

char str[STRING_SIZE];
char pat[PATTERN_SIZE];
int ans_arr[STRING_SIZE];
int failure[PATTERN_SIZE];
int cnt = 0;

void fail(char* pat) {
	int i, n = strlen(pat);
	failure[0] = -1;
	for (int j = 1; j < n; j++) {
		i = failure[j - 1];
		while ((pat[j] != pat[i + 1]) && (i >= 0)) i = failure[i];
		if (pat[j] == pat[i + 1]) failure[j] = i + 1;
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
			ans_arr[cnt++] = i - lenp;
			j = failure[j - 1] + 1;
		}
	}
}

int main() {

	FILE* sFile = fopen("string.txt", "r");
	FILE* pFile = fopen("pattern.txt", "r");

	FILE* fp = fopen("result_kmp.txt", "w");

	if (sFile != NULL && pFile != NULL) {
		fgets(str, STRING_SIZE, sFile);
		fgets(pat, STRING_SIZE, pFile);
	}
	else {
		printf("The string file does not exist.");
		return 1;
	}

	fail(pat);
	pmatch(str, pat);

	fprintf(fp, "%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		fprintf(fp, "%d ", ans_arr[i]);
	}

	fclose(sFile);
	fclose(pFile);
	fclose(fp);

	return 0;
}