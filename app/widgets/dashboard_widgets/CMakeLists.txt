add_library(dashboard_widgets STATIC
    h/YearlyOverviewDashboardWidget.h
    src/YearlyOverviewDashboardWidget.cpp
)

target_include_directories(dashboard_widgets
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/h
)

target_link_libraries(dashboard_widgets
    PUBLIC
        Qt6::Core
        Qt6::Widgets
)
