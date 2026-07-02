FUNNY MATRIMONY CONSOLE APP - C PROJECT
=======================================

This project is made for beginner C programming students.
It uses only basic C topics:
- variable
- basic calculation
- condition
- loop
- switch case
- array
- pointer
- function
- structure
- header file
- text file read/write
- random number generation
- getter and setter style functions

PROJECT FILES
-------------
main.c          -> Main menu, login call, about page
user.h/user.c   -> User structure, register, login helper, view/edit profile, file save/load
quote.h/quote.c -> Random funny quote system using Quote.txt
match.h/match.c -> Suggested match score and sorting
calculator.h/c  -> Love calculator and marriage cost calculator
admin.h/admin.c -> Admin login and admin panel
helper.h/c      -> Input, line printing, pause, newline removing
app_config.h    -> Common constants and file names
Quote.txt       -> Funny quote database
users.txt       -> User data file

HOW TO COMPILE
--------------
Open terminal/cmd in this folder and run:

gcc main.c helper.c quote.c user.c match.c calculator.c admin.c -o matrimony_app

HOW TO RUN
----------
Linux/Mac:
./matrimony_app

Windows MinGW:
matrimony_app.exe

ADMIN LOGIN
-----------
Username: admin
Password: admin123

IMPORTANT NOTE
--------------
Do not type the pipe symbol | in any input.
The program automatically replaces it with / because | is used as the separator in users.txt.

TEXT FILE FORMAT
----------------
users.txt stores data like this:
active|id|email|password|name|gender|age|religion|district|profession|education|height|salary|hobby|maritalStatus|preferredAgeMin|preferredAgeMax|preferredDistrict|preferredEducation|preferredProfession

Quote.txt stores quotes like this:
CATEGORY|MIN|MAX|QUOTE

Example:
AGE|0|17|Bro, focus on school first. Love can wait outside the classroom.
SALARY|30000|79999|Stable income. Parents may start smiling.
