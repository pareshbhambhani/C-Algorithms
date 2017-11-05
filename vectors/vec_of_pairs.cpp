#include  <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

//Function to print pairs
template <class C, class D>
void PrintCord(pair<C,D>& p){
    cout << "(" << p.first <<", " <<p.second <<") ";
}

//Overloading << to print pairs
template <typename C, typename D>
std::ostream& operator <<(ostream& os, const pair<C,D>& p){
    os << "(" << p.first <<", " <<p.second <<") ";
    return os;
}

int main(){
    
    srand(time(NULL));
    
    vector<pair<int,int>> vec;
    vec.emplace_back(1,1);
    
    //test print pair function
    PrintCord(vec[0]);
    cout << endl;
    
    for(int i = 0; i < 10; i++){
        vec.emplace_back(rand()%20,rand()%10);
    }
    
    //printing using overloaded << operator
    cout << "Vec is: \n";
    for(auto i:vec){
        cout << i << " ";
    }
    cout << endl;
    
    random_shuffle(vec.begin(),vec.end());
    
    cout <<"Shuffled vec is: \n";
    for(auto i:vec){
        cout << i << " ";
    }
    cout << endl;
    
    //Find a coordinate in vec
    
    pair<int,int> key(1,1);
    auto it = find_if(vec.begin(),vec.end(),[key](const pair<int,int>& p){return p == key;});
    if(it != vec.end()){
        cout << "Coordinate: " << key << " found at position " << (it - vec.begin()+1) << endl;
    }
    else{
        cout <<"Coordinate: " << key << " not found." << endl;
    }
    
    return 0;
}