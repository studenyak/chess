#ifndef GAME_QML_H
#define GAME_QML_H

#include <QObject>
#include <QMap>
#include <QQueue>

#include "game.h"
#include "piece_qml.h"

class GameQml : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject* parent WRITE setParent)

public:
    explicit GameQml(QObject* parent = 0);
    virtual ~GameQml();

    Q_INVOKABLE
    bool movePiece(unsigned int fromIndex, unsigned toIndex);

    Q_INVOKABLE
    QString getImage(unsigned int nIndex);

    Q_INVOKABLE void start();
    Q_INVOKABLE void load(QString strFileName);
    Q_INVOKABLE void save(QString strFileName);
    Q_INVOKABLE void stop();
    Q_INVOKABLE void prev();
    Q_INVOKABLE void next();

private:
    chess::Game m_Game;
    bool m_bSwitchFlag;
    bool m_bWhitePlayer;
    QObject* m_RootObject;
    QQueue<QString> m_wMovesQueue;
    QQueue<QString> m_rMovesQueue;
    unsigned int m_nCurrentMoveQueueStep;

    const char *indexToAddr(unsigned int nIndex, std::string &strAddr);
    int addrToIndex(QString &str);
    void setParent(QObject* obj);
};


#endif // GAME_QML_H
