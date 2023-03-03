#include "Oldcar.h"
void Oldcar :: setMileage(int mile){
    Mileage = mile;
}
int Oldcar:: getMileage(){
    return Mileage;
}

Oldcar :: Oldcar(){
    Mileage = 0;
}

Oldcar::Oldcar(string v, string m, string mo, int y, float p, string c,int mile):
Car(v,m,mo,y,p,c){
    Mileage = mile;
}
void Oldcar :: print(){
    Car :: print();
    cout<<" "<<Mileage;
    
}
