#include <iostream>
#include <cstdio>

// Abstract base class
class Tetromino {
	public:
		virtual void rotate()=0;
};

// "I"
class Tetro_I : public Tetromino {
	private:
		static const int bound_height = 4;
		static const int bound_width = 4;
		// Current rotation 
		int current_pos;
		int square[bound_height][bound_width];
	public:
		Tetro_I();
		virtual void rotate(void);
		void print();
		~Tetro_I();
};

Tetro_I::Tetro_I() {
	//Initialize to 0;
	for(int j=bound_height; j--;)
	{
		for(int i=0; i<bound_width; i++)
		{
			square[j][i] = 0;
		}
	}

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

void Tetro_I::print(void) {
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

int main(void) {

	Tetro_I t = Tetro_I();
	t.print();
	t.rotate();
	t.print();


	return 0;
}


