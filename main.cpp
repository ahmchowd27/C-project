#include <iostream>
using namespace std;
#include "Newcar.h"
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
int Menu() {
    cout<<"\n"<<setw(20)<< setfill('_')<< "" << "Welcome to Car Dealership!"<< setw(20)<<setfill('_')<<""<< endl;
    cout<< setw(10)<<setfill(' ')<< "" << "Please select the activity you want to perform:" << endl;
    cout << "       1. Search Inventory.  " << endl;
    cout << "       2. Sell/Lease Cars" << endl;
    cout << "       3. Return a Leased Car" << endl;
    cout << "       4. Add Cars to Inventory" << endl;
    cout << "       5. Exit" << endl;
    cout << "       Please Enter a Number: ";
    int option;
    cin >> option;
    return option;
}


void Search(int x) {
    ifstream Old("Oldcars.txt");
    ifstream New("Newcars.txt");
    string l;
    string vi, vi1;
    string m, m1;
    string mo, mo1;
    int y, y1;
    float p = 0.0, p1;
    string ca, ca1;
    float mi = 0.0, mi1;
    string wp, wp1;
    Car ob1;
    Newcar n1;
    size_t pos;
    int count = 0;
    int carcount = 1;
    if (x == 1) {
        cout << "\nEnter VIN: ";
        cin >> vi;

         ob1.setVIN(vi);

        while (Old.good()) {
            getline(Old, l);
            pos = l.find(ob1.getVIN());
            if (pos != string::npos) {
                cout <<"Car number" << carcount <<": "<< l << endl;
                break;
               
            }
            else if (New.good()) {
                getline(New, l);
                pos = l.find(ob1.getVIN());
                if (pos != string::npos) {
                    cout <<"Car number" << carcount <<": "<< l << endl << endl;
                     break;
                }
            }
            else {
                cout << "ARE YOU SURE YOU HAVE ENTERED THE RIGHT VIN" << endl << endl;
                break;
            }
        }
    }
    else if (x == 2) {

        cout << "\nEnter Make: ";
        cin >> m;  
        ob1.setMake(m);

        while (Old.good()) {
            getline (Old, l);
            pos = l.find(ob1.getMake());
            if (pos != string::npos) {
                cout <<"Car number" << carcount <<": "<< l << endl;
                carcount++;
                count++;
            }
            else if (New.good()) {
                getline(New, l);
                pos = l.find(ob1.getMake());
                if (pos != string::npos) {
                    cout <<"Car number" << carcount <<": "<< l << endl;
                    count++;
                }
            }
        }
        if (count == 0) {
            cout << "UNABLE TO FIND ANY CAR BY THIS MAKE COME BACK AGAIN AFTER RESTOCK :)" << endl;
        }
    }

    else if (x == 3) {

        cout << "\nEnter Model: ";
        cin >> mo;
        ob1.setModel(mo);

        while (Old.good()) {
            getline(Old, l);
            pos = l.find(ob1.getModel());
            if (pos != string::npos) {
                cout <<"Car number" << carcount <<": "<< l << endl;
                count++;
            }
            else if (New.good()) {
                getline(New, l);
                pos = l.find(ob1.getModel());
                if (pos != string::npos) {
                    cout <<"Car number" << carcount <<": "<< l << endl;
                    carcount++;
                    count++;
                }
            }
        }
        if (count == 0) {
            cout << "SORRY THERE ARE NO CAR AVAILABLE BY THIS MODEL" << endl << endl;
        }

    }
    else if (x == 4) {
        int yp;
        cout << "\n.              Wich Way you want look for the car?" << endl;
        cout << "                       1. By an individual year" << endl;
        cout << "                       2.By year range" << endl;
        cout << "\n.                    Please Enter your choice: ";
        cin >> yp;
        if (yp>2&&yp<1){
            cout<<"INALID OPTION!!";
        }
       else if (yp == 1) {
            cout << " \n.               Enter the individual year: ";
            cin >> y;
            while (Old >> vi1 >> m1 >> mo1>> y1 >> p1 >> ca1 >> mi1>> wp1 || New >> vi1 >> m1 >> mo1 >> y1>> p1 >> ca1 >> mi1 >> wp1) {
                if (y == y1) {
                    Oldcar oc2(vi1, m1, mo1, y1, p1, ca1, mi1);
                    Newcar nc2(vi1, m1, mo1, y1, p1, ca1, mi1,wp1);
                    nc2.print();
                    //oc2.print();
                    cout<<endl;
                    carcount++;
                    count++;
                }
            }
        }
        else if (yp == 2) {
            int ly, hy;
            cout << "               Enter the lowest year for a vehicle: ";
            cin >> ly;
            cout << "               Enter the highest year for a vehicle: ";
            cin >> hy;
            while (Old >> vi1 >> m1 >> mo1 >> y1 >> p1 >> ca1 >> mi1 >> wp1 || New >> vi1 >> m1>> mo1 >> y1 >> p1 >> ca1 >> mi1 >> wp1) {
                if (ly <= y1 && hy >= y1) {
                    Oldcar oc2(vi1, m1, mo1, y1, p1, ca1, mi1);
                    Newcar nc2(vi1, m1, mo1, y1, p1, ca1, mi1, wp1);
                    nc2.print();
                    cout<<endl;
                    carcount++;
                    count++;
                    
               }
            }
        }
        if (count == 0) {
            cout << "OOPS!! WE ARE UNABLE TO FIND ANY CAR WITH THIS YEAR :(" << endl << endl;
        }
    }

    else if (x == 5) {
        
            int lp, hp;
            cout << "                  Enter the lowest price range: $";
            cin >> lp;
            cout << "                  Enter the highest price range: $";
            cin >> hp;
            while (Old >> vi1 >> m1 >> mo1 >> y1 >> p1 >> ca1 >> mi1 >> wp1 || New >> vi1 >> m1 >> mo1 >> y1 >> p1 >> ca1 >> mi1 >> wp1) {
                if (lp <= p1 && hp >= p1) {
                    Oldcar oc2(vi1, m1, mo1, y1, p1, ca1, mi1);
                    Newcar nc2(vi1, m1, mo1, y1, p1, ca1, mi1, wp1);
                    cout<<"Car number:"<< carcount; nc2.print();
                    cout<<endl;
                    carcount++;
                    count++;
                }
            }
            if (count == 0) {
            cout << "### OOPS!!! WE DONT HAVE ANY CAR IN THIS  CRITERIA ### :(" << endl << endl;
        }

        }
        
       else if (x == 6) {
            int lm, hm;
            cout << "        \nEnter the lowest mileage: ";
            cin >> lm;
            cout << "         Enter the highest mileage: ";
            cin >> hm;

            if (lm == 0 && hm == 0) {
                while (New >> vi1 >> m1 >> mo1 >> y1 >> p1 >> ca1 >> mi1>> wp1) {
                    if (lm <= mi1 && hm >= mi1) {
                        Newcar nc2(vi1, m1, mo1, y1, p1, ca1, mi1,wp1);
                        nc2.print();
                        cout<<endl;
                        count++;
                    }
                }
            }
            else if (lm > 0 && hm > 0) {
                while (Old >> vi1 >> m1 >> mo1 >> y1 >> p1 >> ca1>> mi1 >> wp1) {
                    if (lm <= mi1 && hm >= mi1) {
                        Oldcar oc2(vi1, m1, mo1, y1, p1, ca1, mi1);
                        oc2.print();
                        cout<<endl;
                        count++;
                    }
                }
            }
            else if (lm == 0 && hm > 0) {
                while (Old >> vi1 >> m1 >> mo1 >> y1 >> p1 >> ca1 >> mi1 >> wp1) {
                    if (lm <= mi1 && hm >= mi1) {
                        Newcar nc2(vi1, m1, mo1, y1, p1, ca1, mi1, wp1);
                        Oldcar oc2(vi1, m1, mo1, y1, p1, ca1, mi1);
                        cout <<"Car number" << carcount <<": ";oc2.print();
                        cout<<endl;
                        //carcount++; 
                        count++;
                    }
                }
                while (New >> vi1 >> m1>> mo1 >> y1 >> p1 >> ca1 >> mi1 >> wp1) {
                    if (lm <= mi1 && hm >= mi1) {
                        Newcar nc2(vi1, m1, mo1, y1, p1, ca1, mi1, wp1);
                        cout <<"Car number" << carcount <<": ";nc2.print();
                        cout<< endl;
                        //carcount++;
                        count++;
                        
                    }
                }
                if (count == 0) {
            cout << "### OOPS!!! WE DONT HAVE ANY CAR IN THIS MILEAGE CRITERIA ### :(" << endl << endl;
        }

            }
        }
        
}
void Search() {
    cout<<"\n"<<setw(20)<< setfill('_')<< "" << "How would you like to search for a car?"<<setw(20)<< setfill('_')<< "" << endl;
    cout << "        1. Search by VIN" << endl;
    cout << "        2. Search by Make" << endl;
    cout << "        3. Search by Model" << endl;
    cout << "        4. Search by Year" << endl;
    cout << "        5. Search by Price" << endl;
    cout << "        6. Search by Mileage\n" << endl;
    int searchchoice;
    cout << "\nPlease Enter a Number: ";
    cin >> searchchoice;
    switch (searchchoice) {
    case 1:
        Search(1);
        break;
    case 2:
        Search(2);
        break;
    case 3:
        Search(3);
        break;
    case 4:
        Search(4);
        break;
    case 5:
        Search(5);
        break;
    case 6:
        Search(6);
        break;
        default:
        cout<<"Wrong Entry\n";
    }
}

