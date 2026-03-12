template <typename T>
LinkedListStack<T>::LinkedListStack()
{ }

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {
    // TO DO: Delete all the elements in the stack
    while (top) {
        Node* delMe = top;
        top = delMe->next;
        delete delMe;
        --this->length;
    }
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    // TO DO: Implement copy 
    Node* curr = copyObj.top;
    while (curr) {
        push(curr->data);
        curr = curr->next;
    }

    Node* prev = nullptr;
    Node* next = nullptr;
    curr = top;
    
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    top = prev;
}

template <typename T>
int LinkedListStack<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return this->length == 0;
}

// consider a T& version to allow updating via peek?
// consider const T& to be able to return by ref?
template <typename T>
T LinkedListStack<T>::peek() const {
    // TO DO: implement peek
    return top->data;
}

template <typename T>
void LinkedListStack<T>::pop() {
    // TO DO: Implement pop
    if (isEmpty()) {
        cout << "Nothing to pop. Stack is empty." << endl;
        return;
    }
    cout << "Popping data " << top->data << endl;
    Node* delMe = top;
    top = top->next;
    delete delMe;
    --this->length;
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    // TO DO: Implement push
    Node* newNode = new Node(elem, top);
    top = newNode;
    ++this->length;
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TO DO: Implement rotate

}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    }
    else {
        Node<T> *curr = top;
        while (curr != nullptr){
            cout <<  curr->data  << "\t";
            curr = curr->next;
        }
    }

    cout << endl;
}
