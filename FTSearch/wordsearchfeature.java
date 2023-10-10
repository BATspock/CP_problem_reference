class WordDictionary {
    HashSet<String> dict = new HashSet<>(); 
    public WordDictionary() {
        
    }
    
    public void addWord(String word) {
        dict.add(word);
    }
    
    public boolean search(String word) {
        if (word.contains(".")){
            
            for (String s: dict){

                if (s.length() == word.length()){
                    int i;
                    for (i =0;i<word.length();i++){
                        if (word.charAt(i) == '.') {
                            continue;
                        }
                        else if (word.charAt(i) == s.charAt(i)) {
                            continue;
                        } 
                        else {
                            break;
                        }
                    }
                    if (word.length() == i) {
                        return true;
                    }
                }
            }
            return false;
        } else {
           return dict.contains(word);
        }
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
