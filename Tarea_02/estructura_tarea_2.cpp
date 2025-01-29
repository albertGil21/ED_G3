#include <iostream>
using namespace std;

// Estructura de nodo con templates
template <typename T>
struct NODE
{
    T m_data;
    NODE<T> *m_pNext;
    NODE<T> *m_pPrev;
};

// Lista doblemente enlazada con templates
template <typename T>
class CDoublyLinkedList
{
private:
    NODE<T> *m_pRoot;
    NODE<T> *m_pTail;

public:
    CDoublyLinkedList() : m_pRoot(nullptr), m_pTail(nullptr) {}

    ~CDoublyLinkedList()
    {
        while (m_pRoot != nullptr)
        {
            NODE<T> *temp = m_pRoot;
            m_pRoot = m_pRoot->m_pNext;
            delete temp;
        }
    }

    // Insertar un nodo al final
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
            m_pTail->m_pNext = newNode;
            newNode->m_pPrev = m_pTail;
            m_pTail = newNode;
        }
    }

    // Eliminar un nodo por valor
    void Delete(T data)
    {
        if (m_pRoot == nullptr)
            return;

        if (m_pRoot->m_data == data)
        {
            NODE<T> *temp = m_pRoot;
            m_pRoot = m_pRoot->m_pNext;
            if (m_pRoot != nullptr)
                m_pRoot->m_pPrev = nullptr;
            else
                m_pTail = nullptr;
            delete temp;
            return;
        }

        NODE<T> *current = m_pRoot;
        while (current != nullptr && current->m_data != data)
        {
            current = current->m_pNext;
        }

        if (current != nullptr)
        {
            if (current->m_pNext != nullptr)
                current->m_pNext->m_pPrev = current->m_pPrev;
            else
                m_pTail = current->m_pPrev;

            if (current->m_pPrev != nullptr)
                current->m_pPrev->m_pNext = current->m_pNext;

            delete current;
        }
        else
        {
            cout << "Valor " << data << " no encontrado en la lista!" << endl;
        }
    }

    // Imprimir la lista
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

    list.InsertAtEnd(10);
    list.InsertAtEnd(20);
    list.InsertAtEnd(30);
    list.InsertAtEnd(5);

    list.Print();

    cout << "Eliminando 20 de la lista." << endl;
    list.Delete(20);
    list.Print();

    return 0;
}
