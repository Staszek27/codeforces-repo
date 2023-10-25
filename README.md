### README.md deprecated -- Work in progress

### Tool to create a file system for codeforces contests in an easy way

#### Step 1 [prepare a directory]

Launch line below to simply create a new directory:
`python3 preparer.py {name-of-round}`

#### Step 2 [write a solution]

Navigate to your newly created round directory in `rounds`. In order to write your solution with a fast check, use these files:
- wzor.cpp  <- here is your main file to create a solution.
- test.in   <- insert an input example here.
- launch.sh <- launch it when both `wzor.cpp` & `gen.cpp` are ready in order to test your solution on that sample.

If you successfully solve a problem, then you can end here.

#### Step 3 [test your solution]

However if you want to test your solution more specific (using a brut-force program), navigate to `rounds` once again and use these files:
- brut.cpp  <- if you have an idea for some slower solution for the given problem, write it there.
- gen.cpp   <- write a test generator there
- script.sh <- launch it when both `brut.cpp` & `gen.cpp` are ready to test you `wzor.cpp` solution

### Step 4 [use ready library scraps of codes]

1. In order to check the list of available algorithms, run: `python3 inject.py -ls` in your round directory, which you chosen before.
2. Choose one from listed programs to inject the algorithm to your `wzor.cpp` solution `python3 inject.py cht.cpp`. After that you will see `cht.cpp` content in your main code.
