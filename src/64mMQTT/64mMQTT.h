#ifndef MQTT64M_H
#define MQTT64M_H

#define MQTT_PROTOCAL_LENGTH	6
#define MQTT_VERSION		3
#define MQTT_CLIENT_ID_LENGTH	13
#define MQTT_TOPIC_LENGTH	8


void MQTT_connect(uint8_t tcp_id);
void MQTT_subscribe(uint8_t tcp_id);
void MQTT_publish(uint8_t tcp_id);
void MQTT_terminate(uint8_t tcp_id);

uint16_t swapHLbyte(uint16_t n);
void write2array(uint8_t *target, uint8_t *source, uint8_t length);

typedef uint8_t MQTT_PACKET_SIZE;
typedef uint16_t MQTT_MSG_ID;

//Connect Request
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

//Subscribe
typedef struct mqtt_sub_packet
{
	uint8_t		mqtt_header;
	uint8_t 	msg_length;
	uint16_t 	msd_id;
	uint16_t 	topic_length;
	uint8_t 	topic_name[MQTT_TOPIC_LENGTH];
	uint8_t		req_qos;
}MQTT_SUB_PACKET;

//Publish
typedef struct mqtt_pub_packet
{
	uint8_t		mqtt_header;
	uint8_t 	msg_length;
	uint16_t 	topic_length;
	uint8_t 	topic_name[MQTT_TOPIC_LENGTH];
	uint8_t 	message[10];
}MQTT_PUB_PACKET;

//Terminate
typedef struct mqtt_term_packet
{
	uint8_t		mqtt_header;
	uint8_t 	msg_length;
}MQTT_TERM_PACKET;




#endif