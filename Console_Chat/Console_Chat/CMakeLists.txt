cmake_minimum_required(VERSION 3.5)

project(Chat VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
Console_Chat.cpp
Chat.cpp
Chat.h
Message.cpp
Message.h
User.cpp
User.h
)

add_executable(Chat
            ${PROJECT_SOURCES}
        )
        
install(TARGETS Chat
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
