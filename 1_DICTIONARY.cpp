//
// Created by piyush on 4/4/19.
//


#include <bits/stdc++.h>
using namespace std;

struct node
{
    string word;
    string meaning;
    node *l;
    node *r;

};


class Dictionary
{
public :
    void createDictionary();
    void inorderRecursiveTraversal(node *temp);
    void preorderRecursiveTraversal(node *temp);
    void postorderRecursiveTraversal(node *temp);
    void searchWord();
    void modifyWord();
    void deleteWord(string wordToDelete);
    node *root;
    node *nn;
    Dictionary()
    {
        root = NULL;
    }

};

void Dictionary :: createDictionary()
{
    nn = new node;
    cout << "\n Enter Word    : ";
    cin >> nn->word;
    cout << "\n Enter Meaning : ";
    cin >> nn->meaning;


    nn->l = nn->r = NULL;

    if(root == NULL)
        root = nn;
    else
    {
        node *temp,*parent;

        temp = root;
        while(temp != NULL)
        {
            parent = temp;
            if(nn->word < temp->word)
                temp = temp->l;
            else
                temp = temp->r;

        }

        if(nn->word < parent->word)
            parent->l = nn;
        else
            parent->r = nn;
    }
}

void Dictionary ::inorderRecursiveTraversal(node *temp)
{
    if(temp != NULL)
    {
        inorderRecursiveTraversal(temp->l);
        cout << " " << temp->word << " : ";
        cout << temp->meaning << endl;
        inorderRecursiveTraversal(temp->r);

    }

}

/*
void Dictionary ::pre_rec(node *temp)
{
	if(temp != NULL)
	{
		cout << " " << temp->data << " ";
		pre_rec(temp->l);
		preorderRecursiveTraversal(temp->r);

	}

}


void Dictionary ::pos_rec(node *temp)
{
	if(temp != NULL)
	{
		pos_rec(temp->l);
		pos_rec(temp->r);
		cout << " " << temp->data << " ";
	}

}
*/


void Dictionary :: searchWord()
{
    node *temp = root;
    string searchWord;
    int flag = 0;
    cout << "\nEnter the Word you want to search : ";
    cin >> searchWord;
    //node *parent;
    while(temp != NULL)
    {

        if(temp->word == searchWord)
            break;

        else if(temp->word > searchWord)
        {
            temp = temp->l;

        }
        else
        {
            temp = temp->r;
        }

    }

    if(temp == NULL)
        cout << "\nWord not found" << endl;
    else
    {
        cout << "\nWord Found";
        cout << "\nMeaning : " << temp->meaning;

    }

}

void Dictionary :: modifyWord()
{
    node *temp;
    string s,modifyWord;
    cout << "\nEnter the Word u have to modify : ";
    cin >> modifyWord;

    temp = root;
    while(temp != NULL)
    {

        if(temp->word == modifyWord)
            break;

        else if(temp->word > modifyWord)
        {
            temp = temp->l;

        }
        else
        {
            temp = temp->r;
        }


    }

    if(temp == NULL)
        cout << "\nWord not found" << endl;
    else
    {
        cout << "\nPrevious Meaning : " << temp->meaning;
        cout << "\nEnter New Meaning : ";
        cin >> s;
        temp->meaning = s;

    }

}

void Dictionary :: deleteWord(string wordToDelete)
{

    node *temp, *parent;

    temp = root;
    while(temp != NULL)
    {

        if(temp->word == wordToDelete)
            break;
        parent = temp;
        if(temp->word > wordToDelete)
        {
            temp = temp->l;

        }
        else
        {
            temp = temp->r;
        }

    }

    if(temp == NULL)
    {
        cout << "\nWord not found" << endl;
    }
    else
    {
        // node is root node
        if(temp->l == NULL && temp->r == NULL)
        {

            // node itselfa key
            if(temp->word == wordToDelete)
            {
                temp = NULL;
                delete temp;
            }

            if(wordToDelete < parent->word)
                parent->l = NULL;
            else
                parent->r = NULL;

            temp = NULL;
            delete temp;


        }
            //node nhaving one child
        else if(temp->l != NULL && temp->r == NULL)
        {
            if(wordToDelete < parent->word)
                parent->l = temp->l;
            else
                parent->r = temp->l;


            temp = NULL;
            delete temp;

        }

            //node nhaving one child
        else if(temp->l == NULL && temp->r != NULL)
        {
            if(wordToDelete < parent->word)
                parent->l = temp->r;
            else
                parent->r = temp->r;

            temp = NULL;
            delete temp;

        }
            //node having two child

        else if(temp->l != NULL && temp->r != NULL)
        {
            node *t;
            t = temp->l;
            while(t->r)
                t = t->r;

            string wrd, mean;

            wrd = t->word;
            mean = t->meaning;
            deleteWord(wrd);        //calling deleteWord function again as we have delete this leaf node
            temp->word = wrd;
            temp->meaning = mean;

        }

    }

}



int main()
{
    Dictionary t1,t2,t3,t4;
    cout << "\nBinary Search Dictionary : " << endl;
    int v,c;
    string s,key1;


    do
    {
        c = 1;
        cout << "(1). To insert" << endl;
        cout << "(2). To display Dictionary in Inorder Traversal " << endl;
        cout << "(3). To display Dictionary in Preorder Traversal " << endl;
        cout << "(4). To display Dictionary in Postoder Traversal " << endl;
        cout << "(5). To Search" << endl;
        cout << "(6). To Modify" << endl;
        cout << "(7). To delete node" << endl;
        cout << "(8). To Exit" << endl;
        cout << "\n Enter your choice  :  ";
        cin >> v;

        switch(v)
        {
            case 1 :
                t1.createDictionary();
                t2 = t1;
                t3 = t1;
                t4 = t1;
                break;

            case 2 :
                t1.inorderRecursiveTraversal(t1.root);
                cout << endl;
                break;
                /*
            case 3 :
                t2.preorderRecursiveTraversal(t2.root);
                cout << endl;
                break;
            case 4 :
                t3.pos_rec(t3.root);
                cout << endl;
                break;
                */

            case 5 :
                t2.searchWord();
                break;

            case 6 :
                t1.modifyWord();
                break;

            case 7 :

                cout << "\nEnter the Word u have to delete : ";
                cin >> key1;
                t4.deleteWord(key1);
                break;

            case 8 :
                c = 0;
                break;

        }


    }while(c);





    return 0;
}
