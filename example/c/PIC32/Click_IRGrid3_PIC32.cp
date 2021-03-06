#line 1 "D:/Clicks_git/I/IRGrid_3_Click/SW/example/c/PIC32/Click_IRGrid3_PIC32.c"
#line 1 "d:/clicks_git/i/irgrid_3_click/sw/example/c/pic32/click_irgrid3_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic32/include/stdint.h"




typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "d:/clicks_git/i/irgrid_3_click/sw/example/c/pic32/click_irgrid3_config.h"
#line 1 "d:/clicks_git/i/irgrid_3_click/sw/example/c/pic32/click_irgrid3_types.h"
#line 17 "d:/clicks_git/i/irgrid_3_click/sw/example/c/pic32/click_irgrid3_config.h"
const uint32_t _IRGRID3_I2C_CFG[ 1 ] =
{
 100000
};
#line 1 "d:/clicks_git/i/irgrid_3_click/sw/library/__irgrid3_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic32/include/stdint.h"
#line 62 "d:/clicks_git/i/irgrid_3_click/sw/library/__irgrid3_driver.h"
typedef struct
{
 int16_t kVdd;
 int16_t vdd25;
 float KvPTAT;
 float KtPTAT;
 uint16_t vPTAT25;
 float alphaPTAT;
 int16_t gainEE;
 float tgc;
 float cpKv;
 float cpKta;
 uint8_t resolutionEE;
 uint8_t calibrationModeEE;
 float KsTa;
 float ksTo[4];
 int16_t ct[4];
 float alpha[768];
 int16_t offset[768];
 float kta[768];
 float kv[768];
 float cpAlpha[2];
 int16_t cpOffset[2];
 float ilChessC[3];
 uint16_t brokenPixels[5];
 uint16_t outlierPixels[5];
} paramsMLX90640;
#line 101 "d:/clicks_git/i/irgrid_3_click/sw/library/__irgrid3_driver.h"
void irgrid3_i2cDriverInit( const uint8_t*  gpioObj,  const uint8_t*  i2cObj, uint8_t slave);
#line 108 "d:/clicks_git/i/irgrid_3_click/sw/library/__irgrid3_driver.h"
void irgrid3_gpioDriverInit( const uint8_t*  gpioObj);
#line 118 "d:/clicks_git/i/irgrid_3_click/sw/library/__irgrid3_driver.h"
void irgrid3_writeByte(uint16_t reg, uint16_t _data);
#line 126 "d:/clicks_git/i/irgrid_3_click/sw/library/__irgrid3_driver.h"
uint16_t irgrid3_readByte(uint16_t reg);
#line 135 "d:/clicks_git/i/irgrid_3_click/sw/library/__irgrid3_driver.h"
void irgrid3_readData(uint16_t startAddr, uint16_t nBytes, uint16_t *dataOUT);
#line 143 "d:/clicks_git/i/irgrid_3_click/sw/library/__irgrid3_driver.h"
void irgrid3_getPixelTemperature(float *Ta, float *pixelTemp);
#line 148 "d:/clicks_git/i/irgrid_3_click/sw/library/__irgrid3_driver.h"
void irgrid3_deviceConfiguration();
#line 155 "d:/clicks_git/i/irgrid_3_click/sw/library/__irgrid3_driver.h"
void irgrid3_readEEPROM(uint16_t *eeData);
#line 162 "d:/clicks_git/i/irgrid_3_click/sw/library/__irgrid3_driver.h"
int irgrid3_ExtractParameters(uint16_t *eeData, paramsMLX90640 *mlx90640);
#line 169 "d:/clicks_git/i/irgrid_3_click/sw/library/__irgrid3_driver.h"
int irgrid3_getFrameData(uint16_t *frameData);
#line 176 "d:/clicks_git/i/irgrid_3_click/sw/library/__irgrid3_driver.h"
void irgrid3_setResolution(uint8_t resolution);
#line 183 "d:/clicks_git/i/irgrid_3_click/sw/library/__irgrid3_driver.h"
int irgrid3_getCurResolution();
#line 190 "d:/clicks_git/i/irgrid_3_click/sw/library/__irgrid3_driver.h"
void irgrid3_setRefreshRate(uint8_t refreshRate);
#line 197 "d:/clicks_git/i/irgrid_3_click/sw/library/__irgrid3_driver.h"
int irgrid3_getRefreshRate();
#line 202 "d:/clicks_git/i/irgrid_3_click/sw/library/__irgrid3_driver.h"
void irgrid3_setInterleavedMode();
#line 207 "d:/clicks_git/i/irgrid_3_click/sw/library/__irgrid3_driver.h"
void irgrid3_setChessMode();
#line 214 "d:/clicks_git/i/irgrid_3_click/sw/library/__irgrid3_driver.h"
int irgrid3_getCurMode();
#line 225 "d:/clicks_git/i/irgrid_3_click/sw/library/__irgrid3_driver.h"
float irgrid3_GetTa(uint16_t *frameData, paramsMLX90640 *params);
#line 236 "d:/clicks_git/i/irgrid_3_click/sw/library/__irgrid3_driver.h"
void irgrid3_CalculateTo(uint16_t *frameData, paramsMLX90640 *params, float emissivity, float tr, float *result);
#line 245 "d:/clicks_git/i/irgrid_3_click/sw/library/__irgrid3_driver.h"
void irgrid_getImage(uint16_t *frameData, paramsMLX90640 *params, float *result);
#line 254 "d:/clicks_git/i/irgrid_3_click/sw/library/__irgrid3_driver.h"
int irgrid3_GetSubPageNumber(uint16_t *frameData);
#line 262 "d:/clicks_git/i/irgrid_3_click/sw/library/__irgrid3_driver.h"
float irgrid3_GetVdd(uint16_t *frameData, paramsMLX90640 *params);
#line 33 "D:/Clicks_git/I/IRGrid_3_Click/SW/example/c/PIC32/Click_IRGrid3_PIC32.c"
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
 irgrid3_i2cDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_I2C, 0x33 );
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
