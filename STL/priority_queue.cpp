#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define endl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

// Function to enqueue an element into the priority queue
void enqueue(priority_queue<lli, vector<lli>, greater<lli>> &pqAsc,
             priority_queue<lli> &pqDesc, lli element, lli maxSize) {
    if ((lli)pqAsc.size() < maxSize) {
        pqAsc.push(element);   // Add the element to ascending order queue
        pqDesc.push(element);  // Add the element to descending order queue
        cout << element << " enqueued" << endl;
    } else {
        cout << "Overflow" << endl;
    }
}

// Function to dequeue an element from the ascending priority queue
void dequeueAsc(priority_queue<lli, vector<lli>, greater<lli>> &pqAsc) {
    if (!pqAsc.empty()) {
        cout << pqAsc.top() << " dequeued from ascending queue" << endl;
        pqAsc.pop();  // Remove the top element from ascending order queue
    } else {
        cout << "Underflow" << endl;
    }
}

// Function to dequeue an element from the descending priority queue
void dequeueDesc(priority_queue<lli> &pqDesc) {
    if (!pqDesc.empty()) {
        cout << pqDesc.top() << " dequeued from descending queue" << endl;
        pqDesc.pop();  // Remove the top element from descending order queue
    } else {
        cout << "Underflow" << endl;
    }
}

// Function to get the front (top) element of the ascending queue
lli frontAsc(const priority_queue<lli, vector<lli>, greater<lli>> &pqAsc) {
    if (!pqAsc.empty()) {
        return pqAsc.top();  // Return the top element of ascending queue
    } else {
        cout << "Underflow" << endl;
        return -1;
    }
}

// Function to get the front (top) element of the descending queue
lli frontDesc(const priority_queue<lli> &pqDesc) {
    if (!pqDesc.empty()) {
        return pqDesc.top();  // Return the top element of descending queue
    } else {
        cout << "Underflow" << endl;
        return -1;
    }
}

// Function to get the size of the priority queues
lli size(const priority_queue<lli, vector<lli>, greater<lli>> &pqAsc) {
    return pqAsc.size();  // Return the size of the ascending queue
}

// Function to check if the priority queues are empty
bool isEmpty(const priority_queue<lli, vector<lli>, greater<lli>> &pqAsc) {
    return pqAsc.empty();  // Return true if the ascending queue is empty
}

// Function to check if the priority queues are full
bool isFull(const priority_queue<lli, vector<lli>, greater<lli>> &pqAsc,
            lli maxSize) {
    return (lli)pqAsc.size() == maxSize;  // Return true if the queue is full
}

// Function to print elements of the ascending priority queue
void printAsc(priority_queue<lli, vector<lli>, greater<lli>> pqAsc) {
    if (pqAsc.empty()) {
        cout << "Ascending queue is empty" << endl;
        return;
    }
    cout << "Ascending queue: ";
    while (!pqAsc.empty()) {
        cout << pqAsc.top() << " ";
        pqAsc.pop();
    }
    cout << endl;
}

// Function to print elements of the descending priority queue
void printDesc(priority_queue<lli> pqDesc) {
    if (pqDesc.empty()) {
        cout << "Descending queue is empty" << endl;
        return;
    }
    cout << "Descending queue: ";
    while (!pqDesc.empty()) {
        cout << pqDesc.top() << " ";
        pqDesc.pop();
    }
    cout << endl;
}

int main() {
    /* Priority Queue is a data structure that orders elements based on
    priority. It supports two types:
    1. Ascending order queue (min-heap): The smallest element is given highest
       priority.
    2. Descending order queue (max-heap): The largest element is given highest
       priority.
    Operations include enqueue, dequeue, front, size, isEmpty, isFull, and
    printing.
    */
    fast();
    lli N;
    cin >> N;  // N denotes the number of operations to perform
    priority_queue<lli, vector<lli>, greater<lli>> pqAsc;  // Min-heap
    priority_queue<lli> pqDesc;                            // Max-heap
    lli maxSize = 5;  // Maximum size of the priority queue
    lli functionID, element;

    // Process function IDs and perform corresponding priority queue operations
    while (N--) {
        cin >> functionID;
        switch (functionID) {
            case 1:  // Enqueue operation
                cin >> element;
                enqueue(pqAsc, pqDesc, element, maxSize);
                break;
            case 2:  // Dequeue from ascending order queue
                dequeueAsc(pqAsc);
                break;
            case 3:  // Dequeue from descending order queue
                dequeueDesc(pqDesc);
                break;
            case 4:  // Check if the priority queues are empty
                cout << (isEmpty(pqAsc) ? "True" : "False") << endl;
                break;
            case 5:  // Check if the priority queues are full
                cout << (isFull(pqAsc, maxSize) ? "Yes" : "No") << endl;
                break;
            case 6:  // Get the size of the priority queues
                cout << size(pqAsc) << endl;
                break;
            case 7:  // Get the front element of the ascending queue
                cout << frontAsc(pqAsc) << endl;
                break;
            case 8:  // Get the front element of the descending queue
                cout << frontDesc(pqDesc) << endl;
                break;
            case 9:  // Print the ascending queue
                printAsc(pqAsc);
                break;
            case 10:  // Print the descending queue
                printDesc(pqDesc);
                break;
            default:  // Invalid function ID
                cout << "Invalid function ID" << endl;
                break;
        }
    }
    return 0;
}
