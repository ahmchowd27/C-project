#include "Oldcar.h"
class Newcar: public virtual Car{
    private:
    string Warrentyprovider;
    const float Mileage = 0.0;
    
    public:
    void setWarrentyprovider(string wp);
    string getWarrentyprovider();
    const float getMileage();
    Newcar();
    Newcar(string v, string m, string mo, int y, float p, string c,int mile, string wp);
    void print();
    
};