CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
set(CMAKE_MODULE_PATH ../cmake)

PROJECT ("HelloWorld")

find_package (OpenSplice REQUIRED)

include_directories(
  ${PROJECT_SOURCE_DIR}
  ${OpenSplice_INCLUDE_DIRS}
)
MESSAGE( "PROJECT_SOURCE_DIR=" ${PROJECT_SOURCE_DIR})
MESSAGE( "OpenSplice_INCLUDE_DIRS=" ${OpenSplice_INCLUDE_DIRS})

SET (SRC_FILES
	HelloWorldPub.cpp
)
MESSAGE( "SRC_FILES=" ${SRC_FILES})

SET (PUB_EXE helloPub)
MESSAGE( "PUB_EXE=" ${PUB_EXE})

ADD_EXECUTABLE (${PUB_EXE} ${SRC_FILES})

SET(OpenSplice_DATAMODEL 
	./gen/HelloWorldData.cpp 
	./gen/HelloWorldDataDcps.cpp 
	./gen/HelloWorldDataDcps.h 
	./gen/HelloWorldData_DCPS.hpp 
	./gen/HelloWorldDataDcps_impl.cpp 
	./gen/HelloWorldDataDcps_impl.h 
	./gen/HelloWorldData.h 
	./gen/HelloWorldDataSplDcps.cpp 
	./gen/HelloWorldDataSplDcps.h)
MESSAGE("OpenSplice_DATAMODEL=" ${OpenSplice_DATAMODEL})

SET (DATAMODEL helloWorldData) 
MESSAGE("DATAMODEL=" ${DATAMODEL})

ADD_LIBRARY (${DATAMODEL} SHARED ${OpenSplice_DATAMODEL})

target_link_libraries (helloPub
 ${OpenSplice_LIBRARIES}
)
