///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Ladelle Augustine
// Email:            ladelle2016@gmail.com
// Label:            A02
// Title:            Commenting C++ Code
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
//       This program implements a class that allows a linked list to be used just like 
//       an array. It overloads the "[]" (square brackets) to simulate accessing seperate 
//       array elements, but really it traverses the list to find the specified node using
//       an index value. It also overloads the "+" and "-" signs allowing a user to "add"
//       or "push" items onto the end of the list, as well as "pop" items off the end of our 
//       array. This class is not meant to replace the STL vector library, its simply a project
//       to introduce the beginnings of creating complex / abstract data types. 
//       
// Usage: 
//      - $ ./main filename
//      - This will read in a file containing whatever values to be read into our list/array. 
//      
// Files:            
//      main.cpp    : driver program 
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

int A[100];                               // Declare array A as an int with 100 elements.

struct Node {                             // Declare struct name as Node.
    int x;                                // Declare x as an int member variable.
    Node *next;                           // Pointer to next node. 
    Node() {                              // Default Constructor.
        x = -1;                           // setting x to -1.
        next = NULL;                      // setting next to NULL.  
    }
    Node(int n) {                         // Constructor used to overload when function has a parameter.
        x = n;                            // setting x to passed int parameter n. 
        next = NULL;                      // setting next to NULL.
    }
};
/**
 * Class Name: List
 * 
 * Description:
 *      This class implements a linked list to traverse the list to find the
 *       specified node using an index value. 
 * 
 * Public Methods:
 *                          List()                               
 *      void                Push(int val)
 *      void                Insert(int val)
 *      void                PrintTail()
 *      string              Print()
 *      int                 Pop()
 * 
 * Private Methods:         N/A
 * 
 * Usage: 
 * 
 *      List operator+(const List &Rhs): // Create Instance of List

 *      
 */
class List {                             // Declares Class name as List.
private:                                 // Private access specifiers.
    Node *Head;                          // Pointer to Head node.
    Node *Tail;                          // Pointer to Tail node. 
    int Size;                            // Declare Size as an int member variable.

public:
    List() {                              // Default constructor.
        Head = Tail = NULL;               // Setting Head and Tail to NULL.
        Size = 0;                         // Setting Size to 0.
    } 
   /**
     * Public : Push
     * 
     * Description:
     *      This function adds a value to the list in increments.
     * 
     * Params:
     *      int    :         array size
   
     * Returns:
     *      - This function returns nothing (void).
     */
    void Push(int val) {
                                          // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail) {             // If list is empty.
            Head = Tail = Temp;
        } else {                          // If list is not empty then value is added after tail.
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }
   /**
     * Public: Insert
     * 
     * Description:
     *      This function inserts values to the end of the list. 
     * 
     * Params:
     * 
     *        int    :         array size
     *
     * Returns:
     *      - This function returns nothing (void).
     */
    void Insert(int val) {
                                          // allocate new memory and init node
        Node *Temp = new Node(val);

                                          // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail) {                      // If not pointing at tail.
            Tail = Head;
        }
        Size++;
    }
   /**
     * Public : PrintTail
     * 
     * Description:
     *      This function prints out the end value.
     * 
     * Params: 
     *           NONE
     * 
     * Returns:
     *      - NONE (Void)
     */

    void PrintTail() {
        cout << Tail->x << endl;
    }
  /**
     * Public : Print
     * 
     * Description:
     *      This funciton accesses the elements in the list as string and traverses through it.
     * 
     * Params:
     *      - NONE
     * 
     * Returns:
     *      - list   :    returns the linked list of strings.
     */
    string Print() {
        Node *Temp = Head;
        string list;

        while (Temp != NULL) {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }
   /**
     * Public : Pop
     * 
     * Description:
     *      This functions pops the items off the array. 
     * 
     * Params:
     *                NONE
     * 
     * Returns:
     *      - The function returns 0 (int).
     */

    // not implemented
    int Pop() {
        Size--;
        return 0; //
    }

   /**
     * Function operator+
     * 
     * Description:
     *      This function overload + operator to add List objects.
     * 
     * Params:
     *      - const List     : objects
     * 
     * Returns:
     *      - This functions returns final List object
     */

    List operator+(const List &Rhs) {   
                                          // Create a new list that will contain both when done
        List NewList;

                                          // Get a reference to beginning of local list
        Node *Temp = Head;

                                          // Loop through local list and Push values onto new list
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

                                          // Get a reference to head of Rhs
        Temp = Rhs.Head;

                                          // Same as above, loop and push
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

                                          // Return new concatenated version of lists
        return NewList;
    }
   /**
     * Function operator[]
     * 
     * Description:
     *      This function implements the array operator and 
     *      returns an int value as if the list was an array.
     * 
     * Params:
     *       int   : index of the list values as if an array.
     * 
     * Returns:
     *      - This function returns an int value.
     */

                                         // Implementation of [] operator.  This function returns an
                                         // int value as if the list were an array.
    int operator[](int index) {
        Node *Temp = Head;

        if (index >= Size) {             // If index is greater than or equal to size out of bounds.
            cout << "Index out of bounds, exiting";
            exit(0);
        } else {
                                         // Not out of bound so continues.
            for (int i = 0; i < index; i++) {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }
   /**
     * Function operator<<
     * 
     * Description:
     *      This function creates an object of class list that
     *      calls the prints function list into a file. 
     * 
     * Params:
     *           ostream   : Allow to print out to file
     *            List     : The class 
     * 
     * Returns:
     *      - returns the list into the file after they run through the program.
     */
    friend ostream &operator<<(ostream &os, List L) {
        os << L.Print();
        return os;
    }
};
   /**
     * Function main:
     * 
     * Description:
     *      This function accesses the class functions and pushed values 0 to 25 and 
     *      50 to 100 into lists and cout the lists combined. 
     * 
     * Params:
     *      - int    : array of integers
     *      - char   : pointers to a char pointer
     * 
     * Returns:
     *      - what does this function return (including the type)?
     */
int main(int argc, char **argv) {
    List L1;                              // Declaring L1 as object of the List class.
    List L2;                              // Declaring L2 as object of the List class.

    for (int i = 0; i < 25; i++) {        // for loop to push number 0 - 25 in list
        L1.Push(i);                       // Object L1 accessing push function.
    }

    for (int i = 50; i < 100; i++) {      // for loop to push numbers 50 -100 in list
        L2.Push(i);                       // Object L2 accessing the push function.
    }

    //cout << L1 << endl;
    L1.PrintTail();                       // This is printing out the list of L1 
    L2.PrintTail();                       // This is printing out the list of L2

    List L3 = L1 + L2;                   // Adding both lists together
    cout << L3 << endl;                  // showing the results of Object L3

    cout << L3[5] << endl;               // Showing the results of L3 in index 5.
    return 0;
}