#include "common_headers.hpp"

//Function to return a vector with random integers
vector<int> rand_vector(int size, int max_val, int seed){

    srand(seed);
    vector<int> A;
    for(int i=0; i<size; i++){
        A.push_back(rand()%max_val);
    }

    return A;
}

vector<double> rand_vector_double(int size, double max_val, double min_val, int seed){

    srand(seed);
    vector<double> A;
    for(int i=0; i<size; i++){
        A.push_back(min_val + (double)rand() / RAND_MAX * (max_val - min_val));
    }

    return A;
}

//Function to check if an array is sorted
bool vector_sorted(vector<int> A){

    for(int i=1; i<A.size(); i++){
        if(A[i]< A[i-1]){
            return false;
        }
    }

    return true;
}