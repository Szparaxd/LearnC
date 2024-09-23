#ifndef STRING_HELPER_H
#define STRING_HELPER_H

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

int test();
int arrayContain(char array[], char value);
char* replace_substring(char str[], char oldStr[], char newStr[]);
int findEndIndex(char str[]);
int getLengthStr(char text[]);
char* string_copy(char text[], int index, int length);
char* string_copy2(char text[], int index, int length);
int foo(int x);

#endif // STRING_HELPER_H