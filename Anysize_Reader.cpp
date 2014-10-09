#include "stdafx.h"
#include "iostream"
#include "vector"
#include "string"
#include "map"
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <stack>
#include <sstream>
#include <iomanip>
#include <random>       
#include <assert.h>

using namespace std;

int block_reader(char* buf);

class CFileReader
{
public:
        CFileReader() : m_nSize(0) {}
        int anysize_reader(char *buf, int size);

private:
        char m_buf[4096];
        int m_nSize;
};

int CFileReader::anysize_reader(char *buf, int size)
{
        assert(buf && size >= 0);
        if (0 == size) return 0;

        if (size <= m_nSize)
        {
                memcpy(buf, m_buf, size);
                memcpy(m_buf, m_buf + size, m_nSize - size);
                m_nSize = m_nSize - size;

                return size;
        }

        memcpy(buf, m_buf, m_nSize);
        buf += m_nSize;
        int nLeft = size - m_nSize;
        int nOrgSize = m_nSize;

        m_nSize = block_reader(m_buf);
        if (m_nSize != 4096 && nLeft > m_nSize)
        {
                memcpy(buf, m_buf, m_nSize);
                return m_nSize + nOrgSize;
        }

        return nOrgSize + anysize_reader(buf, nLeft);
}


int _tmain(int argc, _TCHAR* argv[])
{

	return 0;
}


