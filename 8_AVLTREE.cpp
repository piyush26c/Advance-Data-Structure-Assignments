//
// Created by piyush on 4/4/19.
//


#include<iostream>
using namespace std;

struct tnode
{
    string data;
    string mean;
    tnode *L,*R;
};

class AVL
{
private:
    tnode *root;

public:
    AVL()
    {
        root = NULL;
    }

    void createAVLTree();
    void displayAVLTree();
    tnode *insert(tnode *,string,string);
    void inorderTraversalAVLTree(tnode *temp);
    void preorderTraversalAVLTree(tnode *temp);
    int calculateHeight(tnode *temp);
    int MAX(int,int);
    tnode * LL(tnode *);
    tnode * RR(tnode *);
    tnode * LR(tnode *);
    tnode * RL(tnode *);

};

tnode * AVL :: LL(tnode *parent)
{
    tnode *temp;
    temp=  parent->L;
    parent->L = temp->R;
    temp->R = parent;
    return temp;
}

tnode * AVL :: RR(tnode *parent)
{
    tnode *temp;
    temp = parent->R;
    parent->R = temp->L;
    temp->L = parent;
    return temp;
}

tnode * AVL :: LR(tnode *parent)
{
    parent->L = RR(parent->L);

    parent = LL(parent);

    return parent;
}

tnode * AVL :: RL(tnode *parent)
{
    parent->R = LL(parent->R);

    parent = RR(parent);

    return parent;
}


int AVL :: MAX(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int AVL :: calculateHeight(tnode *temp)
{
    if(temp == NULL)
        return -1;

    if(temp->L == NULL && temp->R == NULL)
        return 0;

    return(1 + MAX(calculateHeight(temp->L), calculateHeight(temp->R)));
}

void AVL :: inorderTraversalAVLTree(tnode *temp)
{
    if(temp != NULL)
    {
        inorderTraversalAVLTree(temp->L);
        cout<<"\n"<<temp->data<<"\t"<<temp->mean;
        inorderTraversalAVLTree(temp->R);
    }
}

tnode * AVL :: insert(tnode *temp,string val,string mval)
{
    if(temp == NULL)
    {
        temp = new tnode;
        temp->data = val;
        temp->mean= mval;
        temp->L = temp->R = NULL;

    }
    else
    {
        if(val < temp->data)
        {
            temp->L = insert(temp->L,val,mval);
            if( (calculateHeight(temp->L) - calculateHeight(temp->R)==2) )
            {
                if(val < temp->L->data)
                    temp = LL(temp);
                else
                    temp = LR(temp);
            }
        }
        else
        {
            temp->R = insert(temp->R,val,mval);
            if( (calculateHeight(temp->L) - calculateHeight(temp->R)==-2) )
            {
                if(val > temp->R->data)
                    temp = RR(temp);
                else
                    temp = RL(temp);
            }
        }
    }
    return temp;
}

void AVL :: displayAVLTree()
{
    cout<<"\n Dictionary Data in Sorted way";
    inorderTraversalAVLTree(root);
    cout<<"\n Preorder";
    preorderTraversalAVLTree(root);

}

void AVL :: createAVLTree()
{
    string val,mval;
    char ch;
    do
    {
        cout<<"Enter word & Meaning";
        cin>>val>>mval;
        root = insert(root,val,mval);
        cout<<"Continue";
        cin>>ch;
    }while(ch=='y');
}


void AVL :: preorderTraversalAVLTree(tnode *temp)
{
    if(temp != NULL)
    {
        cout<<"\t"<<temp->data;
        preorderTraversalAVLTree(temp->L);
        preorderTraversalAVLTree(temp->R);
    }
}

int main()
{

    AVL t;
    t.createAVLTree();
    t.displayAVLTree();
    return 0;

}