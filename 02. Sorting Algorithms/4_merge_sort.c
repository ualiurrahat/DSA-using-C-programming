// Merge sort in C.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to merge the divided two part arrays.
void merge(int A[], int left, int mid, int right)
{
    int i;
    // var for index of array A, L, R.
    int index_a, index_l, index_r;
    // var to store size of array L and R.
    int size_left, size_right;

    size_left = mid - left + 1;
    size_right = right - mid;

    int L[size_left];
    int R[size_right];

    // coping elements A[left] to A[mid] to array L
    for (i = 0; i < size_left; i++)
    {
        L[i] = A[left + i];
    }

    // coping elements A[mid+1] to A[right] to array R
    for (i = 0; i < size_right; i++)
    {
        R[i] = A[mid + 1 + i];
    }

    index_l = 0;
    index_r = 0;

    // loop to sort the arrays and place them in A

    for (index_a = left; index_l < size_left && index_r < size_right; index_a++)
    {
        if (L[index_l] < R[index_r])
        {
            A[index_a] = L[index_l];
            index_l++;
        }
        else
        {
            A[index_a] = R[index_r];
            index_r++;
        }
    }

    // now two things can happen here.
    // 1. all the elements of L and R have merged into A.
    // 2. some elements of A or B still left to be merged.
    // so, any of the two loops given below will run
    // but both the will not be running.

    // if L has some element left, we are coping this in A

    while (index_l < size_left)
    {
        A[index_a] = L[index_l];
        index_l++;
        index_a++;
    }

    // if R has some element left, we are coping this in A

    while (index_r < size_right)
    {
        A[index_a] = R[index_r];
        index_a++;
        index_r++;
    }

    // now Array has been completely merged.
}

// function to perform merge-sort algorithm.

// takes array A which needs to be sorted.
// left = index of first element
// right = index of last element.

void merge_sort(int A[], int left, int right)
{
    if (left >= right)
    {
        // when array has one element(left == right) or no element(left > right)
        // then array is already sorted.
        // so will return from the function
        return;
    }

    // we need to divide the array into two parts
    // first array will have elements from index left to mid index
    // second will have elements from index mid+1 to right index

    int mid = left + (right - left) / 2;

    // merging A from A[left] to A[mid]
    merge_sort(A, left, mid);

    // merging A from A[mid+1] to A[right]
    merge_sort(A, mid + 1, right);

    // now merging both the merged array
    merge(A, left, mid, right);
}

int main()
{

    int i, n = 8; // n= index of last element.
    int A[] = {1, 5, 6, 3, 8, 4, 7, 2, 9};

    merge_sort(A, 0, n);

    for (i = 0; i <= n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}