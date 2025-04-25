#include <iostream>
using namespace std;

class BST{
    struct node{
        int data;
        node* left;
        node* right;
    };

    node *root;

public:
    BST() {
        root = NULL;
    }

    void insert(int val) {
        node *temp = new node();
        temp->data = val;
        temp->left = NULL;
        temp->right = NULL;

        if (root == NULL) {
            root = temp;
            return;
        }

        node *curr = root;
        node *parent = NULL;

        while (curr != NULL) {
            parent = curr;
            if (val < curr->data) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        if (val < parent->data) {
            parent->left = temp;
        } else {
            parent->right = temp;
        }
    }

    void inorder(node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST b;
    b.insert(4);
    b.insert(5);
    b.insert(1);
    b.insert(10);

    b.inorder();
}
