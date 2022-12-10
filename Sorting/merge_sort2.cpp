#include "../common_headers.hpp"
#include "../utils.hpp"

/*
Bottom up approach (no memory overhead caused by recursion)

+

Optimization 2:
No merging if A[mid]<= A[mid+1]
*/

void merge_sections(vector<int>& A, vector<int>& aux, int lo, int mid, int hi){
    
    if(!(lo<= mid && mid<= hi)){
        return;
    }

    copy(A.begin()+lo, A.begin()+hi+1, aux.begin()+lo);

    int i= lo, j= mid+1;
    for(int k= lo; k<= hi; k++){

        if(j> hi || i<= mid && aux[i]< aux[j]){

            A[k]= aux[i++];
        }
        else{
            
            A[k]= aux[j++];
        }
    }

}

void merge_sort(vector<int>& A, int lo, int hi){

    vector<int> aux(A);
    int mid_chunk;
    for(int sz= 2; sz< 2*(hi-lo+1); sz*= 2){

        for(int lo_chunk=lo; lo_chunk< hi-sz/2+1; lo_chunk+= sz){

            mid_chunk= lo_chunk+sz/2-1;
            if(A[mid_chunk]> A[mid_chunk+1]){   //Optimization 2

                //If there is between a sz/2 and sz chunk left, it is merged with the right half less than or equal to sz/2 in size
                merge_sections(A, aux, lo_chunk, mid_chunk, min(mid_chunk+sz/2, hi));
            }
        }
    }
}

int main(){

    vector<int> A= rand_vector(1000, 1000);

    cout<<"\nOriginal vector: \n";
    for(auto num: A){
        cout<<num<<" ";
    }

    merge_sort(A, 0, A.size()-1);

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