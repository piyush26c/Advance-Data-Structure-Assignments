//
// Created by piyush on 4/4/19.
//


#include<bits/stdc++.h>
using namespace std;
#define size 10

struct HASH
{
    long int telephoneNumber;
    string companyName;
    string customerName;
};


class TelephoneDirectory
{
public :
    HASH h[size];
    TelephoneDirectory()
    {
        for(int i = 0; i < size; i++)
        {
            h[i].telephoneNumber = -1;
            h[i].companyName  = "----------";
            h[i].customerName = "----------";
        }

    }
    int hashFunction(int key) const;
    void insertData() ;
    void displayData() const;
    int searchPhoneNo() const ;
    void deleteData(int hk);
    bool collision(int hashKey, string tempCompanyName, string tempCustomerName, long long int tempTelephoneNumber);

};


int TelephoneDirectory :: hashFunction(int key) const
{
    return (key % size);
}

bool TelephoneDirectory :: collision(int hashKey, string tempCompanyName, string tempCustomerName, long long int tempTelephoneNumber)
{

    int s = hashKey;
    for(int i = hashKey; i != s-1; i++){
        if(i == hashKey - 2)
            s = i+3;
        if(i == 10)
            i = 0;
        if(h[i].telephoneNumber == -1){
            h[i].companyName = tempCompanyName;
            h[i].customerName = tempCustomerName;
            h[i].telephoneNumber = tempTelephoneNumber;
            return true;
        }
    }

    return false;



}



void TelephoneDirectory :: insertData()
{
    long long tempPhoneNumber;
    string tempCompanyName, tempCustomerName;
    cout << "\nEnter Telephone Number  : ";
    cin >> tempPhoneNumber;
    cout << "\nEnter Company Name      : ";
    cin >> tempCompanyName;
    cout << "\nEnter Customer Name     : ";
    cin >> tempCustomerName;

    int hashkey = hashFunction(tempPhoneNumber);

    if(h[hashkey].telephoneNumber != -1)
    {
        cout << "\nCollision has occured ";
        if(!collision(hashkey,tempCompanyName,tempCustomerName,tempPhoneNumber)){
            cout << "\nHashTable is Full";
        }
    }
    else
    {
        h[hashkey].telephoneNumber = tempPhoneNumber;
        h[hashkey].companyName = tempCompanyName;
        h[hashkey].customerName = tempCustomerName;

    }

}

int TelephoneDirectory ::searchPhoneNo() const {

    long long int searchPhoneNumber;
    cout << "\nEnter the Phone Number  : ";
    cin >> searchPhoneNumber;
    int hashkey = hashFunction(searchPhoneNumber);

    int s = hashkey;
    for(int i = hashkey; i != s-1; i++){

        if(i == hashkey - 2)
            s = i+3;
        if(i == 10)
            i = 0;
        else{
            if(searchPhoneNumber == h[i].telephoneNumber){
                cout << setw(10) << h[i].telephoneNumber << setw(20) << h[i].customerName << setw(20) << h[i].companyName << endl;
                return i;
            }


        }
    }

    return -1;
}


void TelephoneDirectory :: deleteData(int hk) {

    h[hk].companyName  = "----------";
    h[hk].customerName = "----------";
    h[hk].telephoneNumber = -1;
}


void TelephoneDirectory ::displayData() const {


    cout << setw(10) << "Sr.no" << setw(20) << "Customer Name" << setw(20) << "Company Name" << setw(20) << "Phone No" << endl;

    for(int i = 0; i < size; i++){
        cout << setw(10) << i;
        cout << setw(20) << h[i].customerName;
        cout << setw(20) << h[i].companyName;
        cout << setw(15) << h[i].telephoneNumber <<endl;
    }
}


int main(){

    TelephoneDirectory t1;
    cout << "\n****************Telephone DIrectory*********************";
    int sw, dw, q;
    do{
        dw = 1;
        cout << "\n(1). Insert";
        cout << "\n(2). Display";
        cout << "\n(3). Delete";
        cout << "\n(4). Search";
        cout << "\n(5). Exit";
        cin >> sw;
        switch(sw){

            case 1:
                t1.insertData();
                break;

            case 2:
                t1.displayData();
                break;

            case 3:
                q = t1.searchPhoneNo();
                if(q == -1){
                    cout << "\nNo such phone number exist in hash table";

                }else{

                    t1.deleteData(q);
                }
                break;

            case 4:
                if(t1.searchPhoneNo() == -1){
                    cout << "\nNo such phone number exist in hash table";
                }

                break;

            case 5:
                dw = 0;
                break;

            default:
                cout << "\nInvalid Input";


        }

    }while(dw);

    return 0;
}

