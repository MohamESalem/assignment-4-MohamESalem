project(Code_lib)

set(HEADER_FILES
        BST.h
        Dictionary.h
)

set(SOURCE_FILES
        BST.cpp
        Dictionary.cpp
)

add_library(Code_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})