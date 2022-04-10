#ifndef SWITCH_INT_H_
#define SWITCH_INT_H_

#include"../../LIBRARIES/stdTypes.h"


ES_t Switch_enuInt(SW_t * Copy_pAstrSwitchConfig);

ES_t Switch_enuGetState( SW_t * Copy_pstrSwitchInfo , u8 * Copy_pu8Value);



#endif /* SWITCH_INT_H_ */
