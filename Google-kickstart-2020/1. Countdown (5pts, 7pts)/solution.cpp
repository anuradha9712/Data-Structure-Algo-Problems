#include<iostream>
#include<vector>
using namespace std;

int main(){
 
  int T;
  cin>> T;
  int c=1;
  while(T--)
  {
    int N,K;
    cin>>N>>K;
    
    vector<int> V;
    for(int i=1;i<=N;i++){
        int num;
        cin>>num;
        V.push_back(num);
    }
    
    int result = 0;
    for(int i=0;i<N;i++){
        if(V[i]==K){
            int num = K;
            int j=i;
            int len =1;
            while(len!=K){
                if(V[++j]== (--num)) len++;
                else break;
            }
            
            if(len == K) result++;
        }
        
    }
    cout<<"Case #"<<c<<": "<<result<<endl;
    c++;
  }
  
  return 0;

}