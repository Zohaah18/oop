#include <iostream>
#include <string>
using namespace std;
class WaterBottle {
private:
    string company;
    string color;
    int capacity_liters;
    int capacity_milliliters;

public:
   
    // Getter methods
    string getCompany() {
        return company;
    }

    string getColor() {
        return color;
    }

    int getCapacityLiters() {
        return capacity_liters;
    }

    int getCapacityMilliliters() {
        return capacity_milliliters;
    }

    // Setter methods
    void setCompany(string company) {
        this->company = company;
    }

    void setColor(string color) {
        this->color = color;
    }

    
    void consumeWater(int milliliters) {
        int consumed_liters = milliliters / 1000;
        int consumed_remainder = milliliters % 1000;
        
        capacity_liters = capacity_liters-consumed_liters;
        capacity_milliliters = capacity_milliliters- consumed_remainder;

        
        if (capacity_milliliters < 0) {
            capacity_liters -= 1;
            capacity_milliliters += 1000;
        }

        cout << "Water consumed.  " << capacity_liters << " liters, "
     << capacity_milliliters << " milliliters." << endl;
    }
};

int main() {
   
    WaterBottle bottle;

    
   cout << "Company: " << bottle.getCompany() << endl;
  cout << "Color: " << bottle.getColor() << endl;
cout << "Capacity: " << bottle.getCapacityLiters() << " liters, "
              << bottle.getCapacityMilliliters() << " milliliters" << endl;

    // Simulating water consumption
    int consumed_milliliters;
    cout << "Enter the amount of water consumed in milliliters: ";
   cin >> consumed_milliliters;

    bottle.consumeWater(consumed_milliliters);

    return 0;
}
