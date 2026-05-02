#include <stdio.h>
#include <gmp.h>
#include<stdlib.h>

int main() {
    mpz_t fact;
    mpz_init_set_ui(fact, 1);  // fact = 1

    // Compute 100!
    for (int i = 2; i <= 100; i++) {
        mpz_mul_ui(fact, fact, i);
    }

    // Convert factorial to string
    char *str = mpz_get_str(NULL, 10, fact);

    // Sum digits
    int sum = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        sum += str[i] - '0';
    }

    printf("Sum of digits of 100! = %d\n", sum);

    // Free memory
    free(str);
    mpz_clear(fact);

    return 0;
}