//!
//! @file 		Sauron-Tester.c
//! @author 	Geoffrey Hunter <gbmhunter@gmail.com>
//! @date 		2013/07/18
//! @brief 		
//! @details
//!				See README.rst in root folder for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//========================================= INCLUDES ============================================//
//===============================================================================================//

// System includes
#include <stdint.h>		// int8_t, int32_t e.t.c
#include <stdio.h>		// snprintf()
#include <stdlib.h>		// realloc(), malloc(), free()
#include <cctype>		// isalnum() 
#include <getopt.h>		// getopt()	
#include <string.h>		// strlen()

// User includes
#include "include/Sauron-Config.h"
#include "include/Sauron-Tester.h"
#include "include/Sauron-Port.h"

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace Sauron
{

	uint32_t Tester::errorCnt = 0;
	bool Tester::printError = (bool)Sauron_Config_PRINT_ERROR_DEF;
	bool Tester::useGpio = (bool)Sauron_Config_SET_GPIO_DEF;
	Tester::gpioMode_t Tester::gpioMode = Sauron_Config_DEF_GPIO_MODE;
	Tester::gpioState_t Tester::gpioState = Sauron_Config_DEF_GPIO_STATE;
	
	char Tester::debugBuff[Sauron_Config_DEBUG_BUFF_SIZE] = {0};

	//===============================================================================================//
	//======================================= PUBLIC METHODS ========================================//
	//===============================================================================================//

	Tester::Tester()
	{
		
	}
	
	bool Tester::LessThan(double val, double limit)
	{
		if(val < limit)
			return true;
		else
		{
			if(printError)
			{
				snprintf(
					debugBuff,
					sizeof(debugBuff),
					"SAURON: Less-than test failed. '%f' was expected to be less-than '%f'.\r\n",
					val,
					limit);
				Port::DebugPrint(debugBuff);
			}
			if(useGpio)
			{
				if(gpioMode == SET_HIGH)
					Port::SetGpio();
				else if(gpioMode == SET_LOW)
					Port::ClearGpio();
				else // gpioMode == TOGGLE
				{
					if(gpioState == LOW)
					{
						Port::SetGpio();
						gpioState = HIGH;
					}
					else // gpioState == HIGH
					{
						Port::ClearGpio();
						gpioState = LOW;
					}
				}				
			}
			
			errorCnt++;
			
			return false;
		}
	}

	

	//===============================================================================================//
	//==================================== PRIVATE FUNCTIONS ========================================//
	//===============================================================================================//

	// none

} // namespace Sauron