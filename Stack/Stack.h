#include <cassert> // для assert
#include <iostream>
#include <string>
#include <iomanip> // для setw

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
    try {
       /* if (size >= top)
            throw exc::EStackOverflow((char*)"Stack OverFlow");*/
        stackPtr[top++] = value;
    }
    catch(const exc::EStackOverflow &e){
        cout << e.what() << endl;
    }// помещаем элемент в стек
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
    }// помещаем элемент в стек
}

template <typename T>
inline int Stack<T>::getStackSize() const
{
    return size;
}

