#include<iostream>
#include<vector>
#include <math.h> 

using namespace std;

int score(vector<int>& V , int l , int r){
    
    int result =0;
    for(int i=l;i<=r;i++){
        result += pow(-1,i-l) *V[i-1] * (i-l+1);
    }
    return result;
}

int main(){
    
    int T;
    cin>>T;
    int c=1;
    while(T--){
        int N,Q;
        cin>>N>>Q;
        
        vector<int> V;
        for(int i=1;i<=N;i++){
            int num;
            cin>>num;
            V.push_back(num);
        }
        
        int query[Q][3];
        for(int j=0;j<Q;j++){
            char s;
            int n1 ,n2;
            cin>>s>>n1>>n2;
            if(s=='Q') query[j][0] = 1;
            if(s== 'U') query[j][0] = 0;
            query[j][1] = n1;
            query[j][2] = n2;
        }
        
        int result = 0;
        for(int k=0;k<Q;k++){
            if(query[k][0]==1){
                result +=score(V,query[k][1],query[k][2]);
                //cout<<result<<" ";
            }
            if(query[k][0]==0){
                V[query[k][1]-1] = query[k][2];
                //cout<<V[query[k][1]-1]<<" ";
            }
        }
        
        //cout<<"======="<<endl;
        cout<<"Case #"<<c<<": "<<result<<endl;
        c++;
    }
    
    
    return 0;
    
}