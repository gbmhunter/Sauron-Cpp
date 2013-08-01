//!
//! @file 		Sauron-Tracer.cpp
//! @author 	Geoffrey Hunter <gbmhunter@gmail.com>
//! @date 		2013/07/22
//! @brief 		Function/task tracer module.
//! @details
//!				See README.rst in root folder for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//========================================= INCLUDES ============================================//
//===============================================================================================//

// System includes
#include <stdint.h>		// int8_t, int32_t e.t.c
#include <stdio.h>		// snprintf()

// User includes
#include "include/Sauron-Config.hpp"
#include "include/Sauron-Tracer.hpp"
#include "include/Sauron-Port.hpp"

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace Sauron
{

	bool Tracer::enableTrace = Sauron_Config_DEF_ENABLE_TRACE;
	uint32_t Tracer::activeTraceSuite = 0;
	
	//===============================================================================================//
	//================================== PUBLIC METHOD DEFINITIONS ==================================//
	//===============================================================================================//

	void Tracer::Trace(double voltagemV, uint32_t traceSuiteNum)
	{
		if(enableTrace)
		{
			if(traceSuiteNum == activeTraceSuite)
			{
				Port::SetAnalogOut(voltagemV);
			}
		}
	}
	
	//===============================================================================================//
	//================================== PRIVATE METHOD DEFINITIONS =================================//
	//===============================================================================================//

	// none

} // namespace Sauron