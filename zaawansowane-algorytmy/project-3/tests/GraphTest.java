import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;

import static org.junit.jupiter.api.Assertions.*;

class GraphTest {

    @BeforeEach
    void setUp() {
    }

    @Test
    void floydWarshall() {
        int[][] testMatrix = new int[5][5];
        testMatrix[0][0] = 0;
        testMatrix[0][1] = 3;
        testMatrix[0][2] = 8;
        testMatrix[0][3] = Integer.MAX_VALUE;
        testMatrix[0][4] = -4;
        testMatrix[1][0] = Integer.MAX_VALUE;
        testMatrix[1][1] = 0;
        testMatrix[1][2] = Integer.MAX_VALUE;
        testMatrix[1][3] = 1;
        testMatrix[1][4] = 7;
        testMatrix[2][0] = Integer.MAX_VALUE;
        testMatrix[2][1] = 4;
        testMatrix[2][2] = 0;
        testMatrix[2][3] = Integer.MAX_VALUE;
        testMatrix[2][4] = Integer.MAX_VALUE;
        testMatrix[3][0] = 2;
        testMatrix[3][1] = Integer.MAX_VALUE;
        testMatrix[3][2] = -5;
        testMatrix[3][3] = 0;
        testMatrix[3][4] = Integer.MAX_VALUE;
        testMatrix[4][0] = Integer.MAX_VALUE;
        testMatrix[4][1] = Integer.MAX_VALUE;
        testMatrix[4][2] = Integer.MAX_VALUE;
        testMatrix[4][3] = 6;
        testMatrix[4][4] = 0;

        for(int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                System.out.print(testMatrix[i][j] + " ");
            }
            System.out.println();
        }

        Graph graph = new Graph(testMatrix);
        int[][] shortestPaths = graph.floydWarshall();
        for(int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                System.out.print(shortestPaths[i][j] + " ");
            }
            System.out.println();
        }
    }

  @Test
  void floydWarshallShortestPath() {
      int[][] testMatrix = new int[5][5];
      testMatrix[0][0] = 0;
      testMatrix[0][1] = 3;
      testMatrix[0][2] = 8;
      testMatrix[0][3] = Integer.MAX_VALUE;
      testMatrix[0][4] = -4;
      testMatrix[1][0] = Integer.MAX_VALUE;
      testMatrix[1][1] = 0;
      testMatrix[1][2] = Integer.MAX_VALUE;
      testMatrix[1][3] = 1;
      testMatrix[1][4] = 7;
      testMatrix[2][0] = Integer.MAX_VALUE;
      testMatrix[2][1] = 4;
      testMatrix[2][2] = 0;
      testMatrix[2][3] = Integer.MAX_VALUE;
      testMatrix[2][4] = Integer.MAX_VALUE;
      testMatrix[3][0] = 2;
      testMatrix[3][1] = Integer.MAX_VALUE;
      testMatrix[3][2] = -5;
      testMatrix[3][3] = 0;
      testMatrix[3][4] = Integer.MAX_VALUE;
      testMatrix[4][0] = Integer.MAX_VALUE;
      testMatrix[4][1] = Integer.MAX_VALUE;
      testMatrix[4][2] = Integer.MAX_VALUE;
      testMatrix[4][3] = 6;
      testMatrix[4][4] = 0;

      Graph graph = new Graph(testMatrix);
      ArrayList<Integer> path = graph.floydWarshallShortestPath(0, 1);
      System.out.println(path.toString());
  }
}