#ifndef __TETROMINO_H
#define __TETROMINO_H
#include <iostream>
#include <cstdio>

// Abstract base class
class Tetromino {
	public:
		virtual void rotate()=0;
		int xpos;
		int ypos;
};

// Tetrominos with bounding square 4^2
class Tetro_4 : public Tetromino {
	// Accessible by derived classes
	protected:
		static const int bound_height = 4;
		static const int bound_width = 4;
		int square[bound_height][bound_width];
	public:
		// The top left corner of the bounding square
		int xpos, ypos;
		void print(void);
		Tetro_4();
		~Tetro_4();

};

// "I"
class Tetro_I : public Tetro_4 {
	private:
		int current_pos;
	public:
		Tetro_I();
		void rotate(void);
		~Tetro_I();
};

// "O"
class Tetro_O : public Tetro_4 {
	private:
		int current_pos;
	public:
		Tetro_O();
		void rotate(void);
		~Tetro_O();
};

#endif
