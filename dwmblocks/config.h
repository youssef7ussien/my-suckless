//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
    /*Icon*/ /*Command*/               /*Update Interval*/   /*Update Signal*/
    {"",     "microphone_block",       0,                    8},
    {"",     "volume_block",           0,                    6},
    {"",     "battery_block",          30,                   5},
    {"",     "temp_cpu_block",         5,                    7},
    {"",     "cpu_usage_block",        2,                    4},
    {"",     "ram_memory_block",       5,                    3},
    {"",     "keyboard_block",         0,                    2},
    {"",     "clock_block",            5,                    1},
};

//Sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char *delim = "";

// Have dwmblocks automatically recompile and run when you edit this file in
// vim with the following line in your vimrc/init.vim:

// autocmd BufWritePost ~/.local/src/dwmblocks/config.h !cd ~/.local/src/dwmblocks/; sudo make install && { killall -q dwmblocks;setsid dwmblocks & }
