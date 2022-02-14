#### • In a file called clean place the command line that will search for all files - in the current directory as well as in its sub-directories - with a name ending by ~, or with a name that start and end by #
#### • The command line will show and erase all files found.
#### • Only one command is allowed: no ’;’ or ’&&’ or other shenanigans.
--------  
#### В файле с именем clean поместите командную строку, которая будет искать все файлы - в текущем каталоге, а также в его подкаталогах - заканчивая символом ~ и / или всеми файлами, которые начинаются или заканчиваются символом #. 
#### Командная строка покажет и удалит все найденные файлы. 
#### Допускается только одна команда: нельзя использовать ; или && или другие махинации.
        
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

	 -o	 == Или (возможно использовать(не проверял) "-or")

     -name pattern
             True if the last component of the pathname being examined matches
             pattern.  Special shell pattern matching characters (``['',
             ``]'', ``*'', and ``?'') may be used as part of pattern.  These
             characters may be matched explicitly by escaping them with a
             backslash (``\'').

     -print  This primary always evaluates to true.  It prints the pathname of
             the current file to standard output.  If none of -exec, -ls,
             -print, -print0, or -ok is specified, the given expression shall
             be effectively replaced by ( given expression ) -print.

     -delete
             Delete found files and/or directories.  Always returns true.
             This executes from the current working directory as find recurses
             down the tree.  It will not attempt to delete a filename with a
             ``/'' character in its pathname relative to ``.'' for security
             reasons.  Depth-first traversal processing is implied by this
             option.  Following symlinks is incompatible with this option.
--------  
#### Проверка:
```
cd ex08
ls
touch ff~ dd~ #ss# #ee#
ls
mkdir eee
cd eee
touch ffZ~ fdgf~ #fdhgf# #fvjhf#
ls
cd ..
bash clean
ls
```


#### (Не надо) Test:  
-- cat clean  

#### Output:  
-- #!/bin/sh find . -type f -name "##" -print -delete -o -type f -name "~" -print -delete

For more info:  
man find