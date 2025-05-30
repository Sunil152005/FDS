#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct node
{
    char data;
    struct node * next;
};

struct node* top = NULL;

void push(char ele)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL)
        {
        cout << "Memory allocation failed!" << endl;
        return;
        }
    newnode->data = ele;
    newnode->next = top;
    top = newnode;
}

char pop()
{
    if(top == NULL)
    {
    cout << "Stack is empty!" << endl;
    return '\0';
    }
    struct node* temp = top;
    char ele = temp->data; top
    = top->next; free(temp);
    return ele;
}

int isempty()
    {
    return (top == NULL);
    }
int isoperator(char ele)
    {
    return (ele == '+' || ele == '-' || ele == '*' || ele == '/' || ele == '^');
    }
int isoperand(char ele)
    {
    return ((ele >= 'A' && ele <= 'Z') || (ele >= 'a' && ele <= 'z') ||
    (ele >= '0' && ele <= '9'));
    }

int prec(char ele)
{
switch (ele)
{
    case '^':
        return 3;
    case '*': case '/':
        return 2;
    case '+': case '-':
        return 1;
    default:
        return -1;
}
}

void reverse_str(char* str)
{
    int len = strlen(str);
    for (int i= 0; i < len / 2; i++)
        {
            char
            temp = str[i]; str[i] =
            str[len - 1 - i];
            str[len - 1 - i] = temp;
        }
        for (int i = 0; i < len; i++)
        {
        if (str[i] == '(')
            {
                str[i]= ')';
            } else if (str[i] == ')')
            {
                str[i] = '(';
            }
        }
}

void intopost(char expr[], char output[])
{
    int i = 0, j = 0;
    while (expr[i] != '\0')
    {
    if (expr[i] == '(')
        {
        push(expr[i]);
        }
    else if (isoperand(expr[i]))
        {
        output[j++] = expr[i];
        }
    else if (isoperator(expr[i]))
    {
    while (!isempty() && prec(top->data) >= prec(expr[i]))
        {
        output[j++] = pop();
        }
    push(expr[i]);
    }
    else if (expr[i] == ')')
    {
    while (!isempty() && top->data != '(')
        {
        output[j++] = pop();
        }
        pop();
    }
    i++;
    }
    while (!isempty())
        {
        output[j++] = pop();
        }
    output[j] = '0';
}

int main()
{
    char expr[20], post[20];
    cout << "Enter an infix expression: ";
    cin >> expr;

    intopost(expr, post);
    cout << "Postfix expression: " << post << endl;

    reverse_str(expr);
    cout << "Reversed expression: " << expr << endl;

    intopost(expr, post);
    cout << "Reversed expression to postfix: " << post << endl;

    reverse_str(post);
    cout << "Prefix expression: " << post << endl;

    return 0;
}
