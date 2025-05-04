#include <iostream>
#include <queue>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

node* root = NULL;

node* create_node(int data);
void delete_leaf_node(int val);
node* node_pointer(int val);
void post_order(node* temp);

int main() {
    create_node(5);
    node_pointer(5)->left = create_node(3);
    node_pointer(5)->right = create_node(7);
    node_pointer(3)->left = create_node(4);
    
    post_order(root);
    return 0;
}

node* create_node(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    if (root == NULL) {
        root = newnode;
    }
    return newnode;
}

node* node_pointer(int val) {
    if (root == NULL) {
        cout << "Tree is empty\n";
        return NULL;
    }
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        if (temp->data == val) {
            return temp;
        }
        if (temp->left != NULL) {
            if (temp->left->data == val) {
                return temp->left;
            }
            q.push(temp->left);
        }
        if (temp->right != NULL) {
            if (temp->right->data == val) {
                return temp->right;
            }
            q.push(temp->right);
        }
    }
    cout << "Node with value " << val << " not found\n";
    return NULL;
}

void post_order(node* temp) {
    if (temp == NULL) {
        return;
    } else {
        post_order(temp->left);
        post_order(temp->right);
        cout << "[" << temp->data << "]";
    }
}
