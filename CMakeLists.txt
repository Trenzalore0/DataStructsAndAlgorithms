cmake_minimum_required(VERSION 3.5)

project(Learn)

# Defina a versão mínima do Qt que você deseja usar
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Definir a opção de compilação para Debug
set(CMAKE_BUILD_TYPE Debug)

# Adiciona as flags para tratar as advertências como erros
add_compile_options(-Wall -Wextra -Wwrite-strings -Wdeprecated-copy)

# Crie o executável do seu projeto
add_executable(Learn main.cpp)
