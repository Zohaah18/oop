#include<iostream>
using namespace std;
class Restaurant{
    string restaurant_name;
    string location;
    string menu_list[10];
    float price_list[10];
    string valid_coupon_codes_list[100];
    static int total_coupon;
    public:
    void display_menu()
    {
        cout<<"Menu List"<<endl;
        for(int i=0; i<10; i++){
            cout<<menu_list[i]<<": "<<price_list[i]<<endl;
        }
        }
        double generate_bill(int *items_ordered, size_t num_items) {
        double total_cost = 0;
        for (size_t i = 0; i < num_items; ++i) {
            total_cost += price_list[items_ordered[i]];
        }
        return total_cost;
    }
      static void redeem_coupon() {
        total_coupon--;
    }

    ~Restaurant() {
        delete[] menu_list;
        delete[] valid_coupon_codes_list;
    }
};

int Restaurant::total_coupon = 0;
class BOGOCoupon {
private:
    string coupon_code;
    time_t valid_from;
    time_t valid_until;
    string restaurant_code;

public:
    BOGOCoupon(){}
    BOGOCoupon(string code, time_t from, time_t until, string rest_code) : 
        coupon_code(code), valid_from(from), valid_until(until), restaurant_code(rest_code) {}
     
    bool is_valid(string selected_restaurant) {
        time_t current_time = time(nullptr);
        return (current_time >= valid_from && current_time <= valid_until && restaurant_code == selected_restaurant);
    }
    string get_coupon_code()
    {
        return coupon_code;
    }
};
class User {
private:
    string name;
    int age;
    string mobile_number;
    BOGOCoupon* coupons_list;
    string* redeemed_coupons_list;
    size_t num_coupons;
    size_t num_redeemed_coupons;

public:
    User(string n, int a, string mobile) : name(n), age(a), mobile_number(mobile), num_coupons(0), num_redeemed_coupons(0) {
        coupons_list = new BOGOCoupon[100];
        redeemed_coupons_list = new string[100];
    }

    void accumulate_coupon(BOGOCoupon coupon) {
        coupons_list[num_coupons++] = coupon;
    }

    bool has_valid_coupon(string selected_restaurant, string item) {
        for (size_t i = 0; i < num_coupons; ++i) {
            if (coupons_list[i].is_valid(selected_restaurant) && coupons_list[i].get_coupon_code().find(item) != string::npos) {
                return true;
            }
        }
        return false;
    }

    bool redeem_coupon(string coupon_code) {
        for (size_t i = 0; i < num_coupons; ++i) {
            if (coupons_list[i].get_coupon_code() == coupon_code && find(redeemed_coupons_list, redeemed_coupons_list + num_redeemed_coupons, coupon_code) == redeemed_coupons_list + num_redeemed_coupons) {
                redeemed_coupons_list[num_redeemed_coupons++] = coupon_code;
                for (size_t j = i; j < num_coupons - 1; ++j) {
                    coupons_list[j] = coupons_list[j + 1];
                }
                num_coupons--;
                return true;
            }
        }
        return false;
    }

    ~User() {
        delete[] coupons_list;
        delete[] redeemed_coupons_list;
    }
};
int main() {
    Restaurant food_haven;
    food_haven.restaurant_name = "Food Haven";
    food_haven.location = "City Center";
    food_haven.menu_list[0] = "Sushi";
    food_haven.price_list[0] = 15.99;
    food_haven.menu_list[1] = "Pad Thai";
    food_haven.price_list[1] = 12.99;
    food_haven.menu_list[2] = "Mango Tango";
    food_haven.price_list[2] = 8.99;

    Restaurant pixel_bites;
    pixel_bites.restaurant_name = "Pixel Bites";
    pixel_bites.location = "Cyber Street";
    pixel_bites.menu_list[0] = "Binary Burger";
    pixel_bites.price_list[0] = 14.99;
    pixel_bites.menu_list[1] = "Quantum Quinoa";
    pixel_bites.price_list[1] = 10.99;
    pixel_bites.menu_list[2] = "Data Donuts";
    pixel_bites.price_list[2] = 6.99;

    User user("John", 30, "1234567890");

    BOGOCoupon coupon1("FH-BOGO-12345", time(nullptr), time(nullptr) + 3600 * 24 * 30, "FH");
    BOGOCoupon coupon2("PB-BOGO-67890", time(nullptr), time(nullptr) + 3600 * 24 * 30, "PB");
    user.accumulate_coupon(coupon1);
    user.accumulate_coupon(coupon2);

    cout << "=== Food Haven Menu ===" << endl;
    food_haven.display_menu();
    cout << endl << "=== Pixel Bites Menu ===" << endl;
    pixel_bites.display_menu();

    string selected_restaurant = "FH";
    string selected_item = "Sushi";
    if (user.has_valid_coupon(selected_restaurant, selected_item)) {
        if (user.redeem_coupon("FH-BOGO-12345")) {
            Restaurant::redeem_coupon();
            cout << "Coupon redeemed successfully!" << endl;
            cout << "Enjoy your BOGO offer at Food Haven." << endl;
        } else {
            cout << "Coupon already redeemed or invalid." << endl;
        }
    } else {
        cout << "No valid coupon available for selected item or restaurant." << endl;
    }

    return 0;
}