cmake_minimum_required(VERSION 3.19)
project(Sudoku LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_FILES # файлы для компиляции
    main.cpp
    src/MainWindow.cpp
    src/Difficult.cpp
    src/Generator.cpp
    src/MatrixFunctions.cpp
    src/Formatter.cpp
    src/PlayingWindow.cpp
    src/GameCell.cpp
    src/ControlCell.cpp
    src/Helper.cpp
)

set(HEADER_FILE # header'ы для MOC (header'ы, где используется макрос Q_OBJECT)
    header/MainWindow.hpp
    header/Difficult.hpp
    header/PlayingWindow.hpp
    header/GameCell.hpp
    header/ControlCell.hpp
    header/Helper.hpp
)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Gui Widgets) # Поиск QT и его компонентов

qt_standard_project_setup()

qt_wrap_cpp(MOC_FILES ${HEADER_FILE})
qt_add_executable(${PROJECT_NAME}
    ${SRC_FILES}
    ${MOC_FILES}
    res/icon.rc
)


target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

include(GNUInstallDirs)
include_directories(header)

install(TARGETS ${PROJECT_NAME}
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
