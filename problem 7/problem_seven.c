#include<stdio.h>
#include<math.h>
#include<stdbool.h>

bool isPrime(unsigned long long int number);

int main(){
    int i = 1; 
    unsigned long long int j = 2;
    while(i <= 10001){
        if(isPrime(j)){
            printf("%d-->%llu\n", i, j);
            i += 1;
        } j += 1;
    }
    return 0;
}

bool isPrime(unsigned long long int number){
    unsigned long long int idx, L = (int)pow(number, 0.5) + 1, count = 0;
    for(idx = 1; idx < L; idx++){
        if(number % idx == 0){
            count += 1;
        }
    }
    return count == 1;
}
