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
        //Dependency
        BoschTPMS* tpmsObjPtr;
        public:
        //Constructor Dependency injection
         Car(BoschTPMS* tpms): tpmsObjPtr{tpms}{
            cout<<"Car Constructed "<<endl;
        }
        ~Car(){
            cout<<"Car Destructed "<<endl;
        }
        // method dependency injection
        void installTPMS(BoschTPMS* tpmsPtr){
          this->tpmsObjPtr{tpmsPtr};
        }
};
void buildCar(BoschTPMS* ptr){
        Car car{ptr};//Dependendency Injection By Hand
}

int main() {
    // Write C++ code here
    BoschTPMS tpms;
    buildCar(&tpms);
    cout<<"Car Completely Destructed"<<endl;
    return 0;
}
