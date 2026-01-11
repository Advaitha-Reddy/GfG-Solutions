#include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct hash_pair{
    size_t operator()(const pair<int,int>&p) const{
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
};

int count_subs(vector<int>&nums){
    int n=nums.size();
    int c1=0;
    int c2=0;
    int c3=0;


    unordered_map<pair<int,int>,int,hash_pair>mpp;
    mpp[{0,0}]=1;
    int count=0;


    for(int i=0;i<n;i++){
        if(nums[i]==0){
            c1++;
        }
        else if(nums[i]==1){
            c2++;
        }

        else{
            c3++;
        }

        count+=mpp[{c2-c1,c3-c1}];
        mpp[{c2-c1,c3-c1}]++;
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

    int ans=count_subs(nums);
    cout<<"Number of subarrays with equal numsber of x,y,z: "<<ans<<endl;
    return 0;
}