#
#
#

cmake_minimum_required(VERSION 2.8.12)

#
# Name of project
#

project (MiniTerm)

#
#
#

include_directories(include)

#
#
#

set(SOURCE src/console.c)

#
#
#

add_executable(console.o ${SOURCE})
