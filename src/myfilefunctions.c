#define _GNU_SOURCE
#include "../include/myfilefunctions.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (!file || !lines || !words || !chars) return -1;
    rewind(file);
    int c;
    int in_word = 0;
    *lines = *words = *chars = 0;
    while ((c = fgetc(file)) != EOF) {
        (*chars)++;
        if (c == '\n') (*lines)++;
        if (isspace(c)) {
            if (in_word) {
                (*words)++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }
    if (in_word) (*words)++;
    rewind(file);
    return 0;
}

/* Simple grep implementation:
   - Reads file line by line using getline
   - If search_str is found in a line, adds a copy to matches array
   - The function allocates *matches (array of char*) and each string
     Caller must free each matches[i] and free(matches)
*/
int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (!fp || !search_str || !matches) return -1;
    rewind(fp);
    size_t cap = 8;
    size_t count = 0;
    char** arr = malloc(sizeof(char*) * cap);
    if (!arr) return -1;

    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, search_str) != NULL) {
            if (count >= cap) {
                cap *= 2;
                char** tmp = realloc(arr, sizeof(char*) * cap);
                if (!tmp) { free(line); for (size_t i=0;i<count;i++) free(arr[i]); free(arr); return -1; }
                arr = tmp;
            }
            arr[count] = strdup(line);
            if (!arr[count]) { free(line); for (size_t i=0;i<count;i++) free(arr[i]); free(arr); return -1; }
            count++;
        }
    }
    free(line);
    if (count == 0) {
        free(arr);
        *matches = NULL;
        return 0;
    }
    *matches = realloc(arr, sizeof(char*) * count);
    return (int)count;
}
