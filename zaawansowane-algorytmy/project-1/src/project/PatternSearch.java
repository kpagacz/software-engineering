package project;

import java.util.ArrayList;
import java.util.HashMap;

public class PatternSearch {
    private static boolean matchesAt(String pattern, String text, int position) {
        for(int i = 0; i < pattern.length(); i++)
            if(text.charAt(position + i) != pattern.charAt(i)) return false;
        return true;
    }

    /** A naive search of a pattern in a text.
     *
     * @param pattern Pattern to look for in the text.
     * @param text Text.
     * @return ArrayList of positions. Each position begins a match of the pattern in the text.
     */
    public static ArrayList<Integer> naiveSearch(String pattern, String text) {
        ArrayList<Integer> matched_positions = new ArrayList<>();

        for(int i = 0; i <= text.length() - pattern.length(); i++)
            if(matchesAt(pattern, text, i)) matched_positions.add(i);

        return matched_positions;
    }

    private static HashMap<Character, Integer> sundayPreprocess(String pattern) {
        HashMap<Character, Integer> last_position = new HashMap<>();
        for(int i = 0; i < pattern.length(); i++) {
            last_position.put(pattern.charAt(i), i);
        }

        return last_position;
    }

    /** Implementation of the Sunday algorithm (searching a pattern in a text).
     *
     * @param pattern Pattern to look for in the text.
     * @param text Text.
     * @return ArrayList of positions. Each position begins a match of the pattern in the text.
     */
    public static ArrayList<Integer> sundaySearch(String pattern, String text) {
        HashMap<Character, Integer> last_positions = sundayPreprocess(pattern);
        ArrayList<Integer> matched_positions = new ArrayList<>();

        int curr_position = 0;
        while(curr_position <= text.length() - pattern.length()) {
            if(matchesAt(pattern, text, curr_position))
                matched_positions.add(curr_position);
            curr_position += pattern.length();
            if(curr_position < text.length()) {
                int last_pos = last_positions.get(text.charAt(curr_position)) == null ?
                        -1 : last_positions.get(text.charAt(curr_position));
                curr_position -= last_pos;
            }
        }

        return matched_positions;
    }
}
