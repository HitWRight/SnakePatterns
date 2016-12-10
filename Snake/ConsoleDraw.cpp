#include "ConsoleDraw.h"
#include "Settings.h"
#include <vector>

using namespace std;

ConsoleDraw::Console::Console(int height, int width) : m_height(height), m_width(width)
{
	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(info);
	info.dwFontSize.X = 16;
	info.dwFontSize.Y = 12; // leave X as zero
	info.FontWeight = FW_NORMAL;
	wcscpy_s(info.FaceName, L"CONSOLAS");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
	MoveWindow(GetConsoleWindow(), posX, posY, windowX, windowY, TRUE);
}

void ConsoleDraw::Console::Draw(Vec2d const & pos, char const & symbol)
{
	//Initialize the coordinates
	COORD coord = { pos.x, pos.y }; //Static cast unable to work
									//Set the position
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << symbol;
}

void ConsoleDraw::Console::Draw(std::string const & text)
{
	cout << text;
	return;
}

void ConsoleDraw::Console::Draw(Vec2d const & pos, std::string const & text)
{
	COORD coord = { pos.x,pos.y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	Draw(text);
}

void ConsoleDraw::Console::Erase(Vec2d const & pos)
{
	Draw(pos, ' ');
}

void ConsoleDraw::Console::ClearConsole()
{
	for (short int i = 0; i < 25; ++i)
		for (short int j = 0; j < 25; ++j)
			Draw({ i,j }, ' ');
}

std::string ConsoleDraw::Console::ReadBuffer()
{
	PCHAR_INFO buffer = new CHAR_INFO[m_height*m_width];

	HANDLE     hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD      buffer_size = { m_width, m_height };
	COORD      buffer_index = { 0, 0 };  // read/write rectangle has upper-right corner at upper-right corner of buffer
	SMALL_RECT read_rect = { 0,     0, m_width - 1, m_height - 1 };

	ReadConsoleOutput(hStdOut, buffer, buffer_size, buffer_index, &read_rect);

	std::string result = [&]() {
		std::string r = "";
		for (int i=0; i<m_height*m_width; i++)
		{
			r.append(1, buffer[i].Char.AsciiChar);
		}
		return r;
	}();

	delete[] buffer;

	return result;
}

void ConsoleDraw::Console::WriteBuffer(std::string data)
{
	PCHAR_INFO buffer = new CHAR_INFO[m_height*m_width];

	HANDLE     hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD      buffer_size = { m_width, m_height };
	COORD      buffer_index = { 0, 0 };  // read/write rectangle has upper-right corner at upper-right corner of buffer
	SMALL_RECT read_rect = { 0,     0, m_width - 1, m_height - 1 };

	for (int i = 0; i<m_height*m_width; i++)
	{
		buffer[i].Attributes = 7; //ascii encoding
		buffer[i].Char.AsciiChar = data[i];
		buffer[i].Char.UnicodeChar = data[i];
	}

	WriteConsoleOutput(hStdOut, buffer, buffer_size, buffer_index, &read_rect);

    delete[] buffer;
}


