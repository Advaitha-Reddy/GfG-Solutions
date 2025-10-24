#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void kadane_print(vector<int>arr){
    int n=arr.size();
    int curr=arr[0];
    vector<int>prefixSum(n);
    int maxsum=INT_MIN;
    int s=0,end=0,start=0;

    for(int i=1;i<n;i++){
        if(curr+arr[i]<arr[i]){
            curr=arr[i];
            s=i;
        }
        else{
            curr=curr+arr[i];
        }

        prefixSum[i]=max(prefixSum[i-1],curr);

        if(prefixSum[i]>prefixSum[end]){
            end=i;
            start=s;
        }
        
    }

    for(int i=start;i<=end;i++){
        cout<<arr[i]<<" ";
    }
    
}

int main(){
    int n;
    cout<<"Enter the number of elements in the array: "<<endl;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    kadane_print(arr);
    return 0;
}