/* See LICENSE file for copyright and license details. */


/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 2;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 8;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 0;     /* 0 means no systray */
static const unsigned int gappih    = 23;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 23;       /* vert inner gap between windows */
static const unsigned int gappoh    = 23;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 23;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            = 53;       /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const int vertpad            = 15;       /* vertical padding of bar (gap between screen and bar)*/
static const int sidepad            = 15;       /* horizontal padding of bar (gap between screen and bar)*/
static const int horizpadbar        = 1;        /* horizontal padding for statusbar (gap between bar and bar content)*/
static const int vertpadbar         = 1;        /* vertical padding for statusbar (gap between bar and bar content)*/
static const char *fonts[]          = { "JetBrainsMono Nerd Font:size=20", "Iosevka Nerd Font:pixelsize=29:antialias=true:autohint=true" };
static const char *upvol[]          = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "+5%",     NULL };
static const char *downvol[]        = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "-5%",     NULL };
static const char *mutevol[]        = { "/usr/bin/pactl", "set-sink-mute",   "@DEFAULT_SINK@", "toggle",  NULL };
//static const char col_gray1[]       = "#232731";#11121D || #2B2F37
//static const char col_gray2[]       = "#333333";
static const char col_gray1[]       = "#11121D"; // for bg
static const char col_gray2[]       = "#11121D"; // for tags
static const char col_gray3[]       = "#bbbbbb";
//static const char col_gray4[]       = "#eeeeee"; // mostly for text, fg
static const char col_gray4[]       = "#A1A8B2"; // mostly for text, fg
static const char col_cyan[]        = "#005577";
//static const char col_purple[]      = "#5a5aa4";
static const char col_purple[]      = "#9C7CD7";
static const char col_red[]         = "#d54646";
static const char col_green[]       = "#23d18b";
static const char col_yellow[]      = "#d7ba7d";
static const char col_blue[]        = "#81a1c1";
static const char col_magenta[]     = "#c586c0";
static const char col_white[]       = "#abb2bf";
static const char col_bg_alt[]      = "#292d38";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray4, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_purple,  col_purple  },
	[SchemeStatus]  = { col_gray4, col_gray1,  "#000000"  }, // Statusbar right {text,background,not used but cannot be empty}

	[SchemeTagsSel]  = { col_gray2, col_purple,  "#000000"  }, // Tagbar left selected {text,background,not used but cannot be empty}
    [SchemeTagsNorm]  = { col_gray4, col_gray1,  "#000000"  }, // Tagbar left unselected {text,background,not used but cannot be empty}

    [SchemeInfoSel]  = { col_gray4, col_gray1,  "#000000"  }, // infobar middle  selected {text,background,not used but cannot be empty}
    [SchemeInfoNorm]  = { col_gray2, col_gray1,  "#000000"  }, // infobar middle  unselected {text,background,not used but cannot be empty}
};

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* staticstatus */
static const int statmonval = 0;

/* tagging (12 tags lol)    */
static const char *tags[] = { "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  " };
/* alternative tagging (prolly cuz u have 12 tags) */
static const char *tagsalt[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12" };

static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 3;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 50;	/* how far above the bottom of the bar the line should appear (here set to user_bh) */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */


/* tag selection colors - right is bg if selected, other is foreground */
static const char *tagsel[][2] = {
  { "#e0af68", col_gray1 },
  { "#ff9e64", col_gray1 },
  { "#9ece6a", col_gray1 },
  { "#73daca", col_gray1 },
  { "#7dcfff", col_gray1 },
  { "#7aa2f7", col_gray1 },
  { "#9d7cd8", col_gray1 },
  { "#f7768e", col_gray1 },
  { "#db4b4b", col_gray1 },
  { "#c0caf5", col_gray1 },
  { "#737aa2", col_gray1 },
  { "#394b70", col_gray1 },
};


/* back to normal colors */
//static const char *tagsel[][2] = {
  //{ "#eeeeee", col_gray1 },
  //{ "#eeeeee", col_gray1 },
  //{ "#eeeeee", col_gray1 },
  //{ "#eeeeee", col_gray1 },
  //{ "#eeeeee", col_gray1 },
  //{ "#eeeeee", col_gray1 },
  //{ "#eeeeee", col_gray1 },
  //{ "#eeeeee", col_gray1 },
  //{ "#eeeeee", col_gray1 },
  //{ "#eeeeee", col_gray1 },
  //{ "#eeeeee", col_gray1 },
  //{ "#eeeeee", col_gray1 },
//};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            0,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "./patches/vanitygaps.c"

/* #include "./patches/fibonacci.c" */
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
    { "[\\]",     dwindle },
	{ "[M]",      monocle },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ NULL,       NULL },
    /* { "H[]",      deck },*/
	/* { "TTT",      bstack }, */
 	/* { "[@]",      spiral }, */
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
static const char *termcmd[]  = { "st", NULL };

