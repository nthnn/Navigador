#ifndef NAVIGADOR_H
#define NAVIGADOR_H

#include <Arduino.h>
#include <List.h>

enum NavigadorDirection {
    NAVIGADOR_FORWARD_DIRECTION,
    NAVIGADOR_BACKWARD_DIRECTION,
    NAVIGADOR_LEFT_DIRECTION,
    NAVIGADOR_RIGHT_DIRECTION,
}

struct NavigadorPathStruct {
    uint8_t direction;
    unsigned long travel_duration;
};

typedef struct NavigadorPathStruct NavigadorPath;

class Navigador {
    public:
    Navigador(uint16_t motor_1a, uint16_t motor_1b, uint16_t motor_2a, uint16_t motor_2b):
        _pin_motor_1a(motor_1a),
        _pin_motor_1b(motor_1b),
        _pin_motor_2a(motor_2a),
        _pin_motor_2b(motor_2b) {
        pinMode(this->_pin_motor_1a, OUTPUT);
        pinMode(this->_pin_motor_1b, OUTPUT);
        pinMode(this->_pin_motor_2a, OUTPUT);
        pinMode(this->_pin_motor_2b, OUTPUT);
    }

    void forward() {
        digitalWrite(this->_pin_motor_1a, HIGH);
        digitalWrite(this->_pin_motor_1b, LOW);
        digitalWrite(this->_pin_motor_2a, HIGH);
        digitalWrite(this->_pin_motor_2b, LOW);
    }

    void forward(unsigned long travel_duration) {
        this->forward();

        delay(travel_duration);
        this->stop();
    }

    void backward() {
        digitalWrite(this->_pin_motor_1a, LOW);
        digitalWrite(this->_pin_motor_1b, HIGH);
        digitalWrite(this->_pin_motor_2a, LOW);
        digitalWrite(this->_pin_motor_2b, HIGH);
    }

    void backward(unsigned long travel_duration) {
        this->forward();

        delay(travel_duration);
        this->stop();
    }

    void left() {
        digitalWrite(this->_pin_motor_1a, HIGH);
        digitalWrite(this->_pin_motor_1b, LOW);
        digitalWrite(this->_pin_motor_2a, LOW);
        digitalWrite(this->_pin_motor_2b, HIGH);
    }

    void left(unsigned long travel_duration) {
        this->left();

        delay(travel_duration);
        this->stop();
    }

    void right() {
        digitalWrite(this->_pin_motor_1a, LOW);
        digitalWrite(this->_pin_motor_1b, HIGH);
        digitalWrite(this->_pin_motor_2a, HIGH);
        digitalWrite(this->_pin_motor_2b, LOW);
    }

    void right(unsigned long travel_duration) {
        this->right();

        delay(travel_duration);
        this->stop();
    }

    void stop() {
        digitalWrite(this->_pin_motor_1a, LOW);
        digitalWrite(this->_pin_motor_1b, LOW);
        digitalWrite(this->_pin_motor_2a, LOW);
        digitalWrite(this->_pin_motor_2b, LOW);
    }

    void add_path(NavigadorPath path) {
        this->path_list.push_back(path);
    }

    void remove_path(NavigadorPath path) {
        for(size_t i = 0; i < this->path_list.size(); i++)
            if(this->path_list[i].direction == path.direction &&
                this->path_list[i].travel_duration == path.travel_duration) {
                this->path_list.remove(i);
                break;
            }
    }

    void follow_path() {
        for(auto path : this->path_list) {
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

    void clear_path() {
        this->path_list.clear();
    }

    private:
    uint16_t _pin_motor_1a;
    uint16_t _pin_motor_1b;
    uint16_t _pin_motor_2a;
    uint16_t _pin_motor_2b;

    List<NavigadorPath> path_list;
};

#endif