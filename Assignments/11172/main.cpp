#include <iostream>
#include <cstdlib>

#define endl "\n"

using namespace std;

int  main()
{
  int i = 0; // the condition to keep loop
    int j = abs(j); // absolute value of j and l
    int l = abs(l);
    int x;
    cin>>x;
    while(i<x){
        cin>>j>>l;
        if(j<l){
            cout<<'<'<<endl;
        }else if(j>l){
            cout<<'>'<<endl;
        }else{
            cout<<'='<<endl;
        }
        i++;
    }
    return 0;
}