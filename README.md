# CS260_Assignment_03
Linked Queue
--------------------------------------------------------------------------------------------------------------------------------------------------------------------


Important Observation: I was only able to get Git correctly installed on my computer withe the help of my classmates and that was after I was already done with a properly working code. So for this assignment again I only have one commit to the code, and I transfered my README file to this github repository. But for assignment 04 and on I will be able to make several commits to my code so that you can properly see my thought process when implementing my designs. 

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

The goal of this assignment is to create a program that uses a linked-list to store values in a queue. The queue must have the ability to:
- Enqueue: appropriately add a value to the back of the queue as an appropriate element;
- Dequeue: appropriately remove an element from the front of the queue and return its value;
- Peek: a method to peek the front and/or rear value of the queue without removing it. 

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

Design:

Understand what is a linked list:

![image](https://github.com/dudareolon/CS260_Assignment_03/assets/102680672/8e478dee-5f6a-469e-9c47-46803c818872)

A linked list is formed of several Nodes, each Node stores a data and the address that points to the next node. 
For my program I will create a struct Node. This way a Node will be a "data type" and all Nodes will be under the same structure making it easier to work with them.

To implement the queue I could have done it a class or a struct. A struct would set everything to public, while a class is private by defafult. I choose to make the queue a class, because it is easier for me to work with functions/methods under a class. 

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

The parts of the code where I meet each one of the requirements are the following:

- Requirement 1: uses a linked-list to store values in the queue:

Defines what a Node of the linked-list will be

  ![image](https://github.com/dudareolon/CS260_Assignment_03/assets/102680672/3b9ca200-d2d9-4cd6-97ba-b85a14a1fd04)

Then makes the rear and front pointers of the queue to be nodes and initializes the queue to be empty

  ![image](https://github.com/dudareolon/CS260_Assignment_03/assets/102680672/c80e24b7-dd16-4a9d-a041-1e598c7dfd8e)




- Requirement 2:

- Requirement 3:

- Requirement 4:



