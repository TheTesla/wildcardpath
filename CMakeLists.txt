cmake_minimum_required (VERSION 2.8.11)
project (wildcardpath)
add_library (findpathwild findpathwild.c)
add_executable (wildcardpath main.c)
target_link_libraries(wildcardpath findpathwild)



