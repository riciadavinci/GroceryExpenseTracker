add_library(main_window STATIC
    h/MainWindow.h
    src/MainWindow.cpp
)

target_include_directories(main_window
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/h
)

target_link_libraries(main_window
    PUBLIC
        Qt6::Core
        Qt6::Widgets
)
