#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    struct Node {                                                   //node structure for linked list implementation
        T data;
        Node* next;
    };
    Node* frontPtr;     //point to front
    Node* rearPtr;      //point to rear
    int count;

public:
    Queue();                                                //constructor
    ~Queue();                                               //destructor
    void push(T value);
    void pop();
    T front();
    int size();
    bool empty();
    void move_to_rear();
};
                                                    //recursive linear seadrch function
template <typename T>
int recursiveLinearSearchLast(T arr[], int size, T target, int index = -1, int lastFound = -1);

struct ListNode {                                   //linked list node structure for insertion sort
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void insertionSort(ListNode*& head);

#endif