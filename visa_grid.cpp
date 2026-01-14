#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>grid(n,vector<int>(m,0));
    vector<vector<bool>>visited(n,vector<bool>(m,false));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    vector<vector<int>>fixed(n,vector<int>(m,0));


    //Mark special cells
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int c=0;
            int u=grid[i][j];
            if(i-1>=0 && u==grid[i-1][j]){
                c++;
            }
            if(i+1<n && u==grid[i+1][j]){
                c++;
            }
            if(j-1>=0 && u==grid[i][j-1]){
                c++;
            }
            if(j+1<m && u==grid[i][j+1]){
                c++;
            }

            if(c>=2){
                fixed[i][j]=1;
            }
        }
    }


    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(fixed[i][j]==1){
                q.push({i,j});
                visited[i][j]=true;
            }
        }
    }

    vector<int>dx={-1,1};
    vector<int>dy={-1,1};

    while(!q.empty()){
        int size=q.size();
        for(int k=0;k<size;k++){
            auto ele=q.front();
            q.pop();

            int r=ele.first;
            int c=ele.second;

            int element=grid[r][c];
            grid[r][c]=0;

            for(auto&r1:dx){
                if(r+r1>=0 && r+r1<n && !visited[r+r1][c] && grid[r+r1][c]==element){
                    q.push({r+r1,c});
                    visited[r+r1][c]=true;
                }
            }

            for(auto&c1:dy){
                if(c+c1>=0 && c+c1<m && !visited[r][c+c1] && grid[r][c+c1]==element){
                    q.push({r,c+c1});
                    visited[r][c+c1]=true;
                }
            }
        }
    }

    //Gravity application

    for(int i=0;i<m;i++){
        int j=0;
        int l=n-1;

        while(j<=l){
            if(grid[j][i]>0 && grid[l][i]==0){
                swap(grid[j][i],grid[l][i]);
                j++;
                l--;
            }
            else if(grid[j][i]==0){
                j++;
            }
            else{
                l--;
            }
        }
    }


    //PRINT THE UPDATED GRID
    cout<<"UPDATED GRID: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;

}