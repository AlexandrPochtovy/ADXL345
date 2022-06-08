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
#include "I2C_Master/MyI2C.h"
#include "ADXL345_Register.h"

/* состояние процесса обмена данными с устройством как с отдельным элементом сети
 * 	применяется для отображения состояния процесса работы с устройством для главного кода
 */
typedef enum ADXL345_status_t {//состояние устройства
	ADXL_Init,		//устройство не настроено
	ADXL_OK,		//устройство готово к опросу
	ADXL_Faulth	//устройство неисправно
} ADXL345_status;

/*	состояние обмена данными с устройством, использовать для завершения функции работы с устройством */
typedef enum ADXL345_Connect_Status_t {
	ADXL_Processing, //выполняется работа с устройством: обмен данными, обработка результатов
	ADXL_Complite	//работа с устройством завершена, данные считаны/записаны корректно
} ADXL_Connect_Status;

typedef struct ADXL345_RAW_t {
	int16_t X;
	int16_t Y;
	int16_t Z;
} ADXL345_RAW;

typedef struct ADXL345_data_t {
	float X;
	float Y;
	float Z;
} ADXL345_data;

//common data struct for sensor
typedef struct ADXL345_dev_t {
	uint8_t addr;
	uint8_t step;
	ADXL345_status status;
	ADXL345_RAW raw;
	ADXL345_data data;
} ADXL345_dev;

ADXL_Connect_Status ADXL345_Init(I2C_Connection *_i2c, ADXL345_dev *dev, uint8_t *pbuffer);
ADXL_Connect_Status ADXL345_GetData(I2C_Connection *_i2c, ADXL345_dev *dev, uint8_t *pbuffer);
float ADXL345_ConvertData (int16_t raw);

#ifdef __cplusplus
}
#endif
#endif /* ADXL345_H_ */
