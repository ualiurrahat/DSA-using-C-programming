/*
Heap is a complet binary tree
whose each node is greater than all its child(max heap)
or lower than all its child(min heap)
note : as heap is a binary tree, each node has max two child.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to find parent node, left child, right child in a heap
int left(int i)
{
    // i is the index of the parent node
    // so index 2i has the left child.
    return 2 * i;
}

int right(int i)
{ // i is the index of the parent node
    // so index 2i+1 has the right child.
    return 2 * i + 1;
}

int parent(int i)
{
    // need to find the parent of the node at i index.
    // i/2 is the index of the parent node.
    return i / 2;
}

// function to determine if a heap is max heap or not.

int is_max_heap(int H[], int heap_size)
{
    int i, p;

    // loop to display node and its parent.
    for (i = heap_size; i > 1; i--)
    {
        p = parent(i);

        printf("i = %d, p = %d\tH[i] = %d, H[p] = %d\n", i, p, H[i], H[p]);

        // checking max heap or min heap
        if (H[p] < H[i])
        {
            //if parent > child, then heap is not max
            return 0;
        }
    }

    // this is a max heap.returning 1.
    return 1;
}

// function to convert a complete binarty tree into a max heap.
// function takes 3 parameters:
// array containing the heap, size of heap
// node of index from where we will form max heap(index i)

void max_heapify(int heap[], int heap_size, int i)
{
    int l, r, largest, t;

    l = left(i);  // l = index of left child of node at index i
    r = right(i); // r = index of right child.

    // checking who is greater between node and left child.

    if (l <= heap_size && heap[l] > heap[i])
    {
        // since, heap[l] is greater, heap[l] will be largest.
        largest = l;
    }
    else
    {
        largest = i;
    }

    // checking who is greater between largest(found in above code) and right child
    if (r <= heap_size && heap[r] > heap[largest])
    {
        largest = r;
    }

    // now largest is the index of the largest element among node(at index i)
    // left child(index l) and right child(index r).

    // if largest is not the initial node, then we need to shift their position
    if (largest != i)
    {
        t = heap[i];
        heap[i] = heap[largest];
        heap[largest] = t;

        // we took the largest element at index i,
        // and kept heap[i] at largest index.
        // now we will call the max_heapify again from largest index.
        // as heap[i] is not at largest index.

        max_heapify(heap, heap_size, largest);
    }
}

// function to build a max heap

void build_max_heap(int heap[], int heap_size)
{
    int i;
    for (i = heap_size / 2; i >= 1; i--)
    {
        max_heapify(heap, heap_size, i);
    }
}

// function to print the heap.

void print_heap(int heap[], int heap_size)
{
    int i;

    for (i = 1; i <= heap_size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n\n");
}

// function for heap sorting.
// note: we must call build_max_heap befor heap_sort function.

void heap_sort(int heap[], int heap_size)
{
    int i, t;

    // we are exchanging postion of last node and first node in each run.
    for (i = heap_size; i > 1; i--)
    {
        // postion exchange code
        t = heap[1];
        heap[1] = heap[i];
        heap[i] = t;

        // last node sorted.
        // decreasing heap size.
        heap_size -= 1;

        // calling the max heapify function to sort another node.
        max_heapify(heap, heap_size, 1);
    }
}

int main()
{
    int heap_size = 9;

    // heap is inserted in an array.
    // we will keep 0 at index 0 at array.
    // will insert heap elements form index 1 in the array.
    // size of array = size of heap + 1 [as, index 0 is not used to keep heap elements]
    int H[] = {0, 19, 7, 17, 3, 5, 12, 10, 1, 2};

    int flag = is_max_heap(H, heap_size);
    if (flag == 1)
    {
        printf("max heap\n");
    }
    else
    {
        printf("not max heap\n");
    }

    printf("\n\n");

    int A[] = {0, 19, 7, 17, 3, 5, 12, 10, 1, 4};
    flag = is_max_heap(A, heap_size);
    if (flag == 1)
    {
        printf("max heap\n");
    }
    else
    {
        printf("not max heap\n");
    }
    printf("\n\n");

    // now creating  another complete binary tree to convert
    // it into heap

    int heap[] = {0, 19, 7, 12, 3, 5, 17, 10, 1, 2};
    // now printing the heap before calling max_heapify.
    print_heap(heap, heap_size);

    // now calling max_heapify function.
    // node 12 is less than its child 17.
    // so 3 should be index of the node in max_heapify function.
    max_heapify(heap, heap_size, 3);

    // printting the heap now.
    print_heap(heap, heap_size);

    // creating heap2 to build a max heap;
    int heap2[] = {0, 12, 7, 1, 3, 10, 17, 19, 2, 5};

    // printing heap2 before calling build_max_heap function.
    printf("heap 2 before building max heap: ");
    print_heap(heap2, heap_size);

    // calling build_max_heap function.
    build_max_heap(heap2, heap_size);

    printf("Heap 2 after building mas heap: ");
    print_heap(heap2, heap_size);

    // calling heap sort function
    heap_sort(heap2, heap_size);
    // printing heap2
    print_heap(heap2, 9);

    return 0;
}