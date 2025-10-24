/*

|| Longest Substring with K Uniques ||

You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the length of the longest substring that contains exactly k distinct characters.

Note : If no such substring exists, return -1. 

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longestsubstring(string s,int k){
    int n=s.size();
    int i=0;
    int j=0;

    int count=0;
    int maxSize=-1;
    vector<int>freq(26,0);

    while(j<n){
        freq[s[j]-'a']++;
        if(freq[s[j]-'a']==1) count++;

        while(count>k){
            freq[s[i]-'a']--;
            if(freq[s[i]-'a']==0) count--;
            i++;
        }

        if(count==k){
            maxSize=max(maxSize,j-i+1);
        }
        j++;
    }
    return maxSize;
}

int main(){
    int n;
    string s;
    cout<<"Enter the string: "<<endl;
    getline(cin,s);

    int k;
    cout<<"Enter the value of k: "<<endl;
    cin>>k;

    int answer=longestsubstring(s,k);
    cout<<"The longest substring with exactly "<<k<<" unique characters: "<<answer<<endl;
    return 0;

}