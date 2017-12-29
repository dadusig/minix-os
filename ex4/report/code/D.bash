-bash-4.2# cc ppid.c 
-bash-4.2# ps -l   
ST UID   PID  PPID  PGRP     SZ         RECV TTY  TIME CMD
 S   0   140     1   140   1304    (tty) vfs  co  0:00 -bash
 S   0   141     1   141    200    (tty) vfs  c1  0:00 getty
 S   0   142     1   142    200    (tty) vfs  c2  0:00 getty
 S   0   143     1   143    200    (tty) vfs  c3  0:00 getty
 S   0   146   145   146   1312    (wait) pm  p0  0:00 -bash
 W   0   165   146   146    272          vfs  p0  0:00 ps -l
-bash-4.2# 
-bash-4.2# ./a.out 146
145
-bash-4.2# ./a.out 143
1
-bash-4.2# ./a.out 200
0
-bash-4.2# 