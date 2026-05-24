#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Tutorial::Tutorial" for configuration "Debug"
set_property(TARGET Tutorial::Tutorial APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Tutorial::Tutorial PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/Tutorial"
  )

list(APPEND _cmake_import_check_targets Tutorial::Tutorial )
list(APPEND _cmake_import_check_files_for_Tutorial::Tutorial "${_IMPORT_PREFIX}/bin/Tutorial" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
