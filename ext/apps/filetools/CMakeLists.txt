# apps/filetools/CMakeLists.txt

add_executable(sp3version sp3version.cpp)
target_link_libraries(sp3version gpstk)
install (TARGETS sp3version DESTINATION "${CMAKE_INSTALL_BINDIR}")


