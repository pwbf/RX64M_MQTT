
#include "mainHeader.h""

extern bool ETHERNET_RDY[2];



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
	

	
/*MAIN WHILE LOOP START POINT*/	
    while(1){
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

