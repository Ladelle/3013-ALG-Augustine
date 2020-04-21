/*   1112 - UVA -ACCEPTED
    Ladelle Augustine 
    3013 - Algorithms
    Due: 04/19/2020 @ 11:59 pm
    Program 07 - UVA 1112 
    Shortest Path 
*/
#include <algorithm>
#include <cstring>
#include <iostream>


using namespace std;
int amat[101][101];

int main()
{
    /*                   INTIIALIZING VALUES                         */
    int test;
    int n,e,t,m,a,b,w;
    /*            READING IN THE AMOUNT OF CASES/TEST IN FILE        */
    cin >> test;

    /*                    READ INPUT                                 */
    while (test --)
    {
       
        cin >> n; // number of cells in maze
        cin >> e; // number of exit cells
        cin >> t; // starting value  T for counter down
        cin >> m; // M connections of maze
        memset(amat, 63, sizeof amat); // all elements of amat are 63- conversion
        n++;

        for (int i = 0; i < m; i++)
        {
            cin >>a >> b >> w;
            amat[a][b] = w;
        }

/*                 FLOYD WARSHAL ALGORITHM                      */
        for (int l = 0; l < n; l++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    amat[i][j] = min(amat[i][j],
                        amat[i][l] + amat[l][j]);
/*      NUMBER OF MICE THAT HAVE REACHED THE EXIT CELL BY THE TIME    */
        int result = 0;
        for (int i = 0; i < n; i++)
            if (amat[i][e] <= t || (i == e))
                result++;
        cout <<  result << "\n";
        if (test)
            cout << "\n";
  
    }

    return 0;
}