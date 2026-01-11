#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int equal_nos(vector<int>&arr){
    int n=arr.size();
    int c2=0;
    int c1=0;
    int count=0;

    unordered_map<int,int>mpp;
    mpp[0]=1;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            c1++;
        }
        else{
            c2++;
        }

        count+=mpp[c2-c1];
        mpp[c2-c1]++;
    }

    return count;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans=equal_nos(arr);
    cout<<"Number of subarrays with equal number of x and y: "<<ans<<endl;
    return 0;
}