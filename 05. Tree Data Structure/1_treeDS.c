// tree data structure.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;

// tree data structure.
struct node
{
    int data;
    Node *left;
    Node *right;
};

// function to create a new node .
Node *create_node(int item)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    // in case node creation failed.
    if (new_node == NULL)
    {
        printf("Error! Could not create a new node!\n");
        // exiting the whole program.
        exit(1);
    }

    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void add_left_child(Node *node, Node *child)
{
    node->left = child;
}

void add_right_child(Node *node, Node *child)
{
    node->right = child;
}

/*
create this node
              2
        7          9

    1      6              8
        5    10         3   4

*/
// function to create this upper tree.
Node *create_tree()
{
    Node *two = create_node(2);
    Node *seven = create_node(7);
    Node *nine = create_node(9);

    add_left_child(two, seven);
    add_right_child(two, nine);

    Node *one = create_node(1);
    Node *six = create_node(6);
    add_left_child(seven, one);
    add_right_child(seven, six);

    Node *five = create_node(5);
    Node *ten = create_node(10);
    add_left_child(six, five);
    add_right_child(six, ten);

    Node *eight = create_node(8);
    add_right_child(nine, eight);

    Node *three = create_node(3);
    Node *four = create_node(4);

    add_left_child(eight, three);
    add_right_child(eight, four);

    // two named node is the root of the tree.
    return two;
}

// function to traverse the tree in pre-order way.

void pre_order(Node *node)
{
    printf("%d ", node->data);

    if (node->left != NULL)
    {
        pre_order(node->left);
    }

    if (node->right != NULL)
    {
        pre_order(node->right);
    }
}

// function to traverse the tree in post-order way.

void post_order(Node *node)
{

    if (node->left != NULL)
    {
        post_order(node->left);
    }

    if (node->right != NULL)
    {
        post_order(node->right);
    }

    printf("%d ", node->data);
}

// function to traverse the tree in in-order way.

void in_order(Node *node)
{
    if (node->left != NULL)
    {
        in_order(node->left);
    }

    printf("%d ", node->data);

    if (node->right != NULL)
    {
        in_order(node->right);
    }
}

int main()
{
    Node *root = create_tree();
    printf("%d\n", root->data);

    // traversing the tree in pre-order way.
    printf("Traversing the tree in pre-order way: ");
    pre_order(root);
    printf("\n");

    // traversing the tree in post-order way.
    printf("Traversing the tree in post-order way: ");
    post_order(root);
    printf("\n");

    // traversing the tree in in-order way.
    printf("Traversing the tree in in-order way: ");
    in_order(root);

    return 0;
}