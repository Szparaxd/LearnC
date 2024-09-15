#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// zmienna  - zmienna
// &zmienna - adress do zmiennej

// '\0'     - znak końca stringa

float action(float a, float b, char action);
int arrayContain(char array[], char value);
char *replace_substring(char str[], char oldStr[], char newStr[]);
int findEndIndex(char str[]);

int main()
{
    printf("#################################### \n");

    char str[] = "aoaoaoaoaoa";
    char prev[] = "o";
    char new[] = "0";
    char *repStr = replace_substring(str, prev, new);

    printf("%s \n", repStr);

    return 0;
}

char *replace_substring(char str[], char oldStr[], char newStr[])
{
    char result[900] = "";

    int strLength = sizeof(str) / sizeof(str[0]);
    printf("%d \n", strLength);

    int rStrLength = sizeof(result) / sizeof(result[0]);
    printf("%d \n", rStrLength);

    for (int i = 0; i < strLength; i++)
    {

    }

    return "abc";
}

int findEndIndex(char str[])
{   
    int i =0;
    for (i = 0; str[i] != '\0'; i++)
    { }
    return i;
}

char addString(char str[], char strToAdd[])


float action(float a, float b, char action)
{
    switch (action)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        printf("action: %c \n", action);
        return -99.0;
    }
}

int arrayContain(char array[], char value)
{
    for (int i = 0; array[i] != '\0'; i++)
    {
        if (array[i] == value)
            return true;
    }

    return false;
}