#include <X11/XF86keysym.h>
#include "./patches/shiftview.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
	/* b (full), j (full), k (full), i (part), d (part), o (part) */
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_z,      spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_z,      spawn,		   SHCMD("st -e nvim ~/system/github.txt") },
	{ MODKEY,                       XK_b,      spawn,		   SHCMD("feh --bg-fill --randomize ~/Pics/wallpapers/select/* &") },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY|ShiftMask,             XK_j,      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      rotatestack,    {.i = -1 } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_space,  spawn,          SHCMD("dmenu_run -c -l 20") },
	{ MODKEY|ShiftMask,             XK_space,  setlayout,      {0} }, 
	/* o */
	{ MODKEY,                       XK_o,      spawn,		   SHCMD("brave --force-device-scale-factor=1.4") },
	{ MODKEY|ShiftMask,             XK_o,      spawn,		   SHCMD("firefox") },
	/* s */
	{ MODKEY,                       XK_s,      spawn,		   SHCMD("st -e gotop") },
	{ MODKEY|ShiftMask,             XK_s,      spawn,		   SHCMD("nautilus") },
	/* i */
	{ MODKEY,                       XK_i,      spawn,		   SHCMD("trello --force-device-scale-factor=1.5") },
	/* e */
  { MODKEY,                       XK_e,      spawn,		   SHCMD("~/bin/eww open launcher") },
	{ MODKEY|ShiftMask,             XK_e,      spawn,		   SHCMD("st -e tty-clock -t -c -C 4") },
	/* w */
  { MODKEY,                       XK_w,      spawn,		   SHCMD("~/bin/eww close-all") },
  { MODKEY|ShiftMask,             XK_w,      spawn,		   SHCMD("meteo") },
	/* r */
	{ MODKEY,                       XK_r,      spawn,		   SHCMD("st -e ranger") },
	{ MODKEY|ShiftMask,             XK_r,      spawn,		   SHCMD("com.github.sgpthomas.hourglass") },
	/* y */
	{ MODKEY,                       XK_y,      spawn,		   SHCMD("flameshot gui -p ~/Pics/screenshots") },
	{ MODKEY|ShiftMask,             XK_y,      spawn,		   SHCMD("flameshot full -p ~/Pics/screenshots") },
	/* v */
	{ MODKEY,                       XK_v,      spawn,		   SHCMD("code") },
	/* a */
	{ MODKEY,                       XK_a,      spawn,		   SHCMD("st -e calcurse") },
	{ MODKEY|ShiftMask,             XK_a,      spawn,		   SHCMD("pavucontrol") },
	/* m */
	{ MODKEY,                       XK_m,      spawn,		   SHCMD("st -e ncmpcpp") },
	{ MODKEY|ShiftMask,             XK_m,      spawn,		   SHCMD("discord") },
	/* n */
	{ MODKEY|ShiftMask,             XK_n,      spawn,		   SHCMD("spotify --force-device-scale-factor=1.5") },
  /* d */
	{ MODKEY,                       XK_d,      spawn,		   SHCMD("rofi -show drun") },
  /* p */
	{ MODKEY|ShiftMask,             XK_p,      togglealttag,   {0} },
	{ MODKEY,                       XK_semicolon,      spawn,  SHCMD("skippy-xd") },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY,                       XK_n,      shiftview,      {.i = +1 } },
	{ MODKEY,                       XK_p,      shiftview,      {.i = -1 } },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} }, // tile
	{ MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[1]} }, // tile
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[2]} }, // float
	/* { MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[3]} }, // float */
	{ MODKEY|ShiftMask,             XK_f,      togglefloating, {0} },
	{ MODKEY,                       XK_c,      setlayout,      {.v = &layouts[4]} }, // monocle
    { MODKEY|ShiftMask,           XK_c,      setlayout,      {.v = &layouts[5]} }, // dwindle
	{ MODKEY,                       XK_g,      togglegaps,     {0} },
	{ MODKEY|ShiftMask,             XK_g,      defaultgaps,    {0} },
	{ 0,                            XF86XK_AudioLowerVolume, spawn, {.v = downvol } },
	{ 0,                            XF86XK_AudioMute, spawn, {.v = mutevol } },
	{ 0,                            XF86XK_AudioRaiseVolume, spawn, {.v = upvol   } },
	{ MODKEY|ControlMask,		        XK_comma,  cyclelayout,    {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, cyclelayout,    {.i = +1 } },
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
	TAGKEYS(                        XK_0,                      9)
	TAGKEYS(                        XK_F5,                     10)
	TAGKEYS(                        XK_F6,                     11)
	{ MODKEY,                       XK_F2,      spawn,  SHCMD("dm-tool switch-to-greeter") },
	{ MODKEY|ShiftMask,             XK_F2,      spawn,  SHCMD("sudo systemctl hibernate") },
	//{ MODKEY,                       XK_F2,      spawn,  SHCMD("screenkey -s small --scr 1 -p fixed -g 600x100+2573+1330 --opacity .9 --font-color white") },
	//{ MODKEY,                       XK_F3,      spawn,  SHCMD("killall screenkey") },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	/* { MODKEY,                       XK_0,      view,           {.ui = ~0 } }, */
	/* { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } }, */
};


/* bindsym $mod+F1		        restart */
/* bindsym $mod+F2		        exec --no-startup-id screenkey -s small --scr 1 -p fixed -g 600x100+2573+1330 --opacity .9 --font-color white */
/* bindsym $mod+F3	          exec --no-startup-id killall screenkey */
/* bindsym $mod+F12	        exec $term -e nmtui */

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
