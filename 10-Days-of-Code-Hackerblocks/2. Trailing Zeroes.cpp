/*
Given an integer n, write a function that returns count of trailing zeroes in n!.

Input Format
A single integer N.

Constraints
1 <= N <= 10^9

Output Format
A single integer denoting the count of trailing zeroes in N!

Sample Input
5
Sample Output
1
Explanation
Factorial of 5 is 120 which has one trailing 0.


APPROACH:- finding factorial and then calculating the trailing zeroes would result into TLE.
So to solve this problem we first find out factors of 10( i.e. 5 & 2) present in a factorial. 
Also (number of 2) > (number of 5) so we simply find out the multiple of 5 present in a factorial.
To find out the multiple of 5 in a factorial we use a formula:- floor(n/5) + floor(n/5^2) + floor(n/5^3)+ ... +0 (until 0)

*/

#include<iostream>
using namespace std;

int main () {
	int n;
	cin>>n;

	int p = 5;
	int result = 0;
	while((n/p)>0){
		result += n/p;
		p = p*5;
	}

	cout<<result;
	

	return 0;
}
