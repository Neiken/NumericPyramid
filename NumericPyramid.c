#include <stdio.h>
#include <math.h>

double pow(double num, double exponent)
{
	double r = 1;

	for(unsigned x = 0; x < fabs(exponent); x++)
	{
		r *= (exponent < 0 ? 1 / num : num);
	}

	return r;
}

int main(int len, char **args)
{
	if(len < 2 || len > 2) { printf("%s", (len < 2 ? "Too few arguments. Expected 1" : "Too much arguments. Expected 1")); }

	unsigned size = 0;

  for(unsigned x = 0; args[1][x] != '\0'; x++)
	{
		if((args[1][x] < '0' || args[1][x] > '9') && args[1][0] != '-' && args[1][0] != '+') { printf("The parameter needs to be a number, not a text or expression\n"); return 0; }

		else if(args[1][0] == '+' || args[1][0] == '-') { printf("The parameter needs to be a number without sinals\n"); return 0; }

		size += (args[1][x] - '0') * pow(10, strlen(args[1]) - (x+1));
	}

	printf("\n");

	for(unsigned row = 0; row < size / 2 + size % 2; row++)
	{
		for(unsigned col = 0; col < size; col++)
		{
			if(col < row || col > size - (row+1)) printf("  ");
			else printf("%u ", col + 1);
		}

		printf("\n");
	}

	printf("\n");

	return 0;
}
