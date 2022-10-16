#include <iostream>           
using namespace std;         

int binary_search(int a[],int i,int j,int x){
    //Searching x using binary search between i and j.
    int m=(i+j)/2; 
    while(i<=j){  
    if(a[m]==x){return m;}
    else{
        if(a[m]<x){i=m+1;}
        else{j=m-1;}
    }
    m=(i+j)/2;
    }
    return -1; 
}

int Unknown(int a[],int x){
    int i=0,j=1;
    //Increasing j to j*2 so that a[j] exceeds x
    while(a[j]<x){
        i=j;
        j=2*j;
    }
    return binary_search(a,i,j,x);
}





