#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
public:
    virtual void push_back(const T& value) = 0;               // Добавление элемента в конец
    virtual void insert(size_t index, const T& value) = 0;    // Добавление элемента в позицию n
    virtual void erase(size_t index) = 0;                     // Удаление элемента из позиции n
    virtual size_t size() const = 0;                          // Получение количества элементов
    virtual ~List() = default;
    virtual bool empty() const = 0;
    virtual void clear() = 0;
    virtual T* begin() = 0;
    virtual T& operator[](size_t index) = 0;


};

#endif // LIST_H
