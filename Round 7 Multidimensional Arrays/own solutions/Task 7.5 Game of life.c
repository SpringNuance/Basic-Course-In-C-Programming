#include "gameoflife.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Exercise a: Allocates needed memory for the GameArea structure and
 * the actual game area. 'x_size' and 'y_size' indicate the horizontal and
 * vertical dimensions of the GameArea.
 *
 * Returns: pointer to the GameArea structure allocated by this function.
 */
GameArea *createGameArea(unsigned int x_size, unsigned int y_size) {
    GameArea* game = malloc(sizeof(GameArea));
    game -> cells = calloc(y_size, sizeof(CellStatus *));
	for (unsigned int i = 0; i < y_size; i++) {
        game -> cells[i] = calloc(x_size, sizeof(CellStatus));
    }
    for (unsigned int i = 0; i < y_size; i++) {
        for (unsigned int j = 0; j < x_size; j++) {
            game -> cells[i][j] = DEAD;
        }
    }
    game -> x_size = x_size;
    game -> y_size = y_size;
	return game;
}

/* Free memory allocated for GameArea <a>.
 */
void releaseGameArea(GameArea *a) {
    for (unsigned int i = 0; i < a -> y_size; i++) {
        free(a -> cells[i]);
    }
    free(a->cells);
    free(a);
}

/* Exercise b: Initialize game GameArea by setting exactly <n> cells into
 * ALIVE CellStatus in the game GameArea <a>.
 */
void initGameArea(GameArea *a, unsigned int n) {
    unsigned int x_size = a -> x_size;
    unsigned int y_size = a -> y_size;
    CellStatus ** cells = a -> cells;
    for(unsigned int i = 0; i < n; i++) {
        int i = 0;
        int j = 0;
        
        while (cells[i][j] != DEAD) {
            i = rand() % y_size;
            j = rand() % x_size;
        }
        cells[i][j] = ALIVE;
    }

}

/* Exercise c: Output the current CellStatus of GameArea <a>.
 */
void printGameArea(const GameArea *a) {
    CellStatus ** cells = a -> cells;
    for (unsigned int i = 0; i < a -> y_size; i++) {
        for (unsigned int j = 0; j < a -> x_size; j++) {
            if (cells[i][j] == DEAD){
                printf("%c", '.');
            } else printf("%c", '*');
        }
        printf("\n");
    }
}

/* Calculates number of live neighbours around position (x,y),
 * and returns the count.
 */
unsigned int live_neighbours(const GameArea *a, unsigned int x, unsigned int y) {
  int count = 0;
  CellStatus ** cells = a -> cells;
  unsigned int x_size = a -> x_size;
  unsigned int y_size = a -> y_size;
  int xCoord = (int)x;
  int yCoord = (int)y;
  if (x < x_size && y < y_size){
    for(int i = yCoord - 1; i <= yCoord + 1; i++) {
        for(int j = xCoord - 1; j <= xCoord + 1; j++) {
            if (i == yCoord && j == xCoord){
                continue;
            }

            if (i < 0 || j < 0 || i >= (int)y_size || j >= (int)x_size) 
                continue;

            if (cells[i][j] == ALIVE) {
                count++;
            }
        }
    }
  }
  return count;
}

/* Exercise d: Advance GameArea <a> by one generation.
 */
void gameTick(GameArea *a) {
    unsigned int x_size = a -> x_size;
    unsigned int y_size = a -> y_size;
    CellStatus** oldGeneration = a -> cells;
    CellStatus** newGeneration = calloc(y_size, sizeof(CellStatus*));
    for (unsigned int i = 0; i < y_size; i++) {
        newGeneration[i] = calloc(x_size, sizeof(CellStatus));
    }
    for(unsigned int i = 0; i < y_size; i++) {
        for(unsigned int j = 0; j < x_size; j++) {
            int liveCount = live_neighbours(a, j, i);
            if (oldGeneration[i][j] == ALIVE) {
                if (liveCount <= 1 || liveCount >= 4) newGeneration[i][j] = DEAD;
                if (liveCount >= 2 && liveCount <= 3) newGeneration[i][j] = ALIVE;
            } 
            if (oldGeneration[i][j] == DEAD) {
                if (liveCount == 3) newGeneration[i][j] = ALIVE;
                   else newGeneration[i][j] = DEAD;
            }
        }
    }
    for (unsigned int i = 0; i < y_size; i++) {
        free(oldGeneration[i]);
    }
    free(oldGeneration);
    a -> cells = newGeneration;
}
