cmake_minimum_required(VERSION 3.15) # минимальная версия cmake
project(Sudoku)  # название проекта

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_FILES # переменная с именами исходников
	main.cpp
)

include_directories(header)

add_executable(${PROJECT_NAME} ${SRC_FILES}) # название итогого приложения и из чего его собирать
