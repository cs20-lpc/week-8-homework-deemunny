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
        Node<T>* delMe = top;
        top = delMe->next;
        delete delMe;
        --this->length;
    }
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    // TO DO: Implement copy 
    Node<T>* curr = copyObj.top;
    while (curr) {
        push(curr->data);
        curr = curr->next;
    }

    Node<T>* prev = nullptr;
    Node<T>* next = nullptr;
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
    Node<T>* delMe = top;
    top = top->next;
    delete delMe;
    --this->length;
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    // TO DO: Implement push
    Node<T>* newNode = new Node(elem, top);
    top = newNode;
    ++this->length;
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TO DO: Implement rotate
    if (isEmpty() || !top->next) {
        cout << "Stack is empty, nothing to rotate.";
        return;
    }
    if (dir == this->RIGHT) { // move last to first
        Node<T>* curr = top;
        
        while (curr->next->next) { // get to antepenultimate node (new word. fun.)
            curr = curr->next;
        }

        Node<T>* last = curr->next;
        curr->next-> = nullptr;
        last->next = top;
        top = last;
    }
    if (dir == this->LEFT) {  // move first to last
        Node<T>* first = top;
        top = top->next;

        Node<T>* curr = top;
        while (curr->next) {  // find last node
            curr = curr->next;
        }

        curr->next = first;
        first->next = nullptr;
    }
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
