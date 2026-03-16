#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
    int height;
};
int max(int a, int b) {
    return (a > b) ? a : b;
}
int height(struct Node *n) {
    return (n == NULL) ? 0 : n->height;
}
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
int getBalance(struct Node* n) {
    return (n == NULL) ? 0 : height(n->left) - height(n->right);
}
struct Node* insert(struct Node* node, int key) {
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;   // No duplicates
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    // LL
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    // RR
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    // LR
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // RL
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return NULL;
    /* 1. Perform BST delete */
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        /* Node with 0 or 1 child */
        if (root->left == NULL || root->right == NULL) {
            struct Node* temp =
                (root->left) ? root->left : root->right;
            free(root);
            return temp;
        }
        /* Node with 2 children */
        struct Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    /* 2. Update height */
    root->height = 1 + max(height(root->left), height(root->right));
    /* 3. Get balance factor */
    int balance = getBalance(root);
    /* 4. Balance the tree */
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);            // LL
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);            // LR
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);             // RR
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);             // RL
    }
    return root;
}
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}
/* IN-ORDER TRAVERSAL */
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
/* POST-ORDER TRAVERSAL */
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}
int main() {
    struct Node* root = NULL;
    int choice, key;
    do {
        printf("\n1.Insert  2.Delete  3.Search  4.Inorder  5.Postorder   6.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            root = deleteNode(root, key);
            break;
        case 3:
            printf("Enter key to search: ");
            scanf("%d", &key);
            if (search(root, key))
                printf("Key found\n");
            else
                printf("Key not found\n");
            break;
        case 4:
            printf("In-order Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 5:
            printf("Popst-order Traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (1);
    return 0;
}
