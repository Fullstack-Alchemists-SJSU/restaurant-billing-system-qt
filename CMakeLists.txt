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
        add-user.png admin-dashboard.png CMakeLists.txt CMakeLists.txt.user CMakeLists.txt.user.8593eb5 delete.svg edit-user.png edit.svg main.cpp rbs-class-diagram.png README.md users.qrc
        admin/admindashboard.cpp admin/admindashboard.h admin/admindashboard.ui admin/AdminDashboardController.cpp admin/AdminDashboardController.h
        add-user.png admin-dashboard.png CMakeLists.txt CMakeLists.txt.user CMakeLists.txt.user.8593eb5 delete.svg edit-user.png edit.svg main.cpp rbs-class-diagram.png README.md users.qrc
        db/FileManager.cpp db/FileManager.h db/users.csv
        user_use_case/edituserdialog.cpp user_use_case/edituserdialog.h user_use_case/edituserdialog.ui user_use_case/EditUserDialogController.cpp user_use_case/EditUserDialogController.h
        util/Constants.h
        login/LoginController.cpp login/LoginController.h login/LoginDataModel.cpp login/LoginDataModel.h login/mainwindow.cpp login/mainwindow.h login/mainwindow.ui
        util/Enums.cpp
        util/Enums.h
        menu/Menu.cpp menu/Menu.h menu/MenuController.cpp menu/MenuController.h menu/MenuItem.cpp menu/MenuItem.h menu/MenuItemAdapter.cpp menu/MenuItemAdapter.h menu/MenuItemDelegate.cpp menu/MenuItemDelegate.h menu/MenuItemDialog.cpp menu/MenuItemDialog.h menu/MenuListModel.cpp menu/MenuListModel.h menu/MenuListView.cpp menu/MenuListView.h
        db/menuitems.csv
        menu/mainwindow.cpp menu/mainwindow.h menu/mainwindow.ui
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
            util/Enums.cpp
            util/Enums.h
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
            menu/Menu.cpp menu/Menu.h menu/MenuController.cpp menu/MenuController.h menu/MenuItem.cpp menu/MenuItem.h menu/MenuItemAdapter.cpp menu/MenuItemAdapter.h menu/MenuItemDelegate.cpp menu/MenuItemDelegate.h menu/MenuItemDialog.cpp menu/MenuItemDialog.h menu/MenuListModel.cpp menu/MenuListModel.h menu/MenuListView.cpp menu/MenuListView.h
            menu/MenuWindow.cpp menu/MenuWindow.h menu/MenuWindow.ui
            model/user/User.h
            model/user/Admin.h
            model/user/StaffMember.h
            model/user/Accountant.h
            model/user/UserFactory.h
            model/user/UserFactory.cpp
            db/UserManager.h
            db/UserManager.cpp
            admin/UserTableModelAdapter.cpp
            admin/UserTableModelAdapter.h
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