void sellOldCar() {
    ifstream Old;
    string find = "Oldcars.txt";
    Old.open(find);


    string length;
    ofstream temp("temp.txt");
    string vi, vi1;
    string m, m1;
    string mo, mo1;
    int y = 0, y1;
    float p = 0.0, p1;
    string ca, ca1;
    int mi = 0, mi1;
    string wp, wp1;
    int count = 0;
    cout << "Enter VIN: ";
    cin >> vi;
    while (Old >> vi1 >> m1>> mo1 >> y1 >> p1 >> ca1 >> mi1>> wp1) {
        if (vi1 == vi) {
            count++;
        }
        else{
            Oldcar oc2(vi1, m1, mo1, y1, p1, ca1, mi1);
            temp << oc2.getVIN() << " " << oc2.getMake() << " " << oc2.getModel() << " " << oc2.getYear() << " " << oc2.getPrice() << " " << oc2.getCategory()
                << " " << oc2.getMileage() << " " << "UK" << endl;
        }
    }
    if (count == 0) {
        cout << "### OPPS! WE DONT HAVE ANY CAR WITH THIS VIN ####" << endl;
    }
    
    temp.close();
    Old.close();

   

    const char*a = find.c_str();
    remove(a);
    rename("temp.txt", a);
}

void sellNewCar() {
    ifstream New;
    string ost = "Newcars.txt";
    New.open(ost);


    string line;
    ofstream temp2("temp2.txt");
    string vi, vi1;
    string m, m1;
    string mo, mo1;
    int y, y1;
    float p = 0.0, p1;
    string ca, ca1;
    float mi = 0.0, mi1;
    string wp, wp1;
    int count = 0;
    cout << "           Enter VIN: ";
    cin >> vi;
    while (New >> vi1 >> m1>> mo1 >> y1 >> p1 >> ca1 >> mi1 >> wp1) {
        if (vi1 == vi) {
            count++;
        }
        if (vi1 != vi) {
            Newcar nc2(vi1, m1, mo1, y1, p1, ca1, mi1, wp1);
            temp2 << nc2.getVIN() << " " << nc2.getMake() << " " << nc2.getModel() << " " << nc2.getYear() << " " << nc2.getPrice() << " " << nc2.getCategory()
                << " " << nc2.getMileage() << " " << nc2.getWarrentyprovider() << endl;
        }
    }
   
    if (count == 0) {
        cout << "### OPPS! WE DONT HAVE ANY CAR WITH THIS VIN ####" << endl;
    }
    temp2.close();
    New.close();


    const char* c = ost.c_str();
    remove(c);
    rename("temp2.txt", c);
}

