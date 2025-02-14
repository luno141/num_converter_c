#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert a character to its integer value
int charToValue(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    return -1; // Invalid character
}

// Function to convert an integer value to its character representation
char valueToChar(int value) {
    if (value >= 0 && value <= 9) return value + '0';
    if (value >= 10 && value < 36) return value - 10 + 'A';
    return '?'; // Invalid value
}

// Function to convert a number from any base to base 10
long long toDecimal(const char* num, int base) {
    long long result = 0;
    int length = strlen(num);
    for (int i = 0; i < length; i++) {
        int value = charToValue(num[i]);
        if (value >= base || value < 0) {
            printf("Invalid digit '%c' for base %d\n", num[i], base);
            exit(EXIT_FAILURE);
        }
        result = result * base + value;
    }
    return result;
}

// Function to convert a decimal number to any base
void fromDecimal(long long decimal, int base, char* result) {
    int index = 0;
    while (decimal > 0) {
        result[index++] = valueToChar(decimal % base);
        decimal /= base;
    }
    result[index] = '\0';
    // Reverse the result
    for (int i = 0, j = index - 1; i < j; i++, j--) {
        char temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }
}

int main() {
    char number[100], result[100];
    int fromBase, toBase;

    // User input
    printf("Enter the number: ");
    scanf("%s", number);
    printf("Enter the base of the input number: ");
    scanf("%d", &fromBase);
    printf("Enter the base to convert to: ");
    scanf("%d", &toBase);

    // Conversion
    long long decimal = toDecimal(number, fromBase);
    fromDecimal(decimal, toBase, result);

    // Output the result
    printf("The number %s in base %d is %s in base %d.\n", number, fromBase, result, toBase);

    return 0;
}
 