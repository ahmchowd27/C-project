#include<iostream>
#include<string>
using namespace std;
class Car{
private:
string VIN;
string Make;
string Model;
int Year;
float Price;
string Category;

public:
void setVIN(string v);
string getVIN();
void setMake(string m);
string getMake();
void setModel(string mo);
string getModel();
void setYear(int y);
int getYear();
void setPrice(float p);
float getPrice();
void setCategory(string c);
string getCategory();
Car(string v, string m, string mo, int y, float p, string c);
Car();
virtual void print();
};