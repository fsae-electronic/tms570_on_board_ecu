#ifndef DATA_MODEL_H
#define DATA_MODEL_H

#include <stdint.h>

enum motor_fault_t
{
    NO_FAULT = 0,
    OVERVOLTAGE,
    UNDERVOLTAGE,
    OVERCURRENT,
    OVERTEMP,
    INT_ERROR
};

enum drive_state_t
{
    OFF = 0,
    ON,
    FAULT
};

enum mode_t
{
    NORMAL= 0,
    RACE
};



typedef struct
{
    float rpm;

    float motor1_voltage;
    float motor1_current;
    float motor1_temp;

    float motor2_voltage;
    float motor2_current;
    float motor2_temp;

    float tps;
    float brake_front;
    float brake_rear;

    // telemetry additions
    float battery_voltage;
    float battery_current;
    float steering_angle;      // degrees or percent
    float wheel_speed_fl;      // front left
    float wheel_speed_fr;      // front right
    float wheel_speed_rl;      // rear left
    float wheel_speed_rr;      // rear right

    uint8_t traction_on;
    uint8_t drive_enabled;
    uint8_t telemetry_enabled;
    uint8_t mode;

    uint8_t motor1_fault;
    uint8_t motor2_fault;

    uint8_t drive_state;

    // historical data for graphs (circular buffer)
    #define GRAPH_BUFFER_SIZE 256
    float motor1_voltage_history[GRAPH_BUFFER_SIZE];
    float motor1_current_history[GRAPH_BUFFER_SIZE];
    float motor1_temp_history[GRAPH_BUFFER_SIZE];
    float battery_voltage_history[GRAPH_BUFFER_SIZE];
    float motor2_voltage_history[GRAPH_BUFFER_SIZE];
    float motor2_current_history[GRAPH_BUFFER_SIZE];
    float motor2_temp_history[GRAPH_BUFFER_SIZE];
    float battery_current_history[GRAPH_BUFFER_SIZE];
    float steering_angle_history[GRAPH_BUFFER_SIZE];
    float tps_history[GRAPH_BUFFER_SIZE];
    float brake_front_history[GRAPH_BUFFER_SIZE];
    float brake_rear_history[GRAPH_BUFFER_SIZE];
    float wheel_speed_fl_history[GRAPH_BUFFER_SIZE];
    float wheel_speed_fr_history[GRAPH_BUFFER_SIZE];
    float wheel_speed_rl_history[GRAPH_BUFFER_SIZE];
    float wheel_speed_rr_history[GRAPH_BUFFER_SIZE];
    int graph_buffer_index;

} dashboard_data_t;

#endif
