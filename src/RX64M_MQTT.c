
#include "mainHeader.h""

extern bool ETHERNET_RDY[2];

MQTT_PACKET *mp;

uint8_t s = sizeof(*mp);

void main(void){	/*MAIN FUNCTION START POINT*/
/* WIRESHARK
dhcp && !ip.addr == 10.0.0.178 && dhcp.id == 0x12345678
tcp && tcp.flags.syn && ip.dst == 10.0.0.178 && ip.src == 10.0.0.0/24
*/
	#if PRINT_DEBUGGING_MESSAGE == MODE_ENABLE
		printf("Bootup Process\n");
		printf("==========INIT==========\n");
	#endif
	
	Rx64MInitPorts();
	LEDinit();
	R_r_irq_rx_Create();
	R_r_irq_rx_IRQ7_Start();

#if ENABLE_ETHERNET == MODE_ENABLE
	#if PRINT_DEBUGGING_MESSAGE == MODE_ENABLE
		printf("-- INIT: [Enabled] Ethernet\n");
		printf("-- INIT: Ethernet Link Process\n");
	#endif
	
	
	EthernetInit(ENABLE_DHCP);
	while(!ETHERNET_RDY[0]){
		#if PRINT_DEBUGGING_MESSAGE == MODE_ENABLE
			printf("        Waiting for Plug in signal...\n");
		#endif
		R_ETHER_LinkProcess(0);
		R_BSP_SoftwareDelay (500, BSP_DELAY_MILLISECS);
	}
#else
	#if PRINT_DEBUGGING_MESSAGE == MODE_ENABLE
		printf("-- INIT: [Disabled] Ethernet\n");
	#endif
#endif
	
	ServerConnect();
	
	#if PRINT_DEBUGGING_MESSAGE == MODE_ENABLE
		printf("========================\n");
		printf("BOOTED\n");
	#endif
	
	mp -> mqtt_header = 0x10;
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
	
/*MAIN WHILE LOOP START POINT*/	
    while(1){
	    TCP_SendingData(TCP_CONNID_TD, mp, s);
	    R_BSP_SoftwareDelay (100, BSP_DELAY_MILLISECS);
	    TCP_Terminate(TCP_CONNID_TD);
	    R_BSP_SoftwareDelay (100, BSP_DELAY_MILLISECS);
	break;
    }/*MAIN WHILE LOOP END POINT*/
}/*MAIN FUNCTION END POINT*/

void Rx64MInitPorts(void){
        R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_MPC); // Use BSP function to unlock the MPC register.
	
        return;
}

void ServerConnect(void){
	
#if ENABLE_ETHERNET == MODE_ENABLE
	int8_t tcp_connection_status = TCP_Connect(encodeIPv4(TAR_SERVER_IP), TAR_SERVER_PT, TCP_CONNID_TD);
	while(tcp_connection_status != 0 && tcp_connection_status != -57){
		#if PRINT_DEBUGGING_MESSAGE == MODE_ENABLE
			printf("        Waiting for Server Respond...\n");
		#endif
		R_BSP_SoftwareDelay (200, BSP_DELAY_MILLISECS);
		tcp_connection_status = TCP_Connect(encodeIPv4(TAR_SERVER_IP), TAR_SERVER_PT, TCP_CONNID_TD);
	}
	
	#if PRINT_DEBUGGING_MESSAGE == MODE_ENABLE
		printf("        Connection Established!!\n");
		R_BSP_SoftwareDelay (100, BSP_DELAY_MILLISECS);
	#endif
#endif
}

uint16_t swapHLbyte(uint16_t n){
    uint8_t hibyte = (n & 0xff00) >> 8;
    uint8_t lobyte = (n & 0xff);
    
    return lobyte << 8 | hibyte;
}