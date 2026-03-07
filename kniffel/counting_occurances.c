#include <stdio.h>
#include <stdlib.h>


int checkedDicesNoRepeats[7000];
int allRolls[7776];
int one = 0;
int five = 0;
int ten = 0;
int twenty = 0;
int thirty = 0;
int sixty = 0;
int onetwenty = 0;



int main(void) {

    FILE *f = fopen("C:/Users/Leifh/my vcs code/VCS/output.txt", "r"); 
    if (!f) { perror("fopen"); return 1; }

    int num, i = 0;
    while (i < 7776 && fscanf(f, "%d", &num) == 1) {
        allRolls[i++] = num;   
    }
    fclose(f);
     

    int a = 0;
    int j = 0;
    int q = 0;
    int z = 0;
    int u;
    int current;
    int howManyAreIn = 0;
    int occurances = 0;

    while (a < 7776) {

    current = allRolls[a]; 
    a++;


    for ( j = 0; j <= howManyAreIn; j++) // checks the checked dice array to see if we have already counted this combination
    {
        if (current == checkedDicesNoRepeats[j]) {
            goto somewhere; // to do: place other side
        }
        
    }

    

    checkedDicesNoRepeats[q] = current; 
    q++; 
    howManyAreIn++; 



    for (z = (a-1); z < 7776; z++)
    {
        if (current == allRolls[z])
        {
            occurances++;
        }
        
    }
    
    switch (occurances) {
    case 1:   one++;       break;
    case 5:   five++;      break;
    case 10:  ten++;       break;
    case 20:  twenty++;    break;
    case 30:  thirty++;    break;
    case 60:  sixty++;     break;
    case 120: onetwenty++; break;
}


    printf("%d) %d kommt %d mal vor\n", howManyAreIn, current, occurances); // prints how many times every UNIQUE Roll occurs
    somewhere: 
    occurances = 0;
    
}
/*
printf("\nes gibt %d Zahlen, die nur einmal vorkommen\n", one);
printf("es gibt %d Zahlen, die fünf mal vorkemmen\n", five);
printf("es gibt %d Zahlen, die zehn mal vorkommen\n", ten);
printf("es gibt %d Zahlen, die zwangzig mal vorkommen\n", twenty);
printf("es gibt %d Zahlen, die dreizig mal vorkommen\n", thirty);
printf("es gibt %d Zahlen, die sechtszig mal vorkommen\n", sixty);
printf("es gibt %d Zahlen, die HUNDERTZWANGZIG mal vorkommen\n", onetwenty);
printf(" \nmost likely to least likely: no duplicates, one dublicate, two duplicates, one triple, a triple and a duplicate, a quad, quintuple\n"); */


    return 0;

}
      
         
    
 