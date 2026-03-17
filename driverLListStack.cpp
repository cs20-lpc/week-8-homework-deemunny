#include <iostream>
#include "ArrayStack.hpp"
#include "LinkedListStack.hpp"
#include "StackFactory.hpp"

using namespace std;

template <typename T>
void testRotate(Stack<T>* s)
{
    try {
        cout << "Testing rotate RIGHT..." << endl;
        s->rotate(Stack<T>::RIGHT);
        s->print();
        cout << endl;

        cout << "Testing rotate LEFT..." << endl;
        s->rotate(Stack<T>::LEFT);
        s->print();
        cout << endl;
    }
    catch (string e) {
        cout << "Exception: " << e << endl;
    }
}

int main()
{

    Stack<int>* stack1 = StackFactory<int>::GetStack();
    
        try {

        cout << "Adding values to stack:" << endl;

        for (int i = 1; i <= 5; i++) {
            stack1->push(i);
            stack1->print();
            cout << endl;
        }

        cout << "Peek: " << stack1->peek() << endl;
        cout << "Length: " << stack1->getLength() << endl;

        testRotate(stack1);

        cout << "Pop:" << endl;
        stack1->pop();
        stack1->print();
        cout << endl;

        cout << "Clearing stack1..." << endl;
        stack1->clear();

        cout << "Is empty? " << boolalpha << stack1->isEmpty() << endl;

        cout << "Negative tests:" << endl;

        try {
            cout << "Pop when empty:" << endl;
            stack1->pop();
        }
        catch (string e) {
            cout << "Caught exception: " << e << endl;
        }

        try {
            cout << "Peek when empty:" << endl;
            cout << stack1->peek() << endl;
        }
        catch (string e) {
            cout << "Caught exception: " << e << endl;
        }

    }
    catch (string e) {
        cout << "Unhandled exception: " << e << endl;
    }
    
    delete stack1;

    return 0;
}