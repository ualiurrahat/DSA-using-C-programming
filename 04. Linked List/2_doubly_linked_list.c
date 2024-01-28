// Double link list
/* Easch node has
--value
-- address of previous node
-- address of next node
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure for node.
typedef struct node Node;

struct node
{
    int data;
    Node *next;
    Node *prev;
};

// function to create a node in the doubly linked list.
Node *create_node(int item, Node *next, Node *prev)
{
    // creating a node pointer and allocating memory.
    Node *new_node = (Node *)malloc(sizeof(Node));

    // in case of memory allocatin failure.
    if (new_node == NULL)
    {
        printf("Error! Could not create a new node\n");
        // exiting the program.
        exit(1);
    }
    // assigning the value and pointers to the created new node.
    new_node->data = item;
    new_node->prev = prev;
    new_node->next = next;
}

// function to insert a node at the beginning.

Node *prepend(Node *head, int item)
{
    // creating the node
    // that needs to be added in the first place in the list.
    // the first node will have no previos node. so assign null as the prev pointer.
    // took head as next pointer. as this node's next will be the pointer that head is pointing.
    Node *new_node = create_node(item, head, NULL);

    //the previous first node became the second node now.
    // so, we need to assign the new_node as its previous node.

    new_node->next->prev = new_node;

    // what this function returns, we will assign it to the head pointer.
    // so returning the new_node.
    return new_node;
}

// function to insert a node at the end.

Node *append(Node *head, int item)
{
    // this node will be the last one.
    Node *new_node = create_node(item, NULL, NULL);

    // in case if linked list is empty.
    if (head == NULL)
    {
        // then this node is the only node in the list
        // returning the node.
        return new_node;
    }

    // in case linked list is not empty
    // we need to find the last node.
    // then we will assign the last node as the prev of the new_node.

    // using current_node to find the last node.
    Node *current_node = head;

    // loop to find the last node.
    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }

    // found the last node as the current_node.
    // next pointer of current_node would be new_node. assigning it.
    current_node->next = new_node;
    // similarly, previos of the new_node woulb be the current node.
    new_node->prev = current_node;

    // returning head.
    return head;
}

// function to remove a node from the list.

Node *remove_node(Node *head, Node *node)
{
    // if node is the first node of the list.
    // then head and node is same.
    if (node == head)
    {
        // the node->next would be the first node after removing node.
        head = node->next;

        // first would would point to null as its prev pointer.
        head->prev = NULL;

        // freeing node
        free(node);

        // returning head;
        return head;
    }

    // in case node is not the first list.
    Node *previous_node = node->prev;
    Node *next_node = node->next;

    previous_node->next = next_node;
    next_node->prev = previous_node;

    free(node);
    return head;
}

// function to print linked list
// takes head node as parameter.
void print_linked_list(Node *head)
{
    // creating a node current_node assigning head to it.
    Node *current_node = head;
    // will run the loop untill the last node is found
    while (current_node != NULL)
    {
        // printing linked list
        printf("%d ", current_node->data);
        // shifting to the next node.
        current_node = current_node->next;
    }
    printf("\n");
}

int main()
{

    Node *n1, *n2, *n3, *n4, *head;

    // checking create_node function
    n1 = create_node(1, NULL, NULL);
    printf("%d\n", n1->data);

    // checking prepend function.
    head = n1;
    head = prepend(head, 18);
    n2 = head;

    // checking display function
    print_linked_list(head);

    // checking append function
    head = append(head, 8);

    print_linked_list(head);
    n3 = head;
    // checking insert function

    return 0;
}