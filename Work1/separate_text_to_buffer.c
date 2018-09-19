#include<stdio.h>
#include<string.h>



char text[4096]; //
char dest[40]; // test
char src[40];
#define line 97
#define size 40
char Buffer[line][size];



void convert_textto_buffer(char *str) {
  int count = 0;
  int Line = 0;
  int Size = 0;
  int cc = 0;
 
  while (*str != '\0') {
	count++;
    str++;
  
    if(*str == '\r'){
    	cc++;
    	Buffer[Line][Size] = '\r';
    	Size++;
    	Buffer[Line][Size] = '\n';
		str++;
		Line++;
		Size = 0;
		count = 0;
		
		
			
	}
	
	
	
	if(Size == size){
		Line++;
		Size = 0;
		
	}
	
	
	if(count != Size){
		Buffer[Line][Size] = *str;
		Size++;
	}

}

}


void main() {

  strcpy(text,"          ,! ,ORBIT ,R1D] #BJ\r\n\r\n\r\n  ,! ,ORBIT ,R1D] #BJ IS ! _W'S MO/\r\nAF=DABLE ,REFRE%ABLE ,BRL ,4PLAY4 ,X IS\r\nA UNIQUE #C-9-#A DEVICE & S]VES Z A\r\nSELF-3TA9$ BOOK R1D]1 A NOTE-TAK] & Z A\r\nBRL 4PLAY BY 3NECT+ TO A COMPUT] OR\r\nSM>TPH.O VIA ,,USB OR ,BLUETOO?4\r\n  ,EQUIPP$ ) A #BJ-CELL #H-DOT 4PLAY1 !\r\n,ORBIT ,R1D] #BJ IS BAS$ ON REVOLU;N>Y\r\nBRL CELL TE*NOLOGY DEVELOP$ BY ,ORBIT\r\n,RESE>*4 ,! BR1K.? TE*NOLOGY USES\r\nMA9/R1M COMPON5TS & MANUFACTUR+\r\nPROCESSES TO 5ABLE UNIQUE SIGNAGE-QUAL;Y\r\nREFRE%ABLE BRL AT A FRAC;N ( ! CO/ ( !\r\nPIEZOELECTRIC TE*NOLOGY T HAS BE5 US$ 9\r\nBRL CELLS S F>4\r\n  ,ORBIT ,RESE>* 2GAN DEVELOP+ ?\r\nTE*NOLOGY S.EAL YE>S AGO & DEVELOP$\r\nPROTOTYPES DEMON/RAT+ XS VIABIL;Y4 ,!\r\nTE*NOLOGY 0 APPLI$ TO CR1TE ! ,ORBIT\r\n,R1D] #BJ ) FUND+ F ! ,TRANS=M+ ,BRL\r\n,GRP .<,,TBG.>1 A 3SORTIUM ( BL;S\r\nORGANIZA;NS F >.D ! _W4 ,! ,,TBG 0 =M$ 9\r\n#BJAA .U ! L1D]%IP ( ,KEV9 ,C>EY1     #A\r\n,*AIR ( ! ,ROYAL ,NA;NAL ,9/ITUTE ( ,BL\r\n,P1 ) ! EXPRESS PURPOSE ( 9CR1S+ BRL\r\nLIT]ACY _WWIDE BY 5ABL+ A L[-CO/ BRL\r\n4PLAY4 ,! ,,TBG EVALUAT$ OV] #FJ DI6]5T\r\nTE*NOLOGIES 2F *OOS+ ,ORBIT ,RESE>* TO\r\nDEVELOP A L[-CO/ REFRE%ABLE BRL 4PLAY4\r\n  ,! ,ORBIT ,R1D] #BJ IS 9T5D$ TO 2 AN\r\nAF=DABLE FULLY F1TUR$ BRL DEVICE (F]+ !\r\n?REE KEY FUNC;NS T >E REQUIR$ BY MO/\r\nUS]S4\r\n  ,:5 US$ Z A /&AL.O R1D]1 X 5ABLES !\r\nUS] TO R1D ANY FILE F ! ;,,SD C>D4 ,^!\r\nCD 2 ,,BRF & ;,,BRL =MATT$ BOOKS1 TEXT\r\nFILES OR FILES 9 ANY =MAT4 ,? ALL[S\r\n/UD5TS1 ESPECIALLY 9 DEVELOP+ C.TRIES1\r\nTO H 3T5T LOAD$ ON TO ! ;,,SD C>D BY\r\nT1*]S & USE ! UNIT )T ANY LIVE\r\n3NECTIV;Y TO A COMPUT] OR ! 9T]NET4 ,!\r\nR1D] HAS F1TURES = EASY NAVIGA;N1 9S]T+\r\n& $IT+ BOOKM>KS1 BR[S+ .? FOLD]S1 ETC4\r\n  ,Z A BRL 4PLAY1 ! ,ORBIT ,R1D] 3NECTS\r\nTO ,,PC,'S & ,MACS1 I,,OS DEVICES &\r\n,&ROID DEVICES4 ,X PROVIDES ,BLUETOO? &\r\n,,USB 3NECTIV;Y & C 3NECT SIMULTANESLY\r\nTO MULTIPLE DEVICES4 ,US+ ! SCRE5     #B\r\nR1D+ CAPABIL;Y ON ! COMPUT+ DEVICE1 S* Z\r\n,VOICEOV]1 ,BRLBACK OR POPUL> ,,PC SCRE5\r\nR1D]S ! US] C 3TROL ! FUNC;NS ( YR\r\nCOMPUT] OR SM>TPH.O1 USE _! FAVORITE\r\nAPPS1 R1D & S5D TEXT MESSAGES & EMAIL &\r\nBR[SE ! 9T]NET4\r\n  ,Z A NOTE-TAK]1 ! ,ORBIT ,R1D] (F]S\r\nALL ESS5TIAL FILE CR1;N & $IT+ FUNC;NS4\r\n,A US] C CR1TE NEW FILES1 SAVE !M ON\r\n;,,SD C>D & $IT EXI/+ FILES4 ,! ,ORBIT\r\n,R1D] AL 9CLUDES FILE MANAGE;T F1TURES1\r\nALL[+ ! US] TO RE.N1 DELETE1 COPY1 &\r\nCR1TE FOLD]S & FILES4\r\n  ,! DEVICE IS 9H]5TLY LANGUAGE 9DEP5D5T\r\n& PROMPTS & M5US C 2 EASILY LOCALIZ$ =\r\nDI6]5T GEOGRAPHIES4\r\n  ,:ILE X (F]S A HO/ ( F1TURES1 ! UNIT\r\nREMA9S EXTREMELY EASY TO USE & ALL[S\r\nS1M.S & 9/ANTANES SWIT*+ 2T R1D]1 NOTE\r\nTAK] & BRL 4PLAY MODES1 Z WELL Z SELEC;N\r\n2T 3NECT$ DEVICES S* Z A COMPUT] OR\r\n H.O4\r\n  ,! ,ORBIT ,R1D] #BJ IS V COMPACT1\r\nM1SUR+ A LL OV] AN 9* 9 HEI<T & AB #F\r\n9*ES BY #D 9*ES & WEI<+ .U A P.D4     #C\r\n,X 9CLUDES A HI<-QUAL;Y ,P]K9S /YLE\r\nKEYBO>D ) #H KEYS & A SPACE B>4 ,X AL\r\nHAS A CURSOR PAD ) #D >R[ KEYS & A\r\nSELECT BUTTON1 Z WELL Z ROCK] KEYS ON\r\nEA* SIDE ( ! BRL 4PLAY TO 3TROL\r\nNAVIGA;N4\r\n  ,ON ! BACK ( ! UNIT IS A RECESS 9 : >E\r\nLOCAT$ AN ;,,SD ,C>D SLOT1 A ,,USB\r\n,MICRO ;,B SOCKET & A P[] BUTTON4\r\n  ,! UNIT IS P[]$ BY A US]-REPLAC1BLE\r\nFA/-*>G+ LI?IUM BATT]Y : IS RE*>G$ .? !\r\n\r\n,,USB PORT4 ,X IS FLUID & DU/ RESI/ANT &XS 3/RUC;N IS OPTIMIZ$ = DURABIL;Y 9\r\nEXTREME 5VIRON;TAL 3DI;NS4\r\n  ,! ,ORBIT ,R1D] #BJ W 2 AVAILABLE LAT\r\n? YE> ? ! MEMB] ORGANIZA;NS ( ! ,,TBG &\r\nF ,ORBIT ,RESE>*4 ,! :OLESALE PRICE TO\r\n,,TBG MEMB] ORGANIZA;NS W 2 @S#CBJ & !\r\nPRODUCT W AL 2 AVAILABLE TO O!R\r\n4TRIBUTORS AT A PRICE BAS$ ON VOLUME4\r\n\r\n#D");
  printf("strlen text strlen = %d\r\n",strlen(text));
  convert_textto_buffer(text);

int i = 0;


while(i!=100){
	
	printf("%s",Buffer[i]);
	i++;
}
	





}


