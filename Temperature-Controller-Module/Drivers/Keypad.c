/************************************************************************/
/*                          Keypad Driver                               */
/************************************************************************/
#include "Keypad.h"

extern char PORTS[4];
uint8_t prev[4][3] = {{0, 0, 0},
                      {0, 0, 0},
                      {0, 0, 0},
                      {0, 0, 0}};
uint8_t counter_debounce = DEBOUNCING_COUNTER;
uint8_t hash_debounce = DEBOUNCING_COUNTER;

/************************************************************************/
/* Function Description:                                                */
/* Function Initiator for a 4*3 Keypad on PORTD, The Function set the   */
/* Keypad Ports Direction as outputs (First Four) and Input (Last 3)    */
/* Then Enable Port Pull Ups                                            */
/************************************************************************/
void keypad_vInit(void) {

    /* Set Output Pins */
    DIO_vsetPINDir(PORTS[KEYPADPORT], 0U, 1U);
    DIO_vsetPINDir(PORTS[KEYPADPORT], 1U, 1U);
    DIO_vsetPINDir(PORTS[KEYPADPORT], 2U, 1U);
    DIO_vsetPINDir(PORTS[KEYPADPORT], 3U, 1U);

    /* Set Input  */
    DIO_vsetPINDir(PORTS[KEYPADPORT], 4U, 0U);
    DIO_vsetPINDir(PORTS[KEYPADPORT], 5U, 0U);
    DIO_vsetPINDir(PORTS[KEYPADPORT], 6U, 0U);

    /* Pull Up  */
    DIO_Connect_PullUp(PORTS[KEYPADPORT], 4U, 1U);
    DIO_Connect_PullUp(PORTS[KEYPADPORT], 5U, 1U);
    DIO_Connect_PullUp(PORTS[KEYPADPORT], 6U, 1U);

}

/************************************************************************/
/* Function Description:                                                */
/* Matrix Loop Function that checks all Elements in the Keypad Matrix   */
/* (4*3) and Return the Pressed Element if the Circuit was closed, It	*/
/* also Includes a solution for De-bouncing the Button State which      */
/* Affected our Process                                                 */
/************************************************************************/
uint8_t keypad_u8check_press(void) {
    /* Keypad Matrix Definition */
    uint8_t kp[4][3] = {{1U, 2U, 3U},
                        {4U, 5U, 6U},
                        {7U, 8U, 9U},
                        {0U, 0U, 12U}};
    uint8_t row;
    uint8_t column;
    uint8_t ON;
    uint8_t returnval = NOTPRESSED;

    /* Matrix Loop Check for each Keypad Element */
    for (row = 0U; row < 4U; row++) {
        /* Set Output Pins HIGH*/
        DIO_Write_PIN(PORTS[KEYPADPORT], 0U, 1U);
        DIO_Write_PIN(PORTS[KEYPADPORT], 1U, 1U);
        DIO_Write_PIN(PORTS[KEYPADPORT], 2U, 1U);
        DIO_Write_PIN(PORTS[KEYPADPORT], 3U, 1U);

        /*Send Signal LOW*/
        DIO_Write_PIN(PORTS[KEYPADPORT], row, 0U);
        for (column = 0U; column < 3U; column++) {
            /* Read Sent Signal */
            ON = DIO_Read_PIN(PORTS[KEYPADPORT], (column + 4U));

            /*Button Pressed*/
            if (ON == 0U) {
                /*The Button is pressed but needs De-Bouncing*/
                prev[row][column] = 1U;
                /*Decrease The count*/
                counter_debounce = counter_debounce - 1U;
            } else if ((counter_debounce == 0U) && (prev[row][column] == 1U)) {
                /* Current Element is De-Bounced*/
                returnval = kp[row][column];
                /*Reset Previous State*/
                prev[row][column] = 0U;
                /*Reset Counter*/
                counter_debounce = DEBOUNCING_COUNTER;
                /*Break Loop to Return*/
                break;
            } else {
                /*No Button Pressed*/
            }
        }
        /* Break Higher Loop */
        if ((ON == 0U) && (counter_debounce == 0U)) {
            break;
        } else {
            /* Do Nothing */
        }
    }

    /* Return Pressed Key */
    return returnval;
}

/************************************************************************/
/* Function Description:                                                */
/* This Function is a Specific Driver Function that Checks the # Key in */
/* the matrix, Return True When the Button is Pressed, Also Added the   */
/* De-bouncing Algorithm                                                */
/************************************************************************/
uint8_t keypad_Check_OPKey(void) {
    /* Button State */
    uint8_t btn_val;
    /* Condition Return */
    uint8_t pressed = 0U;

    /* Send Signal in Specified Cow */
    DIO_Write_PIN(PORTS[KEYPADPORT], 0U, 1U);
    DIO_Write_PIN(PORTS[KEYPADPORT], 1U, 1U);
    DIO_Write_PIN(PORTS[KEYPADPORT], 2U, 1U);
    DIO_Write_PIN(PORTS[KEYPADPORT], 3U, 0U);

    /* Read from Specified Column */
    btn_val = DIO_Read_PIN(PORTS[KEYPADPORT], 6U);

    if (btn_val == 0U) {
        /* Decrease Counter */
        hash_debounce = hash_debounce - 1U;
    } else if (hash_debounce == 0U) {
        /* Finish De-bouncing -> return pressed value */
        hash_debounce = DEBOUNCING_COUNTER;
        pressed = 1U;
    } else {
        /* Do Nothing */
    }
    return pressed;
}
/************************************************************************/
