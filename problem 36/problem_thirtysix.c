#include<stdio.h>
#include<stdbool.h>

bool isPalindromeBase2(long long unsigned int number);
bool isPalindromeBase10(long long unsigned int number);

int main(){
    long long unsigned int n, idx, sum = 0;

    printf("Enter a number: ");
    scanf("%llu", &n);

    for(idx = 1; idx < 1000000; idx++){
        if(isPalindromeBase10(idx) && isPalindromeBase2(idx)){
            sum += idx;
        }
    }

    printf("sum of all numbers, less than one million, which are palindromic in base 2 and base 10 = %llu\n", sum);

    return 0;
}

bool isPalindromeBase10(long long unsigned int number){
    long long unsigned int copy = number, reverse = 0;

    while(copy){
        reverse = (reverse * 10) + (copy % 10);
        copy /= 10;
    }

    return number == reverse;
}

bool isPalindromeBase2(unsigned long long n) {
    unsigned long long reversed = 0, temp = n;

    while (temp) {
        reversed = (reversed << 1) | (temp & 1);
        temp >>= 1;
    }

    return reversed == n;
}