//Singly Linked list implementation
//https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr

#include <iostream>

using namespace std;

template <class T>
struct Node{
    Node* next;
    T data;
};

template <class T>
class List{
  private:
  Node<T> *head,*tail;
  
  public:
  List(){head = NULL; tail=NULL;}
  void createNode(T value);
  void display();
  void insertStart(T value);
  void insertPosition(int pos,T value);
  void deleteStart();
  void deleteLast();
  void deletePosition(int pos);
  
};

template <class T>
void List<T>::createNode(T value){
    Node<T>* temp = new Node<T>;
    temp->data = value;
    temp->next = NULL;
    
    if(head==NULL){
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else{
        tail->next = temp;
        tail = temp;
        
    }
}

template <class T>
void List<T>::display(){
    Node<T>* temp = new Node<T>;
    temp = head;
    while(temp != NULL){
        cout << temp->data << '\t';
        temp = temp->next;
    }
}

template <class T>
void List<T>::insertStart(T value){
    Node<T>* temp = new Node<T>;
    temp->data = value;
    temp->next = head;
    head = temp;
}

template <class T>
void List<T>::insertPosition(int pos,T value){
    Node<T>* temp = new Node<T>;
    Node<T>* current = new Node<T>;
    Node<T>* previous = new Node<T>;
    current = head;
    for(int i = 1; i<pos;i++){
        previous = current;
        current = current->next;
    }
    temp->data = value;
    previous->next = temp;
    temp->next = current;
}

template <class T>
void List<T>::deleteStart(){
    Node<T>* temp  = new Node<T>;
    temp = head;
    head = temp->next;
    delete temp;
}

template <class T>
void List<T>::deleteLast(){
    Node<T>* current = new Node<T>;
    Node<T>* previous = new Node<T>;
    current = head;
    while(current->next!=NULL){
        previous = current;
        current = current->next;
    }
    previous->next = NULL;
    tail = previous;
    delete current;
    
}

template <class T>
void List<T>::deletePosition(int pos){
    Node<T>* current = new Node<T>;
    Node<T>* previous = new Node<T>;
    current = head;
    for(int i = 1;i<pos;i++){
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    delete current;
}

int main(){
    List<int> obj;
	obj.createNode(25);
	obj.createNode(50);
	obj.createNode(90);
	obj.createNode(40);
	cout<<"\n--------------------------------------------------\n";
	cout<<"---------------Displaying All nodes---------------";
	cout<<"\n--------------------------------------------------\n";
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Inserting At End-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.createNode(55);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Inserting At Start----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insertStart(50);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-------------Inserting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insertPosition(5,60);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Deleting At Start-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.deleteStart();
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Deleing At End-------------------";
	cout<<"\n--------------------------------------------------\n";
	obj.deleteLast();
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"--------------Deleting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.deletePosition(4);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	return 0;
}