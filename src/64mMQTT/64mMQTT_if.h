#ifndef MQTT64M_IF_H
#define MQTT64M_IF_H

/*
MQTT TOPIC:

LW0_TEMP = xxx.x(C)
LW0_VRMS = xx.x(mg)
LW0_VAVG = xx.x(mg)
LW0_VPK0 = xxx(HZ)
LW0_VPK1 = xxx(HZ)
LW0_VPK2 = xxx(HZ)
LW0_VPK3 = xxx(HZ)
LW0_VPK4 = xxx(HZ)

*/

const uint8_t Protocal_Name[MQTT_PROTOCAL_LENGTH] = {'M', 'Q', 'I', 's', 'd', 'p'};
const uint8_t Client_Name[MQTT_CLIENT_ID_LENGTH] = {'T', 'H', 'U', '_', 'R', 'X', '6', '4', 'M', '_', 'I', 'O', 'T'};

const uint8_t Topic_LW0_TEMP[MQTT_TOPIC_LENGTH] = {'L', 'W', '0', '_', 'T', 'E', 'M', 'P'};
const uint8_t Topic_LW0_VRMS[MQTT_TOPIC_LENGTH] = {'L', 'W', '0', '_', 'T', 'E', 'M', 'P'};
const uint8_t Topic_LW0_VAVG[MQTT_TOPIC_LENGTH] = {'L', 'W', '0', '_', 'T', 'E', 'M', 'P'};
const uint8_t Topic_LW0_VPK0[MQTT_TOPIC_LENGTH] = {'L', 'W', '0', '_', 'V', 'P', 'K', '0'};
const uint8_t Topic_LW0_VPK1[MQTT_TOPIC_LENGTH] = {'L', 'W', '0', '_', 'V', 'P', 'K', '1'};
const uint8_t Topic_LW0_VPK2[MQTT_TOPIC_LENGTH] = {'L', 'W', '0', '_', 'V', 'P', 'K', '2'};
const uint8_t Topic_LW0_VPK3[MQTT_TOPIC_LENGTH] = {'L', 'W', '0', '_', 'V', 'P', 'K', '3'};
const uint8_t Topic_LW0_VPK4[MQTT_TOPIC_LENGTH] = {'L', 'W', '0', '_', 'V', 'P', 'K', '4'};
const uint8_t Topic_THU_TEST[MQTT_TOPIC_LENGTH] = {'T', 'H', 'U', '_', 'T', 'E', 'S', 'T'};

//const uint8_t TestMessage[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
const uint8_t TestMessage[10] = {'K', 'O', 'R', 'E', 'A', 'N', 'S', 'U', 'C', 'K'};

typedef enum {
	CONNECT_CMD = 0x10,
	SUBSCRIBE_CMD = 0x82,
	PUBLISH_AT_MOST_ONCE = 0x30,
	PUBLISH_AT_LEAST_ONCE = 0x32,
	PUBLISH_EXACTLY_ONCE = 0x34,
	DISCONNECT_CMD = 0xE0
}MQTT_CONNECT_TYPE;

typedef enum {
	AT_MOST_ONCE,
	AT_LEAST_ONCE,
	EXACTLY_ONCE,
}MQTT_QOS_TYPE;


#endif