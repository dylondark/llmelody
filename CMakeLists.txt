cmake_minimum_required(VERSION 3.16)

project(llmelody VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)
find_package(CURL REQUIRED)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appllmelody
    main.cpp
)

qt_add_qml_module(appllmelody
    URI llmelody
    VERSION 1.0
    QML_FILES
        Main.qml
        QML_FILES OllamaConfig.qml
        SOURCES
        SOURCES ollamainterface.h ollamainterface.cpp
        SOURCES programcontroller.h programcontroller.cpp
        SOURCES prompt.h
        SOURCES threadworker.h
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appllmelody PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appllmelody
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appllmelody
    PRIVATE Qt6::Quick
    PRIVATE CURL::libcurl
)

include(GNUInstallDirs)
install(TARGETS appllmelody
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
