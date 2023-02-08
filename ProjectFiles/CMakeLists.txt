add_executable(philosophers
        main.c
)

target_link_libraries(philosophers pico_stdlib freertos)
pico_add_extra_outputs(philosophers)
