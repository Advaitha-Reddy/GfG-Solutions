#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int subarrays_distinct(vector<int>arr,int k){
    int n=arr.size();
    int count=0;

    unordered_map<int,int>mpp;
    for(int i=0,j=0;j<n;j++){
        mpp[arr[j]]++;

        while(mpp.size()>k){
            mpp[arr[i]]--;
            if(mpp[arr[i]]==0){
                mpp.erase(arr[i]);
            }
            i++;
        }

        count+=(j-i+1);
    }

    return count;
}
int main(){
    int n;
    cout<<"Enter the number of elements: "<<endl;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int count=subarrays_distinct(arr,k);
    cout<<"Number of subarrays with distinct elements less than "<<k<<" : "<<count;
}