class ParkingSystem {
public:
    int bigCarSpace,smallCarSpace,mediumCarSpace,currBig=0,currMedium=0,currSmall=0;
    ParkingSystem(int big, int medium, int small) {
        bigCarSpace=big;
        mediumCarSpace=medium;
        smallCarSpace=small;
    }
    
    bool addCar(int carType) {
        if(carType==3) return ++currSmall<=smallCarSpace;
        else if(carType==2) return ++currMedium<=mediumCarSpace;
        else return ++currBig<=bigCarSpace;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */