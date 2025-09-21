#ifndef MYSTRFUNCTIONS_H
#define MYSTRFUNCTIONS_H

/* Simple string utility functions */

/* Return length of string (not including null terminator) */
int mystrlen(const char* s);

/* Copy src into dest. Return number of characters copied (not including terminating null). */
int mystrcpy(char* dest, const char* src);

/* Copy up to n characters from src into dest; ensure null-termination. Return number copied. */
int mystrncpy(char* dest, const char* src, int n);

/* Append src to dest. Return new length of dest (not including null). */
int mystrcat(char* dest, const char* src);

#endif // MYSTRFUNCTIONS_H
