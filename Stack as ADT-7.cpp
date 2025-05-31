#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
    char data;
    Node* next;
};

Node* top = NULL;

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
    Node* newNode = new Node;
    if (!newNode)
    {
        cout << "Stack Overflow" << endl;
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
        cout << "Stack empty" << endl;
        return '\0';
    }
    char ele = top->data;
    Node* temp = top;
    top = top->next;

    delete temp;
    return ele;
}

void display()
{
    if (isemp())
    {
        cout << "Stack is empty" << endl;
        return;
    }
    Node* current = top;
    cout << "Stack: ";
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    int choice;
    char value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display Stack\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                value = pop();
                if (value != '\0') {
                    cout << "Popped: " << value << endl;
                }
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    while (!isemp())
    {
        pop();
    }

    return 0;
}
