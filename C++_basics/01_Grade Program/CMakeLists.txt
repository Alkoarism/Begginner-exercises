cmake_minimum_required(VERSION 4.01)
project(Exercise01)

add_executable(GradeProgram)
target_sources(GradeProgram
	PRIVATE
		main.cpp
		UX.cpp
	PUBLIC
		FILE_SET HEADERS
		FILES			
			UX.hpp
)
	
