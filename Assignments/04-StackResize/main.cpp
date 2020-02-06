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
//       Overview of a class implementing an array based stack and Resizes the 
//       Stack, if the stack is full or half empty.
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
	int *A;                // pointer to array of int's
	int size;			   // current max stack size
	int top;               // top of stack 
	int G;                 // # of array growth
	int Rcount;             // counting shrink & growth

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
		Rcount = 0;
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
		Rcount = 0;
	}

	/**
	 * Public bool: Empty
	 *
	 * Description:
	 *      Stack empty?
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
	 *      Stack full?
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

		return -99; // some sentinel value
					// not a good solution
	}

	/**
	 * Public int: Pop
	 *
	 * Description:
	 *      Returns top value and removes it from stack
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      [int] top value if any
	 */
	int Pop()
	{
		   
		if (!Empty()) 
		{
			CheckResize();
			return A[top--];
		}
		return -99;                  // some sentinel value
									 // not a good solution
	}



	/**
	 * Public bool: Push
	 *
	 * Description:
	 *      Adds an item to top of stack and calls CheckResize function.
	 *
	 * Params:
	 *      [int] : item to be added
	 *
	 * Returns:
	 *      [bool] ; success = true
	 */
	bool Push(int x) {


		if (Full()) {

			ContainerGrow();                          // check resize will call growth in checkresize
			G++;					//CheckResize();            // calling resize check
		}
		if (Empty())
		{
			               
			A[++top] = x;
			//CheckResize();// resize
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

		int newSize = (size * 1.75);        // size * 1.75

		int *B = new int[newSize];          // creates new array.

		for (int i = 0; i < size; i++) {
			B[i] = A[i - 1];
		}

		delete[] A; // deletes array

		size = newSize;
		A = B;                              // resets array pointer



		Rcount++;                            // counting resize amount

	}

	/**
	 * Public void: ContainerShrink
	 *
	 * Description:
	 *      Resizes the container for the stack by decreasing the stack by .5
	 *      when the stack becomes half empty, after at least gettin full once.
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      NULL
	 */
	void ContainerShrink()
	{
		int newSize = (size * 0.5);      // shrinks size.

			int *B = new int[newSize];  // CREATES NEW ARRAY

			for (int i = 0; i < newSize; i++)
			{
				B[i] = A[i - 1];
			}

			delete[] A;
			size = newSize;

			A = B;
		
		Rcount++; // counting resize amount

	}
	/**
	 * Public void: CheckResize
	 *
	 * Description:
	 *      Checks the Resizes for array if stack is full, if stack is half full
	 *       and if stack has been full at least once to shrink it.
	 *       It calls the containerGrow and containershrink functions.
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      NULL
	 */
	// may just be to check to see if needs to shrink or keep doing what its doing
	void CheckResize()
	{
		int h = (size / 2); // half the size
		int r = (h - 1); // ratio half one less than half size
									  //int Ihe;  // Is Half Empty testing

		if (Empty() == false && Full() == false) // if stack is not full and not empty
		{
			if (h >= 20 && G >= 1 && r < h) //< r == true ) 
			{

				ContainerShrink(); // if the stack has grown at least one time and the size of stack is greater than 20 shrink the stack
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
	void Print() {
		for (int i = 0; i <= top; i++) {
			cout << A[i] << " ";
		}
		cout << endl;
		// MUST HAVE IN CODE
		cout << "################################################### " << endl;
		cout << "Assignment 4 - Resizing the Stack" << endl;
		cout << "CMPS 3013" << endl;
		cout << "Ladelle Augustine" << endl;
		cout << " Max Stack Size: " << G << endl; //NEED TO PLACE VALUE
		cout << " Stack Resized: " << Rcount << " times" << endl; // NEED TO PLACE AMOUNT OF TIME
		cout << " End Stack Size: " << size << endl; // NEED TO PLACE VALUE

		cout << "################################################### " << endl;
	}
	~ArrayStack() // destructor maybe might help free up space
	{
		delete[] A;
	}
};

// MAIN DRIVER
// Simple Array Based Stack Usage:
int main()
{


	ifstream infile("nums_test.dat");                  // opening file
	ofstream outfile("output.txt");              //   putting in ouput file

	ArrayStack stack;

	int number;
	if (!infile.eof())
	{
		while (infile >> number)
		{
			if (number % 2 == 0)
			{
				stack.Push(number);
			}
			else
			{
				stack.Pop();
			}
		}
	}
	/*
	int r = 0;

	for (int i = 0; i < 50; i++) {
		r = rand() % 100;
		r = i + 1;
		if (!stack.Push(r)) {
			cout << "Push failed" << endl;
		}
	}
	
	for (int i = 0; i < 50; i++) {
		stack.Pop();
	}
	*/

	stack.Print();

	infile.close();
	outfile.close();
	system("pause");
	return 0;
}