cmake_minimum_required( VERSION 2.8 )

project( foo )

set( CMAKE_INSTALL_PREFIX "/" )

set( VERSION_MAJOR 0 )
set( VERSION_MINOR 1 )
set( VERSION_PATCH 0 )
set( VERSION_FULL "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}" )

message( "MAJOR: ${VERSION_MAJOR}" )
message( "MINOR: ${VERSION_MINOR}" )
message( "PATCH: ${VERSION_PATCH}" )
message( "FULL:  ${VERSION_FULL}" )

add_subdirectory( include )
add_subdirectory( lib )

configure_file ( "${PROJECT_SOURCE_DIR}/debian/lib${CMAKE_PROJECT_NAME}${VERSION_MAJOR}.acc.in"
  "${PROJECT_SOURCE_DIR}/debian/lib${CMAKE_PROJECT_NAME}${VERSION_MAJOR}.acc"
)
