#include <iostream>
using namespace std;

// Node structure for the circular linked list
struct Node {
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    
    // Create a circular linked list with n nodes
    Node* head = new Node(1);
    Node* current = head;
    
    // Create nodes with values 2 to n
    for (int i = 2; i <= n; i++) {
        Node* newNode = new Node(i);
        current->next = newNode;
        current = newNode;
    }
    
    // Connect the last node to the first node to make it circular
    current->next = head;
    
    // Start from the first node
    current = head;
    Node* prev = nullptr;
    
    // Find the last node to set up the initial prev pointer
    while (current->next != head) {
        current = current->next;
    }
    prev = current; // prev now points to the last node
    current = head; // current points to the first node
    
    // Process n-1 eliminations
    for (int i = 0; i < n - 1; i++) {
        // Move m-1 steps forward (since we're already on the first node to count)
        for (int j = 0; j < m - 1; j++) {
            prev = current;
            current = current->next;
        }
        
        // Delete the m-th node
        prev->next = current->next;
        int value = current->data;
        Node* temp = current;
        current = current->next;
        delete temp;
        
        cout << value << endl;
    }
    
    // Print the last remaining node
    cout << current->data << endl;
    
    // Clean up the last node
    delete current;
    
    return 0;
}