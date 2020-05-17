#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

bool isValid(int kStart,int kEnd,int pStart,int pEnd){
    if((kStart< pStart && kEnd < pStart) || pEnd<=kStart)
        return true;
    else
        return false;
}

int main(){
    int T;
    int caseNo=0;
    cin>>T;
    
    while(T--){
        
        int N;
        cin>>N;
        
        if(N>=2){
            caseNo +=1;
            vector< pair <int,int> > vect;
            
            for(int i=1;i<=N;i++){
                int start ,end;
                cin>>start>>end;
                vect.push_back( make_pair(start,end) ); 
            }
        
            string result ="J";
            int j_endTime = vect[0].second;
            int j_startTime = vect[0].first;
            int c_endTime =0;
            int c_startTime = 0;
        
            for(int i=1; i<N; i++){
                //if valid for J
                if(isValid(vect[i].first,vect[i].second,j_startTime,j_endTime)){
                    result+="J";
                    j_endTime = max(vect[i].second,j_endTime);
                    j_startTime = max(vect[i].first,j_startTime);
    
                }
                //if valid for C
                else if(isValid(vect[i].first,vect[i].second,c_startTime,c_endTime)){
                    result+="C";
                    c_endTime = max(vect[i].second,c_endTime);
                    c_startTime = max(vect[i].first,c_startTime);
    
                }
                else{
                    result = "IMPOSSIBLE";
                }    
            }
            cout<<"Case #"<<caseNo<<": "<<result;
            cout<<endl;
        }
    }
    return 0;
}