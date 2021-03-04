# Solution

## Approach 1: Brute Force

For each node $a_i$ in list A, traverse the entire list B and check if any node in list B coincides with $a_i$.

### Complexity Analysis

* Time complexity: $O(mn)$.
* Space complexity: $O(1)$.

## Approach 2: Hash Table

Traverse list A and store the address/reference to each node in a hash set. Then check every node $b_i$ in list B; if $b_i$ appears in the hash set, then $b_i$ is the intersection node.  

### Complexity Analysis

* Time complexity: $O(m+n)$.
* Space complexity: $O(m)$ or $O(n)$.

## Approach 3: Two Pointers

* Maintain two pointers $pA$ and $pB$ initialized at the head of A and B, respectively. Then let them both traverse through the lists, one node at a time.
* When $pA$ reaches the end of a list, then redirect it to the head of B (yes, B, that's right.); similarly when $pB$ reaches the end of a list, redirect it the head of A.
* If any point $pA$ meets $pB$, then $pA$/$pB$ is the intersection node.
* To see why the above trick would work, consider the following two lists: A = {1,3,5,7,9,11} and B = {2,4,9,11}, which are intersected at node '9'. Since B.length (=4) < A.length (=6), $pB$ would reach the end of the merged list first, because $pB$ traverses exactly 2 nodes less than $pA$ does. By redirecting $pB$ to head A, and $pA$ to head B, we now ask $pB$ to travel exactly 2 more nodes than $pA$ would. So in the second iteration, they are guaranteed to reach the intersection node at the same time.
* If two lists have intersection, then their last nodes must be the same one. So when $pA$/$pB$ reaches the end of a list, record the last element of A/B respectively. If the two last elements are not the same one, then the two lists have no intersections.

### Complexity Analysis

* Time complexity: $O(m+n)$.
* Space complexity: $O(1)$.
