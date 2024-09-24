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

	char* str_a = NULL, * str_b = NULL;
	int size_a = 0, size_b = 0, index_after_action = 0;
	float a = 0, b = 0;

	for (int i = 0; i <= getLengthStr(operacion); i++)
	{
		printf("i=%d c=%c \n", i, operacion[i]);

		if (arrayContain(actions, operacion[i]))
		{
			if (a == 0)
			{
				char* str_a = string_copy(operacion, index_after_action, i - index_after_action);
				printf("str_a=%s.\n", str_a);
				a = atof(str_a);
			}
			else if (b == 0)
			{
				char* str_b = string_copy(operacion, index_after_action, i - index_after_action);
				printf("str_b=%s.\n", str_b);
				b = atof(str_b);
			}

			if (a != 0 && b != 0)
			{
				printf("a=%f b=%f action=%c\n", a, b, operacion[index_after_action - 1]);
				a = calculate(a, b, operacion[index_after_action - 1]);
				b = 0;
				printf("a=%f.\n", a);
			}

			index_after_action = i + 1;
		}

		size_a++;
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