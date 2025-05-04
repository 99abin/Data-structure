#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

node* root = NULL;

node* create_node(int data);
void delete_leaf(int val);
node* node_pointer(int val);
void insert_child(int val, string lr, int data);
void post_order(node* temp);

int main() {
    create_node(5);
    insert_child(5, "left", 3);
    insert_child(5, "right", 7);
    insert_child(3, "left", 4);
    insert_child(7, "left", 8);
    
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

void delete_leaf(int val) {
    if (root == NULL) {
        cout << "Tree is empty\n";
    } else if (root->data == val) {
        cout << "This node isn't leaf\n";
    }
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        if (temp->left != NULL) {
            if (temp->left->data == val && temp->left->left == NULL && temp->left->right == NULL) {
                temp->left = NULL;
                return;
            }
            q.push(temp->left);
        }
        if (temp->right != NULL) {
            if (temp->right->data == val && temp->right->left == NULL && temp->right->right == NULL) {
                temp->right = NULL;
                return;
            }
            q.push(temp->right);
        }
    }
    cout << "Node with value " << val << " not found\n";
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

void insert_child(int val, string lr, int data) {
    if (lr == "left") {
        node_pointer(val)->left = create_node(data);
    } else if(lr == "right") {
        node_pointer(val)->right = create_node(data);
    }
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
