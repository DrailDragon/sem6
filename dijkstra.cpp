#include<iostream>
using namespace std;
int m,n;
int** G,**G1,**G2;
bool* visited;
int cont=1;
void primsalgo(int r){
	int mnm = 1;
while(true){
    mnm = 1;
    visited[r]=true;
    int i;
    for(i=1;i<n;i++){
        if(visited[i]== false){
            mnm = i;
            break;
        }
    }
    if(i == n)
        break;

    for( i=1;i<n;i++){
        if(visited[i] == false && G[r][i] < G[r][mnm])
            mnm = i;
    }
    G1[r][mnm] = G[r][mnm];
    cout<<cont<<"th"<<endl;
    cont++;
    r = mnm;
    }
}
int main(){

    cin>>m>>n;
     int i,j,u,v,w,r;
     n+=1;
     m+=1;
 G = new int*[n];
    if(!G){cout<<"G NULL"<<endl; return 1;}

 G1 = new int*[n];
 if(!G1){cout<<"G1 NULL"<<endl; return 1;}
 G2 = new int*[n];
 if(!G2){cout<<"G2 NULL"<<endl; return 1;}
 for(i=0;i<=n;i++){
    G[i] = new int[n];
    if(!G[i]){cout<<"G["<<i<<"] NULL"<<endl; return 1;}
    G1[i] = new int[n];
    if(!G1[i]){cout<<"G1["<<i<<"] NULL"<<endl; return 1;}
     G2[i] = new int[n];
    if(!G2[i]){cout<<"G2["<<i<<"] NULL"<<endl; return 1;}
 }
 visited = new bool[n];


    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            G[i][j]=-1;
            G1[i][j]=-1;
            G2[i][j]=-1;
        }
    }
    for(i=1;i<m;i++){
        cin>>u>>v>>w;
        G[u][v]=w;
        G2[u][v]=i; //store the indexes of the edges
    }
    cin>>r;
    for(i=0;i<n;i++)
        visited[i]=false;
        cout<<"Graph:"<<endl;
    for(i=1;i<n;i++){
        for(j=1;j<n;j++){
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
    primsalgo(r);
    int mwt=0;
    cout<<"Tree:"<<endl;
    for(i=1;i<n;i++){
        for(j=1;j<n;j++){
            //cout<<G1[i][j]<<" ";
            if(G1[i][j] != -1){
            		mwt+=G1[i][j];
            }
        }
        //cout<<endl;
    }
    cout<<mwt<<endl;
    for(i=1;i<n;i++){
        for(j=1;j<n;j++){
       // cout<<G2[i][j]<<" ";
            if(G1[i][j] != -1){
            		cout<<G2[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
return 0;
}
