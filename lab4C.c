#include <stdio.h>
#include <string.h>

char* removeDigit(char* number, char digit) {
    int n = strlen(number);
    
    for (int i = 0; i < n - 1; i++) {
        if (number[i] == digit && number[i] < number[i + 1]) {
            memmove(&number[i], &number[i + 1], n - i);
            return number;
        }
    }
    
    for (int i = n - 1; i >= 0; i--) {
        if (number[i] == digit) {
            memmove(&number[i], &number[i + 1], n - i);
            break;
        }
    }
    
    return number;
}

int main() {
    char number1[] = "1231";
    char digit1 = '1';
    printf("Result after removing '%c' from \"%s\": %s\n", digit1, number1, removeDigit(number1, digit1));

    char number2[] = "551";
    char digit2 = '5';
    printf("Result after removing '%c' from \"%s\": %s\n", digit2, number2, removeDigit(number2, digit2));

    char number3[] = "7654321";
    char digit3 = '6';
    printf("Result after removing '%c' from \"%s\": %s\n", digit3, number3, removeDigit(number3, digit3));

    return 0;
}
