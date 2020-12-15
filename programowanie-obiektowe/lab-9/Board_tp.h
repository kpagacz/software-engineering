#ifndef BOARD_TP
#define BOARD_TP

#include <iostream>

template <typename T>
class Board_tp
{
public:
	Board_tp(int width, int height);
	~Board_tp();

	void print(std::ostream&);
	T*& get_position(int x, int y);
private:
	T* **board;
	int width, height;
};

#endif BOARD_TP

template<class T>
inline Board_tp<T>::Board_tp(int _width, int _height)
{
	width = _width;
	height = _height;
	board = new T * *[height];

	for (int i = 0; i < height; i++) {
		board[i] = new T*[width];
		for (int j = 0; j < width; j++) board[i][j] = nullptr;
	}
}

template<typename T>
inline Board_tp<T>::~Board_tp()
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) delete board[i][j];
		delete [] board[i];
	}

	delete [] board;
}

template<typename T>
inline void Board_tp<T>::print(std::ostream& out)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) if (board[i][j]) out << *board[i][j]; else out << ".";
		out << "\n";
	}
	out << "\n";
}

template<typename T>
inline T*& Board_tp<T>::get_position(int x, int y)
{
	return board[x][y];
}
