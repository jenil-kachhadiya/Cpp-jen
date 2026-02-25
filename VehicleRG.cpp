#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string manufacturer;
    string model;
    int year;

private:
    string vehicleType;

public:
    static int totalVehicles;

    Vehicle(string vType = "Unknown", string manu = "Unknown", string mdl = "Unknown", int yr = 0) {
        vehicleType = vType;
        manufacturer = manu;
        model = mdl;
        year = yr;
        totalVehicles++;
    }

    virtual ~Vehicle() {
        totalVehicles--;
    }

    void setVehicleType(string vType) { vehicleType = vType; }
    string getVehicleType() const { return vehicleType; }

    virtual void display() const {
        cout << "Type         : " << vehicleType << endl;
        cout << "Manufacturer : " << manufacturer << endl;
        cout << "Model        : " << model << endl;
        cout << "Year         : " << year << endl;
    }
};

int Vehicle::totalVehicles = 0;

class Car : public Vehicle {
protected:
    string fuelType;

public:
    Car(string manu = "Unknown", string mdl = "Unknown", int yr = 0, string fuel = "Petrol")
        : Vehicle("Car", manu, mdl, yr), fuelType(fuel) {}

    void display() const override {
        Vehicle::display();
        cout << "Fuel Type    : " << fuelType << endl;
    }
};

class ElectricCar : public Car {
protected:
    int batteryCapacity;

public:
    ElectricCar(string manu = "Unknown", string mdl = "Unknown", int yr = 0, int battery = 50)
        : Car(manu, mdl, yr, "Electric"), batteryCapacity(battery) {}

    void display() const override {
        Car::display();
        cout << "Battery      : " << batteryCapacity << " kWh" << endl;
    }
};

class SportsCar : public ElectricCar {
    int topSpeed;

public:
    SportsCar(string manu = "Unknown", string mdl = "Unknown", int yr = 0,
              int battery = 100, int speed = 300)
        : ElectricCar(manu, mdl, yr, battery), topSpeed(speed) {
        setVehicleType("Sports Car");
    }

    void display() const override {
        ElectricCar::display();
        cout << "Top Speed    : " << topSpeed << " km/h" << endl;
    }
};

class Aircraft {
protected:
    int flightRange;

public:
    Aircraft(int range = 1000) : flightRange(range) {}

    virtual void displayAircraft() const {
        cout << "Flight Range : " << flightRange << " km" << endl;
    }
};

class FlyingCar : public Car, public Aircraft {
public:
    FlyingCar(string manu = "Unknown", string mdl = "Unknown", int yr = 0,
              string fuel = "Hybrid", int range = 500)
        : Car(manu, mdl, yr, fuel), Aircraft(range) {
        setVehicleType("Flying Car");
    }

    void display() const override {
        Car::display();
        displayAircraft();
    }
};

class Sedan : public Car {
public:
    Sedan(string manu = "Unknown", string mdl = "Unknown", int yr = 0, string fuel = "Petrol")
        : Car(manu, mdl, yr, fuel) {
        setVehicleType("Sedan");
    }
};

class SUV : public Car {
public:
    SUV(string manu = "Unknown", string mdl = "Unknown", int yr = 0, string fuel = "Diesel")
        : Car(manu, mdl, yr, fuel) {
        setVehicleType("SUV");
    }
};

class VehicleRegistry {
private:
    Vehicle* vehicles[100];
    int count;

public:
    VehicleRegistry() : count(0) {}

    ~VehicleRegistry() {
        for (int i = 0; i < count; i++) {
            delete vehicles[i];   // ✅ prevent memory leak
        }
    }

    void addVehicle(Vehicle* v) {
        if (count < 100) {
            vehicles[count++] = v;
            cout << "Vehicle Added Successfully.\n";
        } else {
            cout << "Registry Full!\n";
        }
    }

    void displayAll() const {
        if (count == 0) {
            cout << "No vehicles registered.\n";
            return;
        }

        for (int i = 0; i < count; i++) {
            cout << "\n=============================\n";
            vehicles[i]->display();
        }

        cout << "\n=============================\n";
        cout << "Total Vehicles: " << Vehicle::totalVehicles << endl;
    }
};

