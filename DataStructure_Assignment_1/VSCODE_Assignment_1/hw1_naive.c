#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 10000000
#define PATTERN_SIZE 3000

char str[STRING_SIZE];
char pat[PATTERN_SIZE];
int ans_arr[STRING_SIZE];

int main() {

	FILE* sFile = fopen(".\\string.txt", "r");
	FILE* pFile = fopen(".\\pattern.txt", "r");

	FILE* fp = fopen(".\\result_naive.txt", "w");

	if (sFile != NULL && pFile != NULL) {
		fgets(str, STRING_SIZE, sFile);
		fgets(pat, STRING_SIZE, pFile);
	}
	else if (sFile == NULL) {
		printf("The string file does not exist.\n");
		return 1;
	}
	else {
		printf("The pattern file does not exist.\n");
		return 1;
	}

	int i, j = 0, start = 0;
	int lasts = strlen(str) - 1;
	int lastp = strlen(pat) - 1;
	int endmatch = lastp;

	int cnt = 0;

	for (i = 0; endmatch <= lasts; endmatch++, start++) {
		if (str[endmatch] == pat[lastp])
			for (j = 0, i = start; j < lastp && str[i] == pat[j]; i++, j++);
		if (j == lastp) {
			ans_arr[cnt++] = start;
			j = 0;
		}
	}

	fprintf(fp, "%d", cnt);
	fputs("\n", fp);
	for (int i = 0; i < cnt; i++) {
		fprintf(fp, "%d ", ans_arr[i]);
	}

	fclose(sFile);
	fclose(pFile);
	fclose(fp);

	return 0;
}