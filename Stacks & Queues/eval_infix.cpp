#include "../common_headers.hpp"

/*
1. All operators are considered to be of equal precendence and both ways associative. 
Hence, we chose right to left evaluation

2. Numbers in the expression can be more than 1 digit long
*/

void compute(stack<int>& operands, stack<char>& operators){

    int d1= operands.top();
    operands.pop();

    int d2= operands.top();
    operands.pop();

    char op= operators.top();
    operators.pop();


    switch(op){
        case '+':
        operands.push(d2+d1);
        break;

        case '-':
        operands.push(d2-d1);
        break;

        case '*':
        operands.push(d2*d1);
        break;

        case '/':
        operands.push(d2/d1);
        break;
    }

}

int main(){

    string expr;
    cout<<"\nEnter infix expression: ";
    cin>>expr;

    stack<int> operands;
    stack<char> operators;

    string operand= "";
    for(auto c: expr){
        
        if(isdigit(c)){

            operand+= c;
            continue;
        }
        else if(operand.length()){

            operands.push(stoi(operand));
            operand= "";
        }
        
        if(c == '(' || c == '+' || c == '-' || c == '*' || c == '/'){
            operators.push(c);
        }
        else if(c == ')'){

            while(operators.top() != '('){
                compute(operands, operators);
            }
            operators.pop();
        }
    }

    if(operand.length()){

        operands.push(stoi(operand));
        operand= "";
    }

    while(operators.size()){

        compute(operands, operators);
    }

    cout<<"\nResult= "<<operands.top();
    return 0;
}