#include "pos.h"

namespace chess {

    Pos::Pos():m_nX(0), m_nY(0){}
    Pos::Pos(int x, int y):m_nX(x), m_nY(y)
    {

    }
    Pos::Pos(const std::string &strAddr)
        : m_nX(0)
        , m_nY(0)
    {
        m_strAddr = strAddr;
        const char* chPos = m_strAddr.c_str();
        m_nX = chPos[0] - 0x61;
        if(m_nX >= 8 || m_nX < 0)
            m_nX = -1;
        m_nY = chPos[1] - 0x31;
        if(m_nY >= 8 || m_nY < 0)
            m_nY = -1;
    }

    chess::Pos::operator std::string()
    {
        char chPos[3] = {0};
        if(m_nX >= 8 || m_nX < 0 || m_nY >= 8 || m_nY < 0)
            return "";

        chPos[0] = m_nX + 0x61;
        chPos[1] = m_nY + 0x31;
        m_strAddr.assign(chPos);
        return m_strAddr;
    }

    int Pos::getX()
    {
        return m_nX;
    }
    int Pos::getY()
    {
        return m_nY;
    }
}
