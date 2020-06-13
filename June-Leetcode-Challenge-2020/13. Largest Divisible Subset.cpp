# 13. Largest Divisible Subset

/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:
Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)

Example 2:
Input: [1,2,4,8]
Output: [1,2,4,8]
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector <int> ret;
      int endPoint = 0;
      int retLen = 1;
      int n = nums.size();
      if(!n) return {};
      sort(nums.begin(), nums.end());
      vector <int> len(n, 1);
      vector <int> par(n, 0);
      for(int i = 1; i < n; i++){
         par[i] = i;
         for(int j = 0; j < i; j++){
            if(nums[i] % nums[j] == 0 && len[j] + 1 > len[i]){
               len[i] = len[j] + 1;
               par[i] = j;
            }
         }
         if(len[i] > retLen){
            retLen = len[i];
            endPoint = i;
         }
      }
      ret.push_back(nums[endPoint]);
      while(endPoint != par[endPoint]){
         endPoint = par[endPoint];
         ret.push_back(nums[endPoint]);
      }
      reverse(ret.begin(), ret.end());
      return ret;
        
    }
};
