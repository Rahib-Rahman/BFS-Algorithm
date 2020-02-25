#include<bits/stdc++.h>
#define mxn 10000

using namespace std;

vector< int > graph[mxn];
int start_node, goal_node, parent_node[mxn];
bool visited[mxn];

int getParentNode(int node)
{
    return parent_node[node];
}

void path(int current_node)
{
    if(current_node == start_node)
    {
        printf("%d",current_node);
        return;
    }
    path( getParentNode(current_node) );
    printf("->%d",current_node);
}

bool BFS(int current_node)
{
    int child, number_of_child;
    queue<int>q;
    q.push(current_node);
    visited[current_node] = true;

    while(!q.empty())
    {
        current_node = q.front();
        visited[current_node] = true;
        q.pop();
        if(current_node == goal_node)
            return true;

        number_of_child = graph[current_node].size();

        for(int i=0; i<number_of_child; i++)
        {
            child = graph[current_node][i];
            if(!visited[child])
            {
                q.push(child);
                parent_node[child] = current_node;
            }
        }
    }
    return false;
}

int main()
{
    freopen("BFS_input.txt","r", stdin);

    int number_of_nodes, number_of_edges, edge_start, edge_end;
    printf("Enter the number of Nodes : ");
    scanf("%d",&number_of_nodes);
    printf("Enter the number of Edges : ");
    scanf("%d",&number_of_edges);
    printf("Enter the Edges : \n");

    for(int i=1; i<=number_of_edges; i++)
    {
        scanf("%d %d",&edge_start ,&edge_end);
        graph[edge_start].push_back(edge_end);
        graph[edge_end].push_back(edge_start);
    }

    printf("\nEnter start node : ");
    scanf("%d",&start_node);
    printf("Enter goal node : ");
    scanf("%d",&goal_node);

    printf("\nUsing BFS");
    if( BFS(start_node) )
    {
        printf("\npath from start to goal node : ");
        path(goal_node);
        printf("\n");
    }
    else
    {
        printf("\nThere is no path from start to goal node.\n");
    }
    return 0;
}

