#include "ElectricalTrain.hpp"
#include <stdexcept>

using namespace std;

ElectricalTrain::ElectricalTrain(int powerLimit, int seatLimit, TrainType type,
                             int trainNumber, int speedLimit): Train(type, trainNumber, speedLimit) {
    this->powerLimit = powerLimit;
    this->seatLimit = seatLimit;
    this->power = 0;
    this->seat = 0;
}

int ElectricalTrain::GetPowerLimit() {
    return powerLimit;
}
int ElectricalTrain::GetSeatLimit() {
    return seatLimit;
}
void ElectricalTrain::SetPowerLimit(int powerLimit) {
    if (powerLimit <= 0 || powerLimit > 100) throw std::invalid_argument("");
    this->powerLimit = powerLimit;
}
int ElectricalTrain::GetPower() {
    return power;
}
int ElectricalTrain::GetSeat() {
    return seat;
}
void ElectricalTrain::SetSeat() {
    if (seat + 1 > seatLimit) throw std::invalid_argument("");
    seat += 1;
}
void ElectricalTrain::Charge(int hour) {
    for (int i = 0; i < hour; i++) {
        if (power + 18 > powerLimit) {
            power = powerLimit;
            return;
        }
        power += 18;
    }
}
void ElectricalTrain::PowerUp() {
    if (power <= 0) throw std::invalid_argument("");
    open = true;
    power -= 1;
}
void ElectricalTrain::SpeedUp() {
    if (power <= 0) throw std::invalid_argument("");
    if (power < 3) return;
    power -= 3;
    speed = 15 + speed / 20 + speed;
    speed = (speed > GetSpeedLimit())? GetSpeedLimit() : speed;
}
void ElectricalTrain::SpeedDown() {
    if (power <= 0) throw std::invalid_argument("");
    speed -= 15;
    if (speed < 0) {
        speed = 0;
    }
}
