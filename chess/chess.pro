TEMPLATE = app

QT += qml quick

SOURCES += main.cpp \
    piece.cpp \
	test_piece.cpp \
    board.cpp \
    piece_box.cpp \
	board_filler.cpp \
    game.cpp \
    game_qml.cpp \
    test_board.cpp \
    piece_qml.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
	piece.h \
    board.h \
    piece_box.h \
    board_filler.h \
    game.h \
    game_qml.h \
    piece_qml.h

OTHER_FILES += \
    ../makefile

#CONFIG+=test
CONFIG(test, test|debug|release) {
	#This is a release build
	DEFINES += __GOOGLE_TEST__
} else {
	#This is a debug build
}
