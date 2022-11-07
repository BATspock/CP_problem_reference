//construct a binary search tree from an unsorted vector and return the number of edges between two nodes
//if the nodes are not in the tree, return -1

#include <bits/stdc++.h>

using namespace std;

//structure of a node in the tree
struct Node {
    int data;
    Node *left;
    Node *right;
};

//function to create a new node and insert it in the binary serach tree
Node* insert(Node *root, int data) {
    if (root == NULL) {
        root = new Node();
        root->data = data;
        root->left = root->right = NULL;
    }
    else if (data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

//function to check if a node is present in the binary search tree
bool search(Node *root, int data) {
    if (root == NULL) {
        return false;
    }
    else if (root->data == data) {
        return true;
    }
    else if (data <= root->data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

//function to find the number of edges between two nodes

int findEdges(Node *root, int a, int b) {

    if (root == NULL) {
        return -1;
    }
    else if (root->data == a || root->data == b) {
        return 0;
    }
    else if (a < root->data && b < root->data) {
        return 1 + findEdges(root->left, a, b);
    }
    else if (a > root->data && b > root->data) {
        return 1 + findEdges(root->right, a, b);
    }
    else {
        return 1 + findEdges(root->left, a, b) + findEdges(root->right, a, b);
    }
}

//function that takes vector as input construct tree and return the number of edges between two nodes

int edges(vector<int> v, int a, int b) {
    Node *root = NULL;
    for (int i = 0; i < v.size(); i++) {
        root = insert(root, v[i]);
    }
    if (search(root, a) && search(root, b)) {
        return findEdges(root, a, b);
    }
    else {
        return -1;
    }
}

int main(){
    //input vector
    vector<int> v = {8,7,13,6,2,5,1,9,11,3,4,10};
    //input nodes
    int a = 6, b = 9;
    cout << edges(v, a, b);
    return 0;
}