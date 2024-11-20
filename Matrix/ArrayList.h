#ifndef LAB3_ARRAYLIST_H
#define LAB3_ARRAYLIST_H

#include <iostream>
#include "List.h"
#include "Iterator.h"
#include "Figure.h"

template <typename T>
class ArrayList : public List<T> {

    T* Data;
    size_t Capacity = 10;  //default capacity
    size_t Size;

public:
    using iterator = Iterator<T>;
    iterator begin() { return Iterator(&Data[0]); }
    iterator end() { return Iterator(&Data[Size]); }

    ArrayList() : Data(nullptr), Size(0) {
        Data = new T[Capacity];
    };

    ArrayList(size_t len) : Data(nullptr), Capacity(len * 2), Size(len) {
        Data = new T[Capacity];
        std::fill(begin(), end(), 0);
        Size = 0;
    }

    T& operator[](size_t pos) {
        //how to check is pos positive? cond size_t >= 0 is always true
        try {
            if (pos >= 0 && pos < Size) {
                return Data[pos];
            }
            throw std::out_of_range("Index is out of range");
        }
        catch (std::out_of_range& err) {
            std::cerr << err.what() << std::endl;
        }
        catch (std::exception& err) {
            std::cerr << err.what() << std::endl;
        }
        catch (...) {
            std::cerr << "Something went wrong in [] operator\n";
        }
    }

    ~ArrayList() {
        clear();
    }

    constexpr void push_back(const T& data) override {
        if (Size >= Capacity) {
            reserve(Size * 2);
        }
        Data[Size] = data;
        Size++;
    }

    constexpr void insert(size_t position, const T& data) override { //fix: position could be iterator
        if (position >= 0 && position < Size) {
            if (Size >= Capacity) {
                reserve(Size * 2);
            }
            for (size_t i = Size; i > position; i--) {
                Data[i] = Data[i - 1];
            }

            Data[position] = data;
            Size++;
        }
    }

    void insert(iterator position, const T& data) {
        size_t pos = std::distance(begin(), position);
        if (pos >= 0 && pos < Size) {
            if (Size >= Capacity) {
                reserve(Size * 2);
            }
            for (size_t i = Size; i > pos; i--) {
                Data[i] = Data[i - 1];
            }

            Data[pos] = data;
            Size++;
        }
    }

    constexpr void erase(size_t position) override {  //it should work with iterators
        if (position >= 0 && position < Size) {
            for (size_t i = position; i < Size; i++) {
                Data[i] = Data[i + 1];
            }
            Size--;
        }
    }

    constexpr void erase(iterator position) {
        size_t pos = std::distance(begin(), position);
        if (pos >= 0 && pos < Size) {
            for (size_t i = pos; i < Size; i++) {
                Data[i] = Data[i + 1];
            }
            Size--;
        }
    }


    constexpr size_t size() override {
        return Size;
    }

    constexpr void reserve(size_t new_cap) {
        T* NewData = new T[new_cap];
        for (size_t i = 0; i < Size; ++i) {
            NewData[i] = Data[i];
        }
        delete[] Data;
        Capacity = new_cap;
        Data = NewData;

    }

    [[nodiscard]] constexpr bool empty() const {
        return (Size == 0);
    }

    constexpr void clear() noexcept {
        Size = 0;
        delete[] Data;
    }

    void print() {
        for (int i = 0; i < Size; i++) {
            std::cout << Data[i] << std::endl;
        }
    }
};


#endif //LAB3_ARRAYLIST_H