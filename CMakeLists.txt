cmake_minimum_required(VERSION 3.0.0)
project(wxScmNotifier VERSION 0.1.0)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 17)
set(wxWidgets_ROOT_DIR ${WXWIN})
set(wxWidgets_CONFIGURATION mswu)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(CTest)
enable_testing()

find_package(wxWidgets COMPONENTS core base adv xml xrc REQUIRED)

# Did we find wxWidgets ? This condition will fail
# for as long as the internal vars do not point to
# the proper wxWidgets configuration
if(wxWidgets_FOUND)
     
include(${wxWidgets_USE_FILE})

# For convenience we define the sources as a variable. You can add 
# header files and cpp / c files and CMake will sort them out
file(GLOB wxScmNotifierSources *.cpp)
set(SRCS ${wxScmNotifierSources} )

# If we build for windows systems, we also include the resource file
# containing the manifest, icon and other resources
if(WIN32)
	set(SRCS ${SRCS} resource.rc)
endif(WIN32)

if(WIN32)
  # WIN32 := subsystem is windows instead of console?
  add_executable(wxScmNotifier WIN32 ${SRCS})
else(WIN32)
  add_executable(wxScmNotifier ${SRCS})
endif()

# We add to our target 'minimal' the wxWidgets libraries. These are
# set for us by the find script. If you need other libraries, you
# can add them here as well. 
target_link_libraries(wxScmNotifier ${wxWidgets_LIBRARIES})

else(wxWidgets_FOUND)
    # For convenience. When we cannot continue, inform the user
    message("wxWidgets not found!")
endif(wxWidgets_FOUND)

include(CPack)
