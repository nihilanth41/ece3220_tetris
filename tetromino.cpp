#include <iostream>
#include <cstdio>

// Abstract base class
class Tetromino {
	public:
		virtual void rotate()=0;
};

// Tetrominos with bounding square 4^2
class Tetro_4 : public Tetromino {
	// Accessible by derived classes
	protected:
		static const int bound_height = 4;
		static const int bound_width = 4;
		int square[bound_height][bound_width];
	public:
		void print(void);
		Tetro_4();
		~Tetro_4();

};

void Tetro_4::print(void) {
	for(int j=bound_height; j--;)
	{
		printf("[");
		for(int i=0; i<bound_width; i++)
		{
			printf(" %d ", square[j][i]);
		}
		printf("]\n");
	}
	printf("\n");
}

Tetro_4::Tetro_4() {
	//Initialize to 0;
	for(int j=bound_height; j--;)
	{
		for(int i=0; i<bound_width; i++)
		{
			square[j][i] = 0;
		}
	}
}

Tetro_4::~Tetro_4() {
}

// "I"
class Tetro_I : public Tetro_4 {
	private:
		int current_pos;
	public:
		Tetro_I();
		void rotate(void);
		~Tetro_I();
};

Tetro_I::Tetro_I() {
	// Vertical position 
	current_pos = 1;
	square[bound_height-1][bound_width-2] = 1;
	square[bound_height-2][bound_width-2] = 1;
	square[bound_height-3][bound_width-2] = 1;
	square[bound_height-4][bound_width-2] = 1;
}
Tetro_I::~Tetro_I() {
}

void Tetro_I::rotate(void) {
	if(current_pos == 1)
	{
		current_pos = 2;
		// Zero out old positions
		square[bound_height-1][bound_width-2] = 0;
		square[bound_height-2][bound_width-2] = 0;
		square[bound_height-4][bound_width-2] = 0;
		// Set new positions
		square[bound_height-3][bound_width-4] = 1;
		square[bound_height-3][bound_width-3] = 1;
		square[bound_height-3][bound_width-1] = 1;
	}
	else if(current_pos == 2)
	{
		current_pos = 1;
		// Zero out old positions
		square[bound_height-3][bound_width-4] = 0;
		square[bound_height-3][bound_width-3] = 0;
		square[bound_height-3][bound_width-1] = 0;
		// Set new positions
		square[bound_height-1][bound_width-2] = 1;
		square[bound_height-2][bound_width-2] = 1;
		square[bound_height-4][bound_width-2] = 1;
	}
		
}

// "O"
class Tetro_O : public Tetro_4 {
	private:
		int current_pos;
	public:
		Tetro_O();
		void rotate(void);
		~Tetro_O();
};

void Tetro_O::rotate() {
	// "O" is the only tetromino that doesn't rotate
	// Can still use this to, e.g. play a rotation sound
}

Tetro_O::Tetro_O() {
	current_pos = 1;
	square[2][2] = 1; 
	square[2][1] = 1;
	square[1][2] = 1;
	square[1][1] = 1;
}

Tetro_O::~Tetro_O() {
}



int main(void) {

//	Tetro_I t = Tetro_I();
//	t.print();
//	t.rotate();
//	t.print();
	Tetro_I t = Tetro_I();
	t.print();
	t.rotate();
	t.print();

	Tetro_O o = Tetro_O();
	o.print();
	o.rotate();
	o.print();


	return 0;
}


