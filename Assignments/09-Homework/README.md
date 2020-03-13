## Homework - Data Structures and Complexity
#### Due: 03-13-2020 (Friday @ 3:30 p.m.)

- Given a collection of algorithms that runs on **O(1), O(n log n), O(n), O(n<sup>2</sup>), O(log n), O(n!)**, order the algorithms from fastest to slowest.
- Suppose that the complexity of an algorithm is O(n<sup>2</sup>). Suppose that the program that uses the algorithm run in 10 seconds for a data set of size n. If the data size is doubled, how long will it take (approximately) to run the program? 


- Complexities : **O(1), O(n log n), O(n), O(n<sup>2</sup>), O(log n), O(n!) , O(h)**
1.Finding the max element in an unordered stack would require ______________ operations?
< O(n), because finding the max element searches through all elements in the stack. >
             
2. Finding the min element in an unordered queue would require _____________ operations?
< O(n), because finding the min element searches through  all elements in the queue. >

3. Finding some element in some Binary Search Tree would require _____________ operations?
< O(h) or O(n), because O(h) finds the element based on the height of the tree , O(n) when height of the tree becomes n.>

4. Finding some element in a balanced Binary Search Tree would require _____________ operations?
< O(log n), because binary search because the Binary Search Tree is balances.>

5. Finding some element in an ordered linked list would require _____________ operations (worst case)?
< O(n), because searches through all elements in the linked list. >

6. Finding some element in an ordered linked list would require _____________ operations (average case)?
< O(n/2), because searching through elements half of the linked list will be either less or more than some element we are finding on average.> 
7. Finding some element in an unordered linked list would require _____________ operations (worst case)?
< O(n), because searches through all elements.>

8. For each of the following, count the number of operations where some_statement is executed based on the loops

```cpp
//A
for (int I = 0; I < n; I++)
    for (int j = 1; j < n; j++)
        {some_statement;}
```
< O(n<sup>2</sup>), because "I" loops through n times and "j" loops through n times, which leads to n X n or n<sup>2</sup>. >

```cpp
//B
for (int I = 0; I < n; I +=2)
    for (int j = 1; j < n; j++)
        {some_statement;}
```
<O(n<sup>2</sup>),Even though I iterates plus 2 each time "I" loops through n times and "j" loops through n times, which leads to n X n  is n<sup>2</sup> >
```cpp
//C
for (int j = 1 ; j < n ; j *= 2)
    for (int I = 1; i<n; i++)
        {some_statement;} 
```
< O(n log n ), because the first loop goes through log n times with "j" iterating to the power to 2. The second loop "I" goes through n times. >

At most, how many comparisons are required to search a sorted vector of 1023 elements using the binary
search algorithm? 

< At most 10 comparisons will be required to search a sorted vector of 1023 elements using the binary search element.>

In each of the following examples, please choose the best data structure(s).
- Options are: **Array, Linked Lists, Stack, Queues, Trees, Graphs, Sets, Hash Tables**. 
- Note that there may not be one clear answer.

1. You have to store social network “feeds”. You do not know the size, and things may need to be dynamically added.
<Linked Lists>
2. You need to store undo/redo operations in a word processor.
<Stack>
3. You need to evaluate an expression (i.e., parse).
<Stack>
4. You need to store the friendship information on a social networking site. I.e., who is friends with who.
<Graphs>
5. You need to store an image (1000 by 1000 pixels) as a bitmap.
<Array>
6. To implement printer spooler so that jobs can be printed in the order of their arrival.
<Queues>
7. To implement back functionality in the internet browser.
<Linked List>
8. To store the possible moves in a chess game.
<Graphs>
9. To store a set of fixed key words which are referenced very frequently.
<Hash Tables>
10. To store the customer order information in a drive-in burger place. (Customers keep on coming and they have to get their correct food at the payment/food collection window.)
<Queues>
11. To store the genealogy information of biological species.
<Trees>
12. To store an alphabetized list of names in order to look up quickly.
<Trees>


## Deliverables

- Edit this file and add your answers using markdown!
- Create a folder called `H03` in your assignments folder.
- Put a copy of your markdown file in this folder, and call it README.md.
- Upload to github sometime close to the due date.
- Print out your banner ON ITS OWN PAGE

```
H03
3013
LASTNAME
```

- Print out a hard copy of the file as well. Do not print directly from github. Either use `gitprint` or make it a pdf and print it.
- Make sure you answer thoroughly using complexities where appropriate and/or explaining your choices etc.
