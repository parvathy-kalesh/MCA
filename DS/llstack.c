#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = 0, *newnode, *temp;

void push();
void pop();
void display();

int main()
{
    int c;
    while(1)
    {
        printf("\n 1. push \n 2. pop \n 3. display \n 4. exit");
        printf("\nEnter your choice: ");
        scanf("%d", &c);

        switch(c)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
}

void push()
{
    int item;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &item);
    newnode->data = item;
    newnode->next = top;
    top = newnode;
}

void display()
{
    temp = top;
    if(top == 0)
    {
        printf("List is empty");
    }
    else
    {
        while(temp != 0)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}

void pop()
{
    temp = top;
    if(top == 0)
    {
        printf("List is empty");
    }
    else
    {
        printf("%d is deleted", top->data);
        top = top->next;
        free(temp);
    }
}