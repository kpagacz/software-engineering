package project;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class PatternSearch {
    private static boolean matchesAt(String pattern, String text, int position) {
        for (int i = 0; i < pattern.length(); i++)
            if (text.charAt(position + i) != pattern.charAt(i)) return false;
        return true;
    }

    /**
     * A naive search of a pattern in a text.
     *
     * @param pattern Pattern to look for in the text.
     * @param text    Text.
     * @return ArrayList of positions. Each position begins a match of the pattern in the text.
     */
    public static ArrayList<Integer> naiveSearch(String pattern, String text) {
        ArrayList<Integer> matched_positions = new ArrayList<>();

        for (int i = 0; i <= text.length() - pattern.length(); i++)
            if (matchesAt(pattern, text, i)) matched_positions.add(i);

        return matched_positions;
    }

    private static HashMap<Character, Integer> sundayPreprocess(String pattern) {
        HashMap<Character, Integer> last_position = new HashMap<>();
        for (int i = 0; i < pattern.length(); i++) {
            last_position.put(pattern.charAt(i), i);
        }

        return last_position;
    }

    /**
     * Implementation of the Sunday algorithm (searching a pattern in a text).
     *
     * @param pattern Pattern to look for in the text.
     * @param text    Text.
     * @return ArrayList of positions. Each position begins a match of the pattern in the text.
     */
    public static ArrayList<Integer> sundaySearch(String pattern, String text) {
        HashMap<Character, Integer> last_positions = sundayPreprocess(pattern);
        ArrayList<Integer> matched_positions = new ArrayList<>();

        int curr_position = 0;
        while (curr_position <= text.length() - pattern.length()) {
            if (matchesAt(pattern, text, curr_position))
                matched_positions.add(curr_position);
            curr_position += pattern.length();
            if (curr_position < text.length()) {
                int last_pos = last_positions.get(text.charAt(curr_position)) == null ?
                        -1 : last_positions.get(text.charAt(curr_position));
                curr_position -= last_pos;
            }
        }

        return matched_positions;
    }


    private static int[] mpPartialMatchTable(String pattern) {
        int[] partial_match_table = new int[pattern.length() + 1];
        //      a  b  c  a  b  c  d
        //  -1  0  0  0  1  2  3  0
        //   0  1  2  3  4  5  6  7
        partial_match_table[0] = -1;
        partial_match_table[1] = 0;

        for(int i = 2; i <= pattern.length(); i++) { // prefix_suffix_length = partial_match_table[i - 1]
            int prefix_suffix_length = partial_match_table[i - 1];
            while(prefix_suffix_length > 0 && pattern.charAt(i - 1) != pattern.charAt(prefix_suffix_length)) {
                prefix_suffix_length = partial_match_table[prefix_suffix_length];
            }
            if(pattern.charAt(i - 1) == pattern.charAt(prefix_suffix_length)) ++ prefix_suffix_length;
            partial_match_table[i] = prefix_suffix_length;
        }


        return partial_match_table;
    }

    /**
     * Implementation of the Morris-Pratt algorithm
     *
     * @param pattern pattern to look for in the text
     * @param text    text
     * @return indices of text; each index begins a match of the pattern in the text
     */
    public static ArrayList<Integer> mpSearch(String pattern, String text) {
        ArrayList<Integer> matched_positions = new ArrayList<>();
        int[] partial_match_table = mpPartialMatchTable(pattern);

        int text_index = 0, pattern_index = 0;
        while(text_index <= text.length() - pattern.length()) {
            if(text.charAt(text_index + pattern_index) == pattern.charAt(pattern_index)) {
                // characters match
                ++pattern_index;
                if(pattern_index == pattern.length()) {
                    matched_positions.add(text_index);
                    text_index += pattern.length();
                    pattern_index = 0;
                }
            } else {
                // characters don't match
                text_index += pattern_index - partial_match_table[pattern_index];
                pattern_index = partial_match_table[pattern_index] == -1 ? 0 : partial_match_table[pattern_index];
            }
        }
        return matched_positions;
    }

    private static int[] kmpTable(String pattern) {
        int[] kmp_table = new int[pattern.length() + 1];
        kmp_table[0] = -1;
        kmp_table[1] = 0;
        int prefix_suffix = -1;
        for(int i = 1; i < pattern.length() + 1; i++) {
            while(prefix_suffix > -1 && pattern.charAt(i - 1) != pattern.charAt(prefix_suffix)) {
                prefix_suffix = kmp_table[prefix_suffix];
            }
            prefix_suffix++;
            if(i == pattern.length() || pattern.charAt(i) == pattern.charAt(prefix_suffix)) {
                kmp_table[i] = prefix_suffix;
            } else {
                kmp_table[i] = kmp_table[prefix_suffix];
            }
        }

        return kmp_table;
    }

    public static ArrayList<Integer> kmpSearch(String pattern, String text) {
        ArrayList<Integer> matched_positions = new ArrayList<>();
        int[] partial_match_table = kmpTable(pattern);

        int text_index = 0, pattern_index = 0;
        while(text_index <= text.length() - pattern.length()) {
            if(text.charAt(text_index + pattern_index) == pattern.charAt(pattern_index)) {
                // characters match
                ++pattern_index;
                if(pattern_index == pattern.length()) {
                    matched_positions.add(text_index);
                    text_index += pattern.length();
                    pattern_index = 0;
                }
            } else {
                // characters don't match
                text_index += pattern_index - partial_match_table[pattern_index];
                pattern_index = partial_match_table[pattern_index] == -1 ? 0 : partial_match_table[pattern_index];
            }
        }
        return matched_positions;
    }
}
