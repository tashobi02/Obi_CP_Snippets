#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define endl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
// Function to push an element into the stack
void push(stack<lli> &st, lli element, lli maxSize) {
    if ((lli)st.size() < maxSize) {
        st.push(element);  // Push the element into the stack
        cout << element << " pushed" << endl;
    } else {
        cout << "Overflow" << endl;
    }
}
// Function to pop an element from the stack
void pop(stack<lli> &st) {
    if (!st.empty()) {
        cout << st.top() << " popped" << endl;
        st.pop();  // Pop the top element from the stack
    } else {
        cout << "Underflow" << endl;
    }
}
// Function to check if the stack is empty
bool isEmpty(const stack<lli> &st) {
    return st.empty();  // Return true if the stack is empty
}
// Function to check if the stack is full
bool isFull(const stack<lli> &st, lli maxSize) {
    return (lli)st.size() == maxSize;  // Return true if the stack is full
}
// Function to get the current size of the stack
lli size(const stack<lli> &st) {
    return st.size();  // Return the size of the stack
}
// Function to get the top element of the stack
lli top(const stack<lli> &st) {
    if (!st.empty()) {
        return st.top();  // Return the top element of the stack
    } else {
        cout << "Underflow" << endl;
        return -1;
    }
}
int main() {
    /* Stack is data structure that follows the Last In First Out (LIFO) order
    It can be implemented using the stack container and the following
    operations:
    1. Push: Add an element to the top of the stack
    2. Pop: Remove the top element from the stack
    3. isEmpty: Check if the stack is empty
    4. isFull: Check if the stack is full
    5. size: Get the current size of the stack
    6. top: Get the top element of the stack
    */
    fast();
    lli N;
    cin >> N;  // N denotes the number of operations to perform
    stack<lli> st;
    lli maxSize = 5;  // Maximum size of the stack
    lli functionID, element;
    // Process function IDs and perform corresponding stack operations
    while (N--) {
        cin >> functionID;
        switch (functionID) {
            case 1:  // Push operation
                cin >> element;
                push(st, element, maxSize);
                break;
            case 2:  // Pop operation
                pop(st);
                break;
            case 3:  // Check if the stack is empty
                cout << (isEmpty(st) ? "True" : "False") << endl;
                break;
            case 4:  // Check if the stack is full
                cout << (isFull(st, maxSize) ? "Yes" : "No") << endl;
                break;
            case 5:  // Get the size of the stack
                cout << size(st) << endl;
                break;
            case 6:  // Get the top element of the stack
                cout << top(st) << endl;
                break;
            default:  // Invalid function ID
                cout << "Invalid function ID" << endl;
                break;
        }
    }
    return 0;
}
