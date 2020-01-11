//
// Created by piyush on 4/4/19.
//

#include<bits/stdc++.h>
using namespace std;

struct node
{
    char optr;
    node *l;
    node *r;
};

class stack1
{
public :
    node *stck[20], *m;
    int top;


    stack1()
    {
        top = -1;
    }

    void push(node *p)
    {
        ++top;
        stck[top] = p;
    }

    bool isstackempty()
    {
        if(top == -1)
            return true;
        else
            return false;
    }

    bool isstackfull()
    {
        if(top == 20)
            return true;
        else
            return false;

    }


    node* pop()
    {
        return stck[top--];
    }

    node* gettop()
    {
        if(!isstackempty())
            return stck[top];
        else
            return NULL;
    }

};

class exptree
{
public :
    char exp[20];

    int  priority(char ch);
    void getExpression();
    void createxptree();
    stack1 operand,optor;        //this stacks are for computing in creation of expression tree
    stack1 s1,s2;                //this stacks are for postorder traversal
    node *root;
    void pos_dis(node *t);       //recursive fuction for postorder traversal
    void pos_dis_nonrec();       //non-recursive function for postorder traversal

};

void exptree :: getExpression()
{
    cout << "\n Enter the expression : ";
    cin >> exp;
}

int exptree :: priority(char ch)
{

    switch(ch)
    {
        case '-' :
            return 1;
        case '+' :
            return 1;
        case '*' :
            return 2;
        case '/' :
            return 2;
    }

}


void exptree :: createxptree()
{

    node *nn, *temp;
    for(int i = 0; exp[i] != '\0'; i++)
    {
        nn = new node;
        nn->l = NULL;
        nn->r = NULL;
        nn->optr = exp[i];
        if(nn->optr == '+' || nn->optr == '-' || nn-> optr == '*' || nn->optr == '/')
        {
            if(optor.isstackempty())
            {
                optor.push(nn);
            }
            else
            {
                if(priority((optor.gettop())->optr) >= priority(nn->optr))
                {
                    temp = optor.pop();
                    temp->r = operand.pop();
                    temp->l = operand.pop();
                    operand.push(temp);
                    optor.push(nn);

                }
                else
                {
                    optor.push(nn);

                }


            }


        }
        else
        {
            operand.push(nn);
        }

    }


    while(!optor.isstackempty())
    {
        node *t = optor.pop();
        t->r = operand.pop();
        t->l = operand.pop();
        operand.push(t);

    }

    root = operand.gettop();

    //cout << root->r << endl;
}

void exptree :: pos_dis(node *t)
{
    if(t != NULL)
    {
        pos_dis(t->l);
        pos_dis(t->r);
        cout << t->optr << " ";

    }

}

void exptree ::pos_dis_nonrec() {

    //s1 stack is for computing and s2 stack is our display stack
    node *tptr;
    tptr = root;        //root contains address of very first node address

    do{

        //traversing to very right node of tree
        while(tptr != NULL){
            s1.push(tptr);
            s2.push(tptr);
            tptr = tptr->r;
        }

        tptr = s1.pop();

        //finding the node which has left child
        while(!s1.isstackempty() && tptr->l == NULL){
            tptr = s1.pop();
        }


        //after getting node who is having left child point to that left child
        tptr = tptr->l;
        //and again repeat the same procedure till the stack1 gets empty or nodes are over
    }while(!s1.isstackempty() || tptr != NULL);


    //printing the output stack
    cout << "\nPostfix Expression : ";
    do{
        tptr = s2.pop();
        cout << tptr->optr << " ";
    }while(!s2.isstackempty());

}


int main()
{
    exptree exp1;


    int sw,dw;

    do{
        dw = 1;
        cout << "\n(1). To get infix expression ";
        cout << "\n(2). To display postfix expression ";
        cout << "\n(3). To Exit";
        cin >> sw;
        switch(sw){

            case 1:
                exp1.getExpression();
                exp1.createxptree();
                break;

            case 2:
                exp1.pos_dis_nonrec();
                //exp1.pos_dis(exp1.root);

                break;

            case 3:
                dw = 0;
                break;

            default:
                cout << "\nInvalid Input!!!";

        }
    }while(dw);

    return 0;
}
