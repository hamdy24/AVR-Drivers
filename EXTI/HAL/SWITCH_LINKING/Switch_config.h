#ifndef SWITCH_CONFIG_H_
#define SWITCH_CONFIG_H_

#include"../../LIBRARIES/stdTypes.h"

#define SW_NUM		3


typedef struct
{
	u8 SW_Port;
	u8 SW_Pin;
	u8 SW_State;
}SW_T;

#endif /* SWITCH_CONFIG_H_ */
