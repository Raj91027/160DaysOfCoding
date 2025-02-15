package Hashing;

/*
Group Anagrams Together

Given an array of words arr[], the task is to groups strings that are anagrams. 
An anagram is a word or phrase formed by rearranging the letters of another, using all the original letters exactly once.

Example:

Input: arr[] = ["act", "god", "cat", "dog", "tac"]
Output: [["act", "cat", "tac"], ["god", "dog"]]
Explanation: There are 2 groups of anagrams "god", "dog" make group 1. "act", "cat", "tac" make group 2.
 */


 //[Expected Approach] Using Frequency as keys - O(n*k) Time and O(n*k) Space
//The idea is to that if two strings are anagrams of each other, then the frequency of all characters in both strings will always be the same. 
//So, we can maintain a hash map with the count of characters as keys and the index of the anagram group in the result array as the value. For each word, we can first construct a frequency array of size 26 to store the frequency of each character in the word. //
//Then, we can append the frequency of each character separated by a delimiter, say '$' to form the key for hash map.

//Note the MAX_CHAR is alphabet size of input characters which is typically a constant. 
//If we have only lower case characters, then MAX_CHAR is 26 only. If we consider all ASCII characters, then MAX_CHAR is 256.




// Java Code to group anagrams together by using frequency
// as keys

import java.util.*;

class GfG { 
    static final int MAX_CHAR = 26;

    // Function to generate hash of word s
    static String getHash(String s) {
        StringBuilder hash = new StringBuilder();
        int[] freq = new int[MAX_CHAR];
        
        // Count frequency of each character
        for (char ch : s.toCharArray()) {
            freq[ch - 'a']++;
        }

        // Append the frequency to construct the hash
        for (int i = 0; i < MAX_CHAR; i++) {
            hash.append(freq[i]);
            hash.append("$");
        }

        return hash.toString();
    }

    static ArrayList<ArrayList<String>> anagrams(String[] arr) {
        ArrayList<ArrayList<String>> res = new ArrayList<>();
        Map<String, Integer> mp = new HashMap<>();
        
        for (int i = 0; i < arr.length; i++) {
            String key = getHash(arr[i]);
            
            // If key is not present in the hash map, add
            // an empty group (List) in the result and
            // store the index of the group in hash map
            if (!mp.containsKey(key)) {
                mp.put(key, res.size());
                res.add(new ArrayList<>());
            }

            // Insert the string in its correct group
            res.get(mp.get(key)).add(arr[i]);
        }

        return res;
    }

    public static void main(String[] args) {
        String[] arr = {"act", "god", "cat", "dog", "tac"};
        
        ArrayList<ArrayList<String>> res = anagrams(arr);
        
        for (List<String> group : res) {
            for (String word : group) {
                System.out.print(word + " ");
            }
            System.out.println();
        }
    }
}