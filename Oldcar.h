#include"Car.h"
class Oldcar: public virtual Car{
    private:
    int Mileage;
    public:
    void setMileage(int mile);
    int getMileage();
    Oldcar();
    Oldcar(string v, string m, string mo, int y, float p, string c,int mile);
    void print();
   
};