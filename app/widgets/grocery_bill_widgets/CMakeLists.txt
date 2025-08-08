add_library(grocery_bill_widgets STATIC
    h/AddGroceryBillWidget.h
    src/AddGroceryBillWidget.cpp
    h/SearchGroceryBillWidget.h
    src/SearchGroceryBillWidget.cpp
)

target_include_directories(grocery_bill_widgets
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/h
)

target_link_libraries(grocery_bill_widgets
    PUBLIC
        Qt6::Core
        Qt6::Widgets
)
