#include "../common_headers.hpp"

class Heap{

    vector<int> pq;
    int N;
    bool is_min_heap;

    // If the given index violates order by being less than its children
    void sink(int pos){

        assert(pos >= 0 && pos < N);

        int temp, p1, p2, max_pos;
        while(true){

            p1 = pos*2 + 1;
            p2 = p1 + 1;

            if(p1 >= N){

                return;
            }

            if(p2 >= N){

                max_pos = p1;
            }
            else{

                max_pos = pq[p1] > pq[p2] ? p1 : p2;
            }

            if(pq[max_pos] <= pq[pos]){

                return;
            }

            temp = pq[pos];
            pq[pos] = pq[max_pos];
            pq[max_pos] = temp;
            pos = max_pos;
        }
    }

    // If the given index violates order by being geater than its parent
    void swim(int pos){

        assert(pos >= 0 && pos < N);

        int temp;
        while(pq[pos] > pq[(pos-1)/2]){

            temp = pq[pos];
            pq[pos] = pq[(pos-1)/2];
            pq[(pos-1)/2] = temp;
            pos = (pos-1)/2;
        }
    }

    public:

    // Constructor
    Heap(bool is_min_heap = false){

        this->is_min_heap = is_min_heap;
        N = 0;
    }

    bool isEmpty(){

        return N == 0;
    }

    void insert(int x){

        if(is_min_heap){

            x = -x;
        }

        pq.push_back(x);
        N++;
        swim(N-1);
    }

    int pop(){

        assert(!isEmpty());

        int temp = pq[N-1];
        pq[N-1] = pq[0];
        pq[0] = temp;

        int res = pq[N-1];
        N--;
        if(!isEmpty()){

            sink(0);
        }

        if(is_min_heap){

            res = -res;
        }
        return res;
    }
};