cmake_minimum_required(VERSION 2.6)
project(battleship)
set(battleship_sources
        include/Computer.h src/Computer.cpp
        include/GameInterface.h src/GameInterface.cpp
        include/GameLogic.h src/GameLogic.cpp
        include/Greedy.h src/Greedy.cpp
		include/Grid.h src/Grid.cpp
        include/GridInterface.h src/GridInterface.cpp
        include/Human.h src/Human.cpp
        include/MultipleFunnel.h src/MultipleFunnel.cpp
		include/Player.h src/Player.cpp
        include/PlayerInterface.h src/PlayerInterface.cpp
        include/Random.h src/Random.cpp
        include/Ship.h src/Ship.cpp
		include/SingleFunnel.h src/SingleFunnel.cpp
		include/Square.h src/Square.cpp
		include/Strategy.h src/Square.cpp
        src/main.cpp)
add_executable(battleship ${battleship_sources})
target_include_directories(battleship PUBLIC include)

enable_testing()       
set(Boost_USE_MULTITHREADED ON)
if(MSVC)
    if(NOT BOOST_ROOT)
        set(BOOST_ROOT "C:/local/boost_1_60_0")
    endif()
    set(Boost_INCLUDE_DIR "${BOOST_ROOT}")
    set(Boost_LIBRARY_DIR "${BOOST_ROOT}/lib32-msvc-14.0")
    set(Boost_USE_STATIC_LIBS ON)
    set(Boost_USE_MULTITHREADED ON)

    find_package(Boost COMPONENTS unit_test_framework REQUIRED)

    include_directories(${Boost_INCLUDE_DIR})
    link_directories(${Boost_LIBRARY_DIR})

else()
    find_package(Boost COMPONENTS unit_test_framework REQUIRED)
endif()                                                                                                                                                                                                                                    
include_directories(
	include 
	${Boost_INCLUDE_DIRS}
)
link_directories(${Boost_LIBRARY_DIR})
add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
	${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

set(TEST_SOURCES
	test/config.cpp
	test/Test.cpp
)
add_executable(tester ${TEST_SOURCES})
target_link_libraries(tester
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
add_test(tester tester)
