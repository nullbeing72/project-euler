#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMES 50000
#define MAX_LEN 50

int cmp(const void *a, const void *b);

int main() {
    FILE *file = fopen("file.txt", "r");
    if (!file) {
        printf("Error opening file\n");
        return 1;
    }

    char names[MAX_NAMES][MAX_LEN];
    int count = 0;

    char ch;
    char buffer[MAX_LEN];
    int idx = 0;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '"') {
            continue; // skip quotes
        }
        else if (ch == ',') {
            buffer[idx] = '\0';           // end string
            snprintf(names[count], MAX_LEN, "%s", buffer);
            count++;
            idx = 0;                     // reset buffer
        }
        else {
            buffer[idx++] = ch;          // build string
        }
    }

    // last element (important!)
    if (idx > 0) {
        buffer[idx] = '\0';
        snprintf(names[count], MAX_LEN, "%s", buffer);
        count++;
    }

    fclose(file);

    printf("Total names: %d\n", count);

    printf("\n");

    printf("Before Sorting:\n");
    int i;
    for (i = 0; i < count; i++) {
        printf("%s\t", names[i]);
    }

    printf("\n\n");
    
    // sort
    printf("sorting...\n");
    qsort(names, count, sizeof(names[0]), cmp);
    printf("After Sorting:\n");
    for (i = 0; i < count; i++) {
        printf("%s\t", names[i]);
    }

    printf("\n");

    // Main Solution
    long long total = 0;

    for (int i = 0; i < count; i++) {
        int value = 0;

        for (int j = 0; names[i][j] != '\0'; j++) {
            value += names[i][j] - 'A' + 1;
        }

        total += (long long)(i + 1) * value;
    }

    printf("Total score = %lld\n", total);

    return 0;
}

int cmp(const void *a, const void *b) {
    return strcmp((char*)a, (char*)b);
}