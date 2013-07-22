//!
//! @file 		Sauron-Port.cpp
//! @author 	Geoffrey Hunter <gbmhunter@gmail.com> 
//! @date 		2012/03/19
//! @brief 		Contains port-specific skeleton functions.
//! @details
//!				See README.rst in root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//========================================= INCLUDES ============================================//
//===============================================================================================//

// System includes
#include <stdio.h>		// snprintf()

// User includes
#include "./include/Sauron-Port.h"

#if(CY_PSOC5)
	#include "./Comms/include/UartDebug.h"
	#include "./Comms/include/UartComms.h"
#endif

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace Sauron
{

	//===============================================================================================//
	//===================================== PUBLIC FUNCTIONS ========================================//
	//===============================================================================================//

	void Port::DebugPrint(const char* msg) 
	{
		#ifdef __linux__
			printf("%s", msg);
		#elif(CY_PSOC5)
			UartDebugNs::UartDebug::PutString(msg);
		#else
			#warning No debug output defined
		#endif
	}
	
	void Port::SetGpio()
	{
		#ifdef __linux__
			// Nothing
		#elif(CY_PSOC5)
			PinCpDebugLed2_Write(0);
		#else
			#warning No GPIO output defined
		#endif 
	}
	
	void Port::ClearGpio()
	{
		#ifdef __linux__
			// Nothing
		#elif(CY_PSOC5)
			PinCpDebugLed2_Write(1);
		#else
			#warning No GPIO output defined
		#endif 
	}

	//===============================================================================================//
	//==================================== PRIVATE FUNCTIONS ========================================//
	//===============================================================================================//

	// none

} // namespace Sauron