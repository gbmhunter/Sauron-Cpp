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
#include <stdlib.h>

// User includes
#include "./include/Sauron-Config.hpp"

#if(Sauron_Config_ENABLE_FREERTOS_METRICS == 1)

#include "./include/Sauron-Port.hpp"
#include "./include/Sauron-FreeRtosMetrics.hpp"

#include "FreeRTOS/Source/include/FreeRTOS.h"
#include "FreeRTOSConfig.h"
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
		
		/*
		// Get task information
		vTaskList((signed char*)taskMetricsStringBuff);
		
		snprintf(
			freeHeapSpaceString,
			sizeof(freeHeapSpaceString),
			"\r\nTick = %" STR(SauronPort_PF_UINT32_T) "\r\nFree Heap Space = %" STR(SauronPort_PF_UINT32_T) "bytes (of a total %" STR(SauronPort_PF_UINT32_T) " allocated).\r\n\r\n",
			(uint32_t)xTaskGetTickCount(),
			(uint32_t)xPortGetFreeHeapSize(),
			(uint32_t)configTOTAL_HEAP_SIZE);
		
		strlcat(taskMetricsStringBuff, freeHeapSpaceString, sizeof(taskMetricsStringBuff));
		*/
		
		snprintf(
			freeHeapSpaceString,
			sizeof(freeHeapSpaceString),
			"\r\nTick = %" STR(SauronPort_PF_UINT32_T) "\r\nFree Heap Space = %" STR(SauronPort_PF_UINT32_T) "bytes (of a total %" STR(SauronPort_PF_UINT32_T) " allocated).\r\n\r\n",
			(uint32_t)xTaskGetTickCount(),
			(uint32_t)xPortGetFreeHeapSize(),
			(uint32_t)configTOTAL_HEAP_SIZE);
			
		Port::DebugPrint(freeHeapSpaceString);

		// Get FreeRTOS stats
		GetRtosStats();

	}
	
	//===============================================================================================//
	//=============================== PRIVATE METHOD DECLARATIONS ===================================//
	//===============================================================================================//

	void FreeRtosMetrics::GetRtosStats()
	{
		xTaskStatusType *pxTaskStatusArray;
		
		uint8_t uxArraySize, x;
		uint32_t ulTotalRunTime, ulStatsAsPercentage;

		

		// Take a snapshot of the number of tasks in case it changes while this 
		// function is executing.
		uxArraySize = uxTaskGetNumberOfTasks();

		#if(Sauron_Config_DEBUG_PRINT_VERBOSE == 1)
			snprintf(
				taskMetricsStringBuff,
				sizeof(taskMetricsStringBuff),
				"SAURON: Allocating '%u' bytes for '%u' tasks of info.\r\n",
				uxArraySize * sizeof(xTaskStatusType),
				uxArraySize);
			Port::DebugPrint(taskMetricsStringBuff);
		#endif
		
		// Make sure the write buffer does not contain a string.
		*taskMetricsStringBuff = 0x00;
		
		// Allocate a xTaskStatusType structure for each task.  An array could be
		// allocated statically at compile time.
		pxTaskStatusArray = (xTaskStatusType*)pvPortMalloc(uxArraySize * sizeof(xTaskStatusType));
		
		if(pxTaskStatusArray != NULL)
		{
			#if(Sauron_Config_DEBUG_PRINT_VERBOSE == 1)
				Port::DebugPrint("SAURON: Allocation successful.\r\n");
			#endif
			
			// Generate raw status information about each task.
			//uxArraySize = uxTaskGetSystemState(pxTaskStatusArray, uxArraySize, &ulTotalRunTime);
			uxArraySize = uxTaskGetSystemState(pxTaskStatusArray, uxArraySize, NULL);
			
			#if(Sauron_Config_DEBUG_PRINT_VERBOSE == 1)
				snprintf(
					taskMetricsStringBuff,
					sizeof(taskMetricsStringBuff),
					"SAURON: uxArraySize = '%u'.\r\n",
					uxArraySize);
				Port::DebugPrint(taskMetricsStringBuff);
			#endif
			
			// For percentage calculations.
			ulTotalRunTime /= 100UL;
			
			// Print table title
			snprintf(
				taskMetricsStringBuff,
				sizeof(taskMetricsStringBuff),
				"%s",
				"TASK NAME:\t\tRUN COUNT:\tPERCENT:\r\n");
			
			Port::DebugPrint(taskMetricsStringBuff);
			// Avoid divide by zero errors.

			//if( ulTotalRunTime > 0 )
			//{
				// For each populated position in the pxTaskStatusArray array,
				// format the raw data as human readable ASCII data
				for( x = 0; x < uxArraySize; x++ )
				{
					// What percentage of the total run time has the task used?
					// This will always be rounded down to the nearest integer.
					// ulTotalRunTimeDiv100 has already been divided by 100.
					//ulStatsAsPercentage = pxTaskStatusArray[ x ].ulRunTimeCounter / ulTotalRunTime;

					if( ulStatsAsPercentage > 0UL )
					{
						snprintf(
							taskMetricsStringBuff,
							sizeof(taskMetricsStringBuff),
							"%20s\t\t%lu\t\t%lu%%\r\n",
							pxTaskStatusArray[x].pcTaskName, 
							pxTaskStatusArray[x].ulRunTimeCounter, 
							100lu);
					}
					else
					{
						// If the percentage is zero here then the task has
						// consumed less than 1% of the total run time.
						snprintf(
							taskMetricsStringBuff,
							sizeof(taskMetricsStringBuff),
							"%s\t\t%lu\t\t<1%%\r\n", 
							pxTaskStatusArray[ x ].pcTaskName, 
							pxTaskStatusArray[ x ].ulRunTimeCounter);
					}

					Port::DebugPrint(taskMetricsStringBuff);
				}
			/*
			}			
			else
			{
				#if(Sauron_Config_DEBUG_PRINT_VERBOSE == 1)
					Port::DebugPrint("SAURON: Total runtime is 0.\r\n");
				#endif
			}*/

			// The array is no longer needed, free the memory it consumes.
			vPortFree(pxTaskStatusArray);
		}
		else
		{
			Port::DebugPrint("SAURON: Malloc for task info failed.\r\n");
		}
	}

} // namespace Sauron

#endif // Sauron_Config_ENABLE_FREERTOS_METRICS

// EOF
