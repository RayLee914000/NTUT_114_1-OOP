#include "Train.hpp"

using namespace std;

Train::Train(TrainType type,int trainNumber,int speedLimit) {
    this -> type = type;
    this -> trainNumber = trainNumber;
    this -> speedLimit = speedLimit;
    this -> speed = 0;
    this -> open = false;
}

TrainType Train::GetType() {
    return type;
}
int Train::GetTrainNumber() {
    return trainNumber;
}
int Train::GetSpeed() {
    return speed;
}
int Train::GetSpeedLimit() {
    return speedLimit;
}
bool Train::IsOpen() {
    return open;
}
void Train::PowerUp() {
    open = true;
}
void Train::PowerDown() {
    open = false;
}
