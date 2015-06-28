#include "game_qml.h"
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQuickView>
#include <QQmlProperty>
#include <QVariant>
#include <QQmlEngine>
#include <QQmlApplicationEngine>

GameQml::GameQml(QObject *parent)
{
}

GameQml::~GameQml()
{
}

void GameQml::start()
{
    m_Game.start();
}

void GameQml::load()
{
}

bool GameQml::movePiece(unsigned int fromIndex, unsigned toIndex)
{
    std::string strfromIndex;
    indexToAddr(fromIndex, strfromIndex);

    std::string strToIndex;
    indexToAddr(toIndex, strToIndex);
    return m_Game.movePiece(strfromIndex.c_str(), strToIndex.c_str());
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

QObject *GameQml::getPiece(unsigned int nIndex)
{

}

const char *GameQml::indexToAddr(unsigned int nIndex, std::string& strAddr)
{
    char letter[3] = {'a' + nIndex % 8, '8' - nIndex / 8};
    strAddr = letter;

    return strAddr.c_str();
}

