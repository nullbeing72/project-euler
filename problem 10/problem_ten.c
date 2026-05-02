#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool isPrime(long long unsigned int number);

int main(){
    long long unsigned int n, i, sum = 0;
    printf("Enter number: ");
    scanf("%llu", &n);

    for(i = 1; i <= n; i++){
        if(isPrime(i)){
            sum += i;
        }
    } 
    
    printf("Sum of all primes below %llu = %llu\n", n, sum);

    return 0;
}

bool isPrime(long long unsigned int number){
    if(number < 2){
        return false;
    } else{
        long long unsigned int idx, stop = (int)pow(number, 0.5) + 1, count = 0;
        for(idx = 1; idx < stop; idx++){
            if(number % idx == 0){
                count += 1;
            }
        } 
        return count == 1;
    }
}