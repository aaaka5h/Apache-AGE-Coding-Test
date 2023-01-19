<h3>First Approach: Simple recursion</h3>
While this one-line method is incredibly simple, it is slow and has an exponential time complexity: O(2^n). This is much slower in comparison to more efficient algorithms which can compute F(n) in O(n) time.

Furthermore, for each recursive call, the stack grows. As the input value n increases, the stack also increases linearly, giving our function a space complexity of O(n). There are more efficient algorithms that can compute F(n) with O(1) space complexity.

All in all, this function is useful for small inputs of n as it is correct, consice, and simple.

<h3>Second Approach: Memoization</h3>
Using memoization, we can compute F(n) in O(n) time. This is due to the fact that although we are still using recursive calls, we are caching previously calculated values in an array to avoid redundant recomputation. This is a huge improvement in performance.

However, we still have a space complexity of O(n) as we are creating an array of length n+1. Although this linear space complexity could be improved upon (see third approach) storing all calculated values could be handy depending on the situation. For example, in a scenario where you would want to print the entire sequence of F(0) to F(n) after calculating F(n), the precomputed array will allow you to efficiently do so.

<h3>Third Approach: Bottom-up Dynamic Programming</h3>
In this approach we utilze a for loop to iterate through all values from 3 to n. The time complexity of our function is O(n) because of our loop which runs O(n) times.

Moreover, this function has an O(1) space complexity because it uses a constant amount of memory to store the four local variables. This function is recommended to calculate F(n) for very large values of n as it uses very very little memory as opposed to the other two approaches.

<h3>How to run the code</h3>
The source code for Question 2 is in C and was created on VSCode. To run the source code, simply compile one of the Q2.c files and run it with a command line argument n. The value that will be printed to your console will be F(n).

For example on my Mac, I can compile the file Q2a.c file by typing _gcc Q2a.c -o Q2a.exe_ into my terminal and get the value of F(5) with _./Q2a.exe 5_. Just make sure you are in the proper directory!
