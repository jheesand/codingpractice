template <class T>
Node<T>::Node() : next_(NULL) {
}

template <class T>
Node<T>::Node(T value) : value_(value), next_(NULL) {
}

template <class T>
Node<T>::~Node() {
}


template <class T>
void Node<T>::setValue(T value) {
    value_ = value;
}

template <class T>
void Node<T>::setNextNode(Node<T>* next) {
    next_ = next;
}

template <class T>
T Node<T>::getValue() {
    return value_;
}

template <class T>
Node<T>* Node<T>::getNextNode() {
    return next_;
}