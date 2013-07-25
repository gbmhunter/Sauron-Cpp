======
Sauron
======

------------------------------------------------------------------------------------------------------------------------
A portable, microcontroller-geared unit test and metric (benchmarking) C++ library. It keeps a watchful eye on things...
------------------------------------------------------------------------------------------------------------------------

- Author: gbmhunter <gbmhunter@gmail.com> (http://www.cladlab.com)
- First Ever Commit: 2013/07/19
- Last Modified: 2013/07/25
- Version: v3.0.3.0
- Company: CladLabs
- Project: Free Code Libraries
- Language: C++
- Compiler: GCC	
- uC Model: n/a
- Computer Architecture: n/a
- Operating System: n/a
- Documentation Format: Doxygen
- License: GPLv3

Description
===========

Designed to be both powerful and efficient in an embedded (microcontroller) environment.

Supports deferred error message printing (aka not at the point at which the error occurs), preventing disruptive error handling in time critical functions (e.g. control interrupts).

Support for printing FreeRTOS (a popular embedded real-time operating system) scheduler and task information.

External Dependencies
=====================

FreeRTOS (only if FreeRTOS debug/statistic printing is enabled in Sauron-Config.hpp).

Issues
======

See GitHub Issues.

Limitations
===========

Coming soon...

Usage
=====

Coming soon...
	
Changelog
=========

======== ========== ===================================================================================================
Version  Date       Comment
======== ========== ===================================================================================================
v3.0.3.0 2013/07/25 Completed digital GPIO/analog functionality for Sauron-Tester class. Changed default state for GPIO. Fixed some includes.
v3.0.2.0 2013/07/25 Sauron-Port.hpp now looks for PSOC (add via -D PSOC compiler flag) to be defined to include device.h. Fixed some includes.
v3.0.1.0 2013/07/25 Changed incorrect '.h' includes to '.hpp'.
v3.0.0.0 2013/07/25 Added trace functionality (Sauron-Tracer.hpp/cpp). Removed magic numbers and replaced with sizeof(). Now prints byte unit and total allocated bytes when showing FreeRTOS debug info. Added analog out functionality.
v2.0.0.0 2013/07/22 Added FreeRTOS reporting functionality (Sauron-FreeRtosMetrics.cpp/hpp). Added portable printf() symbols. Added info to README.
v1.1.0.0 2013/07/19 Tester functions now template to support any data type. Added mention of C++ to README. Removed unnecessary includes from Sauron-Port.cpp.
v1.0.0.0 2013/07/19 First version!. Bare-bones files for doing a less-than test with portable code in own file. Makefile included, but not fully functional yet.
======== ========== ===================================================================================================