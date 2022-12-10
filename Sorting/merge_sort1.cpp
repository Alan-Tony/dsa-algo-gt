#include "../common_headers.hpp"
#include "../utils.hpp"

/*
Optimization 1:
Merge sort without copying A to aux multiple times
*/

void merge_halves(vector<int>& A, vector<int>& aux, int lo, int hi){
    
    int mid= lo + (hi-lo)/2;
    int i= lo, j= mid+1;
    for(int k= lo; k<= hi; k++){

        if(j> hi || i<= mid && A[i]< A[j]){

            aux[k]= A[i++];
        }
        else{
            
            aux[k]= A[j++];
        }
    }

}

void merge_sort_worker(vector<int>& A, vector<int>& aux, int lo, int hi){

    if(lo>= hi){

        return;
    }

    int mid= lo + (hi-lo)/2;
    //Optimization 1: Roles of arrays are skipped via address swapping
    merge_sort_worker(aux, A, lo, mid);
    merge_sort_worker(aux, A, mid+1, hi);

    //We know that the sorted halves are stored in A (aux for the child function)
    merge_halves(A, aux, lo, hi);

}

vector<int> merge_sort(vector<int> A, int lo, int hi){

    vector<int> aux(A);
    merge_sort_worker(A, aux, lo, hi);
    return aux;
}

int main(){

    vector<int> A= rand_vector(1000, 1000);

    cout<<"\nOriginal vector: \n";
    for(auto num: A){
        cout<<num<<" ";
    }

    A= merge_sort(A, 0, A.size()-1);

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

    return 0;
}