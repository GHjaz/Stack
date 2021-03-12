#include <cassert> // ��� assert
#include <iostream>

#include <iomanip> // ��� setw

template <typename T>
class Stack
{
private:
    T* stackPtr;                      // ��������� �� ����
    const int size;                   // ������������ ���������� ��������� � �����
    int top;                          // ����� �������� �������� �����
public:
    Stack(int = 1);                  // �� ��������� ������ ����� ����� 1 
    Stack(const Stack<T>&);          // ����������� �����������
    ~Stack();                         // ����������

    inline void push(const T&);     // ��������� ������� � ������� �����
    inline T pop();                   // ������� ������� �� ������� ����� � ������� ���
    inline int getStackSize() const;  // �������� ������ �����

};

// ���������� ������� ������� ������ STack

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
    // ��������� ������ �����
    stackPtr[top++] = value; // �������� ������� � ����
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

