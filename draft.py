#目标： 找出对称且最大的数字

#loop through all the numbers
#check if the number is symmetric, and append it to a list
#check if the number is the largest

#10 * 11 = 110
#11 * 11 = 121
#12 * 11 = 132
#13 * 11 = 143
#...




#9009 is symmetric?

#solution number 1, see if the left half is the reverse of the right half

def symmetricc(st): # check if a string is symmetric
    f = st[:len(st)//2] # first half
    s = st[(len(st) - len(st)//2):][::-1] # reverse
    return f == s

#solution number 2, compare the first and last, second and second last, etc

#st = "123456" len(st) = 6

#when i = 0, st[i] = 1, st[len(st)-1-i] = 6


def symmetric(st): 
    for i in range(len(st)):
        if st[i] != st[len(st)-1-i]:
            return False # one return false will stop the function
    return True


# "10**a" means 10 to the power of a
# i = 10,  j = 10, 11 ,12 ,13 ,14 ,15 ,16 ,17 ,18 ,19 .... 99
# i = 11,  j = 11, 12 ,13 ,14 ,15 ,16 ,17 ,18 ,19 .... 99
# i = 12,  j = 12, 13 ,14 ,15 ,16 ,17 ,18 ,19 .... 99
#...
# i = 99,  j = 10, 11 ,12 ,13 ,14 ,15 ,16 ,17 ,18 ,19 .... 99

#(99 - 10 + 1)^2

#a = 1
#b= 1
#if(a == b):
   # print("1 is equal to 1")
    
# opearator == returns a boolean, which is either True or False

if __name__ == '__main__':
    digit = 4
    palin = []
    for i in range(10**(digit-1),10**digit):
        for j in range(10**(digit-1),10**digit):
            if symmetric(str(i*j)):
                palin.append([i,j,i*j])
    
    # list = [1,2,3,4,5,6,7,8,9,10]  list[0] = 1
    # listoflist = [[1,2,3],[4,5,6],[7,8,9]]  listoflist[0] = [1,2,3]  listoflist[0][0] = 1
    
    
    #palin is a list of lists, each list contains 3 elements
    #palin[0] = [1,1,1], palin[1] = [1,2,2], palin[2] = [1,3,3] ...
    '''            
    palin.sort(key=lambda x: x[2])
    take_end = lambda x: x[2]
    def take_end(elem):
        return elem[2]
    '''
      
    #list = [0 ,100, 234, 6]
    #sort list in ascending order
    #list.sort()  -> [0, 6, 100, 234]
    
    max = palin[0] #max is a list of 3 elements
    for i in range(1, len(palin)):
        if palin[i][2] > max[2]:
            max = palin[i]            
    print(max)
    
#palin = [[11,11,121], [11,22,242], [11,33,363]]
#max = palin[0] = [11,11,121]
#palin[1] = [11,22,242], palin[1][2] = 242
#max[2] = 121




#list = [1,2,3,4,5,6,7,8,9,10]
#list[0] = 1
#newlist = list[0:5] (index zero to index 4)  newlist = [1,2,3,4,5]
#newlist = list[5:10] (index 5 to index 9)  newlist = [6,7,8,9,10]
#newlist = list[5:] (index 5 to the end)  newlist = [6,7,8,9,10]
#newlist = list[:5] (index 0 to index 4)  newlist = [1,2,3,4,5]
#newlist = list[:] (index 0 to the end)  newlist = [1,2,3,4,5,6,7,8,9,10]
#newlist = list[-1] newlist = [10]
    