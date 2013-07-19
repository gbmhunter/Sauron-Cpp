//!
//! @file 		Sauron-Tester.h
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
			//========================================= PUBLIC METHODS ======================================//
			//===============================================================================================//
			
			static bool LessThan(double val, double limit);
		
			
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


} // namespace Sauron

#endif	// #ifndef CLIDE_CMD_H

// EOF
