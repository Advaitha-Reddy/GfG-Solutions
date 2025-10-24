/*

Given a sorted integer array arr[] and an integer k, determine if it is possible to split the array into one or more consecutive subsequences such that:

Each subsequence consists of consecutive integers (each number is exactly one greater than the previous).
Every subsequence has a length of at least k.
Return true if such a split is possible, otherwise return false.

*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>arr,int k){
    int n=arr.size();
    unordered_map<int,int>freq;
    unordered_map<int,int>need;

    for(int x:arr){
        freq[x]++;
    }

    for(int x:arr){
        if(freq[x]==0) continue;

        if(need[x]>0){
            need[x]--;
            need[x+1]++;
        }
        else{
            for(int i=0;i<k;i++){
                if(freq[x+i]==0) return false;
                freq[x+i]--;
            }
            need[x+k]++;
            continue;
        }
        
        freq[x]--;
    }
    return true;
}

int main(){
    int n;
    cout<<"Enter the number of elements in the array: "<<endl;
    cin>>n;

    int k;
    cout<<"Enter the value of k: "<<endl;
    cin>>k;

    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    bool res=isPossible(arr,k);
    if(res==true){
        cout<<"Yayyy split is possible!!!"<<endl;
    }
    else{
        cout<<"Ohh Noo!!! Split is not possible"<<endl;
    }
}