/*
    Author: MD.Ualiur Rahman Rahat

*/

/* Code Topic: linear search algorithm.
    We have to fina a particular number from a given array using linear search algorithm.
    If the number is found in the array, the algo will return its index in the array.
    If not found, algo will return -1.
*/

#include <stdio.h>
#include <stdlib.h>

// function to perform linear search.

int linear_search(int array[], int n, int x)
{
    // array[] has total n elements and we need to check if x exits or not in the array.
    int i;
    // traversing the whole array to find the number x.
    for (i = 0; i < n; i++)
    {
        if (array[i] == x)
        {
            return i; // number is found in the ith index of the array.
        }
    }
    // in case the number x is not found.
    i = -1;
    return i;
}

int main()
{
    int n, i, arr[100];

    printf("Enter total number of elements in the array: ");
    scanf("%d", &n);

    // user input for array elements.
    printf("Enter your array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int findNumber;
    printf("Enter the number you wish to find: ");
    scanf("%d", &findNumber);

    // linear search function to search the number.
    // returns index of the number if found in the array.
    // returns -1 if not found in the array.

    int index = linear_search(arr, n, findNumber);

    printf("\n");

    // displaying result of the linear search
    if (index != -1)
    {
        printf("The element is found at position %d\n", index + 1);
    }
    else
    {
        printf("The element is not found in the array.\n");
    }

    return 0;
}
