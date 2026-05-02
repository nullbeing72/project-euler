#include<stdio.h>

int main(){
    unsigned long long int a, b, total, term;

    a = 1;
    b = 2;
    total = b;

    while(term < 4000000){
        term = a + b;
        if(term % 2 == 0){
            total += term;
        } 

        a = b;
        b = term;
    }

    printf("%llu\n", total);

    return 0;
}

// 4613732