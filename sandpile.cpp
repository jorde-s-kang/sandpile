#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <fstream>


using namespace std;

#define INIT_SAND 200000
#define XLEN 1000
#define YLEN 1000

int step(int grid[][YLEN])
{
	for (int x=0; x < XLEN; x++) {
		for (int y=0; y < YLEN; y++) {
			if (grid[x][y] > 3) {
				grid[x][y] -= 4;
				if (x-1 >= 0)
					grid[x-1][y] += 1;
				if (x+1 < XLEN)
					grid[x+1][y] += 1;
				if (y-1 >= 0)
					grid[x][y-1] += 1;
				if (y+1 < YLEN)
					grid[x][y+1] += 1;
			}
		}
	}
	return 0;
}

int print_grid(int grid[][YLEN])
{
	for (int x = 0; x < XLEN; x++) {
		for (int y = 0; y < YLEN; y++) {
			cout << grid[x][y] << " ";
		}
		cout << endl;
	}

	return 0;
}

int render_image(std::string fname, int grid[][YLEN])
{
	ofstream ofs(fname, ios_base::out | ios_base::binary);
	ofs << "P6" << endl << XLEN << ' ' << YLEN << endl << "3" << endl;
	for (int x = 0; x < XLEN; x++) {
		for (int y = 0; y < YLEN; y++) {
			int val = grid[x][y];
			ofs << (char) val % 4 << (char) val % 2 << (char) val % 1;
		}
	}
	ofs.close();
	return 0;
}

int main(int argc, char *argv[])
{
	int grid[XLEN][YLEN] = {0};
	for (int x = 0; x < XLEN; x++){
		for (int y = 0; y < YLEN; y++) {
			grid[x][y] = 0;
		}
	}

	
	grid[XLEN/2][YLEN/2] = INIT_SAND;
	int n = atoi(argv[1]);
	int fnum = 0;
	for (int i = 0; i <= n; i++) {
		step(grid);

		if (i % 500 == 0){
			std::string fname;
			fname = std::to_string(fnum)+".ppm";
			render_image(fname, grid);
			fnum++;
		}
		
		cout << i << "/" << n << "\r";
	}
	render_image("out.png", grid);
}
