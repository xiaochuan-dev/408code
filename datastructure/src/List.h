#pragma once

namespace datastructure
{

template <typename T = int>
struct ListNode
{
    T data;
    ListNode<T> *next;
    ListNode() = delete;
    ListNode(T);
    ListNode(T, ListNode<T> *);
    ~ListNode() = default;
};

template <typename T = int>
struct List
{
    /**
     * 注意这个head头节点不存数据
     */
    ListNode<T> *head;

    List();
    ~List();

    List &add(T);
    T remove(ListNode<T> *);
};

template <typename T>
ListNode<T>::ListNode(T d) : data{d}, next{nullptr}
{
}

template <typename T>
ListNode<T>::ListNode(T d, ListNode<T> *n) : data{d}, next{n}
{
}

template <typename T>
List<T>::List()
{
    this->head = new ListNode<T>(0);
}

template <typename T>
List<T>::~List()
{
    ListNode<T> *c = this->head;
    while (c != nullptr)
    {
        ListNode<T> *temp = c;
        c = c->next;
        delete temp;
    }
}

template <typename T>
List<T> &List<T>::add(T data)
{
    ListNode<T> *newNode = new ListNode<T>(data);
    ListNode<T> *c = this->head;
    while (c->next != nullptr)
    {
        c = c->next;
    }
    c->next = newNode;
    return *this;
}

template <typename T>
T List<T>::remove(ListNode<T> *removedNode)
{
    ListNode<T> *c = this->head;
    while (c->next != removedNode)
    {
        c = c->next;
    }

    c->next = c->next->next;
    removedNode->next = nullptr;
    T data = removedNode->data;
    delete removedNode;
    return data;
}

} // namespace datastructure
