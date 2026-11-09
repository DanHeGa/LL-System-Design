## Problem

A phone keyboard suggests words while you type. 
You are given a dictionary words and the word typed that the user types one letter at a time.

After each letter, the keyboard shows up to three suggestions: the dictionary words 
that start with the letters typed so far. When more than three words match, it shows
the three that come first in alphabetical order. A dictionary word equal to the letters typed so
far also counts as a match.

Return a list with one entry per typed letter. Entry i is the list of suggestions 
after the first i + 1 letters, in alphabetical order. It is empty when no word matches.

### Function
```cpp
vector<vector<string>> autocomplete(vector<string> words, string typed);
```

### Examples

**Example 1**
```cpp
words = ["ride","rider","rides","riding","road","rate"]
typed = "rid"
return = [["rate","ride","rider"],["ride","rider","rides"],["ride","rider","rides"]]
```
**Example 2**
```cpp
words = ["map","maps","mop"]
typed = "maze"
return = [["map","maps","mop"],["map","maps"],[],[]]
```

**Example 3**
```cpp
words = ["gone","go","golf","goal"]
typed = "gol"
return = [["go","goal","golf"],["go","goal","golf"],["golf"]]
```

### Constraints
- 1 <= words.length <= 10^4
- 1 <= words[i].length <= 20
- 1 <= typed.length <= 30
- words[i] and typed contain only lowercase English letters.
- All words in words are distinct.