class ParkingSystem {
public:
    int bigCarSpace,smallCarSpace,mediumCarSpace;
    ParkingSystem(int big, int medium, int small) {
        bigCarSpace=big;
        mediumCarSpace=medium;
        smallCarSpace=small;
    }
    
    bool addCar(int carType) {
        if(carType==3) return --smallCarSpace>=0;
        else if(carType==2) return --mediumCarSpace>=0;
        else return --bigCarSpace>=0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */