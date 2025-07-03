#include<iostream>
using namespace std;

#define MAX 50

int arr[MAX];

int n=0;

void insertAtBeginning(int value){
    if(n==MAX){
        cout<<"List is full ";
        return;
    }
    for(int i = n;i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=value;
    n++;
}

void insertAtEnd(int value){
    if(n==MAX){
        cout<<"List is full ";
        return;
    }
    arr[n]=value;
    n++;
}

void insertAfter(int value,int key){
    if(n==MAX){
        cout<<"list is full ";
        return;
    }
    int pos=-1;
    for(int i=0;i<n;i++){
        if(key==arr[i]);
            pos=i;
            break;

    }
    if(pos==-1){
        cout<<"key not found ";
        return;
    }
    for(int i=n;i>pos+1;i--){
        arr[i]=arr[i-1];
    }
    arr[pos+1]=value;
    n++;

}

void display(){
    cout<<"\nList: \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
    return;
}

void deleteFromBeginning(){
    if(n==0){
        cout<<"list is empty";
        return;
    }
    for(int i=0;i<n;i++){
        arr[i]=arr[i+1];
        }
        n--;
    return;
}

void deleteFromEnd(){
    if(n==0){
        cout<<"list is empty";
        return;
    }
    n--;
}

void deleteAfterSpecific(int key){
    int pos=-1;
    for(int i=0;i<n;i++){
        if(key==arr[i]){
            pos=i;
                }
    }
    for(int i=pos+1;i<n;i++){
        arr[i]=arr[i+1];
    }
    n--;

}

int main(){
    insertAtBeginning(32);
    insertAtEnd(43);
    display();
    insertAfter(100,32);
    display();
    deleteFromBeginning();
    display();
    insertAtBeginning(999);
    deleteAfterSpecific(999);
    display();

return 0;
}
