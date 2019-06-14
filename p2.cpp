#include<iostream>
using namespace std;
int main()
{
long int t1=1,t2=2,sum=0,n=2;
while(t2<4000000 && t1<4000000){


if(t2%2==0)
    sum+=t2;


int temp=t2;
t2=t1+t2;
t1=temp;
n++;
}
cout<<t1<<endl<<t2<<endl;
cout<<sum;
return 0;
}
