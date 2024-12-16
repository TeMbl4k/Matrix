#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdexcept>
#include "List.h"

template <typename T>
class ArrayList : public List<T> {
private:
    T* data = nullptr;
    size_t count = 0;
    size_t capacity = 0;

    void resize(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < count; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    ArrayList() : capacity(4) {
        data = new T[capacity];
    }

    ~ArrayList() {
        delete[] data;
    }

    void push_back(const T& value) override {
        if (count >= capacity) resize(capacity * 2);
        data[count++] = value;
    }

    void insert(size_t index, const T& value) override {
        if (index > count) throw std::out_of_range("Index out of range");
        if (count >= capacity) resize(capacity * 2);
        for (size_t i = count; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++count;
    }

    void erase(size_t index) override {
        if (index >= count) throw std::out_of_range("Index out of range");
        for (size_t i = index; i < count - 1; ++i) {
            data[i] = data[i + 1];
        }
        --count;
    }

    size_t size() const override {
        return count;
    }

    bool empty() const override {
        return count == 0;
    }

    void clear() override {
        delete[] data;
        data = new T[1];
        count = 0;
        capacity = 1;
    }


    T& operator[](size_t index) override {
        if (index >= count) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

};

#endif // ARRAYLIST_H
