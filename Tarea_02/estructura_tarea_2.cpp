#include <iostream>
using namespace std;

// ESTRUCTURA DEL NODO
template <typename T>
struct NODE {
    T m_data;
    NODE* m_pNext;
};

// CLASE LISTA CIRCULAR SIMPLEMENTE ENLAZADA
template <typename T>
class CLinkedList {
private:
    NODE<T>* m_pRoot;
public:
    CLinkedList() : m_pRoot(nullptr) {}
    
    // INSERTAR NODO AL FINAL
    void Insert(T data) {
        NODE<T>* newNode = new NODE<T>;
        newNode->m_data = data;
        if (m_pRoot == nullptr) {
            m_pRoot = newNode;
            m_pRoot->m_pNext = m_pRoot; // ENLACE CIRCULAR
        } else {
            NODE<T>* current = m_pRoot;
            while (current->m_pNext != m_pRoot) {
                current = current->m_pNext;
            }
            current->m_pNext = newNode;
            newNode->m_pNext = m_pRoot;
        }
    }
    
    // INSERTAR NODO AL INICIO
    void InsertAtHead(T data) {
        NODE<T>* newNode = new NODE<T>;
        newNode->m_data = data;
        if (m_pRoot == nullptr) {
            m_pRoot = newNode;
            m_pRoot->m_pNext = m_pRoot; // ENLACE CIRCULAR
        } else {
            NODE<T>* current = m_pRoot;
            while (current->m_pNext != m_pRoot) {
                current = current->m_pNext;
            }
            newNode->m_pNext = m_pRoot;
            current->m_pNext = newNode;
            m_pRoot = newNode; // ACTUALIZAR RAÍZ AL NUEVO INICIO
        }
    }
    
    // IMPRIMIR LISTA
    void Print() const {
        if (m_pRoot == nullptr) {
            cout << "Lista vacía" << endl;
            return;
        }
        NODE<T>* current = m_pRoot;
        do {
            cout << current->m_data << " -> ";
            current = current->m_pNext;
        } while (current != m_pRoot);
        cout << "(VUELTA A LA RAÍZ)" << endl;
    }
    
    // ELIMINAR UN NODO POR VALOR
    void Delete(T data) {
        if (m_pRoot == nullptr) return;
        
        NODE<T>* current = m_pRoot;
        NODE<T>* prev = nullptr;
        
        // BUSCAR NODO A ELIMINAR
        do {
            if (current->m_data == data) {
                if (prev != nullptr) {
                    prev->m_pNext = current->m_pNext;
                    if (current == m_pRoot) {
                        m_pRoot = prev->m_pNext;
                    }
                } else {
                    // ELIMINAR NODO RAÍZ
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
    
    // INSERTAR ELEMENTOS AL FINAL
    list.Insert(10);
    list.Insert(20);
    list.Insert(30);
    list.Insert(40);
    list.Print();
    
    // INSERTAR AL INICIO
    cout << "Insertando al inicio: 5" << endl;
    list.InsertAtHead(5);
    list.InsertAtHead(12);
    list.InsertAtHead(90);
    list.InsertAtHead(60);
    list.Print();
    
    // ELIMINAR ELEMENTO
    cout << "Eliminando 20 de la lista." << endl;
    list.Delete(20);
    list.Print();
    
    return 0;
}
