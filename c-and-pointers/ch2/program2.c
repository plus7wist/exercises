#include <stdio.h>
#include <stdlib.h>

int main()
{
	char c;
	int in_stack = 0;
	int good_match = 1;
	while ((c = getchar()) != EOF)
	{
		if (c == '{')
		{
			++in_stack;
		}
		else if (c == '}')
		{
			if (in_stack == 0)
			{
				good_match = 0;
				break;
			}
			--in_stack;
		}
	}
	good_match &= (in_stack == 0);
	puts(good_match ? "good match" : "can not match");
	return 0;
}
