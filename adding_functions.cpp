#include "functions.h"

#include <fstream>

void add_car(car& car_) {
    std::ofstream file("cars.txt", std::ios::app);
    if (!file) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    file << "type: " << car_.type << std::endl;
    file << "model: " << car_.model << std::endl;
    file << "power: " << car_.power << std::endl;
    file << "engine_type: " << car_.engine_type << std::endl;
    file << "max_speed: " << car_.max_speed << std::endl;
    file << "\n";

    file.close();
}

void add_car(passenger_car& car_) {
    std::ofstream file("cars.txt", std::ios::app);
    if (!file) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    file << "type: " << car_.type << std::endl;
    file << "model: " << car_.model << std::endl;
    file << "power: " << car_.power << std::endl;
    file << "engine_type: " << car_.engine_type << std::endl;
    file << "max_speed: " << car_.max_speed << std::endl;
    file << "doors_number: " << car_.doors_number << std::endl;
    file << "\n";

    file.close();
}

void add_car(truck& car_) {
    std::ofstream file("cars.txt", std::ios::app);
    if (!file) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    file << "type: " << car_.type << std::endl;
    file << "model: " << car_.model << std::endl;
    file << "power: " << car_.power << std::endl;
    file << "engine_type: " << car_.engine_type << std::endl;
    file << "max_speed: " << car_.max_speed << std::endl;
    file << "load_capacity: " << car_.load_capacity << std::endl;
    file << "axles_number: " << car_.axles_number << std::endl;
    file << "\n";

    file.close();
}

void add_car(bus& car_) {
    std::ofstream file("cars.txt", std::ios::app);
    if (!file) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    file << "type: " << car_.type << std::endl;
    file << "model: " << car_.model << std::endl;
    file << "power: " << car_.power << std::endl;
    file << "engine_type: " << car_.engine_type << std::endl;
    file << "max_speed: " << car_.max_speed << std::endl;
    file << "passengerSeats_number: " << car_.passengerSeats_number << std::endl;
    file << "\n";

    file.close();
}

