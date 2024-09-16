# Cosmic Monkey

This is a quick onboarding puzzle for new members of the Flight Software (FSW) 
subgroup of Brown Space Engineering. It's designed to help you get acquainted 
with C (and all of its weirdness).

In order to correctly write the `cosmic_monkey` function (and its accompanying 
`print_bytes` function for visualizing the result), you'll learn about pointers, 
bitwise operators, and bit masking --- all of which are central to embedded 
systems programming.

## Motivation

The name *"Cosmic Monkey"* comes from Netflix's 
[*"Chaos Monkey"*](https://github.com/Netflix/chaosmonkey?tab=readme-ov-file), a 
process that randomly terminates virtual machines and containers in the 
company's production environment to ensure that their software engineers 
implement instance failure-resilient services. In our satellite's operating 
system, ([PVDXosV2](https://github.com/BrownSpaceEngineering/PVDXosV2)), we have 
implemented a similar task that randomly flips bits to simulate what would 
happen if memory is corrupted by cosmic ray bit-flips. We have no control over 
when/where this radiation will mutate our memory, so having an angry task that 
goes around flipping bits is the best way to make sure PVDXos can recover if 
critical memory is corrupted.

> Best of luck programming; we are very grateful that you've chosen to join FSW!

## Instructions 

1. Have a look in the `stencil` folder, and implement the functions whose 
headers are specified in `./stencil/cosmic_monkey.c`
2. Modify your code so the printing in `cosmic_monkey()` only occurs if the 
`DEBUG` preprocessor macro is defined. 
([hint](https://www.cs.auckland.ac.nz/references/unix/digital/AQTLTBTE/DOCU_078.HTM))
3. Write a Makefile that compiles a `normal` and `debug` version of the 
`cosmic_monkey` executable. 
4. Add error-checking to OS function calls (this can be done in multiple ways; 
the solution code is particularly anal, we wouldn't consistently expect that 
level of error-checking). 
