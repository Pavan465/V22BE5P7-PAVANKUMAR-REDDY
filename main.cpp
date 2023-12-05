/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

class Beacon {
public:
    virtual void sendBeacon() const = 0;  // Pure virtual function for sending beacon packets
    virtual void extractData() const = 0; // Pure virtual function for extracting data
    virtual bool isMoving() const = 0;    // Pure virtual function for checking movement status
    virtual ~Beacon() {}
};

class SampleBeacon : public Beacon {
private:
    std::string macAddress;
    double accelerometerData;
    int batteryLevel;
    bool movingStatus;

public:
    SampleBeacon(const std::string& mac, double accData, int battery)
        : macAddress(mac), accelerometerData(accData), batteryLevel(battery), movingStatus(false) {}

    void sendBeacon() const override {
        std::cout << "Sending beacon packet..." << std::endl;
    }

    void extractData() const override {
        std::cout << "MAC Address: " << macAddress << std::endl;
        std::cout << "Accelerometer Data: " << accelerometerData << std::endl;
        std::cout << "Battery Level: " << batteryLevel << "%" << std::endl;
    }

    bool isMoving() const override {
        // Implement your logic to determine movement status based on accelerometer data
        // For demonstration, let's consider any non-zero accelerometer data indicates movement.
        movingStatus = (accelerometerData != 0.0);
        return movingStatus;
    }
};

int main() {
    SampleBeacon beacon("00:11:22:33:44:55", 2.5, 75);

    beacon.sendBeacon();
    beacon.extractData();

    if (beacon.isMoving()) {
        std::cout << "Beacon is currently moving." << std::endl;
    } else {
        std::cout << "Beacon is not moving." << std::endl;
    }

    return 0;
}

