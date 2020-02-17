///////////////////////////////////////////////////////////////////////////////
//
// Author:           Ladelle Augustine
// Email:            ladelle2016@gmail.com
// Label:            07-H02
// Title:			 Assignment 7 - Heapify
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//              This is an overview of the Heap class. Fix Methods in the code snippet
//               Heapify an unsorted array.
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include "timer.hpp"
#include <algorithm>


using namespace std;

/**
 * Class Heap
 * 
 * @methods:
 *      constructors:
 *          Heap        : default constructor
 *          Heap(int)   : overload constructor with heap size
 *      private:
 *          BubbleUp    : swapping the smallest from the bottom up
 *          Left        : left child 2i
 *          OnHeap      : checking to still be in heap
 *          Parent      : parent i/2 
 *          Right       : right child 2i+1
 *          Swap        : swaping the smallest values
 *          /// Fix These:
 *          Heapify     : heapify a subtree 
 *          SinkDown    : to sinkdown by heap properity.
 *          PickChild   : choosing the smallest child by index. 
 *      public:
 *          Insert      : adding elements to the heap
 *          Print       : printing out elements in heap
 *          Remove      : removing elements from the top of the heap
 */
class Heap {
private:
    int size;                   // size of the array
    int *H;                     // array pointer
    int end;                    // 1 past last item in array

    /**
   * BubbleUp
   * 
   * @description: 
   *    This puts one value into its proper
   *    place in the heap.
   * 
   * @param  {int} index : index to start bubbling at
   * @return             : void
   */
    void BubbleUp(int index) {
        // check parent is not of beginning of array
        if (Parent(index) >= 1) 
        {
            // index is on array and value is less than parent
            while (index > 1 && H[index] < H[Parent(index)]) {
                // do a swap
                Swap(index, Parent(index));

                // update index to values new position
                index = Parent(index);
            }
        }
    }

    /**
     * Left
     * @description:
     *      Calculates index of left child.
     * 
     * @param  {int} index : index of parent
     * @return {int}       : index of left child
     */
    int Left(int index) {  return 2 * index; }

    /**
     * OnHeap
     * @description:
     *      Checks if an index is on the array (past the end).
     * 
     * @param  {int} index : index to check
     * @return {bool}      : 0 = off heap / 1 = on heap
     */
    bool OnHeap(int index) {  return index < end;}

    /**
     * Parent
     * @description:
     *      Calculates parent of a given index.
     * 
     * @param  {int} index : index to check
     * @return {int}       : parent index
     */
    int Parent(int index) { return index / 2;}

    /**
     * Right
     * @description:
     *      Calculates index of right child.
     * 
     * @param  {int} index : index of parent
     * @return {int}       : index of right child
     */
    int Right(int index) { return 2 * index + 1; }

public:
    /**
     * Swap
     * 
     * @description: 
     *      Swaps to values in the heap
     * 
     * @param  {int} i  : index in array
     * @param  {int} j  : index in array
     * @return          : void
     */
    void Swap(int i, int j)
     {
        int temp = H[i];
        H[i] = H[j];
        H[j] = temp;
     }

    ////////////////////////////
    //Fix These Methods
    ////////////////////////////

    /**
     * 
     * @param  {int*} A   :  array pointer with unsorted values to make into a heap
     * @param  {int} size :  size of new heap
     */
  void Heapify(int* A, int s) //size and pointer is passed
    {
       H = A;         // Setting H to A - sending over from array A
     
     
       end = s;       // relocating end to end of new heap 
     

                                            /* Build a Heap*/
        int NLindx = (s / 2) - 1;           // index of the last non-leaf node
      

        for (int i = NLindx; i > 0; i--)    // builds a heap 
        {
            SinkDown(i);                     // calls sinkdown method
        }
     
    
      
 
    }

