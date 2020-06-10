/*
Take as input N, an odd number (>=5) . Print the following pattern as given below for N = 7.

*  ****
*  *
*  *
*******
   *  *
   *  *
****  *

Input Format
Enter value of N ( >=5 )

Constraints
5 <= N <= 99

Output Format
Print the required pattern.
*/

#include<iostream>
using namespace std;
int main() {
	int N;
	cin>>N;

	int spaces = (N-3)/2;
	int stars = (N+1)/2;
  
	cout<<"*";
	for(int i=0;i<spaces;i++){cout<<" ";}
	for(int j=0;j<stars;j++){cout<<"*";}
	cout<<endl;

	for(int k=0;k<spaces;k++){
		cout<<"*";
		for(int i=0;i<spaces;i++){cout<<" ";}
		cout<<"*"<<endl;
	}

	for(int i=0;i<N;i++){cout<<"*";}
	cout<<endl;
	for(int k=0;k<spaces;k++){
		for(int j=0;j<=spaces;j++){cout<<" ";}
		cout<<"*";
		for(int l=0;l<spaces;l++){cout<<" ";}
		cout<<"*"<<endl;
	}

	for(int j=0;j<stars;j++){cout<<"*";}
	for(int i=0;i<spaces;i++) cout<<" ";
	cout<<"*";

	return 0;
}
