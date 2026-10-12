#include <iostream>

struct Node {
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = 0;
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;
    
    Node* head = new Node(1);
    Node* current = head;
    
    for (int i = 2; i <= n; i++) {
        Node* newNode = new Node(i);
        current->next = newNode;
        current = newNode;
    }
    
    current->next = head;
    
    current = head;
    Node* prev = 0;
    
    while (current->next != head) {
        current = current->next;
    }
    prev = current;
    current = head;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            prev = current;
            current = current->next;
        }
        
        prev->next = current->next;
        int value = current->data;
        Node* temp = current;
        current = current->next;
        delete temp;
        
        std::cout << value << std::endl;
    }
    
    std::cout << current->data << std::endl;
    
    delete current;
    
    return 0;
}