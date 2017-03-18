include(ToolCreateQtProjectZipFileConsole.pri)

SOURCES += \
    $$PWD/qtcreateqtprojectzipfilemaindialog.cpp \
    $$PWD/qtcreateqtprojectzipfilemenudialog.cpp


HEADERS  += \
    $$PWD/qtcreateqtprojectzipfilemaindialog.h \
    $$PWD/qtcreateqtprojectzipfilemenudialog.h

FORMS += \
    $$PWD/qtcreateqtprojectzipfilemaindialog.ui \
    $$PWD/qtcreateqtprojectzipfilemenudialog.ui

OTHER_FILES += \
    $$PWD/ToolCreateQtProjectZipFileDesktop.pri

RESOURCES += \
    $$PWD/ToolCreateQtProjectZipFile.qrc


