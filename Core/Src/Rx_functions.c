/*
 * Rx_functions.c
 *
 *  Created on: Sep 9, 2026
 *      Author: amira
 */
#include "Rx_functions.h"

header deserialize_header(const uint8_t buf){
	header hdr;
	hdr.ID = (buf >> 6)& 0x03;
	hdr.deadmanSwitch = (buf >> 5) & 0x01;
	hdr.packetNumber = buf & 0x1F;
	return hdr;
}

kinematics deserialize_kinematics(const uint8_t *buf) {
    kinematics pkt;
    uint8_t i = 0;

    // header: unpack the single byte back into ID (2 bits) and deadmanSwitch (1 bit)
    //uint8_t header_byte = buf[i++];
    //pkt.header.ID            = (header_byte >> 1) & 0x03;
    //pkt.header.deadmanSwitch =  header_byte        & 0x01;

    pkt.header = deserialize_header(buf[i++]);

    // wheelSpeed (uint16_t), big-endian: MSB was written first
    pkt.wheelSpeed  = ((uint16_t)buf[i]   << 8) | (uint16_t)buf[i+1];
    i += 2;

    // lat (uint32_t), big-endian
    pkt.lat = ((uint32_t)buf[i]   << 24) |
              ((uint32_t)buf[i+1] << 16) |
              ((uint32_t)buf[i+2] << 8 ) |
              ((uint32_t)buf[i+3]      );
    i += 4;

    // log (uint32_t), big-endian
    pkt.log = ((uint32_t)buf[i]   << 24) |
              ((uint32_t)buf[i+1] << 16) |
              ((uint32_t)buf[i+2] << 8 ) |
              ((uint32_t)buf[i+3]      );
    i += 4;

    // pitch (uint8_t) - single byte, no shifting needed
    pkt.pitch = buf[i++];

    // yawRate (uint16_t), big-endian
    pkt.yawRate = ((uint16_t)buf[i] << 8) | (uint16_t)buf[i+1];
    i += 2;

    return pkt;
}

powertrain deserialize_powertrain(const uint8_t *buf) {
    powertrain pkt;
    uint8_t i = 0;

    // header: unpack the single byte back into ID (2 bits) and deadmanSwitch (1 bit)
//    uint8_t header_byte = buf[i++];
//    pkt.header.ID            = (header_byte >> 1) & 0x03;
//    pkt.header.deadmanSwitch =  header_byte        & 0x01;
    pkt.header = deserialize_header(buf[i++]);


    // motorCurrent (uint16_t), big-endian
    pkt.motorCurrent = ((uint16_t)buf[i] << 8) | (uint16_t)buf[i+1];
    i += 2;

    // motorVoltage (uint16_t), big-endian
    pkt.motorVoltage = ((uint16_t)buf[i] << 8) | (uint16_t)buf[i+1];
    i += 2;

    // batteryCurrent (uint16_t), big-endian
    pkt.batteryCurrent = ((uint16_t)buf[i] << 8) | (uint16_t)buf[i+1];
    i += 2;

    // batteryVoltage (uint16_t), big-endian
    pkt.batteryVoltage = ((uint16_t)buf[i] << 8) | (uint16_t)buf[i+1];
    i += 2;

    return pkt;
}

thermal deserialize_thermal(const uint8_t *buf){
	thermal pkt;
	uint8_t i = 0;

	pkt.header =  deserialize_header(&(buf[i++]));
	pkt.probe1 = buf[i++];
	pkt.probe2 = buf[i++];
	pkt.probe3 = buf[i++];
	pkt.probe4 = buf[i++];
	pkt.probe5 = buf[i++];
	pkt.probe6 = buf[i++];

	return pkt;


}

