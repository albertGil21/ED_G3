#include <iostream>
using namespace std;

struct NODE
{
    int m_data;
    NODE* m_pNext;
};

class CCircularLinkedList
{
private:
    NODE* m_pRoot;

public:
    CCircularLinkedList() : m_pRoot(nullptr) {}

    // Método para insertar un nodo al final
    void Insert(int data)
    {
        NODE* newNode = new NODE;
        newNode->m_data = data;

        if (m_pRoot == nullptr)
        {
            m_pRoot = newNode;
            newNode->m_pNext = m_pRoot; // El primer nodo apunta a sí mismo
        }
        else
        {
            NODE* current = m_pRoot;
            while (current->m_pNext != m_pRoot)
            {
                current = current->m_pNext;
            }
            current->m_pNext = newNode;
            newNode->m_pNext = m_pRoot; // Mantener la circularidad
        }
    }

    // Método para imprimir la lista
    void Print() const
    {
        if (m_pRoot == nullptr)
        {
            cout << "La lista está vacía." << endl;
            return;
        }

        NODE* current = m_pRoot;
        do
        {
            cout << current->m_data << " -> ";
            current = current->m_pNext;
        } while (current != m_pRoot);
        cout << "(inicio)" << endl; // Indica que se completó el ciclo
    }

    // Método para borrar un nodo con un valor específico
    void Delete(int data)
    {
        if (m_pRoot == nullptr)
        {
            cout << "La lista está vacía." << endl;
            return; // Lista vacía, no hay nada que borrar
        }

        NODE* current = m_pRoot;
        NODE* prev = nullptr;

        // Caso especial: eliminar el nodo raíz
        if (m_pRoot->m_data == data)
        {
            // Si solo hay un nodo en la lista
            if (m_pRoot->m_pNext == m_pRoot)
            {
                delete m_pRoot;
                m_pRoot = nullptr;
                cout << "Se eliminó el único nodo de la lista." << endl;
                return;
            }

            // Buscar el último nodo para actualizar su enlace
            NODE* last = m_pRoot;
            while (last->m_pNext != m_pRoot)
            {
                last = last->m_pNext;
            }

            NODE* temp = m_pRoot;
            m_pRoot = m_pRoot->m_pNext;
            last->m_pNext = m_pRoot; // Mantener la circularidad
            delete temp;
            cout << "Nodo raíz eliminado exitosamente." << endl;
            return;
        }

        // Buscar el nodo a eliminar
        do
        {
            prev = current;
            current = current->m_pNext;

            if (current->m_data == data)
            {
                prev->m_pNext = current->m_pNext;
                delete current;
                cout << "Nodo con valor " << data << " eliminado exitosamente." << endl;
                return;
            }
        } while (current != m_pRoot);

        cout << "Valor " << data << " no encontrado en la lista." << endl;
    }
};

int main()
{
    CCircularLinkedList list;

    // Insertar algunos elementos iniciales
    list.Insert(10);
    list.Insert(20);
    list.Insert(30);
    list.Insert(5);

    cout << "Lista inicial:" << endl;
    list.Print();

    char continuar;
    do
    {
        int valor;
        cout << "\nIngresa el número que deseas borrar: ";
        cin >> valor;

        list.Delete(valor);

        cout << "Lista actualizada:" << endl;
        list.Print();

        cout << "\n¿Deseas borrar otro número? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    cout << "Programa finalizado." << endl;

    return 0;
}
