#ifndef POS_H
#define POS_H
#include <string>

namespace chess {

    class Pos
    {
    public:
        Pos();
        Pos(int x, int y);
        Pos(const std::string& strAddr);
        std::string toStringAddr();
        operator std::string();
        int getX();
        int getY();
    private:
        int m_nX;
        int m_nY;
        std::string m_strAddr;
    };
}
#endif // POS_H
