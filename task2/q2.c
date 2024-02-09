#include <stdio.h>

// swap function using XOR 
void swap(void *a, void *b, size_t size) {
     char *byte_a = (char *)a;
      char *byte_b = (char *)b;

    for (size_t i = 0; i < size; ++i) {
        byte_a[i] ^= byte_b[i];
        byte_b[i] ^= byte_a[i];
        byte_a[i] ^= byte_b[i];
    }
}

int main() {
    // Example with integers
    int x = 5, y = 10;

    printf("Before swapping: x = %d, y = %d\n", x, y);
    swap(&x, &y, sizeof(int));
    printf("After swapping: x = %d, y = %d\n", x, y);

    // Example with floats
    float a = 3.14, b = 2.718;

    printf("\nBefore swapping: a = %.2f, b = %.2f\n", a, b);
    swap(&a, &b, sizeof(float));
    printf("After swapping: a = %.2f, b = %.2f\n", a, b);
    return 0;
}


