cmake_minimum_required(VERSION 3.20)

project(ControlVersion)

set(CMAKE_CXX_STANDARD 20)

add_compile_definitions(AMD64)

add_executable (ControlVersion
	"src/main.cpp"

	"src/versioning/Commit.cpp"
	"src/versioning/Commit.hpp"
	"src/utils/FileUtils.cpp"   
	"src/versioning/StorageManager.cpp")




