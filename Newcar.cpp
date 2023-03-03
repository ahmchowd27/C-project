#include "Newcar.h"
Newcar::Newcar(){
    Warrentyprovider = "";
    const float Mileage = 0.0;
    
}
Newcar :: Newcar(string v, string m, string mo, int y, float p, string c,int mile, string wp):
Car(v,m,mo,y,p,c){
    Warrentyprovider = wp;
    const float Mileage = mile;
}

void Newcar :: setWarrentyprovider(string wp){
    Warrentyprovider = wp;
}
string Newcar :: getWarrentyprovider(){
    return Warrentyprovider;
}
const float Newcar :: getMileage(){
    return Mileage;
}
void Newcar :: print(){
    Car :: print();
    cout<<" "<<Mileage <<" " <<Warrentyprovider;
    
}
