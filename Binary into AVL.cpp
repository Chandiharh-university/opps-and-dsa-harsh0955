#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class GeneralTreeNode {
public:
    int data;
    vector<GeneralTreeNode*> children;

    GeneralTreeNode(int val) : data(val) {}
};

class BinaryTreeNode {
public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

BinaryTreeNode* convertGeneralToBinary(GeneralTreeNode* root) {
    if (root == nullptr) return nullptr;

    BinaryTreeNode* binaryNode = new BinaryTreeNode(root->data);

    if (!root->children.empty()) {
        binaryNode->left = convertGeneralToBinary(root->children[0]);
    }

    BinaryTreeNode* current = binaryNode->left;
    for (size_t i = 1; i < root->children.size(); ++i) {
        if (current) {
            current->right = convertGeneralToBinary(root->children[i]);
            current = current->right; // Move to the right child
        }
    }

    return binaryNode;
}

void inorderTraversal(BinaryTreeNode* root, vector<int>& elements) {
    if (root == nullptr) return;
    inorderTraversal(root->left, elements);
    elements.push_back(root->data);
    inorderTraversal(root->right, elements);
}

BinaryTreeNode* sortedArrayToAVL(vector<int>& elements, int start, int end) {
    if (start > end) return nullptr;

    int mid = (start + end) / 2;
    BinaryTreeNode* root = new BinaryTreeNode(elements[mid]);

    root->left = sortedArrayToAVL(elements, start, mid - 1);
    root->right = sortedArrayToAVL(elements, mid + 1, end);

    return root;
}

BinaryTreeNode* convertToAVL(BinaryTreeNode* root) {
    vector<int> elements;
    inorderTraversal(root, elements); // Step 1: Get sorted elements
    return sortedArrayToAVL(elements, 0, elements.size() - 1); // Step 2: Build AVL tree
}

void printInorder(BinaryTreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    
    GeneralTreeNode* generalRoot = new GeneralTreeNode(10);
    GeneralTreeNode* child1 = new GeneralTreeNode(5);
    GeneralTreeNode* child2 = new GeneralTreeNode(20);
    GeneralTreeNode* child3 = new GeneralTreeNode(3);
    GeneralTreeNode* child4 = new GeneralTreeNode(7);
    GeneralTreeNode* child5 = new GeneralTreeNode(30);

    generalRoot->children.push_back(child1);
    generalRoot->children.push_back(child2);
    child1->children.push_back(child3);
    child1->children.push_back(child4);
    child2->children.push_back(child5);

    BinaryTreeNode* binaryRoot = convertGeneralToBinary(generalRoot);

    cout << "Inorder of converted binary tree: ";
    printInorder(binaryRoot);
    cout << endl;

    BinaryTreeNode* avlRoot = convertToAVL(binaryRoot);

    cout << "Inorder of converted AVL tree: ";
    printInorder(avlRoot);
    cout << endl;

    // Ideally, you should implement a destructor or a cleanup function to free allocated memory.

    return 0;
}