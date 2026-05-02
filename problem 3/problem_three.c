#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool isPrime(long long unsigned int number);

int main(){
    long long unsigned int n, max_pfactor = 2;
    printf("Enter an integer: ");
    scanf("%llu", &n);

    while(n){
        for(int i = 1; i <= n; i++){
            if(n % i == 0 && isPrime(i) && max_pfactor < i){
                max_pfactor = i;
                break;
            }
        } n /= max_pfactor;
    }

    printf("Largest prime factor: %llu\n", max_pfactor);

    return 0;
}

bool isPrime(long long unsigned int number){
    if(number < 2){
        return false;
    } else{
        long long unsigned int idx, stop = (int)pow(number, 0.5) + 1, count = 0;
        for(idx = 1; idx <= stop; idx++){
            if(number % idx == 0){
                count += 1;
            }
        }
        return count == 1;
    }
}