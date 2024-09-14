#include <stdio.h>
#include <stdlib.h>

// zmienna  - zmienna
// &zmienna - adress do zmiennej

// '\0'     - znak końca stringa

int sum(int a, int b);
int sub(int a, int b);

void clearArray(char array[]);
int action(int a, int b, char action);

int main()
{
    printf("#################################### \n");

    char actions[] = {'+', '-'};
    char lastAction = '+';
    // char operation[100];
    // printf("Dzialanie: ");
    // scanf("%s", operation); // Spacja przed %c pomija białe znaki

    // test
    char operation[] = "11+22+33-66";
    printf("Dzialanie: %s\n", operation);

    int i = 0, cellIndex = 0, a = 0, b = 0;
    char cell[] = {'\0', '\0', '\0', '\0'};

    int length = sizeof(operation) / sizeof(operation[0]);
    for (i = 0; i < length; i++)
    {
        if ((operation[i] != '+' || operation[i] != '-') &&  operation[i] != '\0')
        {
            cell[cellIndex] = operation[i];
            cellIndex++;
            continue;
        }

        if(operation[i] != '\0')
            lastAction = operation[i];

        cellIndex = 0;

        if (a != 0)
            b = atoi(cell);
        else
            a = atoi(cell);

        if (a != 0 && b != 0)
        {
            a = action(a, b, lastAction);
            b = 0;
        }

        clearArray(cell);
    }

    printf("Dzialanie: %s wynik= %d", operation, a);
    return 0;
}

int action(int a, int b, char action)
{
    switch (action)
    {
    case '+':
        return sum(a, b);
    case '-':
        return sub(a,b);
    default:
        return -99;
    }
}

int sum(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

void clearArray(char array[])
{
    for (int i = 0; array[i] != '\0'; i++)
    {
        array[i] = '\0';
    }
}