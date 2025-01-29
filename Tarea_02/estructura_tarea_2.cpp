#include <iostream>
using namespace std;

// Node structure using templates
template <typename T>
struct NODE
{
    T m_data;                 // Node data
    NODE<T> *m_pNext;         // Pointer to the next node
};

// Linked List class using templates
template <typename T>
class CLinkedList
{
private:
    NODE<T> *m_pRoot;         // Pointer to the root node

public:
    // Constructor
    CLinkedList() : m_pRoot(nullptr) {}

    // Destructor
    ~CLinkedList()
    {
        while (m_pRoot != nullptr)
        {
            NODE<T> *temp = m_pRoot;
            m_pRoot = m_pRoot->m_pNext;
            delete temp;
        }
    }

    // Method to insert a node at the end of the list
    void InsertAtEnd(T data)
    {
        NODE<T> *newNode = new NODE<T>;
        newNode->m_data = data;
        newNode->m_pNext = nullptr;

        if (m_pRoot == nullptr)
        {
            m_pRoot = newNode;
        }
        else
        {
            NODE<T> *current = m_pRoot;
            while (current->m_pNext != nullptr)
            {
                current = current->m_pNext;
            }
            current->m_pNext = newNode;
        }
    }

    // Method to insert a node at the beginning of the list
    void InsertAtBeginning(T data)
    {
        NODE<T> *newNode = new NODE<T>;
        newNode->m_data = data;
        newNode->m_pNext = m_pRoot;
        m_pRoot = newNode;
    }

    // Method to delete a node by value
    void Delete(T data)
    {
        if (m_pRoot == nullptr)
            return;

        // Special case: deleting the root node
        if (m_pRoot->m_data == data)
        {
            NODE<T> *temp = m_pRoot;
            m_pRoot = m_pRoot->m_pNext;
            delete temp;
            return;
        }

        // Search for the node to delete
        NODE<T> *current = m_pRoot;
        while (current->m_pNext != nullptr && current->m_pNext->m_data != data)
        {
            current = current->m_pNext;
        }

        // If we found the node
        if (current->m_pNext != nullptr)
        {
            NODE<T> *temp = current->m_pNext;
            current->m_pNext = current->m_pNext->m_pNext;
            delete temp;
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
    CLinkedList<int> list;

    // Insert some elements at the end
    list.InsertAtEnd(10);
    list.InsertAtEnd(20);
    list.InsertAtEnd(30);

    // Insert an element at the beginning
    list.InsertAtBeginning(5);

    // Print the list
    list.Print();

    // Delete an element
    cout << "Deleting 20 from the list." << endl;
    list.Delete(20);
    list.Print();

    return 0;
}
