#ifndef MAIN_SETTING_H
#define MAIN_SETTING_H

#define		USING_LOCAL		1

#define		TCP_CONNID_TD		1
#define		TCP_CONNID_FD		2
#define		SRC_CLIENT_IP		0,0,0,0			//This define seems unused

#if USING_LOCAL == 1
	#define		TAR_SERVER_IP		10,0,0,178
	#define		TAR_SERVER_PT		1883
#else
	#define		TAR_SERVER_IP		45,77,22,98
	#define		TAR_SERVER_PT		80
#endif


//MODE_ENABLE | MODE_DISABLE
//Functions
#define		ENABLE_ETHERNET			(MODE_ENABLE)
#define		ENABLE_DHCP			(MODE_ENABLE)


//Mode
#define		FLUSH_BUF_AFTER_SENDING		(MODE_ENABLE)
#define		PRINT_DEBUGGING_MESSAGE		(MODE_ENABLE)

#endif