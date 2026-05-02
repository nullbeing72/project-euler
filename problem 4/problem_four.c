#include<stdio.h>
#include<stdbool.h>

bool isPalindrome(long long unsigned int number);

int main(){
    long long unsigned int i, j, max_palindrome;

    max_palindrome = 100 * 100;

    for(i = 100; i < 1000; i++){
        for(j = 100; j < 1000; j++){
            if(isPalindrome(i * j) && max_palindrome < i * j){
                max_palindrome = i * j;
            }
        }
    } printf("Largest palindrome made from the product of two 3-digit number = %llu\n", max_palindrome);

    return 0;
}

bool isPalindrome(long long unsigned int number){
    long long unsigned int copy = number, reverse = 0;
    while(copy){
        reverse = (reverse * 10) + (copy % 10);
        copy /= 10;
    }
    return reverse == number;
}