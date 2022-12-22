#include "../common_headers.hpp"
#include "../utils.hpp"

/*
Future scope:
1. Try out different partition schemes
2. Try out optimizations that achieve O(log(n)) complexity (worst case), and other optimizations that include parallelization
*/

/*
There are 2 ../common implementations of this:
1. With pivot as the left most element (more straightforward to me)
2. With pivot as the right most element (a little fancy implementation in Princeton course)
*/
int partition(vector<int> &A, int lo, int hi){

    //Let's go with pivot on the right
    int temp, i=lo, j=lo;
    while(i<=j && i<= hi && j<=hi){
        if(A[j]<A[hi]){
            temp= A[i];
            A[i]= A[j];
            A[j]= temp;
            i++;
        }
        j++;
    }

    temp= A[i];
    A[i]= A[hi];
    A[hi]= temp;

    return i;
}

void quick_sort(vector<int>& A, int lo, int hi){
    if(hi<lo) return;

    int p= partition(A, lo, hi);
    quick_sort(A, lo, p-1);
    quick_sort(A, p+1, hi);
}

int main(){

    auto t= time(0);
    vector<int> A= rand_vector(100, 20, t);

    cout<<"\nOriginal vector: \n";
    for(auto num: A){
        cout<<num<<" ";
    }

    quick_sort(A, 0, A.size()-1);

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