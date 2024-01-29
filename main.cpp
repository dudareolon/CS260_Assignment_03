// CS260 - Winter 2024 - Assignment 03 - Linked Queue
// Author: Eduarda (Duda) Reolon
// Description: This code uses a linked list to implement the queue abstract data type (First in, First Out data type). 
// This program has methods to enqueue (add a value to the rear of the queue), dequeue (remove a value from the front of the queue),
// and peek (check what is the value at the rear of the queue without deleting it). Lastly, this program also runs tests to make sure
// the class is correctly functioning.


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
    Queue Testing_Queue; // create a queue from the class
    Testing_Queue.initialize(); //must initialize queue before running the functions

    // Test 1
    // Try to run dequeue, back and front peek when the queue is empty, no nodes have been added yet
    Testing_Queue.back_peek();
    Testing_Queue.dequeue();
    Testing_Queue.front_peek();
    // Output:
    // Can't peek what the rear value of the queue is because the queue is empty
    // Can't remove a value from the queue because the queue is empty
    // Can't peek what the front value of the queue is because the queue is empty
    // Correct

    // Test 2
    // Add the first variable to the queue (so there is only one node in the queue) and then peek what are the front and rear variables
    Testing_Queue.enqueue(10);
    Testing_Queue.front_peek();
    Testing_Queue.back_peek();
    // Output:
    // 10 was added to the queue
    // The number at the front of the queue is 10
    // The number in the end of the queue is 10
    // Correct

    // Test 3 
    // Queue has only one variable, but attempt to remove two variables out of the queue
    Testing_Queue.dequeue();
    Testing_Queue.dequeue();
    // Output:
    // 10 was removed from the queue
    // Can't remove a value from the queue because the queue is empty
    // Correct

    // Test 4
    // Add several nodes to the queue and check if the front and rear pointers are pointing to the correct node
    Testing_Queue.enqueue(20);
    Testing_Queue.enqueue(30);
    Testing_Queue.enqueue(5);
    Testing_Queue.enqueue(4);
    Testing_Queue.enqueue(3);
    Testing_Queue.enqueue(0);
    Testing_Queue.front_peek();
    Testing_Queue.back_peek();
    // Front should be pointing to the node 20 and rear should be pointing to 0
    // Output:
    // The number at the front of the queue is 20
    // The number in the end of the queue is 0
    // Correct

    // Test 4
    // Check if the dequeue function is following the FIFO principle, and removing the node on the front which would be 20  
    Testing_Queue.dequeue();
    // Output:
    // 20 was removed from the queue
    // Correct

    // Test 5
    // Check if after a variable was removed that the front pointer would adjust and if the rear pointer would remain pointing to the last variable in
    Testing_Queue.front_peek();
    Testing_Queue.back_peek();
    // Output:
    // The number at the front of the queue is 30 (updated to the variable added right after 20 was added)
    // The number in the end of the queue is 0 (remained the same)
    // Correct

    // Test 6
    // Remove more variables than there are in the queue and then try to check for the value the rear pointer is indicating
    // Check if rear pointer is updating when the queue gets empty
    Testing_Queue.dequeue();
    Testing_Queue.dequeue();
    Testing_Queue.dequeue();
    Testing_Queue.dequeue();
    Testing_Queue.dequeue();
    Testing_Queue.dequeue();
    Testing_Queue.dequeue();
    Testing_Queue.back_peek();
    // Output:
    // 0 was removed from the queue (last number from the queue is removed)
    // Can't remove a value from the queue because the queue is empty (error message)
    // Can't remove a value from the queue because the queue is empty (error message)
    // Can't peek what the rear value of the queue is because the queue is empty (error message)
    // Correct

    return 0;
}
