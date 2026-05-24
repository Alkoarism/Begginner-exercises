cmake_minimum_required(VERSION 4.1.3)
project(Exercise06)

add_executable(TIC_TAC_TOE)
target_sources(TIC_TAC_TOE
	PRIVATE
		generic.cpp
		IA_TTT.cpp
		main2-0.cpp
		Tic_Tac_Toe.cpp
	PUBLIC
		FILE_SET HEADERS
		FILES
			generic.hpp
			IA_TTT.hpp
			Tic_Tac_Toe.hpp
)	
