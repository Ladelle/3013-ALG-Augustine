///////////////////////////////////////////////////////////////////////////////
//
// Author:           Ladelle Augustine
// Email:            ladelle2016@gmail.com
// Label:            05-P02
// Title:			 Assignment 5 - Processing in Linear Time
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//              This program is to load a json file into a linked list
//              and Time it from start to finish. Also, this program 
//              uses getch which, prompted the user to type in a word
//              and find it in the linked list. The program then shows 
//              the words found with the word the user writes or not and
//              tells the user at most 10 words and the seconds it took
//              to find it.
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Timer.hpp"
#include "mygetch.hpp"
#include <time.h>
#include <chrono>
#include <fstream>
#include <string>
#include "list.hpp"

#include "jsonFacade.hpp"

using namespace std;
using json = nlohmann::json;

int main()
{

    // read JSON file
    JsonFacade file("dict_w_defs.json");

                                                       /*         Time                 */   

    Timer T, RunList;                                        // Timer T = Getch ; RunList = LinkedList
   
    double s; 
    double m; 
    double ls; 
    long lm; 

                                                         /*    LinkedList            */
    
    Dictionary List;                                          // Object from list.hpp - linkedlist 

  

    vector<string> keys = file.getKeys();

    RunList.Start();                                         // starting Timer RunList
    T.Sleep(1500);                                           // milliseconds

    for (int i = 0; i < keys.size(); i++)                    // for loop 
    {
        string word = file.getKey(i);                       // getting word

        string def = file.getValue(word);                   // getting definitions

        List.Insert(word, def);                             // loading word and def into list
    }

    RunList.End();                                          //Finish running Timer 
    ls = RunList.Seconds();                                 // calculates Timer in Seconds
    lm = RunList.MilliSeconds();                            // calculates Timer in MilliSeconds

                                                            /*       Getch Section          */

    char k;                                                 // holder for character being typed
    string var = "";                                        // var to concatenate letters to

    cout << "Type keys and watch what happens. Type capital E to quit." << endl;

    
    while ((k = getch()) != 'E')
    {
        T.Start();                                           // Start Timer for Getch
        var += k;                                            // append char to var

        if ((int)k != 10)                                   
        {  
            
            cout << var << "\n\n" << endl;
           
        }
        
        List.search(var) ;                                  // searches for var
       
       
                                                          // hitting enter sets word back to empty
        if((int)k == 10 )
        {
            cout<<"Enter pressed ... Word is empty\nWord: "<<endl;
            var = "";
        }

        T.End();                                           // end timer for getch
        s = T.Seconds();                                   // calculates timer in seconds
        cout << List.Itemsfound() << "  found in : " << s << "  seconds" << endl;

        List.DisplayTenW();                                // displays ten words
        cout << "\n\n\n\n\n\n\n\n\n ";
    
    }

    system("pause");
    return 0;
}