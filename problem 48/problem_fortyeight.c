#include <stdio.h>
#include <gmp.h>

int main() {
    mpz_t number, idx, term, total, mod;

    mpz_inits(number, idx, term, total, mod, NULL);
    mpz_set_ui(total, 0);

    // mod = 10^10 (to get the last 10 digits)
    mpz_ui_pow_ui(mod, 10, 10);

    gmp_printf("Enter number: ");
    gmp_scanf("%Zd", &number);

    for (mpz_set_ui(idx, 1); mpz_cmp(idx, number) <= 0; mpz_add_ui(idx, idx, 1)) {
        mpz_pow_ui(term, idx, mpz_get_ui(idx)); // term = idx^idx
 
        mpz_add(total, total, term);
    }

    mpz_mod(total, total, mod);

    gmp_printf("Last ten digits of the series = %Zd\n", total);

    mpz_clears(number, idx, term, total, mod, NULL);

    return 0;
}