#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node * top = NULL;

int isemp()
{
    if (top == NULL)
    {
        return 1;
    } else
    {
        return 0;
    }
}

void push(char ele)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode)
        {
        printf("Stack Overflow\n");
        return;
        }
    newNode->data = ele;
    newNode->next = top;
    top = newNode;
}

char pop()
{
    if (top == NULL)
        {
        printf("Stack empty \n");
        return '\0';
        }
    char ele = top->data;
    struct Node* temp = top;
    top = top->next;

    free(temp);
    return ele;
}

void display()
{
    if (isemp())
        {
        printf("Stack is empty\n");
        return;
        }
    struct Node* current = top;
    printf("Stack: ");
    while (current != NULL)
    {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    int choice;
    char value;


    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to push: ");
                scanf(" %c", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != '\0') {
                    printf("Popped: %c\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

} while (choice != 4);
while (!isemp())
    {
    pop();
    }
    return 0;
}
