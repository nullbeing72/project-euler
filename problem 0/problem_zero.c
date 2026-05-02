#include<stdio.h>
#include<math.h>

int main(){
    unsigned long long int idx, total = 0;

    printf("\tcurrent total: %llu\n", total);
    for(idx = 1; idx <= 521000; idx += 2){
        printf("idx: %llu\n", idx);
        total += (unsigned long long int)pow(idx, 2);
        printf("\tcurrent total: %llu\n", total);
    }

    printf("\n");
    printf("%llu\n", total);

    return 0;
}

// 23570126833246500 
