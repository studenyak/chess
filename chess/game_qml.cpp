#include <QVariant>
#include <QQmlEngine>
#include <QQmlApplicationEngine>
#include <QFile>
#include <QTextStream>
#include <QMetaObject>
#include <QChar>
#include <QDebug>
#include <QUrl>

#include "game_qml.h"

GameQml::GameQml(QObject *parent)
    : m_nCurrentMoveQueueStep(0)
    , m_bWhitePlayer(true)
    , m_bSwitchFlag(false)
{
}

GameQml::~GameQml()
{
}

void GameQml::start()
{
    m_Game.start();
}

void GameQml::load(QString strUrlFileName)
{
    QUrl strUrl(strUrlFileName);
    QFile file(strUrl.toLocalFile());
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        while (!in.atEnd())
            m_rMovesQueue.enqueue(in.readLine());
        file.close();
    }
    else
        qDebug() << "Unable to load file";
}

bool GameQml::movePiece(unsigned int fromIndex, unsigned toIndex)
{
    std::string strfromIndex;
    indexToAddr(fromIndex, strfromIndex);

    std::string strToIndex;
    indexToAddr(toIndex, strToIndex);

    if( m_Game.movePiece(strfromIndex.c_str(), strToIndex.c_str(), m_bWhitePlayer) )
    {
        QString str;
        QTextStream stream(&str);
        stream << fromIndex << "," << toIndex;
        m_wMovesQueue.enqueue(stream.readAll());

        QMetaObject::invokeMethod(m_RootObject, "movePiece",
                                  Q_ARG(QVariant, QVariant(fromIndex)),
                                  Q_ARG(QVariant, QVariant(toIndex)));
        m_bWhitePlayer ^= true;
        return true;
    }
    return false;
}

QString GameQml::getImage(unsigned int nIndex)
{
    chess::Board& board = m_Game.getBoard();
    const char* piece_name = board.getPieceName(nIndex);
    QString str(piece_name);
    if(!str.isEmpty())
        return QString("img/" + str + ".png");
    return QString("");
}

void GameQml::save(QString strUrlFileName)
{
    QUrl strUrl(strUrlFileName);
    QFile file(strUrl.toLocalFile());
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        while(!m_wMovesQueue.isEmpty())
            out << m_wMovesQueue.dequeue() << "\n";
        file.close();
    }
    else
        qDebug() << "Unable to open file " << strUrl.toLocalFile();
}

void GameQml::stop()
{
    m_Game.stop();
}

void GameQml::prev()
{
    qDebug() << m_nCurrentMoveQueueStep;

    if(m_rMovesQueue.size() == 0)
        return;
    if(m_nCurrentMoveQueueStep > m_rMovesQueue.size())
        return;

    if(!m_bSwitchFlag)
    {
        m_nCurrentMoveQueueStep--;
        m_bSwitchFlag = true;
        m_bWhitePlayer ^= 1;
    }

    QString strMove = m_rMovesQueue.at(m_nCurrentMoveQueueStep);
    QStringList list = strMove.split(",");
    qDebug() << list[1] << "," << list[0];

    qDebug() << "White Player: " << m_bWhitePlayer;
    if(movePiece(list[1].toInt(), list[0].toInt()))
    {
        if(m_nCurrentMoveQueueStep > 0)
            m_nCurrentMoveQueueStep--;
    }

    qDebug() << "m_nCurrentMoveQueueSte =: " << m_nCurrentMoveQueueStep;
}

void GameQml::next()
{
    if(m_rMovesQueue.size() == 0)
        return;
    if(m_nCurrentMoveQueueStep >= m_rMovesQueue.size())
        return;

    if(m_bSwitchFlag)
    {
        m_bSwitchFlag = false;
        m_bWhitePlayer ^= 1;
    }

    qDebug() << "White Player: " << m_bWhitePlayer;
    QString strMove = m_rMovesQueue.at(m_nCurrentMoveQueueStep);
    QStringList list = strMove.split(",");
    qDebug() << list[0] << "," << list[1];
    if( movePiece(list[0].toInt(),list[1].toInt()))
    {
        if(m_nCurrentMoveQueueStep < m_rMovesQueue.size())
            m_nCurrentMoveQueueStep++;
    }

    qDebug() << m_nCurrentMoveQueueStep;
}

const char *GameQml::indexToAddr(unsigned int nIndex, std::string& strAddr)
{
    char letter[3] = {'a' + nIndex % 8, '8' - nIndex / 8};
    strAddr = letter;

    return strAddr.c_str();
}

int GameQml::addrToIndex(QString& str)
{
    qDebug() << str;
    if(str.isEmpty())
        return -1;

    qDebug() << (char)str.at(1).toLatin1() << " : " << (char)str.at(0).toLatin1();
    qDebug() << '8' - (char)str.at(1).toLatin1() << " : " << (char)str.at(0).toLatin1() - 'a';

    unsigned int index = ('8' - (char)str.at(1).toLatin1()) * 7 + ((char)str.at(0).toLatin1() - 'a');
    qDebug() << str << " to " << index;
    return index;
}

void GameQml::setParent(QObject *obj)
{
    m_RootObject = obj;
}

