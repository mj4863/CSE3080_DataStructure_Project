#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define STRING_SIZE 10000000
#define PATTERN_SIZE 3000

char string[STRING_SIZE];
char pattern[PATTERN_SIZE];

void main() {

    srand(0);  // 테스트 7로함

    /* create string file */
    FILE* strfile, * patfile;
    char strfilename[200], patfilename[200];
    int i, rv;

    for (i = 0; i < STRING_SIZE - 1; i++) {
        rv = rand() % 3000;
        if (rv == 0) string[i] = 'B';
        else string[i] = 'A';
    }
    string[STRING_SIZE - 1] = (char)0;

    for (i = 0; i < PATTERN_SIZE - 1; i++) {
        rv = rand() % 3000;
        if (rv == 0) pattern[i] = 'B';
        else pattern[i] = 'A';
    }
    pattern[PATTERN_SIZE - 1] = (char)0;

    sprintf(strfilename, "string.txt");
    strfile = fopen(strfilename, "w");
    fputs(string, strfile);
    fclose(strfile);

    sprintf(patfilename, "pattern.txt");
    patfile = fopen(patfilename, "w");
    fputs(pattern, patfile);
    fclose(patfile);
}
