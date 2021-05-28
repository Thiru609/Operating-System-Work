#include <iostream>
using namespace std;
int main()
{
int i,j,l,p,r;
cout<<"Enter Number of Processes(ex:4) and Requests(ex:3)"<<endl;
cin>>p>>r;

int held[4][3] = { { 0, 0, 0 }, // P0 // Adjacency matric for resource hold
{ 1, 0, 0 }, // P1
{0, 0, 1 }, // P2
{ 0, 1, 0 }}; // P3


int req[4][3] = { { 1, 1, 0 }, // P0 // Adjacency matrix for resource request
{ 0, 0, 1 }, // P1
{ 0, 0, 0 }, // P2
{ 0, 0, 1 }}; // P3

//for (i = 0; i < p; i++) //to initialize arrays by user input
//for (j = 0; j < r; j++)
//cin>>held[i][j]>>req[i][j];

int wfg[4][4] = { { 0, 0, 0,0 },
{ 0, 0, 0,0 },
{0, 0, 0,0 },
{ 0, 0, 0,0 }};

for(i=0;i<p;i++){ //finding wait for graph
for(j=0;j<r;j++)
{
if(req[i][j]==1)
{
for(l=0;l<p;l++)
{
if(held[l][j]==1)
{
wfg[i][l]=1;
}
}
}
 }}
for(i=0;i<p;i++)
{for(j=0;j<p;j++)
cout<<wfg[i][j];
cout<<endl;
}
return(0);