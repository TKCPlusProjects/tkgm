add_library(
  ${PROJECT_NAME} STATIC
  ${PROJECT_BASE_INCLUDE_LIST}
  ${PROJECT_BASE_SRC_LIST}
)

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
)

target_include_directories(
    ${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${PROJECT_BASE_INCLUDE}>
    $<INSTALL_INTERFACE:include>
)

find_package(nlohmann_json CONFIG REQUIRED)
find_package(imgui REQUIRED)
find_package(tkcore CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME}
  nlohmann_json::nlohmann_json
  imgui::imgui
  tkcore::tkcore)