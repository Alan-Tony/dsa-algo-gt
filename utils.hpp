#include "common_hearders.hpp"

//Function to return a vector with random integers
vector<int> rand_vector(int size, int max_val){

    srand(time(0));
    vector<int> A;
    for(int i=0; i<size; i++){
        A.push_back(rand()%max_val);
    }

    return A;
}

//Function to check if an array is sorted
bool vector_sorted(vector<int> A){
    if(A.size()<=1){
        return true;
    }

    for(int i=1; i<A.size(); i++){
        if(A[i]< A[i-1]){
            return false;
        }
    }

    return true;
}