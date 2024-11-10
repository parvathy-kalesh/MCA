#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* create();
void preorder(struct node *root);
void postorder(struct node *root);
void inorder(struct node *root);

struct node* create() {
    int x;
    struct node newnode = (struct node)malloc(sizeof(struct node));
    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);
    if (x == -1) {
        free(newnode);  // Free the allocated memory if no node is created
        return NULL;
    }
    newnode->data = x;
    printf("Enter the left child of %d\n", x);
    newnode->left = create();
    printf("Enter the right child of %d\n", x);
    newnode->right = create();
    return newnode;
}

void preorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
        printf("%d ", root->data);
}
void inorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main(void) {
    struct node *root = NULL;
    int choice;
    while (1) { // Loop for continuous operations
        printf("\n1. Create\n2. Preorder\n 3.inorder \n 4.postorder \n 5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                root = create();
                break;
            case 2:
                preorder(root);
                printf("\n"); // Print a newline after preorder traversal
                break;
                case 3:
                inorder(root);
                break;
                case 4:
                postorder(root);
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
