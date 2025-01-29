#include <iostream>
using namespace std;

// Node structure using templates
template <typename T>
struct NODE
{
    T m_data;                 // Node data
    NODE<T> *m_pNext;         // Pointer to the next node
    NODE<T> *m_pPrev;         // Pointer to the previous node
};

// Doubly Linked List class using templates
template <typename T>
class CDoublyLinkedList
{
private:
    NODE<T> *m_pRoot;         // Pointer to the root node
    NODE<T> *m_pTail;         // Pointer to the tail node

public:
    // Constructor
    CDoublyLinkedList() : m_pRoot(nullptr), m_pTail(nullptr) {}

    // Destructor
    ~CDoublyLinkedList()
    {
        while (m_pRoot != nullptr)
        {
            NODE<T> *temp = m_pRoot;
            m_pRoot = m_pRoot->m_pNext;
            delete temp;
        }
    }

    // Method to insert a node at the end
    void InsertAtEnd(T data)
    {
        NODE<T> *newNode = new NODE<T>;
        newNode->m_data = data;
        newNode->m_pNext = nullptr;
        newNode->m_pPrev = nullptr;

        if (m_pRoot == nullptr)
        {
            m_pRoot = newNode;
            m_pTail = newNode;
        }
        else
        {
            m_pTail->m_pNext = newNode;  // The next node of the last node is the new node
            newNode->m_pPrev = m_pTail;  // The previous node of the new node is the last node
            m_pTail = newNode;           // Now, m_pTail points to the new node
        }
    }

    // Method to delete a node by value
    void Delete(T data)
    {
        if (m_pRoot == nullptr)
            return; // List is empty

        // Special case: deleting the root node
        if (m_pRoot->m_data == data)
        {
            NODE<T> *temp = m_pRoot;
            m_pRoot = m_pRoot->m_pNext;
            if (m_pRoot != nullptr)
                m_pRoot->m_pPrev = nullptr;
            else
                m_pTail = nullptr; // If the list becomes empty
            delete temp;
            return;
        }

        // Search for the node to delete
        NODE<T> *current = m_pRoot;
        while (current != nullptr && current->m_data != data)
        {
            current = current->m_pNext;
        }

        // If the node is found
        if (current != nullptr)
        {
            if (current->m_pNext != nullptr)
                current->m_pNext->m_pPrev = current->m_pPrev;
            else
                m_pTail = current->m_pPrev; // Update tail if deleting the last node

            if (current->m_pPrev != nullptr)
                current->m_pPrev->m_pNext = current->m_pNext;

            delete current;
        }
        else
        {
            cout << "Value " << data << " not found in the list!" << endl;
        }
    }

    // Method to print the list
    void Print() const
    {
        NODE<T> *current = m_pRoot;
        while (current != nullptr)
        {
            cout << current->m_data << " -> ";
            current = current->m_pNext;
        }
        cout << "nullptr" << endl;
    }
};

int main()
{
    CDoublyLinkedList<int> list;

    // Insert some elements
    list.InsertAtEnd(10);
    list.InsertAtEnd(20);
    list.InsertAtEnd(30);
    list.InsertAtEnd(5);

    // Print the list
    list.Print();

    cout << "Deleting 20 from the list." << endl;
    list.Delete(20);
    list.Print();

    return 0;
}
