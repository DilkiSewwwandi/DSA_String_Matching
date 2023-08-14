#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void appendingToFile(int line, int index) {
    FILE *outputFile = fopen("output.txt", "a");

    if (outputFile == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(outputFile, "Found Pattern in Line: %d Index: %d\n", line, index);
    fclose(outputFile);
}

void prefix(char *pattern, int length, int lps[]) {
    int j = 0;
    lps[0] = 0;
    for (int i = 1; i < length; i++) {
        if (pattern[j] == pattern[i]) {
            lps[i] = j + 1;
            j++;
        } else {
            if (j != 0) {
                j = lps[j - 1];
                i--; 
            } else {
                lps[i] = 0;
            }
        }
    }
}

void kmp(char *text, char *pattern, int line) {
    int n = strlen(text);
    int m = strlen(pattern);
    int LPS[m];
    int j = 0;
    int s = 0;
    prefix(pattern, m, LPS); // Calculating LPS array
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = LPS[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
            if (j == m) {
                appendingToFile(line, i - m + 1);
                s++;
                j = LPS[j - 1];
            }
        }
    }
}

void dotpattern(char *text, char *pattern, int i, int line) {
    for (char j = 'a'; j <= 'z'; j++) {
        char modifiedPattern[100];
        strcpy(modifiedPattern, pattern);
        if (modifiedPattern[i] == '.') {
            modifiedPattern[i] = j;
            kmp(text, modifiedPattern, line);
        }
    }

    for (char j = 'A'; j <= 'Z'; j++) {
        char modifiedPattern[100];
        strcpy(modifiedPattern, pattern);
        if (modifiedPattern[i] == '.') {
            modifiedPattern[i] = j;
            kmp(text, modifiedPattern, line);
        }
    }
}


int main() {
    FILE *outputFile = fopen("output.txt", "w");
    fclose(outputFile);

    FILE *patternFile = fopen("pattern1.txt", "r"); //enter the name of the pattern file here
    if (patternFile == NULL) {
        perror("Error opening pattern file!");
        return 1;
    }

    char pattern[100]; 
    if (fgets(pattern, sizeof(pattern), patternFile) == NULL) {
        perror("Error reading pattern from file");
        fclose(patternFile);
        return 1;
    }
    fclose(patternFile);

    FILE *textFile = fopen("text1.txt", "r"); //enter the name of the text file here
    if (textFile == NULL) {
        perror("Error opening text file!");
        return 1;
    }

    char text[1000];
    int line = 1;

    while (fgets(text, sizeof(text), textFile)) {
        text[strcspn(text, "\n")] = '\0';
        for (int i = 0; i < strlen(pattern); i++) {
            char c = pattern[i];
            if (c == '.') {
                dotpattern(text, pattern, i, line);
            }
        }
        kmp(text, pattern, line);
        line++;
    }

    fclose(textFile); //close the text file
    return 0;
}