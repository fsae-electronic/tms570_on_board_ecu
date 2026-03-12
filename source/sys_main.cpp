#include "Bridgetek_EVE2.h"

#include "dashboard.h"
#include "ui_touch.h"
#include "data_model.h"

// EEPROM helpers moved to ui_touch.cpp. prototypes in ui_touch.h


Bridgetek_EVE2 eve;

dashboard_data_t data;

int main()
{

    eve.setup(WQVGA);
    eve.Init();


    eve_calibrate(eve);


    data.rpm = 4500;

    data.motor1_voltage = 320;
    data.motor1_current = 80;
    data.motor1_temp = 45;

    data.motor2_voltage = 320;
    data.motor2_current = 82;
    data.motor2_temp = 47;

    data.tps = 35;
    data.brake_front = 10;
    data.brake_rear = 5;

    data.battery_voltage = 400;
    data.battery_current = 50;
    data.steering_angle = 0;
    data.wheel_speed_fl = 0;
    data.wheel_speed_fr = 0;
    data.wheel_speed_rl = 0;
    data.wheel_speed_rr = 0;

    data.traction_on = 1;
    data.drive_enabled = 0;

    data.mode = NORMAL; // NORMAL
    data.motor1_fault = NO_FAULT;
    data.motor2_fault = NO_FAULT;
    data.drive_state = OFF;


    while(1)
    {
        // Primero dibuja los botones con sus TAGs
        dashboard_draw(eve, &data);

        // simular variación en telemetría
        data.battery_voltage += 0.1;
        if (data.battery_voltage > 420) data.battery_voltage = 380;
        data.battery_current += 0.05;
        if (data.battery_current > 60) data.battery_current = 40;
        data.steering_angle += 1;
        if (data.steering_angle > 90) data.steering_angle = -90;
        data.tps += 1;
        if (data.tps > 100) data.tps = 0;
        data.brake_front += 0.5;
        if (data.brake_front > 100) data.brake_front = 0;
        data.brake_rear += 0.3;
        if (data.brake_rear > 100) data.brake_rear = 0;

        data.wheel_speed_fl += 1;
        data.wheel_speed_fr += 1.2;
        data.wheel_speed_rl += 0.8;
        data.wheel_speed_rr += 0.9;
        if (data.wheel_speed_fl > 250) data.wheel_speed_fl = 0;
        if (data.wheel_speed_fr > 250) data.wheel_speed_fr = 0;
        if (data.wheel_speed_rl > 250) data.wheel_speed_rl = 0;
        if (data.wheel_speed_rr > 250) data.wheel_speed_rr = 0;

        data.rpm += 50;
        if (data.rpm > 5000) data.rpm = 0;

        // simulate faults occasionally
        static int sim_counter = 0;
        sim_counter++;
        if (sim_counter % 1000 == 0) {
            data.motor1_fault = (data.motor1_fault + 1) % 6; // cycle through faults
            data.motor2_fault = (data.motor2_fault + 1) % 6;
            data.drive_state = (data.drive_state + 1) % 3; // OFF, ON, FAULT
        }

        // update graph buffers
        data.motor1_voltage_history[data.graph_buffer_index] = data.motor1_voltage;
        data.motor1_current_history[data.graph_buffer_index] = data.motor1_current;
        data.motor1_temp_history[data.graph_buffer_index] = data.motor1_temp;
        data.battery_voltage_history[data.graph_buffer_index] = data.battery_voltage;
        data.motor2_voltage_history[data.graph_buffer_index] = data.motor2_voltage;
        data.motor2_current_history[data.graph_buffer_index] = data.motor2_current;
        data.motor2_temp_history[data.graph_buffer_index] = data.motor2_temp;
        data.battery_current_history[data.graph_buffer_index] = data.battery_current;
        data.steering_angle_history[data.graph_buffer_index] = data.steering_angle;
        data.tps_history[data.graph_buffer_index] = data.tps;
        data.brake_front_history[data.graph_buffer_index] = data.brake_front;
        data.brake_rear_history[data.graph_buffer_index] = data.brake_rear;
        data.wheel_speed_fl_history[data.graph_buffer_index] = data.wheel_speed_fl;
        data.wheel_speed_fr_history[data.graph_buffer_index] = data.wheel_speed_fr;
        data.wheel_speed_rl_history[data.graph_buffer_index] = data.wheel_speed_rl;
        data.wheel_speed_rr_history[data.graph_buffer_index] = data.wheel_speed_rr;
        data.graph_buffer_index = (data.graph_buffer_index + 1) % GRAPH_BUFFER_SIZE;


        // Pequeño delay para permitir que hardware procese toques
        // delay(20);

        // Luego lee el toque (después que los botones tienen TAGs)
        ui_handle_touch(eve, &data);
    }
}
