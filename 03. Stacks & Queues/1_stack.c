#include <stdio.h>

#define STACK_MAX 10

typedef struct
{
    int top;
    int data[STACK_MAX];
} Stack;

void push(Stack *s, int item)
{
    // will keep the item var to to the top if stack is not full.

    // checking if stack is full or not.
    if (s->top < STACK_MAX)
    {
        // keeping the item at the top of the stack
        s->data[s->top] = item;
        // increasing top's value by 1.
        s->top = s->top + 1;
    }
    else
    {
        // stack is full
        printf("Stack is full!\n");
    }
}

int pop(Stack *s)
{
    int item;

    // checking if stack is empty.
    if (s->top == 0)
    {
        printf("Stack is empty!\n");
        return -1;
    }
    else
    {
        s->top = s->top - 1;
        item = s->data[s->top];
    }
    return item;
}

void initStack(Stack *s)
{
    s->top = 0;
}

int main()
{
    Stack s1;
    int item;

    //  intializing value of s1.top = 0 with initStack() function.
    initStack(&s1);

    // sending 10,20,30 in the stack.
    push(&s1, 10);
    push(&s1, 20);
    push(&s1, 30);

    // now calling the pop function and printing the returned value.
    item = pop(&s1);
    printf("%d\n", item);

    item = pop(&s1);
    printf("%d\n", item);

    item = pop(&s1);
    printf("%d\n", item);

    // calling pop again and this time stack is empty.
    item = pop(&s1);
    printf("%d\n", item);

    return 0;
}