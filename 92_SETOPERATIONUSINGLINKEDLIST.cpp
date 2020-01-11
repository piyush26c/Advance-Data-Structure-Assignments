/*
//
// Created by piyush on 4/4/19.
//

#include<bits/stdc++.h>
using namespace std;
#define SIZE 20

struct node
{
    int data;
    node* next;

};

class SetUsingLinkedList
{
public :
    node *head;
    SetUsingLinkedList()
    {
        head = NULL;
    }
    void createSet();
    void displaySet();




};


void SetUsingLinkedList :: displaySet()
{

    node *cn;
    cn = head;

    while(cn != NULL)
    {
        cout << cn->data << " ";
        cn=cn->next;
    }

}

void SetUsingLinkedList :: createSet()
{
    char ch;
    node *nn,*cn;


    do
    {
        nn = new node;
        nn->next = NULL;

        cout << "\nEnter the element : ";
        cin >> nn->data;

        if(head == NULL)
        {
            head = nn;

        }
        else
        {

            cn = head;
            while(cn->next != NULL)
            {
                cn = cn->next;
            }

            cn->next = nn;

        }


        cout << "\nDo you want to enter another entry ?";
        cin >> ch;

    }while(ch == 'Y' || ch == 'y');




}

int main()
{

    SetUsingLinkedList sA,sB;
    int sw,dw;

    do
    {
        dw = 1;

        cout << "\nEnter (1). To insert element in sets";
        cout << "\nEnter (2). To display elements of set";
        cout << "\nEnter (3). To Exit";
        cin >> sw;

        switch(sw)
        {
            case 1 :
                cout << "\nInserting Elements in Set A : ";
                sA.createSet();
                cout << "\nInserting Elements in Set B : ";
                sB.createSet();
                break;

            case 2 :
                cout << "\nDisplaying Set A  : ";
                sA.displaySet();
                cout << "\nDisplaying Set B  : ";
                sB.displaySet();
                break;

            case 3 :
                dw = 0;
                break;

            default :
                cout << "\nInvalid Entry!!";


        }





    }while(dw);


    return 0;
}







*/

//Mayuresh code mine is incomplete

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

class set1
{
public: node *nn,*cn,*temp,*header,*hu,*hin,*honA,*honB;
    char z;
    int flag;
    set1()
    {
        nn=cn=header=hu=hin=honA=honB=NULL;
    }
    void insert()
    {
        do
        {
            nn=new node;
            nn->next=NULL;
            cout<<"\nEnter the element in the set :";
            cin>>nn->data;

            if(header==NULL)
            {
                header=nn;
            }
            else
            {
                cn=header;
                while(cn->next!=NULL)
                {
                    cn=cn->next;
                }
                cn->next=nn;

            }
            cout<<"\nWant to insert another element in the set (Y/N):";
            cin>>z;
        }while(z=='Y'||z=='y');
    }

    void display(node *cn)
    {
        cout<<"{";
        while(cn!=NULL)
        {
            cout<<cn->data<<",";
            cn=cn->next;
        }
        cout<<"}"<<endl;
    }

    int search(node *temp,int key)
    {
        cn=temp;
        while(cn!=NULL)
        {
            if(cn->data==key)
            {
                cout<<"\nElement found :"<<cn->data<<endl;
                return 1;
            }
            cn=cn->next;
        }
        return 0;
    }

    void unionf(node *h1,node *h2) //A==h1=s1.header==temp1==cn1 , B==h2=s2.header==temp2==cn2
    {
        node* cn1=h1;   //IMPORTANT A
        node* cn2=h2;   //IMPORTANT B

        while(cn1!=NULL)
        {
            nn=new node;
            nn->next=NULL;

            nn->data=cn1->data;
            cn1=cn1->next;              //IMP

            if(hu==NULL)  //s3.hu
            {
                hu=nn;
            }
            else
            {
                temp=hu;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=nn;
            }
        }

        node *temp1=h1;    //A     //IMPORTANT
        node *temp2=h2;    //B     //IMPORTANT
        while(temp2!=NULL)
        {
            flag=0;
            //each ele of B(temp2) is compared to all ele of A(temp1)
            while(temp1!=NULL)
            {
                if(temp2->data==temp1->data)
                {
                    flag=1;
                    break;
                }

                temp1=temp1->next;
            }
            if(flag==0)
            {
                nn=new node;
                nn->next=NULL;
                nn->data=temp2->data;

                if(hu==NULL)
                    hu=nn;
                else
                {
                    temp=hu;
                    while(temp->next!=NULL)
                    {
                        temp=temp->next;
                    }
                    temp->next=nn;
                }
            }
            temp2=temp2->next;  //IMPORTANT
        }

    }

    void interf(node *h1,node *h2) //A==h1=s1.header==temp1 , B==h2=s2.header==temp2
    {
        node* temp1=h1;


        while(temp1!=NULL)
        {
            node* temp2=h2;
            flag=0;
            //each ele of A(temp1) is compared to all ele of B(temp2)
            while(temp2!=NULL)
            {
                if(temp1->data==temp2->data)
                {
                    flag=1;
                    break;
                }

                temp2=temp2->next;
            }
            if(flag==1)
            {
                nn=new node;
                nn->next=NULL;
                nn->data=temp2->data;

                if(hin==NULL)
                    hin=nn;
                else
                {
                    temp=hin;
                    while(temp->next!=NULL)
                    {
                        temp=temp->next;
                    }
                    temp->next=nn;
                }
            }

            temp1=temp1->next;  //IMPORTANT
        }
    }

