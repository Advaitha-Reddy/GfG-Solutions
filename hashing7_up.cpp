#include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector<pair<int,int>> cnt_sub(vector<int>arr,int k){
    int n=arr.size();
    int count=0;
    int sum=0;
    map<int,vector<int>>mpp;
    vector<pair<int,int>>vec;

    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==k) vec.push_back({0,i});

        else if(mpp.find(sum-k)!=mpp.end()){
            for(auto&it:mpp[sum-k]){
                vec.push_back({it+1,i});
            }
        }

        mpp[sum].push_back(i);
    }
    
    return vec;
}


int main(){

    int n;
    cout<<"Enter the number of elements : "<<endl;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int k;
    cout<<"Enter the value of k: "<<endl;
    cin>>k;

    vector<pair<int,int>>ans=cnt_sub(arr,k);
    int n1=ans.size();
    for(int j=0;j<n1;j++){
        int l=ans[j].first;
        int r=ans[j].second;

        for(int k=l;k<=r;k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    }
    //int count=cnt_sub(arr,k);
    //cout<<count<<endl;
    return 0;

}