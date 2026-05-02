#include<stdio.h>
#include<math.h>

#define MAX_LEN 100000

int main(){
    FILE *file=fopen("file.txt", "r");
    if(!file){
        printf("Error opening file\n");
        return 1;
    } 

    int digits[MAX_LEN];
    char ch;
    int idx_i = 0, count = 0;

    while((ch = fgetc(file)) != EOF){
        digits[idx_i++] = ch - '0'; 
        count += 1;
    }

    printf("\nNumber of digits in the number = %d\n", count);

    for(idx_i = 0; idx_i < count; idx_i++){
        printf("%d", digits[idx_i]);
    } 

    printf("\n\n");

    // Main Solution
    int term, idx_j;
    long long unsigned int max_product = 1, product, req_num = 1, temp_num = 0;
    printf("Enter term: ");
    scanf("%d", &term);

    int copy = term - 1;

    for(idx_i = 0; idx_i < count - term; idx_i++){
        product = 1;
        for(idx_j = 0; idx_j < term; idx_j++){
            temp_num += digits[idx_i + idx_j] * pow(10, copy);
            copy -= 1;  
            product *= digits[idx_i + idx_j];
        }
        if(max_product < product){
            max_product = product;
            req_num = temp_num;
        }
        temp_num = 0;
        copy = term - 1;
    }

    printf("\n");
    printf("the %d adjacent digits in the 1000-digit number that have the greatest product = %llu\n", term, req_num);
    printf("the product = %llu\n", max_product);

    return 0;
}