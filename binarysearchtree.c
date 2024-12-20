#include <stdio.h>
#include <stdlib.h>

// Define the structure for the nodes of the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a new node into the binary search tree
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, return a new node
    if (root == NULL)
        return createNode(data);

    // Otherwise, recur down the tree
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    // Return the (unchanged) node pointer
    return root;
}

// Search for a value in the binary search tree
struct Node* search(struct Node* root, int data) {
    // Base case: root is null or data is present at the root
    if (root == NULL || root->data == data)
        return root;

    // Data is greater than root's data, so search in the right subtree
    if (data > root->data)
        return search(root->right, data);

    // Data is smaller than root's data, so search in the left subtree
    return search(root->left, data);
}

// In-order traversal of the binary search tree (left, root, right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Pre-order traversal (root, left, right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order traversal (left, right, root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Find the node with the minimum value in the BST
struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node from the binary search tree
struct Node* deleteNode(struct Node* root, int key) {
    // Base case: root is null
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's data
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    // If the key to be deleted is greater than the root's data
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    // If key is the same as root's data, this is the node to be deleted
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Main function to demonstrate the operations
int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nBinary Search Tree Operations Menu:\n");
        printf("1. Insert a node\n");
        printf("2. Search for a node\n");
        printf("3. In-order traversal\n");
        printf("4. Pre-order traversal\n");
        printf("5. Post-order traversal\n");
        printf("6. Delete a node\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert a node
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Node %d inserted.\n", value);
                break;
            
            case 2:
                // Search for a node
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* foundNode = search(root, value);
                if (foundNode != NULL)
                    printf("Node with value %d found in the tree.\n", value);
                else
                    printf("Node with value %d not found in the tree.\n", value);
                break;

            case 3:
                // In-order traversal
                printf("In-order traversal of the binary search tree: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                // Pre-order traversal
                printf("Pre-order traversal of the binary search tree: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                // Post-order traversal
                printf("Post-order traversal of the binary search tree: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
                // Delete a node
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Node %d deleted (if it existed).\n", value);
                break;

            case 7:
                // Exit
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