    void onlyA(node *h1,node *h2) //A==h1=s1.header==temp1 , B==h2=s2.header==temp2
    {
        node* temp1=h1;


        while(temp1!=NULL)
        {   node* temp2=h2;
            flag=0;
            //each ele of A(temp1)is compared to all ele of B & if it is not present in B(temp2) then onlt put that element of A in onlyA(honA)set
            while(temp2!=NULL)
            {
                if(temp1->data==temp2->data)
                {
                    flag=1;
                    break;
                }

                temp2=temp2->next;
            }
            if(flag==0)
            {
                nn=new node;
                nn->next=NULL;
                nn->data=temp1->data;

                if(honA==NULL)
                    honA=nn;
                else
                {
                    temp=honA;
                    while(temp->next!=NULL)
                    {
                        temp=temp->next;
                    }
                    temp->next=nn;
                }
            }

            temp1=temp1->next;  //IMPORTANT
        }

    }

    void onlyB(node *h1,node *h2) //A==h1=s1.header==temp1 , B==h2=s2.header==temp2
    {
        node* temp2=h2;

        while(temp2!=NULL)
        {
            node* temp1=h1;
            flag=0;
            //each ele of B(temp2)is compared to all ele of A & if it is not present in A(temp1) then onlt put that element of B in onlyB(honB)set
            while(temp1!=NULL)
            {
                if(temp2->data==temp1->data)
                {
                    flag=1;
                    break;
                }

                temp1=temp1->next;
            }
            if(flag==0)
            {
                nn=new node;
                nn->next=NULL;
                nn->data=temp2->data;

                if(honB==NULL)
                    honB=nn;
                else
                {
                    temp=honB;
                    while(temp->next!=NULL)
                    {
                        temp=temp->next;
                    }
                    temp->next=nn;
                }
            }

            temp2=temp2->next;  //IMPORTANT
        }

    }

    void subset(node* h1,node* h2)
    {
        //cheacking whether A is subset of B

        node* temp1=h1;

        while(temp1!=NULL)
        {  node* temp2=h2;
            flag=0;
            while(temp2 != NULL)
            {
                if(temp1->data==temp2->data)
                {
                    temp1=temp1->next;
                    flag=1;
                }
                temp2=temp2->next;
            }
            if(flag==0)
            {
                cout<<"\nA is not subset of B"<<endl;
                break;
            }
        }
        if(flag==1)
            cout<<"\nA is subset of B"<<endl;


        node* temp2=h2;

        //cheacking whether B is subset of A
        while(temp2 != NULL)
        {
            node* temp1=h1;
            flag=0;
            while(temp1!=NULL)
            {
                if(temp2->data==temp1->data)
                {
                    temp2=temp2->next;
                    flag=1;
                }
                temp1=temp1->next;
            }
            if(flag==0)
            {
                cout<<"\nB is not subset of A"<<endl;
                break;
            }
        }
        if(flag==1)
            cout<<"\nB is subset of A"<<endl;
    }
};

int main()
{
    set1 s1,s2,s3;  //s1==set A  ,  s2==set B ,s3 is used for calling functions
    int flag,ch,key,temp;
    char z;

    do
    {
        cout<<"\n*********** SET OPERATIONS BY LINKED-LIST**********\n";

        cout<<"\nEnter";
        cout<<"\n1.Inserting elements in the two sets (A,B)";
        cout<<"\n2.Displaying that two sets (A,B)";
        cout<<"\n3.To search an element in set A or B";
        cout<<"\n4.A Union B";
        cout<<"\n5.A Intersection B";
        cout<<"\n6.(A-B)";
        cout<<"\n7.(B-A)";
        cout<<"\n8.To check Subset :";
        cin>>ch;

        switch(ch)
        {
            case 1: cout<<"\nInserting in set A :";
                s1.insert();
                cout<<"\nInserting in set B :";
                s2.insert();
                break;

            case 2: cout<<"\nDisplaying set A :";
                s1.display(s1.header);
                cout<<"\nDisplaying set B :";
                s2.display(s2.header);
                break;

            case 3: cout<<"\nEnter 1.To search element in set A , 2.To search element in set B :";
                cin>>flag;
                cout<<"\nEnter element you want to search :";
                cin>>key;
                if(flag==1)
                    temp=s3.search(s1.header,key);
                else if(flag==2)
                    temp=s3.search(s2.header,key);
                if(temp==0)
                    cout<<"\nElement not found!";
                break;

            case 4: s3.unionf(s1.header,s2.header);
                s3.display(s3.hu);
                break;

            case 5: s3.interf(s1.header,s2.header);
                s3.display(s3.hin);
                break;

            case 6: s3.onlyA(s1.header,s2.header);
                s3.display(s3.honA);
                break;

            case 7: s3.onlyB(s1.header,s2.header);
                s3.display(s3.honB);
                break;

            case 8: s3.subset(s1.header,s2.header);
                break;

            default:cout<<"\nINVALID CHOICE!\n";

        }
        cout<<"\nWant to continue? (Y/N) :";
        cin>>z;

    }while(z=='Y' || z=='y');

}