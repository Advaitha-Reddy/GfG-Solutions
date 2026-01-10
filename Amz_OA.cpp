#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int substring(string st,string t){
    unordered_map<char,int>mpp;

    int n=st.size();
    for(int i=0;i<n;i++){
        mpp[st[i]]++;
    }

    map<char,int>mpp2;
    int n1=t.size();
    for(int i=0;i<n1;i++){
        mpp2[t[i]]++;
    }

    int count=INT_MAX;

    for(auto&it:mpp2){
        int need=it.second;
        char ch=it.first;

        count=min(count,mpp[ch]/need);
    }

    return count;
}

int main(){
    string st;
    getline(cin,st);

    string t;
    getline(cin,t);

    int count=substring(st,t);
    cout<<"Answer: "<<count<<endl;
    return 0;
}