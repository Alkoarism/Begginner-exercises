This directory contains source code examples for the CMake Tutorial.
Each step has its own subdirectory containing code that may be used as a
starting point. The tutorial examples are progressive so that each step
provides the complete solution for the previous step.

You'll surely forget how to use this tool. Knowing that, here is a small step-by-step guide on how to set it up for a project:
>OBS: All info here was taken from https://cmake.org/

---

### STEP 0: Basics

Check if cmake is installed in your system.

```Bash
$ cmake --version #This should show a small message with version and info on cmake
```

```Bash
$ sudo pacman -S cmake #Command to install the package on arch
```
    
Following are some basic commands:

```Bash
$ cmake -S <dir> #Defines root -origin- directory, current if not specified
$ cmake -B <dir> #Defines build directory, current if not specified
$ cmake --build <dir> #Executes the command for building the project according to specs defined on the previous commands
```

Generators can make many versions of a build, the most relevant of which being "Debug" and "Release". Maketools (linux) and Ninja have this as a possibility by default.

Example of a few commands used:
```Bash
$ cmake -G Ninja -B build #Configures Ninja as building tool
$ cmake --build build --config Debug #Builds a Debug version
```

---

### STEP 1: Creating a CML file (or distributed set of files) 

First and foremost:Header - version and project name
```cmake
cmake_minimum_required(VERSION x.xx)
project(myProjectName)
```

Followed by .cpp files target:
```cmake
add_executable(MyProgram)
target_sources(MyProgram
    PRIVATE
        main.cpp
)
```

>[!Important]
>May it be clear from here onwards that CMakes deals in targets which are merely names to which are then associated properties so functions can act on them accordingly. Here *MyProgram* is being defined as an executable target

And who doesn´t like some includes:
```cmake
add_library(MyLibrary)
target_sources(MyLibrary
    library_implementation.cxx
    
PUBLIC
    FILE_SET myHeadersName
    TYPE HEADER
    BASE_DIR
        includes
    FILES
        includes/library_header.h
    )
```

>[!TIP]
>There's a few possible shortcuts here, like excluding the lines TYPE HEADER if FILE_SET is named as "HEADERS", or entirely removing the need to state paths relative to the source (as seen with BASE_DIR and at FILES declarations) if the CML file is inside the folder itself as described bellow
    
Last but not least, let's not forget to link everything:
```cmake
    target_link_libraries(MyProgram
        PRIVATE
            MyLibrary
    )
```
    
CML files can be written as a single CMakeLists.txt file at the root directory of a project or spread out through the project tree in order to separate concerns to their respective folders. In both cases the code is the same and needs only a few lines to be ported between each style as follows:
```cmake
add_subdirectory(MyProgram) \\Related CML stuff goes here
add_subdirectory(MyLibrary) \\same for .h file relate CML code
```

---

### STEP 2: The CMake Language 
**Do not forget: Everything is a string!**

Manipulation of variables happens through strings so, in order to get anything done names must be accessed as if they themselves could be changed through their annoying ```${${NAME}}``` multi-layered string access key. 

>[!NOTE]
>This access the value of a variable by first accessing the variable itself inside a function and **THERE ARE INSTANCES WHERE THIS COULD HAVE MORE LAYERS**

That aside, most of the language functions need closing (```endif()```, ```endwhile()```, ```endforeach()``` etc) but are pretty much what one would expect of standard turing-complete programing languages - except for the fact that most conditionals are treated as string operations.

#### Some relevant topics:

To separate concerns in CMake contexts, the extension ```.cmake``` can be used for pure configuration files with varying names, that should be used with a "include(<FILENAME>)" directive in the CMakesLists.txt parent file in order to keep everything tidy. This directive IS NOT the same as "add_subdirectory()", as the former is targeted at .cmake files whereas the latter looks for CML.txt files.

Testing a ```.cmake``` file can be accomplished using the command bellow.
```bash
$ cmake -P <FILENAME>
```
---

### STEP 3: Configuration and cache variables

Optional build targets can be configured in a project via ```option()```. This can be used while sending the -B command with a -D directive to allow customizing what will and will not be compiled when building a project.

>[!NOTE]
>```<INITIAL_STATE>``` and ```<DESIRED_STATE>``` may be basically anything - from a standard string to a bool value

```cmake
\\The option command should be strutured like so:
option(SPECIAL_COMPILE_DIRECTIVE_NAME "General description" <INITIAL_STATE>)
```

