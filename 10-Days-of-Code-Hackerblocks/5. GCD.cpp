# GCD

/*
Take the following as input.

A number (N1)
A number (N2)
Write a function which returns the GCD of N1 and N2. Print the value returned.

Input Format
Two integers seperated by a new line.

Constraints
0 < N1 < 1000000000
0 < N2 < 1000000000

Output Format
Output a single integer which is the GCD of the given integers.

Sample Input
16 
24
Sample Output
8
Explanation
The largest number that divides both N1 and N2 is called the GCD of N1 and N2.
*/

#include<iostream>
using namespace std;

int gcd(int a,int b){
	if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
   
    // base case 
    if (a == b) 
        return a; 
   
    // a is greater 
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a);
}
int main() {
	int a,b;
	cin>>a>>b;
	int result = gcd(a,b);
	cout<<result;
	return 0;
}
