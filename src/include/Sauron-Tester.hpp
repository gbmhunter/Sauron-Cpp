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

#include "Sauron-Config.hpp"
#include "Sauron-Port.hpp"

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
			static bool LessThan(var_t val, var_t limit, double voltage, uint32_t testSuiteNum);
			
			template<typename var_t>
			static bool LessThan(var_t val, var_t limit, double voltage);
			
			template<typename var_t>
			static bool LessThan(var_t val, var_t limit);
		
			template<typename var_t>
			static bool LessThanOrEqual(var_t val, var_t limit, double voltage, uint32_t testSuiteNum);
		
			template<typename var_t>
			static bool LessThanOrEqual(var_t val, var_t limit, double voltage);
		
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
			
			//! @brief		Set to true if you want to use the analog output.
			static bool useAnalogOut;
			
			//! @brief		Stores the number of the currently active test suite.
			static uint32_t activeTestSuite;
			
		private:
		
			static char debugBuff[Sauron_Config_DEBUG_BUFF_SIZE];
		
			static void DoGpio();
			
			static void DoAnalog(double voltagemV);
			
			//===============================================================================================//
			//======================================= PRIVATE VARIABLES =====================================//
			//===============================================================================================//
			
			
			
	};

	//===============================================================================================//
	//================================= PUBLIC TEMPLATE METHOD DEFINITIONS ==========================//
	//===============================================================================================//
	
	//! @note Base function
	template<typename var_t>
	bool Tester::LessThan(var_t val, var_t limit, double voltage, uint32_t testSuiteNum)
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
				DoGpio();
			
			// Only set analog output if useAnalogOut = true and
			// voltage is positive.
			if(useAnalogOut && voltage >= 0.0 && testSuiteNum == activeTestSuite)
				DoAnalog(voltage);
			
			errorCnt++;
			
			return false;
		}
	}
	
	//! @brief
	//! @note 		Simplified function.
	template<typename var_t>
	bool Tester::LessThan(var_t val, var_t limit, double voltage)
	{
		return LessThan(val, limit, voltage, 1);
	}
	
	//! @brief
	//! @note 		Simplified function.
	template<typename var_t>
	bool Tester::LessThan(var_t val, var_t limit)
	{
		return LessThan(val, limit, -1.0, 1);
	}
	
	//! @brief
	//! @note		Base function.
	template<typename var_t>
	bool Tester::LessThanOrEqual(var_t val, var_t limit, double voltage, uint32_t testSuiteNum)
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
			
			// Only set analog output if useAnalogOut = true and
			// voltage is positive.
			if(useAnalogOut && voltage >= 0.0 && testSuiteNum == activeTestSuite)
				DoAnalog(voltage);
				
			return false;
		}
	}
	
	//! @brief
	//! @note 		Simplified function.
	template<typename var_t>
	bool Tester::LessThanOrEqual(var_t val, var_t limit, double voltage)
	{
		return LessThanOrEqual(val, limit, voltage, 1);
	}
	
	//! @brief
	//! @note 		Simplified function.
	template<typename var_t>
	bool Tester::LessThanOrEqual(var_t val, var_t limit)
	{
		return LessThanOrEqual(val, limit, -1.0, 1);
	}
	
} // namespace Sauron

#endif	// #ifndef SAURON_TESTER_H

// EOF
