#include "../common_headers.hpp"

class WQUPC{

    vector<int> parent;
    vector<int> weight;
    int N;

    public:
    
    WQUPC(int N){

        this->N= N;
        parent= vector<int>(N, 0);
        for(int i=0; i<N; i++){
            parent[i]= i;
        }
        
        weight= vector<int>(N, 1);
    }

    int find_root(int node){
        
        if(node == parent[node]){
            return node;
        }

        int p= find_root(parent[node]);
        //Path compression
        parent[node]= p;

        return p;
    }

    void node_union(int node1, int node2){

        int p1= find_root(node1), p2= find_root(node2);
        if(p1 == p2){
            //Already in the same component
            return;
        }

        if(weight[p1]>= weight[p2]){

            parent[p2]= p1;
            if(weight[p1] == weight[p2]){
                weight[p1]++;
            }
        }else{

            parent[p1]= p2;
        }
    }
};

int main(){
    
    int n, root, node, node1, node2;
    cout<<"\nEnter the number of nodes: ";
    cin>>n;

    WQUPC *qf = new WQUPC(n);

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