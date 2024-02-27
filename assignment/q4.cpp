#include<iostream>
using namespace std;
class rollercoaster{
    string name;
    float height;
    float length;
    float speed;
    int capacity;
    int CurrentNumRiders;
    bool RideInProgess;
   public:
   rollercoaster():name("Roller coaster"),height(500),length(2000),speed(0),capacity(20),CurrentNumRiders(0),RideInProgess(false){}
   rollercoaster(string name,float height, float length, float speed,int capacity, int CurrentNumRiders):name(name),height(height),length(length),speed(speed),CurrentNumRiders(CurrentNumRiders),RideInProgess(false){
    if(capacity%2==0 || capacity%3==0)
    {
        this->capacity=capacity;
    }
    else this->capacity=capacity+1;
   }
   void set_name(string n){
    name=n;
   }
   void set_height(float h){
    height=h;
   }
   void set_length(float l){
    length=l;
   }
   void set_speed(float s){
    speed=s;
   }
   void set_capacity(int c){
    capacity=c;
     if(c%2==0 || c%3==0)
    {
        this->capacity=c;
    }
    else this->capacity=c+1;
   }
   void set_CurrentNumRiders(int cr){
    CurrentNumRiders=cr;
   }
   void set_RiderInProgess(bool rp){
    RideInProgess=rp;
   }
   string get_name(){
    return name;
   }
   float get_height(){
    return height;
   }
   float get_length(){
    return length;
   }
    float get_speed(){
    return speed;
   }
   int get_capacity(){
    return capacity;
   }
   int get_CurrentNumRiders(){
    return CurrentNumRiders;
   }
   bool get_RiderInProgess(){
    return RideInProgess;
   }
   int loadriders(int numRiders){
      if (!RideInProgess && CurrentNumRiders + numRiders <= capacity) {
            CurrentNumRiders += numRiders;
            return 0; 
        } else {
            return numRiders - (capacity - CurrentNumRiders);
        }
   }
   int ride(int CurrentNumRiders){
    if(RideInProgess==true){
        return -1;
    }
    else{
      if(capacity==CurrentNumRiders){
        return 0;
      }
      else{
        return capacity=capacity-CurrentNumRiders;
      }

    }
    }
    void stopRide(){
        if (RideInProgess) {
            RideInProgess = false;
        }
    }
        void unloadRiders() {
        if (!RideInProgess) {
            CurrentNumRiders = 0;
        }
    }
    void accelerate() {
        
        int lastDigit = 4;
        speed += lastDigit;
    }

    
    void applyBrakes() {
        int firstDigit = 2; 
        speed -= firstDigit;
        if (speed < 0)
            speed = 0; 
    }
};

int main() {
    rollercoaster coaster1; 
    rollercoaster coaster2("Thrilling Thunder", 600, 2500, 0, 25, 0); 

    cout << "Name of coaster 1: " << coaster1.get_name() << endl;
    cout << "Capacity of coaster 1: " << coaster1.get_capacity() << endl;
    cout << "Name of coaster 2: " << coaster2.get_name() << endl;
    cout << "Capacity of coaster 2: " << coaster2.get_capacity() << endl;

    return 0;
   }
