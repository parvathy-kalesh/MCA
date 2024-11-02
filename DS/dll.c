#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *p;
    struct node *n;
};

void create();
void display();
void insertatbeg();
void insertatpos();
void insertatend();
void deletebeg();
void deleteend();
void deletepos();
int count = 0;
struct node *newnode, *head = 0, *temp, *nextnode,*tail;

int main() {
    int n;
    while (1) {
        printf("\n 1. create 2. display 3. exit 4. insert at beginning 5. insert at position 6 .insert at end  7.delete at beginning 8.delete at end 9.delete at pos");
        printf("\nEnter your choice: ");
        scanf("%d", &n);
        switch (n) {
            case 1: create();
                    break;
            case 2: display();
                    break;
            case 3: exit(0);
                    break;
            case 4: insertatbeg();
                    break;
            case 5: insertatpos();
                    break;
              case 6:insertatend();
              break;
              case 7:deletebeg();
              break;
              case 8:deleteend();
              break;
              case 9:deletepos();
              break;
            default: printf("\nInvalid choice");
        }
    }
}

void create() {
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->n = 0;
    newnode->p = 0;
    if (head == 0) {
        head = tail= newnode;
    } else {
        tail->n = newnode;
        newnode->p = tail;
        tail= newnode;
    }
    count++;  // Increment count whenever a new node is added
}

void display() {
    temp = head;
    count = 0;  // Reset count to 0 before counting
    while (temp != 0) {
        printf("%d ", temp->data);
        temp = temp->n;
        count++;
    }
    printf("\nNumber of nodes: %d\n", count);
}

void insertatbeg() {
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->n = head;
    newnode->p = 0;
    if (head != 0) {
        head->p = newnode;
    }
    head = newnode;
    count++;  // Increment count whenever a new node is added
}

void insertatpos() {
    int pos, i = 1;
    printf("Enter the position: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > count + 1) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        insertatbeg();
        return;
    }
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    temp = head;
    while (i < pos - 1) {
        temp = temp->n;
        i++;
    }
    nextnode = temp->n;
    newnode->n = nextnode;
    newnode->p = temp;
    if (nextnode != 0) {
        nextnode->p = newnode;
    }
    temp->n = newnode;
    count++;  // Increment count whenever a new node is added
}  

void insertatend()
{
	   newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->n = 0;
    newnode->p = 0;
    tail->n=newnode;
    newnode->p=tail;
    tail=newnode;
}

void deletebeg()
{
	if(head==0)
	{
		printf("list is empty");
	}
	else
	{
		temp=head;
		head=head->n;
		head->p=0;
		free(temp);
	}
}

void deleteend()
{
	if(tail==0)
	{
		printf(" nothing to delete");
	}
	else
	{
		temp=tail;
		tail->p->n=0;
		tail=tail->p;
		free(temp);
	}
}
 void deletepos()
 {
 	int pos,i=1;
 	temp=head;
 	printf("enter pos");
 	scanf("%d",&pos);
 	while(i<pos)
 	{
 		temp=temp->n;
 		i++;
 	}
 	temp->p->n=temp->n;
 	temp->n->p=temp->p;
 	free(temp);
 }