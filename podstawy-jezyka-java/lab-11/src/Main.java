import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.CharBuffer;
import java.nio.channels.FileChannel;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.DirectoryStream;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Comparator;
import java.util.Stack;
import java.util.stream.StreamSupport;

import static java.nio.file.StandardCopyOption.REPLACE_EXISTING;
import static java.nio.file.StandardOpenOption.READ;
import static java.nio.file.StandardOpenOption.TRUNCATE_EXISTING;
import static java.nio.file.StandardOpenOption.WRITE;

public class Main {
  public static void main(String[] args) {
    // Setting up the file structure
    try {
      Files.createDirectories(FileSystems.getDefault().getPath("./Dir0/Dir1/Dir11/Dir111"));
      Files.createDirectories(FileSystems.getDefault().getPath("./Dir0/Dir2"));
      Files.createDirectories(FileSystems.getDefault().getPath("./Dir0/Dir3/Dir31"));
      Files.createDirectories(FileSystems.getDefault().getPath("./Dir0/Dir3/Dir32"));
    } catch (IOException e) {
      e.printStackTrace();
    }
    try {
      Files.createFile(FileSystems.getDefault().getPath("./Dir0/Dir1/Dir11/Dir111/File3.txt"));
    } catch (IOException e) {
      e.printStackTrace();
    }
    try {
      Files.createFile(FileSystems.getDefault().getPath("./Dir0/Dir1/Dir11/File1.txt"));
    } catch (IOException e) {
      e.printStackTrace();
    }
    try {
      Files.createFile(FileSystems.getDefault().getPath("./Dir0/Dir1/Dir11/File2.txt"));
    } catch (IOException e) {
      e.printStackTrace();
    }
    try {
      Files.createFile(FileSystems.getDefault().getPath("./Dir0/Dir2/File4.txt"));
    } catch (IOException e) {
      e.printStackTrace();
    }
    try {
      Files.createFile(FileSystems.getDefault().getPath("./Dir0/Dir3/Dir31/File5.txt"));
    } catch (IOException e) {
      e.printStackTrace();
    }

    // Task 1
    try {
      Files.copy(
          FileSystems.getDefault().getPath("./Dir0/Dir1/Dir11/File1.txt"),
          FileSystems.getDefault().getPath("./Dir0/Dir3/Dir32/File1.txt"),
          REPLACE_EXISTING);
    } catch (IOException e) {
      e.printStackTrace();
    }

    // Task 2
    Path p1 = FileSystems.getDefault().getPath("./Dir0/Dir1/Dir11/File1.txt");
    Path p2 = FileSystems.getDefault().getPath("./Dir0/Dir1/Dir11/File2.txt");
    try (BufferedReader reader = Files.newBufferedReader(p1);
        BufferedWriter writer = Files.newBufferedWriter(p2, TRUNCATE_EXISTING)) {
      reader
          .lines()
          .forEach(
              line -> {
                line = line.replace('a', '@');
                try {
                  writer.write(line);
                  writer.newLine();
                } catch (IOException e) {
                  e.printStackTrace();
                }
              });
    } catch (IOException e) {
      e.printStackTrace();
    }

    // Task 3
    Path p3 = FileSystems.getDefault().getPath("./Dir0/Dir1/Dir11/File1.txt");
    Path p4 = FileSystems.getDefault().getPath("./Dir0/Dir1/Dir11/Dir111/File3.txt");
    try (BufferedReader reader = Files.newBufferedReader(p3);
        BufferedWriter writer = Files.newBufferedWriter(p4, TRUNCATE_EXISTING)) {
      // I use a stack because apparently reading a file in reverse using buffers is horribly
      // complicated in java. I am aware of a terrible memory performance of this solution and would
      // not recommend using it for any large files.
      Stack<String> stack = new Stack<>();
      reader.lines().forEach(stack::push);
      while (!stack.empty()) {
        String line = stack.pop();
        writer.write(line);
        writer.newLine();
      }
    } catch (IOException e) {
      e.printStackTrace();
    }

    // Task 4
    Path p5 = FileSystems.getDefault().getPath("./Dir0/Dir1/Dir11/File1.txt");
    Path p6 = FileSystems.getDefault().getPath("Dir0/Dir2/File4.txt");
    try {
      Files.copy(p5, p6, REPLACE_EXISTING);
    } catch (IOException e) {
      e.printStackTrace();
    }

    // I have to admit this task proved to be the hardest of this batch. It remains unclear to me
    // whether there is a simpler way to finish it.
    try (FileChannel channel = FileChannel.open(p6, READ, WRITE)) {
      int charactersSeen = 0;
      int bytesRead = -1;

      while (charactersSeen < 201) {
        channel.position(bytesRead + 1);
        ByteBuffer readBuffer = ByteBuffer.allocate(256);
        int newBytesRead = channel.read(readBuffer);
        String readString = new String(readBuffer.array(), StandardCharsets.UTF_8);
        StringBuilder writeString = new StringBuilder();
        for (int j = 0; j < readString.length(); j++) {
          if (charactersSeen % 2 == 0 && charactersSeen < 201) {
            writeString.append(" ");
          } else {
            writeString.append(readString.charAt(j));
          }
          charactersSeen++;
        }
        channel.position(channel.position() - newBytesRead);
        bytesRead += newBytesRead;
        channel.write(ByteBuffer.wrap(writeString.toString().getBytes(StandardCharsets.UTF_8)));
      }
    } catch (IOException e) {
      e.printStackTrace();
    }

    // Task 5
    try {
      recurrentLS(FileSystems.getDefault().getPath("./Dir0"), 0);
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  private static void recurrentLS(Path p, int depth) throws IOException {
    if (Files.isRegularFile(p)) {
      System.out.println(
          " ".repeat(depth)
              + FileSystems.getDefault()
                  .getPath("")
                  .toUri()
                  .relativize(p.toUri())
                  .getPath() // because I want the path relative to the root
              + " Size: "
              + Files.size(p)
              + "b");
      return;
    }
    System.out.println(
        " ".repeat(depth)
            + FileSystems.getDefault().getPath("").toUri().relativize(p.toUri()).getPath()
            + ":");
    DirectoryStream<Path> paths = Files.newDirectoryStream(p);
    StreamSupport.stream(paths.spliterator(), false)
        .sorted(Comparator.comparing(Path::toString))
        .forEach(
            path -> {
              try {
                recurrentLS(path, depth + 1);
              } catch (IOException e) {
                e.printStackTrace();
              }
            });
  }
}
