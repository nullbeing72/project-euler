#include<stdio.h>

int main(){
    unsigned long int idx, total1, total2;

    for(idx = 1; idx <= 100; idx++){
        total1 += idx;
        total2 += idx * idx;
    }
    total1 *= total1;

    printf("%lu\n", total1 - total2);  
    
    return 0;
}