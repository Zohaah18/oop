#include <iostream>
using namespace std;

class Table {
private:
    int total_seats;
    int occupiedSeats;
    int freeSeats;
    bool clean;

public:
    Table() : total_seats(4), occupiedSeats(0), freeSeats(4), clean(true) {}

    Table(int capacity) {
        if (capacity == 8) {
            total_seats = 8;
        } else {
            total_seats = 4;
        }
        occupiedSeats = 0;
        freeSeats = total_seats;
        clean = true;
    }

    bool isClean() const {
        return clean;
    }

    int getCapacity() const {
        return total_seats;
    }

    void useTable(int groupSize) {
        if (!clean) {
            cout << "Table is not clean. Cannot use." << endl;
            return;
        }
        int seatsNeeded = (groupSize <= 4) ? 4 : 8;
        if (seatsNeeded > freeSeats) {
            cout << "Insufficient seats available for the group." << endl;
        } else {
            occupiedSeats = seatsNeeded;
            freeSeats -= seatsNeeded;
            cout << "Table is now occupied by a group of " << groupSize << " with capacity " << total_seats << "." << endl;
        }
    }

    void haveLunch() {
        if (occupiedSeats == 0) {
            cout << "No one is seated at the table." << endl;
            return;
        }
        clean = false;
        cout << "Lunch has been served. Table is no longer clean." << endl;
    }

    void leaveTable() {
        if (occupiedSeats == 0) {
            cout << "No one is seated at the table." << endl;
            return;
        }
        occupiedSeats = 0;
        freeSeats = total_seats;
        cout << "Table is now vacant." << endl;
    }

    void cleanTable() {
        if (occupiedSeats != 0) {
            cout << "Table cannot be cleaned as it is occupied." << endl;
            return;
        }
        clean = true;
        cout << "Table has been cleaned." << endl;
    }
};

void OccupyTable(Table tables[], int groupSize) {
    for (int i = 0; i < 5; ++i) {
        if (tables[i].isClean()) {
            tables[i].useTable(groupSize);
            return;
        }
    }
    cout << "All tables are occupied. Please try again later." << endl;
}

void EmptyTable(Table tables[], int index) {
    if (index < 0 || index >= 5) {
        cout << "Invalid table index." << endl;
        return;
    }
    tables[index].leaveTable();
}

int main() {
    Table tables[5] = {Table(8), Table(8), Table(4), Table(4), Table(4)};

    OccupyTable(tables, 4); // Assume this is table 1
    OccupyTable(tables, 6); // Assume this is table 2

    tables[0].useTable(4); // Using table 1
    tables[0].haveLunch();
    tables[0].leaveTable();
    tables[0].cleanTable();

    EmptyTable(tables, 1); // Empty table 2

    return 0;
}
