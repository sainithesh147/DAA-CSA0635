#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(const char *str) {
    int length = strlen(str);
    int i, j;

    char lowercaseStr[length + 1];
    for (i = 0; i < length; i++) {
        lowercaseStr[i] = tolower(str[i]);
    }
    lowercaseStr[length] = '\0';

    i = 0;
    j = length - 1;
    while (i < j) {
        while (!isalnum(lowercaseStr[i]) && i < j) {
            i++;
        }
        while (!isalnum(lowercaseStr[j]) && i < j) {
            j--;
        }
        if (lowercaseStr[i] != lowercaseStr[j]) {
            return 0; 
        }
        i++;
        j--;
    }
    return 1; 
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    if (str[strlen(str) - 1] == '\n') 
	{
        str[strlen(str) - 1] = '\0';
    }

    if (isPalindrome(str)) 
	{
        printf("%s is a palindrome.\n", str);
    } 
	else 
	{
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}
