#include "common_hearders.hpp"
#include "utils.hpp"

void insertion_sort(vector<int>& A){
    
}

int main(){
    vector<int> A= rand_vector(10, 20);

    cout<<"\nOriginal vector: \n";
    for(auto num: A){
        cout<<num<<" ";
    }

    insertion_sort(A);

    cout<<"\nVector after sorting: \n";
    for(auto num: A){
        cout<<num<<" ";
    }

    cout<<"\n";
    return 0;
}