/*
    Author: MD. Ualiur Rahman Rahat

*/

/* Code Topic: Implementation of insertion sort algorithm.
    We have to sort a given array in increasing order with the
    use of insertion sort algorithm.

    Complexity: worst case-> O(n^2).
                best case -> O(n)

*/

#include <stdio.h>

// function to perform insertion sorting.

void insertion_sort(int a[], int n) // takes an array, and an interger n indicating the size of the array as input.
{
    int i, j, item;

    for(i = 1; i < n; i++)
    {
        // assigning value of a[i] to variable item.
        item = a[i];

        // now we have to search the perfect place for the item element.
        j = i - 1;

        while(j >= 0 && a[j] > item) // j has to be greater than 0 as it indicates index of the element.
        {
            a[j+1] = a[j]; // shifting the a[j] to the right as it is bigger than the item.
            j = j-1;        // changing value of j;

        }

        // now a[j+1] is empty and we have to store item there.
        a[j+1] = item;
    }
}

int main()
{
    int n,i;
    printf("Enter total elements in arra: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements: \n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nUser input array: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // sorting the array.
    insertion_sort(arr, n);

    printf("\nArray after sorting: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }


}

