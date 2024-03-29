#include "../common_headers.hpp"
#include "../utils.hpp"

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

    auto t= time(0);
    vector<int> A= rand_vector(100, 20, t);

    cout<<"\nOriginal vector: \n";
    for(auto num: A){
        cout<<num<<" ";
    }

    selection_sort(A);

    cout<<"\nVector after sorting: \n";
    for(auto num: A){
        cout<<num<<" ";
    }

    if(vector_sorted(A)){
        cout<<"\nCheck sorted: success";
    }
    else{
        cout<<"\nCheck sorted: failure";
    }

    cout<<"\n";
    return 0;
}