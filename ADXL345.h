/*********************************************************************************
   Original author: Alexandr Pochtovy<alex.mail.prime@gmail.com>

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

 * 	ADXL345.h
 * 	Created on: 31.01.2022
 */

#ifndef ADXL345_H_
#define ADXL345_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "I2C/MyI2C.h"
#include "ADXL345_Register.h"

enum ADXL345_ADDRESS {
	ADXL345_ADDR = 0xA6//Assumes ALT address pin low
};

#define ADXL345_DATA_LENGHT  6

typedef struct ADXL345_RAW {
	int16_t X;
	int16_t Y;
	int16_t Z;
} ADXL345_RAW_t;

typedef struct ADXL345_data {
	float X;
	float Y;
	float Z;
} ADXL345_data_t;

//common data struct for sensor
typedef struct ADXL345 {
	const uint8_t addr;
	uint8_t step;
	Device_status_t status;
	ADXL345_RAW_t raw;
	ADXL345_data_t data;
} ADXL345_t;

uint8_t ADXL345_Init(I2C_Connection *_i2c, ADXL345_t *dev);
uint8_t ADXL345_GetData(I2C_Connection *_i2c, ADXL345_t *dev);
float ADXL345_ConvertData (int16_t raw);

#ifdef __cplusplus
}
#endif
#endif /* ADXL345_H_ */
