#include <iostream>
using namespace std;

struct NODE 
{
    int m_data;
    NODE* m_pNext;
};

class Queue 
{
private:
    NODE* m_pFront;  // Apunta al nodo frontal (primer nodo insertado)
    NODE* m_pRear;   // Apunta al nodo trasero (último nodo insertado)
    
public:
    Queue() : m_pFront(nullptr), m_pRear(nullptr) {}  // Constructor que inicializa la cola vacía
    
    // Método para agregar un nodo al final de la cola (enqueue)
    void Enqueue(int data) 
    {
        NODE* newNode = new NODE;
        newNode->m_data = data;
        newNode->m_pNext = nullptr;
        
        if (m_pRear == nullptr) 
        {
            // Si la cola está vacía, tanto el frente como el trasero apuntan al nuevo nodo
            m_pFront = newNode;
            m_pRear  = newNode;
        } 
        else 
        {
            // Si la cola no está vacía, el nodo trasero apunta al nuevo nodo
            m_pRear->m_pNext = newNode;
            m_pRear = newNode;  // Ahora, el nuevo nodo es el nodo trasero
        }
        cout << "Se ha insertado " << data << " en la cola." << endl;
    }
    
    // Método para eliminar un nodo de la cola (dequeue)
    void Dequeue() 
    {
        if (m_pFront == nullptr) 
        {
            cout << "La cola está vacía, no se puede hacer dequeue." << endl;
            return;
        }
        int removedData = m_pFront->m_data;
        NODE* temp = m_pFront;
        m_pFront = m_pFront->m_pNext;  // El nuevo frente será el siguiente nodo
        delete temp;  // Liberar memoria del nodo que se elimina
        
        if (m_pFront == nullptr) 
        {
            m_pRear = nullptr;  // Si la cola está vacía, el nodo trasero también debe ser nulo
        }
        cout << "Se ha eliminado " << removedData << " de la cola." << endl;
    }
    
    // Método para obtener el valor del frente de la cola (front)
    int Front() const {
        if (m_pFront == nullptr) {
            cout << "La cola está vacía." << endl;
            return -1;  // Devolver un valor que indique que la cola está vacía
        }
        return m_pFront->m_data;
    }
    
    // Método para verificar si la cola está vacía
    bool IsEmpty() const {
        return m_pFront == nullptr;
    }
    
    // Método para imprimir el contenido de la cola
    void Print() const 
    {
        if (m_pFront == nullptr) {
            cout << "La cola está vacía." << endl;
            return;
        }
        
        NODE* current = m_pFront;
        cout << "Contenido de la cola: ";
        while (current != nullptr) {
            cout << current->m_data << " -> ";
            current = current->m_pNext;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    Queue queue;
    int choice, value;

    cout << "Bienvenido al programa de Cola (Queue)!" << endl;

    do {
        cout << "\nSelecciona una operación:" << endl;
        cout << "1. Insertar (Enqueue)" << endl;
        cout << "2. Eliminar (Dequeue)" << endl;
        cout << "3. Ver frente de la cola" << endl;
        cout << "4. Verificar si la cola está vacía" << endl;
        cout << "5. Imprimir la cola" << endl;
        cout << "0. Salir" << endl;
        cout << "Opción: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Ingresa el valor a insertar: ";
                cin >> value;
                queue.Enqueue(value);
                queue.Print();
                break;

            case 2:
                queue.Dequeue();
                queue.Print();
                break;

            case 3:
                value = queue.Front();
                if (value != -1) {
                    cout << "El frente de la cola es: " << value << endl;
                }
                break;

            case 4:
                if (queue.IsEmpty()) {
                    cout << "La cola está vacía." << endl;
                } else {
                    cout << "La cola no está vacía." << endl;
                }
                break;

            case 5:
                queue.Print();
                break;

            case 0:
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                break;

            default:
                cout << "Opción no válida. Por favor, elige una opción correcta." << endl;
                break;
        }

    } while (choice != 0);

    return 0;
}
