//
// Created by piyush on 4/4/19.
//

#include<iostream>
using namespace std;

struct node
{
    int vertex_no;
    node *next;
};
node *N[20];                    //array of node structure

class Graph
{
public :
    //default constructor
    Graph()
    {
        for(int i = 0; i < 20; i++)
        {
            stck[i] = 0;
            visited[i] = 0;
            queue_bfs[i] = 0;
        }
        top = -1;
        front = -1;
        rear = -1;
    }

    int arr[20][20];                 //edge-matrix
    int no_nodes;
    int visited[20];                 //maintaining record of traversed nodes-array

    int stck[20];                   //stack-array implementation for DFS(Non_Recursive)
    int top;
    void push(int num);
    int pop();
    void createAdjacencyMatrix();
    bool isNodeNumberValid(int x, int y);
    void displayAdjacencyMatrix();
    void createAdjacencyList();
    void displayAdjacencyList();
    void dfsNonRecursive(int a);
    void dfsRecursive(int a);


    void bfsNonRecursive(int x);
    int rear,front;
    int queue_bfs[20];

};

bool Graph :: isNodeNumberValid(int x, int y)
{
    if(x <= no_nodes - 1 && x >= 0 && y <= no_nodes - 1 && y >= 0)
        return true;
    else
        return false;

}

void Graph :: push(int num)
{
    stck[++top] = num;
}

int Graph :: pop()
{
    return stck[top--];
}


void Graph :: bfsNonRecursive(int x)
{
    int y,x1;
    visited[x] = 1;

    queue_bfs[++rear] = x;

    while(front <= rear)
    {
        x1 = queue_bfs[front++];

        cout << x1 << " ";

        for(y = 0; y < no_nodes; y++)
        {
            if(arr[x1][y] == 1 && visited[y] == 0)
            {
                queue_bfs[++rear] = y;
                visited[y] = 1;
            }
        }

    }

}


void Graph :: dfsNonRecursive(int a)
{
    int b,a1;
    push(a);
    visited[a] = 1;

    while(top != -1)
    {
        a1 = pop();
        cout << a1 << " " ;

        for(b = 0; b < no_nodes; b++)
        {
            if(arr[a1][b] == 1 && visited[b] == 0)
            {
                push(b);
                visited[b] = 1;
            }

        }

    }
}



void Graph :: dfsRecursive(int a)
{

    int i;
    visited[a] = 1;
    cout << a << " ";
    for(int b = 0; b < no_nodes; b++)
    {
        if(arr[a][b] == 1 && visited[b] == 0)
        {
            dfsRecursive(b);
        }
    }
}



void Graph :: displayAdjacencyList()
{
    node* cn;
    for(int i = 0; i < no_nodes; i++)
    {
        cn = N[i];
        //cout << i;
        //cout << a << " ";
        while(cn != NULL)
        {
            cout << i;
            cout << "->";
            cout << cn->vertex_no;
            cout << " ";
            cn = cn->next;
        }
        cout << endl;
    }



}

void Graph :: createAdjacencyList()
{

    int v1, v2,c1,t;
    cout << "\nEnter the Number of Nodes : ";
    cin >> no_nodes;
    cout << "\nEnter (1). for directed Graph ";
    cout << "\nEnter (2). for undirected graph ";
    cin >> t;

    node *nn, *temp;
    do
    {

        cout << "\nEnter the edge : ";
        cin >> v1;
        cin >> v2;
        if(isNodeNumberValid(v1, v2))
        {

            //for undirected graph
            if(t == 2)
            {
                //first time
                nn = new node;
                nn->vertex_no = v2;
                nn->next = NULL;
                temp = N[v1];

                if(temp == NULL)
                    N[v1] = nn;
                else
                {
                    while(temp->next != NULL)
                        temp = temp->next;

                    temp->next = nn;
                }

                //second time
                nn = new node;
                nn->vertex_no = v1;
                nn->next = NULL;
                temp = N[v2];

                if(temp == NULL)
                    N[v2] = nn;
                else
                {
                    while(temp->next != NULL)
                        temp = temp->next;

                    temp->next = nn;
                }

            }
                //for directed graph
            else
            {
                nn = new node;
                nn->vertex_no = v2;
                nn->next = NULL;
                temp = N[v1];

                if(temp == NULL)
                    N[v1] = nn;
                else
                {
                    while(temp->next != NULL)
                        temp = temp->next;

                    temp->next = nn;
                }

            }


        }
        else
            cout << "\nInvalid Edge Input";


        cout << "\nEnter 1/0 to continue : ";
        cin >> c1;

    }while(c1);








}

