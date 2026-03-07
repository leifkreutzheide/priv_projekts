#include <stdio.h>
#include <stdlib.h>

void getDigits(int n, int possibilities[5]);

int main() {

int possibilities[252];
int arr²[252][5]; // arr²[row][column]. arr²[i] gives a 5 digit array that lies at the i-th row
int i = 0;

FILE *ptr = fopen("possibilities_no_repeats.txt", "r");
        if (ptr == NULL) {
            printf("failed to open file + youre fat\n");
            return 1; }

    while (fscanf(ptr, "%d", &possibilities[i]) == 1) // "while (fscanf reads %d (one line at a time) and stores them @ &possibilites at index i) is still working/true/1 then i++"
    {
        i++;
    } fclose(ptr);

//if (arr3[0] == arr3[1] && arr3[1] == arr3[2] && arr3[2] == arr3[3] && arr3[3] == arr3[4])

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