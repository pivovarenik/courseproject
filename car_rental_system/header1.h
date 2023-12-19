#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <typeinfo>
#include <Windows.h>
#include <process.h>
#include <conio.h>
#include <vector>
#include <fstream>
#include <iterator>
#include <chrono>
#include <ctime>
#include <chrono>
#include <memory>
#include <sstream>
using namespace std;

class Printable {
public:
    virtual void saveToFile(std::ofstream& out) const = 0;
    virtual void button(int x, int y) = 0;
};
class Car : public Printable {
    string body;
    string type;
    string name;
    float engine_capacity;
    string fuel_type;
    string transmission;
    float fuel_use;
    int booked;
    float cost;
public:
    Car()
    {
        body = "Седан";
        fuel_type = "Бензин";
        transmission = "Автомат";
        booked = 0;
        fuel_use = 6.6;
        type = "Легковой автомобиль";
        name = "Volkswagen Passat";
        engine_capacity = 1.6;
        cost = 10;
    };
    string getbody() {
        return body;
    }
    string gettype() {
        return type;
    }
    string getfuel_type() {
        return fuel_type;
    }
    string getname() {
        return name;
    }
    string gettransmission() {
        return transmission;
    }
    float getcapacity() {
        return engine_capacity;
    }
    float getfuel_use() {
        return fuel_use;
    }
    float getcost() {
        return cost;
    };
    void setcost(float cost) {
        this->cost = cost;
    }
    int getbooked() {
        return booked;
    }
    void setbody(string body) {
        this->body = body;
    }
    void settype(string type) {
        this->type = type;
    }
    void setfuel_type(string type) {
        this->fuel_type = type;
    }
    void setname(string name) {
        this->name = name;
    }
    void settransmission(string trans) {
        this->transmission = trans;
    }
    void setcapacity(float capacity) {
        this->engine_capacity = capacity;
    }
    void setfuel_use(float fuel_use) {
        this->fuel_use = fuel_use;
    }
    void book() {
        booked++;
    }
    void unbook() {
        booked--;
    }
    void saveToFile(std::ofstream& out) const override;
    void loadFromFile(std::ifstream& in);
    void button(int x,int y) override;
    friend ostream& operator<<(ostream& out, Car car);
    bool operator==(Car other) const {
        if (this->body == other.body && this->name == other.name && this->type == other.type && this->cost == other.cost && this->engine_capacity == other.engine_capacity && this->fuel_type == other.fuel_type && this->fuel_use == other.fuel_use && this->transmission == other.transmission) {
            return true;
        }
        else return false;
    }
};

class Reservation;
class User {
protected:          
    string name;
    string surname;
    string login;
    string password;
public:
    static vector<Car> cars;
    static vector<Reservation> all_reservations;
    User() {
        login = "";
        password = "";
        name = "";
        surname = "";
        
    }
    void setAccountInfo(string login, string password,string name,string surname);
    string encryptPassword(const string& password);
    string getname();
    string getsurname();
    string getpassword();
    void register_();
    int login_();
    string getlogin();
    void setdata(User a);
    void changeAccountinfo();
    virtual ~User() {};
};

class Client : public User {
public:
    static vector<shared_ptr<Reservation>> my_reservations;
    Client() : User() {
        
    };
    Client(User a) {
        surname = a.getsurname();
        name = a.getname();
        login = a.getlogin();
        password = a.getpassword();

    }
    void choosecar();
    void cout_reservations();
    void notifications() {};
    void change_reservation();
    void getreservations();

};
struct Date {
    int day;
    int month;  
    int year;
    int input();
    bool operator==(Date& otherdate) {
        if (day == otherdate.day && month == otherdate.month && year == otherdate.year) {
            return true;
        }
        else return false;
    }
    friend istream& operator>>(istream& in, Date& input);
    friend ostream& operator<<(ostream& out, Date output);
    bool operator<(Date other) {
        if (year < other.year)
            return true;
        if (year > other.year)
            return false;
        if (month < other.month)
            return true;
        if (month > other.month)
            return false;
        return day < other.day;
    }
    bool operator>(Date other) {
        if (year > other.year)
            return true;
        if (year < other.year)
            return false;
        if (month > other.month)
            return true;
        if (month < other.month)
            return false;
        return day > other.day;
    }
    int operator-(const Date& other) const;
};

