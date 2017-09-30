// https://www.hackerrank.com/challenges/ctci-making-anagrams
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
public class MakingAnagrams {
    public static int numberNeeded(String first, String second) {
        int total = 0;
        HashMap<Character,Integer> firstCounts = new HashMap<Character,Integer>(countLetters(first));
        HashMap<Character,Integer> secondCounts = new HashMap<Character,Integer>(countLetters(second));
        String alphabet = "abcdefghijklmnopqrstuvwxyz";
        for(char letter : alphabet.toCharArray()){
            total += java.lang.Math.abs(firstCounts.get(letter) - secondCounts.get(letter));
        }
        return total;
    }

    public static HashMap<Character,Integer> countLetters(String s) {
        HashMap<Character,Integer> sCounts = new HashMap<Character,Integer>(26);
        String alphabet = "abcdefghijklmnopqrstuvwxyz";
        for(char letter : alphabet.toCharArray()){
            sCounts.put(letter, 0);
        }
        for(char letter : s.toCharArray()){
            int count = sCounts.get(letter) + 1;
            sCounts.put(letter, count);
        }
        return sCounts;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String a = in.next();
        String b = in.next();
        System.out.println(numberNeeded(a, b));
    }
}
