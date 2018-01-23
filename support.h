#include <time.h>
#ifndef declare
#define support extern
#define SG_LO_LIMIT	40
#define SG_HI_LIMIT	70
#else
#define support 
#endif

support Display*		display;
support int		screen_number;
support Window		mainwindow;
support char*		displayname;
support int		i;
support XEvent		event;
support long		event_mask;
support int		width,height;
support Bool		status;
support Twidgets		widgets;
support Window		widgwin;
support Window		afp1;
support Window		afp2;
support int		EndFlag;
support XColor		scr_clr,tmp_clr;
support XColor		colors[16];
support Colormap		colormap;
support int		board_ox;
support int		board_oy;
support int		hx,hy;
support Window		main_hscroll;
support Window		main_vscroll;
support Window		button_data;
support XColor		ColorRed;
support XColor		ColorGreen;
support XColor		ColorBackground;
support int		RODS,RodStep,CntrlRods;
support int		ANC,A,AK,AF,AM,AG,AD,AE;
support int		ALY1,ALY2,ALY3,ALY4,ALY5,ALY;
support int             BTN1,BTN2,BTN3,BTN4,BB,B;
support int             C;
support int		DP,DS;
support int		F1,F2,F3;
support int             HG,HR,HV,HY,JA,JB,JH,JI,JJ,JK,JL,JN,JO;
support int		JP,JQ,JR,JS,JT,JU,JV,JW,JX,JY,JZ,JF,JM,HB;
support int             JC,JG,HC,JE,HZ;
support int             LA,LB,LC,LD,LE,LF;
support int             PZ,PP;
support double		KA,GM,GN,GO,GP,KB,KC;
support double          GQ,GR,GS,GG,GI,GH,GJ,MP,GL;
support int             OldMwth,OldPower,OldPTemp,OldPPres,OldFlow,OldMass;
support int             OldSTemp,OldSPres,OldSG1,OldSG2,OldSG3;
support int             OldVKV,OldMVA,OldMW,OldMVAR,OldCurrent,OldRPM;
support char		AI,AJ,AL,AN,SY,TI;
support int		YA,YB,YC,YD,YE,YF,YG,YH,YI,YJ,YK,YL,YM,YN;
support int             D[45],LBa[11];
support int		SI,SD,S1,S2,S3,ST,SP;
support int		TP,TU;
support int		WC,WD,WG,WA,WB,WF,WH,WE;
support int		FP;
support int             ZE,ZB;
support long		Cycles,TotalMW,AvgMW;
support char		Buffer[1000];
support int		LoadMode;
support int		LoadCycle;
support int		EventMode;
support long		Score;
support int		PlantStatus;
support int		Warnings;
support int		Rcp1,Rcp2,Rcp3;
support char		Reactor;
support double		RandSeed;
support int		Breakdown;
support long            timeval;

#ifndef declare
extern int	rndm(int x);
#endif
