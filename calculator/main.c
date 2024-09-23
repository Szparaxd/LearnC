#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "string_helper.h"

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

int main() {
	char actions[] = "+-*/";
	char txt[] = "22+33+44";

	char* str_a = NULL, * str_b = NULL;
	int size_a = 0, size_b = 0, index_after_action = 0;
	float a = 0, b = 0;

	for (int i = 0; i < getLengthStr(txt); i++)
	{
		if (arrayContain(actions, txt[i]))
		{
			printf("zwieram=%c \n", txt[i]);

			if (a == 0)
			{
				char* str_a = string_copy(txt, index_after_action, i - index_after_action);
				printf("str_a=%s.\n", str_a);
				a = atof(str_a);
				index_after_action = i + 1;
			}
			else if (b == 0)
			{
				char* str_b = string_copy(txt, index_after_action, i - index_after_action);
				printf("str_b=%s.\n", str_b);
				b = atof(str_b);
				index_after_action = i + 1;
			}
		}

		size_a++;
	}

	return 0;
}