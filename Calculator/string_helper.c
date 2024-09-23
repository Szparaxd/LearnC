#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include "string_helper.h"


int test() {
    return 11;
}

int getLengthStr(char text[])
{
    int i = 0;
    while (text[i] != '\0')
    {
        i++;
    }

    return i;

}

char* replace_substring(char str[], char oldStr[], char newStr[])
{
    char result[900] = "";
    int resultIndex = 0;

    printf("%s \n", oldStr);

    int strLength = getLengthStr(str);
    int subLength = getLengthStr(oldStr);
    int newLength = getLengthStr(newStr);

    printf("strLength=%d subLength=%d newLength=%d \n", strLength, subLength, newLength);

    for (int i = 0; i < strLength; i++)
    {
        printf("i=%d char='%c' \n", i, str[i]);

        if (str[i] == oldStr[0] && str[i + subLength - 1] == oldStr[subLength - 1])
        {
            printf("if! \n");
            int exsist = 1;
            for (int j = 0; j < subLength - 1; j++)
            {
                if (str[i + j] != oldStr[j])
                {
                    exsist = 0;
                    break;
                }
            }


            printf("exsist=%d \n", exsist);
            if (exsist)
            {
                for (int j = 0; j < newLength; j++)
                {
                    printf("i=%d j=%d \n", i, j);
                    result[resultIndex] = newStr[j];
                    resultIndex++;
                }

                i += subLength - 1;
                continue;
            }
        }

        result[resultIndex] = str[i];
        resultIndex++;
    }

    printf("res= %s \n", result);

    //return result;

    //char* result2 = malloc(strLength + 1);
    //if (!result2)
    //    return NULL;
    //strcpy(result2, str);
    return str;
}

char* addString(char str[], char strToAdd[])
{
    return str;
}

int findEndIndex(char str[])
{
    int i = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
    }
    return i;
}

int arrayContain(char array[], char value)
{
    for (int i = 0; array[i] != '\0'; i++)
    {
        if (array[i] == value)
            return 1;
    }

    return 0;
}

char* string_copy(char text[], int index, int length)
{
    char* result = malloc(length + 1);
    if (result == NULL)
    {
        fprintf(stderr, "B³¹d alokacji pamiêci w funkcji copy\n");
        exit(1);
    }
    for (int i = 0; i < length; i++)
    {
        result[i] = text[index + i];
    }
    result[length] = '\0'; // Null-terminacja ³añcucha
    return result;
}

char* string_copy2(char text[], int index, int length)
{
    char* name = "Flavio";
    return name;
}

int foo(int x)    /* Function definition */
{
    return x + 5;
}