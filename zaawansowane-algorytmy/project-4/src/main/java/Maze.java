import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.concurrent.ThreadLocalRandom;

public class Maze {
  private UndirectedGraph mazeGraph;
  private ArrayList<Edge> mst;
  private final int cellSize = 50;
  private final int strokeWidth = 10;
  private final int width;
  private final int height;

  public Maze(int width, int height) {
    this.width = width;
    this.height = height;
    generateGraph(width, height);
    this.mst = KruskalAlgorithm.getMst(mazeGraph);
  }

  private void generateGraph(int width, int height) {
    this.mazeGraph = new UndirectedGraph();
    for (int i = 0; i < width * height; i++) {
      mazeGraph.addVertex();
    }

    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        int sourceNode = i * width + j;
        if (j != width - 1) {
          mazeGraph.addEdge(sourceNode, sourceNode + 1, ThreadLocalRandom.current().nextInt(0, 10));
        }
        if (i != height - 1) {
          mazeGraph.addEdge(
              sourceNode, sourceNode + width, ThreadLocalRandom.current().nextInt(0, 10));
        }
      }
    }
  }

  public UndirectedGraph getMazeGraph() {
    return this.mazeGraph;
  }

  public void exportMaze(String fileName) throws IOException {
    File file = new File(fileName);
    try {
      file.delete();
    } catch (Exception ignored) {
    }
    if (file.createNewFile()) {
      FileWriter writer = new FileWriter(file);
      writer.write(
          "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
              + "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n"
              + "  \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n"
              + "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\"\n"
              + "     width=\""
              + width * cellSize
              + strokeWidth
              + "\" height=\""
              + height * cellSize
              + strokeWidth
              + "\">");

      // draw each cell
      for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
          writer.write(
              getSvgRectangle(
                  i * cellSize, j * cellSize, cellSize, cellSize, "white", "black", strokeWidth));
        }
      }

      // destroy borders between connected cells
      // the vertex with the smaller index is always first in connectedVertices
      for (Edge edge : mst) {
        int sourceVertex = edge.connectedVertices[0].index;
        int destVertex = edge.connectedVertices[1].index;
        writer.write(
            getSvgRectangle(
                sourceVertex % width * cellSize + strokeWidth / 2,
                (sourceVertex / width) * cellSize + strokeWidth / 2,
                cellSize - strokeWidth + (destVertex - sourceVertex) % width * cellSize,
                cellSize - strokeWidth + (destVertex - sourceVertex) / width * cellSize,
                "white",
                "white",
                0));
      }

      writer.write("</svg>");
      writer.close();
    }
  }

  private String getSvgRectangle(
      int x, int y, int width, int height, String fill, String stroke, int strokeWidth) {
    return "<rect x=\""
        + x
        + "\" y=\""
        + y
        + "\" width=\""
        + width
        + "\" height=\""
        + height
        + "\" fill=\""
        + fill
        + "\" stroke=\""
        + stroke
        + "\" stroke-width=\""
        + strokeWidth
        + "\" />\n";
  }
}
