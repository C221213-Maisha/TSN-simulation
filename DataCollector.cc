#include <fstream>
#include <omnetpp.h>



using namespace omnetpp;

import DataCollector;

// Add to submodules:
dataCollector: DataCollector {
    @display("p=300,300");
}

class DataCollector : public cSimpleModule {
protected:
    std::ofstream outFile;

    virtual void initialize() override {
        outFile.open("simulation_data.csv");
        outFile << "timestamp,frame_size,delay,queue_length\n";
    }

    virtual void handleMessage(cMessage *msg) override {
        // Record data when packets pass through
        double now = simTime().dbl();
        int frameSize = msg->getByteLength();

        // Record to CSV
        outFile << now << "," << frameSize << ","
                << "0" << "," << "0" << "\n"; // Placeholders
    }

    virtual void finish() override {
        outFile.close();
    }
};

Define_Module(DataCollector);
