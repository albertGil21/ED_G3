#include <iostream>
using namespace std;

struct NODE 
{
    int m_data;
    NODE* m_pNext;
};

class Stack 
{
private:
    NODE* m_pTop;  // Apunta al nodo superior (último nodo insertado)
    
public:
    Stack() : m_pTop(nullptr) {}  // Constructor que inicializa la pila vacía
    
    // Método para agregar un nodo a la pila (push)
    void Push(int data) 
    {
        NODE* newNode = new NODE;
        newNode->m_data = data;
        newNode->m_pNext = m_pTop;  // El siguiente de este nuevo nodo será el anterior nodo superior
        m_pTop = newNode;           // Ahora, el nuevo nodo es el nodo superior
        cout << "Se ha insertado " << data << " en la pila." << endl;
    }
    
    // Método para eliminar un nodo de la pila (pop)
    void Pop() 
    {
        if (m_pTop == nullptr) 
        {
            cout << "La pila está vacía, no se puede hacer pop." << endl;
            return;
        }
        int removedData = m_pTop->m_data;
        NODE* temp = m_pTop;
        m_pTop = m_pTop->m_pNext;  // El nuevo nodo superior será el siguiente nodo
        delete temp;               // Liberar memoria del nodo que se elimina
        cout << "Se ha eliminado " << removedData << " de la pila." << endl;
    }
    
    // Método para obtener el valor superior de la pila (top)
    int Top() const 
    {
        if (m_pTop == nullptr) 
        {
            cout << "La pila está vacía." << endl;
            return -1;  // Devolver un valor que indique que la pila está vacía
        }
        return m_pTop->m_data;
    }
    
    // Método para verificar si la pila está vacía
    bool IsEmpty() const 
    {
        return m_pTop == nullptr;
    }
    
    // Método para imprimir el contenido de la pila
    void Print() const 
    {
        if (m_pTop == nullptr) 
        {
            cout << "La pila está vacía." << endl;
            return;
        }
        
        NODE* current = m_pTop;
        cout << "Contenido de la pila: ";
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
    Stack stack;
    int choice, value;

    cout << "Bienvenido al programa de Pilas (Stack)!" << endl;

    do 
    {
        cout << "\nSelecciona una operación:" << endl;
        cout << "1. Insertar (Push)" << endl;
        cout << "2. Eliminar (Pop)" << endl;
        cout << "3. Ver el valor superior (Top)" << endl;
        cout << "4. Verificar si la pila está vacía" << endl;
        cout << "5. Imprimir la pila" << endl;
        cout << "0. Salir" << endl;
        cout << "Opción: ";
        cin >> choice;

        switch(choice) 
        {
            case 1:
                cout << "Ingresa el valor a insertar: ";
                cin >> value;
                stack.Push(value);
                stack.Print();
                break;

            case 2:
                stack.Pop();
                stack.Print();
                break;

            case 3:
                value = stack.Top();
                if (value != -1) 
                {
                    cout << "El valor superior de la pila es: " << value << endl;
                }
                break;

            case 4:
                if (stack.IsEmpty()) 
                {
                    cout << "La pila está vacía." << endl;
                } 
                else 
                {
                    cout << "La pila no está vacía." << endl;
                }
                break;

            case 5:
                stack.Print();
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
