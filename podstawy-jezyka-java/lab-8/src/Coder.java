import java.util.AbstractMap;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;

public class Coder {
    private static final HashMap<Character, Character> codePattern = new HashMap<Character, Character>(Map.ofEntries(
            new AbstractMap.SimpleEntry<>('g', 'a'),
            new AbstractMap.SimpleEntry<>('d', 'e'),
            new AbstractMap.SimpleEntry<>('r', 'y'),
            new AbstractMap.SimpleEntry<>('p', 'o'),
            new AbstractMap.SimpleEntry<>('l', 'u'),
            new AbstractMap.SimpleEntry<>('k', 'i'),
            new AbstractMap.SimpleEntry<>('a', 'g'),
            new AbstractMap.SimpleEntry<>('e', 'd'),
            new AbstractMap.SimpleEntry<>('y', 'r'),
            new AbstractMap.SimpleEntry<>('o', 'p'),
            new AbstractMap.SimpleEntry<>('u', 'l'),
            new AbstractMap.SimpleEntry<>('i', 'k')
    ));

    private Coder() {};
    public static String code(String source) {
        StringBuilder answer = new StringBuilder();
        for(int i = 0; i < source.length(); i++) {
            boolean capitalized = Character.isUpperCase(source.charAt(i));
            char c = Character.toLowerCase(source.charAt(i));
            c = codePattern.getOrDefault(c, c);
            if (capitalized) c = Character.toUpperCase(c);
            answer.append(c);
        }
        return answer.toString();
    }
}
