#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "string_helper.h"

float calculate(float a, float b, char action);
float toCount(char operacion[]);
void check(float value, char operacion[]);

int main() {
	check(99, "33+33+33");
	check(6, "2+2*2");

	return 0;
}

float calculate(float a, float b, char action)
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


float toCount(char operacion[])
{
        char actions[] = "+-*/";

        int index_after_action = 0;
        float a = 0, b = 0;
        bool has_a = false, has_b = false;

	for (int i = 0; i <= getLengthStr(operacion); i++)
	{
		printf("i=%d c=%c \n", i, operacion[i]);

                if (arrayContain(actions, operacion[i]))
                {
                        char *tmp = string_copy(operacion, index_after_action, i - index_after_action);
                        printf("segment=%s.\n", tmp);

                        if (!has_a)
                        {
                                a = atof(tmp);
                                has_a = true;
                        }
                        else if (!has_b)
                        {
                                b = atof(tmp);
                                has_b = true;
                        }

                        free(tmp);

                        if (has_a && has_b)
                        {
                                printf("a=%f b=%f action=%c\n", a, b, operacion[index_after_action - 1]);
                                a = calculate(a, b, operacion[index_after_action - 1]);
                                b = 0;
                                has_b = false;
                                printf("a=%f.\n", a);
                        }

                        index_after_action = i + 1;
                }
	}

	printf("r=%f  \n", a);
	return a;
}

void check(float value, char operacion[])
{
	float result = 0;
	result = toCount(operacion);

	printf("r=%f  \n", result);
	float abc = ((value - result) * (value - result)) / 2;

	if (abc < 0.01)
	{
		printf("success %s = %f; %f \n", operacion, result, value);
	}
	else
	{
		printf("failed %s = %f; %f \n", operacion, result, value);
	}
}