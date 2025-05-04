#include <iostream>
#include <queue>
#include <string>
#include <cctype>
using namespace std;

struct node {
    string data;
    node* left;
    node* right;
};

node* root = NULL;

node* create_node(string data);
void delete_leaf(string val);
void insert_child(string val, string lr, string data);
void post_order(node* temp);
int post_fix(node* temp);

int main() {
    root = create_node("/"); 
    insert_child("/", "left", "+");
    insert_child("/", "right", "-");
    insert_child("+", "left", "3");
    insert_child("+", "right", "*");
    insert_child("-", "left", "13");
    insert_child("-", "right", "4");
    insert_child("*", "left", "8");
    insert_child("*", "right", "3");
    
    post_order(root);
    cout << "\npostfix value: " << post_fix(root);
    return 0;
}

node* create_node(string data) {
    node* newnode = new node(); 
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

void delete_leaf(string val) {
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

void insert_child(string val, string lr, string data) {
    if (root == NULL) {
        cout << "Tree is empty\n";
        return;
    }
    queue<node*> q;
    q.push(root);
    node* point = NULL;
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        if (temp->data == val) {
            point = temp;
            break;
        }
        if (temp->left != NULL) {
            q.push(temp->left);
        }
        if (temp->right != NULL) {
            q.push(temp->right);
        }
    }
    if (point == NULL) {
        cout << "Node with value " << val << " not found\n";
        return;
    }
    if (lr == "left") {
        if (point->left != NULL) {
            cout << "Left child already exists\n";
        } else {
            point->left = create_node(data);
        }
    } else if (lr == "right") {
        if (point->right != NULL) {
            cout << "Right child already exists\n";
        } else {
            point->right = create_node(data);
        }
    } else {
        cout << "Invalid direction\n";
    }
}

void post_order(node* temp) {
    if (temp == NULL) {
        return;
    }
    post_order(temp->left);
    post_order(temp->right);
    cout << "[" << temp->data << "]";
}


int post_fix(node* temp) {
    if (temp == NULL) {
        return 0;
    }
    
    int left_val = post_fix(temp->left);
    int right_val = post_fix(temp->right);
    
    bool isDigit = true;
    for (char c : temp->data) {
        if (!isdigit(c)) {
            isDigit = false;
            break;
        }
    }
    
    if (isDigit) {
        return stoi(temp->data);
    } else {
        if (temp->data == "+") {
            return left_val + right_val;
        } else if (temp->data == "-") {
            return left_val - right_val;
        } else if (temp->data == "*") {
            return left_val * right_val;
        } else if (temp->data == "/") {
            return left_val / right_val;
        } else {
            cout << "Invalid operator: " << temp->data << endl;
            return 0;
        }
    }
}
