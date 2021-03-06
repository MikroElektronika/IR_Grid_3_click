/*
Example for IRGrid3 Click

    Date          : sep 2018.
    Author        : Katarina Perendic

Test configuration PIC32 :
    
    MCU                : P32MX795F512L
    Dev. Board         : EasyPIC Fusion v7
    PIC32 Compiler ver : v4.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes I2C module and USB UART for data logging
- Application Initialization - Initializes driver init and IR Grid 3 module
- Application Task - (code snippet) - Reads the temperature of all pixels and creates a pixel temperature matrix that logs on usbuart every 500ms

- note :
   The sensor needs about 4 minutes for calibration

*/

#include "Click_IRGrid3_types.h"
#include "Click_IRGrid3_config.h"

float pixelTemp[768];
float Ta = 0;
uint16_t cnt;
char demoText[ 100 ];

void systemInit()
{
    Delay_80us();
    mikrobus_i2cInit( _MIKROBUS1, &_IRGRID3_I2C_CFG[0] );
    mikrobus_logInit( _LOG_USBUART_A, 115200 );
    mikrobus_logWrite(" --- System Init --- ", _LOG_LINE);
    Delay_ms( 100 );
}

void applicationInit()
{
    irgrid3_i2cDriverInit( (T_IRGRID3_P)&_MIKROBUS1_GPIO, (T_IRGRID3_P)&_MIKROBUS1_I2C, 0x33 );
    irgrid3_deviceConfiguration();
    mikrobus_logWrite("--- Start measurement ---", _LOG_LINE);
    Delay_100ms();
}

void applicationTask()
{
    irgrid3_getPixelTemperature(&Ta,&pixelTemp[0]);

    mikrobus_logWrite("Ambient temperature:  ",_LOG_TEXT);
    FloatToStr(Ta,demoText);
    mikrobus_logWrite(demoText,_LOG_LINE);
    mikrobus_logWrite(" ", _LOG_LINE);
    mikrobus_logWrite("--- Pixel temperature matrix 32x24 ---", _LOG_LINE);


    for ( cnt = 0 ; cnt < 768 ; cnt++)
    {
        FloatToStr(pixelTemp[cnt],demoText);
        demoText[ 5 ] = 0 ;
        mikrobus_logWrite(demoText, _LOG_TEXT);
        mikrobus_logWrite("|", _LOG_TEXT);
        Delay_1ms();
        if(((cnt % 32) == 0) && (cnt > 0))
        {
            mikrobus_logWrite(" ", _LOG_LINE);
        }
    }
    mikrobus_logWrite(" ", _LOG_LINE);
    Delay_ms( 500 );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}