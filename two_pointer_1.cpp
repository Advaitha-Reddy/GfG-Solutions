#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int subarrays_less_than_k(vector<int>&arr,int k){
    int n=arr.size();
    int count=0;
    int sum=0;
    for(int i=0,j=0;j<n;j++){
        sum+=arr[j];
        while(sum>k){
            sum=sum-arr[i];
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
    int count=subarrays_less_than_k(arr,k);
    cout<<"Number of subarrays with sum less than equal to "<<k<<" : "<<count;
}