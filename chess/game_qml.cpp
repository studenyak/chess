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

    if(nIndex/8 == 1)
        return QString("img/" + str + ".png");
    if(nIndex == 0 || nIndex == 7)
        return QString("img/rook_black.png");
    if(nIndex == 1 || nIndex == 6)
        return QString("img/knight_black.png");
    if(nIndex == 2 || nIndex == 5)
        return QString("img/bishop_black.png");
    if(nIndex == 3)
        return QString("img/queen_black.png");
    if(nIndex == 4)
        return QString("img/king_black.png");

    if(nIndex/8 == 6)
        return QString("img/pawn_white.png");
    if(nIndex == 56 || nIndex == 63)
        return QString("img/rook_white.png");
    if(nIndex == 57 || nIndex == 62)
        return QString("img/knight_white.png");
    if(nIndex == 58 || nIndex == 61)
        return QString("img/bishop_white.png");
    if(nIndex == 59)
        return QString("img/queen_white.png");
    if(nIndex == 60)
        return QString("img/king_white.png");
    return QString("");
}

QObject *GameQml::getPiece(unsigned int nIndex)
{

}

