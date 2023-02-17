//
//  main.cpp
//  Floyd warshall Algorithm
//
//  Created by Harsh Gupta on 01/12/22.
//

#include <iostream>
#include <vector>
using namespace std;

void floyd(vector<vector<int>>&matrix){
    unsigned long n=matrix.size();
    //    int n=matrix.size();
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(matrix[i][j]==-1)
                matrix[i][j]=1e9;
            if(i==j) matrix[i][j]=0;
        }
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(matrix[i][j]==1e9)
                matrix[i][j]=-1;
        }
}
int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    int V;
    cin>>V;
    vector<vector<int>>matrix(V,vector<int>(V,-1));
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
        {
            cin>>matrix[i][j];
        }
    floyd(matrix);
    for(int i=0;i<V;i++){
//        cout<<"|-|-|-|-|-|-|-|-|-|"<<endl;
        for(int j=0;j<V;j++)
            cout<<matrix[i][j]<<"|";
        cout<<endl;
    }
    
    return 0;
}


//    input test case--------
//
//    12
//    0 4 2 1 2 9 4 8 -1 4 -1 -1
//    9 0 3 6 2 6 2 3 6 -1 -1 3
//    7 1 0 10 8 9 1 3 -1 7 -1 10
//    5 1 9 0 3 -1 1 10 7 1 -1 7
//    -1 5 1 4 0 2 10 4 10 6 4 5
//    7 8 3 7 5 0 5 1 3 5 7 2
//    6 -1 6 1 10 7 0 10 -1 -1 7 7
//    -1 3 2 7 4 -1 4 0 10 5 6 10
//    10 6 1 10 4 4 7 10 0 4 7 4
//    1 1 6 8 8 9 2 10 6 0 -1 3
//    5 9 3 -1 4 3 -1 -1 -1 3 0 1
//    2 2 8 6 2 4 4 3 -1 3 4 0
