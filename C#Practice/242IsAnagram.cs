public class Solution {
    public bool IsAnagram(string s, string t) {
        if (s.Length != t.Length) return false;

        Dictionary<char, int> charFrequency = new Dictionary<char, int>();
        for (int i = 0; i < s.Length; i++) {
            charFrequency[s[i]] = charFrequency.GetValueOrDefault(s[i], 0) + 1;
            charFrequency[t[i]] = charFrequency.GetValueOrDefault(t[i], 0) - 1;
        }

        return charFrequency.All(entry => entry.Value == 0);
    }
}
