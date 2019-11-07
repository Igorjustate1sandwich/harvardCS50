#include <stdio.h>
#include <strings.h>

int main()
{
    char name1[] = "Foo";
    char name2[] = "FOo";

    int result = strcasecmp(name1, name2);

    printf("%d \n", result);
}


/*
strcasecmp() output codes:
<0 = string1 less than string2
0 = string1 = string2
> 0 = string1 greater than string2
*/