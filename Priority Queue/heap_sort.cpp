#include "../common_headers.hpp"
#include "../utils.hpp"
#include "PriorityQueue.hpp"

void test_heap_sort(int is_min_heap=false){

    Heap *h = new Heap(is_min_heap);

    int size = 100;
    auto t = time(0);
    vector<int> A = rand_vector(size, 10000, t);

    cout<<"\nOriginal vector: \n";
    for(auto num: A){
        cout<<num<<" ";
    }

    // Creating heap
    for(int x : A){

        h->insert(x);
    }

    vector<int> res;
    while(!h->isEmpty()){

        res.push_back(h->pop());
    }
    reverse(res.begin(), res.end());

    cout<<"\nVector after sorting: \n";
    for(auto num: res){
        cout<<num<<" ";
    }

    if(vector_sorted(res) ^ is_min_heap){
        cout<<"\nCheck sorted: success";
    }
    else{
        cout<<"\nCheck sorted: failure";
    }
}

int main(){

    test_heap_sort(false);
    test_heap_sort(true);

    cout<<"\n";
    return 0;
}