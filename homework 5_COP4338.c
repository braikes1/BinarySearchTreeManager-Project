#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

struct node *newNode(int item) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

int main() {
    struct node *root = NULL;
    int value;

    printf("Enter the numbers to be inserted in the BST (enter -1 to stop): \n");
    while(1) {
        scanf("%d", &value);
        if(value == -1) break;
        root = insert(root, value);
    }

    printf("Inorder traversal of the given BST: \n");
    inorder(root);

    return 0;
}