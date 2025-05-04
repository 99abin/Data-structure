queue - cpp - linkedlist based
#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* head = NULL;
node* tail = NULL;

node* create_node(int data);
void enqueue(int data);
void dequeue();
int size();
void print();

int main() {
    enqueue(5);
    enqueue(7);
    dequeue();
    enqueue(8);
    dequeue();
    
    print();
    cout << "\nQueue size: " << size();
    return 0;
}

node* create_node(int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void enqueue(int data){
    if (head == NULL) {
        node* newnode = create_node(data);
        head = tail = newnode;
    } else {
        node* newnode = create_node(data);
        tail->next = newnode;
        tail = newnode;
    }
}

void dequeue(){
    if (head == NULL) {
        cout << "there's nothing to delete\n";
    } else {
        node* temp = head->next;
        head->next = NULL;
        head = temp;
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
