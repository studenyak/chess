#ifndef GAME_QML_H
#define GAME_QML_H

#include "game.h"
#include "piece_qml.h"
#include <QObject>
#include <QMap>
#include <QQueue>

class GameQml : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject* parent WRITE setParent)

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

    Q_INVOKABLE
    void save();

    Q_INVOKABLE
    void stop();

    Q_INVOKABLE
    void prev();

    Q_INVOKABLE
    void next();

private:
    chess::Game m_Game;
    QMap<unsigned int, QObject*> m_PiecePool;
    QObject *object;
    const char *indexToAddr(unsigned int nIndex, std::string &strAddr);
    int addrToIndex(QString &str);
    QQueue<QString> m_wMovesQueue;
    QQueue<QString> m_rMovesQueue;
    void setParent(QObject* obj);
    QObject* m_RootObject;
    unsigned int m_nCurrentMoveQueueStep;
    bool m_bWhitePlayer;
    bool m_bSwitchFlag;

public slots:
    QObject* getPiece(unsigned int nIndex);
};


#endif // GAME_QML_H
