#include "../common_headers.hpp"

/*
Required functionalities:

1. qf.find(node1)
2. qf.union(node1, node2)

*/

class QuickFind{
    vector<int> root;
    int N;

    public:
    QuickFind(int N){
        this->N = N;
        root= vector<int>(N, 0);
        for(int i=0; i<N; i++){
            root[i]= i;
        }
    }

    int find_root(int p){
        if(p>= this->N){
            return -1;
        }

        return root[p];
    }

    void node_union(int p1, int p2){
        if(p1>= this->N || p2>= this->N || p1 == p2){
            return;
        }

        int new_root= root[p2], old_root= root[p1];
        for(int i=0; i<this->N; i++){
            if(root[i] == old_root){
                root[i]= new_root;
            }
        }
    }
};

int main(){
    
    int n, root, node, node1, node2;
    cout<<"\nEnter the number of nodes: ";
    cin>>n;

    QuickFind *qf = new QuickFind(n);

    int option;
    while (true){

        cout<<"\n1. Display roots.\n2. Find root.\n3. Union nodes.\nEnter option: ";
        cin>>option;

        switch (option){

            case 1:
            cout<<"\nNode\tRoot";
            for(int i=0; i<n; i++){
                root= qf->find_root(i);
                cout<<"\n"<<i<<"\t"<<root;
            }
            break;

            case 2:
            cout<<"\nEnter node number: ";
            cin>>node;
            cout<<"\nRoot of "<<node<<"= "<<qf->find_root(node);
            break;

            case 3:
            cout<<"\nEnter node 1: ";
            cin>>node1;
            cout<<"\nEnter node 2: ";
            cin>>node2;
            qf->node_union(node1, node2);
            break;
            
            default:
            cout<<"\nInvalid option";
        }
    }
    return 0;
}