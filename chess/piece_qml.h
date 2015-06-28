#ifndef BISHOP_WHITE_QML_H
#define BISHOP_WHITE_QML_H

#include <QObject>
#include <QThread>
#include "piece.h"

class PieceQml : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString source READ getSource WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(int x READ getX WRITE setX NOTIFY xChanged)
    Q_PROPERTY(int y READ getY WRITE setY NOTIFY yChanged)

public:
    explicit PieceQml(QObject* parent = 0);
    int m_nX;
    int m_nY;
    QString m_strSource;

    QString getSource();
    void setSource(const QString& strSource);
    int getX() const;
    void setX(const int pos);
    int getY() const;
    void setY(const int pos);

signals:
    void xChanged();
    void yChanged();
    void sourceChanged();

};

#endif // BISHOP_WHITE_QML_H
