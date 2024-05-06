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
    ${PROJECT_SOURCE_DIR}/util
    ${PROJECT_SOURCE_DIR}/order
    ${PROJECT_SOURCE_DIR}/bill
    ${PROJECT_SOURCE_DIR}/payment
)

set(PROJECT_SOURCES
        main.cpp
        util/Enums.cpp
        login/mainwindow.cpp
        login/mainwindow.h
        login/mainwindow.ui
)

add_executable(restaurant-billing-system
    ${PROJECT_SOURCES}
    users.qrc
    util/Constants.h
    util/Enums.cpp
    util/Enums.h
    db/FileManager.h
    db/FileManager.cpp
    db/menuitems.csv
    db/UserManager.h
    db/UserManager.cpp
    login/LoginDataModel.cpp
    login/LoginDataModel.h
    login/LoginController.h
    login/LoginController.cpp
    admin/admindashboard.h
    admin/admindashboard.cpp
    admin/admindashboard.ui
    admin/AdminDashboardController.h
    admin/AdminDashboardController.cpp
    admin/UserTableModelAdapter.cpp
    admin/UserTableModelAdapter.h
    user_use_case/edituserdialog.h
    user_use_case/edituserdialog.cpp
    user_use_case/EditUserDialogController.h
    user_use_case/EditUserDialogController.cpp
    user_use_case/edituserdialog.ui
    payment/Payment.h
    payment/Payment.cpp
    bill/bill.h
    bill/Bill.cpp
    bill/BillInterface.h
    bill/BillDecorator.h
    bill/PartyDiscountDecorator.h
    bill/CouponDiscountDecorator.h
    model/user/User.h
    model/user/Admin.h
    model/user/StaffMember.h
    model/user/Accountant.h
    model/user/UserFactory.h
    model/user/UserFactory.cpp
    menu/Menu.cpp
    menu/Menu.h
    menu/MenuController.cpp
    menu/MenuController.h
    menu/MenuItem.cpp
    menu/MenuItem.h
    menu/MenuItemAdapter.cpp
    menu/MenuItemAdapter.h
    menu/MenuItemDelegate.cpp
    menu/MenuItemDelegate.h
    menu/MenuItemDialog.cpp
    menu/MenuItemDialog.h
    menu/MenuListModel.cpp
    menu/MenuListModel.h
    menu/MenuListView.cpp
    menu/MenuListView.h
    menu/MenuWindow.cpp
    menu/MenuWindow.h
    menu/MenuWindow.ui
    order/controllers//OrderController.cpp
    order/controllers//OrderController.h
    order/facade/OrderManagementFacade.cpp
    order/facade/OrderManagementFacade.h
    order/models/Order.cpp
    order/models/Order.h
    order/models/OrderItem.cpp
    order/models/OrderItem.h
    order/OrderAdapter.h
    order/OrderAdapter.cpp
    order/OrderListModel.h
    order/OrderListModel.cpp
    order/orderdetails.cpp
    order/orderdetails.h
    order/orderdetails.ui
    order/orderwindow.h order/orderwindow.cpp order/orderwindow.ui
    order/orderdetails.h order/orderdetails.cpp order/orderdetails.ui
    order/orderdetails.h order/orderdetails.cpp order/orderdetails.ui
    order/OrderTableAdapter.h
    order/OrderTableAdapter.cpp
    bill/billwindow.h bill/billwindow.cpp bill/billwindow.ui
    bill/billdetails.h bill/billdetails.cpp bill/billdetails.ui


)

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
