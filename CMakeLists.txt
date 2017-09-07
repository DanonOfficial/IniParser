cmake_minimum_required(VERSION 3.8)
project(IniParser)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp IniParser.cpp IniParser.h NoFileError.h SectionError.h VariableError.h WrongFormatError.h NoSuchVariable.h)
add_executable(IniParser ${SOURCE_FILES})