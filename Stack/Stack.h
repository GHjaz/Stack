#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "ExceptionStack.h"


template <typename T>
class Stack
{
private:
    T* stackPtr;                      // указатель на стек
    const int size;                   // максимальное количество элементов в стеке
    int top;                          // номер текущего элемента стека
public:
    Stack(int = 10);                  // по умолчанию размер стека равен 1 
    Stack(const Stack<T>&);          // конструктор копирования
    ~Stack();                         // деструктор

    inline void push(const T&);     // поместить элемент в вершину стека
    inline T pop();                   // удалить элемент из вершины стека и вернуть его
    inline int getStackSize() const;    // получить размер стека
    inline T* getPtr() const;         // получить указатель на стек
    inline int getTop() const;        // получить номер текущего элемента в стеке

};



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
    //.. Обрабатываем исключение
    if (size == top) { throw exc::StackOverFlow("Stack Overflow"); }
    
    stackPtr[top++] = value;
   
}

//..Функция удаления
template <typename T>
inline T Stack<T>::pop()
{
    const char* Er = "Stack empty";
    // .. Обрабатываем исключения
    if (top == NULL) { throw exc::StackEmpty("Stack Empty"); }
    stackPtr[--top];
}

// вернуть размер стека
template <typename T>
inline int Stack<T>::getStackSize() const
{
    return size;
}

// вернуть указатель на стек (для конструктора копирования)
template <typename T>
inline T* Stack<T>::getPtr() const
{
    return stackPtr;
}

// вернуть размер стека
template <typename T>
inline int Stack<T>::getTop() const
{
    return top;
}

