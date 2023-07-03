#include <Arduino.h>

#include "navigador.h"

Navigador::Navigador(uint16_t motor_1a, uint16_t motor_1b, uint16_t motor_2a, uint16_t motor_2b):
    _pin_motor_1a(motor_1a),
    _pin_motor_1b(motor_1b),
    _pin_motor_2a(motor_2a),
    _pin_motor_2b(motor_2b) {
    pinMode(this->_pin_motor_1a, OUTPUT);
    pinMode(this->_pin_motor_1b, OUTPUT);
    pinMode(this->_pin_motor_2a, OUTPUT);
    pinMode(this->_pin_motor_2b, OUTPUT);
}

void Navigador::forward() {
    digitalWrite(this->_pin_motor_1a, HIGH);
    digitalWrite(this->_pin_motor_1b, LOW);
    digitalWrite(this->_pin_motor_2a, HIGH);
    digitalWrite(this->_pin_motor_2b, LOW);
}

void Navigador::forward(unsigned long travel_duration) {
    this->forward();

    delay(travel_duration);
    this->stop();
}

void Navigador::backward() {
    digitalWrite(this->_pin_motor_1a, LOW);
    digitalWrite(this->_pin_motor_1b, HIGH);
    digitalWrite(this->_pin_motor_2a, LOW);
    digitalWrite(this->_pin_motor_2b, HIGH);
}

void Navigador::backward(unsigned long travel_duration) {
    this->forward();

    delay(travel_duration);
    this->stop();
}

void Navigador::left() {
    digitalWrite(this->_pin_motor_1a, HIGH);
    digitalWrite(this->_pin_motor_1b, LOW);
    digitalWrite(this->_pin_motor_2a, LOW);
    digitalWrite(this->_pin_motor_2b, HIGH);
}

void Navigador::left(unsigned long travel_duration) {
    this->left();

    delay(travel_duration);
    this->stop();
}

void Navigador::right() {
    digitalWrite(this->_pin_motor_1a, LOW);
    digitalWrite(this->_pin_motor_1b, HIGH);
    digitalWrite(this->_pin_motor_2a, HIGH);
    digitalWrite(this->_pin_motor_2b, LOW);
}

void Navigador::right(unsigned long travel_duration) {
    this->right();

    delay(travel_duration);
    this->stop();
}

void Navigador::stop() {
    digitalWrite(this->_pin_motor_1a, LOW);
    digitalWrite(this->_pin_motor_1b, LOW);
    digitalWrite(this->_pin_motor_2a, LOW);
    digitalWrite(this->_pin_motor_2b, LOW);
}

void Navigador::add_path(NavigadorPath path) {
    this->path_list.add(path);
}

void Navigador::remove_path(NavigadorPath path) {
    for(size_t i = 0; i < this->path_list.getSize(); i++)
        if(this->path_list[i].direction == path.direction &&
            this->path_list[i].travel_duration == path.travel_duration) {
            this->path_list.remove(i);
            break;
        }
}

void Navigador::follow_path() {
    for(int i = 0; i < this->path_list.getSize(); i++) {
        NavigadorPath path = this->path_list[i];

        switch(path.direction) {
            case NAVIGADOR_FORWARD_DIRECTION:
                this->forward();
                break;
            case NAVIGADOR_BACKWARD_DIRECTION:
                this->backward();
                break;
            case NAVIGADOR_LEFT_DIRECTION:
                this->left();
                break;
            case NAVIGADOR_RIGHT_DIRECTION:
                this->right();
                break;
            default:
                break;
        }

        delay(path.travel_duration);
        this->stop();
    }
}

void Navigador::clear_path() {
    this->path_list.clear();
}
