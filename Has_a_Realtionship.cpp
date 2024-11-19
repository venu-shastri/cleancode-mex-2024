// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class BoschTPMS{
    public:
BoschTPMS(){
            cout<<"Bosch TPMS Constructed "<<endl;
    }
    ~BoschTPMS(){
            cout<<"Bosch TPMS Destructed "<<endl;
    }
};
class Engine{
public:
    Engine(){
            cout<<"Engine Constructed "<<endl;
    }
    ~Engine(){
            cout<<"Engine Destructed "<<endl;
    }
};
class Car{
        //Contains,composition , death relationship
        Engine engineObj;
        //holds,Aggregation
        BoschTPMS tpmsObj;
        public:
         Car(){
            cout<<"Car Constructed "<<endl;
        }
        ~Car(){
            cout<<"Car Destructed "<<endl;
    }
};

int main() {
    // Write C++ code here
    Car car;
    return 0;
}
