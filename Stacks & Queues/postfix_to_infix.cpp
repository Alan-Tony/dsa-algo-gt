#include "../common_headers.hpp"

int main(){

    string expr;
    cout<<"\nEnter postfix expression: ";
    cin>>expr;

    stack<string> st;
    string n1, n2;
    for(auto c: expr){

        if(isalpha(c)){

            st.push(string(1, c));
        }
        else{
            n1= st.top();
            st.pop();

            n2= st.top();
            st.pop();

            st.push('(' + n2 + c + n1 + ')');
        }
    }

    cout<<"\nEquivalent infix expression:\n"<< st.top();

    return 0;
}