    /**
     * SinkDown
     * @description:
     *      Places one heap item into its proper place in the heap
     *      by bubbling it down to it proper location.
     * 
     * @param  {int} index  : index to start from in the array
     * @return              : void 
     */
  void SinkDown(int index)
    {
        int LeftC= Left(index);      // LeftChild 
        int RightC= Right(index);    // Rightchile
        int smallest= index;         // initalizing smallest to index
     
        if (LeftC < end && H[LeftC] < H[index])   
        {
            smallest = LeftC;   
        }
        if (RightC < end && H[RightC] < H[smallest])
        {
            smallest = RightC;
        }
        if (smallest != index)
        {
            Swap(index, smallest);
            SinkDown(smallest);          // sinking down with the smallest value   
        }

    }

    /**
     * PickChild
     * @description:
     *      If one child exists, return it.
     *      Otherwise, return the smaller of the two.
     * 
     * @param  {int} index  : index of parent in the array
     * @return              : index to child 
     */
    int PickChild(int index) 
    {
          int PickChild(int index); // index of parent in array return index of child
    
        while (OnHeap(index))       // making sure on heap
        {
            if (end % 2 == 1)       // When NO right child
            {
                return Left(index);
            }
            else                    // When has TWO children.
            {
                if (Right(index) < end)
                {
                    if (H[Right(index)] > H[Left(index)])
                    {
                        return Left(index);
                    }
                    else
                    {
                        return Right(index);
                    }
                }

            }
        }
    }
    
     
    


    /**
   * Heap constructor
   */
    Heap() {
        size = 100;
        H = new int[size];
        end = 1;
    }

    /**
   * Heap constructor
   * 
   * @param  {int} s : heap size 
   */
    Heap(int s) {
        size = s;
        H = new int[s];
        end = 1;
    }

    /**
   * Insert
   * 
   * @description:
   *        Add a value to the heap.
   * 
   * @param  {int} x : value to Insert
   * @return         : void
   */
    void Insert(int x) {
        H[end] = x;
        BubbleUp(end);
        end++;
    }

    /**
     * For test our heap !!!  
     */
    void Print(ostream& out)
    {
        out << " The Heap " << " ";
        for (int i = 1; i <= end-1; i++)
        {
         
            out << H[i];
            if (i < end - 1)
            {
                
                out << "->" << " ";
            }
        }
        out << endl;
    
    }

    /**
     * Remove
     * @description:
     *      Removes item from top of heap
     * 
     * @return {int}  : top of heap
     */
    int Remove() {
        int temp = H[1];
        H[1] = H[end]; // removed root 
        --end;

        return temp;
    }

};

int main() {
   ofstream out("outfile.txt");// printing to outfile 

   Timer testMethodTimer;
   double timeItTook;
   Heap Test1;
   Heap Test2;

   int Arraytest[11] = { 25,22,18,28,1,30,17,50,33,7,9 };
   int *A = Arraytest ;

   
   testMethodTimer.Start();                       // Starting timer
   Test2.Heapify(A, 11);                          // Testing if Heapify works
   testMethodTimer.End();                         // Stoping timer

   timeItTook = testMethodTimer.Seconds();        // Time it took 
   out << "*********************************************************" << endl;
   out << " Ladelle Augustine " << endl;
   out << " Assignment 7 - Heapify " << endl;
   out << " CMPS 3013 " << endl; 

   out << " ######################################################## " << endl;
   out << " Method Used: Heapify " << endl;
   out << " Time Taken by Method To Run: " << timeItTook << " Second(s)" << " " << endl ;
   out << " ------------------------------------------------------- " << endl; 
   Test2.Print(out);
  out  << " ________________________________________________________" << endl; 
  
   testMethodTimer.Start();                         // starting timer                                                 // Insert method used
    Test1.Insert(26);
    Test1.Insert(23);
    Test1.Insert(19);
    Test1.Insert(29);
    Test1.Insert(2);
    Test1.Insert(31);
    testMethodTimer.End();                          // stoping timer

    timeItTook = testMethodTimer.Seconds();         // time it took 


    out << " Method Used: Insert " << endl;
    out << " Time Taken by Method To Run: " << timeItTook << " Second(s)" << " " << endl;
    out << " ------------------------------------------------------- " << endl;
    Test1.Print(out);
    out << " #######################################################" << endl;

    out.close();
     system("pause");
    return 0;
}