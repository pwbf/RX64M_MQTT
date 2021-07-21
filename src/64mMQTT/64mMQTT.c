#include "platform.h"
#include "globalVar.h"

#include "MainSetting.h"

#include "64mMQTT.h"
#include "64mMQTT_if.h"

void MQTT_connect(void){
	
	MQTT_CONNECT_TYPE mct;
	MQTT_CONN_PACKET *mp;
	MQTT_PACKET_SIZE s = sizeof(*mp);
	
	mp -> mqtt_header = CONNECT_CMD;
	mp -> msg_length = s - 3;
	mp -> prt_length = swapHLbyte(0x06);
	mp -> prt_name[0] = 'M';
	mp -> prt_name[1] = 'Q';
	mp -> prt_name[2] = 'I';
	mp -> prt_name[3] = 's';
	mp -> prt_name[4] = 'd';
	mp -> prt_name[5] = 'p';
	mp -> mqtt_version = 0x03;
	mp -> connect_flags = 0x02;
	mp -> keep_alive = swapHLbyte(0x78);
	mp -> client_id_length = swapHLbyte(0x0d);
	mp -> client_id[0] = 'T';
	mp -> client_id[1] = 'H';
	mp -> client_id[2] = 'U';
	mp -> client_id[3] = '_';
	mp -> client_id[4] = 'R';
	mp -> client_id[5] = 'X';
	mp -> client_id[6] = '6';
	mp -> client_id[7] = '4';
	mp -> client_id[8] = 'M';
	mp -> client_id[9] = '_';
	mp -> client_id[10] = 'I';
	mp -> client_id[11] = 'O';
	mp -> client_id[12] = 'T';
	
	TCP_SendingData(TCP_CONNID_TD, mp, s);
	R_BSP_SoftwareDelay (100, BSP_DELAY_MILLISECS);
}

uint16_t swapHLbyte(uint16_t n){
    uint8_t hibyte = (n & 0xff00) >> 8;
    uint8_t lobyte = (n & 0xff);
    
    return lobyte << 8 | hibyte;
}