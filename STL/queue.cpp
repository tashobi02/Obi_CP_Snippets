#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define endl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

// Function to enqueue an element into the queue
void enqueue(queue<lli> &q, lli element, lli maxSize) {
    if ((lli)q.size() < maxSize) {
        q.push(element);  // Add the element to the queue
        cout << element << " enqueued" << endl;
    } else {
        cout << "Overflow" << endl;
    }
}

// Function to dequeue an element from the queue
void dequeue(queue<lli> &q) {
    if (!q.empty()) {
        cout << q.front() << " dequeued" << endl;
        q.pop();  // Remove the front element from the queue
    } else {
        cout << "Underflow" << endl;
    }
}

// Function to check if the queue is empty
bool isEmpty(const queue<lli> &q) {
    return q.empty();  // Return true if the queue is empty
}

// Function to check if the queue is full
bool isFull(const queue<lli> &q, lli maxSize) {
    return (lli)q.size() == maxSize;  // Return true if the queue is full
}

// Function to get the current size of the queue
lli size(const queue<lli> &q) {
    return q.size();  // Return the size of the queue
}

// Function to get the front element of the queue
lli front(const queue<lli> &q) {
    if (!q.empty()) {
        return q.front();  // Return the front element of the queue
    } else {
        cout << "Underflow" << endl;
        return -1;
    }
}

// Function to get the rear element of the queue
lli rear(const queue<lli> &q) {
    if (!q.empty()) {
        return q.back();  // Return the rear element of the queue
    } else {
        cout << "Underflow" << endl;
        return -1;
    }
}

int main() {
    /* Queue is a data structure that follows the First In First Out (FIFO)
    order It is used to store elements in a linear order and perform operations
    like enqueue (insertion), dequeue (deletion), front (get the front element),
    rear (get the rear element), isEmpty (check if the queue is empty),
    isFull (check if the queue is full), and size (get the current size of the
    queue).
    */
    fast();
    lli N;
    cin >> N;  // N denotes the number of operations to perform
    queue<lli> q;
    lli maxSize = 5;  // Maximum size of the queue
    lli functionID, element;

    // Process function IDs and perform corresponding queue operations
    while (N--) {
        cin >> functionID;
        switch (functionID) {
            case 1:  // Enqueue operation
                cin >> element;
                enqueue(q, element, maxSize);
                break;
            case 2:  // Dequeue operation
                dequeue(q);
                break;
            case 3:  // Check if the queue is empty
                cout << (isEmpty(q) ? "True" : "False") << endl;
                break;
            case 4:  // Check if the queue is full
                cout << (isFull(q, maxSize) ? "Yes" : "No") << endl;
                break;
            case 5:  // Get the size of the queue
                cout << size(q) << endl;
                break;
            case 6:  // Get the front element of the queue
                cout << front(q) << endl;
                break;
            case 7:  // Get the rear element of the queue
                cout << rear(q) << endl;
                break;
            default:  // Invalid function ID
                cout << "Invalid function ID" << endl;
                break;
        }
    }
    return 0;
}
