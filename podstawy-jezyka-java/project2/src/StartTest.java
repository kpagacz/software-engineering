import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class StartTest {

  @Test
  void formatTime() {
    assertEquals("00:00:00", Start.formatTime(0));
    assertEquals("00:00:10", Start.formatTime(10));
    assertEquals("00:01:10", Start.formatTime(70));
    assertEquals("00:10:10", Start.formatTime(10 * 60 + 10));
    assertEquals("01:10:10", Start.formatTime(60 * 60 + 10 * 60 + 10));
    assertEquals("10:10:10", Start.formatTime(10 * 60 * 60 + 10 * 60 + 10));
    assertEquals("101:10:10", Start.formatTime(101 * 60 * 60 + 10 * 60 + 10));
  }
}
