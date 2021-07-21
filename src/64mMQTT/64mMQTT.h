#ifndef MQTT64M_H
#define MQTT64M_H

#define MQTT_PROTOCAL_LENGTH	6
#define MQTT_VERSION		3
#define MQTT_CLIENT_ID_LENGTH	13


void MQTT_connect(void);
uint16_t swapHLbyte(uint16_t n);

typedef uint8_t MQTT_PACKET_SIZE;
typedef uint16_t MQTT_MSG_ID;

typedef struct mqtt_conn_packet
{
	uint8_t		mqtt_header;
	uint8_t 	msg_length;
	int16_t 	prt_length;
	uint8_t		prt_name[MQTT_PROTOCAL_LENGTH];
	uint8_t		mqtt_version;
	uint8_t		connect_flags;
	int16_t		keep_alive;
	int16_t		client_id_length;
	uint8_t		client_id[MQTT_CLIENT_ID_LENGTH];
	
}MQTT_CONN_PACKET;

typedef struct mqtt_sub_packet
{
	uint8_t		mqtt_header;
	uint8_t 	msg_length;
	int16_t 	msd_id;
	int16_t 	topic_length;
	uint8_t 	topic_name[];
	
}MQTT_SUB_PACKET;



MQTT_MSG_ID = 0x0010;

#endif