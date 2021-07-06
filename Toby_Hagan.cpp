// Lab 10 - Toby Hagan 40254482

#include "mbed.h"
#include "C12832_lcd.h"
#include "LM75B.h"


//  C12832 LCD display library by Peter Drescher 
//  https://os.mbed.com/users/dreschpe/code/C12832_lcd/
//
//  LM75B temperature sensor library by Neil Thiessen
//  https://os.mbed.com/users/neilt6/code/LM75B/ 


// **** Global Variables *****
C12832_LCD lcd;           // Create LCD display object  128 x 32 
LM75B t_sensor(p28,p27);  // Create temp sensor object Addr 0x90

DigitalOut led_1(LED1);   // Onboard LED used for debugging

AnalogIn potentiometer_1(p19);    // Pot 1 on pin 19 (range 0.0 to 1.0)
AnalogIn potentiometer_2(p20);    // Pot 1 on pin 20 (range 0.0 to 1.0)

DigitalIn pb_centre(p14);   // joystick centre push button

Serial pc(USBTX,USBRX);   // Serial comms object

int state;  // Store program state - Display temp in 1=Celsius 2=Fahrenheit

PwmOut blueLed(p25);    // Blue led declaration
PwmOut redLed(p23);    //Red led declaration

int main()
{
    // Initialise led lights as off.
    blueLed=1;
    redLed=1;
    
    float temp_c = 0;  // Initialse variable for current temperature in Celsius
    float temp_f = 0;  // Current temperature in Fahrenheit
    
    int serial_char = 0;  // Character buffer from serial port
    
    // Initialise global variables
    state = 1;   // Display temperature in Celsius
    
    while(1) 
    {
        
        // ******** Joystick Button ********
        if(pb_centre==1) // Center push button pressed
        {
            // pulse_LCD(led_1);  // Pulse LED 1 to help debug
            
            if(state==1) // Toggle program state from (1 to 2) or (2 to 1)
                state=2;  
            else if(state==2) 
                state=3;
            else if(state==3)
                state=1;
            
            while(pb_centre) // loop while centr push button is held down
            {}
        }
        
        
        // ******** PuTTY Terminal ********
        // Check if data waiting in serial port buffer
        if(pc.readable())
        {
            serial_char = pc.getc();  // Display chararacter on 7 segment
                
            if(serial_char=='C' || serial_char=='c')
            {               
                pc.printf("Board temperature = %.2f C \r\n", temp_c ); 
                pc.printf("Display is in Celsius \r\n\n");
                state=1;
            }
            else if(serial_char=='F' || serial_char=='f')
            {               
                pc.printf("Board temperature = %.2f F \r\n", temp_f );
                pc.printf("Display is in Fahrenheit \r\n\n");
                state=2;
            }
            else if(serial_char=='B' || serial_char=='b')
            {               
                pc.printf("*** Display Blanked *** \r\n\n");
                state=3;
            }
        }
        
        
        // ******** Top Row Display ********
        lcd.locate(1,1);  //  Locate cursor to test row 2 on LCD (col, row)
             
        // Read temperature from sensor in Celsius
        temp_c = t_sensor.temp(); 

        temp_f = (temp_c * 1.8)+32;  // Calculate Fahrenheit
        
        if(state==1)
        {
            // Display current temperature in degrees celsius
            lcd.printf("Current Temperature %.1f C ", temp_c ); 
        }
        else if(state==2)
        {
            // Display current temperature in degrees fahrenheit
            lcd.printf("Current Temperature %.1f F ", temp_f ); 
        }
        else if(state==3)
        {
            lcd.cls();
        }
        
        
        // ******** Middle Row Display ********
        lcd.locate(1,10);
        
        // Read the high boundary using potentiometer 2
        float high_input_deg_C = (70 * potentiometer_2.read()) - 10.0;
        float high_input_deg_F = (high_input_deg_C * 1.8) +32;
        
        if(state==1)
        {
            // Display high limit temperature in degrees celsius
            lcd.printf("High Limit(20 to 80)  %2.f C", high_input_deg_C);
        }
        else if(state==2)
        {
            // Display high limit temperature in degrees fahrenheit
            lcd.printf("High Limit(68 to 176) %2.f F", high_input_deg_F);
        }
        else if(state==3)
        {
            lcd.cls();
        }
        
        
        // ******** Bottom Row Display ********
        lcd.locate(1,21);
        // Read the low boundary using potentiometer 1
        float low_input_deg_C = (70 * potentiometer_1.read()) - 10.0;
        float low_input_deg_F = (low_input_deg_C * 1.8) +32;
        
        if(state==1)
        {
            // Display low limit temperature in degrees celsius
            lcd.printf("Low Limit(-15 to 35)  %2.f C", low_input_deg_C);
        }
        else if(state==2)
        {
            // Display low limit temperature in degrees fahrenheit
            lcd.printf("Low Limit(5 to 95)    %2.f F", low_input_deg_F);
        }
        else if(state==3)
        {
            lcd.cls();
        }
        
        
        // ********* Alarm Lights ********
        // Two if statements and else statements are used to allow both lights
        // to be on at the same time.
        
        // If statement to check if current temperature is above the high limit
        if (temp_c>high_input_deg_C)
        {
            redLed=0;    // Red LED turned on
        }
        else
        {
            redLed=1;    // Red LED turned off
        }
        
        // If statement to check if current temperature is below the low limit
        if (temp_c<low_input_deg_C)
        {
            blueLed=0;    // Blue LED turned on
        }
        else
        {
            blueLed=1;    // Blue LED turned off
        }
    }
}
