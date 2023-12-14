#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.h"
using namespace std;
namespace Records {
    Database::Database()
    {
        mNextSlot = 0;
        mNextRenovationID = kFirstRenovationID;
    }
    Database::~Database()
    {
    }
    Renovation& Database::addRenovation(int inMalfunctionCode, int inModelCode, std::string inDescription,
        std::string inSymptoms, std::string inRepairMethods,
        int inPartCode1, int inPartCode2, int inPartCode3, int inLaborCost)
    {
        if (mNextSlot >= kMaxRenovations) {
            cerr << "There is no more room to add the new renovation!" << endl;
            throw exception();
        }
        Renovation& theRenovation = mRenovations[mNextSlot++];
        theRenovation.setRenovationID(mNextSlot);
        theRenovation.setMalfunctionCode(inMalfunctionCode);
        theRenovation.setModelCode(inModelCode);
        theRenovation.setDescription(inDescription);
        theRenovation.setSymptoms(inSymptoms);
        theRenovation.setRepairMethods(inRepairMethods);
        theRenovation.setPartCode1(inPartCode1);
        theRenovation.setPartCode2(inPartCode2);
        theRenovation.setPartCode3(inPartCode3);
        theRenovation.setLaborCost(inLaborCost);
        theRenovation.setRepaired(false);

        return theRenovation;
    }
    Renovation& Database::getRenovation(int inRenovationID)
    {
        for (int i = 0; i < mNextSlot; i++) {
            if (mRenovations[i].getRenovationID() == inRenovationID) {
                return mRenovations[i];
            }
        }
        cerr << "No renovation with ID " << inRenovationID << endl;
        throw exception();
    }
    Renovation& Database::getRenovation(string inDescription)
    {
        for (int i = 0; i < mNextSlot; i++) {
            if (mRenovations[i].getDescription() == inDescription) {
                return mRenovations[i];
            }
        }
        cerr << "No match with description " << inDescription << endl;
        throw exception();
    }
    void Database::displayAll()
    {
        for (int i = 0; i < mNextSlot; i++) {
            mRenovations[i].display();
        }
    }
    void Database::displayRepaired()
    {
        for (int i = 0; i < mNextSlot; i++) {
            if (mRenovations[i].getRepaired()) {
                mRenovations[i].display();
            }
        }
    }
    void Database::displayUnrepaired()
    {
        for (int i = 0; i < mNextSlot; i++) {
            if (!mRenovations[i].getRepaired()) {
                mRenovations[i].display();
            }
        }
    }
}