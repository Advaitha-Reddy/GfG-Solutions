#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int min_uniq_sum(vector<int>nums,int k){
    int n=nums.size();
    int ans=INT_MAX;

    int i=0;
    unordered_map<int,int>mpp;
    for(int j=0;j<n;j++){
        if(++mpp[nums[j]]==1){
            k-=nums[j];
        }

        while(k<=0){
            ans=min(ans,j-i+1);
            if(--mpp[nums[i]]==0){
                k+=nums[i];
            }
            i++;
        }
    }

    if(ans==INT_MAX){
        return -1;
    }

    return ans;
}


int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int k;
    cin>>k;

    int ans=min_uniq_sum(nums,k);
    cout<<"Minimum lengthed subarray with unique sum of unique elements atleast k: "<<ans<<endl;
    return 0;
}