#include "common_hearders.hpp"
#include "utils.hpp"

void selection_sort(vector<int>& A){

    int min, temp;
    for(int i=0; i<A.size(); i++){
        min= i;
        for(int j=i+1; j<A.size(); j++){
            if(A[j] < A[min]){
                min= j;
            }
        }

        if(A[min] < A[i]){
            //Swapping positions
            temp= A[i];
            A[i]= A[min];
            A[min]= temp;
        }
    }
}

int main(){

    vector<int> A= rand_vector(10, 20);

    cout<<"\nOriginal vector: \n";
    for(auto num: A){
        cout<<num<<" ";
    }

    selection_sort(A);

    cout<<"\nVector after sorting: \n";
    for(auto num: A){
        cout<<num<<" ";
    }

    cout<<"\n";
    return 0;
}