@ECHO OFF
PROMPT $p$g
PATH C:\DOS;C:\NC5;C:\UTIL;c:\tp\bin;c:\bc\bin;c:\ensemble;c:\pacc\bin;c:\windows;
SET TEMP=G:\TMP
MD G:\TMP
SET WATTCP.CFG=c:
date 12-9-2016
rem time
lh ctmouse
lh smartdrv
font
call slip8250.bat
call itime
lh nc