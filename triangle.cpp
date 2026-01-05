#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int valid_triangles(vector<int>&nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int count=0;
    for(int k=n-1;k>=2;k--){
        int i=0;
        int j=k-1;

        while(i<j){
            if(nums[i]+nums[j]>nums[k]){
                count+=(j-i);
                j--;
            }
            else{
                i++;
            }
        }
    }

    return count;
}


int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int ans=valid_triangles(nums);
    cout<<"Number of valid triangles from the given array: "<<ans<<endl;
    return 0;
}