#ifndef NAVIGADOR_H
#define NAVIGADOR_H

#include <Arduino.h>
#include <List.hpp>

enum NavigadorDirection {
    NAVIGADOR_FORWARD_DIRECTION,
    NAVIGADOR_BACKWARD_DIRECTION,
    NAVIGADOR_LEFT_DIRECTION,
    NAVIGADOR_RIGHT_DIRECTION,
};

struct NavigadorPathStruct {
    uint8_t direction;
    unsigned long travel_duration;
};

typedef struct NavigadorPathStruct NavigadorPath;

class Navigador {
    public:
    Navigador(uint16_t motor_1a, uint16_t motor_1b, uint16_t motor_2a, uint16_t motor_2b);

    void forward();
    void backward();
    void left();
    void right();

    void forward(unsigned long travel_duration);
    void backward(unsigned long travel_duration);
    void left(unsigned long travel_duration);
    void right(unsigned long travel_duration);

    void add_path(NavigadorPath path);
    void remove_path(NavigadorPath path);

    void follow_path();
    void clear_path();

    void stop();

    private:
    uint16_t _pin_motor_1a,
        _pin_motor_1b,
        _pin_motor_2a,
        _pin_motor_2b;

    List<NavigadorPath> path_list;
};

#endif