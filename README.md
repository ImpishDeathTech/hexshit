# hexshit
A pretty hexadecimal dump utility with a crass, comical name written in c++

I wrote this on a spur of "Why not? Haven't done that yet!", I know unix already has a hexdump, but this one aims to look better than that ugly
junk. It is intentionally written so it can be both run as a program or included as a utility function for a program. I just hope others may find it of use.

It's a small program with no external dependancies, it is suggested to compile this with g++, as it has not been tested with other compilers yet; I only use gcc, but by all means, try it with other compilers too! R&D FTW!

`g++ -std=c++20 -o hs main.cxx hexshit.cxx`
