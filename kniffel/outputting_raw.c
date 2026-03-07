#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int e;
int d;
int c;
int b;
int a;
int overallCount = 1;

//array of dice (a --> e) with starting values
int dice[5] = {1, 1, 1, 1, 1}; 

//backup of dice
int backup[5];

//how sort function should compare ints: (doesnt need to be in main() or specifically called)
int compareInts(const void *a, const void *b)  {
    return (*(int*)a - *(int*)b);
} 
 

// save, sort, print and restore function
void saveSortPrintRestoreFunction (int dice[5], int backup[5]){

    //save
    memcpy(backup, dice, 5 * sizeof(int));
    //sort  
    qsort(dice, 5, sizeof(int), compareInts);
    //print
    printf("%d%d%d%d%d\n", dice[0], dice[1], dice[2], dice[3], dice[4]);
    //restore
    memcpy(dice, backup, 5 * sizeof(int));

}

//base function that does the printing after cycling:
void printAndCycle(int dice[5]) {
    for (e = 1; e < 7; e++) 
        {
            dice[4] = e;
            saveSortPrintRestoreFunction (dice, backup);
    

        }
        
        
}


void EandD1(int dice[5]){ 

    for (d = 1; d < 7 ; d++)
    {
    dice [3] = d;
    printAndCycle(dice); 
    }

}


 // MAIN FUNCTION // 
int main()                             
{

    int a;
    int b;
    int c;
    int d;
    int e;
    int count = 1;

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
            printf("%d) %d%d%d%d%d\n", count, a, b, c, d, e);
             count = count + 1;
             
        }   
        }   
        }
        }
        
    }
    
    

return 0;
}

