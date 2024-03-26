#include <stdio.h>

int findLargest(int arr[], int n) 
{
    int max = arr[0]; 
    int i;
    for ( i = 1; i < n; i++) 
	{
        if (arr[i] > max) 
		{
            max = arr[i]; 
        }
    }

    return max;
}

int main() 
{
    int arr[100], n,i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for ( i = 0; i < n; i++) 
	
	{
        scanf("%d", &arr[i]);
    }

    int largest = findLargest(arr, n);

    printf("The largest element in the array is: %d\n", largest);

    return 0;
}
