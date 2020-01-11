//
// Created by piyush on 4/4/19.
//

#include<bits/stdc++.h>
using namespace std;
#define SIZE 20

class SetUsingArray
{
public :
    int elements[SIZE];
    int numberOfElements;
    void createSet();
    void displaySet(SetUsingArray sA, SetUsingArray sB);
    void searchElement();
    void union_AB(SetUsingArray sA, SetUsingArray sB);
    void intersection(SetUsingArray sA, SetUsingArray sB);
    void difference(SetUsingArray f, SetUsingArray intersection);

};

void SetUsingArray :: difference(SetUsingArray f, SetUsingArray intersection)
{

    int noes = f.numberOfElements;
    int noei = intersection.numberOfElements;
    int i1 = 0,flag = 0,i;

    for( i = 0; i < noes; i++)
    {
        flag = 0;
        for(int j = 0; j < noei; j++)
        {

            if(intersection.elements[j] == f.elements[i])
            {
                flag = 1;
                break;

            }

        }



        if(flag == 0)
        {
            elements[i1] = f.elements[i];
            ++i1;

        }

    }



    numberOfElements = i1;

    //display the difference between the set
    for(int i = 0; i < numberOfElements; i++)
        cout << elements[i] << " ";

    cout  << endl;



}



void SetUsingArray :: intersection(SetUsingArray sA, SetUsingArray sB)
{
    int noeA = sA.numberOfElements;
    int noeB = sB.numberOfElements;
    int i1 = 0;
    for(int i = 0; i < noeA; i++)
    {
        for(int j = 0; j < noeB; j++)
        {
            if(sA.elements[i] == sB.elements[j])
            {
                elements[i1] = sA.elements[i];
                ++i1;
            }

        }

    }

    //updating the number of elements of intersection;
    numberOfElements = i1;


}

void SetUsingArray :: union_AB(SetUsingArray sA, SetUsingArray sB)
{
    int noeA = sA.numberOfElements;
    int noeB = sB.numberOfElements;
    int i1,flag = 0;
    //filling all elements of set A;
    for( i1 = 0; i1 < noeA; i1++)
        elements[i1] = sA.elements[i1];

    for(int i = 0; i < noeB; i++)
    {
        flag = 0;
        for(int j = 0; j < noeA; j++)
        {
            if(sA.elements[j] == sB.elements[i])
            {
                flag = 1;
                break;

            }


        }
        if(flag == 0)
        {

            elements[i1] = sB.elements[i];
            ++i1;

        }



    }

    //updating the count of elements in union set of A and B
    numberOfElements = i1;
}

void SetUsingArray :: searchElement()
{
    int elementToFind;
    cout << "\nEnter the element to be searched in Set : ";
    cin >> elementToFind;

    for(int i = 0; i < numberOfElements; i++)
    {
        if(elements[i] == elementToFind)
        {
            cout << "\nElement Found ";
            break;
        }

    }
    cout << "\nElement not found";

}

void SetUsingArray :: createSet()
{

    cout << "\nEnter the total numbers of elements containing SET : ";
    cin >> numberOfElements;
    for(int i = 0; i < numberOfElements; i++)
    {
        cin >> elements[i];
    }
}

void SetUsingArray :: displaySet(SetUsingArray sA, SetUsingArray sB)
{

    cout << "\nSet A : ";
    for(int i = 0; i < sA.numberOfElements; i++)
        cout << sA.elements[i] << " ";

    cout << endl;

    cout << "\nSet B : ";
    for(int i = 0; i < sB.numberOfElements; i++)
        cout << sB.elements[i] << " ";
}



int main()
{

    int sw,dw;
    char ch;
    SetUsingArray sA,sB,unionAB,intersectionAB,displayAB,A_B,B_A;
    do
    {

        cout << "\n***************SET OPERATIONS**********************";
        cout << "\nEnter (1). to create set.";
        cout << "\nEnter (2). to display set.";
        cout << "\nEnter (3). to search element in set.";
        cout << "\nEnter (4). to calculate union of A & B.";
        cout << "\nEnter (5). to calculate intersection of A & B.";
        cout << "\nEnter (6). to calculate A - B";
        cout << "\nEnter (7). to calculate B - A" << endl;
        cin >> sw;

        switch(sw)
        {

            case 1:
                cout << "\nCreating Set A : ";
                sA.createSet();
                cout << "\nCreating Set B : ";
                sB.createSet();
                break;

            case 2:
                displayAB.displaySet(sA,sB);
                break;
            case 3:
                unionAB.union_AB(sA,sB);
                unionAB.searchElement();
                break;

            case 4:
                unionAB.union_AB(sA,sB);
                cout << "\nUnion of Set A and Set B : ";
                for(int i = 0; i < unionAB.numberOfElements; i++)
                    cout << unionAB.elements[i] << " ";
                break;

            case 5:
                intersectionAB.intersection(sA,sB);
                for(int i = 0; i < intersectionAB.numberOfElements; i++)
                    cout << intersectionAB.elements[i] << " ";
                break;

            case 6:
                intersectionAB.intersection(sA,sB);
                A_B.difference(sA, intersectionAB);
                break;

            case 7:
                intersectionAB.intersection(sA,sB);
                B_A.difference(sB, intersectionAB);
                break;

        }

        cout << "\nDo you want to continue Y/N : ";
        cin >> ch;

    }while(ch == 'Y' || ch == 'y');



    return 0;

}
