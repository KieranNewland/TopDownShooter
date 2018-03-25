#include "Screen.h"

int Screen::m_nScreenWidth;
int Screen::m_nScreenHeight;

void Screen::Init(const int nWidth, const int nHeight)
{
	m_nScreenWidth = nWidth;
	m_nScreenHeight = nHeight;
}