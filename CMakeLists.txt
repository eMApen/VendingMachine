cmake_minimum_required(VERSION 3.10)
project(VendingMachineProject)

set(CMAKE_CXX_STANDARD 11)

add_executable(VendingMachineProject 
                src/main.cpp 
                src/product.cpp
                src/vending_machine.cpp 
                src/user.cpp
                src/discount_vm.cpp
                )


# 添加头文件搜索路径
target_include_directories(VendingMachineProject PRIVATE ${PROJECT_SOURCE_DIR}/include)
