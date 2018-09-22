Infinite Morphism checking program
https://github.com/xenon
Alexander Acker - September 22nd 2018
-------------------------------------------------------------------------------
What does it do?

(1) Morphism Generating
Files: array-generator.rkt, maps.rkt, run.rkt

maps.rkt:
Contains definitions of mappings from single digit numbers to lists of numbers.

array-generator.rkt:
Takes a mapping and applies it to itself a certain number of times.
Always applies itself to 0 in the base case (maps must handle 0)
eg: (iterate_map h_map 3) => h_map(h_map(h_map(0)))

* Applying the mapping enough times begins to approximate the beginning of
an infinite word h_map(...(h_map(0))) (where ... is infinite applications).

run.rkt:
Simply change the map to and number of applications (last line of the file)
and run it with Racket in order to produce an approximation of the infinite
word.

The output is formatted as following (to standard out):
<LENGTH OF THE WORD><newline>
<THE WORD ITSELF>
-------------------------------------------------------------------------------
(2) Checking for additive square
Files: asquare.c

Additive square: Two consecutive blocks of the same length and same sum.

Reads a morphism in the format of output from (1).
Checks the morphism for an additive square.
Prints whether or not it has an additive square to standard out.
-------------------------------------------------------------------------------
Compilation

Just use make in the root of the source this will build asquare.c => asquare.
-------------------------------------------------------------------------------
Process of generating a morphism and checking it:

(1) Create your mapping and place it in maps.rkt, you may name it as you like,
but for simplicity we'll refer to the function you make as as my_map.

(2) Modify the last line of run.rkt to contain (iterate_map my_map xx) where
xx is the number of times you apply this mapping to itself.

(3) To generate the morphism into a text file run this command:
racket run.rkt > my-morphism.txt

(4) To check for additive squares run the following command:
./asquare < my-morphism.txt
-------------------------------------------------------------------------------
examples directory
Includes some example morphisms that you can test with asquare.
