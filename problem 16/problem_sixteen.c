#include <stdio.h>
#include<string.h>
#include <gmp.h>

int main() {
    // 1. Initialize the large integer types
    mpz_t base, result;
    mpz_init(result);
    mpz_init_set_ui(base, 2); // Set base to 2

    // 2. Calculate 2^1000
    // mpz_pow_ui(destination, base, exponent)
    mpz_pow_ui(result, base, 1000);

    // 3. Convert the result to a string to sum the digits
    char *numStr = mpz_get_str(NULL, 10, result);
    
    unsigned long long int total = 0;
    for (int i = 0; numStr[i] != '\0'; i++) {
        total += numStr[i] - '0'; // Convert char digit to int
    }

    // 4. Output the result
    printf("The sum of the digits of 2^1000 is: %llu\n", total);

    // 5. Clean up memory
    void (*freefunc)(void *, size_t);
    mp_get_memory_functions(NULL, NULL, &freefunc);
    freefunc(numStr, strlen(numStr) + 1);
    mpz_clear(base);
    mpz_clear(result);

    return 0;
}