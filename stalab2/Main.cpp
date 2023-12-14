#include <iostream>
#include <stdexcept>
#include <string>
#include <limits> 
#include "Database.h"

using namespace std;
using namespace Records;

int displayMenu();
void addRenovation(Database& inDB);
void displayAll(Database& inDB);
void displayRepaired(Database& inDB);
void displayNotRepaired(Database& inDB);
void markRenovationAsRepaired(Database& inDB);





int main(int argc, char** argv) {
    Database renovationDB;
    
    Renovation ren1(12, 13, "glass", "broken", "replace", 15, 154, 11, 300);
    ren1.display();

    Renovation* ren2 = new Renovation(22, 23, "button", "erased", "repaint", 25, 254, 21, 400);
    ren2->display();
    delete ren2;

    bool done = false;

    while (!done) {
        int selection = displayMenu();
        switch (selection) {
        case 1:
            addRenovation(renovationDB);
            break;
        case 2:
            displayAll(renovationDB);
            break;
        case 3:
            displayRepaired(renovationDB);
            break;
        case 4:
            displayNotRepaired(renovationDB);
            break;
        case 5:
            markRenovationAsRepaired(renovationDB);
            break;
        case 0:
            done = true;
            break;
        default:
            cerr << "Unknown command." << endl;
        }
    }
    return 0;
}

int displayMenu() {
    int selection;
    cout << endl;
    cout << "Renovation Database" << endl;
    cout << "-------------------" << endl;
    cout << "1) Add a new renovation" << endl;
    cout << "2) List all renovations" << endl;
    cout << "3) List all repaired renovations" << endl;
    cout << "4) List all not repaired renovations" << endl;
    cout << "5) Mark a renovation as repaired" << endl;
    cout << "0) Quit" << endl;
    cout << endl;

    cout << "---> ";
    cin >> selection;
    return selection;
}

void addRenovation(Database& inDB) {
    int malfunctionCode, modelCode, partCode1, partCode2, partCode3, laborCost;
    string description, symptoms, repairMethods;
    
    cout << "Malfunction code? ";
    cin >> malfunctionCode;
        while (std::cin.fail()) {
        	std::cerr << "Please enter a valid integer for the malfunction code." << std::endl;
        	std::cin.clear();
        	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        	std::cout << "Malfunction code? ";
        	std::cin >> malfunctionCode;
        }
    cout << "Model code? ";    
    cin >> modelCode;
        while (std::cin.fail()) {
        	std::cerr << "Please enter a valid integer for the malfunction code." << std::endl;
        	std::cin.clear();
        	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        	std::cout << "Malfunction code? ";
        	std::cin >> modelCode;
        }
    cout << "Description? ";
    cin >> description;
    cout << "Symptoms? ";
    cin >> symptoms;
    cout << "Repair methods? ";
    cin >> repairMethods;
    cout << "Part code 1? ";
    cin >> partCode1;
        while (std::cin.fail()) {
        	std::cerr << "Please enter a valid integer for the malfunction code." << std::endl;
        	std::cin.clear();
        	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        	std::cout << "Malfunction code? ";
        	std::cin >> partCode1;
        }
    cout << "Part code 2? ";
    cin >> partCode2;
        while (std::cin.fail()) {
        	std::cerr << "Please enter a valid integer for the malfunction code." << std::endl;
        	std::cin.clear();
        	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        	std::cout << "Malfunction code? ";
        	std::cin >> partCode2;
        }
    cout << "Part code 3? ";
    cin >> partCode3;
        while (std::cin.fail()) {
        	std::cerr << "Please enter a valid integer for the malfunction code." << std::endl;
        	std::cin.clear();
        	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        	std::cout << "Malfunction code? ";
        	std::cin >> partCode3;
        }
    cout << "Labor cost? ";
    cin >> laborCost;
        while (std::cin.fail()) {
        	std::cerr << "Please enter a valid integer for the malfunction code." << std::endl;
        	std::cin.clear();
        	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        	std::cout << "Malfunction code? ";
        	std::cin >> laborCost;
        }

    try {
        inDB.addRenovation(malfunctionCode, modelCode, description, symptoms, repairMethods,
            partCode1, partCode2, partCode3, laborCost);
    }
    catch (const std::exception& ex) {
        cerr << "Unable to add new renovation!" << endl;
        return;
    }
}

void displayAll(Database& inDB) {
    inDB.displayAll();
}

void displayRepaired(Database& inDB) {
    inDB.displayRepaired();
}

void displayNotRepaired(Database& inDB) {
    inDB.displayUnrepaired();
}

void markRenovationAsRepaired(Database& inDB) {
    int renovationID;
    cout << "Renovation ID? ";
    cin >> renovationID;

    try {
        Renovation& renovation = inDB.getRenovation(renovationID);
        renovation.setRepaired(true);
        cout << "Renovation " << renovationID << " has been marked as repaired." << endl;
    }
    catch (const std::exception& ex) {
        cerr << "Unable to mark renovation as repaired!" << endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return;
    }
}