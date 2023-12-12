/*
builtin list:
Your shell must implement the following builtins:
	X echo with option -n
	X cd with only a relative or absolute path
	X pwd with no options
	◦ export with no options
	X unset with no options
	X env with no options or arguments
	X exit with no options

// doc
ft_builtins.h

ft_exit.c
> ft_exit();
> static ft_free();
*/

/*
ft_split $PATH =
/nfs/homes/mjochum/bin:
/usr/local/sbin:
/usr/local/bin:
/usr/sbin:
/usr/bin:
/sbin:
/bin:
/usr/games:
/usr/local/games:
/snap/bin
cd:
	*temp
	*dir
	*old
	1.
	if no directory
	and $HOME empty
	do nothing

	2.
	if no dorectory
	and $HOME set to non empty
	cd sets $HOME as current

	3.
	if *dir is set
	and starts with '/' set temp = *dir

	4.
	if *dir starts with "." or ".."
	set curpath to *dir

	5.
	if *dir non null
	test every single concatenation of *$PATH and *dir 
!!	final path must end with '/'

?	6. set *curpath to *dir


	

*/
