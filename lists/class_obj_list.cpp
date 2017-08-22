//storing class objects in list

#include<iostream>
#include <list>
#include <ctime>

using namespace std;

class myclass{
  private: //by default private. But good practice to specify separately.
  int a,b,sum;
  public:
  myclass():a(0),b(0),sum(0){} //contructor with no input param
  myclass(int a, int b):a(a),b(b),sum(a+b){} //constructor with input params
  int getsum(){return sum;}
  //friend functions
  friend bool operator < (const myclass& obj1, myclass& obj2);
  friend bool operator > (const myclass& obj1, myclass& obj2);
  friend bool operator == (const myclass& obj1, myclass& obj2);
  friend bool operator != (const myclass& obj1, myclass& obj2);
};

bool operator < (const myclass& obj1, myclass& obj2){
    return obj1.sum < obj2.sum;
}

bool operator > (const myclass& obj1, myclass& obj2){
    return obj1.sum > obj2.sum;
}

bool operator == (const myclass& obj1, myclass& obj2){
    return obj1.sum == obj2.sum;
}

bool operator != (const myclass& obj1, myclass& obj2){
    return obj1.sum != obj2.sum;
}

int main(){
    
    unsigned short int i;
    
    list<myclass> lst1,lst2;
    
    //create first list
    for(i=0;i<10;i++){
        lst1.push_back(myclass(i,i)); //push needs the data type of the list as input param.
    }
    
    cout << "First List: ";
    
    list<myclass>::iterator it1 = lst1.begin();
    for(;it1!=lst1.end();it1++){
        cout << it1->getsum() << " ";
    }
    cout << endl << endl;
    
    //create second list
    for(i=0;i<10;i++){
        lst2.emplace_back(i*2,i*3); //Emplace used for constructing and inserting element at end.
                                    //Automatically constructs the element of the data type of the list. 
    }
    
    cout << "Second List: ";
    
    list<myclass>::iterator it2 = lst2.begin();
    for(;it2!=lst2.end();it2++){
        cout << it2->getsum() << " ";
    }
    cout << endl << endl;
    
    //Merging lists
    
    lst1.merge(lst2);
    
    cout << "First List merged with second: ";
    
    for(it1=lst1.begin();it1!=lst1.end();it1++){
        cout << it1->getsum() << " ";
    }
    cout << endl << endl;
    
    
    //Sorting radom list of class Object
    
    list<myclass> lst3;
    srand(time(NULL)); //Seed RNG
    for(i = 0;i<10;i++){
        lst3.emplace_back(rand()%10,rand()%10);
    }
    
    cout << "Random list is: ";
    for (it1 = lst3.begin();it1!=lst3.end();it1++){
        cout << it1->getsum() << " ";
    }
    cout << endl << endl;
    
    //Sort list
    lst3.sort();
    
    cout << "Sorted list is: ";
    for (it1 = lst3.begin();it1!=lst3.end();it1++){
        cout << it1->getsum() << " ";
    }
    cout << endl << endl;
    
    return 0;
}