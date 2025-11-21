#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int maxi_sub(vector<int>&arr,int k){
    int n=arr.size();
    int sum=0;
    int maxi=0;
    unordered_map<int,int>mpp;
    
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==k) maxi=max(maxi,i+1);

        else if(mpp.find(sum-k)!=mpp.end()){
            maxi=max(maxi,i-mpp[sum-k]);
        }

        if(mpp.find(sum)==mpp.end()){
            mpp[sum]=i;
        }
    }

    return maxi;
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
    cout<<"Enter the value of k: "<<endl;
    cin>>k;

    int max_length=maxi_sub(arr,k);
    cout<<"Maximum subarray length with the sum equal to "<<k<<" is: "<<max_length<<endl;
    return 0;
}