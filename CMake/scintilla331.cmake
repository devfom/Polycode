CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(scintilla CXX)

IF(NOT CMAKE_BUILD_TYPE)
    #SET(CMAKE_BUILD_TYPE "Debug")
    SET(CMAKE_BUILD_TYPE "Release")
    MESSAGE("No CMAKE_BUILD_TYPE specified, defaulting to ${CMAKE_BUILD_TYPE}") 
ENDIF(NOT CMAKE_BUILD_TYPE)

# to distinguish between debug and release lib
SET(CMAKE_DEBUG_POSTFIX "d")

include_directories ( include src lexlib polycode )
file (GLOB SCINTILLA_SRC src/*.cxx lexlib/*.cxx lexers/*.cxx polycode/*.cxx)

IF(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions( -DSCI_LEXER=1 -DSCINTILLA_QT=1 -DSTATIC_BUILD=1 -DSCI_NAMESPACE=1 )
ENDIF(CMAKE_COMPILER_IS_GNUCXX)

# We only want a static lib
ADD_LIBRARY(scintilla ${SCINTILLA_SRC})

SET_TARGET_PROPERTIES(scintilla 
    PROPERTIES OUTPUT_NAME scintilla3.3.1)

INSTALL(TARGETS scintilla
    RUNTIME DESTINATION bin
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib)

INSTALL(FILES )

INSTALL(FILES 
    include/Platform.h
    include/Scintilla.h
    include/ILexer.h    
    DESTINATION include/scintilla331/)

INSTALL(FILES
    src/SVector.h
    src/SplitVector.h
    src/Partitioning.h
    src/RunStyles.h
    src/ContractionState.h
    src/CellBuffer.h
    src/CallTip.h
    src/KeyMap.h
    src/Indicator.h
    src/XPM.h
    src/LineMarker.h
    src/Style.h
    src/AutoComplete.h
    src/ViewStyle.h
    src/CharClassify.h
    src/Decoration.h
    src/Document.h
    src/Selection.h
    src/PositionCache.h
    src/Editor.h
    src/ScintillaBase.h
    DESTINATION include/scintilla331/)