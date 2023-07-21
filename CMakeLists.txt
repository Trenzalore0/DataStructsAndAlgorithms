cmake_minimum_required(VERSION 3.5)

project(Learn)

# Defina a versão mínima do Qt que você deseja usar
set(CMAKE_CXX_STANDARD 20)

# Definir a opção de compilação para Debug
set(CMAKE_BUILD_TYPE Debug)

# Crie o executável do seu projeto
add_executable(Learn main.cpp)
