#ifndef _ADCS_DEVICE_H_
#define _ADCS_DEVICE_H_

/*
** Required header files.
*/
#include "device_cfg.h"
#include "hwlib.h"

/*
** Type definitions
*/
#define ADCS_DEVICE_HDR_0 0xC0
#define ADCS_DEVICE_HDR_1 0xFF
#define ADCS_DEVICE_HDR   ((ADCS_DEVICE_HDR_0 << 8) | ADCS_DEVICE_HDR_1)

#define ADCS_DEVICE_NOOP_CMD     0x00
#define ADCS_DEVICE_REQ_HK_CMD   0x01
#define ADCS_DEVICE_REQ_DATA_CMD 0x02
#define ADCS_DEVICE_CFG_CMD      0x03

#define ADCS_DEVICE_TRAILER_0 0xFE
#define ADCS_DEVICE_TRAILER_1 0xFE
#define ADCS_DEVICE_TRAILER   ((ADCS_DEVICE_TRAILER_0 << 8) | ADCS_DEVICE_TRAILER_1)

#define ADCS_DEVICE_CMD_SIZE    8
#define ADCS_DEVICE_HDR_TRL_LEN 4

/*
** ADCS device housekeeping telemetry definition
*/
typedef struct
{
    uint16_t DeviceCounter;
    uint16_t DeviceConfig;

} __attribute__((packed)) ADCS_Device_HK_tlm_t;
#define ADCS_DEVICE_HK_LNGTH sizeof(ADCS_Device_HK_tlm_t)
#define ADCS_DEVICE_HK_SIZE  ADCS_DEVICE_HK_LNGTH + ADCS_DEVICE_HDR_TRL_LEN

/*
** ADCS device data telemetry definition
*/
typedef struct
{
    uint16_t Chan1;
    uint16_t Chan2;
    uint16_t Chan3;

} __attribute__((packed)) ADCS_Device_Data_tlm_t;
#define ADCS_DEVICE_DATA_LNGTH sizeof(ADCS_Device_Data_tlm_t)
#define ADCS_DEVICE_DATA_SIZE  ADCS_DEVICE_DATA_LNGTH + ADCS_DEVICE_HDR_TRL_LEN

/*
** Prototypes
*/
int32_t ADCS_ReadData(uart_info_t *device, uint8_t *read_data, uint8_t data_length);
int32_t ADCS_CommandDevice(uart_info_t *device, uint16_t cmd, uint16_t payload);
int32_t ADCS_RequestHK(uart_info_t *device, ADCS_Device_HK_tlm_t *data);
int32_t ADCS_RequestData(uart_info_t *device, ADCS_Device_Data_tlm_t *data);

#endif /* _ADCS_DEVICE_H_ */
