#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    
    Node(int value) {
        data = value;
        next = 0;
    }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    struct Node* head = new Node(1);
    struct Node* current = head;
    
    for (int i = 2; i <= n; i++) {
        struct Node* newNode = new Node(i);
        current->next = newNode;
        current = newNode;
    }
    
    current->next = head;
    
    current = head;
    struct Node* prev = 0;
    
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
        struct Node* temp = current;
        current = current->next;
        delete temp;
        
        printf("%d\n", value);
    }
    
    printf("%d\n", current->data);
    
    delete current;
    
    return 0;
}