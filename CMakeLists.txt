cmake_minimum_required(VERSION 3.5)

project(restaurant-billing-system VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

include_directories(
    ${PROJECT_SOURCE_DIR}/admin
    ${PROJECT_SOURCE_DIR}/db
    ${PROJECT_SOURCE_DIR}/login
    ${PROJECT_SOURCE_DIR}/user_use_case
    ${PROJECT_SOURCE_DIR}/user_use_util
)

set(PROJECT_SOURCES
        main.cpp
        login/mainwindow.cpp
        login/mainwindow.h
        login/mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(restaurant-billing-system
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET restaurant-billing-system APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(restaurant-billing-system SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(restaurant-billing-system
            ${PROJECT_SOURCES}
            users.qrc
            util/Constants.h
            db/FileManager.h
            db/FileManager.cpp
            login/LoginDataModel.cpp
            login/LoginDataModel.h
            login/LoginController.h
            login/LoginController.cpp
            admin/admindashboard.h
            admin/admindashboard.cpp
            admin/admindashboard.ui
            admin/AdminDashboardController.h
            admin/AdminDashboardController.cpp
            user_use_case/edituserdialog.h
            user_use_case/edituserdialog.cpp
            user_use_case/EditUserDialogController.h
            user_use_case/EditUserDialogController.cpp
            user_use_case/edituserdialog.ui
        )
    endif()
endif()

target_link_libraries(restaurant-billing-system PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.restaurant-billing-system)
endif()
set_target_properties(restaurant-billing-system PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS restaurant-billing-system
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(restaurant-billing-system)
endif()
