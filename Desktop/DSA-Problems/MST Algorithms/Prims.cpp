#include<bits/stdc++.h>
using namespace std;

int minKey(vector<int>& key, vector<bool>& mstset){
    int min=INT_MAX, min_index;
    for(int v=0;v<mstset.size();v++){
        if(mstset[v]==false && key[v]<min){
            min=key[v];
            min_index=v;
        }
    }
    return min_index;
}


void printMST(vector<int>&parent, vector<vector<int>>&graph){
    cout<<"Edge \t weight"<<"\n";
    for(int i=1;i<graph.size();i++){
        cout<<parent[i]<<" - "<<i<<"\t";
        cout<<graph[parent[i]][i]<<"\n";
    }
}

void primMST(vector<vector<int>>& graph){
    int vsize=graph.size();
    vector<int>parent(vsize);
    vector<int>key(vsize);
    vector<bool>mstset(vsize);
    for(int i=0;i<vsize;i++){
        key[i]=INT_MAX;
        mstset[i]=false;
    }
    key[0]=0;
    parent[0]=-1;

    for(int count=0 ; count<vsize-1 ; count++){
        int u=minKey(key,mstset);
        mstset[u]=true;
        for(int v=0;v<vsize;v++){
            if(graph[u][v]  &&  mstset[v]==false && graph[u][v]<key[v]){
                parent[v]=u;key[v]=graph[u][v];
            }
        }
    }
    printMST(parent,graph);
}
int main(){
    vector<vector<int>> graph={ { 0, 2, 0, 6, 0 },
                        		{ 2, 0, 3, 8, 5 },
                        		{ 0, 3, 0, 0, 7 },
                        		{ 6, 8, 0, 0, 9 },
                        		{ 0, 5, 7, 9, 0 } };
    primMST(graph);
    return 0;
}