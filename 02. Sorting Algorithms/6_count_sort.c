
// counting sort
/* If we have m number of +ve intergers and if they are within limit to the number n
then we can sort them in time complexity O(m+n) using counting sort.

conditions:
1. all the input must be +ve integers
2. the highest value of the input must be known

*/

// here we will sort an array using countion sort.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    int A[] = {3, 4, 1, 6, 2, 4, 9, 7, 8, 4, 2, 1};
    // total elements 12 . all are +ve
    // let highest num be 10.
    // will declare an array with 10+1 size
    int n = 12;
    int count[11];

    // initializing each element in the array with value 0
    for (int i = 0; i < 11; i++)
    {
        count[i] = 0;
    }

    // counting the total appearance of elements

    for (int i = 0; i < n; i++)
    {
        int x = A[i];
        count[x]++;
    }

    // printing each element as index with its total appearance
    for (int i = 0; i < 11; i++)
    {
        printf("index : %d, count value: %d\n", i, count[i]);
    }

    printf("here is the sorted array: \n");
    int i, j;

    for (i = 1; i < 10; i++)
    {
        for (j = 1; j <= count[i]; j++)
        {
            printf("%d ", i);
        }
    }

    return 0;
}
