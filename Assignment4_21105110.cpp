//Ans 1
// In-place means that the algorithm does not use extra space for manipulating the input but may require a small though non-constant extra space for its operation. Usually, this space is O(log n), though sometimes anything in O(n) (Smaller than linear) is allowed.

// Examples of in place Sorting Algorithms:-

// Bubble Sort
// Heap Sort
// Insertion Sort

// Examples of not in place Algorithms :-

// Merge Sort
// Radix Sort



//Ans 2
#include <iostream>
using namespace std;

void IP(int arr[],int n){
    
    int i=0,j=i+1;
    while(j<=n-1){
        int temp=arr[j];
        while(i>=0){
            if(arr[i]>temp){
                arr[i+1]=arr[i];
                i--;
            }
            if(i==-1){arr[0]=temp;break;}
            if(arr[i]<=temp){arr[i+1]=temp;break;}
        }
        j++;
        i=j-1;
    }
    return;
}


void OP(int arr[],int si,int ei){
    
    
    if(si==ei){return;}
    int j=si+1;
    int temp=arr[j];
    while(si>=0){
        if(arr[si]>temp){
            arr[si+1]=arr[si];
            si--;
        }
        if(si==-1){arr[0]=temp;break;}
        if(arr[si]<=temp){arr[si+1]=temp;break;}
    }
    OP(arr,si+1,ei);
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){cout<<arr[i]<<" ";}
}
int main(){
    int n;
    
    cout<<"Number of elements: ";
    cin>>n;
    int arr[n],arr2[n];
    cout<<"Elements seperated by space: ";
    for(int i=0;i<n;i++){cin>>arr[i];}
    
    for(int i=0;i<n;i++){arr2[i]=arr[i];}
    cout<<endl;
    cout<<"Before Sorting : ";display(arr,n);
    
    IP(arr,n);
    cout<<endl;
    cout<<"Array after in place  : ";
    
    display(arr,n);
    cout<<endl;
    
    OP(arr2,0,n-1);
    cout<<"Array after out place : ";
    
    display(arr,n);
    cout<<endl;

}



//Ans 3
// Lets consider an example
// If we want to reverse an array then its in-place algorithm
// will be swaping the first and last element of array until we reach the 
// middle of array
// If we want to solve the same problem using out-place 
// algorithm we have to create one extra array of same size and copy 
// elements of original array from back to the front of new array
// Thus out place algorith increases the space complexity to O(n) as we have creaed an 
// extra array.



















