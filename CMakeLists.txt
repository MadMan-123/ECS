cmake_minimum_required(VERSION 3.24)
project(ECSc__)

set(CMAKE_CXX_STANDARD 23)

add_executable(ECS main.cpp ECS/Entity.cpp ECS/Entity.h ECS/EntityManager.cpp ECS/EntityManager.h ECS/Component.cpp ECS/Component.h ECS/CommonECS.h ECS/ComponentManager.cpp ECS/ComponentManager.h)
