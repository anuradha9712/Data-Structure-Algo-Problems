#include <iostream>
#include <algorithm>
// #include <bits/stdc++.h> 
using namespace std;

int main(){
    int T;
    int caseNo=0;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        caseNo +=1;

        int matrix[N][N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>matrix[i][j];
            }
        }
        int trace = 0;
        for(int k=0;k<N;k++){
            trace += matrix[k][k];
        }
        
        int rowRepeat =0;
        int colRepeat =0;
       
        for(int r=0;r<N;r++){
            unordered_set<int> duplicate;
            bool isRepeated = false;
            
            for(int c=0;c<N;c++){
                if(duplicate.count(matrix[r][c]))
                    isRepeated = true;
                else
                    duplicate.insert(matrix[r][c]);
            }
            if(isRepeated)
                rowRepeat++;
        }
        
          for(int r=0;r<N;r++){
            unordered_set<int> duplicate;
            bool isRepeated = false;

            for(int c=0;c<N;c++){
                if(duplicate.count(matrix[c][r]))
                    isRepeated = true;
                else
                    duplicate.insert(matrix[c][r]);
            }
            if(isRepeated)
                colRepeat++;
        }
        
      
        cout<<"Case #"<<caseNo<<": "<<trace<<" "<<rowRepeat<<" "<<colRepeat;
        cout<<endl;

    }
    return 0;
}