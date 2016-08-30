cmake_minimum_required(VERSION 3.6)
project(bsi_aed)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(SOURCE_FILES *c)
#add_executable(bsi_aed ${SOURCE_FILES})
file( GLOB APP_SOURCES src/*.c )
foreach( testsourcefile ${APP_SOURCES} )
    # I used a simple string replace, to cut off .cpp.
    string( REPLACE ".c" "" testname ${testsourcefile} )
    string( REGEX MATCH "[^\/]*$" testname ${testname})
    #[^\/]*$/
    #[^\/]* match a single character not present in the list below
    #Quantifier: * Between zero and unlimited times, as many times as possible, giving back as needed [greedy]
    #\/ matches the character / literally
    #$ assert position at end of the string
    add_executable( ${testname}  ${testsourcefile} )
    # Make sure YourLib is linked to each app
    #target_link_libraries( ${testname} YourLib )
endforeach( testsourcefile ${APP_SOURCES} )