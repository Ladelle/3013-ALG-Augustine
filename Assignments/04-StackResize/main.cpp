///////////////////////////////////////////////////////////////////////////////
//
// Author:           Ladelle Augustine
// Email:            ladelle2016@gmail.com
// Label:            04-P01
// Title:			 Assignment 4 - Array Based Stack
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       Overview of a class implementing an array based stack.
//       Resize the Stack, if the stack is full or half empty.
//       Calculate the Maximum stack size, the amount of times 
//       the stack was resized and the end stack size. 
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>

using namespace std;

/**
 * ArrayStack
 *
 * Description:
 *      Array based stack
 *
 * Public Methods:
 *      - See class below
 *
 * Usage:
 *      - See main program
 *
 */
class ArrayStack {
private:
	int* A;									  // Pointer to array of int's
	int size;								  // Current stack size
	int top;								  // Top of stack 
	int G;									  // # of array growth
	int MaxG;								  // the max size of array
	int S;									  // Shrink count
	int Cpop;								  // Call to pop count

public:
	/**
	 * ArrayStack
	 *
	 * Description:
	 *      Constructor no params
	 *
	 * Params:
	 *     - None
	 *
	 * Returns:
	 *     - NULL
	 */
	ArrayStack() {
		size = 10;
		A = new int[size];
		top = -1;
		G = 0;
		MaxG = 0;
		S = 0;
		Cpop = 0;
	}

	/**
	 * ArrayStack
	 *
	 * Description:
	 *      Constructor size param
	 *
	 * Params:
	 *     - int size
	 *
	 * Returns:
	 *     - NULL
	 */
	ArrayStack(int s) {
		size = s;
		A = new int[s];
		top = -1;
		G = 0;
		MaxG = 0;
		S = 0;
		Cpop = 0;
	}

	/**
	 * Public bool: Empty
	 *
	 * Description:
	 *      Checks to see if stack is empty?
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      [bool] true = empty
	 */
	bool Empty() {
		return (top <= -1);
	}

	/**
	 * Public bool: Full
	 *
	 * Description:
	 *      Checks to see if Stack is full?
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      [bool] true = full
	 */
	bool Full() {
		return (top >= size - 1);
	}

	/**
	 * Public int: Peek
	 *
	 * Description:
	 *      Returns top value without altering the stack
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      [int] top value if any
	 */
	int Peek() {
		if (!Empty()) {
			return A[top];

		}

		return -99;                           // some sentinel value
											  // not a good solution
	}

	/**
	 * Public int: Pop
	 *
	 * Description:
	 *      Returns top value and removes it from stack also calls CheckResize method.
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      [int] top value if any
	 */
	int Pop()
	{
		Cpop++;
		if (!Empty())
		{
	
			CheckResize();     // calling CheckResize function

			return A[top--];
		}
		return -99;                           // some sentinel value
											  // not a good solution
	}



	/**
	 * Public bool: Push
	 *
	 * Description:
	 *      Adds an item to top of stack, if full called ContainerGrow if
	 *      stack is not empty and not full it calls CheckResize function.
	 *
	 * Params:
	 *      [int] : item to be added
	 *
	 * Returns:
	 *      [bool] ; success = true
	 */
	bool Push(int x) {


		if (Full()) {

			ContainerGrow();                // Calls containerGrow because stack is full
			G++;                           // Calculates the amount of times the containerGrow method is called.
			return true;
		}
		if (Empty())
		{

			A[++top] = x;                   // add to the top of the stack
			return true;
			
		}
		else 
		{
			
			A[++top] = x;
			CheckResize();
			return true;
		
		}

		return false;

	}
	/**
 * Public void: ContainerGrow
 *
 * Description:
 *      Resizes the container for the stack by increasing the stack by 1.75
 *      when the stack becomes full.
 *
 * Params:
 *      NULL
 *
 * Returns:
 *      NULL
 */

	void ContainerGrow()
	{

		int newSize = (size * 1.75);       // Size will increase by (size * 1.75)

		int* B = 0;						   // Creates pointer B to new array.
		B = new int[newSize];			   // Creates new array B and initilizes size as newSize.

		if (newSize > MaxG)				   // Calculates the Maximum size of stack
		{
			MaxG = newSize;
		}
	
		for (int i = 0; i <size; i++)	   // For loop to copy elements in array A to array B.
		{
			B[i] = A[i-1];
		}
		delete[] A;		
		 // Deletes array A
		size = newSize;					   // Setting size to what the newSize was.
		A = B;							   // Resets array pointers.
	}

	/**
	 * Public void: ContainerShrink
	 *
	 * Description:
	 *      Resizes the container for the stack by decreasing the stack by .5
	 *      when the stack becomes half empty, after at least getting full once and
	 *      the pop function being called at least one time.
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      NULL
	 */  
	void ContainerShrink()
	{

		int newSize = (size * 0.5);        // Shrinks size.

		int* B = new int[newSize];		   // Creates a new array with pointer B.

		for (int i = 0; i < newSize; i++)  // For loop to copy elements in array A to array B.
		{
			B[i] = A[i-1];
		}

		delete[] A;							// Deletes array A
		size = newSize;						// Setting size to what the newSize was.

		A = B;								// Resets array pointer

	}
	/**
	 * Public void: CheckResize
	 *
	 * Description:
	 *      Checks the Resizes for array; if stack is full, if stack is half full,
	 *      if stack has been full at least once and if pop has been called at least
	 *      one time to shrink it. This method makes a call to ContainerShrink method.
	 *
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      NULL
	 */
	void CheckResize()
	{
		int h =  (size / 2) ;						// h = Half of the size of current items on stack
 		int p = (top + 1);										// p = the element one less than h. 

		if (Empty() == false && Full() == false)				// If stack is not full and not empty then run the rest. 
		{
 			if (size >= 20 && G >= 1 && p <= h && Cpop >= 1)		// If half size is >=20, has called ContainerGrow more than 1 time,
																//  p < h and  pop has bee   n called more than 1 time call ContainerShrink.
			{
				ContainerShrink();								// Calling ContainerShrink method.
				S++;											// Counting shrinking 
			}
		}
	}
	 

	/**
	 * Public void: Print
	 *
	 * Description:
	 *      Prints stack to standard out
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      NULL
	 */
	void Print(ostream& out)
	{
		out << "################################################### " << endl;
		out << "Assignment 4 - Resizing the Stack" << endl;
		out << "CMPS 3013" << endl;
		out << "Ladelle Augustine" << endl;
		out << "Max Stack Size: " << MaxG << endl;
		out << "Stack Resized: " << G + S << " time(s)" << endl;
		out << "End Stack Size: " << size << endl;
		out << "################################################### " << endl;
	}


	~ArrayStack()                                     // Destructor 
	{
		delete[] A;
	}
};

// MAIN DRIVER
// Simple Array Based Stack Usage:
int main()
{


	ifstream infile("nums_test.dat");					  // Opening file
	ofstream out("outputoutput.txt");                   // Putting in ouput file

	ArrayStack stack;

	int number;
	if (!infile.eof())                                // If not the end of the file proceed with while statement
	{
		while (infile >> number)					  // Reading in file data 
		{
			if (number % 2 == 0)					  // Calculating if the numbers are even.
			{
				stack.Push(number);                   // If numbers are even then push them into stack.
			}
			else
			{
				stack.Pop();						  // If numbers are odd pop from the stack.
			}
		}
	}
	stack.Print(out);


	infile.close();
	out.close();
	system("pause");
	return 0;
}

