QT += widgets multimedia opengl

DIR_OPENCV_LIBS = /usr/local/lib
DIR_OTHER_LIBS = /usr/lib/x86_64-linux-gnu

unix:INCLUDEPATH += "/usr/include/GL/"

unix:LIBS += -L$$DIR_OPENCV_LIBS

unix:LIBS += -lopencv_core \
             -lopencv_highgui \
             -lopencv_imgproc \
             -lopencv_objdetect \
#             -lopencv_calib3d \
#             -lopencv_ml \
#             -lopencv_video \
#             -lopencv_features2d \
#             -lopencv_flann \
#             -lopencv_photo \
#             -lopencv_stitching \
#             -lopencv_superres \
#             -lopencv_video \
#             -lopencv_videostab \
#             -lopencv_imgcodecs \
              -lopencv_videoio \
#             -lopencv_bgsegm

LIBS += "$$DIR_OTHER_LIBS/libespeak.so"

SOURCES += \
    main.cpp \
    graph/graph.cpp \
    graph/node.cpp \
    graph/xmlreader.cpp \
    theme/colorizer.cpp \
    theme/theme.cpp \
    interface/block.cpp \
    interface/interface.cpp \
    processor/camera.cpp \
    interface/image.cpp \
    speech.cpp \
    interface/camerawidget.cpp

HEADERS += \
    graph/graph.hpp \
    graph/node.hpp \
    graph/xmlreader.hpp \
    theme/colorizer.hpp \
    theme/theme.hpp \
    interface/block.hpp \
    interface/interface.hpp \
    processor/camera.hpp \
    common.hpp \
    interface/image.hpp \
    speech.hpp \
    interface/camerawidget.h \
    interface/texture.h

FORMS += \
    interface/interface.ui \
    interface/block.ui