class Reservation : public Printable{
    string receiver_login;
    Car vehicle;
    Date acquisition_date;
    Date return_date;
public:
    string getcarname() {
        return vehicle.getname();
    }
    string getreceiver_login() {
        return receiver_login;
    }
    Date returnAcquisitiondate() {
        return acquisition_date;
    }
    Date returnReturnDate() {
        return return_date;
    }
    void setAcquisitionDate(Date date) {
        this->acquisition_date = date;
    }
    void setReturnDate(Date date) {
        this->return_date = date;
    }
    Car getcar() {
        return vehicle;
    }
    void loadFromFile(std::ifstream& in);
    float getcost() {
        return vehicle.getcost() * (return_date - acquisition_date);
    }
    void saveToFile(std::ofstream& out) const override;
    void button(int x, int y) override;
    void setdata(string login, Car vehicle, Date ac_date, Date return_date) {
        this->receiver_login = login;
        this->vehicle = vehicle;
        this->acquisition_date = ac_date;
        this->return_date = return_date;
    }
    void show();
    bool operator==(Reservation other) {
        if (acquisition_date == other.acquisition_date && return_date == other.return_date && receiver_login == other.receiver_login && vehicle == other.vehicle) {
            return true;
        }
        else return false;
    }
};
        
class Admin : public User {
    static void EraseCar(vector<Car> &x,int i) {
        int kol = 0, c =all_reservations.size();
        for (int j = 0; j < c; j++) {
            if (x[i] == all_reservations[j-kol].getcar()) {
                all_reservations.erase(all_reservations.begin() + j-kol);
                kol++;
            }
        }
        x.erase(cars.begin() + i);
    }
public:
    Admin() : User() {
        ifstream fin;
        Car temp;
        Reservation temp1;
        fin.open("C:\\Users\\USER\\Desktop\\baby_work\\car_rental_system\\info\\cars.txt");
        while (!fin.eof()) {
            temp.loadFromFile(fin);
            if (temp.gettype() == "") break;
            cars.push_back(temp);
        }
        fin.seekg(0);
        fin.close();
        fin.open("C:\\Users\\USER\\Desktop\\baby_work\\car_rental_system\\info\\reservations.txt");
        while (!fin.eof()) {
            temp1.loadFromFile(fin);
            if (temp1.getreceiver_login() == "") break;
            all_reservations.push_back(temp1);
        }
        fin.seekg(0);
        fin.close();
    };
    Admin(User a) {
        surname = a.getsurname();
        name = a.getname();
        login = a.getlogin();
        password = a.getpassword();
    }
    void addCar();
    void addAdmin() {};
    void coutCars();
    void cout_reservations();
    ~Admin() {
        ofstream fout;
        fout.open("C:\\Users\\USER\\Desktop\\baby_work\\car_rental_system\\info\\cars.txt", ios::trunc);
        for (int i = 0; i < cars.size(); i++) {
            cars[i].saveToFile(fout);
        }
        cars.clear();
        fout.close();
        fout.open("C:\\Users\\USER\\Desktop\\baby_work\\car_rental_system\\info\\reservations.txt",ios::trunc);
        for (int i = 0; i < all_reservations.size(); i++) {
            all_reservations[i].saveToFile(fout);
        }
        all_reservations.clear();
        fout.close();
    }
};
template<class T>
class Notification {
    T message;
    string login;
public:
    template <class T>
    void sendmessage() {
        ofstream fout;
        fout.open("C:\\Users\\USER\\Desktop\\baby_work\\car_rental_system\\info\\notifications.txt");
        fout << login << endl << message << endl;
        fout.close();
    }
    
    template<class T>
    void setmessage(T message) {
        this->message = message;
    }
    void setlogin(string login) {
        this->login = login;
    }
    template<class T>
    T getmessage() {
        return message;
    }
    string getlogin() {
        return login;
    }
    template <class T>
    Notification readmessage() {
        ifstream fin;
        fin.open("C:\\Users\\USER\\Desktop\\baby_work\\car_rental_system\\info\\notifications.txt");
        fin >> login >> message;
        Notification new_notif;
        newnotif.setmessage(message);
        newnotif.setlogin(login);
        return newnotif;
    }
};
namespace vsl {
    extern void coutUserFunct();
    extern int UserMenu(MOUSE_EVENT_RECORD);
    extern int menu(int(*op)(MOUSE_EVENT_RECORD));
    extern void coutMenu();
    extern int MainMenu(MOUSE_EVENT_RECORD ir);
    extern void clear();
    extern void gotoxy(int x, int y);
    extern void endProgram();
    extern void coutAdmFunct();
    extern int AdmMenu(MOUSE_EVENT_RECORD ir);
    void setzabor(int x, int y, int length, int width);
    extern void All_cars(vector<Car> vehicles);
    extern int EscapeKey(KEY_EVENT_RECORD);
    extern int escmenu(int(*op)(MOUSE_EVENT_RECORD));
    extern void All_cars_user(vector<Car> vehicles);
    extern int AdmCars(MOUSE_EVENT_RECORD ir);
    extern int UserCars(MOUSE_EVENT_RECORD ir);
    extern void All_reservations(vector<shared_ptr<Reservation>> reservations);
    extern int UserReservations(MOUSE_EVENT_RECORD ir);
    extern void All_reservations(vector<Reservation> reservations);
    extern int AdminReservations(MOUSE_EVENT_RECORD ir);
}
using namespace vsl;
extern string logininput(string a);
extern string stars(string a);
