# OVERTHINKING THE ONE THAT WAS ACCEPTED WAS MAINFORUVA.PY

# Ladelle Augustine
# 3013- Algorithms
# Due: 04/16/2020
# Program 06 - UVA 11597 
# Spanning Trees
# 
import math
import itertools
import array as arr
# side notes: To delete
# ctrl + k+ c = comment block 
# ctrl + k + u = un comment

def main():
    #decalre cases as 0
    cases = 0
    
    #opening file
    with open("input2.txt","r") as infile:
        # checks if file is in open mode --> proceeds if YES
        if infile.mode == "r":
            #setting values as each line is read in
            values = infile.readlines()
            #for loop to read in each value 
            for c in values:
                #counts the cases in file
                cases += 1
                #converting string to int 
                n = int(c)
                #calculate edges
                edges = n - 1
                #if c = 0 then has to be end of file so break.
                if c == 0:
                    break
                aset = {}
                # # creating a holder for the n values
                holder = []
                # using a for loop to add value to holder using n
                for x in range(1,n+1):
                    holder.append(x)
                    aset = {x}
                # adding values from holder into set
                aset.update(holder)
                # setting size of subsets "l" = 2
                l = 2
                #placing the combinations of subsets into a container called holder2
                holder2 =[set(i) for i in itertools.combinations(aset,l)]
                
                #setting number of sets to the length of holder2
                number = len(holder2) 
                
                #maximum possible numbers of sparring with unique sets
                maxSpar = int (number/edges)
                #prints out case # and the value in each case without '\n'
                print("Case:", cases," Edges: ", edges,"Verticies: ", c.strip('\n'), "max possible spars: ", maxSpar)


                
    # closes the file         
    infile.close()

    
# testing function    
if __name__== "__main__":
    main()
    
    # FROM MAIN.PY  COPIED #
    #    cases = 0
    # holder =[]
    # holder2 = []
    

    # for line in sys.stdin:    
    #     if '0' == line.rstrip():
    #         break
    #     else:
    #         cases += 1
    #         n = int(line)
    #         edges = n - 1
    #         for x in range(1,n+1):
    #             holder.append(x)  
    #         #holder2 =[set(i) for i in itertools.combinations(holder,2)]   
    #         number = len(holder2)
    #         maxSpar = int (number/edges)
    #         print("Case:", cases,": ", maxSpar)
                             