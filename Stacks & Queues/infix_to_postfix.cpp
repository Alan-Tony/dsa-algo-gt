#include "../common_headers.hpp"

/*
Precedence chart:
1. '('
2. '^' (By virtue of right to left associativity, the right operator will have a higher precendence if 2 such operators are consecutive)
3 . '+', '-'

Note:
1. All oeprands are letters.
2. Input expression is assumed to be valid.
*/

int prec(char op){

    switch(op){
        case '+':
        case '-':
        return 1;

        case '*':
        case '/':
        return 2;

        case '^':
        return 3;

        case '(':
        return 4;

        default:
        return -1;
    }
}

bool greater_prec(char op, char top_op){

    if(op == top_op && op == '^' ||
    prec(op)> prec(top_op)){

        return true;
    }
    else{

        return false;
    }
}

int main(){

    string expr;
    cout<<"\nEnter infix expression: ";
    cin>>expr;

    stack<char> st;
    string postfix= "";
    for(auto c: expr){

        if(isalpha(c)){

            postfix+= c;
        }
        else if(c == ')'){

            while(st.top() != '('){

                postfix+= st.top();
                st.pop();
            }
            st.pop();
        }
        else if(c == '(' ||
        !st.size() || 
        greater_prec(c, st.top()) ){

            st.push(c);
        }
        else{   //When the precendence of the operator is less than the top of the stack

            while(st.size() &&
            !greater_prec(c, st.top()) &&
            st.top() != '('){
                
                postfix+= st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    //Pop remaining operators from the stack
    while(st.size()){

        postfix+= st.top();
        st.pop();
    }

    cout<<"\nEquivalent postfix expression:\n"<< postfix<< "\n";

    return 0;
}