//!
//! @file 		Sauron-Tester.hpp
//! @author 	Geoffrey Hunter <gbmhunter@gmail.com> 
//! @date 		2013/03/19
//! @brief 		
//! @details
//!				See README.rst in root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef SAURON_TESTER_H
#define SAURON_TESTER_H

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

#include <stdint.h>

#include "Sauron-Config.h"

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace Sauron
{
	class Tester
	{	
		
		public:
		
			typedef enum
			{
				SET_HIGH,
				SET_LOW,
				TOGGLE
			} gpioMode_t;
			
			typedef enum
			{
				LOW,
				HIGH
			} gpioState_t;
			
			//===============================================================================================//
			//==================================== CONSTRUCTORS/DESTRUCTOR ==================================//
			//===============================================================================================//
			
			//! @brief		Constructor
			Tester();
				
			//! @brief		Destructor.
			~Tester();
			
			//===============================================================================================//
			//=================================== PUBLIC METHOD DECLARATIONS ================================//
			//===============================================================================================//
			
			template<typename var_t>
			static bool LessThan(double val, double limit);
		
			template<typename var_t>
			static bool LessThanOrEqual(var_t val, var_t limit);
			
			//===============================================================================================//
			//======================================= PUBLIC VARIABLES ======================================//
			//===============================================================================================//
		
			//! @brief		Counts the total number of errors.
			static uint32_t errorCnt;
		
			//! @brief		Set to true to print errors.
			//! @details	If doing error checking within time-critical code,
			//!				this could slow down execution time by too much.
			static bool printError;
			
			//! @brief		Set to true to use the GPIO when an error is detected.
			static bool useGpio;
			
			//! @brief		Determines how the GPIO is controller. Only applicable if
			//!				useGpio is true.
			static gpioMode_t gpioMode;
			
			static gpioState_t gpioState;
			
		private:
		
			static char debugBuff[Sauron_Config_DEBUG_BUFF_SIZE];
		
			// none
	};

	//===============================================================================================//
	//================================= PUBLIC TEMPLATE METHOD DEFINITIONS ==========================//
	//===============================================================================================//
	
	template<typename var_t>
	bool Tester::LessThan(var_t val, var_t limit)
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
					(double)val,
					(double)limit);
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
	
	template<typename var_t>
	bool Tester::LessThanOrEqual(var_t val, var_t limit)
	{
		if(val <= limit)
			return true;
		else
		{
			if(printError)
			{
				snprintf(
					debugBuff,
					sizeof(debugBuff),
					"SAURON: Less-than or equal-to test failed. '%f' was expected to be less-than or equal-to '%f'.\r\n",
					(double)val,
					(double)limit);
				Port::DebugPrint(debugBuff);
			}
			if(useGpio)
				DoGpio();
				
			return false;
		}
	}
	
} // namespace Sauron

#endif	// #ifndef SAURON_TESTER_H

// EOF
