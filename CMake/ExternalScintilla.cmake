# Build a local version
INCLUDE(ExternalProject)

SET(scintilla331_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/scintilla331)

SET(scintilla331_CMAKE_ARGS
    -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR> 
    -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
	-DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}
    -DCMAKE_OSX_ARCHITECTURES=${CMAKE_OSX_ARCHITECTURES}
    -DCMAKE_DEBUG_POSTFIX=d
)

ExternalProject_Add(scintilla331
    PREFIX ${scintilla331_PREFIX}

    DOWNLOAD_DIR ${POLYCODE_DEPS_DOWNLOAD_DIR}

    URL http://downloads.sourceforge.net/scintilla/scintilla331.zip
    URL_MD5 3bf66b74e15a4b87dffc010064d37e29

    PATCH_COMMAND ${CMAKE_COMMAND} -E copy_if_different ${PolycodeDependencies_SOURCE_DIR}/../CMake/scintilla331.cmake <SOURCE_DIR>/CMakeLists.txt

    INSTALL_DIR ${POLYCODE_DEPS_CORE_PREFIX}
    CMAKE_ARGS ${scintilla331_CMAKE_ARGS}
)