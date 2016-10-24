find_package(mbed REQUIRED)

add_executable(blink_NUCLEO_L432KC main.cpp)
target_compile_options(blink_NUCLEO_L432KC
	PRIVATE
		-fno-exceptions -fno-rtti
)

target_link_libraries(blink_NUCLEO_L432KC mbed::mbed)

enable_binary_generation(blink_NUCLEO_L432KC)
add_flash_target(blink_NUCLEO_L432KC)
