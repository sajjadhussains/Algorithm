/*
    _What is dynamic programming?
        -->When the bigger porblem can be solved by smaller,smaller subproblem then the programming can be called dynamic programming.

    _How to solve dynamic programming?
        -->To solve dynamic programming 3 steps should follow:
            1.Define the states
            2.identify the recursive equation from smaller subproblems.
            3.Define base case.

        Example:solving fibonacci series
            1.fib(n)---->the parameters of the function is called state.
            2.//calculate recursive equation:
                fib(n)=fib(n-1)+fib(n-2)
            3.//base case: if from other subproblems doesn't need any help to   solve the smallest subproblem,then it is called base case.
                fib(1)=1  |these twos are base case,because there doesn't need any
                fib(2)=1  |help from other subproblems to solve it.

                But,
                fib(4)--for solving it needs help from other subproblem

    __There are two ways to solve dynamic programming.
        1.Memoization process/recursive/Top Down
        2.Tabulation/iterative/Bottom Up
    
    1.Memoization process/recursive/Top Down:
        fun(n,a,b,c){
            1.handle base case
            2.if current state is already solved, return the result
            3.calculate the result from smaller subproblems.
        }
    
    2.Tebulation/Iterative/Bottom Up:
        //1.handle base case.
        //2.loop through the states
            2.1:calculate the result from smaller subproblem
*/