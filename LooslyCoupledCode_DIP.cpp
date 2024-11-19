// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class ITPMSValueProvider{
    public:
    virtual int getPSIValues()=0;
};
class NexDigitronTPMS:public ITPMSValueProvider{
  public:
        NexDigitronTPMS(){
            cout<<"NexDigitron TPMS Constructed "<<endl;
        }
         ~NexDigitronTPMS(){
            cout<<"NexDigitron TPMS Destructed "<<endl;
    }
        int getPSIValues(){ return 0;}
};
class BoschTPMS:public ITPMSValueProvider{
    public:
BoschTPMS(){
            cout<<"Bosch TPMS Constructed "<<endl;
    }
    ~BoschTPMS(){
            cout<<"Bosch TPMS Destructed "<<endl;
    }
    int getPSIValues(){ return 0;}
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
        ITPMSValueProvider* tpmsObjPtr;
        public:
        //Constructor Dependency injection
         Car(ITPMSValueProvider* tpms): tpmsObjPtr{tpms}{
            cout<<"Car Constructed "<<endl;
        }
        ~Car(){
            cout<<"Car Destructed "<<endl;
        }
        // method dependency injection
        void installTPMS(ITPMSValueProvider* tpmsPtr){
          this->tpmsObjPtr=tpmsPtr;
        }
};
void buildCarWithBoschTpms(BoschTPMS* ptr){
        Car car{ptr};//Dependendency Injection By Hand
}

void buildCarWithNextDigitromTpms(NexDigitronTPMS* ptr){
        Car car{ptr};//Dependendency Injection By Hand
}

int main() {
    // Write C++ code here
    BoschTPMS tpms;
    buildCarWithBoschTpms(&tpms);

    NexDigitronTPMS ndTpms;
    buildCarWithNextDigitromTpms(&ndTpms);

    cout<<"Car Completely Destructed"<<endl;
    return 0;
}
