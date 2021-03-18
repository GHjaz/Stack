#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "ExceptionStack.h"


template <typename T>
class Stack
{
private:
    T* stackPtr;                      // ��������� �� ����
    const int size;                   // ������������ ���������� ��������� � �����
    int top;                          // ����� �������� �������� �����
public:
    Stack(int = 10);                  // �� ��������� ������ ����� ����� 1 
    Stack(const Stack<T>&);          // ����������� �����������
    ~Stack();                         // ����������

    inline void push(const T&);     // ��������� ������� � ������� �����
    inline T pop();                   // ������� ������� �� ������� ����� � ������� ���
    inline int getStackSize() const;    // �������� ������ �����
    inline T* getPtr() const;         // �������� ��������� �� ����
    inline int getTop() const;        // �������� ����� �������� �������� � �����

};



// ����������� �����
template <typename T>
Stack<T>::Stack(int maxSize) :
    size(maxSize) // ������������� ���������
{
    stackPtr = new T[size]; // �������� ������ ��� ����
    top = 0; // �������������� ������� ������� �����;
}

// ����������� �����������
template <typename T>
Stack<T>::Stack(const Stack<T>& otherStack) :
    size(otherStack.getStackSize()) // ������������� ���������
{
    stackPtr = new T[size]; // �������� ������ ��� ����� ����
    top = otherStack.getTop();

    for (int ix = 0; ix < top; ix++)
        stackPtr[ix] = otherStack.getPtr()[ix];
}

// ������� ����������� �����
template <typename T>
Stack<T>::~Stack()
{
    delete[] stackPtr; // ������� ����
}

// ������� ���������� �������� � ����
template <typename T>
inline void Stack<T>::push(const T& value)
{
    //.. ������������ ����������
    if (size == top) { throw exc::StackOverFlow("Stack Overflow"); }
    
    stackPtr[top++] = value;
   
}

//..������� ��������
template <typename T>
inline T Stack<T>::pop()
{
    const char* Er = "Stack empty";
    // .. ������������ ����������
    if (top == NULL) { throw exc::StackEmpty("Stack Empty"); }
    stackPtr[--top];
}

// ������� ������ �����
template <typename T>
inline int Stack<T>::getStackSize() const
{
    return size;
}

// ������� ��������� �� ���� (��� ������������ �����������)
template <typename T>
inline T* Stack<T>::getPtr() const
{
    return stackPtr;
}

// ������� ������ �����
template <typename T>
inline int Stack<T>::getTop() const
{
    return top;
}

