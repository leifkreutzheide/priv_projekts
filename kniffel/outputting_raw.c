#include <stdio.h>
#include <stdlib.h>
#include <string.h>





// MAIN FUNCTION // 
int main()                             
{

    int a;
    int b;
    int c;
    int d;
    int e;
    int count = 1;
    int AllPossibilitiesNoRepeats[300];
    int current;

    FILE *raw = fopen("raw_data.txt", "w");  // "w" = write (creates file if not exists)
        if (raw == NULL) {
            printf("failed to open file\n");
            return 1;
        }

    printf("\n");

    for (a = 1; a < 7; a++)
    {

        for (b = 1; b < 7; b++)
        {
            for (c = 1; c < 7; c++)
        {
                for (d = 1; d < 7; d++)
        {
                    for (e = 1; e < 7; e++)
        {
            fprintf(raw, "%d%d%d%d%d\n", a, b, c, d, e); // prints all raw data to raw aka raw_data.txt
             
        }   
        }   
        }
        }
        
    }
    
    fclose(raw); // closes raw_data.txt file

return 0;
}

