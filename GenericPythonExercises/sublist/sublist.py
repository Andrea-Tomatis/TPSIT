'''
Sublist: Given two lists determine if the first list is contained within the second 
         list, if the second list is contained within the first list, if both lists 
         are contained within each other or if none of these are true.

@Andrea-Tomatis
'''

def checkLists(a,b):
    if a == b:
        return 'equal'

    if len(a) < len(b): 
        bigger = b
        minor = a
    else: 
        bigger = a
        minor = b
    
    for i in range(len(bigger)-1):
        j = 0
        while j < len(minor):
            if bigger[i+j] != minor[j]: 
                break
            j += 1
            
        if j == len(minor):
            return 'sublist'
    
    return 'nothing'

def main():
    print(checkLists([1,2,3],[1,2,3]))
    print(checkLists([1,2,3],[1,2,4,4]))
    print(checkLists([1,2,3,4,5],[1,2,3,4]))


if __name__ == '__main__':
    main()