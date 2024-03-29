#include <stdio.h>
#include <stdbool.h>


bool isPrime(int n, int i) {
    if (n <= 2)
        return (n == 2) ? true : false;
    if (n % i == 0)
        return false;
    if (i * i > n)
        return true;
    return isPrime(n, i + 1);
}


void printPrimes(int limit, int num) {
    if (num <= limit) {
        if (isPrime(num, 2)) {
            printf("%d ", num);
        }
        printPrimes(limit, num + 1);
    }
}

int main() {
    int limit;
    printf("Enter the limit to generate prime numbers: ");
    scanf("%d", &limit);

    printf("Prime numbers up to %d are: ", limit);
    printPrimes(limit, 2); // Start from 2, as it's the smallest prime number

    return 0;
}
