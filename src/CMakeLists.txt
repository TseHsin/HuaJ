AUX_SOURCE_DIRECTORY(. SRC_LIST)
SET(LIB_LIST ${PROJECT_SOURCE_DIR}/lib/gl3w.c ${PROJECT_SOURCE_DIR}/lib/LoadShaders.cpp)
SET(LIB_HEAD_LIST ${PROJECT_SOURCE_DIR}/include/GL3/gl3w.h ${PROJECT_SOURCE_DIR}/include/LoadShaders.h)
SET(HEAD_LIST
        "drawobject.h"
        "transform.h"
        "quaternion.h"
        "drawManage.h"
        "gl_window.h"
        "matrix4.h"
        "vector3.h"
        "guid.h"
        "singleton.h"
        "targetver.h"
        )
#MESSAGE(STATUS ${PROJECT_SOURCE_DIR})
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/include/GL ${PROJECT_SOURCE_DIR}/include/GL3
        /usr/include)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib /usr/lib)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
ADD_EXECUTABLE(huaj ${LIB_LIST} ${LIB_HEAD_LIST} ${SRC_LIST} ${HEAD_LIST})
TARGET_LINK_LIBRARIES(huaj -lglfw3 -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor -lGLU -lGL -lglut -lCg -lCgGL -lrt -lpthread -lm -ldl)

