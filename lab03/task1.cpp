#include <iostream>
#include <string>
using namespace std;
class BoardMarker {
private:
    string brand;
    string shade;
    bool refillable;
    bool ink_status;

public:
    
    // Getter methods
       string getBrand() {
        return brand;
    }

      string getShade() {
        return shade;
    }

    bool isRefillable(){
        return refillable;
    }

    bool isInkDepleted() const {
        return ink_status;
    }

    // Setter methods
    void setBrand(string brand) {
        this->brand = brand;
    }

    void setShade(string shade) {
        this->shade = shade;
    }

    void setRefillable(bool refillable) {
        this->refillable = refillable;
    }

    void setInkStatus(bool ink_status) {
        this->ink_status = ink_status;
    }

    // Writing method
    void write() {
        if (isInkDepleted()) {
            cout << "Cannot write. " << endl;
        } 
        else {
            cout << "Writing..." << endl;
        }
    }

    // Refill method
    void refill() {
        if (isRefillable()) {
            cout << "Refilling the board marker." << endl;
            ink_status = true;
        } else {
        cout << "Cannot refill. Marker is not refillable." <<endl;
        }
    }
};

int main() {
    // Illustrating the class functionality
    BoardMarker marker;

    marker.setBrand("Sharpie");
    marker.setShade("red");
    marker.setInkStatus(false);

    
    cout << "Brand: " << marker.getBrand() << endl;
    cout << "Shade: " << marker.getShade() << endl;
    cout << "Refillable: " << boolalpha << marker.isRefillable() <<endl;
    cout << "Ink Depleted: " << boolalpha << marker.isInkDepleted() << endl;

    marker.write(); 
    marker.refill(); 

    marker.setRefillable(false); 
    marker.refill();             
    return 0;
}
