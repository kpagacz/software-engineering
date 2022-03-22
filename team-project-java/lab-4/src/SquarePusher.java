import java.util.Random;
import java.util.concurrent.TimeUnit;

public class SquarePusher implements Runnable {
  private final int square;
  private final Board board;

  public SquarePusher(int square, Board board) {
    super();
    this.square = square;
    this.board = board;
  }

  @Override
  public void run() {
    while (board.getSquarePosition(square) != 9) {
      board.moveSquare(square);
      Random rng = new Random();
      try {
        TimeUnit.SECONDS.sleep(rng.nextInt(5));
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
  }
}
