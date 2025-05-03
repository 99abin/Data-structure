#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* head = NULL;
node* tail = NULL;

node* create_node(int data);
void push(int data);
void pop();
int size();
void print();

int main() {
    push(3);
    push(5);
    pop();
    push(17);
    pop();
    push(15);
    push(2);
    
    print();
    cout << "\nStack size: " << size();
    return 0;
}

node* create_node(int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void push(int data){
    if (head == NULL) {
        node* newnode = create_node(data);
        head = tail = newnode;
    } else {
        node* newnode = create_node(data);
        tail->next = newnode;
        tail = newnode;
    }
}

void pop(){
    if (head == NULL) {
        cout << "There's nothing to delete\n";
    } else {
        node* itr = head;
        while (itr->next != tail) {
            itr = itr->next;
        }
        itr->next = NULL;
        tail = itr;
    }
}

int size() {
    node* itr = head;
    int count = 0;
    while (itr != NULL) {
        count++;
        itr = itr->next;
    }
    return count;
}

void print(){
    if (head == NULL) {
        cout << "Stack is empty\n";
    } else {
        node* itr = head;
        while (itr != NULL) {
            cout << "[" << itr->data << "]";
            itr = itr->next;
        }
    }
}
