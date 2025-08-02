#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next=NULL;
        Node(int data){
            this ->data=data;
        }
        void assignNext(Node* temp){
            next=temp;
        }
        int getData(){
            return data;
        }
        Node* getNext(){
            return next;
        }
};

int main(){
    Node* newNode= new Node(10);
    cout<<"hi"<<endl;
    int getData=newNode->getData();
    cout<<getData<<endl;
}