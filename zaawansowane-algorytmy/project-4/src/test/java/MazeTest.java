import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.io.IOException;

import static org.junit.jupiter.api.Assertions.assertEquals;

class MazeTest {
    Maze maze;
    @BeforeEach
    void setUp() {
        maze = new Maze(20, 10);
    }
    @Test
    void testCreatingMazeGraph() {
        Vertex firstVertex = maze.getMazeGraph().vertices.get(0);
        assertEquals(1, firstVertex.edges.get(0).connectedVertices[1].index);
        assertEquals(8, firstVertex.edges.get(1).connectedVertices[1].index);
        Vertex anotherVertex = maze.getMazeGraph().vertices.get(9);
        assertEquals(4, anotherVertex.edges.size());
    }

  @Test
  void getMazeGraph() {}

  @Test
  void exportMaze() throws IOException {
        maze.exportMaze("test.xml");
  }
}