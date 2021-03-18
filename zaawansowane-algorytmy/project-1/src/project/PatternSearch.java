package project;

import java.util.ArrayList;

public class PatternSearch {
    public static void main(String[] args) {
        java.util.Scanner in = new java.util.Scanner(System.in);
        String text = in.nextLine();
        String pattern = in.nextLine();
        System.out.println(naiveSearch(pattern, text));
    }

    private static boolean matchesAt(String pattern, String text, int position) {
        for(int i = 0; i < pattern.length(); i++)
            if(text.charAt(position + i) != pattern.charAt(i)) return false;
        return true;
    }

    public static ArrayList<Integer> naiveSearch(String pattern, String text) {
        ArrayList<Integer> matched_positions = new ArrayList<Integer>();

        for(int i = 0; i <= text.length() - pattern.length(); i++)
            if(matchesAt(pattern, text, i)) matched_positions.add(i);

        return matched_positions;
    }
}