void leaseOldCar() {
    ifstream Old;
    string path = "Oldcars.txt";
    Old.open(path);

    string line;
    ofstream temp("temp.txt");
    ofstream makeLease;
    ifstream takeLease;
    takeLease.open("CarOnLease.txt");

    makeLease.open("CarOnLease.txt", ios::in|ios::out|ios::ate);
    string vi, vi1;
    string m, m1;
    string mo, mo1;
    int y = 0, y1;
    float p = 0.0, p1;
    string ca, ca1;
    float mi = 0.0, mi1;
    string wp, wp1;
    int count = 0;
    cout << "            Enter VIN: ";
    cin >> vi;
    
    while (Old >> vi1 >> m1 >> mo1 >> y1 >> p1 >> ca1 >> mi1 >> wp1) {
        if (vi1 == vi) {
            Oldcar oc2(vi1, m1, mo1, y1, p1, ca1, mi1);
            if (takeLease.is_open()) {
                makeLease << oc2.getVIN() << " " << oc2.getMake() << " " << oc2.getModel() << " " << oc2.getYear() << " " << oc2.getPrice() << " " << oc2.getCategory()
                    << " " << oc2.getMileage()<<" " << "UK"<<endl;
                takeLease.close();
                makeLease.close();
            }
            count++;
        }

        else if (vi1 != vi) {
            Oldcar oc2(vi1, m1, mo1, y1, p1, ca1, mi1);
            Newcar nc2(vi1, m1, mo1, y1, p1, ca1, mi1, wp1);
            temp << oc2.getVIN() << " " << oc2.getMake() << " " << oc2.getModel() << " " << oc2.getYear() << " " << oc2.getPrice() << " " << oc2.getCategory()
                << " " << oc2.getMileage()<<"UK"<< endl;
        }
    }

    if (count == 0) {
        cout << "### OPPS! WE DONT HAVE ANY CAR WITH THIS VIN #### :(:("<< endl;
    }
    temp.close();
    Old.close();


    const char* k = path.c_str();
    remove(k);
    rename("temp.txt", k);
}

