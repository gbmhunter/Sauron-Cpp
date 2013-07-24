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
#include "include/Sauron-Config.h"
#include "include/Sauron-Tracer.h"
#include "include/Sauron-Port.h"

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace Sauron
{

	bool Tracer::enableTrace = Sauron_Config_DEF_ENABLE_TRACE;

	//===============================================================================================//
	//================================== PUBLIC METHOD DEFINITIONS ==================================//
	//===============================================================================================//

	void Tracer::Trace(double voltagemV)
	{
		if(enableTrace)
			Port::SetAnalogOut(voltagemV);
	}
	
	//===============================================================================================//
	//================================== PRIVATE METHOD DEFINITIONS =================================//
	//===============================================================================================//

	// none

} // namespace Sauron