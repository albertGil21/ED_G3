#include <iostream>
using namespace std;

// Template structure for Node
template <typename T>
struct NODE {
    T m_data;
    NODE* m_pNext;
};

// Template class for Circular Linked List
template <typename T>
class CLinkedList {
private:
    NODE<T>* m_pRoot;
public:
    CLinkedList() : m_pRoot(nullptr) {}
    
    // Insert node at the end
    void Insert(T data) {
        NODE<T>* newNode = new NODE<T>;
        newNode->m_data = data;
        if (m_pRoot == nullptr) {
            m_pRoot = newNode;
            m_pRoot->m_pNext = m_pRoot; // Circular link
        } else {
            NODE<T>* current = m_pRoot;
            while (current->m_pNext != m_pRoot) {
                current = current->m_pNext;
            }
            current->m_pNext = newNode;
            newNode->m_pNext = m_pRoot;
        }
    }
    
    // Insert node at the beginning
    void InsertAtHead(T data) {
        NODE<T>* newNode = new NODE<T>;
        newNode->m_data = data;
        if (m_pRoot == nullptr) {
            m_pRoot = newNode;
            m_pRoot->m_pNext = m_pRoot; // Circular link
        } else {
            NODE<T>* current = m_pRoot;
            while (current->m_pNext != m_pRoot) {
                current = current->m_pNext;
            }
            newNode->m_pNext = m_pRoot;
            current->m_pNext = newNode;
            m_pRoot = newNode; // Update root to new head
        }
    }
    
    // Print the list
    void Print() const {
        if (m_pRoot == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        NODE<T>* current = m_pRoot;
        do {
            cout << current->m_data << " -> ";
            current = current->m_pNext;
        } while (current != m_pRoot);
        cout << "(back to root)" << endl;
    }
    
    // Delete a node by value
    void Delete(T data) {
        if (m_pRoot == nullptr) return;
        
        NODE<T>* current = m_pRoot;
        NODE<T>* prev = nullptr;
        
        // Searching for node to delete
        do {
            if (current->m_data == data) {
                if (prev != nullptr) {
                    prev->m_pNext = current->m_pNext;
                    if (current == m_pRoot) {
                        m_pRoot = prev->m_pNext;
                    }
                } else {
                    // Deleting root node
                    if (m_pRoot->m_pNext == m_pRoot) {
                        delete m_pRoot;
                        m_pRoot = nullptr;
                        return;
                    }
                    NODE<T>* temp = m_pRoot;
                    while (temp->m_pNext != m_pRoot) {
                        temp = temp->m_pNext;
                    }
                    temp->m_pNext = m_pRoot->m_pNext;
                    m_pRoot = m_pRoot->m_pNext;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->m_pNext;
        } while (current != m_pRoot);
    }
};

int main() {
    CLinkedList<int> list;
    
    list.Insert(10);
    list.Insert(20);
    list.Insert(30);
    list.Insert(40);
    list.Print();
    
    cout << "Inserting at head: 5" << endl;
    list.InsertAtHead(5);
    list.Print();
    
    cout << "Deleting 20 from the list." << endl;
    list.Delete(20);
    list.Print();
    
    return 0;
}
