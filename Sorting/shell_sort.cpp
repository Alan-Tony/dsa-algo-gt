#include "../common_headers.hpp"
#include "../utils.hpp"

vector<int> increment_seq(int N){

    int choice;
    cout<<"\n1. 3x + 1\nEnter choice: ";
    cin>>choice;

    vector<int> seq;
    switch (choice)
    {

        case 1:
        default:
        int x=1;
        do{
            seq.push_back(x);
            x= 3*x + 1;
        }while(x < N);
    }

    return seq;
}

void shell_sort(vector<int>& A){

    vector<int> seq= increment_seq(A.size());
    int h, pos, temp, k;
    for(int i=seq.size()-1; i>=0; i--){

        h= seq[i];
        //h-sorting for each value of h in the sequence
        for(int j=h; j<A.size(); j++){
            
            //Find correct position in the subsequence
            pos= j;
            while(pos>= h && A[j]< A[pos-h]){

                pos-= h;
            }

            //Moving A[j] to the position
            temp= A[j];
            k= j;
            while(k> pos){

                A[k]= A[k-h];
                k-= h;
            }
            A[pos]= temp;
        }
    }

}

int main(){

    vector<int> A= rand_vector(1000, 100);

    cout<<"\nOriginal vector: \n";
    for(auto num: A){
        cout<<num<<" ";
    }

    shell_sort(A);

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