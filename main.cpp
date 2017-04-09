#include <iostream>

using namespace std;
int parent[9]={0};
int find(int i){
    while(parent[i]){
        i=parent[i];
    }

    return i;
}

int uni(int i ,int j){

if(i!=j){
parent[j]=i;
return 1;

}
return 0;
}

void printP(){
int i=1;
for(i=1;i<=6;i++)
    cout<<"  "<<parent[i];
cout<<endl;
}




int main()
{
   //cout << "Hello world!" << endl;

    int A[9][9];
    int ne;
    cout<<"enter the no of nodes"<<endl;
    cin>>ne;
    cout<<"enter the adjacency matrix"<<endl;
    int i=0,j=0;
    for(i=1;i<=ne;i++)
    {
        for(j=1;j<=ne;j++)
            cin>>A[i][j];
    }

    for(i=1;i<=ne;i++)
    {
        for(j=1;j<=ne;j++)
        {
            if(A[i][j]==0)
                A[i][j]=999;
        }

    }
    int n=1,mincost=0;
    int m,r=0,c=0;
    while(n<ne)
    {m=999;
     for(i=1;i<=ne;i++)
    {
        for(j=i+1;j<=ne;j++)
        {
            if(A[i][j]<m)
            {
                m=A[i][j];
                r=i;
                c=j;
            }
        }
    }
    int a,b;
    printP();
    a=find(r);
    b=find(c);
    if(uni(a,b))
    {   printP();
        mincost+=m;
        cout<<"including edge "<<r<<c<<"with cost "<<m<<endl;

        n++;

    }
     A[r][c]=999;

    }

    cout<<"min cost is "<<mincost<<endl;
    return 0;
}
