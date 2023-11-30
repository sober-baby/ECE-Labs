//BSTrees
//Homework
/*implement operators such that the lhs has the same structure as the rhs (hint: use pre-order traversal)
derive a class StudentBST from BSTree to define a BST of students
objecttive: redefine as few functions as possible
*/

//Complexity of BSTs
/*
Def: a set of node n0, n1, n2, ... nk is a path from n0 to nk if ni is the parent of ni+1 for i = 0, 1, 2, ... k-1
Def: path from n0 to nk has length of k  (one less than number of nodes)
Def: height of tree is equal to max length of a path from root to any node in the tree + 1
Def: height of empty tree is -1

In a tree of height h, how many nodes might tree have？

min# nodes: h 
max# nodes: 2^h - 1

Assume a tree with n nodes: 

max height: n 
minimal height: log2(n+1)

Complxity of search,insert,delete    is     O(h)= worst case O(n), best case O(log2(n))
most BST, if node keys are added in quasi-random order, than all operations are O(log2(n))

logn of 1000000 is 20

Other types of trees:
-balanced bin trees

*/


//Hash Tables

/*

                        Unsorted Array     Sorted Array     Sorted List     Sorted List     BST(min height)     Hash Table
Insert                  O(1)               O(n)             O(1)            O(n)            O(log n)            O(1)
Search                  O(n)               O(n)             O(n)            O(n)            O(log n)            O(1)














*/
