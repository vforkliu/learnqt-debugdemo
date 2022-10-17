set(MODULE_NAME "XUIKit")
set(FOLDER_PLUGIN_QML_URI "com.xkit.ui")
set(FOLDER_PLUGIN_QML_PLUGIN ${MODULE_NAME})
string(REPLACE "." "/" PLUGIN_INSTALL_DIR_SUFFIX ${FOLDER_PLUGIN_QML_URI})
set(FOLDER_PLUGIN_BUILD_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib/${MODULE_NAME}/${PLUGIN_INSTALL_DIR_SUFFIX})
add_library(${MODULE_NAME}
    SHARED
    xuikit_plugin.cpp
    tomitem.cpp
    fileutils.cpp
    xuikit.qrc
    )

set_target_properties(${MODULE_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${FOLDER_PLUGIN_BUILD_OUTPUT_PATH})
set_target_properties(${MODULE_NAME} PROPERTIES VERSION "0.0.1" SOVERSION 1)

target_link_libraries(${MODULE_NAME} PRIVATE
        Qt5::Qml
        Qt5::Core
        Qt5::Quick
        Qt5::QuickControls2
        )

set(QML_INSTALL_DIR /usr/${KDE_INSTALL_QMLDIR})
set(PLUGIN_INSTALL_DIR ${QML_INSTALL_DIR}/${PLUGIN_INSTALL_DIR_SUFFIX})

install(TARGETS ${MODULE_NAME} LIBRARY DESTINATION ${PLUGIN_INSTALL_DIR})
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/qml/ DESTINATION ${PLUGIN_INSTALL_DIR}/qml)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/qmldir DESTINATION ${PLUGIN_INSTALL_DIR})

# COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/qml ${FOLDER_PLUGIN_BUILD_OUTPUT_PATH}/qml
#if (BUILD_FOLDER_PLUGIN_EXAMPLE)
#    set(COPY_TARGET_NAME ${MODULE_NAME}CopyTarget)
#    add_custom_target(${COPY_TARGET_NAME}
#            DEPENDS ${MODULE_NAME}
#            COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/qmldir ${CMAKE_BINARY_DIR}/lib/xuikit/com/xkit/ui/qmldir
#            )
#endif ()

add_custom_target(copy_to_lib_filebrowsing
    ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/lib/XUIKit/com/xkit/ui/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/qmldir ${CMAKE_BINARY_DIR}/lib/XUIKit/com/xkit/ui/
    DEPENDS ${MODULE_NAME}
)
