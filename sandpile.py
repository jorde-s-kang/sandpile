import matplotlib.pyplot as plt
import sys
import numpy as np


def step(grid):
    cols = grid.shape[0]
    rows = cols = grid.shape[1]
    for x in range(0, cols-1):
        for y in range(0, rows-1):
            if grid[x][y] > 3:
                grid[x][y] = grid[x][y] - 4
                grid[x-1][y] += 1
                grid[x+1][y] += 1
                grid[x][y+1] += 1
                grid[x][y-1] += 1
            
def main(n):
    grid = np.zeros((1000,1000))
    grid[500][500] = 10000
    last_hash = None
    for i in range(n):
        # print(f"Iterating... {i}/{n}", end='\r')
        step(grid)
    # plt.imshow(grid, cmap="inferno")
    # plt.show()
    
if __name__ == "__main__":
    main(int(sys.argv[1]))
