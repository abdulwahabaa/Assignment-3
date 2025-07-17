#include "queue.h"
#include <iostream>
using namespace std;

template <typename T>       //queue constructor
Queue<T>::Queue() : frontPtr(nullptr), rearPtr(nullptr), count(0) {}

template <typename T>       //queue destructor
Queue<T>::~Queue() {
    while (!empty()) {
        pop();
    }
}

template <typename T>       //push operation
void Queue<T>::push(T value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (empty()) {
        frontPtr = rearPtr = newNode;
    }
    else {
        rearPtr->next = newNode;
        rearPtr = newNode;
    }
    count++;
}

template <typename T>       //pop operation
void Queue<T>::pop() {
    if (empty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    Node* temp = frontPtr;
    frontPtr = frontPtr->next;
    delete temp;
    count--;
    if (empty()) {
        rearPtr = nullptr;
    }
}

template <typename T>       //front operation
T Queue<T>::front() {
    if (empty()) {
        cout << "Queue is empty!" << endl;
        return T();
    }
    return frontPtr->data;
}

template <typename T>       //size operation
int Queue<T>::size() {
    return count;
}

template <typename T>       //empty operation
bool Queue<T>::empty() {
    return count == 0;
}

template <typename T>       //move to rear operation
void Queue<T>::move_to_rear() {
    if (size() <= 1) return;
    T frontValue = front();
    pop();
    push(frontValue);
}

template <typename T>       //recursive linear search implemenatation
int recursiveLinearSearchLast(T arr[], int size, T target, int index, int lastFound) {
    if (index == size - 1) {
        return lastFound;
    }

    index++;                    //move to next index
    if (arr[index] == target) {
        lastFound = index;
    }

    return recursiveLinearSearchLast(arr, size, target, index, lastFound);
}

void insertionSort(ListNode*& head) {       //builds sorted list by inserting each element in correct position
    if (head == nullptr || head->next == nullptr) return;

    ListNode* sorted = nullptr;             //initialize empty sorted list
    ListNode* current = head;               //start with the first
       
    while (current != nullptr) {
        ListNode* next = current->next;     //next node

        if (sorted == nullptr || sorted->val >= current->val) {
            current->next = sorted;         //insert at the beginning
            sorted = current;
        }
        else {
            ListNode* temp = sorted;        //find correct position
            while (temp->next != nullptr && temp->next->val < current->val) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;                     //next node
    }

    head = sorted;                          //update head
}

template class Queue<int>;
template int recursiveLinearSearchLast(int arr[], int size, int target, int index, int lastFound);