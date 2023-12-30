#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;           // Parameter 1: node number
    struct node* left;  // Parameter 2: left node (pointed)
    struct node* right; // Parameter 3: right node (pointed)
} Node;

/*
 * Function: insert
 * Description: Inserts a node with the given data into a binary tree.
 * Parameters:
 *   - pNode: A pointer to the root of the binary tree.
 *   - insert_data: The data to be inserted into the tree.
 * Returns: A pointer to the modified binary tree.
 */
Node* insert(Node* pNode, int insert_data) {
    // If the node has not been set yet
    if (pNode == NULL) {
        // Create a new node and assign the insert_data
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = insert_data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    // If the number to insert is smaller than the node number
    if (insert_data < pNode->data) {
        // Recursively insert it in the left subtree
        pNode->left = insert(pNode->left, insert_data);
    }

    // Otherwise, if the number to insert is greater than the node number
    else if (insert_data > pNode->data) {
        // Recursively insert it in the right subtree
        pNode->right = insert(pNode->right, insert_data);
    }

    return pNode;
}

/*
 * Function: post_order
 * Description: Performs a post-order traversal of a binary tree and prints the data of each node.
 * Parameters:
 *   - root: A pointer to the root of the binary tree.
 */
void post_order(Node* root) {
    if (root == NULL) {
        return;
    }
    // Recursively traverse the left subtree
    post_order(root->left);
    // Recursively traverse the right subtree
    post_order(root->right);
    // Visit the current node
    printf("%d ", root->data);
}

/*
 * Function: in_order
 * Description: Performs an in-order traversal of a binary tree and prints the data of each node.
 * Parameters:
 *   - root: A pointer to the root of the binary tree.
 */
void in_order(Node* root) {
    if (root == NULL) {
        return;
    }
    // Recursively traverse the left subtree
    in_order(root->left);
    // Visit the current node
    printf("%d ", root->data);
    // Recursively traverse the right subtree
    in_order(root->right);
}

/*
 * Function: pre_order
 * Description: Performs a pre-order traversal of a binary tree and prints the data of each node.
 * Parameters:
 *   - root: A pointer to the root of the binary tree.
 */
void pre_order(Node* root) {
    if (root == NULL) {
        return;
    }
    // Visit the current node
    printf("%d ", root->data);
    // Recursively traverse the left subtree
    pre_order(root->left);
    // Recursively traverse the right subtree
    pre_order(root->right);
}

int main(void) {
    Node* root = NULL;
    // Insert nodes into the binary tree
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 2);
    root = insert(root, 8);
    root = insert(root, 11);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 9);
    root = insert(root, 6);
    root = insert(root, 0);
    root = insert(root, 10);
    root = insert(root, 7);
    root = insert(root, 5);
    printf("pre_order: ");
    // Print the tree using pre-order traversal
    pre_order(root);
    printf("\nin_order: ");
    // Print the tree using in-order traversal
    in_order(root);
    printf("\npost_order: ");
    // Print the tree using post-order traversal
    post_order(root);
    printf("\n");
    return 0;
}
