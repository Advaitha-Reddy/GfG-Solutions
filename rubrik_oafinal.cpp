#include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct hash_pair{
    size_t operator()(const vector<int>&vec) const{
        size_t h1=hash<int>()(vec[0]);
        size_t h2=hash<int>()(vec[1]);
        size_t h3=hash<int>()(vec[2]);
        size_t h4=hash<int>()(vec[3]);
        
        return h1^(h2<<2)^(h3<<3)^(h4<<4);
    }
};
int count_subs(vector<int>&nums){
    int n=nums.size();

    int c1=0;
    int c2=0;
    int c3=0;
    int c4=0;
    int c5=0;
    int count=0;

    unordered_map<vector<int>,int,hash_pair>mpp;
    mpp[{0,0,0,0}]=1;

    for(int i=0;i<n;i++){
        if(nums[i]==0){
            c1++;
        }

        else if(nums[i]==1){
            c2++;
        }

        else if(nums[i]==2){
            c3++;
        }

        else if(nums[i]==3){
            c4++;
        }

        else if(nums[i]==4){
            c5++;
        }

        count+=mpp[{c2-c1,c3-c1,c4-c1,c5-c1}];
        mpp[{c2-c1,c3-c1,c4-c1,c5-c1}]++;
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