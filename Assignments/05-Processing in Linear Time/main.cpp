#include <iostream>
#include <fstream>
#include <chrono>
#include "Timer.hpp"
#include "JsonFacade.hpp"
#include "mygetch.hpp"
#include "LinkedListDict.h" 

using namespace std; 

int main()
{

	
	Dictionary List; // linked list to contain dictionary
	ofstream out("outfile.txt");
	JsonFacade file("dict_small.json"); // creating an object to read in file

	Timer RunList;
	double Trun;

	string key; // key variable to access json file
	string def; // defintion variable 
	vector<string> keys = file.getKeys();

	RunList.Start();  // starting time

	for (int i = 0; i < keys.size(); i++)
	{
		key = file.getKey(i);  // getting word

		def = file.getValue(key); // getting definitions
		List.Insert(key, def);
	}

	RunList.End();
    Trun = RunList.Seconds();   // Time in seconds

	

/* Input starts   */

	char User;   // place for char being typed
	string input = ""; // variable to cat. letters
	cout << " Type a word. Type capital E to quit. " << endl;
	
	while ((User = getch()) != 'E')
	{
		Timer UserT;
		UserT.Start();
		input += User;

		if ((int)User != 10)
		{
			cout << Trun <<endl;
			cout << User << " The key is : " <<  (int)User << endl;
		
		}
		if((int)User == 10 )
		{
			cout << " Enter pressed ... sets word back to empty \n User: "<< endl; 
			input = "";
		}
        List.search(input);     // searching for input
		UserT.End();
	
	

		size_t search = UserT.Seconds(); // user info time search
		
		cout << "\n\n" <<List.Itemsfound() << " Words Were Found In : " << search << " Seconds " << endl;
		

		List.DisplayTenW();

		cout << "\n\n\n " << endl;
	}

				
	/* Closing infile and out */
	//infile.close();
	out.close();
	system("pause");
	return 0;
}

