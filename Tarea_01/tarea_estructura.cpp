#include <iostream>
using namespace std;

struct Vector
{
    int *m_pVect; // Puntero al buffer
    int m_nCount; // Controla cuántos elementos están realmente usados
    int m_nMax;   // Controla cuántos elementos están asignados como máximo
    int m_nDelta; // Para controlar el incremento
};

void Resize(Vector *pThis);

void Insert(Vector *pThis, int elem)
{
    if (pThis->m_nCount == pThis->m_nMax)
        Resize(pThis);

    pThis->m_pVect[pThis->m_nCount++] = elem;
}

void Resize(Vector *pThis)
{
    int *pTemp, i;
    pTemp = new int[pThis->m_nMax + pThis->m_nDelta]; // Allocate para un nuevo vector
    for (i = 0; i < pThis->m_nMax; i++)              // Transferir los elementos
        pTemp[i] = pThis->m_pVect[i];
    delete[] pThis->m_pVect; // Eliminar el vector antiguo
    pThis->m_pVect = pTemp;  // Actualizar el puntero
    pThis->m_nMax += pThis->m_nDelta; // El máximo debe incrementarse por delta
}

void Display(Vector *pThis)
{
    cout << "Elementos en el arreglo: ";
    for (int i = 0; i < pThis->m_nCount; i++)
    {
        cout << pThis->m_pVect[i] << " ";
    }
    cout << endl;
    cout << "Cantidad de elementos almacenados: " << pThis->m_nCount << endl;
}

int Search(Vector *pThis, int elem)
{
    for (int i = 0; i < pThis->m_nCount; i++)
    {
        if (pThis->m_pVect[i] == elem)
            return i; // Devuelve la posición del elemento encontrado
    }
    return -1;
}

void Delete(Vector *pThis, int elem)
{
    int pos = Search(pThis, elem);
    if (pos == -1)
    {
        cout << "Elemento " << elem << " no encontrado." << endl;
        return;
    }

    for (int i = pos; i < pThis->m_nCount - 1; i++)
    {
        pThis->m_pVect[i] = pThis->m_pVect[i + 1]; // Desplazar elementos a la izquierda
    }
    pThis->m_nCount--; // Reducir la cantidad de elementos
    cout << "Elemento " << elem << " eliminado." << endl;
}

int main()
{
    Vector myVect;
    myVect.m_nCount = 0;
    myVect.m_nMax = 0;
    myVect.m_nDelta = 5;
    myVect.m_pVect = nullptr;

    Insert(&myVect, 10); // Insertar elemento 10
    Insert(&myVect, 20); // Insertar elemento 20
    Insert(&myVect, 30); // Insertar elemento 30

    cout << "Vector inicial: " << endl;
    Display(&myVect); // Mostrar los elementos (Display)

    Delete(&myVect, 20); // Eliminar elemento 20

    cout << "Vector despues de eliminar: " << endl;
    Display(&myVect); // Mostrar los elementos (Display)

    delete[] myVect.m_pVect; // Liberar la memoria asignada

    return 0;
}
