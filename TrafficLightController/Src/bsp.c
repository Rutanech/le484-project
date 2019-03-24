#include "bsp.h"
#include "timer.h"

// exported global variables
volatile int Button_Status = 0;

/** @brief  Initialize I/O for lamps
    @retval None
*/
void BSP_Init(void)
{
}

/** @brief  Change lamps to GREEN
    @retval None
*/
void Signal_Pass(void)
{
    RED_OFF();
	GREEN_ON();
}

/** @brief  Change lamps to RED
    @retval None
*/
void Signal_Block(void)
{
	YELLOW_OFF();
	RED_ON();
}

/** @brief  Flash YELLOW lamp
    @retval None
*/
void Signal_Flash(void)
{
	GREEN_OFF();
  YELLOW_ON();
}
void Signal_Walk(void)
{
	GREEN_OFF();
  YELLOW_ON();
}
