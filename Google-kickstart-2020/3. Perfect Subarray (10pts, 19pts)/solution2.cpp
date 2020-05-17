#include<iostream>
#include<vector>
#include <bits/stdc++.h> 

using namespace std;

bool isPerfectSquare(int num){
    /*
    if(num == 1 || num==0)
        return true;
        
        long l=1 , r=num;
        while(l<= r){
            long mid = l + ((r-l)/2);
            long s = mid*mid;
            if(s== num)
                return true;
            if(s<num)
                l = mid+1;
            else
                r = mid-1;
        }
    return false;*/
      long double sr = sqrt(num); 
  
    // If square root is an integer 
    return ((sr - floor(sr)) == 0); 
}

int main()
{
    
    int T;
    cin>>T;
    int c=1;
    while(T--){
        int N;
        cin>>N;
        vector<int>V;
        for(int i=0;i<N;i++){
            int num;
            cin>>num;
            V.push_back(num);
        }
        
        int result = 0;
        for(int i=0;i<N;i++){
            int sum = 0;
            for(int j=i;j<N;j++){
                sum+=V[j];
                if(isPerfectSquare(sum)) result++;
            }
        }
        
        cout<<"Case #"<<c<<": "<<result<<endl;
        c++;
        
    }
    return 0;

}