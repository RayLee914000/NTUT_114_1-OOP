#include "CargoPaper.hpp"
using namespace std;


 CargoPaper::CargoPaper(std::string dest, std::string src, int range, int volume,
                       CargoType cargoType) : Ticket(dest, src, range, 0, TrainType::Cargo){
    this -> volume = volume;
    this -> cargoType = cargoType;
 }
 int  CargoPaper::GetVolume() {
     return volume;
 }
 CargoType  CargoPaper::GetCargoType() {
     return cargoType;
 }
 void CargoPaper::CalculateTicketPrice() {
     price = range * 4;
     if (cargoType == CargoType::Vehicle)price += volume * 75;
     else price += (volume / 100) * 75;
     if (cargoType == CargoType::Food || cargoType == CargoType::Drink) price *= 1.1;
     if (cargoType == CargoType::Electronics || cargoType == CargoType::Furniture) price *= 1.15;
     if (cargoType == CargoType::Vehicle) price *= 1.2;
 }