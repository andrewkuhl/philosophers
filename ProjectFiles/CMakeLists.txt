add_executable(philosophers
        main.c
        LED.c
        LED.h
)

target_link_libraries(philosophers pico_stdlib freertos)
pico_add_extra_outputs(philosophers)
