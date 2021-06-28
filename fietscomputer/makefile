#============================================================================
#
# simple project makefile (just a main file)
#
# (c) Wouter van Ooijen (wouter@voti.nl) 2017
#
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE_1_0.txt or copy at 
# http://www.boost.org/LICENSE_1_0.txt) 
#
#============================================================================

# source files in this project (main.* is automatically assumed)
SOURCES += fietscomputer.cpp oledTask.cpp magnetTask.cpp fietscomputerTask.cpp temperatureTask.cpp angleTask.cpp

# header files in this project
HEADERS += fietscomputer.hpp oledTask.hpp magnetTask.hpp fietscomputerTask.hpp temperatureTask.hpp angleTask.hpp

# other places to look for files for this project
SEARCH  := ../MPU9250/

RESULTS := main.lss

# set RELATIVE to the next higher directory 
# and defer to the appropriate Makefile.* there
SERIAL_PORT := COM3
RELATIVE := ..
include $(RELATIVE)/MPU9250/makefile
include $(RELATIVE)/Makefile.due