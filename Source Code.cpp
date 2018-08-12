#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

int i,j,m,n,k,lbl,c[20][20];
char x[20],y[20],b[20][20];

void eff(float i, float j){
    float ef;
    ef = (j*100)/i;
	cout<<endl<<endl<<setprecision(3)<<ef<<"% DNA matches."<<endl;
}

void print(int i,int j){
    if(i==0 || j==0)
        return;
    if(b[i][j]=='c'){
        print(i-1,j-1);
        cout<<x[i-1];
        lbl = 1;
        k++;
    }
    else if(b[i][j]=='u')
        print(i-1,j);
    else
        print(i,j-1);
}

void lcs()
{
    m=strlen(x);
    n=strlen(y);
    for(i=0;i<=m;i++)
        c[i][0]=0;
    for(i=0;i<=n;i++)
        c[0][i]=0;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++){
            if(x[i-1]==y[j-1]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='c';
            }
            else if(c[i-1][j]>=c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]='u';
            }
            else{
                c[i][j]=c[i][j-1];
                b[i][j]='l';
            }
        }
}

main()
{
    cout<<"Enter first DNA sequence:"<<endl;
    cin>>x;
    cout<<"Enter second DNA sequence:"<<endl;
    cin>>y;
    cout<<endl;
    lcs();
    print(m,n);
    if(lbl == 1)
        cout<<" is the longest common subsequence"<<endl;
    else
        cout<<"NO MATCH FOUND!";
    if(m >= n)
        eff(m,k);
    else
        eff(n,k);
}
