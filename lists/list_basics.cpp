#include <iostream>
#include <list>
#include <ctime>

using namespace std; //using standard namespace


int main(){
    
    list<int> lst; //Create an empty list
    unsigned int i;
    srand(time(NULL));//seed RNG
    list<int>::iterator it; //iterator
    
    for(i=0;i<10;i++){
        lst.push_back(i);
    }
    
    cout << "Size: " << lst.size() << endl << endl; //Size of list
    
    cout << "Contents: ";
    
    for(it = lst.begin();it!= lst.end();it++){
        cout << *it << " ";
    }
    cout << endl << endl;
    
    //change contents
    
    for(it = lst.begin();it!=lst.end();it++){
        *it+=100;
    }
    cout << "New Contents: ";
    
    for(it = lst.begin();it!= lst.end();it++){
        cout << *it << " ";
    }
    cout << endl<<endl;
    
    //reversed print
    cout << "Reverse Contents: ";
    it = lst.end();
    while(it!=lst.begin()){
        it--; //end points to last plus one location. Need to depricate before pointing to last location
        cout << *it << " ";
    }
    cout << endl << endl;
    
    //erasing complete list
    lst.erase(lst.begin(),lst.end()); //or use lst.clear();
    
    
    for (i=0;i<10;i++){
        lst.push_front(rand()%20);
    }
    
    cout << "Original Contents: ";
    
    for(it = lst.begin();it!= lst.end();it++){
        cout << *it << " ";
    }
    cout << endl << endl;
    
    //sort the list
    cout << "Sorted Contents: ";
    lst.sort();
    
    for(it = lst.begin();it!=lst.end();it++){
        cout << *it << " ";
    }
    cout << endl << endl;
    
    //Clear list
    lst.clear();
    
    if(lst.empty()){cout << "list erased" << endl << endl;}
    
    //Merging list
    list <int> lst2;
    
    for(i=0;i<10;i++){
        lst.push_back(rand()%10);
        lst2.push_back(rand()%10);
    }
    
    cout << "First List: ";
    for(it = lst.begin();it!=lst.end();it++){
        cout << *it << " ";
    }
    cout << endl << endl;
    
    cout << "Second List: ";
    for(it = lst2.begin();it!=lst2.end();it++){
        cout << *it << " ";
    }
    cout << endl << endl;
    
    //sort lists for merging. Merging works on sorted lists.
    lst.sort();
    lst2.sort();
    
    lst.merge(lst2);
    
    cout << "First List Merged with second: ";
    for(it = lst.begin();it!=lst.end();it++){
        cout << *it << " ";
    }
    cout << endl << endl;
    
    if(lst2.empty()){cout << "List 2 empty after merger" << endl << endl;}
    
    
    
    //Clear both lists
    lst.clear();
    lst2.clear();
    
    for(i=0;i<10;i++){
        lst.push_back(rand()%10);
        lst2.push_back(rand()%10);
    }
    
    cout << "First List: ";
    for(it = lst.begin();it!=lst.end();it++){
        cout << *it << " ";
    }
    cout << endl << endl;
    
    cout << "Second List: ";
    for(it = lst2.begin();it!=lst2.end();it++){
        cout << *it << " ";
    }
    cout << endl << endl;
    
    //Splicing lists together
    lst.splice(lst.end(),lst2); //splice second list at the end of first
    
    cout << "First List Spliced with second: ";
    for(it = lst.begin();it!=lst.end();it++){
        cout << *it << " ";
    }
    cout << endl << endl;
    
    if(lst2.empty()){cout << "List 2 empty after splicing" << endl << endl;}
    
    //Clear lists
    lst.clear();
    lst2.clear();
    
    for(i=0;i<10;i++){
        lst.push_back(rand()%10);
        lst2.push_back(rand()%10);
    }
    
    cout << "First List: ";
    for(it = lst.begin();it!=lst.end();it++){
        cout << *it << " ";
    }
    cout << endl << endl;
    
    cout << "Second List: ";
    for(it = lst2.begin();it!=lst2.end();it++){
        cout << *it << " ";
    }
    cout << endl << endl;
    
    //inserting part of second list to first
    it = lst.begin(); //iterator to lst
    advance(it,3); // move iterator to fourth element
    
    list<int>::iterator it2 = lst2.begin(); //iterator to second list
    advance(it2,4); // move iterator to point to fifth element
    
    lst.insert(it,lst2.begin(),it2);
    
    cout << "First List inserted with part of second: ";
    for(it = lst.begin();it!=lst.end();it++){
        cout << *it << " ";
    }
    cout << endl << endl;
    
    
    return 0;
}


