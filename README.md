# greedily-increasing-subsequence-kattis-contest

Given a permutation A=(a1,a2,…,aN) of the integers 1,2,…,N, we define the greedily increasing subsequence (GIS) in the following way.

Let g1=a1. For every i>1, let gi be the leftmost integer in A that is strictly larger than gi−1. If there for a given i is no such integer, we say that the GIS of the sequence is the sequence (g1,g2,...,gi−1).

Your task is to, given a permutation A, compute the GIS of A.

Input
The first line of input contains an integer 1≤N≤106, the number of elements of the permutation A. The next line contains N distinct integers between 1 and N, the elements a1,…,aN of the permutation A.

Output
First, output a line containing the length l of the GIS of A. Then, output l integers, containing (in order) the elements of the GIS.

Explanation of sample 1
In this case, we have the permutation 2,3,1,5,4,7,6. First, we have g1=2. The leftmost integer larger than 2 is 3, so g2=3. The leftmost integer larger than 3 is 5 (1 is too small), so g3=5. The leftmost integer larger than 5 is 7, so g4=7. Finally, there is no integer larger than 7. Thus, the GIS of 2,3,1,5,4,7,6 is 2,3,5,7.

https://open.kattis.com/problems/greedilyincreasing
