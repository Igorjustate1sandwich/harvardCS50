#include <stdio.h>

int main()
{
	int count = 3;

	 for (int i = 0; i <  count-1; i++) // MASSIVE NOTE FOR WHY YOU GET 3 AS OUTPUT!! COUNT = 0 HERE AS BASELINE. SEE WHAT HAPPENS WHEN REMOVE NUMERICALS.
    {
		printf("OUTER LOOP:	i = %i \n", i);

        for (int j = 0; j < count-i-1; j++) // SAME AS ^
        {
			printf("INNER LOOP:	i = %i, count = %i \n", i, count);
        }
    }
}