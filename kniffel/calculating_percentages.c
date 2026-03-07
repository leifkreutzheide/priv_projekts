#include <stdio.h>
#include <stdlib.h>

void getDigits(int n, int possibilities[5]);

// all subsets
int kniffel[6];
int k = 0; 
int großeStraße[50];
int gs = 0; 
int kleineStraße[50];
int ks = 0; 
int fullHouse[60];
int fh = 0; 
int triple[60];
int t = 0; 
int quad[60];
int q = 0; 
int other[200];
int q = 0; 

int possibilities[252];
int arr²[252][5]; // arr²[row][column]. arr²[i] gives a 5 digit array that lies at the i-th row
int i = 0;

int main() {

//----------------------------- reading possibilities out of file

FILE *ptr = fopen("possibilities_no_repeats.txt", "r");
        if (ptr == NULL) {
            printf("failed to open file + youre fat\n");
            return 1; }

    while (fscanf(ptr, "%d", &possibilities[i]) == 1) // "while (fscanf reads %d (one line at a time) and stores them @ &possibilites at index i) is still working/true/1 then i++"
    {
        i++;
    } fclose(ptr);

//----------------------------- creating a 2D array out of a 1D array

for (int n = 0; n < 252; n++) {
    getDigits(possibilities[n], arr²[n]);
}

//----------------------------- sorting all possibilities into their subsets

for (int j = 0; j < 252; j++){

    // kniffel
    if (arr²[j][0] == arr²[j][1] && arr²[j][1] == arr²[j][2] && arr²[j][2] == arr²[j][3] && arr²[j][3] == arr²[j][4]) {
        kniffel[k] = 10000*arr²[j][0] + 1000*arr²[j][1] + 100*arr²[j][2] + 10*arr²[j][3] + arr²[j][4];
        k++; }

    // große Straße

    // kleine Straße

    // full house
    if (arr²[j][0] == arr²[j][1] && arr²[j][1] != arr²[j][2] && arr²[j][2] == arr²[j][3] && arr²[j][3] == arr²[j][4]){
        fullHouse[fh] = 10000*arr²[j][0] + 1000*arr²[j][1] + 100*arr²[j][2] + 10*arr²[j][3] + arr²[j][4];
        fh++;
    }
}


for (int n = 0; n < 252; n++) {
    getDigits(possibilities[n], arr²[n]);
}


printf("%d, %d, %d, %d, %d\n", arr²[0][0], arr²[0][1], arr²[0][2], arr²[0][3], arr²[0][4]);


return 0;
}



// getDigits take in an int n (the to-be-chopped-up int) and an Array to which the chopped parts will be passed to (passed by reference automatically bc its an array).
// i is last index from the Array. 
// digits[i] = ... writes directly into my original array.
// digits are extraced right to left. LSB to MSB
// with the modulo operator % -->  Dividing any integer by 10 always leaves the rightmost digit as the remainder:
// n = n/10 chops of the right most digit entierly (remainders are discarded)
//
//

void getDigits(int n, int possibilities[252]) {
    for (int i = 4; i >= 0; i--) {
        possibilities[i] = n % 10;
        n = n/10;
    }
}