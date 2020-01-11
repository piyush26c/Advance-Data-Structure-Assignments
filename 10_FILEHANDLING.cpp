//
// Created by piyush on 4/4/19.
//

#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

class StudentDatabase
{
private:
    int phn;
    char name[40];
    char division;
    char address[40];


public:
    void get()
    {
        cout << "\nEnter the name of the student :";
        cin >> name;
        cout << "\nEnter the Roll Number of the student : ";
        cin >> phn;
        cout << "\nEnter the Division of the student : ";

    }
    void display()
    {
        cout<<"\nName :"<<name<<" & Phone number :"<<phn<<endl;
        cout<<"*******************************************"<<endl;
    }
    inline char* get_name()
    {
        return name;
    }
    inline long long int get_phn()
    {
        return phn;
    }


};
int main()
{
    char z,name[30];
    int ch,a,flag=0;
    StudentDatabase t;
    long long int phn;
    fstream file;

    do
    {   cout<<"\n*****STUDENT DATABASE*****\n";
        cout<<"\n1.To create/Update contact list\n";
        cout<<"\n2.To Display whole contact list\n";
        cout<<"\n3,To search contact by name\n";
        cout<<"\n4.To search contact by phone number\n";
        cout<<"\n5.To update the contact :\n";
        cin>>ch;

        switch(ch)
        {
            case 1: file.open("number.txt",ios::out|ios::app);
                do
                {
                    t.get();
                    file.write((char*)&t,sizeof(t));

                    cout<<"\nEnter 1 to add another contact else 0 :";
                    cin>>a;
                }while(a==1);
                file.close();

                break;

            case 2: file.open("number.txt",ios::in);
                while(file)
                {
                    file.read((char*)&t,sizeof(t));
                    if(file)
                        t.display();
                }
                file.close();
                break;

            case 3: file.open("number.txt",ios::in);
                cout<<"\nEnter the name of person you want to search :";
                cin>>name;
                flag=0;
                while(file)
                {   file.read((char*)&t,sizeof(t));
                    if(strcmp(name,t.get_name())==0)
                    {
                        flag=1;
                        cout<<"\nRecord found!";
                        t.display();
                        break;
                    }
                }
                if(flag==0)
                {
                    cout<<"\nRecord not found!";
                }
                file.close();
                break;

            case 4: file.open("number.txt",ios::in);
                cout<<"\nEnter the phone number of person you want to search :";
                cin>>phn;
                flag=0;
                while(file)
                {   file.read((char*)&t,sizeof(t));
                    if(phn==t.get_phn())
                    {
                        flag=1;
                        cout<<"\nRecord found!";
                        t.display();
                        break;
                    }
                }
                if(flag==0)
                {
                    cout<<"\nRecord not found!";
                }
                file.close();
                break;

            case 5: file.open("number.txt",ios::in|ios::out);
                cout<<"\nEnter the name of person you want to search :";
                cin>>name;
                flag=0;
                while(file)
                {   file.read((char*)&t,sizeof(t));
                    if(strcmp(name,t.get_name())==0)
                    {
                        flag=1;
                        cout<<"\nRecord found!";
                        t.display();

                        cout<<"\nEnter the info for updation :";
                        file.seekp(-sizeof(t),ios::cur); //seekp() or seekg() serkawata pointer file
                        t.get();
                        file.write((char*)&t,sizeof(t));

                        break;
                    }
                }
                if(flag==0)
                {
                    cout<<"\nRecord not found!";
                }
                file.close();
                break;

            default:cout<<"\nInvalid Input.";
                break;
        }

        cout<<"\nWant to continue? (Y/N):";
        cin>>z;
    }while(z=='Y'||z=='y');
}