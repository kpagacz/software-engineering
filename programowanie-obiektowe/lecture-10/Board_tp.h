#ifndef BOARD_TP
#define BOARD_TP

#include <iostream>

template <typename T> class Board_tp;
template <typename T> std::ostream& operator<<(std::ostream& out, const Board_tp<T>& board);

template <typename T>
class Board_tp
{
public:
	Board_tp(int width, int height);
	~Board_tp();

	friend std::ostream& operator<< <T>(std::ostream& out, const Board_tp<T>& board);
	T*& get_position(int x, int y);
	T*& get_position(std::pair<int, int>);
private:
	T* **board;
	int width, height;
};


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
std::ostream& operator<<(std::ostream& out, const Board_tp<T>& board)
{
	for (int i = 0; i < board.height; i++) {
		for (int j = 0; j < board.width; j++) {
			if (board.board[i][j]) out << *board.board[i][j]; else out << ".";
			out << " ";
		}
		out << "\n";
	}
	return out;
}

template<typename T>
inline T*& Board_tp<T>::get_position(int x, int y)
{
	return board[x][y];
}

template<typename T>
inline T*& Board_tp<T>::get_position(std::pair<int, int> coords) {
	return get_position(coords.first, coords.second);
}

#endif // BOARD_TP