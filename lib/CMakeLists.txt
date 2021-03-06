find_program(DPKG_BUILDFLAGS dpkg-buildflags)

if (DPKG_BUILDFLAGS)
  message(STATUS "dpkg-buildflags available, adjusting compiler flags.")
  execute_process(
    COMMAND ${DPKG_BUILDFLAGS} "--get" "CFLAGS"
    OUTPUT_VARIABLE DPKG_BUILDFLAGS_CFLAGS
    OUTPUT_STRIP_TRAILING_WHITESPACE
    )

  execute_process(
    COMMAND ${DPKG_BUILDFLAGS} "--get" "CPPFLAGS"
    OUTPUT_VARIABLE DPKG_BUILDFLAGS_CPPFLAGS
    OUTPUT_STRIP_TRAILING_WHITESPACE
    )

  execute_process(
    COMMAND ${DPKG_BUILDFLAGS} "--get" "CXXFLAGS"
    OUTPUT_VARIABLE DPKG_BUILDFLAGS_CXXFLAGS
    OUTPUT_STRIP_TRAILING_WHITESPACE
    )

  execute_process(
    COMMAND ${DPKG_BUILDFLAGS} "--get" "LDFLAGS"
    OUTPUT_VARIABLE DPKG_BUILDFLAGS_LDFLAGS
    OUTPUT_STRIP_TRAILING_WHITESPACE
    )

  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${DPKG_BUILDFLAGS_CFLAGS}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${DPKG_BUILDFLAGS_CXXFLAGS}")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} \
${DPKG_BUILDFLAGS_LDFLAGS}")
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} \
${DPKG_BUILDFLAGS_LDFLAGS}")
  set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} \
${DPKG_BUILDFLAGS_LDFLAGS}")
  set(CMAKE_STATIC_LINKER_FLAGS "${CMAKE_STATIC_LINKER_FLAGS} \
${DPKG_BUILDFLAGS_LDFLAGS}")

  add_definitions("${DPKG_BUILDFLAGS_CPPFLAGS}")
else()
  message(STATUS "Could not find dpkg-buildflags,
 not building with packaging setup C/C++/LD-Flags.")
endif(DPKG_BUILDFLAGS)

include_directories(
    .
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_BINARY_DIR}
)

set( LIBSOURCES
    ${PROJECT_SOURCE_DIR}/src/foo.cpp
)

add_library( libfoo SHARED ${LIBSOURCES} )

set_target_properties( libfoo PROPERTIES
  COMPILE_FLAGS "-std=c++11"
  VERSION "${VERSION_MINOR}.${VERSION_PATCH}"
  SOVERSION "${VERSION_MAJOR}"
  OUTPUT_NAME foo
)

target_link_libraries( libfoo )

install( TARGETS libfoo LIBRARY DESTINATION usr/lib )
