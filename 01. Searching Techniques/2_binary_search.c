/*
    Author: MD.Ualiur Rahman Rahat

*/

/* Code topic: Binary search algorithm.
    We will try to find a particular number from a given array.
    If the number is found in the array, the algo will return its index in the array.
    If not found, the algo will return -1.

    Complexity: O(log n)

    Condition: The array needs to be sorted first.
    So Insert an array which is sorted.
    Otherwise code will not work as expected.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to perform binary search algorithm.

int binary_search(int A[], int n, int x)
{
    // vat to store index of the numbers.
    int left_index, right_index, mid_index;
    left_index = 0;
    right_index = n - 1;

    while (left_index <= right_index)
    {
        mid_index = (left_index + right_index) / 2;

        // Case when we find the number.
        if (A[mid_index] == x)
        {
            return mid_index; // x was found in this number of index.
        }

        // Case when mid index number is greater than the searched number.

        else if (A[mid_index] > x)
        {
            right_index = mid_index - 1;
        }

        // case when mid index number is less than the searched number.
        else
        {
            left_index = mid_index + 1;
        }
    }

    // in case when the number is not found.
    return -1;
}

int main()
{
    // here we have taken a sorted array
    // you can change the array elements.
    // but make sure the elements are sorted first.
    int arr[20] = {1, 4, 6, 7, 10, 19, 22, 23, 30, 35, 39, 46, 49, 50, 52, 55, 61, 67, 70, 71};

    // let's find the number 46 in the array. You can try with other numbers too.
    int findNumber = 46;

    // var for total number of elements in the array.
    int totalElements = 20;

    // now performing binary search with the help of the funciton binary_search.
    int index = binary_search(arr, totalElements, findNumber);

    // displaying output of the binary search.
    if (index != -1)
    {
        printf("The element is found at the position %d\n", index + 1);
    }
    else
    {
        printf("The element is not found.\n");
    }

    return 0;
}