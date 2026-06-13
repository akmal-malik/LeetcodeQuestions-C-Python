from typing import List

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = {}

        for word in strs:
            key = ''.join(sorted(word))

            if key not in groups:
                groups[key] = []

            groups[key].append(word)

        return list(groups.values())


# Test
sol = Solution()

strs = ["eat", "tea", "tan", "ate", "nat", "fat"]

result = sol.groupAnagrams(strs)

print(result)