#include<stdio.h>

long long unsigned int triangular(long long unsigned int term);

unsigned int countFactors(long long unsigned int number);

int main(){
    long long unsigned int term = 1, temp;
    unsigned int count;
    while(1){
        temp = triangular(term);
        count = countFactors(temp);
        if(count > 500){
            printf("value of the first triangle number to have over five hundred divisors: %u\n", temp);
            break;
        }
        term += 1; 
    }

    return 0;
}

long long unsigned int triangular(long long unsigned int term){
    return term * (term + 1) / 2;
}

unsigned int countFactors(long long unsigned int number){
    long long unsigned int idx;
    unsigned int exponent = 0, total = 1;
    for(idx = 2; idx * idx <= number; idx++){
        while(number % idx == 0){
            exponent += 1;
            number /= idx;
        } 
        total *= (exponent + 1);
        exponent = 0;
    }
    if(number > 1){
        total *= 2;
    }
    return total;
}