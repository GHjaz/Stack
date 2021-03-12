#include <cassert> // для assert
#include <iostream>

#include <iomanip> // для setw

template <typename T>
class Stack
{
private:
    T* stackPtr;                      // указатель на стек
    const int size;                   // максимальное количество элементов в стеке
    int top;                          // номер текущего элемента стека
public:
    Stack(int = 1);                  // по умолчанию размер стека равен 1 
    Stack(const Stack<T>&);          // конструктор копирования
    ~Stack();                         // деструктор

    inline void push(const T&);     // поместить элемент в вершину стека
    inline T pop();                   // удалить элемент из вершины стека и вернуть его
    inline int getStackSize() const;  // получить размер стека

};

// реализация методов шаблона класса STack

// конструктор Стека
template <typename T>
Stack<T>::Stack(int maxSize) :
    size(maxSize) // инициализация константы
{
    stackPtr = new T[size]; // выделить память под стек
    top = 0; // инициализируем текущий элемент нулем;
}

// конструктор копирования
template <typename T>
Stack<T>::Stack(const Stack<T>& otherStack) :
    size(otherStack.getStackSize()) // инициализация константы
{
    stackPtr = new T[size]; // выделить память под новый стек
    top = otherStack.getTop();

    for (int ix = 0; ix < top; ix++)
        stackPtr[ix] = otherStack.getPtr()[ix];
}

// функция деструктора Стека
template <typename T>
Stack<T>::~Stack()
{
    delete[] stackPtr; // удаляем стек
}

// функция добавления элемента в стек
template <typename T>
inline void Stack<T>::push(const T& value)
{
    // проверяем размер стека
    stackPtr[top++] = value; // помещаем элемент в стек
}


template <typename T>
inline T Stack<T>::pop()
{
    stackPtr[--top]; 
    return stackPtr[top];
}

template <typename T>
inline int Stack<T>::getStackSize() const
{
    return size;
}

