/*
 * Rx_functions.h
 *
 *  Created on: Sep 9, 2026
 *      Author: amira
 */

#ifndef INC_RX_FUNCTIONS_H_
#define INC_RX_FUNCTIONS_H_

#include "Rx_structs.h"
header deserialize_header(const uint8_t buf);
kinematics deserialize_kinematics(const uint8_t *buf);
powertrain deserialize_powertrain(const uint8_t *buf);
thermal deserialize_thermal(const uint8_t *buf);


#endif /* INC_RX_FUNCTIONS_H_ */
