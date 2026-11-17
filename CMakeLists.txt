cmake_minimum_required(VERSION 3.10)
project(luna VERSION 0.0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

option(ENABLE_LTO "Enable Link Time Optimization (LTO) in Release mode" OFF)

add_executable(${PROJECT_NAME}
    src/main.c
    src/_i_base.c
)

target_include_directories(${PROJECT_NAME} PRIVATE thirdparty)


if(ENABLE_LTO)
    include(CheckIPOSupported)
    check_ipo_supported(RESULT ipo_supported OUTPUT error)

    if(ipo_supported)
        message(STATUS "LTO/IPO enabled for Release builds")
        set_property(TARGET ${PROJECT_NAME} PROPERTY INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)
    else()
        message(WARNING "LTO/IPO is not supported: ${error}")
    endif()
endif()


target_compile_options(${PROJECT_NAME} PRIVATE
    -march=native -mtune=native

# ── Debug ───────────────────────────────────────────────────────────────
    $<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:GNU,Clang>>:
        -O1 -g -ggdb
        -Wall -Wextra -Wuninitialized -Wformat -Wformat-security -Wno-unused
        -Werror
    >

# ── Release ─────────────────────────────────────────────────────────────
    $<$<AND:$<CONFIG:Release>,$<CXX_COMPILER_ID:GNU,Clang>>:>
)

# Strip symbols in Release mode on Linux/GCC/Clang
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND $<$<CONFIG:Release>:${CMAKE_STRIP}> $<$<CONFIG:Release>:$<TARGET_FILE:${PROJECT_NAME}>>
    COMMENT "$<$<CONFIG:Release>:With stripping>"
)


# ── Linker: mold (if available) ─────────────────────────────────────────
find_program(MOLD_LINKER NAMES ld.mold mold)
if(MOLD_LINKER)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=mold")
endif()
