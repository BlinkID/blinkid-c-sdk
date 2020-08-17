cmake_minimum_required( VERSION 3.6 )

project( JNI )

set( SRC_PATH ${CMAKE_CURRENT_LIST_DIR}/src/main/jni )

add_library( jni SHARED ${SRC_PATH}/jni.c )

set( rec_api_path ${CMAKE_CURRENT_LIST_DIR}/../../../../ )

add_library( RecognizerAPI SHARED IMPORTED )
set_target_properties( RecognizerAPI PROPERTIES
        IMPORTED_LOCATION "${rec_api_path}/lib/Android/${ANDROID_ABI}/libRecognizerApi.so"
        INTERFACE_INCLUDE_DIRECTORIES "${rec_api_path}/include"
)

target_link_libraries( jni PRIVATE RecognizerAPI jnigraphics )