int main() {
    VehicleRegistry registry;
    int choice;

    do {
        cout << "\n---- Vehicle Registry Menu ----\n";
        cout << "1. Add Car\n";
        cout << "2. Add Electric Car\n";
        cout << "3. Add Sports Car\n";
        cout << "4. Add Flying Car\n";
        cout << "5. Add Sedan\n";
        cout << "6. Add SUV\n";
        cout << "7. View All Vehicles\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            registry.addVehicle(new Car("Toyota", "Corolla", 2020, "Petrol"));
            break;

        case 2:
            registry.addVehicle(new ElectricCar("Tesla", "Model 3", 2021, 75));
            break;

        case 3:
            registry.addVehicle(new SportsCar("Porsche", "Taycan", 2022, 93, 320));
            break;

        case 4:
            registry.addVehicle(new FlyingCar("AeroMobil", "AM4", 2023, "Hybrid", 700));
            break;

        case 5:
            registry.addVehicle(new Sedan("Honda", "City", 2019, "Petrol"));
            break;

        case 6:
            registry.addVehicle(new SUV("Ford", "Endeavour", 2021, "Diesel"));
            break;

        case 7:
            registry.displayAll();
            break;

        case 0:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}

/*

---- Vehicle Registry Menu ----
1. Add Car
2. Add Electric Car
3. Add Sports Car
4. Add Flying Car
5. Add Sedan
6. Add SUV
7. View All Vehicles
0. Exit
Enter choice: 1
Vehicle Added Successfully.

---- Vehicle Registry Menu ----
1. Add Car
2. Add Electric Car
3. Add Sports Car
4. Add Flying Car
5. Add Sedan
6. Add SUV
7. View All Vehicles
0. Exit
Enter choice: 2
Vehicle Added Successfully.

---- Vehicle Registry Menu ----
1. Add Car
2. Add Electric Car
3. Add Sports Car
4. Add Flying Car
5. Add Sedan
6. Add SUV
7. View All Vehicles
0. Exit
Enter choice: 3
Vehicle Added Successfully.

---- Vehicle Registry Menu ----
1. Add Car
2. Add Electric Car
3. Add Sports Car
4. Add Flying Car
5. Add Sedan
6. Add SUV
7. View All Vehicles
0. Exit
Enter choice: 4
Vehicle Added Successfully.

---- Vehicle Registry Menu ----
1. Add Car
2. Add Electric Car
3. Add Sports Car
4. Add Flying Car
5. Add Sedan
6. Add SUV
7. View All Vehicles
0. Exit
Enter choice: 5
Vehicle Added Successfully.

---- Vehicle Registry Menu ----
1. Add Car
2. Add Electric Car
3. Add Sports Car
4. Add Flying Car
5. Add Sedan
6. Add SUV
7. View All Vehicles
0. Exit
Enter choice: 6
Vehicle Added Successfully.

---- Vehicle Registry Menu ----
1. Add Car
2. Add Electric Car
3. Add Sports Car
4. Add Flying Car
5. Add Sedan
6. Add SUV
7. View All Vehicles
0. Exit
Enter choice: 7

=============================
Type         : Car
Manufacturer : Toyota
Model        : Corolla
Year         : 2020
Fuel Type    : Petrol

=============================
Type         : Car
Manufacturer : Tesla
Model        : Model 3
Year         : 2021
Fuel Type    : Electric
Battery      : 75 kWh

=============================
Type         : Sports Car
Manufacturer : Porsche
Model        : Taycan
Year         : 2022
Fuel Type    : Electric
Battery      : 93 kWh
Top Speed    : 320 km/h

=============================
Type         : Flying Car
Manufacturer : AeroMobil
Model        : AM4
Year         : 2023
Fuel Type    : Hybrid
Flight Range : 700 km

=============================
Type         : Sedan
Manufacturer : Honda
Model        : City
Year         : 2019
Fuel Type    : Petrol

=============================
Type         : SUV
Manufacturer : Ford
Model        : Endeavour
Year         : 2021
Fuel Type    : Diesel

=============================
Total Vehicles: 6

---- Vehicle Registry Menu ----
1. Add Car
2. Add Electric Car
3. Add Sports Car
4. Add Flying Car
5. Add Sedan
6. Add SUV
7. View All Vehicles
0. Exit
Enter choice: 0
Exiting Program...
*/