void Graph :: createAdjacencyMatrix()
{
    int t,c;
    int n1,n2;

    cout << "\nEnter the Number of Nodes : ";
    cin >> no_nodes;

    //making all elements zero
    for(int y = 0; y < no_nodes; y++)
    {
        for(int h = 0; h < no_nodes; h++)
            arr[y][h] = 0;
    }

    cout << "\nEnter (1). for directed Graph ";
    cout << "\nEnter (2). for undirected graph ";
    cin >> t;

    cout << endl;

    cout << "\nEnter the Edges ";

    do
    {
        cout << "\nEnter First Node  : ";
        cin >> n1;
        cout << "\nEnter Second Node : ";
        cin >> n2;
        if(isNodeNumberValid(n1, n2))
        {
            if(t == 1)
            {
                arr[n1][n2] = 1;
            }
            else if(t == 2)
            {
                arr[n1][n2] = 1;
                arr[n2][n1] = 1;
            }

        }
        else
            cout << "\nInvalid Edge points";

        cout << "\nEnter 1/0 to continue : ";
        cin >> c;


    }while(c);




}



void Graph :: displayAdjacencyMatrix()
{
    cout << "\nAdjancey Matrix" << endl;

    for(int i = 0; i < no_nodes; i++)
    {
        for(int j = 0; j < no_nodes; j++)
        {
            cout << arr[i][j] << "  " << "  ";

        }
        cout << endl;

    }

    cout << endl;



}


int main()
{
    Graph g1;

    int dw,sw;

    do
    {
        dw = 1;
        cout << "\n(1). To Create Adjency Matrix";
        cout << "\n(2). To Display Adjency Matrix";
        cout << "\n(3). To Create Adjency List";
        cout << "\n(4). To Display Adjency List";
        cout << "\n(5). DFS(recursive)";
        cout << "\n(6). DFS(Non_Recursive)";
        cout << "\n(7). BFS(Non_Recursive)";
        cout << "\n(8). To Exit";
        cin >> sw;

        switch(sw)
        {

            case 1:
                g1.createAdjacencyMatrix();
                break;

            case 2:
                g1.displayAdjacencyMatrix();
                break;

            case 3:
                g1.createAdjacencyList();
                break;

            case 4:
                g1.displayAdjacencyList();
                break;

            case 5:
                if(g1.no_nodes != 0)
                {
                    //dfs_recursive method
                    g1.dfsRecursive(0);

                }
                else
                {
                    cout << "\nGraph does not exists";
                }
                break;

            case 6:
                if(g1.no_nodes != 0)
                {
                    //g1.dfs_non_rec(0);

                    for(int f = 0; f < g1.no_nodes; f++)
                    {
                        if(g1.visited[f] != 1)
                            g1.dfsNonRecursive(f);
                    }
                }
                else
                {
                    cout << "\nGraph does not exists";
                }
                break;


            case 7:
                if(g1.no_nodes != 0)
                {
                    //g1.bfs_non_rec(0);

                    for(int f = 0; f < g1.no_nodes; f++)
                    {
                        if(g1.visited[f] != 1)
                            g1.bfsNonRecursive(f);
                    }
                }
                else
                {
                    cout << "\nGraph does not exists";
                }
                break;

            case 8:
                dw = 0;
                break;

        }

    }while(dw);




    return 0;
}
