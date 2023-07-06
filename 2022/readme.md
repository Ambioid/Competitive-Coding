# Solutions/explanation for 2022

## Q1
This is a question that is very straightfoward, and is quite similar to a caesar cypher, except with individual letters having different values depending on the letters before them. You can use a for loop to iterate through the length of the string. C++ makes this easier as casting the character to an integer directly gives you its ASCII value. You can use this in 
```cpp
str[i] = str[i] - str[i-1]
```

then using an if statement to loop back if value is out of bounds. I think that this was a good opportunity to learn about ASCII handling as well as strings, lists, and indexing.

I have also used the opposite, encrypt function to answer parts b and d.

## Q2
This one was tricky. My solution was not yet complete but I think I have gotten the general idea. I've used a 2d array here to represent the information, [25][6], for the 25 hexagons with 6 edges each. Since the drones just move in 1 direction, I can just iteratively increase their hexagon value by 1, when they take over a hexagon's edge I set that edge to equal 1 or -1, then do some calculations involving a hasmap to find the opposite hexagon and edge and set that as claimed as well, but only if it isn't at the edge. Then I just used a sum function to find the net value to find whose control the hexagon is under. However this program gets quickly very fast, and I was unable to finish the skirmishing part of the program.

This was a good opportunity to learn about arrays (esp the SCOURGE of c-style arrays instead just std::array) and I've learnt about implementation of 2d arrays and hashmaps in C++, as well as other things. I might come back to solve this question properly.

## Q3
This one I kind of solved? My solution works by iterating through the input array to reconstruct the raw input data, then uses a recursive algorithm to apply it and get the entire list of permuatations, then finding the _i_th element. Actually now that I mention it that can be an optimization. Currently it gets stuck at the recursive part too easily. Will return to optimize at a later date.

This helped me to learn how to use vectors instead of arrays, as well as methods for the string datatpe like .find() and .clear()
