//#ifndef 64MMQTT_H
//#define 64MMQTT_H

#define MQTT_PROTOCAL_LENGTH	6
#define MQTT_VERSION		3
#define MQTT_CLIENT_ID_LENGTH	13


typedef struct mqttpacket
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
	
}MQTT_PACKET;

//#endif