#pragma once

#include <iostream>
#include "Renovation.h"
namespace Records {
    const int kMaxRenovations = 100;
    const int kFirstRenovationID = 10000;
    class Database
    {
    public:
        Database();
        ~Database();
        Renovation& addRenovation(int inMalfunctionCode, int inModelCode, std::string inDescription,
            std::string inSymptoms, std::string inRepairMethods,
            int inPartCode1, int inPartCode2, int inPartCode3, int inLaborCost);
        Renovation& getRenovation(int inRenovationID);
        Renovation& getRenovation(std::string inDescription);
        void displayAll();
        void displayRepaired();
        void displayUnrepaired();
    protected:
        Renovation mRenovations[kMaxRenovations];
        int mNextSlot;
        int mNextRenovationID;
    };
}