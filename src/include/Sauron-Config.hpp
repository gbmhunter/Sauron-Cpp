//!
//! @file 		Sauron-Config.hpp
//! @author 	Geoffrey Hunter <gbmhunter@gmail.com> 
//! @date 		2013/04/02
//! @brief 		Configuration file for Sauron.
//! @details
//!				See README.rst in root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef SAURON_CONFIG_H
#define SAURON_CONFIG_H

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

// none

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace Sauron
{

	//===============================================================================================//
	//==================================== PUBLIC DEFINES ===========================================//
	//===============================================================================================//

	//=============== DEBUG SWITCHES ============//

	#define Sauron_Config_DEBUG_PRINT_GENERAL		1u				//!< Print general debug msgs
	#define Sauron_Config_DEBUG_PRINT_VERBOSE		1u				//!< Print verbose debug msgs
	#define Sauron_Config_DEBUG_PRINT_ERROR			1u				//!< Print error debug msgs

	#define Sauron_Config_DEBUG_PRINT_ANY	(Sauron_Config_DEBUG_PRINT_GENERAL | Sauron_Config_DEBUG_PRINT_VERBOSE | Sauron_Config_DEBUG_PRINT_ERROR)
	
	//! @brief		The size of the debug buffer.
	//! @details	All writes use snprintf so should be safe if too small.
	#define Sauron_Config_DEBUG_BUFF_SIZE			(200u)
	
	//! @brief		(bool) Default value for printing errors.
	#define Sauron_Config_PRINT_ERROR_DEF 			0u;
	
	//! @brief		(bool) Default value for setting GPIO on error.
	#define Sauron_Config_SET_GPIO_DEF 				1u;
	
	//! @brief		(Tester::gpioMode_t) Default value for setting GPIO on error.
	#define Sauron_Config_DEF_GPIO_MODE 			Tester::TOGGLE;
	
	//! @brief		(Tester::gpioState_t) Default state for GPIO.
	#define Sauron_Config_DEF_GPIO_STATE 			Tester::LOW;
	
	//! @brief		(bool) Set to 1 to enable the printing of FreeRTOS metrics
	//! @note		FreeRTOS must be installed on the system, and configUSE_TRACE_FACILITY and configUSE_STATS_FORMATTING_FUNCTIONS
	//!				must be defined as 1, otherwise you will compiler errors.
	#define Sauron_Config_ENABLE_FREERTOS_METRICS	1u
		
} // namespace Sauron

#endif	// #ifndef SAURON_CONFIG_H

// EOF
