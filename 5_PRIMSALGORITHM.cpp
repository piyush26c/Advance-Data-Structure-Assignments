//
// Created by Piyush on 2/20/2019.
//


#include<bits/stdc++.h>
using namespace std;
#define maxsize 20


class primsAlgorithm
{
public :

    int costm[maxsize][maxsize], distm[maxsize], sourcem[maxsize], visitedm[maxsize], matrix[maxsize][maxsize];
    int sp[maxsize][maxsize];
    int min_dist,min_cost, edge, u, v, n1, n2;
    int no_nodes;
    void create_adjancencymatrix();
    void create_costmatrix();
    bool valid(int x, int y);
    void prims_algo();
    void display_mst();

};

void primsAlgorithm :: display_mst()
{
    cout << "\nMinimum Spanning Tree Adjancency Matrix";
    cout << endl;
    for(int i = 0; i < no_nodes; i++)
    {
        for(int k = 0; k < no_nodes; k++)
            cout << sp[i][k] << " ";

        cout << endl;

    }

}

bool primsAlgorithm :: valid(int x, int y)
{
    if(x <= no_nodes - 1 && x >= 0 && y <= no_nodes - 1 && y >= 0)
        return true;
    else
        return false;

}



void primsAlgorithm :: create_adjancencymatrix()
{

    cout << "\nEnter the Number of Nodes : ";
    cin >> no_nodes;

    //making all elements zero
    for(int y = 0; y < no_nodes; y++)
    {
        for(int h = 0; h < no_nodes; h++)
        {
            sp[y][h] = 0;                         //making spanning tree adj_matrix initialised to 0
            matrix[y][h] = 0;
        }
    }

    cout << "\nEnter the Edges ";

    int weight, c;

    do
    {
        cout << "\nEnter First Node  : ";
        cin >> n1;
        cout << "\nEnter Second Node : ";
        cin >> n2;
        cout << "\nEnter Weight      : ";
        cin >> weight;
        if(valid(n1,n2))
        {

            matrix[n1][n2] = weight;
            matrix[n2][n1] = weight;

        }
        else
            cout << "\nInvalid Edge points";

        cout << "\nEnter 1/0 to continue : ";
        cin >> c;


    }while(c);


}


void primsAlgorithm :: create_costmatrix()
{
    for(int i = 0; i < no_nodes; i++)
    {
        for(int j = 0; j < no_nodes; j++)
        {
            if(matrix[i][j] == 0)
                costm[i][j] = INT_MAX;
            else
                costm[i][j] = matrix[i][j];

        }


    }



    //displaying the cost_matrix
    for(int i = 0; i < no_nodes; i++){
        for(int j = 0; j < no_nodes; j++){
            cout << costm[i][j] << " ";
        }
        cout << endl;
    }

}


void primsAlgorithm :: prims_algo()
{
    //first making all visited, source, distance matrices zero
    for(int i = 0; i < no_nodes; i++)
    {
        distm[i] = 0;
        sourcem[i] = 0;
        visitedm[i] = 0;
    }

    //starting from vertex no.0
    distm[0] = INT_MAX;
    visitedm[0] = 1;

    //calculated distance of all vertices from vertex 0;
    for(int i = 1; i < no_nodes; i++)
    {
        distm[i] = costm[0][i];
        sourcem[i] = 0;
        visitedm[i] = 0;

    }

    min_cost = 0;



    while(accumulate(visitedm,visitedm+no_nodes,0) != no_nodes)
    {
        min_dist = INT_MAX;

        //finding the edge with minimum weight from source vertex
        for(int i = 1; i < no_nodes; i++)
        {
            if(visitedm[i] == 0 && distm[i] < min_dist)
            {
                min_dist = distm[i];
                v = i;                //storing the source index to get source of this vertex i;

            }


        }

        //add edge in spanning tree and mark vertex as visited
        u = sourcem[v];               //here we had marked the source;
        sp[u][v] = distm[v];
        sp[v][u] = distm[v];
        visitedm[v] = 1;


        //updating the distance_matrix and also source where we update the source
        for(int i = 1; i < no_nodes; i++)
        {
            if(visitedm[i] == 0 && costm[v][i] < distm[i])
            {
                distm[i] = costm[v][i];
                sourcem[i] = v;

            }

        }

        min_cost = min_cost + costm[u][v];


    }


}


int main()
{

    int sw, dw;
    primsAlgorithm p;
    do
    {
        dw = 1;
        cout << "\n(1). To enter edges and their weights";
        cout << "\n(2). To get minimum spanning tree";
        cout << "\n(3). To get minimum cost of the minimal spanning tree";
        cout << "\n(4). To exit";
        cin >> sw;


        switch(sw)
        {
            case 1:
                p.create_adjancencymatrix();
                p.create_costmatrix();
                p.prims_algo();
                break;
            case 2:
                p.display_mst();
                break;

            case 3:
                cout << "\nMinimum Cost :" << p.min_cost << endl;
                break;
            case 4:
                dw = 0;
                break;

            default :
                cout << "\nInvalid Input";

        }

    }while(dw);

    return 0;
}

