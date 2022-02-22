// https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/?ref=lbp

#include <bits/stdc++.h>
using namespace std;

#define N 8

int isNextPositionSafe(int xFuturePosition,int yFuturePosition, int futureVisitAt[N][N]) {
  // -1 implies that the position was never visited as the value never changed.

  return ( xFuturePosition >= 0 && xFuturePosition < N && yFuturePosition >= 0 && yFuturePosition < N && futureVisitAt[xFuturePosition][yFuturePosition] == -1)
}

int solveKnightPathProblem(int Xposition, int Yposition, int knightPath[N][N], int knightPositionNo, int knightMoveX[N], int knightMoveY[N]) {
  int nextKnightPositionX, nextKnightPositionY;

  if(knightPositionNo == N * N) return 1;

  for(int k=0; k < N; k++) {
    // setting next coordinates on 8 by 8 chessboard
    nextKnightPositionX = Xposition + knightMoveX[k];
    nextKnightPositionY = Yposition + knightMoveY[k];

    // if the position is not safe, it'll loop for k times, 0 through 8, and if still no move is possible, [checking through knightMoveX, knightMoveY] then this is the last point, and it will return 0; 
    // It won't go inside below if statement.
    if(isNextPositionSafe(nextKnightPositionX, nextKnightPositionY, knightPositionNo)) {

      //this will replace -1 with the visited value
      knightPath[nextKnightPositionX, nextKnightPositionY] = knightPositionNo;

      //recursively it will check the positions with next x and y coordinates and will also check if the position is safe or not.
      if(solveKnightPathProblem(nextKnightPositionX, nextKnightPositionY, knightPositionNo + 1, knightPath, knightMoveX, knightMoveY) == 1) 
      return 1;
      else {
        // if the next position doesn't exist or unsafe, this function will return 0, as described at line 23.
        // then it will come into THIS block, ie else block;
        // the next position is then set to -1 [unvisited].
        knightPath[nextKnightPositionX, nextKnightPositionY] = -1;
      }
    }
    return 0;
  }
}

void printKnightTourSolution(int fullKnightPath[N][N]) {
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++)
      cout << " " << setw(2) << fullKnightPath[i][j] << " ";
    cout << endl;
  }
}

int solveKnightPath(){

  //this is the static chess board. 
  int knightPath[N][N];

  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      allPaths[i][j] = -1;
    }
  }

  int knightMoveX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
  int knightMoveY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

  knightPath[0][0] = 0;

  if(solveKnightPathProblem(0, 0, 1, knightPath, knightMoveX, knightMoveY) == 0) {
    cout << "Solution doesn't exist because it has returned 0" << endl;
  } else {
    printKnightTourSolution(knightPath);
  }
};

int main() {
  solveKnightPath();
  return 0;
}






















