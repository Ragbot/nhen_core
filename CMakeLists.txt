project(nhen)

add_executable(nhen main.cpp nhen_parser.cpp)

target_link_libraries(nhen curl pugixml)
