//merge sort recursive
#include <bits/stdc++.h>
using namespace std;

//this node class
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

// take input function and input would be ended if you enetered -1
node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}

//print linked list function
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//merge two sorted linked list
node* mergeTwoLLs(node *head1, node *head2) {
    node * ft ;
    node * fh ;    
        
    if( head1 == NULL){
        return head2;
    }
    if( head2 == NULL){
        return head1;
    }
    
    if( head1->data < head2->data){
        fh= head1;
        ft = head1;
        head1 = head1->next;
    }
    else{
        fh = head2;
        ft = head2;
        head2 = head2->next;
    }
    
    while(head1 != NULL && head2 != NULL){
        if(head1->data > head2->data){
                ft -> next = head2;
                ft = ft -> next;
                head2 = head2 -> next;       
        }
        else{
                ft -> next = head1;
                ft = ft -> next;
                head1 = head1 -> next;  
        }
    }
    if(head1==NULL){
        ft -> next = head2;
    }
    else{
        ft -> next = head1;
    }    
    return fh;
}

//mergesort function in linked list
node* mergeSort(node *head) {
    if( head == NULL || head->next == NULL){
        return head;
    }
    
    int c=0;
    node *temp =head;
    
    //find the size of linked list
    while( temp != NULL){
        c++;
        temp= temp->next;
    }
    
    //this is the middle of the linked list
    int m = c/2;
    
    temp=head;
    for(int i=0;i<m-1;i++){
        temp = temp -> next;
    }
    
    //head1 for the next array
    node *head1 = temp->next;
    temp->next =NULL;
    
    
    head = mergeSort(head);
    head1 = mergeSort(head1);
    return mergeTwoLLs(head,head1);
    
}

//main function
int main()
{
    node* head=takeinput();
    head= mergeSort(head);
    print(head);
    return 0;
}