#ifndef __TETROMINO_H
#define __TETROMINO_H
#include <iostream>
#include <cstdio>

// Abstract base class
class Tetromino {
	public:
		virtual void rotate()=0;
		virtual int getxpos()=0;
		virtual int getypos()=0;
		virtual void setxpos(int)=0;
		virtual void setypos(int)=0;
		virtual int getboundheight(void)=0;
		virtual int getboundwidth(void)=0;
		virtual int getsquare(int, int)=0;
};

// Tetrominos with bounding square 4^2
class Tetro_4 : public Tetromino {
	// Accessible by derived classes
	protected:
		static const int bound_height = 4;
		static const int bound_width = 4;
		int square[bound_height][bound_width];
		int xpos, ypos;
	public:
		// The top left corner of the bounding square
		void print(void);
		int getxpos(void);
		int getypos(void);
		void setxpos(int);
		void setypos(int);
		int getboundheight(void);
		int getboundwidth(void);
		int getsquare(int, int);
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
