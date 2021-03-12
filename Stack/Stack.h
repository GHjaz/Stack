#include <cassert> // ��� assert
#include <iostream>
#include <string>
#include <iomanip> // ��� setw

namespace exc {
    class EStackExcepetion {
    public:
        EStackExcepetion(const char* arg_message) {
            message = new char[strlen(arg_message) + 1];
            int N = strlen(arg_message) + 1;
            strcpy_s(message, N, arg_message);
        }
        const char* what() const { return message; }
    private:
        char* message;
    };

    class EStackEmpty :public EStackExcepetion {
    public:
        EStackEmpty(const char* arg) :EStackExcepetion(arg) {}
    };

    class EStackOverflow :public EStackExcepetion {
    public:
        EStackOverflow(const char* arg) :EStackExcepetion(arg) {}
    };
}


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
    try {
       /* if (size >= top)
            throw exc::EStackOverflow((char*)"Stack OverFlow");*/
        stackPtr[top++] = value;
    }
    catch(const exc::EStackOverflow &e){
        cout << e.what() << endl;
    }// �������� ������� � ����
}


template <typename T>
inline T Stack<T>::pop()
{

    try {
      /*  if (top == NULL)
            throw exc::EStackEmpty((char*)"Stack Empty");*/
        stackPtr[--top];
    }
    catch (const exc::EStackEmpty &e) {
        cout << e.what() << endl;
    }// �������� ������� � ����
}

template <typename T>
inline int Stack<T>::getStackSize() const
{
    return size;
}

