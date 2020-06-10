cmake_minimum_required(VERSION 3.5)
project(cfg)

add_executable(${PROJECT_NAME}
    configure.c
    memory.c
    ptr_lists.c
	misc.c
	errors.c
	main.c
)

target_compile_options(${PROJECT_NAME} PRIVATE "-Wall" "-Wextra" "-g" "-D_DEBUGGING" )
