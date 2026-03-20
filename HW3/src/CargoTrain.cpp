#include "CargoTrain.hpp"
#include <stdexcept>

using namespace std;

CargoTrain::CargoTrain(int fuelLimit, int cargoLimit, TrainType type,
    int trainNumber, int speedLimit): Train(type, trainNumber, speedLimit) {
    this->fuelLimit = fuelLimit;
    this->cargoLimit = cargoLimit;
    this->fuel = 0;
    this->cargo = 0;
}
int CargoTrain::GetFuelLimit() {
    return fuelLimit;
}
int CargoTrain::GetCargoLimit() {
    return cargoLimit;
}
void CargoTrain::SetFuelLimit(int fuelLimit) {
    if (fuelLimit <= 0 || fuelLimit > 1000) throw std::invalid_argument("");
    this -> fuelLimit = fuelLimit;
}
int CargoTrain::GetFuel() {
    return fuel;
}
int CargoTrain::GetCargo() {
    return cargo;
}
void CargoTrain::AddCargo(int cargo) {
    if (this -> cargo + cargo > cargoLimit) throw std::invalid_argument("");
    this->cargo += cargo;
}
void CargoTrain::AddFuel(int fuel) {
    if (this -> fuel + fuel > fuelLimit) throw std::invalid_argument("");
    this->fuel += fuel;
}
void CargoTrain::PowerUp() {
    if (fuel <= 0) throw std::invalid_argument("");
    if (fuel < 5) return;
    open = true;
    fuel -= 5;
}
void CargoTrain::SpeedUp() {
    if (fuel <= 0) throw std::invalid_argument("");
    if (fuel < 10) return;
    fuel -= 10;
    double ratio = (double)cargo / cargoLimit;
    if (ratio < 0.3)
        speed = 15 + speed / 20 + speed;
    else if (ratio <= 0.7)
        speed = 15 + speed / 25 + speed;
    else
        speed = 15 + speed / 30 + speed;
    speed = (speed > GetSpeedLimit())? GetSpeedLimit() : speed;
}
void CargoTrain::SpeedDown() {
    if (fuel <= 0) throw std::invalid_argument("");
    speed -= 15;
    if (speed < 0) speed = 0;
}