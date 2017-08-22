#include <iostream>
#include <vector>
#include <ctime>

using namespace std; //using standard namespace

//Daily temperatures class
class DailyTemp{
    
    int temp; //temp is private by default
    
    public:
    DailyTemp():temp(0){} //Constructor
    DailyTemp(int x):temp(x){} //Constructor
    DailyTemp& operator =(int x){ //Overloading '=' operator
        temp = x;
        return *this;
    }
    
    double get_temp(){return temp;}
    
};

//overloading '<' operator to compare two DailyTemp objects
bool operator < (DailyTemp& a, DailyTemp& b){
    return a.get_temp() < b.get_temp();
}

//overloading '==' operator to compare two DailyTemp objects
bool operator == (DailyTemp& a, DailyTemp& b){
    return a.get_temp() == b.get_temp();
}

int main(){
   srand(time(NULL)); //seed rndom number generator
    
    vector<DailyTemp> v;
    unsigned int i;
    
    for(i = 0;i<7;i++){
        v.push_back(DailyTemp(60 + rand()%30));
    }
    
    cout << "Farenheit Temp : \n";
    for(i=0;i<v.size();i++){
        cout << v[i].get_temp() << " ";
    }
    cout << endl;

//Farenheit to Centigrade
vector<DailyTemp> z(v); //copy vector v to z
for(i = 0; i < v.size();i++){
   z[i] = (v[i].get_temp()-32)*5/9; //convert F to C
}
    cout << "Centigrade Temp : \n";
    for(i = 0;i<z.size();i++){
        cout << z[i].get_temp() << " ";
    }
    cout << endl;
    
    return 0;
}