cmake_minimum_required(VERSION 3.16)
project(lab_oop_game VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Добавляем предупреждения
add_compile_options(-Wall -Wextra -Wpedantic)

# Указываем папку с заголовками
include_directories(${PROJECT_SOURCE_DIR}/include)

# Автоматически собираем все .cpp файлы из src/
file(GLOB SOURCES src/*.cpp)

# Создаём исполняемый файл
add_executable(lab_oop_game ${SOURCES})
