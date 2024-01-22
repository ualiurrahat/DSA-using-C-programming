/*
    Author: MD. Ualiur Rahman Rahat

*/

/* Code Topic: Selection sort algorithm.
    We have to sort a given array in increagin order.
    Using selection sort algorithm.

*/

#include <stdio.h>

// function to perform selection sorting.
void selection_sort(int a[], int n) // function takes an array and its total number of elements as input.
{
    int i, j;
    int index_min, temp;

    // loop from index 0 to n-1 to sort the numbers.
    for (i = 0; i < n - 1; i++)
    {
        // now declaring the ith number as the lowest.
        // so i is the index for the lowest numbers.
        index_min = i;

        // loop to check if any number from i+1 to the last index having lower value than the ith number.
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[index_min])
            {
                // since a[j] is lower than ith number.
                // so updating index for the lowes number's index.
                index_min = j; //
            }
        }

        if (index_min != i)
        {
            // in case i was not the lowest among the numbers.
            // now exchanging postion of the two numbers to sort the array.
            temp = a[i];
            a[i] = a[index_min];
            a[index_min] = temp;
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
    printf("\n");
    printf("Input array before sorting: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    //using function to perform selection sorting.
    selection_sort(arr, n);

    // displaying array after selection-sorting.

    printf("\n\n");
    printf("Array after sorting: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
