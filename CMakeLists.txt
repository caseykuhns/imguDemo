cmake_minimum_required(VERSION 3.0.0)
project(imgui VERSION 0.1.0)

find_package(directxtk12 CONFIG REQUIRED)




#do something
file(GLOB SRCS imgui/*.cpp imgui/*.h imgui/backends/*.cpp imgui/backends/*.h)

add_executable(DemoApp main.cpp ${SRCS})

target_include_directories(DemoApp PRIVATE imgui/ imgui/backends)

target_link_libraries(DemoApp PRIVATE
d3d12.lib dxgi.lib dxguid.lib uuid.lib
kernel32.lib user32.lib
comdlg32.lib advapi32.lib shell32.lib
ole32.lib oleaut32.lib
runtimeobject.lib
Microsoft::DirectXTK12
)