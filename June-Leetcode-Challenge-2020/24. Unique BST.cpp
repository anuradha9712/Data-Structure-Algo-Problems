/*

Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

/* Approach:- Find Catalan Number using Binomial Coefficient
Time Complexity:- O(n)*/

class Solution {
public:
    
        // Returns value of Binomial Coefficient C(n, k) 
     long int binomialCoeff(int n, int k) 
    { 
        long int res = 1; 

        // Since C(n, k) = C(n, n-k) 
        if (k > n - k) 
            k = n - k; 

        // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1] 
        for (int i = 0; i < k; ++i) 
        { 
            res *= (n - i); 
            res /= (i + 1); 
        } 

        return res; 
    }
    
    int numTrees(int n) {
         // Calculate value of 2nCn 
        long int c = binomialCoeff(2*n, n); 
  
        // return 2nCn/(n+1) 
        return c/(n+1);
    }
};
