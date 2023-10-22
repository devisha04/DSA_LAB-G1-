#include <iostream>

// Binary Tree Node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to perform a preorder traversal of a binary tree
void preorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Visit the current node
    std::cout << root->data << " ";

    // Recursively traverse the left subtree
    preorderTraversal(root->left);

    // Recursively traverse the right subtree
    preorderTraversal(root->right);
}

int main() {
    // Create a simple binary tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "Preorder Traversal: ";
    preorderTraversal(root);

    // Clean up the memory (optional but recommended)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