```bash
$ cmake -B build -DSPECIAL_COMPILE_DIRECTIVE_NAME=<DESIRED_STATE>
```

>[!TIP]   
>The -D build directive can also be used to configure CMAKE specific options (e.g. ```CMAKE_CXX_STANDARD```) - the specification and possible CMAKE options can be found at https://cmake.org/

All of these can be set up upfront at a file named *CMakePresets.json* or *CMakeUserPresets.json*. These can be **very** usefull to avoid needing to needlesly set build flags for every compilation. It should be noted that *CMakePresets.json* is intended to be a part of the project development process as it contains instructions on how to build it. The user version has it's usage clear by context.

A cmake setting can be reset using the following command:
```bash
$ cmake --fresh <OTHER_OPTIONS> <PATH_TO_SOURCE>
```
---

### STEP 4: Target Commands 

CMake offers a few functions for defining the properties of targets, as explained in Step1. Bellow follows a list containing these functions and a simple description of what they're used for:

| Common/Recommended | Advanced/Caution | Esoteric/Footguns |
| ------------------ | ---------------- | ----------------- |
| :command:`target_compile_definitions` | :command:`get_target_property` | :command:`target_include_directories` |
|:command:`target_compile_features` | :command:`set_target_properties` | :command:`target_link_directories` |
| :command:`target_link_libraries` | :command:`target_compile_options` | |
|:command:`target_sources` | :command:`target_link_options` | |
| | :command:`target_precompile_headers` | |

#### Common / Recommended
- **target_compile_definitions:** Add compile definitions to a target (e.g. compiling experimental libraries);
- **target_compile_features:** Add expected compiler features to a target (e.g. cxx_std_20);
- **target_link_libraries:** Specify libraries or flags to use when linking a given target and/or its dependents (explained above);
- **target_sources:** Specifies sources to use when building a target and/or its dependents (explained above);

#### Advanced / Caution
- **get_target_property:** Get a property from a target and stores it in a <VARIABLE>
- **set_target_properties:** Sets properties on targets
- **target_compile_options:** Add compile options to a target (Used in case of many compilers - e.g. -Wall for gcc and /W03 for MSVC);
- **target_link_options:** Add options to the link step for an executable, shared library or module library target;
- **target_precompile_headers:** Add a list of header files to precompile (Used for performance improvements on serial compilations);

### Esoteric / Footguns
- **target_include_directories:** Specifies include directories to use when compiling a given target (e.g. third-party includes)
- **target_link_directories:** Add link directories to a target (Same as above, but for linking operations - e.g. libs)
---

### STEP 05: Library concepts 

There are several ways a library can be used by a program as well as many other sources for such libraries/ includes (e.g. Third-party, external sources, internal separated sources etc). In an atempt to cover for such cases, an optional second argument can be passed when adding a library for compilation on a CMake file. Following are such types and the general code for passing them:

```cmake
add_library(<TARGET_LIBRARY> <TYPE>)
```

The ```<TYPE>``` argument can be any of the following:
- **STATIC:** Archive of object files for use when linking other targets.
- **SHARED:** Dynamic library that may be linked by other targets and loaded at runtime.
- **MODULE:** Plugin that may not be linked by other targets, but may be dynamically loaded at runtime using dlopen-like functionality.
- **OBJECT:** Collection of object files which have not been archived or linked into a library.
- **INTERFACE:** Specifies usage requirements for dependents but does not compile sources and does not produce a library artifact on disk.    
---

### Step 6: In-Depth System Introspection

*This chapter doesn´t concern me right now.*

It's all about directives for selecting very system specific headers and libraries. My projects don´t have a use for this, neither do I have any kind of application for these.

An example is the usage of SSE2 related functions (a Intel-Specific set of CPU instructions - also implemented in AMD processors) for optimization of math operations. Although it may be usefull for low-level programming and systems optimization, I'm dealing with high-level data transfer with GPUs - thus it doesn´t look immediately applicable. Might come in handy someday.

---

### Step 7: Custom Commands and Generated Files

*(As far as I get it:)* This chapter introduces a way to add meta-generated files with code inside that might be used at runtime.

The compiler or - in this situation - the build environment takes notice of such a possibility and prepares these binaries beforehand through a series of custom commands that predict it's generation.

>[!NOTE]
>These files may have their own "main" function and can exist on a completely separate pipeline relative to the proper "main" on the bigger program

---

### Step 8: Testing and CTest


---

### Step 9: Installation Commands and Concepts


---

### Step 10: Finding Dependencies


---

### Step 11: Miscellaneous Features
