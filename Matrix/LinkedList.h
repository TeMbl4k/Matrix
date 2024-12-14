#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>
#include "List.h"

template <typename T>
class LinkedList : public List<T> {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data, Node* next = nullptr) : data(data), next(next) {}
    };
    Node* head = nullptr;
    Node* tail = nullptr;
    size_t count = 0;

public:
    LinkedList() = default;

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_back(const T& value) override {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        ++count;
    }

    void insert(size_t index, const T& value) override {
        if (index > count) throw std::out_of_range("Index out of range");
        if (index == 0) {
            head = new Node(value, head);
            if (!tail) tail = head;
        }
        else {
            Node* prev = head;
            for (size_t i = 0; i < index - 1; ++i) prev = prev->next;
            prev->next = new Node(value, prev->next);
            if (prev == tail) tail = prev->next;
        }
        ++count;
    }

    void erase(size_t index) override {
        if (index >= count) throw std::out_of_range("Index out of range");
        Node* temp = head;
        if (index == 0) {
            head = head->next;
        }
        else {
            Node* prev = head;
            for (size_t i = 0; i < index - 1; ++i) prev = prev->next;
            temp = prev->next;
            prev->next = temp->next;
            if (temp == tail) tail = prev;
        }
        delete temp;
        --count;
    }

    size_t size() const override {
        return count;
    }

    bool empty() const override {
        return count == 0;
    }

    void clear() override {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        count = 0;
    }

    T* begin() override {
        if (!head) return nullptr;
        return &head->data;
    }

    T& operator[](size_t index) override {
        if (index >= count) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = head;
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }



};

#endif // LINKEDLIST_H
