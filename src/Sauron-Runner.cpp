//!
//! @file 		Sauron-Runner.cpp
//! @author 	Geoffrey Hunter <gbmhunter@gmail.com> 
//! @date 		2012/03/19
//! @brief 		Contains run function for Sauron to do regular processing.
//! @details
//!				See README.rst in root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//========================================= INCLUDES ============================================//
//===============================================================================================//

// User includes
#include "./include/Sauron-Port.hpp"
#include "./include/Sauron-Runner.hpp"

#if(Sauron_Config_ENABLE_FREERTOS_METRICS == 1)
	#include "./include/Sauron-FreeRtosMetrics.hpp"
#endif

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace Sauron
{

	//===============================================================================================//
	//================================ PUBLIC METHOD DECLARATIONS ===================================//
	//===============================================================================================//

	void Runner::Run()
	{
		#if(Sauron_Config_ENABLE_FREERTOS_METRICS == 1)
			// Print performance metrics
			FreeRtosMetrics::Run();
		#endif
	}
	
	//===============================================================================================//
	//=============================== PRIVATE METHOD DECLARATIONS ===================================//
	//===============================================================================================//

} // namespace Sauron

// EOF
