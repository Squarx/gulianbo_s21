QT       += core gui widgets opengl openglwidgets concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 -lGLU -lglm -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -lGLEW

include(QtGifImage/src/gifimage/qtgifimage.pri)
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../backend/facade/facade.cc \
    ../backend/figure/figure.cc \
    ../backend/file_reader/file_reader.cc \
    ../backend/normalization_parameters/norm_params.cc \
    ../backend/qt_draw_scene/qt_draw_scene.cc \
    ../backend/qt_draw_scene/set_color.cc \
    ../backend/scene/scene.cc \
    ../backend/strategy/facets_parcer.cc \
    ../backend/strategy/vertex_parser.cc \
    ../backend/vertex/vertex.cc \
    ../controller/controller.cc \
    actions/buttons.cc \
    actions/change_evets.cc \
    ../main.cc \
    front.cc \
    open_file/open_file.cc \
    settings/settings.cc

HEADERS += \
    ../backend/edge/edge.h \
    ../backend/facade/facade.h \
    ../backend/facade_operations/facade_operation_result.h \
    ../backend/figure/figure.h \
    ../backend/file_reader/base_filereader.h \
    ../backend/file_reader/file_reader.h \
    ../backend/normalization_parameters/norm_params.h \
    ../backend/qt_draw_scene/base_scene_drawer.h \
    ../backend/qt_draw_scene/qt_draw_scene.h \
    ../backend/scene/scene.h \
    ../backend/solver/solver_strategy.h \
    ../backend/strategy/abstract_parcer.h \
    ../backend/strategy/facets_parcer.h \
    ../backend/strategy/vertex_parser.h \
    ../backend/vertex/vertex.h \
    ../controller/controller.h \
    ../internal/internal.h \
    front.h

FORMS += \
    front.ui
    
ICON = radem.icns
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../objects/cube.obj
