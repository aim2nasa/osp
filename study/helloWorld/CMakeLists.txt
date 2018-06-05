CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
set(CMAKE_MODULE_PATH ../cmake)

PROJECT ("HelloWorld")

include (osmacros)

find_package (OpenSplice REQUIRED)

include_directories(
  ${PROJECT_SOURCE_DIR}
  ${OpenSplice_INCLUDE_DIRS}
)
MESSAGE( "PROJECT_SOURCE_DIR=" ${PROJECT_SOURCE_DIR})
MESSAGE( "OpenSplice_INCLUDE_DIRS=" ${OpenSplice_INCLUDE_DIRS})

SET (PUB_SRC_FILES
	HelloWorldPub.cpp
)
MESSAGE( "PUB_SRC_FILES=" ${PUB_SRC_FILES})

SET (SUB_SRC_FILES
	HelloWorldSub.cpp
)
MESSAGE( "SUB_SRC_FILES=" ${SUB_SRC_FILES})

SET (PUB_EXE helloPub)
MESSAGE( "PUB_EXE=" ${PUB_EXE})

SET (SUB_EXE helloSub)
MESSAGE( "SUB_EXE=" ${SUB_EXE})

ADD_EXECUTABLE (${PUB_EXE} ${PUB_SRC_FILES})
ADD_EXECUTABLE (${SUB_EXE} ${SUB_SRC_FILES})

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

MESSAGE ("OpenSplice_DEFINITIONS=" ${OpenSplice_DEFINITIONS})
MESSAGE ("DEFINITIONS=" ${DEFINITIONS})

ADD_DEFINITIONS (
 ${OpenSplice_DEFINITIONS}
 ${DEFINITIONS}
)

target_link_libraries (helloPub
 ${OpenSplice_LIBRARIES}
 ${DATAMODEL}
)

target_link_libraries (helloSub
 ${OpenSplice_LIBRARIES}
 ${DATAMODEL}
)
