//
// Created by piyush on 4/4/19.
//


#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    int lth,rth;
    node *l, *r;
};

class ThreadedBinaryTree
{
public :
    node *dummy, *nn, *root;

    //constructor
    ThreadedBinaryTree()
    {
        dummy = new node;
        dummy->data = -10000;
        dummy->l = dummy->r = NULL;
        dummy->lth = dummy->rth = 0;
        root = NULL;

    }

    void createThreadedBinaryTree();
    void inorderTraversalOfBinaryTree();
    void preorderTraversalOfBinaryTree();
    void postorderTraversalOfBinaryTree();


};

void ThreadedBinaryTree :: createThreadedBinaryTree()
{
    nn = new node;
    cin >> nn->data;
    nn->lth = nn->rth = 0;
    nn->l = nn->r = NULL;

    if(root == NULL)
    {
        root = nn;
        dummy->l = root;
        root->l = root->r = dummy;
    }
    else
    {
        node *temp, *parent;

        temp = root;

        while(temp != NULL)
        {
            parent = temp;

            if(nn->data < temp->data)
            {
                if(temp->lth == 1)
                {
                    temp = temp->l;

                }
                else
                {
                    temp = NULL;
                }

            }
            else
            {
                if(temp->rth == 1)
                {
                    temp = temp->r;
                }
                else
                {
                    temp = NULL;
                }

            }
        }


        if(nn->data < parent->data)
        {
            nn->l = parent->l;
            nn->r = parent;
            parent->lth = 1;
            parent->l = nn;
        }
        else
        {
            nn->r = parent->r;
            nn->l = parent;
            parent->rth = 1;
            parent->r = nn;
        }


    }

}

void ThreadedBinaryTree :: inorderTraversalOfBinaryTree()
{
    node *temp;
    temp = root;


    while(1)
    {
        while(temp->lth == 1)
            temp = temp->l;

        cout << temp->data << " " ;

        while(temp->rth == 0)
        {
            if(temp->r == dummy)
            {
                return;

            }
            else
            {
                temp = temp->r;

            }
            cout << temp->data << " ";

        }

        temp = temp->r;
    }



}

void ThreadedBinaryTree :: preorderTraversalOfBinaryTree()
{
    node *temp;
    temp = root;

    while(1)
    {
        while(temp->lth == 1)
        {
            cout << temp->data << " ";
            temp = temp->l;

        }

        cout << temp->data << " ";

        while(temp->rth == 0)
        {
            if(temp->r == dummy)
                return;
            else
                temp = temp->r;

        }

        temp = temp->r;

    }
}


/*void tbt :: postorder()
{
    node *temp;
    temp = root;

    while(1)
    {
        while(temp->lth == 1)
        {

            temp = temp->l;

        }


        cout << temp->data << " ";

        while(temp->rth == 0)
        {
            cout << temp->r->data << " ";
            if(temp->r == dummy)
                return;
            else
                temp = temp->r;

            cout << temp->data << " ";
        }

        temp = temp->r;

    }
}*/


int main()
{
    ThreadedBinaryTree t1,t2,t3;
    cout << "\nThreaded Binary Search Tree : " << endl;
    int v,c;

    do
    {
        c = 1;
        cout << "(1). To Insert Data " << endl;
        cout << "(2). To Display(Inorder) " << endl;
        cout << "(3). To Display(Preorder) " << endl;
        // cout << "(4). To Display(Postorder) " << endl;
        cout << "(5). To Exit " << endl;
        cout << "\nEnter your choice : ";
        cin >> v;

        switch(v)
        {
            case 1 :
                t1.createThreadedBinaryTree();
                t2 = t1;
                t3 = t1;
                break;

            case 2 :
                t1.inorderTraversalOfBinaryTree();
                cout << endl;
                break;

            case 3 :
                t2.preorderTraversalOfBinaryTree();
                cout << endl;
                break;

            case 4 :
                t3.postorderTraversalOfBinaryTree();
                cout << endl;
                break;

            case 5 :
                c = 0;
                break;


        }

    }while(c);


    return 0;
}



