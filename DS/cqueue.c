#define N 5
#include <stdio.h>

int queue[N];
int front = -1;
int rear = -1;

void in(int x);
void out();
void display();

int main() {
    int n, x;
    while (1) {
        printf("\n1.Insert 2.Delete 3.Exit 4.Display\n");
        printf("Enter choice: ");
        scanf("%d", &n);
        switch (n) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &x);
                in(x);
                break;
            case 2:
                out();
                break;
            case 3:
                return 0;
            case 4:
                display();
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void in(int x) {
    if ((rear + 1) % N == front) {
        printf("Queue is full\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

void out() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else if (front == rear) {
        printf("Deleted: %d\n", queue[front]);
        front = rear = -1;
    } else {
        printf("Deleted: %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d\n", queue[rear]);
    }
}