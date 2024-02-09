#include<iostream>
using namespace std;

class BoardMarker{
    private:
    string brand;
    string shade;
    bool refillable;
    bool ink_status;

   public:

   void setbrand(string brand){
      brand=currency;
   }
   void setshade(string shade){
    shade=color;
   }
   void set_refillable(bool refillable){
    refillable=choice;
   }
   void set_inkstatus(bool ink_status){
    ink_status=status;
   }
   // Getter methods
   string getbrand(){
      return brand;
   }
    string getshade(){
        return shade;
    }
    bool isrefillable(){
        return refillable;
    }
    bool ink_status(){
        return ink_status;
    }
   
  void write() const {
        if (isInkDepleted()) {
            cout << "Cannot write. Ink is depleted." << endl;
        } else {
         cout << "Writing..." << endl;
        }
    }
  void refill() {
        if (isRefillable()) {
            cout << "Refilling the board marker." << endl;
            ink_status = true;
        } else {
            std::cout << "Cannot refill" << endl;
        }
    }
};

int main() {
   
    BoardMarker marker;

    
    marker.setBrand("Sharpie");
    marker.setShade("red");
    marker.setInkStatus(false);


    cout << "Brand: " << marker.getBrand() << endl;
    cout << "Shade: " << marker.getShade() << endl;
    cout << "Refillable: " << boolalpha << marker.isRefillable() << endl;
     cout << "Ink status: "  << marker.isInkDepleted() <<endl;
    marker.refill();
    marker.write();  

    marker.setRefillable(false); /
    marker.refill();            

    return 0;
}

