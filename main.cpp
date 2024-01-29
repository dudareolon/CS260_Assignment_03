// CS260 - Winter 2024 - Assignment 03 - Linked Queue
// Author: Eduarda (Duda) Reolon
// Description: This code uses a linked list to implement the queue abstract data type (First in, First Out data type). 
// This program has methods to enqueue (add a value to the rear of the queue), dequeue (remove a value from the front of the queue),
// and peek (check what is the value at the rear of the queue without deleting it). Lastly, this program also runs tests to make sure
// the classes are correctly functioning.


#include <iostream>

using std::cout;
using std::endl;


// Each 'cell' in the linked list is called a Node. This struct defines what a Node is.
struct Node {
    // each node in a linked list is formed of a slot for the data and a slot for a pointer address that points to the next node in 
    // the linked list
    int data; // the nodes will only store integer values
    Node* next; // the node will store the memory address of the next node in the linked list (this is the pointer) 
};

// This is the queue data struct class that includes the methods for the functionality of the queue 
class Queue {

    // a struct is set by default public while a class is private
    // the values inside this class will be used out of it so I had to make them public
    // I tried to make Queue a struct and not a class but I struggled coding the methods with the struct
    public:
    
    // Create two general pointers under the struct Node that will point to the front and rear locations of the queue
    // Think of them like assigning a value to a variable, but instead you are assigning a value to a pointer
    Node* front;
    Node* rear;


    // This function initializes an empty queue
    void initialize() {

        front = nullptr; // nullptr represents a null pointer value, which means that the pointers does not point to an object
        rear = nullptr;
        // Having both the front and rear pointers pointing to nullptr indicates that the queue is empty, in other words there are no
        // elements in the queue for the front and the rear pointer to point to
    }

    // Checks if the queue is empty
    bool isEmpty() const { // Returns a true or false
        return front == nullptr; // Could have been with the rear pointer as well, since both point to nullptr when queue is empty
    }

    // Function to add a value to the back/rear of the queue
    // Void means this function does not return any value
    void enqueue(int value) {

        // 'Node* addressNewNode' declares a pointer variable that stores the location of the enqueued Node 
        // 
        // Dynamically allocates memory for a new instance of the Node struct:
        // The data will be the value input by the user when calling the function
        // The Node instead of pointing to next, it will point to nullptr, because the added node is currently the last one in the queue
        Node* addressNewNode = new Node{value, nullptr};

        //Check if the queue was empty and the newly added node is the only node in the queue
        if (isEmpty()) { 
            front = rear = addressNewNode; // if there is only one element in the queue, that element is both the front and the rear

        } else { // If the queue was not empty
            // Pointer Assignment:
            // The node that was in the rear position now points at the address of the newly added node
            rear->next = addressNewNode;
            // Rear is updated to be the newly added node
            rear = addressNewNode;
        }

        cout << value << " was added to the queue" << endl;
        cout << endl;
    }

    // This function removes an element from the front of the queue
    // First In, First Out principle (FIFO)
    int dequeue() {
        // Check if queue is empty
        if (isEmpty()) {
            // return error message and 0 in case the queue is empty
            rear == nullptr;
            cout << "Can't remove a value from the queue because the queue is empty" << endl;
            cout << endl;
            return 0;
        }

        int removed_value = front->data; // the data that is on the front of the queue is stored in removed_value
        front = front->next; //updates the front pointer to point to the next node in the queue

        cout << removed_value << " was removed from the queue" << endl ;
        cout << endl;
        return 0;
    }

    // Returns the value at the front of the queue without removing it
    int front_peek() {
        if (isEmpty()) {
            // In case queue is empty, it corrects the rear pointer to make sure it is pointing to nullptr as well 
            rear == nullptr;
            cout << "Can't peek what the front value of the queue is because the queue is empty" << endl;
            cout << endl;
            return 0;
        }
        int front_data = front->data; // return the data of the node the front pointer is pointing to
        // it must be 'data' because that is how the struct Node was set

        cout << "The number at the front of the queue is " << front_data << endl ;
        cout << endl;
        return 0;
    }

    // Returns the value at the rear of the queue without removing it
    int back_peek() {
        if (isEmpty()) {
            rear == nullptr;
            cout << "Can't peek what the rear value of the queue is because the queue is empty" << endl;
            cout << endl;
            return 0;
        }

        int rear_data = rear->data; // return the data of the node the rear pointer is pointing to

        cout << "The number in the end of the queue is " << rear_data << endl ;
        cout << endl;
        return 0;
    }


};


// Testing
int main() {
    Queue myQueue;
    myQueue.initialize();

    myQueue.back_peek();
    myQueue.dequeue();
    myQueue.front_peek();
    myQueue.enqueue(10);
    myQueue.dequeue();
    myQueue.dequeue();

    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.enqueue(5);
    myQueue.enqueue(4);
    myQueue.enqueue(3);
    myQueue.enqueue(0);

    myQueue.front_peek();

    myQueue.dequeue();

    myQueue.back_peek();

    myQueue.front_peek();

    myQueue.dequeue();

    myQueue.front_peek();

    myQueue.dequeue();

    myQueue.front_peek();

    myQueue.back_peek();

    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.back_peek();

    return 0;
}
