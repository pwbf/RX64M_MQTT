#include "platform.h"
#include "globalVar.h"

#include "MainSetting.h"

#include "64mMQTT.h"
#include "64mMQTT_if.h"

uint16_t MSG_IDENTIFIER = 0x0010;

	MQTT_CONNECT_TYPE mct;
	MQTT_QOS_TYPE mqos;
	
	MQTT_CONN_PACKET *mcp;
	MQTT_SUB_PACKET *msp;
	MQTT_PUB_PACKET *mpp;
	MQTT_TERM_PACKET *mtp;
	
	//one nest +1 byte
	MQTT_PACKET_SIZE smcp = sizeof(*mcp) - 1;
	MQTT_PACKET_SIZE smsp = sizeof(*msp) - 1;
	MQTT_PACKET_SIZE smpp = sizeof(*mpp) - 0;
	MQTT_PACKET_SIZE smtp = sizeof(*mtp);
	
void MQTT_connect(uint8_t tcp_id){
	
	mcp -> mqtt_header = CONNECT_CMD;
	mcp -> msg_length = smcp - 2;
	mcp -> prt_length = swapHLbyte(0x06);
	write2array(&(mcp -> prt_name), &Protocal_Name, MQTT_PROTOCAL_LENGTH);
	mcp -> mqtt_version = 0x03;
	mcp -> connect_flags = 0x02;
	mcp -> keep_alive = swapHLbyte(0x78);
	mcp -> client_id_length = swapHLbyte(0x0d);
	write2array(&(mcp -> client_id), &Client_Name, MQTT_CLIENT_ID_LENGTH);
	
	TCP_SendingData(tcp_id, mcp, smcp);
	R_BSP_SoftwareDelay (100, BSP_DELAY_MILLISECS);
}

void MQTT_subscribe(uint8_t tcp_id){
	
	msp -> mqtt_header = SUBSCRIBE_CMD;
	msp -> msg_length = smsp - 2;
	msp -> msd_id = swapHLbyte(MSG_IDENTIFIER++);
	msp -> topic_length = swapHLbyte(MQTT_TOPIC_LENGTH);
	write2array(&(msp -> topic_name), &Topic_THU_TEST, MQTT_TOPIC_LENGTH);
	msp -> req_qos = AT_MOST_ONCE;
	
	TCP_SendingData(tcp_id, msp, smsp);
	R_BSP_SoftwareDelay (100, BSP_DELAY_MILLISECS);
}

void MQTT_publish(uint8_t tcp_id){
	
	mpp -> mqtt_header = PUBLISH_AT_MOST_ONCE;
	mpp -> msg_length = smpp - 2;
	mpp -> topic_length = swapHLbyte(MQTT_TOPIC_LENGTH);
	write2array(&(mpp -> topic_name), &Topic_THU_TEST, MQTT_TOPIC_LENGTH);
	write2array(&(mpp -> message), &TestMessage, 10);
	
	TCP_SendingData(tcp_id, mpp, smpp);
	R_BSP_SoftwareDelay (100, BSP_DELAY_MILLISECS);
}

void MQTT_terminate(uint8_t tcp_id){
	
	mtp -> mqtt_header = DISCONNECT_CMD;
	mtp -> msg_length = 0;
	
	TCP_SendingData(tcp_id, mtp, smtp);
	R_BSP_SoftwareDelay (100, BSP_DELAY_MILLISECS);
	TCP_Terminate(tcp_id);
	R_BSP_SoftwareDelay (100, BSP_DELAY_MILLISECS);
}

uint16_t swapHLbyte(uint16_t n){
    uint8_t hibyte = (n & 0xff00) >> 8;
    uint8_t lobyte = (n & 0xff);
    
    return lobyte << 8 | hibyte;
}

void write2array(uint8_t *target, uint8_t *source, uint8_t length){
    for(uint8_t index = 0; index < length; index++)
    	*(target + index) = *(source + index);
}