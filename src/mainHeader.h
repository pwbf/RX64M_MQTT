#ifndef MAINHEADER_H
#define MAINHEADER_H

/*
//	You should NOT modify definetion below!!
//	All customizable settings are in MainSetting.h
//	--by PWBF 2021.3.22
*/

#include "typedefine.h"
#include "iodefine.h"
#include "platform.h"
#include "globalVar.h"


/*For LED*/
#include "LEDprocess.h"

/*For Ethernet Process*/
#include "EthernetProcess.h"

/*For MQTT*/
#include "64mMQTT.h"

/*For Mode or Function Switching*/
#include "MainSetting.h"

/*For HW interrupt*/
#include "r_irq_rx.h"

void Rx64MInitPorts(void);
void ServerConnect(void);

#endif