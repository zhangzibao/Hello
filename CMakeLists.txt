cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 14)
set(PROJECT_NAME Hello)
project(Hello)
#3.head file path，头文件目录
INCLUDE_DIRECTORIES(
        Headers
        include
        Eigen
)
#AUX_SOURCE_DIRECTORY(. DIR_SRCS)
# 配置QT的包
set(QT_HOME "C:/Qt/Qt5.9.4/5.9.4/mingw53_32/lib/cmake")   #对应的Qt的安装目录
set(CMAKE_PREFIX_PATH ${QT_HOME})# qt的路径
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
####这里根据Project的实际情况来添加需要的模块
find_package(Qt5Widgets REQUIRED Qt5Core Qt5Gui)
# 配置mysql-connect
find_package(Qt5Sql)
set(Projects_QT5_Libraries
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Sql
        )
#查找当前文件夹中的所有源文件，也可以通过Set命令将所有文件设置为一个变量
FILE(GLOB SRC_FILES ./Sources/*.cpp ./Sources/config/*.cpp ./Sources/model/*.cpp ./Sources/util/*.cpp)
#查找设置当前文件夹中所有的头文件
FILE(GLOB HEAD_FILES "./Headers/*.h")
#查找设置当前文件夹中所有的ui文件
FILE(GLOB UI_FILES "./Forms/*.ui")
#通过Ui文件生成对应的头文件，一定要添加
qt5_wrap_ui(WRAP_FILES ${UI_FILES})
#source_group("Ui" FILES ${UI_FILES} ${WRAP_FILES})
add_executable(PROJECT_NAME
        ${SRC_FILES}
        ${HEAD_FILES}
        ${WRAP_FILES})
target_link_libraries(PROJECT_NAME ${Projects_QT5_Libraries})
LINK_LIBRARIES(FANN)
target_compile_features(PROJECT_NAME PRIVATE cxx_range_for)