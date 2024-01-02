#ifndef description
#define description

#include <string>
#include <iostream>

struct car {
    car(std::string type_, std::string model_, int power_, std::string engine_type_, int max_speed_) :
        type(type_), model(model_), power(power_), engine_type(engine_type_), max_speed(max_speed_) {}

    car() {}

    std::string type;
    std::string model;
    int power;
    std::string engine_type;
    int max_speed;
};

struct passenger_car : car {
    passenger_car(std::string type_, std::string model_, int power_, std::string engine_type_, int max_speed_, int doors_number_):
        car(type_, model_, power_, engine_type_, max_speed_), doors_number(doors_number_) {}

    passenger_car() {}

    int doors_number;
};

struct truck : car {
    truck(std::string type_, std::string model_, int power_, std::string engine_type_, int max_speed_, int load_capacity_, int axles_number_):
        car(type_, model_, power_, engine_type_, max_speed_), load_capacity(load_capacity_), axles_number(axles_number_) {}

    truck() {}


    int load_capacity;
    int axles_number;
};

struct bus : car {
    bus(std::string type_, std::string model_, int power_, std::string engine_type_, int max_speed_, int passengerSeats_number_):
        car(type_, model_, power_, engine_type_, max_speed_), passengerSeats_number(passengerSeats_number_) {}

    bus() {}

    int passengerSeats_number;
};

#endif
