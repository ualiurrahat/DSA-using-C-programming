#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 Linked list: each node has two elements:
1. data
2. address of next node.

*/

// structure for node
typedef struct node Node;
struct node
{
    int data;   // for data
    Node *next; // for next node address
};

// function to create node for the linked list
// takes two parameter as argument.
// item = element to be stored in the node itself
// *next = Node pointer indicating the next node address

Node *create_node(int item, Node *next)
{
    // creating a new node now.memory allcation.
    Node *new_node = (Node *)malloc(sizeof(Node));

    // if allocation failed,then pointer will return NULL
    if (new_node == NULL)
    {
        printf("Error! Could not create new node\n");
        exit(1); // exiting the function.
    }

    // assigning the element and address of next node in case
    // allocation is successful.
    new_node->data = item;
    new_node->next = next;

    // returning the node that we created.
    return new_node;
}

// function to add a node in the beginning of the linked list
// takes 2 parameters: head pointer and item.

Node *prepend(Node *head, int item)
{
    // we will create a new node whose data will be item
    // and it would point the node that is being pointed by the head.
    Node *new_node = create_node(item, head);

    // now returning new_node. now it is the first node of the linked list.
    //head should point this node. so will assign the return of
    // this function to the head.
    return new_node;
}

// function to add a node at the end of the linked list.

Node *append(Node *head, int item)
{
    // we will create a new node with item as its data.
    // since, it is the last node, it would point null.
    Node *new_node = create_node(item, NULL);

    //if linked list is empty then,
    if (head == NULL)
    {
        // if list is empty, then new_node is the first node of the list.
        //so returning new_node.
        // what append() function will return, we will assign it to head.
        // so head will point to this new_node.
        return new_node;
    }

    // now we need to find out the last node.
    // so we created a node and assign head to it.
    Node *current_node = head;
    // last node points to null.
    // so untill we get a node like this, we will keep running the loop.

    while (current_node->next != NULL)
    {
        //next node of current_node is current_node->next.
        current_node = current_node->next;
    }

    // now current_node is the last node.
    // so assigning new_node to its next.
    current_node->next = new_node;
    return head;
}

// function add a node among other nodes in the linked list.
// takes two paramert:
// item which will be the value of the new node.
// a node pointer , after which we will add the new node we are creating.
void insert_node(Node *node, int item)
{
    // creating a new node with item as its value
    // it would point the node which is being pointed by the input node pointer
    Node *new_node = create_node(item, node->next);

    //now assigning new_node as the next node of node pointer.
    node->next = new_node;
}

// function to remove any node from a linked list.
// takes head pointer and the node pointer (which we want to remove) as parameter.
//returns the head pointer.

Node *remove_node(Node *head, Node *node)
{
    // case 1:
    // if node is the first element in the linked list,
    // then head should point to the next node.
    if (node == head)
    {
        head = node->next;
        // freeing node
        free(node);
        // returning head.
        return head;
    }

    // case 2:
    // node is not the first element in the linked list.
    // so we need to find the previous node of the node we want to remove.
    Node *current_node = head;
    while (current_node != NULL)
    {
        if (current_node->next == node)
        {
            break;
        }
        current_node = current_node->next;
    }
    // case when the node we want to delete does not exist in the linked list.
    if (current_node == NULL)
    {
        return head; // linked list should be same. so returning head.
    }
    // found the node. so the previos node(current_node) should point the
    // address of the node which is pointed by the node that needs to be removed.
    current_node->next = node->next;

    // freeing node
    free(node);
    return head;
}

// function to search a node in the linked list
// takes two parameter:
// head node, and item.
// function will check if a node with item value exist or not.
// if exists, then function will return the node
// function will return the first node if there are nodes having the item value.
// if node does not exit , function will return 0;
Node *search_node(Node *head, int item)
{
    Node *current_node = head;

    while (current_node != NULL)
    {
        if (current_node->data == item)
        {
            printf("Node does exist!\n");
            return current_node;
        }
        current_node = current_node->next;
    }
    printf("Node does not exist\n");
    return 0;
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

// function to count total number of node in a linked list
// takes head as parameter.
// returns total num of node.
int count_node(Node *head)
{
    int count = 0;
    Node *current_node = head;
    while (current_node != NULL)
    {
        count++;
        current_node = current_node->next;
    }
    return count;
}

int main()
{

    Node *n1, *head, *n2, *n4, *n5;

    // creating the first node n1.
    n1 = create_node(10, NULL);
    // assigning head to n1.
    head = n1;
    // printing the list.
    print_linked_list(head);

    // now adding 20 as the first node
    head = prepend(head, 20);
    print_linked_list(head);

    // adding 30 as the last list element.
    head = append(head, 30);
    print_linked_list(head);

    head = append(head, 15);
    print_linked_list(head);

    // searching in the list if a node with value 30 exist.
    // this exist.
    n2 = search_node(head, 30);
    printf("%u\n", n2);

    // node with value 40 does not exist.
    // so n3 will show 0.
    Node *n3 = search_node(head, 40);
    printf("%u\n", n3);

    // inserting two element 50, 100 in between the list.
    insert_node(n1, 50);
    print_linked_list(head);
    insert_node(n2, 100);
    print_linked_list(head);

    // counting total node in list.
    int count = count_node(head);
    printf("%d\n", count);

    // now will remove some element.
    head = remove_node(head, n2);
    print_linked_list(head);

    head = remove_node(head, n5);
    print_linked_list(head);

    printf("%d\n", count_node(head));

    return 0;
}