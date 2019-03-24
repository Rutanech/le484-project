#include "ctrler.h"
#include "bsp.h"

Ctrler_State_t Ctrler_State = RESTART;

void Ctrler_Init()
{
}

uint32_t Ctrler_Exec(Event_t evt)
{
    uint32_t timeout_value = 0;
    
    switch(Ctrler_State) {
        case RESTART:
					if (evt == TIMEOUT){
					Signal_Pass();
					}
				if (evt == BUTTON){
						Ctrler_State = WAIT;
					timeout_value = 50;
						}
	           break;
				case WAIT:
				if (evt == TIMEOUT){	
				Signal_Flash();
				Ctrler_State = BLOCKED;
				timeout_value = 20;
				}
				break;
				case BLOCKED:
				if (evt == TIMEOUT){
					Signal_Block();
					Ctrler_State = RESTART;
					timeout_value = 20;
				}					
				break;
        default:
            Ctrler_State = OUT_OF_SERVICE;
				Signal_Pass();
    }
    return timeout_value;
}
