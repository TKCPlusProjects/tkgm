set(DEMO_NAME demo)

if(EXISTS ${CMAKE_CURRENT_BINARY_DIR}/modules)
  file(REMOVE_RECURSE ${CMAKE_CURRENT_BINARY_DIR}/modules)
endif()
file(COPY ../modules DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# add executable
file(GLOB_RECURSE PROJECT_DEMO_SRC_LIST ./*.cpp)
add_executable(${DEMO_NAME} ${PROJECT_DEMO_SRC_LIST})

# compile features
target_compile_features(${DEMO_NAME} 
  PUBLIC cxx_std_17
)
# compile options
if (MSVC)
  target_compile_options(${DEMO_NAME} 
    PUBLIC /utf-8
  )
  target_compile_options(${DEMO_NAME} 
    PUBLIC /EHsc
  )
endif()

# link dependencies
target_link_libraries(${DEMO_NAME} ${PROJECT_NAME})
