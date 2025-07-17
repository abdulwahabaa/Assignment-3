#include "queue.h"
#include <iostream>
using namespace std;

void displayQueue(Queue<int>& q) {          //displays all elements
    cout << "Queue: ";
    int size = q.size();
    for (int i = 0; i < size; i++) {
        cout << q.front() << " ";           //print front
        q.move_to_rear();                   //move to rear
    }
    cout << endl;
}

void testQueue() {                          //tests queue operations
    Queue<int> myQueue;
    for (int i = 1; i <= 10; i++) {
        myQueue.push(i * 10);
    }

    displayQueue(myQueue);

    cout << "Moving from front to rear..." << endl;
    myQueue.move_to_rear();
    displayQueue(myQueue);
}

void testLinearSearch() {                   //tests recursive linear search
    int arr[] = { 2, 5, 3, 7, 5, 9, 5, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    int lastIndex = recursiveLinearSearchLast(arr, size, target);
    cout << "Last occurrence of " << target << " is at index: " << lastIndex << endl;
}

void testInsertionSort() {                  //tests insertion sort on linked lists
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    cout << "Before: ";
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    insertionSort(head);

    cout << "After: ";
    temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    while (head) {                             //cleans up memory
        ListNode* toDelete = head;
        head = head->next;
        delete toDelete;
    }
}

int main() {                                    //runs all functions
    cout << " Test Queue " << endl;
    testQueue();

    cout << "\n Test Recursive Linear Search " << endl;
    testLinearSearch();

    cout << "\n Test Insertion Sort on Linked List " << endl;
    testInsertionSort();

    return 0;
}