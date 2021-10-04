cmake_minimum_required(VERSION 3.5)

project(cake_game LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Network REQUIRED)
find_package(Qt5 COMPONENTS Core Gui REQUIRED)


set(QRC_FILE res.qrc)
qt5_add_resources(QRC ${QRC_FILE})

if(ANDROID)
  add_library(cake_game SHARED
    main.cpp
    widget.cpp
    widget.h
    widget.ui
    core.h
    TCP_server.h
    TCP_client.h
    mypushbottom.h
    mypushbottom.cpp
    playscene.h
    playscene.cpp
    ${QRC}
    online.h
    online.cpp
    online.ui
    gameroom.cpp
    gameroom.h
    gameroom.ui
    joinscene.cpp
    joinscene.h
    joinscene.ui
  )
else()
  add_executable(cake_game
    main.cpp
    widget.cpp
    widget.h
    widget.ui
    core.h
    TCP_server.h
    TCP_client.h
    mypushbottom.h
    mypushbottom.cpp
    playscene.h
    playscene.cpp
    onlineplay.h
    onlineplay.cpp
    ${QRC}
    online.h
    online.cpp
    online.ui
    gameroom.cpp
    gameroom.h
    gameroom.ui
    joinscene.cpp
    joinscene.h
    joinscene.ui
    onlineplay.h
    onlineplay.cpp
  )
endif()

target_link_libraries(cake_game PRIVATE Qt5::Widgets)
target_link_libraries(cake_game PRIVATE Qt5::Network)
target_link_libraries(cake_game PRIVATE Qt5::Core Qt5::Gui)
