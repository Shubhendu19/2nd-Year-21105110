#include <iostream>                   
using namespace std;                  
class Node{
    public:   
    string name;
    int age;
    Node*next; 
    Node*prev;    
    Node(string name,int age){
        this->name=name;
        this->age=age;
        next=NULL; 
        prev=NULL; 
    }
};

void append(Node* &head,string name,int age){
    Node*temp=head;    
    Node*newNode=new Node(name,age);   
    if(temp==NULL){
        head=newNode;
    }
    else{
        while(temp->next!=NULL){temp=temp->next;}
        temp->next=newNode;
        newNode->prev=temp;
    }
}

void insert(Node*&head,string name,int age){
    
    Node*newNode=new Node(name,age);
    
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}

void displayHead(Node*head){
    Node*temp=head;
    while(temp!=NULL){cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]"<<"--";temp=temp->next;}
    cout<<endl;
}

void displayTail(Node*head){
    Node*temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    while(temp!=NULL){cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]"<<"--";temp=temp->prev;}
    cout<<endl;
}

void deleteN(Node*&head,int i){
    if(i==0){
        Node*temp=head;
        head=temp->next;
        head->prev=NULL;
        delete temp;
    }
    else{
        Node*temp=head;
        for(int j=0;j<i;j++){temp=temp->next;}
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }
}

void pop(Node*&head){
    Node*temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    temp->prev->next=NULL;
    delete temp;
}

int main(){   
    Node*head=NULL;
	int no_of_family_mem;   
	cout<<"Number of Members:";cin>>no_of_family_mem;    
	for(int i=1;i<=no_of_family_mem;i++){
		string name;
		int age;
		cout<<"Name "<<i<<":";cin>>name;
		cout<<"Age "<<i<<":";cin>>age;
        
		append(head,name,age);
	}
    cout<<endl;   
    cout<<"Result"<<endl;
    cout<<endl;
    displayHead(head);
}



