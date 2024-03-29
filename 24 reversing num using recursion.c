#include <stdio.h>

int reverseNumber(int num) {

    if (num < 10) {
        return num;
    }

    else {

        int lastDigit = num % 10;
  
        int reversed = reverseNumber(num / 10);

        return lastDigit * pow(10, (int)log10(num)) + reversed;
    }
}

int main() {
    int number;
    
    
    printf("Enter a number: ");
    scanf("%d", &number);
    

    int reversedNumber = reverseNumber(number);
    

    printf("Reversed number: %d\n", reversedNumber);
    
    return 0;
}
