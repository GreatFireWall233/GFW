/* 

	DHT22 temperature sensor driver

*/

#ifndef MQ2_H_
#define MQ2_H_

#include <stdint.h>
#define DHT_OK 0
#define DHT_CHECKSUM_ERROR -1
#define DHT_TIMEOUT_ERROR -2

#define NO_OF_SAMPLES 64

void initMQ2();
uint32_t readMQ2RowData();

#endif