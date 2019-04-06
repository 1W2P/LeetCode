using System;
using System.Collections.Generic;
using System.Linq;
public class main {
	public static void Main() {
		
		var ret =  new Solution().IsSubsequence("axc", "ahbgdc");
		Console.WriteLine(ret);
	}
}

public class Solution {
    public bool IsSubsequence(string s, string t) {
		int sIdx = 0;
		foreach(var ch in t){
			if(sIdx < s.Length && s[sIdx] == ch ){
				if(++sIdx == s.Length)
					break;
			}
		}
		if(sIdx == s.Length)
			return true;
		else
			return false;
	}
}