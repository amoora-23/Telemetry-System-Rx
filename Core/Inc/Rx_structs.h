/*
 * Tx_structs.h
 *
 *  Created on: Sep 9, 2026
 *      Author: amira
 */

#ifndef INC_TX_STRUCTS_H_
#define INC_TX_STRUCTS_H_

#include <stdint.h>

typedef struct{
	uint8_t ID: 2;
	uint8_t deadmanSwitch: 1;
	uint8_t packetNumber: 5;

}header;

typedef struct{
	header header;
	uint32_t timeStamp;
	uint16_t wheelSpeed;
	uint32_t lat;
	uint32_t log;
	uint8_t pitch;
	uint16_t yawRate;
}kinematics;

typedef struct{
	header header;
	uint16_t motorCurrent;
	uint16_t motorVoltage;
	uint16_t batteryCurrent;
	uint16_t batteryVoltage;
}powertrain;

typedef struct{
	header header;
	uint8_t probe1;
	uint8_t probe2;
	uint8_t probe3;
	uint8_t probe4;
	uint8_t probe5;
	uint8_t probe6;
}thermal;

#endif /* INC_TX_STRUCTS_H_ */
