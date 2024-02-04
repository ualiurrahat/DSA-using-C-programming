// quick sort
// here, we have always taken the last element of array as pivot.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to part the array into two part.
// using a pivot
int partition(int A[], int low, int high)
{
    int pivot, i, j, t;
    // selecting pivot
    pivot = A[high];

    // loop to place pivot in its right order
    for (i = low - 1, j = low; j < high; j++)
    {
        if (A[j] < pivot)
        {
            // need to exchange place between A[j] and A[i]
            i = i + 1;
            t = A[j];
            A[j] = A[i];
            A[i] = t;
        }
    }
    // now we need to place pivot rightly
    // till index i, array is sorted
    // i+1 is the place for pivot
    // placing pivot
    t = A[high];
    A[high] = A[i + 1];
    A[i + 1] = t;

    // function returns pivot's index.
    return i + 1;
}

// function to perform quick sort
// 3 parameters: array that be sorted, low = index of first element, high = index of last element
void quick_sort(int A[], int low, int high)
{
    // base condtion
    // if array has one element(low = high) or no elemnet(low>high)
    // array is sorted. so need to return from the function.
    if (low >= high)
    {
        return;
    }

    int p; // p is the index of pivot
    // partion function returns the index of pivot
    p = partition(A, low, high);

    // after calling partition function,A[p] now is in right place.
    // now will sort the numbers postioning before and after A[p].

    // sorting numbers from index low to p-1
    quick_sort(A, low, p - 1);

    // sorting numbers from index p+1 to high
    quick_sort(A, p + 1, high);
}

int main()
{
    int i, n = 8;
    int A[] = {1, 5, 6, 3, 5, 8, 7, 2, 9};

    quick_sort(A, 0, n);

    for (i = 0; i <= n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}