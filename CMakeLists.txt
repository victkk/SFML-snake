cmake_minimum_required(VERSION 3.16)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)


add_executable(test src/test.cpp)
target_link_libraries(test PRIVATE sfml-graphics)
target_compile_features(test PRIVATE cxx_std_17)

add_executable(snake src/snake_test.cpp src/entity/snake.cpp src/utils.cpp src/entity/snakeManager.cpp src/entity/snakeManager.hpp src/entity/food.hpp src/entity/food.cpp src/entity/foodManager.hpp src/entity/foodManager.cpp src/screen/gameScreen.hpp src/screen/gameScreen.cpp src/screen/pauseScreen.hpp src/screen/pauseScreen.cpp src/screen/IScreen.hpp src/screen/screenManager.hpp src/screen/screenManager.cpp)
target_link_libraries(snake PRIVATE sfml-graphics)
target_compile_features(snake PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET snake
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:snake>
        VERBATIM)
endif()
