#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node
{
    double value;
    struct Node *next;
} Node;

struct Stack
{
    struct Node *top;
} Stack;

struct Stack *createStack()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == NULL;
}

void push(struct Stack *stack, double value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

double pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        fprintf(stderr, "Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    struct Node *temp = stack->top;
    double value = temp->value;
    stack->top = temp->next;
    free(temp);
    return value;
}


double peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->value;
}


int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void infixToPostfix(const char *infix, char *postfix)
{
    struct Stack *stack = createStack();
    int k = 0;

    for (int i = 0; i < strlen(infix); i++)
    {
        if (isspace(infix[i]))
            continue;

        if (isdigit(infix[i]))
        {
    
            while (isdigit(infix[i]) || infix[i] == '.')
            {
                postfix[k++] = infix[i++];
            }
            postfix[k++] = ' '; 
            i--;                
        }
        else if (infix[i] == '(')
        {
            push(stack, '(');
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
            {
                postfix[k++] = (char)pop(stack);
                postfix[k++] = ' ';
            }
            pop(stack); 
        }
        else
        {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence((char)peek(stack)))
            {
                postfix[k++] = (char)pop(stack);
                postfix[k++] = ' ';
            }
            push(stack, (double)infix[i]);
        }
    }

    while (!isEmpty(stack))
    {
        postfix[k++] = (char)pop(stack);
        postfix[k++] = ' ';
    }
    postfix[k - 1] = '\0'; 
    free(stack);           
}

double evaluatePostfix(char *postfix)
{
    struct Stack *stack = createStack();
    char *token = strtok(postfix, " ");

    while (token != NULL)
    {
        if (isdigit(token[0]) || (token[0] == '-' && strlen(token) > 1))
        {
            push(stack, atof(token));
        }
        else
        {
            double b = pop(stack);
            double a = pop(stack);
            double result;

            switch (token[0])
            {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
            default:
                fprintf(stderr, "Unknown operator: %s\n", token);
                exit(EXIT_FAILURE);
            }
            push(stack, result); 
        }
        token = strtok(NULL, " ");
    }

    double finalResult = pop(stack); 
    free(stack);               
    return finalResult;
}

int main()
{
    char infixExpression[100];
    char postfix[100];

    printf("Enter an infix expression: ");
    fgets(infixExpression, sizeof(infixExpression), stdin);
    infixExpression[strcspn(infixExpression, "\n")] = '\0';

    infixToPostfix(infixExpression, postfix);
    printf("Postfix: %s\n", postfix);

    double result = evaluatePostfix(postfix);
    printf("Result: %.3f\n", result);

    return 0;
}
