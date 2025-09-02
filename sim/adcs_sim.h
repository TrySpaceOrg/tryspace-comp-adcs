#ifndef ADCS_SIM_H
#define ADCS_SIM_H

#include <math.h>
#include "adcs_device.h"
#include "simulith.h"
#include "simulith_component.h"
#include "simulith_42_context.h"
#include "simulith_42_commands.h"

// Configuration parameters
#define ADCS_SIM_UPDATE_RATE_HZ 10

// Status codes
#define ADCS_SIM_SUCCESS 0
#define ADCS_SIM_ERROR  1

// Adcs simulator state
typedef struct 
{
    // Communication handles
    uint8_t uart_port;
    uint32_t uart_handle;
    void* time_handle;
    // Simulator specifics
    double last_update_time;
    // Device specifics
    ADCS_Device_HK_tlm_t hk;
    ADCS_Device_Data_tlm_t data;
} adcs_sim_state_t;

// Function declarations
static void send_housekeeping(adcs_sim_state_t* state);
static void send_adcs_data(adcs_sim_state_t* state);
static void handle_command(adcs_sim_state_t* state, const uint8_t* data, size_t length);
static void adcs_sim_on_tick(uint64_t tick_time_ns, const simulith_42_context_t* context_42);
int adcs_sim_init(adcs_sim_state_t* state);
void adcs_sim_cleanup(adcs_sim_state_t* state);

#endif /* ADCS_SIM_H */ 