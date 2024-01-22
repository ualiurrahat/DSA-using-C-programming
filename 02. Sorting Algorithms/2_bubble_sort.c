/*
    Author: MD. Ualiur Rahman Rahat

*/

/* Code Topic: Implementation of bubble sort algorithm.
    We have to sort a given array in increasing order with the
    use of bubble sort algorithm.

    Complexity: O(n^2).

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// function to perform bubble sort algo.

void bubble_sort(int a[], int n)
// takes two parameters: an array, total number of elements in the array.
{
    int i, j, temp;

    // running loop to sort the array.
    for (i = 0; i < n ; i++)
    {
        
        for (j = 0; j < n - i - 1; j++)
        {
            // checking if the number with  index j is greater than the number with j+1 index
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                
            }
        }
        
    }
}

int main()
{

    int n, i;

    // user input for total number of elements.
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    // creating array to store the elements.
    int arr[n];

    //user input for array elements.
    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // displaying input array.
    printf("\n\n");
    printf("Input array before sorting: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // performing bubble sorting using the function.

    bubble_sort(arr, n);

    // displaying array after selection-sorting.

    printf("\n\n");
    printf("Array after sorting: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
