#include <stdio.h>

int main()
{
    int pages_read, size, symbol_count, dots = 10;

    printf("** Sahils book progress tracker ** \n");
    printf("Enter how many pages you have read: ");
    scanf(" %d", &pages_read);
    printf("Enter size of book: ");
    scanf(" %d", &size); printf("\n");

    int progress = 100 * (float)pages_read / size;
    /* 
    Note that regular divison is required for this basic formula to
    work. That means having at least one FLOAT on either side of the
    division (/) symbol. 

    Without the float, this would simply be integer division, which
    is inaccurate. e.g. 5/2 would equal 2 instead of 2.5 because everything
    after the decimal point is cut off.
    */

   // Get first digit via integer division
   while (progress >= 10)
   {
       symbol_count = progress/ 10;
       break;
   }

    printf("You have read %d%% of the book! \n", progress);
    printf("If you read 25 pages a day, you will be finished after %.1f days! \n", 
    (size - pages_read) / 25.00);
    
    // Visual progress bar
    if (progress >= 10)
    {
        printf("Progress Bar:           [");
        for (int i = 0; i < symbol_count; i++)
        {
            printf("##");
        }

        for (dots = 10; dots > symbol_count; dots--)
        {
            printf("..");
        }
        printf("]");
        printf("\n");
    }
}