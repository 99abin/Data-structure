// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* head = NULL;
node* tail = NULL;

node* create_node(int data);
void insert_front(int data);
void insert_rear(int data);
void insert_at(int index, int data);
void delete_at(int data);
int size();
void print();

int main() {
    insert_front(5);
    insert_front(9);
    insert_rear(7);
    
    print();
    cout << "size: " << size() << "\n";

    return 0;
}

node* create_node(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insert_front(int data) {
    if (head == NULL) {
        node* newnode = create_node(data);
        head = newnode;
        tail = newnode;
    } else {
        node* newnode = create_node(data);
        newnode->next = head;
        head = newnode;
    }
}

void insert_rear(int data){
    if (head == NULL) {
        node* newnode = create_node(data);
        head = newnode;
        tail = newnode;
    } else {
        node* newnode = create_node(data);
        tail->next = newnode;
        tail = newnode;
    }
}

void insert_at(int index, int data) {
    
}

void delete_at(int data) {
    
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

void print() {
    node* itr = head;
    while (itr != NULL) {
        cout << "[" << itr->data << "]--->";
        itr = itr->next;
    }
    cout << "[NULL]\n";
}
