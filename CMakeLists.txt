cmake_minimum_required(VERSION 3.5)

project(untitled LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package 會找Qt5_DIR
set(Qt5_DIR  "C:\\Qt\\5.15.2\\msvc2019_64\\lib\\cmake\\Qt5\\")

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

add_executable(untitled
    ${PROJECT_SOURCES}
)

target_link_libraries(untitled PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)


add_executable(Qt5::windeployqt IMPORTED)

set_target_properties(Qt5::windeployqt PROPERTIES
    IMPORTED_LOCATION "C:\\Qt\\5.15.2\\msvc2019_64\\bin\\windeployqt.exe"
)
# %PATH% 當前path；$<SEMICOLON>此為分號；${qt5_install_prefix}的bin資料夾，內有windeployqt.exe
# $<TARGET_FILE_DIR:untitled>/$<TARGET_FILE_NAME:untitled>，產生的exe
add_custom_command(TARGET untitled
    POST_BUILD
    COMMAND Qt5::windeployqt "$<TARGET_FILE_DIR:untitled>/$<TARGET_FILE_NAME:untitled>"
)