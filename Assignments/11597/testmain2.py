# # OVERTHINKING THE ONE THAT WAS ACCEPTED WAS MAINFORUVA.PY
# Ladelle Augustine
# 3013- Algorithms
# Due: 04/16/2020
# Program 06 - UVA 11597 
# Spanning Trees
# 
import math
import itertools
import array as arr
import sys
# side notes: To delete
# ctrl + k+ c = comment block 
# ctrl + k + u = un comment

def main():
   #decalre cases as 0
    cases = 0
    
    #opening file
    while True:
        #setting values from input
        v = int(input())
            #if c = 0 then has to be end of file so break.
        if v == 0:
            break
        else:
            #counts the cases in file
            cases += 1
            #converting verticies and nth
            n = v
            #calculate edges
            edges = n - 1
            # # creating a holder for the n values
            holder = []
            l = 2
            # using a for loop to add value to holder using n
            for x in range(1,n+1):
                holder.append(x)
                # for subset in itertools.combinations(holder,l):
                #     #aset = holder(x)
            holder2 =[set(i) for i in itertools.combinations(holder,l)]

            # adding values from holder into set
            #aset.update(holder)
            # setting size of subsets "l" = 2
            #l = 2
            #placing the combinations of subsets into a container called holder2
           # holder2 =[set(i) for i in itertools.combinations(aset,l)]
                
            #setting number of sets to the length of holder2
            number = len(holder2) 
                
            #maximum possible numbers of sparring with unique sets
            maxSpar = int(number/edges)
            #prints out case # and the value in each case without '\n'
        print("Case:", cases,": ", maxSpar)
                             

                
    
# testing function    
if __name__== "__main__":
    main()