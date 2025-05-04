#include <iostream>
#include <queue>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

node* root = NULL;

void create_node(int data);
node* nodepointer(int val);

int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";

    return 0;
}

void create_node(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
}

node* nodepointer(int val) {
    if (root != NULL) {
        cout << "node didn't exist\n";
    } else {
        queue<node*> q;
        q.push(root);
        while (q.front()->data != val) {
            if (q.front()->left->data == val) {
                return q.front()->left;
            } else {
                q.push(q.front()->left);
            }
            if (q.front()->right->data == val) {
                return q.front()->right;
            } else {
                q.push(q.front()->right);
            }
            q.pop();
        }
    }
    cout << "node didn't exist\n";
    return NULL;
}
