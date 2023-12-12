![when a shell user dies -XKCD]https://imgs.xkcd.com/comics/admin_mourning.png[^1]

# 42minishell
## tremy & mjochum [^2]

> I like to go into a little shell and be a hermit and make music for a while.
> _Delta Goodrem_

Picture a Venn diagram. At the intersection of "42 Perpignan" and "things we have to do to move up in the world" sits MINISHELL, a 42 project where you, uhhh ... *checks notes* have to recode a SHELL interface.
Sounds easy?
It does. Except 78% of your time is spent checking the output of a specific function against bash to try and get the same result.
Virtually turning this endeavour into a sort of coding purgatory.

# Learning objectives
This project has very interesting individual concepts.
## builtins
cd, env, pwd, export, unset and exit are builtins functions we had to re-code.
They can be found in the [/builtins/](builtins)
 folder.
## forks
Turns out you have to enter child processes to work with pipes and execve. 
We also managed to get the PID of our program with forks.
But also, you can't run ALL the builtins in there. Export alone (outputs an alphebetically sorted list of all environment variables) has to be pipe-able. But you can't run "export PATH=etc/:path1/usr/:etcetc/".
## execve
Used for all the functions that arent builtins.
## infile and outfiles
to output into files, and takes files as input.
dup2() is your friends
## pipes
*sigh*

[^1]:https://xkcd.com/686/
[^2]:both very handsome and very cool
