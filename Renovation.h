#include <iostream>
#include <string>

namespace Records {

    class Renovation {
    public:
    
    Renovation();
    Renovation(
    	int malfunction, 
    	int model, 
    	const std::string& desc, 
    	const std::string& sym,
        const std::string& repair, 
        int part1, 
        int part2, 
        int part3,
        int laborcost);
        
        void changeLaborCost(int newCost);
        void completeRepair();
        void display(); 
        
        void setMalfunctionCode(int inMalfunctionCode);
        int getMalfunctionCode();
        void setModelCode(int inModelCode);
        int getModelCode();
        void setDescription(std::string inDescription);
        std::string getDescription();
        void setSymptoms(std::string inSymptoms);
        std::string getSymptoms();
        void setRepairMethods(std::string inRepairMethods);
        std::string getRepairMethods();
        void setPartCode1(int inPartCode1);
        int getPartCode1();
        void setPartCode2(int inPartCode2);
        int getPartCode2();
        void setPartCode3(int inPartCode3);
        int getPartCode3();
        void setLaborCost(int inLaborCost);
        int getLaborCost();
        void setRepaired(bool isRepaired);
        bool getRepaired();
        void setRenovationID(int inRenovationID);
        int getRenovationID();

    private:
        
        int malfunctionCode;
        int modelCode;
        std::string description;
        std::string symptoms;
        std::string repairMethods;
        int partCode1;
        int partCode2;
        int partCode3;
        int laborCost;
        bool repaired;
        int renovationID;
    };
}