#include"Car.h"
Car::Car(string v, string m, string mo, int y, float p, string c){
    VIN = v;
    Make = m;
    Model = mo;
    Year = y;
    Price = p;
    Category = c;
}

Car :: Car(){
    VIN = "";
    Make = "";
    Model = "";
    Year = 0;
    Price = 0;
    Category = "";
}
void Car :: setVIN(string v){
    VIN = v;
}
string Car :: getVIN(){
    return VIN;
}
void Car :: setMake(string m){
    Make = m;
}
string Car :: getMake(){
    return Make;
}

void Car :: setModel(string mo){
    Model = mo;
}

string Car :: getModel(){
    return Model;
}
void Car :: setYear(int y){
    Year = y;
}
int Car :: getYear(){
    return Year;
}
void Car :: setPrice(float p){
    Price = p;
}

float Car :: getPrice(){
    return Price;
}
void Car :: setCategory(string c){
    Category = c;
}
string Car :: getCategory(){
    return Category;
}
void Car :: print(){
    cout<<VIN<<" "<<Make<<" "<<Model<<" "<<Year<<" "<<Price<<" "<<Category;
}
