#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define endl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

// Function to add an element to the front of the deque
void pushFront(deque<lli> &dq, lli element, lli maxSize) {
    if ((lli)dq.size() < maxSize) {
        dq.push_front(element);  // Add the element to the front of the deque
        cout << element << " pushed to front" << endl;
    } else {
        cout << "Overflow" << endl;
    }
}

// Function to add an element to the back of the deque
void pushBack(deque<lli> &dq, lli element, lli maxSize) {
    if ((lli)dq.size() < maxSize) {
        dq.push_back(element);  // Add the element to the back of the deque
        cout << element << " pushed to back" << endl;
    } else {
        cout << "Overflow" << endl;
    }
}

// Function to remove an element from the front of the deque
void popFront(deque<lli> &dq) {
    if (!dq.empty()) {
        cout << dq.front() << " popped from front" << endl;
        dq.pop_front();  // Remove the front element from the deque
    } else {
        cout << "Underflow" << endl;
    }
}

// Function to remove an element from the back of the deque
void popBack(deque<lli> &dq) {
    if (!dq.empty()) {
        cout << dq.back() << " popped from back" << endl;
        dq.pop_back();  // Remove the back element from the deque
    } else {
        cout << "Underflow" << endl;
    }
}

// Function to check if the deque is empty
bool isEmpty(const deque<lli> &dq) { return dq.empty(); }

// Function to check if the deque is full
bool isFull(const deque<lli> &dq, lli maxSize) {
    return (lli)dq.size() == maxSize;
}

// Function to get the size of the deque
lli size(const deque<lli> &dq) { return dq.size(); }

// Function to get the front element of the deque
lli front(const deque<lli> &dq) {
    if (!dq.empty()) {
        return dq.front();  // Return the front element of the deque
    } else {
        cout << "Underflow" << endl;
        return -1;
    }
}

// Function to get the back element of the deque
lli back(const deque<lli> &dq) {
    if (!dq.empty()) {
        return dq.back();  // Return the back element of the deque
    } else {
        cout << "Underflow" << endl;
        return -1;
    }
}

// Function to clear the deque
void clear(deque<lli> &dq) {
    dq.clear();  // Remove all elements from the deque
    cout << "Deque cleared" << endl;
}

// Function to print the entire deque
void printDeque(const deque<lli> &dq) {
    if (!dq.empty()) {
        // Print all elements of the deque using iterators
        for (const auto &element : dq) {
            cout << element << " ";
        }
        cout << endl;
    } else {
        cout << "Deque is empty" << endl;
    }
}

int main() {
    /* Deque is a data structure that allows insertion and deletion of elements
    from both the front and the back It performs both LIFO (Last In First Out)
    and FIFO (First In First Out) operations It can be implemented using the
    deque container and the following operations:
    1. Push to front: Add an element to the front of the deque
    2. Push to back: Add an element to the back of the deque
    3. Pop from front: Remove an element from the front of the deque
    4. Pop from back: Remove an element from the back of the deque
    5. Return front: Get the front element of the deque
    6. Return back: Get the back element of the deque
    And all others of stack and queue
    */
    fast();
    lli N;
    cin >> N;  // N denotes the number of operations to perform
    deque<lli> dq;
    lli maxSize = 5;  // Maximum size of the deque
    lli functionID, element;

    // Process function IDs and perform corresponding deque operations
    while (N--) {
        cin >> functionID;
        switch (functionID) {
            case 1:  // Push to front
                cin >> element;
                pushFront(dq, element, maxSize);
                break;
            case 2:  // Push to back
                cin >> element;
                pushBack(dq, element, maxSize);
                break;
            case 3:  // Pop from front
                popFront(dq);
                break;
            case 4:  // Pop from back
                popBack(dq);
                break;
            case 5:  // Check if the deque is empty
                cout << (isEmpty(dq) ? "True" : "False") << endl;
                break;
            case 6:  // Check if the deque is full
                cout << (isFull(dq, maxSize) ? "Yes" : "No") << endl;
                break;
            case 7:  // Get the size of the deque
                cout << size(dq) << endl;
                break;
            case 8:  // Get the front element
                cout << front(dq) << endl;
                break;
            case 9:  // Get the back element
                cout << back(dq) << endl;
                break;
            case 10:  // Clear the deque
                clear(dq);
                break;
            case 11:  // Print the entire deque
                printDeque(dq);
                break;
            default:  // Invalid function ID
                cout << "Invalid function ID" << endl;
                break;
        }
    }
    return 0;
}
