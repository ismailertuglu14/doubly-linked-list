//
//  main.cpp
//  linked-list
//
//  Created by İsmail Ertuğlu on 13.11.2022.
//

#include <iostream>
//#include <stdlib.h>

using namespace std;


struct Node{
    int value;
    Node* next;
    Node* prev;
};

class LinkedList{
    
private:
    Node* head;
    Node* tail;
    Node* iterate;
    int length;
public:
    LinkedList(){
        head = NULL;
        tail = NULL;
        length = 0;
    }
    
    /// Create a New Node and add to head
    void addToHead(int value);
    /// Create a New Node and add to tail
    void addToTail(int value);
    /// Create a New Node between any index, left or right
    void addToBetween(int value,int target,char direction);
    /// Delete Node
    void deleteNode(int target);
    /// Print all nodes
    void printNodes();
    
};



int main(int argc, const char * argv[]) {
    // insert code here...
    LinkedList l;
    
    cout << "Hello, World!\n";

    l.addToHead(1);
    l.addToTail(2);
    l.addToTail(3);
    l.addToBetween(7, 2, 'r');
    l.addToHead(4);
    l.addToTail(5);
    //l.deleteNode(5);
  //  l.deleteNode(2);

    l.printNodes();
    
    return 0;
}

void LinkedList::addToHead(int value){
    Node* newNode = new Node;
    newNode->value = value;
    length++;
    if(head == NULL){
        newNode->next = NULL;
        newNode->prev = NULL;
        head = newNode;
        tail = newNode;
    }else{
        newNode->prev = NULL;
        
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    
}

void LinkedList::addToTail(int value){
    Node* newNode = new Node;
    newNode->value = value;
    length++;
    if(head == NULL){
        newNode->next = NULL;
        newNode->prev = NULL;
        head = newNode;
        tail = newNode;
    }else{
        newNode->next = NULL;
        
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    
}
void LinkedList::addToBetween(int value, int target, char direction){
    this->iterate = this->head;
    // If linked list is empty
    if(head == NULL){
        cout<<"Linked list is Empty. Process executed";
    }else{
        bool isFinded = false;
        while(iterate){
            if(iterate->value == target){
                Node* newNode = new Node;
                newNode->value = value;
                isFinded = true;
                
                // add to left
                if(direction == 'l'){
                    iterate->prev->next = newNode;
                    iterate->prev =newNode;
                    newNode->next = iterate;
                    newNode->prev = iterate->prev;
                }
                
                // add to right
                if(direction == 'r'){
                    iterate->next->prev = newNode;
                    newNode->next = iterate->next;
                    iterate->next = newNode;
                    newNode->prev = iterate;
                }
                               
                length++;
                break;
            }else{
                iterate = iterate->next;
            }
            
            
        }
        if(isFinded == false){
            cout<<"Target doesn't exist in linked list";
        }
    }
}
void LinkedList::deleteNode(int target){
    
    bool isExist = false;
    Node* temp = this->head;
    if(head == NULL){
        cout<<"Linked list is empty"<<endl;
        return;
        
     // Delete Node from head
    }else if(this->head->value == target){
        head = temp->next;
        delete temp;
        length--;
        
        
    }else if(this->tail->value == target){
   
        temp = tail->prev;
        delete tail;
        temp->next = NULL;
        tail = temp;
        length--;
        
        
    //Delete Node from between
    }else{
        this->iterate = this->head;
        length--;
        while(iterate){
            // Sorunu çöz listeyi basmıyo
            if(iterate->value == target){
                temp = iterate;
                iterate->prev->next= iterate->next;
                iterate->next->prev = iterate->prev;
                delete temp;
            }
                
        }
        // If target doesn't exist
        if(!isExist){
            cout<<"Target doesn't exist in the linked list!"<<endl;
        }
        
    }
    
    
    
}
void LinkedList::printNodes(){
            
    Node * iterate = this->head; //start from head
    int size = 0;
    // this is equals to iterate != NULL
    while(iterate){
        cout<<iterate->value<<" ";
        iterate = iterate->next;
        size += sizeof(iterate->value);
    }
    cout<<"\nTotal length => "<<length<<endl;
    cout<<"Total size of Node values => "<<size<<endl;
}

