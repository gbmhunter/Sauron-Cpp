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

// System
#include <stdio.h>

// User includes
#include "./include/Sauron-Config.hpp"

#if(Sauron_Config_ENABLE_FREERTOS_METRICS == 1)

#include "./include/Sauron-Port.hpp"
#include "./include/Sauron-FreeRtosMetrics.hpp"

#include "FreeRTOS/Source/include/FreeRTOS.h"
#include "FreeRTOS/Source/include/task.h"

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace Sauron
{
	
	char FreeRtosMetrics::taskMetricsStringBuff[250] = {0};
	char FreeRtosMetrics::freeHeapSpaceString[150] = {0};

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
			sizeof(freeHeapSpaceString),
			"\r\nTick = %" STR(SauronPort_PF_UINT32_T) "\r\nFree Heap Space = %" STR(SauronPort_PF_UINT32_T) "bytes of %" STR(SauronPort_PF_UINT32_T) " allocated.\r\n\r\n",
			(uint32_t)xTaskGetTickCount(),
			(uint32_t)xPortGetFreeHeapSize(),
			(uint32_t)configTOTAL_HEAP_SIZE);
		
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
