#include "common_hearders.hpp"
#include "utils.hpp"

void insertion_sort(vector<int>& A){
    int pos, j;
    for(int i=1; i<A.size(); i++){

        for(j=i-1; j>-1; j--){
            if(A[i]>= A[j]){
                break;
            }
        }

        //Shift elements before insertion
        int pos=j+1;
        int temp= A[i];
        for(j=i; j>=pos+1; j--){
            A[j]= A[j-1];
        }
        //Insertion
        A[pos]= temp;

    }
}

int main(){
    vector<int> A= rand_vector(1000, 200);

    cout<<"\nOriginal vector: \n";
    for(auto num: A){
        //cout<<num<<" ";
    }

    insertion_sort(A);

    cout<<"\nVector after sorting: \n";
    for(auto num: A){
        //cout<<num<<" ";
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