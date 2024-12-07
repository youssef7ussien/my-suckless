/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int horizpadbar        = 4;        /* horizontal padding for statusbar */
static const int vertpadbar         = 6;        /* vertical padding for statusbar */
static const int focusonwheel       = 0;
static const char *fonts[]          = { "JetBrainsMono NF:size=9", "NotoColorEmoji:pixelsize=9:antialias=true:autohint=true" };
static const char dmenufont[]       = "JetBrainsMono NFM:size=9";
static const char col_gray1[]       = "#1D1D1D";
static const char col_gray2[]       = "#8B7E72";
static const char col_gray3[]       = "#d5c4a1";
static const char col_gray4[]       = "#ebdbb2";
static const char col_gray5[]        = "#413F3D";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
  [SchemeNorm] = { col_gray3, col_gray1, col_gray5 },
	[SchemeSel]  = { col_gray4, col_gray5,  col_gray2  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *  WM_WINDOW_ROLE(STRING) = role
	 */
	/* class                  role        instance    title           tags mask    iscentered     switchtag    isfloating   monitor */
	{ "center-float",         NULL,         NULL,             NULL,       0,           1,             0,           1,          -1 },
	{ NULL,                   NULL,         "center-float",   NULL,       0,           1,             0,           1,          -1 },
	{ "nocenter-float",       NULL,         NULL,             NULL,       0,           0,             0,           1,          -1 },
	{ "LibreWolf",            "browser",    NULL,             NULL,       1,           0,             1,           0,           1 },
	{ "LibreWolf",            NULL,         "Devtools",       NULL,       0,           1,             0,           1,          -1 },
	{ "LibreWolf",            NULL,         "Toolkit",        NULL,       0,           1,             0,           1,          -1 },
	{ "LibreWolf",            "page-info",  NULL,             NULL,       0,           1,             0,           1,          -1 },
	{ "LibreWolf",            NULL,         "Places",         NULL,       0,           1,             0,           1,          -1 },
	{ "jetbrains-studio",     NULL,         NULL,             NULL,       1 << 1,      0,             0,           0,          -1 },
	{ "jetbrains-idea",       NULL,         NULL,             NULL,       1 << 1,      0,             0,           0,          -1 },
	{ "VSCodium",             NULL,         NULL,             NULL,       1 << 2,      0,             0,           0,          -1 },
	{ "Gimp",                 NULL,         NULL,             NULL,       1 << 7,      0,             1,           0,          -1 },
	{ "Inkscape",             NULL,         NULL,             NULL,       1 << 7,      0,             1,           0,          -1 },
	{ "Soffice",              NULL,         NULL,             NULL,       1 << 6,      0,             1,           0,          -1 },
	{ "Thunar",               NULL,         NULL,             NULL,       1 << 5,      0,             1,           0,          -1 },
	{ "discord",              NULL,         NULL,             NULL,       1 << 8,      1,             0,           1,          -1 },
	{ "Nsxiv",                NULL,         NULL,             NULL,       0,           1,             0,           1,          -1 },
	{ "Mousepad",             NULL,         NULL,             NULL,       0,           1,             0,           1,          -1 },
	{ "mpv",                  NULL,         NULL,             NULL,       0,           1,             0,           1,          -1 },
	{ "obsidian",             NULL,         NULL,             NULL,       1 << 6,      0,             0,           0,          -1 },
	{ "TelegramDesktop",      NULL,         NULL,             NULL,       1 << 8,      1,             1,           1,          -1 },
	{ "Qalculate-gtk",        NULL,         NULL,             NULL,       0,           1,             0,           1,          -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_gray5, "-sf", col_gray4, NULL };
// static const char *termcmd[]  = { "st", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
  // { MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ControlMask,           XK_j,      pushdown,       {0} },
	{ MODKEY|ControlMask,           XK_k,      pushup,         {0} },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ControlMask|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigstatusbar,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigstatusbar,   {.i = 5} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

