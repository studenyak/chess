#ifndef GAME_QML_H
#define GAME_QML_H

#include "game.h"
#include "piece_qml.h"
#include <QObject>
#include <QMap>

class GameQml : public QObject
{
    Q_OBJECT
public:
    explicit GameQml(QObject* parent = 0);
    virtual ~GameQml();

    Q_INVOKABLE
    void start();

    Q_INVOKABLE
    void load();

    Q_INVOKABLE
    bool movePiece(unsigned int fromIndex, unsigned toIndex);

    Q_INVOKABLE
    QString getImage(unsigned int nIndex);

private:
    chess::Game m_Game;
    QMap<unsigned int, QObject*> m_PiecePool;
    QObject *object;
    const char *indexToAddr(unsigned int nIndex, std::string &strAddr);

public slots:
    QObject* getPiece(unsigned int nIndex);
};

#endif // GAME_QML_H
