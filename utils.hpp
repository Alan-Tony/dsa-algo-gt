#include "common_hearders.hpp"

//Function to return a vector with random integers
vector<int> rand_vector(int size, int max_val){

    srand(time(0));
    vector<int> A;
    for(int i=0; i<10; i++){
        A.push_back(rand()%20);
    }

    return A;
}