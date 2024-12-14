#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
public:
    virtual void push_back(const T& value) = 0;               // ���������� �������� � �����
    virtual void insert(size_t index, const T& value) = 0;    // ���������� �������� � ������� n
    virtual void erase(size_t index) = 0;                     // �������� �������� �� ������� n
    virtual size_t size() const = 0;                          // ��������� ���������� ���������
    virtual ~List() = default;
    virtual bool empty() const = 0;
    virtual void clear() = 0;
    virtual T* begin() = 0;
    virtual T& operator[](size_t index) = 0;


};

#endif // LIST_H
