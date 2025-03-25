// #include<bits/stdc++.h>
// using namespace std;
// int INF = 1e9;

//  int countStages(vector<vector<int>>&Graph){
//         int k = 1;//source node ka stage 1
//         int u =0;
//         int  n = Graph.size();
//         int v = u+1;
//        while(v!=n)
//         {
//             if(Graph[u][v]!=INF){
//                 u = v;
//                 k++;
//             }
//             v++;
//         }
//       return k;
//     }

// int main()
// {
//     vector<vector<int>> graph = {
//         {0, 2, 1, 3, INF, INF, INF, INF},  // Stage 1
//         {INF, 0, INF, INF, 2, 3, INF, INF}, // Stage 2
//         {INF, INF, 0, INF, 6, 7, INF, INF}, // Stage 2
//         {INF, INF, INF, 0, INF, 4, 2, INF}, // Stage 2
//         {INF, INF, INF, INF, 0, INF, INF, 3}, // Stage 3
//         {INF, INF, INF, INF, INF, 0, INF, 1}, // Stage 3
//         {INF, INF, INF, INF, INF, INF, 0, 5}, // Stage 3
//         {INF, INF, INF, INF, INF, INF, INF, 0}  // Stage 4 (Sink)
//     };

//    int stages = countStages(graph);
//    cout<<"Number of Stages in Graph is:"<<stages;


//    return 0;
// }

#include <iostream>
#include <climits>
using namespace std;
#define N 4
#define INF INT_MAX
void stagesAndVertices(int cost[N][N])
{
    int k=1;
    cout<<k<<" has 1 vertex "<<endl;
    k++;
    int node=0;
    while(node!=N-1)
    {
        int c=0;
        for(int j=node+1;j<N;j++)
        {
            
            if(cost[node][j]!=INF)
            {
                c++;
            }
        }
        cout<<k<<" has "<<c<<" vertices "<<endl;
        for(int j=node+1;j<N;j++)
        {
            if(cost[node][j]!=INF)
            {
                node=j;
                k++;
                break;
            }
        }
    }
    cout<<"Total stages: "<<k-1<<endl;
}
int main()
{
    int cost[N][N]=
    {
        {INF,2,3,INF},
        {INF,INF,INF,6},
        {INF,INF,INF,7},
        {INF,INF,INF,INF}
    };
    stagesAndVertices(cost);
return 0;
}
