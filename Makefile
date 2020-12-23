# The Graphics Math Library is a header-only library, meaning there's no need to compile it.
# This Makefile compiles the test.cpp file only.
# Test.cpp is meant to test out the library.

COMPILER = g++
EXECUTABLE_NAME = test.exe

main:
	${COMPILER} -o ${EXECUTABLE_NAME} test.cpp -I./include/
