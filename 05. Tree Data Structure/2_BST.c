/*
Binary Search Tree: For each node in BST
- left child < node < right child
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for BST

typedef struct node Node;

struct node
{
    int data;
    Node *parent;
    Node *left;
    Node *right;
};

// function to create a new node in the BST.
Node *create_node(int item)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Memory Allcoation failed!!!\n");
        exit(1);
    }
    new_node->data = item;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

// add left child

void add_left_child(Node *node, Node *child)
{
    node->left = child;
    if (child != NULL)
    {
        child->parent = node;
    }
}

/// add right child
void add_right_child(Node *node, Node *child)
{
    node->right = child;
    if (child != NULL)
    {
        child->parent = node;
    }
}

// function to insert a new node in the BST
Node *bst_insert(Node *root, Node *node)
{
    Node *parent_node, *current_node;
    // if list is empty the, this node will be the only node.
    // so we will return this node as root
    if (root == NULL)
    {
        root = node;
        return root;
    }
    // when list is not empty.means it has at least 1 node already.

    // we will keep parent of the node pointer in the parent_node.
    // but first assigning null in parent_node
    parent_node = NULL;
    // we will try to find the parent node using loop.
    // will use current_node and start the loop from root.
    // will run the loop untill null is found.
    current_node = root;

    while (current_node != NULL)
    {
        parent_node = current_node;
        if (node->data < current_node->data)
        {
            current_node = current_node->left;
        }
        else
        {
            current_node = current_node->right;
        }
    }
    // now we found the parent node for node.
    // will add node as the left child or right child of parent_node.
    if (node->data < parent_node->data)
    {
        add_left_child(parent_node, node);
    }
    else
    {
        add_right_child(parent_node, node);
    }
    // returning the root.
    return root;
}

/*
               10
        5                17
      3     7         12     19
    1   4

    we need to create this as BST
    created creat_bst() function  below to do this.
*/
// function to create BST given in the example.

Node *create_bst()
{
    Node *root, *node;
    int i;
    int ara[] = {5, 17, 3, 7, 12, 19, 1, 14};
    // first creating root node.
    root = create_node(10);
    // inserting each array element in the BST.
    for (i = 0; i < 8; i++)
    {
        // creating node with each array element
        node = create_node(ara[i]);
        // inserting each node in the BST
        root = bst_insert(root, node);
    }

    return root;
}

// function to display the BST in in-order method

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

// function to search a node in the BST

Node *bst_search(Node *root, int item)
{
    Node *node = root;
    while (node != NULL)
    {
        if (node->data == item)
        {
            return node;
        }
        if (item < node->data)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    return node;
}

// function to find the lowest value node in the BST

Node *bst_minimum(Node *root)
{
    Node *node = root;

    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}
// function to transplant a node.
// replacing current_node with new_node
Node *bst_transplant(Node *root, Node *current_node, Node *new_node)
{
    if (current_node == root)
    {
        root = new_node;
    }
    else if (current_node == current_node->parent->left)
    {
        add_left_child(current_node->parent, new_node);
    }
    else
    {
        add_right_child(current_node->parent, new_node);
    }
    return root;
}

// function to delete a node from the BST.
// function takes two parameters.
// deletes the node and returns the root after needed change is done.
Node *bst_delete(Node *root, Node *node)
{
    Node *smallest_node;
    // when node has only rigth child and no left child.
    if (node->left == NULL)
    {
        root = bst_transplant(root, node, node->right);
    }
    // when node has only right child, no left child
    else if (node->right == NULL)
    {
        root = bst_transplant(root, node, node->left);
    }
    else
    {
        smallest_node = bst_minimum(node->right);

        if (smallest_node->parent != node)
        { //smallest_node is not the child of node.
            // so need to do two things.
            // will replace smallest_node with its right child
            // add right child of the node as smallest_node's right child.

            // replacing smallest_node with its right child.
            root = bst_transplant(root, smallest_node, smallest_node->right);
            // adding node's right child as smallest_node's right child.

            // replacing node's left child as smallest_node's left child
            add_right_child(smallest_node, node->right);
        }
        // in case when smallest_node is the direct child of node

        // replacing node with smallest node

        root = bst_transplant(root, node, smallest_node);
        add_left_child(smallest_node, node->left);
    }

    free(node);
    return root;
}
int main()
{
    Node *root = create_bst();
    Node *node;

    printf("BST: \n");
    in_order(root);
    printf("\n");

    // searching and deleting node value 1
    node = bst_search(root, 1);

    if (node != NULL)
    {
        printf("Will delete %d\n", node->data);
        root = bst_delete(root, node);

        printf("BST: \n");
        in_order(root);
        printf("\n");
    }

    else
    {
        printf("Node not found\n");
    }

    // searching and deleting node value 5
    node = bst_search(root, 5);

    if (node != NULL)
    {
        printf("Will delete %d\n", node->data);
        root = bst_delete(root, node);

        printf("BST: \n");
        in_order(root);
        printf("\n");
    }

    else
    {
        printf("Node not found\n");
    }

    // searching and deleting node 10
    node = bst_search(root, 10);

    if (node != NULL)
    {
        printf("Will delete %d\n", node->data);
        root = bst_delete(root, node);

        printf("BST: \n");
        in_order(root);
        printf("\n");
    }

    else
    {
        printf("Node not found\n");
    }
    return 0;
}