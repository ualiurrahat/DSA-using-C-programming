// priority queue.
// priority queue is made using heap.
// max priority heap and min priority heap.
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

// function to find the max element in the queue
int get_maximum(int heap[])
{
    // in max heap, the index 1 has the max element.
    return heap[1];
}

// function to extrac the max element from a priority queue.
// to extract maximum node, we will replace max node with the last node.
// then will reduce the heap size by 1
// then will call the max heapify function to ensure it to be heap again.
// will return the max item till heap is emtpy

int extract_max(int heap[], int heap_size)
{
    // heap[1] is the max node
    int max_item = heap[1];

    // replace heap[1] with the last node
    heap[1] = heap[heap_size];

    // now we will decrease heap size by 1. as we don't need the last element.
    // value of the last element already been assigned in heap[1]
    heap_size -= 1;

    // now will the max_heapify function to maintain the heap .
    // will start from index 1 to recreate the heap if it is broken.
    max_heapify(heap, heap_size, 1);

    // returning the max node
    return max_item;
}

// function to insert a node in the priority queue.
int insert_node(int heap[], int heap_size, int node)
{
    // we need to add the node integer in the queue

    int i, p, t;

    // heap size will increase after adding the node.
    heap_size += 1;

    // node element would be added as last node
    heap[heap_size] = node;

    // now will check if last node heap[heap_size] is greater than its parent
    // if so, then it will be replaced with its parent's index.
    // this continues untill the node becomes the root node
    // or the node gets lesser to its parent.

    i = heap_size;
    while (i > 1 && heap[i] > heap[parent(i)])
    {
        p = parent(i);

        // exchanging position of node with its parent's position.
        t = heap[p];
        heap[p] = heap[i];
        heap[i] = t;

        // the new index of the node would be its parents node
        i = p;
    }
    // function will return heap size at last
    return heap_size;
}

int main()
{

    return 0;
}