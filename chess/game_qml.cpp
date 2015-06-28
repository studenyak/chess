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
    chess::Board& board = m_Game.getBoard();
    return board.movePiece(fromIndex, toIndex);
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

