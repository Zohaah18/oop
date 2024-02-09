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
    WaterBottle(string company, string color, int capacity_liters, int capacity_milliliters) {
        this->company = company;
        this->color = color;
        this->capacity_liters = capacity_liters;
        this->capacity_milliliters = capacity_milliliters;
    }

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

    int getCapacityMilliliters(){
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
        int consumedliters = milliliters / 1000;
        int consumedremainder_ml = milliliters % 1000;
        
        capacity_liters -= consumed_liters;
        capacity_milliliters -= consumed_remainder_ml;

        if (capacity_milliliters < 0) {
            capacity_liters -= 1;
            capacity_milliliters += 1000;
        }

        cout << "Water consumed. Updated capacity: " << capacity_liters << " liters, "
                  << capacity_milliliters << " milliliters." << endl;
    }
};

int main() {
    WaterBottle bottle;

   
    cout << "Company: " << bottle.getCompany() <<endl;
    cout << "Color: " << bottle.getColor() << endl;
    cout << "Capacity: " << bottle.getCapacityLiters() << " liters, "
              << bottle.getCapacityMilliliters() << " milliliters" << endl;

    int consumed_milliliters;
    cout << "Enter the amount of water consumed (in milliliters): ";
    cin >> consumed_milliliters;

    bottle.consumeWater(consumed_milliliters);

    return 0;
}

  
