#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    printf("--- Testing String Functions ---\n");
    char a[256] = "Hello";
    char b[256] = " World";
    printf("a = '%s'\n", a);
    printf("b = '%s'\n", b);
    printf("mystrlen(a) = %d\n", mystrlen(a));
    mystrcat(a, b);
    printf("After mystrcat(a,b): a = '%s'\n", a);
    char dest[20];
    mystrcpy(dest, "copy-test");
    printf("mystrcpy -> dest = '%s'\n", dest);
    mystrncpy(dest, "abcdefg", 4);
    printf("mystrncpy(dest, 'abcdefg', 4) -> dest = '%s'\n", dest);

    printf("\n--- Testing File Functions ---\n");
    const char* fname = "test_input.txt";
    FILE* f = fopen(fname, "w+");
    if (!f) { perror("fopen"); return 1; }
    fprintf(f, "This is a test file.\nLine two has word test.\nThird line.\nAnother test line.\n");
    fflush(f);

    int lines, words, chars;
    if (wordCount(f, &lines, &words, &chars) == 0) {
        printf("Counts for %s: lines=%d words=%d chars=%d\n", fname, lines, words, chars);
    } else {
        printf("wordCount failed\n");
    }

    char** matches = NULL;
    int found = mygrep(f, "test", &matches);
    if (found > 0) {
        printf("mygrep found %d matches:\n", found);
        for (int i = 0; i < found; ++i) {
            printf("%s", matches[i]);
            free(matches[i]);
        }
        free(matches);
    } else if (found == 0) {
        printf("mygrep: no matches\n");
    } else {
        printf("mygrep failed\n");
    }
    fclose(f);
    remove(fname);

    printf("\nProgram finished.\n");
    return 0;
}
