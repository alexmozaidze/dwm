static const unsigned int borderpx  = 2;
static const unsigned int gappx     = 0;
static const unsigned int snap      = 32;
static const int showbar            = 0;
static const int topbar             = 1;
static const char *fonts[]          = { "LiberationMono:size=10" };

static const char black[]           = "#282C34";
static const char lighter_black[]   = "#646E82";
static const char gray[]            = "#ABB2BF";
static const char blue[]            = "#61AFEF";
static const char red[]             = "#E06C75";
static const char purple[]          = "#C678DD";
static const char green[]           = "#98C379";
static const char yellow[]          = "#E5C07B";
static const char cyan[]            = "#56B6C2";
static const char white[]           = "#F0F2F4";

static const char *colors[][3]      = {
	/*                 fg     bg      border   */
	[SchemeNorm]   = { gray,  black,  lighter_black },
	[SchemeSel]    = { white, red,    red           },
};

static const unsigned int baralpha = 150;
static const unsigned int borderalpha = OPAQUE;

static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, baralpha },
	[SchemeSel]  = { OPAQUE, baralpha, baralpha },
};

static const char *tags[] = { "  ", "  ", "  ", "  " };

static const Rule rules[] = {
	/* class         instance    title       tags mask     isfloating   monitor */
	{ "st-256color", NULL,       NULL,       1,            0,           -1 },
	{ "Emacs",       NULL,       NULL,       1,            0,           -1 },
	{ "Firefox",     NULL,       NULL,       2,            0,           -1 },
	{ "Gimp",        NULL,       NULL,       4,            0,           -1 },
	{ "Sxiv",        NULL,       NULL,       4,            0,           -1 },
	{ "Parole",      NULL,       NULL,       8,            0,           -1 },
	{ "MPlayer",     NULL,       NULL,       8,            0,           -1 },
};

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },
	{ "><>",      NULL },
	{ "[M]",      monocle },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "###",      gaplessgrid },
};

static const float mfact     = 0.55;
static const int nmaster     = 1;
static const int resizehints = 0;

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

static Key keys[] = {
	/* modifier                           key        function        argument */
	{ MODKEY,                             XK_b,      togglebar,      {0} },
	{ MODKEY,                             XK_n,      focusstack,     {.i = +1 } },
	{ MODKEY,                             XK_p,      focusstack,     {.i = -1 } },
	{ MODKEY,                             XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                             XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                             XK_q,      setmfact,       {.f = -0.05} },
	{ MODKEY,                             XK_e,      setmfact,       {.f = +0.05} },
	{ MODKEY,                             XK_Return, zoom,           {0} },
	{ MODKEY,                             XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,                   XK_c,      killclient,     {0} },
	{ MODKEY,                             XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                             XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                             XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                             XK_u,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                             XK_o,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                             XK_g,      setlayout,      {.v = &layouts[5] } },
	{ MODKEY|ShiftMask,                   XK_f,      togglefullscr,  {0} },
	{ MODKEY,                             XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,                   XK_space,  togglefloating, {0} },
	{ MODKEY,                             XK_j,      moveresize,     {.v = "0x 50y 0w 0h" } },
	{ MODKEY,                             XK_k,      moveresize,     {.v = "0x -50y 0w 0h" } },
	{ MODKEY,                             XK_l,      moveresize,     {.v = "50x 0y 0w 0h" } },
	{ MODKEY,                             XK_h,      moveresize,     {.v = "-50x 0y 0w 0h" } },
	{ MODKEY|ShiftMask,                   XK_j,      moveresize,     {.v = "0x 0y 0w 50h" } },
	{ MODKEY|ShiftMask,                   XK_k,      moveresize,     {.v = "0x 0y 0w -50h" } },
	{ MODKEY|ShiftMask,                   XK_l,      moveresize,     {.v = "0x 0y 50w 0h" } },
	{ MODKEY|ShiftMask,                   XK_h,      moveresize,     {.v = "0x 0y -50w 0h" } },
	{ MODKEY|ControlMask,                 XK_k,      moveresizeedge, {.v = "t"} },
	{ MODKEY|ControlMask,                 XK_j,      moveresizeedge, {.v = "b"} },
	{ MODKEY|ControlMask,                 XK_h,      moveresizeedge, {.v = "l"} },
	{ MODKEY|ControlMask,                 XK_l,      moveresizeedge, {.v = "r"} },
	{ MODKEY|ControlMask|ShiftMask,       XK_k,      moveresizeedge, {.v = "T"} },
	{ MODKEY|ControlMask|ShiftMask,       XK_j,      moveresizeedge, {.v = "B"} },
	{ MODKEY|ControlMask|ShiftMask,       XK_h,      moveresizeedge, {.v = "L"} },
	{ MODKEY|ControlMask|ShiftMask,       XK_l,      moveresizeedge, {.v = "R"} },
	{ MODKEY,                             XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,                   XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                             XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                             XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,                   XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,                   XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                             XK_minus,  setgaps,        {.i = -4 } },
	{ MODKEY,                             XK_equal,  setgaps,        {.i = +4 } },
	{ MODKEY|ShiftMask,                   XK_equal,  setgaps,        {.i = 0  } },
	{ MODKEY|ShiftMask,                   XK_q,      quit,           {0} },
	TAGKEYS( XK_1, 0 )
	TAGKEYS( XK_2, 1 )
	TAGKEYS( XK_3, 2 )
	TAGKEYS( XK_4, 3 )
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
