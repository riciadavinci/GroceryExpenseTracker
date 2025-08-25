add_library(database STATIC
    sql_query_loader/h/SqlQueryLoader.h
    sql_query_loader/src/SqlQueryLoader.cpp
)

target_include_directories(database
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/database_manager/h
        ${CMAKE_CURRENT_SOURCE_DIR}/sql_query_loader/h
        ${CMAKE_CURRENT_SOURCE_DIR}/database_schema_manager/h
        ${CMAKE_CURRENT_SOURCE_DIR}/database_seeder/h
)

target_link_libraries(database
    PUBLIC
        Qt6::Core
        Qt6::Sql
)

add_subdirectory(database_manager)
add_subdirectory(sql_query_loader)
add_subdirectory(database_schema_manager)
add_subdirectory(database_seeder)