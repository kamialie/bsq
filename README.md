# bsq
Task - find the biggest square on the given map, avoiding obstacles.

As you may notice, this was a team of two project. Our algorythm was making 
the biggest square possible, given the sizes of initial map. Then it would 
start checking from top left corner going to the right, then down, if it 
doesn't meet the requirement of avoiding obstacles, as our task was to find 
one that is the closest to the top, then closest to the left edge of the map. 
Our small optimization was moving the current square to not just one step 
to the right, but over furthest obstaclem if it found one on the way. 
If initial square didn't find a space to fit in, one step smaller one would 
start its journey from the top left corner. If map comes from standard input, 
we would first write it to "temporary" file, then work with that file. 
I know that it's a terrible practice, as we later learned about writing files 
to lists, if we don't know the overall size beforehand, but it was the brightest 
idea at the time :)

P.S. there is also a test_files directory, which would give you an idea of
what a valid map is
