#include <iostream>
using namespace std;

// ESTRUCTURA DEL NODO PARA LISTA DOBLEMENTE ENLAZADA
template <typename T>
struct NODE {
    T m_data;
    NODE* m_pNext;
    NODE* m_pPrev;
};

// CLASE LISTA DOBLEMENTE ENLAZADA
template <typename T>
class CDoublyLinkedList {
private:
    NODE<T>* m_pRoot;
    NODE<T>* m_pTail;
public:
    CDoublyLinkedList() : m_pRoot(nullptr), m_pTail(nullptr) {}
    
    // INSERTAR NODO AL FINAL
    void Insert(T data) {
        NODE<T>* newNode = new NODE<T>;
        newNode->m_data = data;
        newNode->m_pNext = nullptr;
        newNode->m_pPrev = nullptr;
        
        if (m_pRoot == nullptr) {
            m_pRoot = newNode;
            m_pTail = newNode;
        } else {
            m_pTail->m_pNext = newNode;
            newNode->m_pPrev = m_pTail;
            m_pTail = newNode;
        }
    }
    
    // IMPRIMIR LISTA
    void Print() const {
        NODE<T>* current = m_pRoot;
        while (current != nullptr) {
            cout << current->m_data << " <-> ";
            current = current->m_pNext;
        }
        cout << "nullptr" << endl;
    }
    
    // ELIMINAR UN NODO POR VALOR
    void Delete(T data) {
        if (m_pRoot == nullptr) return;
        
        NODE<T>* current = m_pRoot;
        while (current != nullptr && current->m_data != data) {
            current = current->m_pNext;
        }
        
        if (current == nullptr) return; // No se encontró el nodo
        
        if (current == m_pRoot) { // ELIMINAR PRIMER NODO
            m_pRoot = current->m_pNext;
            if (m_pRoot != nullptr) {
                m_pRoot->m_pPrev = nullptr;
            } else {
                m_pTail = nullptr;
            }
        } else if (current == m_pTail) { // ELIMINAR ÚLTIMO NODO
            m_pTail = current->m_pPrev;
            if (m_pTail != nullptr) {
                m_pTail->m_pNext = nullptr;
            } else {
                m_pRoot = nullptr;
            }
        } else { // ELIMINAR NODO INTERMEDIO
            current->m_pPrev->m_pNext = current->m_pNext;
            current->m_pNext->m_pPrev = current->m_pPrev;
        }
        
        delete current;
    }
};

int main() {
    CDoublyLinkedList<int> list;
    
    // INSERTAR ELEMENTOS
    list.Insert(10);
    list.Insert(20);
    list.Insert(30);
    list.Insert(5);
    list.Print();
    
    // ELIMINAR UN ELEMENTO
    cout << "Eliminando 20 de la lista." << endl;
    list.Delete(20);
    list.Print();
    list.Delete(10);
    list.Print();
    list.Delete(5);
    list.Print();
    list.Delete(30);
    list.Print();
    
    return 0;
}
