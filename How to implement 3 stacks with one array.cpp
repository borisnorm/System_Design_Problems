ref:
http://stackoverflow.com/a/4770793

Space (not time) efficient. You could:

1) Define two stacks beginning at the array endpoints and growing in opposite directions.

2) Define the third stack as starting in the middle and growing in any direction you want.

3) Redefine the Push op, so that when the operation is going to overwrite other stack, you shift the whole middle stack in the opposite direction before Pushing.

You need to store the stack top for the first two stacks, and the beginning and end of the third stack in some structure.

Following @ruslik's suggestion, the middle stack could be implemented using an alternating sequence for subsequent pushes. The resulting stack structure will be something like:

| Elem 6 | Elem 4 | Elem 2 | Elem 0 | Elem 1 | Elem 3 | Elem 5 |
In this case, you'll need to store the number n of elements on the middle stack and use the function:

f[n_] := 1/4 ( (-1)^n (-1 + 2 n) + 1) + BS3  
to know the next array element to use for this stack.

Although probably this will lead to less shifting, the implementation is not homogeneous for the three stacks, and inhomogeneity (you know) leads to special cases, more bugs and difficulties to maintain code.
