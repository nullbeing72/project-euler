#include<stdio.h>
#include<math.h>

#define PHI (1 + sqrt(5))/2

int main(){
    unsigned int term = 1, numberOfDigit;

    while(1){
        numberOfDigit = (unsigned int)floor(term * log10(PHI) - log10(sqrt(5))) + 1;
        if(numberOfDigit == 1000){
            printf(" index of the first term in the Fibonacci sequence to contain 1000 digits: %u\n", term);
            break;
        }
        term += 1;
    }

    return 0;
}