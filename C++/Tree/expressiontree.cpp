#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

struct node {
    string data;
    node* left;
    node* right;
};

node* root = NULL;
stack<int> operand;

node* create_node(string data);
void delete_leaf(string lval);
void insert_child(string pval, string dir, string data);
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

void delete_leaf(string lval) {
    if (root == NULL) {
        cout << "Tree is empty\n";
    } else if (root->data == lval) {
        cout << "This node isn't leaf\n";
    }
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        if (temp->left != NULL) {
            if (temp->left->data == lval && temp->left->left == NULL && temp->left->right == NULL) {
                temp->left = NULL;
                return;
            }
            q.push(temp->left);
        }
        if (temp->right != NULL) {
            if (temp->right->data == lval && temp->right->left == NULL && temp->right->right == NULL) {
                temp->right = NULL;
                return;
            }
            q.push(temp->right);
        }
    }
    cout << "Node with value " << lval << " not found\n";
}

void insert_child(string pval, string dir, string data) {
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
        if (temp->data == pval) {
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
        cout << "Node with value " << pval << " not found\n";
        return;
    }
    if (dir == "left") {
        if (point->left != NULL) {
            cout << "Left child already exists\n";
        } else {
            point->left = create_node(data);
        }
    } else if (dir == "right") {
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
    
    post_fix(temp->left);
    post_fix(temp->right);
    
    bool digit = true;
    for (char c : temp->data) {
        if (!isdigit(c)) {
            digit = false;
        }
    }
    if (digit == true) {
        operand.push(stoi(temp->data));
    } else {
        int val2 = operand.top();
        operand.pop();
        int val1 = operand.top();
        operand.pop();
        if (temp->data == "+") {
            operand.push(val1 + val2);
        } else if (temp->data == "-") {
            operand.push(val1 - val2);
        } else if (temp->data == "*") {
            operand.push(val1 * val2);
        } else if (temp->data == "/") {
            operand.push(val1 / val2);
        } else {
            cout << "invalid operator\n";
        }
    }
    
    return operand.top();
}
