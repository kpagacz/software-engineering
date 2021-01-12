#ifndef BOARD_TP
#define BOARD_TP

#include <iostream>

template <typename T>
class Plansza
{
public:
	Plansza(int width, int height);
	~Plansza();

	void print(std::ostream&);
	void wstaw(int x, int y, T* elem);
	void usun(int x, int y);
	bool sprawdz(symbole::Kolko)
private:
	T*** board;
	int width, height;
	T*& get_position(int x, int y);
	enum symbole
	{
		Kolko*,
		Krzyzyk*
	};
};


template<class T>
inline Plansza<T>::Plansza(int _width, int _height)
{
	width = _width;
	height = _height;
	board = new T * *[height];

	for (int i = 0; i < height; i++) {
		board[i] = new T * [width];
		for (int j = 0; j < width; j++) board[i][j] = nullptr;
	}
}

template<typename T>
inline Plansza<T>::~Plansza()
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) delete board[i][j];
		delete[] board[i];
	}

	delete[] board;
}

template<typename T>
inline void Plansza<T>::print(std::ostream& out)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (board[i][j]) out << *board[i][j]; else out << ".";
			out << " ";
		}
		out << "\n";
	}
	out << "\n";
}

template<typename T>
inline void Plansza<T>::wstaw(int x, int y, T* elem)
{
	delete get_position(x, y);
	get_position(x, y) = elem;
}

template<typename T>
inline void Plansza<T>::usun(int x, int y)
{
	delete get_position(x, y);
	get_position(x, y) = nullptr;
}

template<typename T>
inline T*& Plansza<T>::get_position(int x, int y)
{
	return board[x][y];
}

#endif // Plansza