/************************************************************************/
/*                          Temperature Manager                         */
/************************************************************************/
#include "TMP_Manager.h"

/* Declare and Define Global Variables Shared with other files */
uint8_t SET_Temperature = 25U;
uint8_t CRT_Temperature = 0U;

extern uint8_t CRT_TEMP_COUNTER;
extern uint8_t SET_TEMP_COUNTER;

extern uint8_t state_indx;

uint8_t reading_buffer = 0;
uint8_t temp_reading = 0;
uint8_t pos = 0; /* Indicates the units and tens in SET Temperature */

uint8_t debouncing_counter = 0;

/*************************************************************************/
/* Function Description:                                                 */
/* Initialization of the keypad and TC72 Temperature Sensor to the entire*/
/* system.                                                               */
/*************************************************************************/
void TMP_Manager_vInit(void) {
    keypad_vInit();
    TC72_Init(ONE_SHOT_MODE);
}

/*************************************************************************/
/* Function Description:                                                 */
/* Read/Fetch Current Temperature from TC72 and Reset Current Temperature*/
/* Counter.                                                              */
/*************************************************************************/
void Update_CRT_Temperature(void) {
    /* This means when (200 ms) is passed */
    if (CRT_TEMP_COUNTER >= 20U) {
        CRT_Temperature = (uint8_t) TC72_Read();
        CRT_TEMP_COUNTER = 0U;
    } else {
        /* Do Nothing, Didn't reach the required time */
    }
}


/*************************************************************************/
/* Function Description:                                                 */
/* Read/Fetch the Set Temperature given/written by the User on Keypad.   */
/* The Fetch is done every 200 ms                                        */
/*************************************************************************/
void Update_SET_Temperature(void) {
    /* This means when (200 ms) is passed */
    if (SET_TEMP_COUNTER >= 20U) {
        /* Get SET Temperature From Keypad */
        reading_buffer = keypad_u8check_press();

        /* Check that User Pressed an actual Key */
        if ((reading_buffer != NOTPRESSED) && (reading_buffer != HASH_KEY)) {
            SET_Temperature = reading_buffer;
            if (pos == 0U) {
                temp_reading = reading_buffer * 10U;
                pos++;
            } else {
                temp_reading += reading_buffer;
                SET_Temperature = temp_reading;

                /* (pos is 1 now) we need to reset it with 0*/
                pos = 0U;
            }
        } else {
            /* Do Nothing (Nothing is pressed) */
            /* LED_vTurnOff('D', 0); */
        }

        SET_TEMP_COUNTER = 0U;
    } else {
        /* Do Nothing, Didn't reach the required time */
    }
}
