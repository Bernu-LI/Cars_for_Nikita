#include "description.h"
#include "adding_functions.h"

#include <fstream>
#include <any>
#include <sstream>

void get_cars(std::vector <car>& c, std::vector <passenger_car>& p_c, std::vector <truck>& t, std::vector <bus>& b) {
    std::ifstream file("cars.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    std::string line;
    car car_;
    passenger_car passenger_car_;
    truck truck_;
    bus bus_;

    while (std::getline(file, line)) {
        if (line.empty()) {
            if (!car_.type.empty()) {
                c.emplace_back(car_);
                car_ = {};
            } else if (!passenger_car_.type.empty()) {
                p_c.emplace_back(passenger_car_);
                passenger_car_ = {};
            } else if (!truck_.type.empty()) {
                t.emplace_back(truck_);
                truck_ = {};
            } else if (!bus_.type.empty()) {
                b.emplace_back(bus_);
                bus_ = {};
            }
            continue;
        }

        std::istringstream iss(line);
        std::string field, value;

        std::getline(iss, field, ':');
        std::getline(iss, value);
        field = field.substr(0, field.find_last_not_of(' ') + 1);
        value = value.substr(value.find_first_not_of(' '));

        if (field == "type") {
            if (value == "passenger car") {
                passenger_car_.type = value;
            } else if (value == "truck") {
                truck_.type = value;
            } else if (value == "bus") {
                bus_.type = value;
            } else {
                car_.type = value;
            }
        } else if (field == "model") {
            if (!car_.type.empty()) {
                car_.model = value;
            } else if (!passenger_car_.type.empty()) {
                passenger_car_.model = value;
            } else if (!truck_.type.empty()) {
                truck_.model = value;
            } else if (!bus_.type.empty()) {
                bus_.model = value;
            }
        } else if (field == "power") {
            if (!car_.type.empty()) {
                car_.power = std::stoi(value);
            } else if (!passenger_car_.type.empty()) {
                passenger_car_.power = std::stoi(value);
            } else if (!truck_.type.empty()) {
                truck_.power = std::stoi(value);
            } else if (!bus_.type.empty()) {
                bus_.power = std::stoi(value);
            }
        } else if (field == "engine_type") {
            if (!car_.type.empty()) {
                car_.engine_type = value;
            } else if (!passenger_car_.type.empty()) {
                passenger_car_.engine_type = value;
            } else if (!truck_.type.empty()) {
                truck_.engine_type = value;
            } else if (!bus_.type.empty()) {
                bus_.engine_type = value;
            }
        } else if (field == "max_speed") {
            if (!car_.type.empty()) {
                car_.max_speed = std::stoi(value);
            } else if (!passenger_car_.type.empty()) {
                passenger_car_.max_speed = std::stoi(value);
            } else if (!truck_.type.empty()) {
                truck_.max_speed = std::stoi(value);
            } else if (!bus_.type.empty()) {
                bus_.max_speed = std::stoi(value);
            }
        } else if (field == "doors_number") {
            passenger_car_.doors_number = std::stoi(value);
        } else if (field == "load_capacity") {
            truck_.load_capacity = std::stoi(value);
        } else if (field == "axles_number") {
            truck_.axles_number = std::stoi(value);
        } else if (field == "passengerSeats_number") {
            bus_.passengerSeats_number = std::stoi(value);
        }
    }

    if (!car_.type.empty()) {
        c.emplace_back(car_);
    } else if (!passenger_car_.type.empty()) {
        p_c.emplace_back(passenger_car_);
    } else if (!truck_.type.empty()) {
        t.emplace_back(truck_);
    } else if (!bus_.type.empty()) {
        b.emplace_back(bus_);
    }

    file.close();
}

void findFastSlowCar() {
    std::vector <car> c;
    std::vector <passenger_car> p_c;
    std::vector <truck> t;
    std::vector <bus> b;

    get_cars(c, p_c, t, b);

    std::string fastestModel; int max_speed = INT_MIN;
    std::string slowestModel; int min_speed = INT_MAX;

    for (auto& i : c) {
        if (i.max_speed > max_speed) {
            fastestModel = i.model;
            max_speed = i.max_speed;
        }
        if (i.max_speed < min_speed) {
            slowestModel = i.model;
            min_speed = i.max_speed;
        }
    }
    for (auto& i : p_c) {
        if (i.max_speed > max_speed) {
            fastestModel = i.model;
            max_speed = i.max_speed;
        }
        if (i.max_speed < min_speed) {
            slowestModel = i.model;
            min_speed = i.max_speed;
        }
    }
    for (auto& i : t) {
        if (i.max_speed > max_speed) {
            fastestModel = i.model;
            max_speed = i.max_speed;
        }
        if (i.max_speed < min_speed) {
            slowestModel = i.model;
            min_speed = i.max_speed;
        }
    }
    for (auto& i : b) {
        if (i.max_speed > max_speed) {
            fastestModel = i.model;
            max_speed = i.max_speed;
        }
        if (i.max_speed < min_speed) {
            slowestModel = i.model;
            min_speed = i.max_speed;
        }
    }

    std::cout << "The fasted car: " << fastestModel << " (" << max_speed << " km/h)" << std::endl;
    std::cout << "The slowest car: " << slowestModel << " (" << min_speed << " km/h)" << std::endl;
}

void findMatchingCars() {
    int speed;
    int power;
    std::string type;

    int doors_number = -1;
    int load_capacity = -1;
    int axles_number = -1;
    int passengerSeats_number = -1;

    std::cout << "Enter speed: "; std::cin >> speed;
    std::cout << "Enter power: "; std::cin >> power;
    std::cout << "Enter type: "; std::cin.ignore(); std::getline(std::cin, type);

    if (type == "passenger car") {
        std::cout << "Enter number of doors: "; std::cin >> doors_number;
    }
    if (type == "truck") {
        std::cout << "Enter load capacity: "; std::cin >> load_capacity;
        std::cout << "Enter number of axles: "; std::cin >> axles_number;
    }
    if (type == "bus") {
        std::cout << "Enter number of passenger seats: "; std::cin >> passengerSeats_number;
    }

    std::vector <car> c;
    std::vector <passenger_car> p_c;
    std::vector <truck> t;
    std::vector <bus> b;

    get_cars(c, p_c, t, b);

    std::cout << "\nHere are all the matching cars:\n";

    if (type == "passenger car") {
        for (auto& i : p_c) {
            if (i.max_speed == speed and i.power == power and i.doors_number == doors_number) {
                std::cout << i.model << std::endl;
            }
        }
    }
    else if (type == "truck") {
        for (auto& i : t) {
            if (i.max_speed == speed and i.power == power and i.load_capacity == load_capacity and i.axles_number == axles_number) {
                std::cout << i.model << std::endl;
            }
        }
    }
    else if (type == "bus") {
        for (auto& i : b) {
            if (i.max_speed == speed and i.power == power and i.passengerSeats_number == passengerSeats_number) {
                std::cout << i.model << std::endl;
            }
        }
    }
    else {
        for (auto& i : c) {
            if (i.max_speed == speed and i.power == power) {
                std::cout << i.model << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

void new_car() {
    std::string type;
    std::string model;
    int power;
    std::string engine_type;
    int max_speed;
    std::cout << "Adding a new car:" << std::endl;
    std::cout << "Enter type: "; std::cin.ignore(); std::getline(std::cin, type);
    std::cout << "Enter model: "; getline(std::cin, model);
    std::cout << "Enter power: "; std::cin >> power;
    std::cout << "Enter type of engine: "; std::cin >> engine_type;
    std::cout << "Enter max speed: "; std::cin >> max_speed;
    if (type == "passenger car") {
        int doors_number;
        std::cout << "Enter number of doors: "; std::cin >> doors_number;
        passenger_car car_(type, model, power, engine_type, max_speed, doors_number);
        add_car(car_);
    }
    else if (type == "truck") {
        int load_capacity;
        int axles_number;
        std::cout << "Enter load capacity: "; std::cin >> load_capacity;
        std::cout << "Enter number of axles: "; std::cin >> axles_number;
        truck car_(type, model, power, engine_type, max_speed, load_capacity, axles_number);
        add_car(car_);
    }
    else if (type == "bus") {
        int passengerSeats_number;
        std::cout << "Enter number of passenger seats: "; std::cin >> passengerSeats_number;
        bus car_(type, model, power, engine_type, max_speed, passengerSeats_number);
        add_car(car_);
    }
    else {
        car car_(type, model, power, engine_type, max_speed);
        add_car(car_);
    }
    std::cout << "The car was successfully added" << std::endl;
}