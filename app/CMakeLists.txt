add_subdirectory(core/bill_item_core)
add_subdirectory(core/grocery_bill_core)
add_subdirectory(database/database_manager)
add_subdirectory(database/bill_item_repository)
add_subdirectory(database/grocery_bill_repository)
add_subdirectory(widgets/bill_item_widgets)
add_subdirectory(widgets/grocery_bill_widgets)
add_subdirectory(widgets/dashboard_widgets)
add_subdirectory(widgets/main_window)


if (WIN32)
    set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/groceryexp.rc")
    # add_executable(groceryexp main.cpp ${APP_ICON_RESOURCE_WINDOWS})
    qt_add_executable(groceryexp main.cpp ${APP_ICON_RESOURCE_WINDOWS})
endif()

target_include_directories(groceryexp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/core/bill_item_core/h/)
target_include_directories(groceryexp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/core/grocery_bill_core/h/)
target_include_directories(groceryexp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/database/database_manager/h/)
target_include_directories(groceryexp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/database/bill_item_repository/h/)
target_include_directories(groceryexp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/database/grocery_bill_repository/h/)
target_include_directories(groceryexp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/widgets/bill_item_widgets/h/)
target_include_directories(groceryexp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/widgets/grocery_bill_widgets/h/)
target_include_directories(groceryexp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/widgets/dashboard_widgets/h/)
target_include_directories(groceryexp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/widgets/main_window/h/)

target_link_libraries(groceryexp
    PRIVATE
        Qt6::Core
        Qt6::Widgets
        Qt6::Sql
        main_window
)
