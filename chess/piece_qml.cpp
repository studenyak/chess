#include "piece_qml.h"

PieceQml::PieceQml(QObject *parent)
{
}

QString PieceQml::getSource()
{
    return QString("img/bishop_white.png");
}

int PieceQml::getX() const
{
    return m_nX;
}

void PieceQml::setX(const int xPos)
{
    m_nX = xPos;
    emit xChanged();
}

void PieceQml::setSource(const QString& str)
{
    m_strSource = str;
    emit sourceChanged();
}

int PieceQml::getY() const
{
    return m_nY;
}

void PieceQml::setY(const int yPos)
{
    m_nY = yPos;
    emit yChanged();
}
