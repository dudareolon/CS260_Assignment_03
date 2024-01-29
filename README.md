# CS260_Assignment_03
Linked Queue
--------------------------------------------------------------------------------------------------------------------------------------------------------------------


Important Observation: I was only able to get Git correctly installed on my computer with the help of my classmates and that was after I was already done with a properly working code. So for this assignment again I only have one commit to the code, and I transferred my README file to this GitHub repository. But for assignment 04 and on I will be able to make several commits to my code so that you can properly see my thought process when implementing my designs. 

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

The goal of this assignment is to create a program that uses a linked list to store values in a queue. The queue must have the ability to:
- Enqueue: appropriately add a value to the back of the queue as an appropriate element;
- Dequeue: appropriately remove an element from the front of the queue and return its value;
- Peek: a method to peek the front and/or rear value of the queue without removing it. 

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

Design:

Understand what is a linked list:

![image](https://github.com/dudareolon/CS260_Assignment_03/assets/102680672/8e478dee-5f6a-469e-9c47-46803c818872)

A linked list is formed of several Nodes, each Node stores data and the address that points to the next node. 
For my program, I will create a struct Node. This way a Node will be a "data type" and all Nodes will be under the same structure making it easier to work with them.

To implement the queue I could have done it in a class or a struct. A struct would set everything to the public, while a class is private by default. I chose to make the queue a class because it is easier for me to work with functions/methods under a class. Here is the schematics for the class:

![image](https://github.com/dudareolon/CS260_Assignment_03/assets/102680672/bcb2deda-88b8-4155-a544-b9ea553922d5)



--------------------------------------------------------------------------------------------------------------------------------------------------------------------

Analyze the complexity of your implementations (at least the run-time of the add, remove, and peek methods):

  When analyzing the complexity of an implementation it is important to understand what the Asymptotic Big-O notation is. The Asymptotic Big-O notation measures the complexity of a program, providing an upper bound limit on the worst-case performance of the program. The notation is an O followed by a function for the upper limit as you can see below:

  ![image](https://github.com/dudareolon/CS260_Assignment_03/assets/102680672/80ea6f20-c1c8-4204-ac58-5d00b1b5da02)

  From my Assembly coding background, I like to think of the complexity of a program on how many clock cycles it takes to run all lines of the program. For example, programs that have loops, nested loops, and such, take a longer time to run than code like mine that is linear. Since my program for this assignment runs line by line, it is considered under the O(1) notation due to its constant time. It is also important to note that C++ and other languages ignore comment lines when running the program, so having a lot of comments does not change the run-time of the program.

  The time complexity for my entire code is O(1). However, the space complexity is O(n) being that n is the number of nodes in the queue; that is because each node in the queue is dynamically allocated in the memory.


--------------------------------------------------------------------------------------------------------------------------------------------------------------------


The parts of the code where I meet each one of the requirements are the following:

- Requirement 1: uses a linked list to store values in the queue:

Defines what a Node of the linked list will be

  ![image](https://github.com/dudareolon/CS260_Assignment_03/assets/102680672/3b9ca200-d2d9-4cd6-97ba-b85a14a1fd04)

Then makes the rear and front pointers of the queue nodes and initializes the queue to be empty

  ![image](https://github.com/dudareolon/CS260_Assignment_03/assets/102680672/c80e24b7-dd16-4a9d-a041-1e598c7dfd8e)




- Requirement 2: has an enqueue method that will appropriately add a value to the back of the queue as an appropriate element:

![image](https://github.com/dudareolon/CS260_Assignment_03/assets/102680672/d52dba79-78f3-4865-a4bc-d2c80a418976)

  

- Requirement 3: has a dequeue method that will appropriately remove an element from the front of the queue and return its value:

![image](https://github.com/dudareolon/CS260_Assignment_03/assets/102680672/badf5ab9-dd11-4c0f-a26a-40b26e9f334f)

  

- Requirement 4: Optionally has a peek method that returns the value at the front of the queue without removing it:

![image](https://github.com/dudareolon/CS260_Assignment_03/assets/102680672/0f126002-4ce9-41da-9d23-f4f1ac81236f)

I also made an extra peek function that returns the value at the rear/back of the queue without removing it. Here it is:

![image](https://github.com/dudareolon/CS260_Assignment_03/assets/102680672/abfb6f39-1a41-45cf-88ad-10b138a0cc1c)
