
# INTAL DATA STRUCTURE (BigInt)

## Introduction 
This is a simple data structure made to represent large non negative integers. It is stored a NULL terminating string.
The types provided by C are limited in the size of integers it can represent. Type int can only represent ~0 - 64000, while
intal can represent numbers from 0 to 10^2500 making it possible to meet most of the applications for large numbers.
Intal can be used for scientific computing and managing very large values. It can also be used in cryptology as large prime 
numbers can be easily represented in Intal.


## Aprroach:

### Genral:
Most of the algorithms have few base cases that will help pass all corner test cases and make them fast. The algortithms implemented 
here try to manage memory. Some memory leaks are possible. Some of the algorithms can be optimized.

### Addition:
To find the sum the algorithm mimics a human adding two large numbers. It adds them digit by digit and propogates the carry
towards the most significant digit. No special case is given for any overflow. Once the addition is done any leading zeros are 
removed.

### Subtraction:
It returns the absalute difference between two numbers. If the second number is larger, the two numbers are swapped. This algorithm
also mimics a human performing subtraction. It subtracts digit by digit. Once the subtraction is done any leading zeros are 
removed.

### Comparison:
It firstly removes any leading zeros and then compares the length of the string. Which ever string is longer the number it 
represent is larger. If the strings are of same lengths then the algorithm goes digit by digit from MSD to LSD till a mishmatch 
is found. Based on the mishmatch it returns the comparison value.

### Multiply:
This also mimics a human. It is a O(n^2) algorithm. The results is stored in an integer array and then later converted to a string.

### Mod:
To implement this algorithm firstly a division algorithm was implement. Using the fromula R = D - d*int(D/d) the mod is calculated.

### Power:
A simple iterative multiplication will not work in this case as it would result in a O(n^3) algorithm. To mitigate this Binary Exponentiation 
has been used. It has been implement iteratively. This makes the algorithm faster reducing the time complexity for extra static number of variables.

### GCD:
This has been implemented using the MOD functionality and the Eulers formula recursively. This makes the algorithm extreamly fsat and the code converges
onto the answer fairly quickly.

### Fibonacci:
This has been implemented using Dynamic programming using 2 extra varibles. This will make the algorithm run much faster in exchange for
a few kilo bytes of memory.

### Factorial:
This has been implemented using an iterative approach using multiplication as base operation. This is the brute force approach and in this case further
optimization is not needed.

### Binary Coeffcient:
This function is written as a DP algorithm. It uses extra space of order O(k+1). The algorithm also uses the identity C(n,k) = C(n,n-k) to make sure
that the time taken for C(1000,900) is not grater than C(1000,500). The whole algorithm works on the basis of C(n,k) = C(n-1,k-1) + C(n-1,k). Thus the 
program needs only O(K) extra space.

### MAX,MIN,Search:
These algorithms are implemented as a single for loop iterating through the array to find the in,max,key.

### Binary Search:
There is only a small chage made here from the regular binary search, it makes sure that it will find the first occurance. To do so it checks if 
the number preceding the key in the list is also smaller than the key. Other than that samll change the algorithm is unchanged from the original.
The time complexity is O(logn)

### Sorting:
The sorting is carried out using quick sort algorithm. This is done as to make sure no extra space is needed. THe time complexity is O(nlogn) in the average case.
Heap sort could have been implement as the size of the array is less than 1000 elements.

### coin row problem:
The recursive code for the problem was converted into an iterative code. This eleminated the space needed for the stack. The algorithm works fast and 
requires only O(1) extra space. The recursive code was abandoned as it took tooo much time.



## Future Scope:

* Implement more functions. Such as left and right shift (by factor of 10).
* Add a function to change the base of the given number. (Base 2,8,16).
* Incorporate non positive numbers.
* Make the algorithms more efficient.
* Make the lenght of the strings variable based on the size of the number. This can be done by making a new data structure similar to string which is 
implemented as a dynamic array so memory is not wasted for small numbers. This way most of the memory which is currently being wasted will no longer be wasted.
* Currently all memory leaks have been spotted and avoided.
