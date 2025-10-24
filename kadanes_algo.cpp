#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int>arr){
    int n=arr.size();
    vector<int>prefixSum(n);
    int curr=arr[0];
    prefixSum[0]=arr[0];

    for(int i=1;i<n;i++){
        curr=max(curr+arr[i],arr[i]);
        prefixSum[i]=max(prefixSum[i-1],curr);
    }

    int maxsum=INT_MIN;
    for(int i=0;i<n;i++){
        maxsum=max(maxsum,prefixSum[i]);
    }

    return maxsum;
}

int main(){
    int n;
    cout<<"Enter the number of elements in the array: "<<endl;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Maximum subarray sum generated from the given array is: "<<kadane(arr)<<endl;
    return 0;
}