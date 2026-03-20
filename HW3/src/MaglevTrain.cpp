#include "MaglevTrain.hpp"
#include <stdexcept>
using namespace std;

MaglevTrain::MaglevTrain(int powerLimit, int seatLimit, TrainType type,
                         int trainNumber, int speedLimit): Train(type, trainNumber, speedLimit) {
    this -> powerLimit = powerLimit;
    this -> seatLimit = seatLimit;
    this -> power = 0;
    this -> seat = 0;
}

int MaglevTrain::GetPowerLimit() {
    return powerLimit;
}
int MaglevTrain::GetSeatLimit() {
    return seatLimit;
}
void MaglevTrain::SetPowerLimit(int powerLimit) {
    if (powerLimit <= 0 || powerLimit > 100) throw std::invalid_argument("");
    this -> powerLimit = powerLimit;
}
int MaglevTrain::GetPower() {
    return power;
}
int MaglevTrain::GetSeat() {
    return seat;
}
void MaglevTrain::SetSeat() {
    if (seat + 1 > seatLimit) throw std::invalid_argument("");
    seat += 1;
}
void MaglevTrain::Charge(int hour) {
    for (int i = 0; i < hour; i++) {
        if (power + 14 > powerLimit) {
            power = powerLimit;
            return;
        }
        power += 14;
    }
}
void MaglevTrain::PowerUp() {
    if (power <= 0) throw std::invalid_argument("");
    power -= 1;
    open = true;
}
void MaglevTrain::SpeedUp() {
    if (power <= 0) throw std::invalid_argument("");
    if (power < 3) return;
    power -= 3;
    speed = 30 + speed / 15 + speed;
    speed = (speed > GetSpeedLimit())?GetSpeedLimit() : speed;
}
void MaglevTrain::SpeedDown() {
    if (power <= 0) throw std::invalid_argument("");
    speed -= 30;
    if (speed < 0) speed = 0;
}
