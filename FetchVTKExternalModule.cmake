
include(FetchContent)

set(proj VTKExternalModule)
set(EP_SOURCE_DIR ${CMAKE_BINARY_DIR}/${proj})
FetchContent_Populate(${proj}
  SOURCE_DIR     ${EP_SOURCE_DIR}
  GIT_REPOSITORY git://github.com/KitwareMedical/VTKExternalModule
  GIT_TAG        3bae71e5eba073e589810a8bef947d65c90a2174
  QUIET
  )
message(STATUS "Remote - ${proj} [OK]")

set(VTKExternalModule_SOURCE_DIR ${EP_SOURCE_DIR})
message(STATUS "Remote - VTKExternalModule_SOURCE_DIR:${VTKExternalModule_SOURCE_DIR}")