void leaseNewCar() {
    ifstream New;
    string path = "Newcars.txt";
    New.open(path);

    string line;
    ofstream temp("temp.txt");
    ofstream makeLease;
    ifstream takeLease("CarOnLease.txt");
    
    makeLease.open("CarOnLease.txt", ios::in|ios::out|ios::ate);
    string vi, vi1;
    string m, m1;
    string mo, mo1;
    int y = 0, y1;
    float p = 0, p1;
    string ca, ca1;
    float mi = 0, mi1;
    string wp, wp1;
    int count = 0;
    cout << "Enter VIN: ";
    cin >> vi;
    
    while (New >> vi1 >> m1 >> mo1 >> y1 >> p1 >> ca1 >> mi1 >> wp1) {
        if (vi1 == vi) {
            Newcar newcar2(vi1, m1, mo1, y1, p1, ca1, mi1, wp1);
            if (takeLease.is_open()) {
                makeLease << newcar2.getVIN() << " " << newcar2.getMake() << " " << newcar2.getModel() << " " << newcar2.getYear() << " " << newcar2.getPrice() << " " << newcar2.getCategory()
                    << " " << newcar2.getMileage() << " " << newcar2.getWarrentyprovider() << endl;
                makeLease.close();
                takeLease.close();
            }
            count++;
        }

        else if (vi1 != vi) {

            Newcar nc2(vi1, m1, mo1, y1, p1, ca1, mi1, wp1);
            temp << nc2.getVIN() << " " << nc2.getMake() << " " << nc2.getModel() << " " << nc2.getYear() << " " << nc2.getPrice() << " " << nc2.getCategory()
                << " " << nc2.getMileage() << " " << nc2.getWarrentyprovider() << endl;
        }
    }

    if (count == 0) {
        cout << "### OPPS! WE DONT HAVE ANY CAR WITH THIS VIN ####"<<endl;
    temp.close();
    New.close();


    const char* pp = path.c_str();
    remove(pp);
    rename("temp.txt", pp);
}
}

