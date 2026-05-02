#include<stdio.h>

long long unsigned int gcd(long long unsigned int a, long long unsigned int b);

int main(){
    long long unsigned int n, idx, product;
    printf("Enter a number: ");
    scanf("%llu", &n);

    product = n;

    for(idx = 1; idx < n; idx++){
        if(product % idx != 0){
            product *= idx / gcd(product, idx);
        }
    }

    printf("Smallest positive number that is evenly divisible by all of the numbers from 1 to %llu = %llu\n", n, product);

    return 0;
}

long long unsigned int gcd(long long unsigned int a, long long unsigned int b){
    if(a == 0 && b == 0){
        return 0;
    }else if(a == 0){
        return b;
    } else if(b == 0){
        return a;
    } else{
        return gcd(b, a % b);
    }
}

// Explanation
// n = 20
// Consider the number to be 20
// Is 20 divisible by 1? Yes (We do not have to bother about 1, since 1 is already a factor of 1)
// Is 20 divisible by 2? Yes (We do not have to bother about 1, since 1 is already a factor of 2)
// Is 20 divisible by 3? No  (Since the number is not divisible by 3, the number must be modified. --> 20 * 3 = 60)
// Is 60 divisible by 4? Yes 
// Is 60 divisible by 5? Yes
// Is 60 divisible by 6? Yes
// Is 60 divisible by 7? No  (The number must be modified. --> 60 * 7 = 420)
// Is 420 divisible by 8? No (Since, 420 is already divisible by 4, we need to multiply 420 by 2 so that the number becomes divisible by 8)
//                           (So, the number gets modified into: 420 * 2 = 840 which is divisible by 8)
// How to get 2? gcd of 420 and 8 is 4. And 8 / 4 = 2
// The process goes on till 19.           