#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> A(10, 2);
    for(auto num: A){
        cout<<num<<" ";
    }
    return 0;
}