void SellOrLease() {
    cout << "How do you want to make a purchase?" << endl;
    cout << "1. Sell a Car" << endl;
    cout << "2. Lease a Car" << endl;
    int sellorlease;
    cin >> sellorlease;
    switch (sellorlease) {
    case 1:
        cout << "Are you selling new or old car?" << endl;
        cout << "1. New Car" << endl;
        cout << "2. Old Car" << endl;
        int sellnewold;
        cin >> sellnewold;
        if (sellnewold == 1) {
            sellNewCar();
        }
        else if (sellnewold == 2) {
            sellOldCar();
        }
        break;
    case 2:
        cout << "Are you leasing new or old car?" << endl;
        cout << "1. New Car" << endl;
        cout << "2. Old Car" << endl;
        int leasenewold;
        cin >> leasenewold;
        if (leasenewold == 1) {
            leaseNewCar();
        }
        else if (leasenewold == 2) {
            leaseOldCar();
        }
        break;
    }
}


void returnLeasedCar() {
    
    ifstream OnLease;
    string path = "CarOnLease.txt";
    OnLease.open(path);

    string line;
    ofstream temp("temp.txt");
    ofstream makeReturn;
    ifstream takeReturn;
    takeReturn.open("Oldcars.txt");

    makeReturn.open("Oldcars.txt", ios::in|ios::out|ios::ate);
    string vi, vi1;
    string m, m1;
    string mo, mo1;
    int y = 0, y1;
    float p = 0.0, p1;
    string ca, ca1;
    int mi = 0, mi1;
    string wp, wp1;
    int count = 0;
    cout << "Enter VIN: ";
    cin >> vi;
    cout << "Enter Current Mileage: ";
    cin >> mi;
    while (OnLease >> vi1 >> m1>> mo1 >> y1 >> p1 >> ca1 >> mi1 >> wp1) {

        if (makeReturn.is_open()) {
        if (vi == vi1 && mi <= mi1) {
            cout << "   !!!!!YOUR MILEAGE MUST BE HIGHER THAN THE TIME OF LEASE!!!!!! :(   " << endl;
            Oldcar oc2(vi1, m1, mo1, y1, p1, ca1, mi1);
            Newcar nc2(vi1, m1, mo1, y1, p1, ca1, mi1, wp1);
            temp << oc2.getVIN() << " " << oc2.getMake() << " " << oc2.getModel() << " " << oc2.getYear() << " " << oc2.getPrice() << " " << oc2.getCategory()
                << " " << oc2.getMileage() << " " << "NA" << endl;
            count++;
        }
            
            else if (mi > mi1) {
                if (vi == vi1) {
                    Oldcar oc2(vi1, m1, mo1, y1, p1, ca1, mi);
                    Newcar nc2(vi1, m1, mo1, y1, p1, ca1, mi, wp1);


                    makeReturn << nc2.getVIN() << " " << nc2.getMake() << " " << nc2.getModel() << " " << nc2.getYear() << " " << nc2.getPrice() << " " << nc2.getCategory()
                        << " " << mi << " " << nc2.getWarrentyprovider() << endl;
                    takeReturn.close();
                    makeReturn.close();
                    
                    count++;
                }
            }

            

                    else if (vi != vi1) {
                        Oldcar oc2(vi1, m1, mo1, y1, p1, ca1, mi1);
                        Newcar nc2(vi1, m1, mo1, y1, p1, ca1, mi1, wp1);
                        temp << oc2.getVIN() << " " << oc2.getMake() << " " << oc2.getModel() << " " << oc2.getYear() << " " << oc2.getPrice() << " " << oc2.getCategory()
                            << " " << oc2.getMileage() << endl;
                    }


        }
       
    }
    if (count == 0) {
        cout << "OOPS!!! YOUR MILEAGE MUST BE HIGHER THAN THE LAST RECORD AND YOUR VIN MUST MATCH!!!! :(" << endl << endl;
    }
    temp.close();
    OnLease.close();


    const char* d = path.c_str();
    remove(d);
    rename("temp.txt", d);
}
void AddNewCar(){
ifstream Old("Oldcars.txt");
ifstream New("Newcars.txt");
string l;
ofstream outnew;
ifstream innew;
innew.open("Newcars.txt");

outnew.open("Newcars.txt", ios::app);
string vi, vi1;
string m, m1;
string mo, mo1;
int y = 0, y1;
float p = 0.0, p1;
string ca, ca1;
float mi = 0.0, mi1;
string wp, wp1;
int count = 0;
cout << "Enter VIN: ";
cin >> vi;
while (Old >> vi1 >> m1 >> mo1 >> y1 >> p1 >> ca1 >> mi1 >> wp1 || New >> vi1 >> mo1 >> mo1 >> y1 >> p1 >> ca1 >> mi1 >> wp1) {
    if (vi == vi1) {
        cout << "       Seems like this car already exist :(" << endl;
        exit(1);
    }
}
cout << "      Enter Make: ";
cin >> m;
cout << "      Enter Model: ";
cin >> mo;
cout << "      Enter Year: ";
cin >> y;
cout << "      Enter Price: ";
cin >> p;
cout << "      Enter Category: ";
cin >> ca;
cout << "      Enter Warrenty Provider: ";
float dmi = 0.0;
cin >> wp;
    if (innew.is_open()) {
            outnew << vi << " " << m << " " << mo << " " << y << " " << p << " " << ca
                << " " << dmi << " " << wp << endl;
            innew.close();
            outnew.close();
        }
        
    }



