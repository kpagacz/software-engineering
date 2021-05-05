import java.util.ArrayList;

public class Graph {
  private int verticesNumber;
  private int[][] adjacencyMatrix;

  public Graph(int[][] adjacencyMatrix) {
    this.adjacencyMatrix = adjacencyMatrix;
    this.verticesNumber = adjacencyMatrix.length;
  }

  public int[][] floydWarshall() {
    int[][] shortestPaths = new int[verticesNumber][verticesNumber];
    for (int i = 0; i < verticesNumber; i++)
      for (int j = 0; j < verticesNumber; j++) shortestPaths[i][j] = adjacencyMatrix[i][j];

    for (int k = 0; k < verticesNumber; k++)
      for (int i = 0; i < verticesNumber; i++)
        for (int j = 0; j < verticesNumber; j++)
          try {
            shortestPaths[i][j] =
                Math.min(
                    shortestPaths[i][j], Math.addExact(shortestPaths[i][k], shortestPaths[k][j]));
          } catch (ArithmeticException ignored) {

          }

    return shortestPaths;
  }

  public int floydWarshall(int i, int j) {
    int[][] shortestPaths = floydWarshall();
    return shortestPaths[i][j];
  }

  public ArrayList<Integer> floydWarshallShortestPath(int start, int end) {
    int[][] shortestPaths = new int[verticesNumber][verticesNumber];
    int[][] successors = new int[verticesNumber][verticesNumber];

    for (int i = 0; i < verticesNumber; i++)
      for (int j = 0; j < verticesNumber; j++) {
        shortestPaths[i][j] = adjacencyMatrix[i][j];
        if(shortestPaths[i][j] != Integer.MAX_VALUE) {
          successors[i][j] = j;
        } else {
          successors[i][j] = -1;
        }
      }

    for (int k = 0; k < verticesNumber; k++)
      for (int i = 0; i < verticesNumber; i++)
        for (int j = 0; j < verticesNumber; j++)
          try {
           if (shortestPaths[i][j] > Math.addExact(shortestPaths[i][k], shortestPaths[k][j])) {
            shortestPaths[i][j] =  Math.addExact(shortestPaths[i][k], shortestPaths[k][j]);
            successors[i][j] = successors[i][k];
           }
          } catch (ArithmeticException ignored) {
          }

    if (successors[start][end] == -1) return new ArrayList<>();
    ArrayList<Integer> path =  new ArrayList<>();
    path.add(start);
    while (start != end) {
      start = successors[start][end];
      path.add(start);
    }

    return path;
  }
}
