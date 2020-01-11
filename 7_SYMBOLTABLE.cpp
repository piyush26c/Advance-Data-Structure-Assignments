//
// Created by piyush on 4/4/19.
//

//
// Created by pccoe-02 on 2/14/19.
//
#include<bits/stdc++.h>
using namespace std;
#define SIZE 10

struct node
{
    string nameofidentifier;
    string typeofidentifier;
    int initialvalue;
    int lineNumbers[SIZE];
    int countOfLineNumbers;
    node *next;

};

class SymbolTable
{

public:
    char ch, ch1;
    node *nn, *head, *cn;
    SymbolTable()
    {
        head = NULL;
    }

    void createSymbolTable();
    void displaySymbolTable(node *headt, int h);
    void modifyEntryInSymbolTable( node *nf);
    void deleteEntryInSymbolTable(string sd);
    node* searchEntryInSymbolTable(string noi);


};

void SymbolTable::deleteEntryInSymbolTable(string sd)
{
    node* temp;
    node* parent;
    temp = head;


    if(temp->nameofidentifier == sd)
    {
        head = temp->next;


    }
    else
    {
        parent = head;
        temp = temp->next;

        while(temp != NULL)
        {

            if(temp->nameofidentifier == sd)
            {

                parent->next = temp->next;
                cout << "\nNode deleted Successfully";
                break;
            }
            else
            {
                parent = temp;
                temp = temp->next;
            }

        }


    }






}

void SymbolTable ::modifyEntryInSymbolTable(node *nf)
{
    string s6;
    cout << "\nEnter the Updateded Values :";
    cout << "\nEnter the Type of Identifier : ";
    cin >> nf->typeofidentifier;
    cout << "\nEnter the Initial Value : ";
    cin >> nf->initialvalue;
    cout << "\nEnter the Line Numbers ";
    int i = 0;
    do{
        cin >> nf->lineNumbers[i];
        i = i + 1;
        cout << "\nDo you want to enter another line number (y/n) : ";
        cin >> ch;
    }while(ch == 'y' || ch == 'Y');


    nf->countOfLineNumbers = i;




}

node* SymbolTable ::searchEntryInSymbolTable(string noi)
{
    node *temp;
    temp = head;
    while(temp != NULL)
    {
        if(temp->nameofidentifier == noi)
        {
            return temp;
        }
        temp = temp->next;

    }

    return NULL;

}

void SymbolTable ::createSymbolTable()
{

    do{
        nn = new node;
        cout << "\nEnter the Name of Identifier : ";
        cin >> nn->nameofidentifier;
        cout << "\nEnter the Type of Identifier : ";
        cin >> nn->typeofidentifier;
        cout << "\nEnter the Initial Value : ";
        cin >> nn->initialvalue;
        cout << "\nEnter the Line Numbers ";
        nn->next = NULL;


        int i = 0;
        do{
            cin >> nn->lineNumbers[i];
            i = i + 1;
            cout << "\nDo you want to enter another line number (y/n) : ";
            cin >> ch;
        }while(ch == 'y' || ch == 'Y');


        nn->countOfLineNumbers = i;


        if(head == NULL){
            head = nn;
        } else{

            cn = head;
            while(cn->next != NULL){
                cn = cn->next;
            }

            cn->next = nn;
        }

        cout << "\nDo you want to enter another entry (y/n) : ";
        cin >> ch1;

    }while(ch1 == 'y' || ch1 == 'Y');


}

void SymbolTable ::displaySymbolTable(node *headt, int h)
{

    if(headt==NULL)
    {
        cout << "\nNo Symbol Table present";
    }
    else
    {
        cout<<setw(20)<<"Name of identifier\t"<<setw(10)<<"Datatype\t"<<setw(15)<<"Initial Value\t"<<setw(20)<<"Line No.\t"<<setw(10)<<"Count"<<endl;
        cn=headt;

        if(h == 0)
        {
            while(cn!=NULL)
            {
                cout<<setw(20)<<cn->nameofidentifier<<"\t"<<setw(10)<<cn->typeofidentifier<<"\t"<<setw(15)<<cn->initialvalue<<"\t"<<setw(15);

                for(int i=0;i<cn->countOfLineNumbers;i++)
                {
                    cout<<cn->lineNumbers[i]<<",";
                }
                cout<<"\t"<<setw(5)<<cn->countOfLineNumbers<<endl;

                cn=cn->next;
            }

        }
        else
        {
            cout<<setw(20)<<cn->nameofidentifier<<"\t"<<setw(10)<<cn->typeofidentifier<<"\t"<<setw(15)<<cn->initialvalue<<"\t"<<setw(15);

            for(int i=0;i<cn->countOfLineNumbers;i++)
            {
                cout<<cn->lineNumbers[i]<<",";
            }
            cout<<"\t"<<setw(5)<<cn->countOfLineNumbers<<endl;


        }


    }



}




int main(){

    SymbolTable s;
    int sw, dw;
    string s5;

    do{
        dw = 1;
        cout << "\n(1). To create Symbol Table.";
        cout << "\n(2). To display.";
        cout << "\n(3). To exit";
        cout << "\n(4). To search";
        cout << "\n(5). To Modify";
        cout << "\n(6). To Delete";
        cin >> sw;
        switch(sw){

            case 1:
                s.createSymbolTable();
                break;

            case 2:
                s.displaySymbolTable(s.head, 0);
                break;

            case 3:
                dw = 0;
                break;
            case 4:

                cout << "\nEnter the Name of Identifier : ";
                cin >> s5;
                if(s.searchEntryInSymbolTable(s5) == NULL)
                    cout << "\nIdentifier not found";
                else
                {
                    cout << "\nIdentifier found";
                    s.displaySymbolTable(s.searchEntryInSymbolTable(s5), 1);
                }
                break;
            case 5:
                cout << "\nEnter the Name of Identifier to be get modified : ";
                cin >> s5;
                if(s.searchEntryInSymbolTable(s5) == NULL)
                    cout << "\nIdentifier not found";
                else
                {
                    cout << "\nIdentifier found";
                    s.modifyEntryInSymbolTable(s.searchEntryInSymbolTable(s5));
                }
                break;

            case 6:
                cout <<"\nEnter the Name of Identifier to be deleted : ";
                cin >> s5;
                if(s.searchEntryInSymbolTable(s5) == NULL)
                    cout << "\nIdentifier not found";
                else
                {
                    s.deleteEntryInSymbolTable(s5);
                }
                break;


            default:
                cout << "\nInvalid Input!";

        }
    }while(dw);
    return 0;
}