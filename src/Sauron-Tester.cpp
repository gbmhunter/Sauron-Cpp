//!
//! @file 		Sauron-Tester.cpp
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

// User includes
#include "include/Sauron-Config.hpp"
#include "include/Sauron-Tester.hpp"
#include "include/Sauron-Port.hpp"

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
	bool Tester::useAnalogOut = (bool)Sauron_Config_DEF_USE_ANALOG_OUT;
	uint32_t Tester::activeTestSuite = Sauron_Config_DEF_ACTIVE_TEST_SUITE;
	
	char Tester::debugBuff[Sauron_Config_DEBUG_BUFF_SIZE] = {0};

	//===============================================================================================//
	//================================== PUBLIC METHOD DEFINITIONS ==================================//
	//===============================================================================================//

	Tester::Tester()
	{
		
	}
	
	void Tester::DoGpio()
	{
		if(gpioMode == SET_LOW)
		{
			gpioState = LOW;
			Port::ClearGpio();
		}
		else if(gpioMode == SET_HIGH)
		{
			gpioState = HIGH;
			Port::SetGpio();
		}
		if(gpioMode == TOGGLE)
		{
			if(gpioState == LOW)
			{
				gpioState = HIGH;
				Port::SetGpio();
			}
			else // gpioState == HIGH
			{
				gpioState = LOW;
				Port::ClearGpio();
			}
		}
	}
	
	void Tester::DoAnalog(double voltagemV)
	{
		 Port::SetAnalogOut(voltagemV);
	}
	
	//===============================================================================================//
	//================================== PRIVATE METHOD DEFINITIONS =================================//
	//===============================================================================================//

	// none

} // namespace Sauron