void AddOldCar() {
    ifstream Old("Oldcars.txt");
    ifstream New("Newcars.txt");
    string l;
    ofstream outold;
    ifstream inold;
    inold.open("Oldcars.txt");

    outold.open("Oldcars.txt", ios::app);
    string vi, vi1;
    string m, m1;
    string mo, mo1;
    int y = 0, y1;
    float p = 0.0, p1;
    string ca, ca1;
    float mi = 0.0, mi1;
    string wp, wp1;
    int count = 0;
    cout << "Enter VIN: ";
    cin >> vi;
    while (Old >> vi1 >> m1 >> mo1 >> y1 >> p1 >> ca1 >> mi1 >> wp1 || New >> vi1 >> m1 >> mo1 >> y1 >> p1 >> ca1 >> mi1 >> wp1) {
        if (vi == vi1) {
            cout << " Seems like this car already exist " << endl;
            exit(1);
        }
    }
    cout << "     Enter Make: ";
    cin >> m;
    cout << "     Enter Model: ";
    cin >> mo;
    cout << "     Enter Year: ";
    cin >> y;
    cout << "     Enter Price: ";
    cin >> p;
    cout << "     Enter Category: ";
    cin >> ca;
    cout << "     Enter Mileage: ";
    cin >> mi;
    
    if (inold.is_open()) {
        outold << vi << " " << m << " " << mo << " " << y << " " << p << " " << ca
        << " " << mi<<" UK"<<endl;;
        inold.close();
        outold.close();
    }

}
    

    
void AddCar() {
    cout << "Are you adding a new or an old car?" << endl;
    cout << "1. New Car" << endl;
    cout << "2. Old Car" << endl;
    cout << "Please Enter a number: ";
    int addop;
    cin >> addop;
    switch (addop) {
    case 1:
        AddNewCar();
        break;
    case 2:
        AddOldCar();
        break;
    }

}






int main()
{
    int Entry = Menu();
    while (Entry != 5) {
        switch (Entry) {
        case 1:
            Search();
            break;
        case 2:
            SellOrLease();
            break;
        case 3:
             returnLeasedCar();
             break;
         
         case 4:
             AddCar();
             break;
        }
    
    
         

       Entry = Menu();
        
    }
}
