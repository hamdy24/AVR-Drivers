#ifndef SWITCH_INT_H_
#define SWITCH_INT_H_

#include"../../LIBRARIES/stdTypes.h"
#include "Switch_config.h"

ES_T Switch_enuInt(SW_T * Copy_pAstrSwitchConfig);

ES_T Switch_enuGetState( SW_T * Copy_pstrSwitchInfo , u8 * Copy_pu8Value);



#endif /* SWITCH_INT_H_ */
