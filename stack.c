#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// define the stack structure
struct Stack
{
    int data[MAX_SIZE];
    int top;
};

// initialize the stack
void initialize(struct Stack *stack)
{
    stack->top = -1; // initialize the top to -1(empty stack)
}

// check if the stack is full
bool isFull(struct Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

// check if the stack is empty
bool isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// push an element onto the stack
void push(struct Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack overflow.Can not push %d\n", value);
        return;
    }
    stack->data[++stack->top] = value;
}

// pop and element from the stack and return its value
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow.Can not pop element from an empty stack.\n");
        return -1;
    }

    return stack->data[stack->top--];
}

int main()
{

    struct Stack stack;
    initialize(&stack);

    // push some element into the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // pop element from the stack and print them
    while (!isEmpty(&stack))
    {
        printf("%d\n", pop(&stack));
    }

    return 0;
}