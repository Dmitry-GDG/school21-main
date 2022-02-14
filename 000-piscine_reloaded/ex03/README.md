#### • Write a command line that searches for all file names that end with ".sh" (without quotation marks) in the current directory and all its sub-directories. It should display only the file names without the .sh.
#### • Example of output:

#### Напишите командную строку, 
#### которая ищет в текущем каталоге и во всех его подкаталогах все файлы, 
#### имена которых заканчиваются на «.sh» (без кавычек) 
#### и отображает только их имена, без .sh.
        
```
$>./find_sh.sh | cat -e
find_sh$
file1$
file2$
file3$
$>
```
```
man find
```
	 .	 Искать в текущем и вложенных каталогах

     -type t
             True if the file is of the specified type.  Possible file types
             are as follows:

             b       block special
             c       character special
             d       directory
             f       regular file
             l       symbolic link
             p       FIFO
             s       socket

     -name pattern
             True if the last component of the pathname being examined matches
             pattern.  Special shell pattern matching characters (``['',
             ``]'', ``*'', and ``?'') may be used as part of pattern.  These
             characters may be matched explicitly by escaping them with a
             backslash (``\'').

     -exec utility [argument ...] ;
             True if the program named utility returns a zero value as its
             exit status.  Optional arguments may be passed to the utility.
             The expression must be terminated by a semicolon (``;'').  If you
             invoke find from a shell you may need to quote the semicolon if
             the shell would otherwise treat it as a control operator.  If the
             string ``{}'' appears anywhere in the utility name or the argu-
             ments it is replaced by the pathname of the current file.
             Utility will be executed from the directory from which find was
             executed.  Utility and arguments are not subject to the further
             expansion of shell patterns and constructs.

     -exec utility [argument ...] {} +
             Same as -exec, except that ``{}'' is replaced with as many path-
             names as possible for each invocation of utility.  This behaviour
             is similar to that of xargs(1).

     basename string [suffix]
     basename [-a] [-s suffix] string [...]
     The basename utility deletes any prefix ending with the last slash `/'
     character present in string (after first stripping trailing slashes), and
     a suffix, if given.  The suffix is not stripped if it is identical to the
     remaining characters in string.  The resulting filename is written to the
     standard output.  A non-existent suffix is ignored.  If -a is specified,
     then every argument is treated as a string as if basename were invoked
     with just one argument.  If -s is specified, then the suffix is taken as
     its argument, and all other arguments are treated as a string.

--------  


#### Test:
```
chmod +x find_sh.sh
cd ..
bash ex03/find_sh.sh | cat -e
```

#### More info:  
man find  
man basename  