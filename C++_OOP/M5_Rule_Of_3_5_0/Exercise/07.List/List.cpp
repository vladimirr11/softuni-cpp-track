#include "List.h"

#include <sstream>
#include <stdexcept>

List::Node::Node(int value, Node* prev, Node* next) :
    value(value), prev(prev), next(next) {}

int List::Node::getValue() const {
    return value;
}

void List::Node::setValue(int value) {
    this->value = value;
}

List::Node* List::Node::getNext() const {
    return next;
}

void List::Node::setNext(Node* next) {
    this->next = next;
}

List::Node* List::Node::getPrev() const {
    return prev;
}

void List::Node::setPrev(Node* prev) {
    this->prev = prev;
}

List::List() : head(nullptr), tail(nullptr), size(0) {}

List::List(const List& other) : head(nullptr), tail(nullptr), size(0) {
    addAll(other);
}

int List::first() const {
    if (this->isEmpty()) {
        throw std::range_error("Cannot get first element of empty list");
    }

    return head->getValue();
}

void List::add(int value) {
    if (isEmpty()) {
        head = new Node(value, nullptr, nullptr);
        tail = head;
    } else {
        Node* newNode = new Node(value, tail, nullptr);
        tail->setNext(newNode);
        tail = newNode;
    }

    size++;
}

void List::addAll(const List& other) {
    for (Node* node = other.head; node != nullptr; node = node->getNext()) {
        add(node->getValue());
    }
}

void List::removeFirst() {
    if (!isEmpty()) {
        Node* oldHeadElement = head;

        if (head != tail) {
            // we have more than 1 node
            head = head->getNext();
            head->setPrev(nullptr);
        } else {
            // we have only 1 node
            head = nullptr;
            tail = nullptr;
        }

        delete oldHeadElement;

        size--;
    }
}

void List::removeAll() {
    while (!isEmpty()){
        removeFirst();
    }
}

size_t List::getSize() const {
    return size;
}

bool List::isEmpty() const {
    return getSize() == 0;
}

List List::getReversed(List l) {
    List reversed;
    for (Node* node = l.tail; node != nullptr; node = node->getPrev()) {
        reversed.add(node->getValue());
    }

    return reversed;
}

std::string List::toString() const {
    std::ostringstream output;

    for (Node* node = head; node != nullptr; node = node->getNext()) {
        output << node->getValue();

        // this check avoids adding a blankspace after the last element
        if (node->getNext() != nullptr) {
            output << " ";
        }
    }

    return output.str();
}

List& List::operator<<(const int& value) {
    add(value);
    return *this;
}

List& List::operator<<(const List& other) {
    addAll(other);
    return *this;
}

List& List::operator=(const List& other) {
    if (this != &other) {
        removeAll();
        addAll(other);
    }

    return *this;
}

List::~List() {
    removeAll();
}
