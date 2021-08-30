#include <iostream>

using namespace std;

int main( )
{
    cout<<" enter the size the of the array"<<endl;
    
    int n;
    cin>>n;
    
    int *p;
    p=new int [ n];
    
    int i=0 ;
    
    while( i<n)
    {
        cin>>p[ i];
        i++;
    }
    
    int j=0 ;
    
    while( j<n)
    {
        cout<<p[j]<<endl;
        j++;
    }
}
