#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL,*temp;

void create();
void display();
void insertbeg();
void insertend();
void insertpos();
void deletebeg();
void deleteend();
void deletepos();

int count = 0;

int main() {
    int choice;
    while (1) { // Loop for continuous operations
        printf("\n1. Create\n2. Display\n3. Exit \n4. Insert at beginning \n5. Insert at end"
               "\n6. Insert at position \n7.delete at beg \n8.delete at end\n 9.delete at specific positionEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            case 4:
                insertbeg();
                break;
            case 5:
                insertend();
                break;
            case 6:
                insertpos();
                break;
              case 7:
              deletebeg();
              break;
              case 8:
              deleteend();
              case 9:
              deletepos();
              break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void create() {
    int num;
    printf("\nEnter the data (-1 to stop): ");
    scanf("%d", &num);
    while (num != -1) {
        struct node newnode = (struct node)malloc(sizeof(struct node));
        newnode->data = num;
        newnode->next = NULL;
        
        if (start == NULL) {
            start = newnode;
        } else {
            struct node *ptr = start;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newnode;
        }
        count++; // Increment count as a new node is added
        printf("\nEnter the data (-1 to stop): ");
        scanf("%d", &num);
    }
}

void display() {
    if (start == NULL) {
        printf("\nThe list is empty.\n");
        return;
    }
    
    printf("\nThe list elements are: ");
    struct node *ptr = start;
    while (ptr != NULL) {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void insertbeg() {
    struct node newnode = (struct node)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = start;
    start = newnode;
    count++; // Increment count
}

void insertend() {
    struct node newnode = (struct node)malloc(sizeof(struct node));
    printf("Enter the data you want to insert: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    
    if (start == NULL) { // If the list is empty
        start = newnode;
    } else {
        struct node *temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    count++; // Increment count
}

void insertpos() {
    int pos, i = 1;
    printf("Enter the position: ");
    scanf("%d", &pos);
    
    if (pos < 1 || pos > count + 1) { // Check for valid position
        printf("Invalid position\n");
        return;
    }
    
    struct node newnode = (struct node)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    
    if (pos == 1) { // Insert at the beginning
        newnode->next = start;
        start = newnode;
    } else {
        struct node *temp = start;
        while (i < pos - 1 && temp != NULL) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    count++; // Increment count
}
  
  void deletebeg()
  {
  	
  	if(start==0)
  	{
  		printf("list is empty");
  	}
  	else
  	{
  		temp=start;
  		start=start->next;
  		free(temp);
  	}
  }
  
  void deleteend()
  {
  	struct node *pnode;
  	temp=start;
  	while(temp->next!=0)
  	{
  		pnode=temp;
  		temp=temp->next;
  	}
  	if(temp==start)
  	{
  		start=0;
  	}
  	else
  	{
  		pnode->next=0;
  	}
  	free(temp);
  }
  
  void deletepos()
  {
  	struct node *nextnode;
  	int pos,i=1;
  	temp=start;
  	printf("enter the position u want to delete");
  	scanf("%d",&pos);
  	while(i<pos-1)
  	{
  		temp=temp->next;
  		i++;
  	}
  	nextnode=temp->next;
  	temp->next=nextnode->next;
  	free(nextnode);
  }