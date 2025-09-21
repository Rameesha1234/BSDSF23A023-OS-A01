#include "../include/mystrfunctions.h"

int mystrlen(const char* s) {
    int len = 0;
    if (!s) return 0;
    while (s[len] != '\0') ++len;
    return len;
}

int mystrcpy(char* dest, const char* src) {
    if (!dest || !src) return -1;
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
    return i;
}

int mystrncpy(char* dest, const char* src, int n) {
    if (!dest || !src || n <= 0) return 0;
    int i = 0;
    while (i < n - 1 && src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
    return i;
}

int mystrcat(char* dest, const char* src) {
    if (!dest || !src) return -1;
    int d = 0;
    while (dest[d] != '\0') ++d;
    int s = 0;
    while (src[s] != '\0') {
        dest[d + s] = src[s];
        ++s;
    }
    dest[d + s] = '\0';
    return d + s;
}
