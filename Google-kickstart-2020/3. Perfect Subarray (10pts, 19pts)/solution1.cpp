#include<iostream>
#include<vector>
#include <bits/stdc++.h> 

using namespace std;

int main()
{
    
    int T;
    cin>>T;
    int c=1;
    while(T--){
        
        int N;
        cin>>N;
        vector<int>V;
        
        int sum=0;
        V.push_back(0);
        for(int i=1;i<=N;i++){
            int num;
            cin>>num;
            sum +=num;
            V.push_back(sum);
        }
        
        int result =0;
        for(int i=0;i<N;i++){
            for(int j=i+1;j<=N;j++){
                int diff = V[j]-V[i];
                double s = sqrt(diff);
                if(s== floor(s)) result++;
            }
        }

        
        cout<<"Case #"<<c<<": "<<result<<endl;
        c++;
        
    }
    return 0;

}