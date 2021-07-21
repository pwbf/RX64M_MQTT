#ifndef MQTT64M_IF_H
#define MQTT64M_IF_H



typedef enum {
	CONNECT_CMD = 0x10,
	SUBSCRIBE_CMD = 0x82,
	PUBLISH_AT_MOST_ONCE = 0x30,
	PUBLISH_AT_LEAST_ONCE = 0x32,
	PUBLISH_EXACTLY_ONCE = 0x34,
	DISCONNECT_CMD = 0xE0
}MQTT_CONNECT_TYPE;


#endif