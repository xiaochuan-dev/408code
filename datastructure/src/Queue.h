#pragma once

namespace datastructure
{
/**
 * 循环队列
 */
template <typename T = int>
struct Queue
{
    int size;
    /**
     * 这里为了和书上操作差不多使用指针不是std::vector
     */
    T* data;

    int front;
    int rear;

    Queue() = delete;
    Queue(int);
    ~Queue();
    T getFront();
    T getRear();
    Queue<T>& enQueue(T);
    T deQueue();
    bool empty();
    bool full();
};

template <typename T>
Queue<T>::Queue(int size)
{
    this->size = size;
    this->data = new T[size];
    this->front = 0;
    this->rear = 0;
}

template <typename T>
Queue<T>::~Queue()
{
    delete[] this->data;
}

/**
 * 对头元素就是front指针的元素
 */
template <typename T>
T Queue<T>::getFront()
{
    return *(this->data + this->front);
}
/**
 * 队尾指针指向队尾的下一个index
 */
template <typename T>
T Queue<T>::getRear()
{
    int index  = this->rear == 0 ? this->size - 1 : this->rear - 1;
    return this->data[index];
}

template <typename T>
Queue<T>& Queue<T>::enQueue(T data)
{
    this->data[this->rear] = data;
    this->rear = (this->rear + 1) % this->size; 
    return *this;
}

template <typename T>
T Queue<T>::deQueue()
{
    T temp = this->data[this->front];
    this->front = (this->front + 1) % this->size;
    return temp;
}

template <typename T>
bool Queue<T>::empty()
{
    return this->rear == this->front;
}

template <typename T>
bool Queue<T>::full()
{
    return (this->rear + 1) % this->size == this->front;
}
}