import java.util.stream.IntStream;

public class Board {
  private int[] squares;

  public Board() {
    squares = IntStream.generate(() -> 0).limit(10).toArray();
  }

  public synchronized void moveSquare(int square) {
    squares[square]++;
    System.out.println(this);
  }

  public synchronized int getSquarePosition(int square) {
    return squares[square];
  }

  @Override
  public String toString() {
    StringBuilder out = new StringBuilder();
    out.append("Current board state:\n");
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++)
        if (squares[i] != j) out.append(".");
        else out.append("S");
      out.append("\n");
    }
    return out.toString();
  }
}
