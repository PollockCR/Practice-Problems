// https://www.hackerrank.com/challenges/ctci-ransom-note

import java.util.*;

public class Solution {
    Map<String, Integer> magazineMap;
    Map<String, Integer> noteMap;

    public Solution(String magazine, String note) {
        magazineMap = new HashMap<String,Integer>();
        noteMap = new HashMap<String,Integer>();
        String word;
        while(!magazine.isEmpty()){
            if(magazine.contains(" ")){
                word = magazine.substring(0, magazine.indexOf(" "));
                magazine = magazine.substring(magazine.indexOf(" ")+1);
            } else {
                word = magazine;
                magazine = "";
            }
            if(magazineMap.containsKey(word)){
                magazineMap.put(word, magazineMap.get(word)+1);
            } else {
                magazineMap.put(word, 1);
            }
        }
        while(!note.isEmpty()){
            if(note.contains(" ")){
                word = note.substring(0, note.indexOf(" "));
                note = note.substring(note.indexOf(" ")+1);
            } else {
                word = note;
                note = "";
            }
            if(noteMap.containsKey(word)){
                noteMap.put(word, noteMap.get(word)+1);
            } else {
                noteMap.put(word, 1);
            }
        }
    }

    public boolean solve() {
        for(String word : noteMap.keySet()){
            if(magazineMap.containsKey(word))
            {
                if(magazineMap.get(word) < noteMap.get(word)){
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        int n = scanner.nextInt();

        // Eat whitespace to beginning of next line
        scanner.nextLine();

        Solution s = new Solution(scanner.nextLine(), scanner.nextLine());
        scanner.close();

        boolean answer = s.solve();
        if(answer)
            System.out.println("Yes");
        else System.out.println("No");

    }
}
