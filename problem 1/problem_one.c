#include<stdio.h>

int main(){
    unsigned int idx, total = 0;
    
    for(idx = 1; idx < 1000; idx++){
        if(idx % 3 == 0 && idx % 5 == 0){
            total += idx;
        } else if(idx % 3 == 0){
            total += idx;
        } else if(idx % 5 == 0){
            total += idx;
        }
    }

    printf("%lu\n", total);
    return 0;
}