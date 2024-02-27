#include <iostream>
using namespace std;

class Pet {
private:
    string healthstatus;
    int hungerlevel;
    int happinesslevel;
    string specialskills;

public:
    Pet(){}
    Pet(string healthStatus, int hungerLevel, int happinessLevel, string specialSkills)
        : healthstatus(healthStatus), hungerlevel(hungerLevel), happinesslevel(happinessLevel), specialskills(specialSkills) {}

    void displaypetdetails() {
        cout << "Details about Pet: " << endl;
        cout << "Health status: " << healthstatus << endl;
        cout << "Happiness Level: " << happinesslevel << endl;
        cout << "Special skills: " << specialskills << endl;
    }

    void updateHappiness(int userInteraction) {
        if (userInteraction < 0) {
            if (hungerlevel > 0) {
                happinesslevel -= 1;
            }
        } else {
            happinesslevel += 1;
            if (happinesslevel > 10) {
                happinesslevel = 10;
            }
        }
    }

    void updateHealth() {
        if (hungerlevel >= 5) {
            healthstatus = "Sick";
        } else {
            healthstatus = "Healthy";
        }
    }

    void updateHunger(int feed) {
        hungerlevel -= feed;
        if (hungerlevel < 0) {
            hungerlevel = 0;
        }
    }
};

class Adopter {
private:
    string adoptername;
    string adoptermobilenum;
    Pet adoptedpetrecords[10];
    int adoptedpets;

public:
    Adopter(string name, string mobilenum) : adoptername(name), adoptermobilenum(mobilenum), adoptedpets(0) {}

    void adoptpet(const Pet &pet) {
        if (adoptedpets < 10) {
            adoptedpetrecords[adoptedpets++] = pet;
            cout << "Pet is adopted " << endl;
        } else {
            cout << "Maximum limit reached. You cannot adopt more pets" << endl;
        }
    }

    void returnpet(int num) {
        if (num >= 0 && num < adoptedpets) {
            cout << "Pet returned." << endl;
            for (int i = num; i < adoptedpets - 1; i++) {
                adoptedpetrecords[i] = adoptedpetrecords[i + 1];
            }
            adoptedpets--;
        } else {
            cout << "Invalid input. Pet returned failed." << endl;
        }
    }

    void displayadoptedpets() {
        cout << "Adopted Pets: " << endl;
        for (int i = 0; i < adoptedpets; i++) {
            cout << "Pet" << i + 1 << ":" << endl;
            adoptedpetrecords[i].displaypetdetails();
            cout << endl;
        }
    }
};

int main() {
    Pet pet1("Healthy", 3, 7, "Fetch, Run");
    Pet pet2("Healthy", 4, 8, "Purr, Jump");
    Pet pet3("Sick", 2, 6, "Fly, Sing");

    Adopter adopter1("Zoha", "122334567");
    Adopter adopter2("Arisha", "132354678990");

    adopter1.adoptpet(pet1);
    adopter1.adoptpet(pet2);
    adopter2.adoptpet(pet3);

    adopter1.displayadoptedpets();
    adopter2.displayadoptedpets();

    adopter1.returnpet(1);
    adopter1.displayadoptedpets();

    return 0;
}
