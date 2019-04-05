#include "hal_data.h"

ioport_level_t P0_05Status;
ioport_level_t P0_06Status;
const bsp_delay_units_t bsp_delay_units = BSP_DELAY_UNITS_MILLISECONDS;     /* Define the units to be used with the software delay function */
uint32_t delay = 10;                                                 /* Calculate the delay in terms of bsp_delay_units */

void hal_entry(void) {
    while(1)
    {
        g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_00, IOPORT_LEVEL_HIGH);
        R_BSP_SoftwareDelay(delay, bsp_delay_units);/* Delay */
        g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_01, IOPORT_LEVEL_HIGH);
        R_BSP_SoftwareDelay(delay, bsp_delay_units);/* Delay */
        g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_02, IOPORT_LEVEL_HIGH);
        R_BSP_SoftwareDelay(delay, bsp_delay_units);/* Delay */

        g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_00, IOPORT_LEVEL_LOW);
        R_BSP_SoftwareDelay(delay, bsp_delay_units);/* Delay */
        g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_01, IOPORT_LEVEL_LOW);
        R_BSP_SoftwareDelay(delay, bsp_delay_units);/* Delay */
        g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_02, IOPORT_LEVEL_LOW);
        R_BSP_SoftwareDelay(delay, bsp_delay_units);/* Delay */

        g_ioport.p_api->pinRead(IOPORT_PORT_00_PIN_05, &P0_05Status);
        if(P0_05Status == IOPORT_LEVEL_LOW && delay <= 100){
            delay = delay+1;
        }

        g_ioport.p_api->pinRead(IOPORT_PORT_00_PIN_06, &P0_06Status);
        if(P0_06Status == IOPORT_LEVEL_LOW && delay > 1){
            delay = delay-1;
        }
    }
}
