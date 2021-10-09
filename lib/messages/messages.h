#ifndef MESSAGES_H
#define MESSAGES_H

#include <Arduino.h>

namespace messages {

typedef enum command {
    NO_OP = 0000,
    STATUS_REQ = 0001,
    STATUS_RES = 0002,
    TURN_ON_PUMP = 0003,
    TURN_OFF_PUMP = 0004,
    TURN_ON_AUX = 0005,
    TURN_OFF_AUX = 0006,
    ALERT = 0007,
} command_t;

typedef enum alert {
    NO_ALERT = 0000,
    LOW_WATER_LEVEL = 0001,
    COMMAND_OVERRIDEN = 0002,  // command overriden -maybe trying to turn the
                               // pump on just after turning it off
    INVALID_COMMAND_FORMAT = 0003,  // command format
    OUT_OF_ORDER_COMMAND = 0004,  // seq number is not greater than last message
} alert_t;

typedef struct __attribute__((packed)) message {
    uint16_t seq;
    uint8_t command;
    uint8_t value;
    uint8_t salt;
} message_t;

void pack(void *buffer, message_t message);
}  // namespace messages

#endif