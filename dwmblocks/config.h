//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
    /*Icon*/ /*Command*/               /*Update Interval*/   /*Update Signal*/
    {"",     "microphone-block.sh",    0,                    8},
    {"",     "volume-block.sh",        0,                    6},
    {"",     "battery-block.sh",       30,                   5},
    {"",     "temp-cpu-block.sh",      5,                    7},
    {"",     "cpu-usage-block.sh",     2,                    4},
    {"",     "ram-memory-block.sh",    5,                    3},
    {"",     "keyboard-block.sh",      0,                    2},
    {"",     "clock-block.sh",         5,                    1},
};

//Sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char *delim = "";

// Have dwmblocks automatically recompile and run when you edit this file in
// vim with the following line in your vimrc/init.vim:

// autocmd BufWritePost ~/.local/src/dwmblocks/config.h !cd ~/.local/src/dwmblocks/; sudo make install && { killall -q dwmblocks;setsid dwmblocks & }
