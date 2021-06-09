# Temperature Controller Module

Temperature Controller is a System designed to provide Temperature Control Functionality. The System provide the User the ability to reach a Set Temperature `SET_TEMPERATURE` by applying a PWM Voltage to a Heater with a selected Intensity controlled by user. The System Display it's States which notify the user of what System Processes are running in the background. 

## System Interface 

Below you can find the System Design Interface on Proteus 8.10. On the left all user interactions are collected from LCD Display, Keypad, System State LEDs and the Intensity Potentiometer. On the right the backbone of the System placed. Our Brain and Muscles presented in the ATMEGA32 Microcontroller, TC72 Temperature Sensor and PWM Circuit Converter. For the sake of Testing an Oscilloscope was added to see the Heater Operation from Enabling the Heater and Different Duty Cycles Applied to Disabling the Heater on NORMAL States.

<img src="Sources\System.png" style="zoom: 50%;" />

## System Operation

First a Welcoming Animation starts indicating the start of the System. Then the Idle screen is displayed with a default 25c SET TEMPERATURE, This is the STANDBY state at which the System starts Operation. The System Operates in Four different States: 

- STANDBY: At this State the System awaits the User to enter desired SET TEMPERATURE which the system will try to achieve, moving to the second state requires the user to press # Key on the Keypad
- OPERATIONAL: At this state the System starts measuring the CRT TEMPERATURE which is the current Heater Temperature and compare with the selected temperature to apply PWM Voltage which turns the Heater On until reaching the marginal area of Temperature difference which moves us to the second state.
- NORMAL: At this state the System has reached it's desired SET Temperature with at least 5c error. The System tries to maintain such state at operation by turning the heater on or off at this state, in case of failing this operation the system moves to the fourth state.
- ERROR: At this state the system has failed to reach it's desired temperature which requires the user to Restart the System.

Our states operation are better described in the following diagram which shows the relations between states, how the system can jump from state to the other and what are the operational components of the system at each state. 

<img src="Sources\System States.jpg" style="zoom: 25%;" />

## System Design

We followed a Layered Architecture to best design our System to meet the User's needs. The Layers Starts from the Top at our Main Script which is a Higher Manager (Mode Manager), Next come the Lower Managers Heater Control, Display Manager Scheduler and Temperature Manager. These four Managers are the Process Controllers for the Mode Manager. Each Manager has a defined set of Tasks :

- Display Manager: Main Controller of the LCD Display Functionalities. Displays both Welcoming Screen, Idle Screen, System States and Temperatures 
- Heater Control: From the name, It Controls the Heater's Functionality From Disabling the Heater to Enabling the Heater, Heater Intensity Control, System States Check and System State LEDs.
- Scheduler: This is our Timer Manager, Most of our Tasks are Periodic like taking the Sensor's Read every 200ms and Updating Heater Intensity every 500ms.
- Temperature Manager: Main Interface to the TC72 Sensor, also responsible for the update of the CRT and SET Temperatures.

Our Design is also better described through the following diagram which shows the relations between managers and what each file in the project is and it's dependencies.

<img src="Sources\System Design.png" style="zoom:67%;" />



## System Components

Our System is composed of the following components

- ATMEGA32 Microcontroller: System Brains 
- LCD Display: User Display
- Keypad: User Interface/Control
- TC72 : Temperature Sensor 
- Potentiometer: Heater Intensity Controller