#ifdef __GOOGLE_TEST__

    #include <gtest/gtest.h>
    int main(int argc, char *argv[])
    {
        ::testing::InitGoogleTest(&argc, argv);
         return  RUN_ALL_TESTS();
    }

#else

    #include <QGuiApplication>
    #include <QQmlApplicationEngine>
    #include <QQmlComponent>
    #include "game_qml.h"
    #include "piece_qml.h"

    int main(int argc, char *argv[])
    {
        QGuiApplication app(argc, argv);
        qmlRegisterType<GameQml>("stood.game.chess", 1, 0, "Game");
        qmlRegisterType<PieceQml>("stood.game.chess.piece", 1, 0, "Piece");

        QQmlApplicationEngine engine;
        engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

        return app.exec();
    }
#endif
