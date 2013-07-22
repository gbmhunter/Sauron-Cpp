//!
//! @file 		Sauron-FreeRtosMetrics.cpp
//! @author 	Geoffrey Hunter <gbmhunter@gmail.com> 
//! @date 		2012/03/19
//! @brief 		Calls FreeRTOS API that returns performance metrics about the operating system.
//! @details
//!				See README.rst in root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//========================================= INCLUDES ============================================//
//===============================================================================================//

// User includes
#include "./include/Sauron-Config.h"

#if(Sauron_Config_ENABLE_FREERTOS_METRICS == 1)

#include "./include/Sauron-Port.h"

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace Sauron
{
	
	char FreeRtosMetrics::taskMetricsStringBuff[200] = {0};
	char FreeRtosMetrics::freeHeapSpaceString[100] = {0};

	//===============================================================================================//
	//================================ PUBLIC METHOD DECLARATIONS ===================================//
	//===============================================================================================//

	void FreeRtosMetrics::Run()
	{
		// Print performance metrics
		#if(Sauron_Config_DEBUG_PRINT_GENERAL == 1)
			Port::DebugPrint("SAURON: Gathering/printing FreeRTOS metrics...\r\n");
		#endif

		// Get task information
		vTaskList((signed char*)taskMetricsStringBuff);
		
		snprintf(
			freeHeapSpaceString,
			50,
			"\r\nTick = %u\r\nFree Heap Space = %u\r\n\r\n",
			(uint32) xTaskGetTickCount(),
			(uint32) xPortGetFreeHeapSize());
		
		strlcat(taskMetricsStringBuff, freeHeapSpaceString, sizeof(taskMetricsStringBuff));
		// Print task information
		
		Port::DebugPrint(taskMetricsStringBuff);
	}
	
	//===============================================================================================//
	//=============================== PRIVATE METHOD DECLARATIONS ===================================//
	//===============================================================================================//


} // namespace Sauron

#endif // Sauron_Config_ENABLE_FREERTOS_METRICS

// EOF
