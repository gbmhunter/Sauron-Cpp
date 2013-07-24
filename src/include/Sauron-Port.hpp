//!
//! @file 		Sauron-Port.hpp
//! @author 	Geoffrey Hunter <gbmhunter@gmail.com> 
//! @date 		2013/03/19
//! @brief 		Contains port-specific skeleton functions.
//! @details
//!				See README.rst in root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef SAURON_PORT_H
#define SAURON_PORT_H

#if(CY_PSOC5)
	extern "C" {
		// PSoC
		#include <device.h>
	}
#endif // #if(CY_PSOC5)

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace Sauron
{

	//===============================================================================================//
	//==================================== PUBLIC DEFINES ===========================================//
	//===============================================================================================//

	#define STR_EXPAND(tok) #tok
	#define STR(tok) STR_EXPAND(tok)
	
	#if(defined __linux__)
		#define SauronPort_PF_UINT32_T		u
		#define SauronPort_PF_INT32_T		i
		#define SauronPort_PF_CHAR_T		c
	#elif(CY_PSOC5)
		#define SauronPort_PF_UINT32_T		lu
		#define SauronPort_PF_INT32_T		li
		#define SauronPort_PF_CHAR_T		li
	#else
		#warning No platform defined. Using defaults.
		#define SauronPort_PF_UINT32_T		u
		#define SauronPort_PF_INT32_T		i
		#define SauronPort_PF_CHAR_T		c
	#endif
		
	//===============================================================================================//
	//=================================== PUBLIC TYPEDEFS ===========================================//
	//===============================================================================================//

	// none

	//===============================================================================================//
	//================================== PUBLIC VARIABLES/STRUCTURES ================================//
	//===============================================================================================//

	// none

	//===============================================================================================//
	//=================================== PUBLIC FUNCTION PROTOTYPES ================================//
	//===============================================================================================//

	//! @brief		Contains all the port-specific functions
	class Port
	{

		public:
		
			//===============================================================================================//
			//==================================== CONSTRUCTORS/DESTRUCTOR ==================================//
			//===============================================================================================//
			
			// none
		
			//! @brief		Prints debug messages. Port specific.
			//! @public
			static void DebugPrint(const char* msg);

			//! @brief		Prints messages to the command-line.
			static void CmdLinePrint(const char* msg);
			
			static void SetGpio();
			
			static void ClearGpio();
			
			//! @brief		Sets an analogue output to a certain voltage.
			//! @note		Port-specific.
			static void SetAnalogOut(double voltage);
	};

} // namespace SAURON

#endif	// #ifndef SAURON_PORT_H

// EOF
