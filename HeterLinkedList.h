#ifndef __Hater__Linked__List__H__
#define __Hater__Linked__List__H__

template <class T>
class Node{
private:
    T value;
    Node *next;
public:
    Node(T v);
    
};

template <class T>
class LinkedList{
private:
    Node<int> *head;
public:
    LinkedList(Node<T> *head);
};

#endif