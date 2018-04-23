
//disjoint set template
//tonmoy

#include<bits/stdc++.h>
using namespace std;

int lead[500000+2];
int rak[500000+2];
int Count;//the number of set initially the value is n(number of elements)

//makes n set at first  set
void make_set(int n)
{
    for(int i = 1;i<=n;i++)
    {
        lead[i] = i;
        rak[i] = 0;
    }
}

//find the leader or lead of any object
int find_set(int x)
{
    if(lead[x] == x)
         return x;

    lead[x] = find_set(lead[x]);

    return lead[x];
}

//merge two set .
void Merge(int x,int y)
{
   int  lx = find_set(x);
   int  ly = find_set(y);

   if(lx != ly)//decreases  the number of sets
   {
       Count--;
   }
   else
    return;


    if(rak[lx] > rak[ly])
        lead[ly] = lx;
     else
          lead[lx] = ly;
    if(rak[ly] == rak[lx])
             rak[ly] = rak[ly] + 1;
}

