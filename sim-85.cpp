#include <fstream>
#include <string>
#include<iostream>
#include<string.h>
#include<graphics.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<conio.h>
#include<dos.h>

#define INT_MAX_X 1300
#define INT_MAX_Y 750

using namespace std;
void main_graph();

int Tstate=1;
int status_graphics=1;
int status_fetch=0;
//make a disable graphics button

void logo()
{
for(int i=0 ;i<=120 ; i++)
    {
    setcolor(COLOR(0,i*2,1.3*i));
    settextstyle(9,0,7 );
    outtextxy(500,250,"SIM - 85");
    settextstyle(9,0,3 );
    outtextxy(500,350,"The Graphical Simulator");
    delay(10);
    }
for(int i=120 ;i>=0 ; i--)
    {
    setcolor(COLOR(0,i*2,1.3*i));
    settextstyle(9,0,7 );
    outtextxy(500,250,"SIM - 85");
    settextstyle(9,0,3 );
    outtextxy(500,350,"The Graphical Simulator");
    delay(5);
    }
    setcolor(WHITE);
    settextstyle( 11,0,1 );
    setfillstyle(SOLID_FILL,BLACK);
    bar(-10,-100,1400,800);
    delay(300);
}

int move(string status ,int start, int end ,int position)
{
    if(status_graphics)
    {

    if (status == "up")
        {int i ;
            for( i = start-1; i>start-13   ; i--)
                {
                    line(position+1,i-1,position+11,i-1);
                    delay(50);
                }
            for( i = start-1; i > end + 10 ; i--)
            {
                rectangle(position+1,i,position + 11,i-10);
                floodfill(position+3, i-1,WHITE);
                setcolor(0);
                line(position+1,i+1,position+11,i+1);
                setcolor(WHITE);
                delay(5);
            }
            setcolor(0);
            for( ; i > end ; i-- )
                {
                    line(position+1,i+1,position+11,i+ 1);
                    delay(50);
                }
            setcolor(WHITE);
        }

    if (status == "down")
        {int i ;
            for( i = start+3; i<start+13   ; i++)
                {
                    line(position+1,i-1,position+11,i-1);
                    delay(50);
                }
            for( i = start+3; i < end - 10 ; i++)
            {
                rectangle(position+1,i,position + 11,i+10);
                floodfill(position+3, i+1,WHITE);
                setcolor(0);
                line(position+1,i-1,position+11,i-1);
                setcolor(WHITE);
                delay(5);
            }
            setcolor(0);
            for(;i<end;i++)
                {
                    line(position+1,i-1,position+11,i-1);
                    delay(50);
                }
            setcolor(WHITE);
        }

    if (status == "right")
        {
            int i;
            for(i=start+1;   i<start+11   ;i++)
                {
                    line(i,position-1,i,position-11);
                    delay(50);
                }
            for(         ;   i<end        ;i++)
                {
                    line(i,position-1,i,position-11);
                    setcolor(0);
                    line(i-10,position-1,i-10,position-11);
                    setcolor(WHITE);
                    delay(5);
                }
                setcolor(0);
            for(         ;   i<end+10        ;i++)
                {
                    line(i-10,position-1,i-10,position-11);
                    delay(50);
                }
                setcolor(WHITE);
        }

    if (status == "left")
        {
            int i;
            for(i=start-1;   i>start-11   ;i--)
                {
                    line(i,position-1,i,position-11);
                    delay(50);
                }
            for(         ;   i>end        ;i--)
                {
                    line(i,position-1,i,position-11);
                    setcolor(0);
                    line(i+10,position-1,i+10,position-11);
                    setcolor(WHITE);
                    delay(5);
                }
                setcolor(0);
            for(         ;   i>end-10        ;i--)
                {
                    line(i+10,position-1,i+10,position-11);
                    delay(50);
                }
                setcolor(WHITE);
        }
}
}


int  move(string arg)
{
    if(status_graphics)
    {


    if(arg=="a to bus")
    {
        move("up",235,195,346);
        return 0;
    }

    if(arg=="bus to a")
    {
        move("down",195,235,346);
        return 0;
    }

    if(arg=="bus to temp")
    {
        move("down",195,235,496);
        return 0;
    }
    if(arg=="temp to bus")
    {
        move("up",235,195,496);
        return 0;
    }
    if(arg=="flip flop to bus")
    {
        move("up",235,195,636);
        return 0;
    }
    if(arg=="bus to flip flop")
    {
        move("down",195,235,636);
        return 0;
    }
    if(arg=="bus to ir")
    {
        move("down",180,235,796);
        return 0;
    }
    if(arg=="reg to bus")
    {
        move("up",235,199,946);
        return 0;
    }
    if(arg=="bus to reg")
    {
        move("down",199,235,946);
        return 0;
    }
    if(arg=="bus to ad buffer")
    {
        move("down",195,585,1026);
        return 0;
    }
    if(arg=="ad buffer to bus")
    {
        move("up",585,195,1026);
        return 0;
    }
    if(arg=="ir to id")
    {
        move("down",300,335,786);
        return 0;
    }
    if(arg=="id to cu")
    {
        move("down",400,435,781);
        return 0;
    }
    if(arg=="data to memory")
    {
//  rectangle(1040,620,1080,634);
        move("right",1040,1080,633);
        return 0;
    }
    if(arg=="data from memory")
    {
        move("left",1080,1040,633);
        return 0;
    }
    if(arg=="addr to memory")
    {
        setfillstyle(SOLID_FILL,COLOR(255,255,254));
        floodfill(1050,630,WHITE);
        floodfill(1050,666,WHITE);
        delay(1000);

        setfillstyle(SOLID_FILL,BLACK);
        floodfill(1050,630,WHITE);
        floodfill(1050,666,WHITE);
        return 0;
    }
    if(arg=="in bus")
    {
        setfillstyle(SOLID_FILL,COLOR(150,0,255));
        floodfill(282,142,WHITE);
        delay(1000);

        setfillstyle(SOLID_FILL,BLACK);
        floodfill(282,142,WHITE);
        return 0;
    }

    if(arg=="reg to buffers")
    {
        setfillstyle(SOLID_FILL,COLOR(255,255,254));
        floodfill(928,569,WHITE);
        delay(1000);
        setfillstyle(SOLID_FILL,BLACK);
        floodfill(928,569,WHITE);
        return 0;
    }

    if(arg=="alu to bus")
    {
        move("right",650,733,379);
        move("up",378,199,721);
        return 0;
    }
    if(arg=="a to alu")
    {
        move("down",300,383,346);
        move("right",346,431,383);
        return 0;
    }

    }
}


void show_creator()
{
    setcolor(BLACK);

    for(int i=0;i<400;i++)
    {
        arc(305 +i, 670,270,90,20);
        if(i%3==0)
        delay(1);

    }
        setcolor(WHITE);
    outtextxy(330,655," Yash             Atin             Shaurya      Nipun      Abhishek");
    outtextxy(330,670," Bhardwaj      Agnihotri      Kalia          Garg       Gupta");
    delay(4000);
        setcolor(BLACK);
    for(int i=399;i>2;i--)
    {
        arc(302 +i, 670,270,90,20);
    }
    setcolor(WHITE);
    setfillstyle( 11 ,COLOR(0,128,128)); // teal
    floodfill(350,670,WHITE);
}



int call_click(int status_run , int & status_fetch)
{
    Tstate++;
                setfillstyle(SOLID_FILL,BLACK);
                char s[10];
                sprintf(s,"%d",Tstate);
                bar(950,73,1060,90);
                outtextxy(950,73,"T-State");
                outtextxy(1030,73,s);
                Tstate%=8;

    while(status_run)
    {int xx,yy;
       getmouseclick(WM_LBUTTONDOWN,xx,yy);

            if(xx>1040&&xx<1160&&yy>6&&yy<45&&status_run)
            {
                // run all
                status_run=0;

                    setfillstyle(SOLID_FILL,COLOR(112,112,112));
                    floodfill(1045,8,WHITE);
                    setfillstyle(SOLID_FILL,BLACK);
                    delay(100);
                    floodfill(1045,8,WHITE);
                return status_run;
            }
            else if(xx>1170&&xx<1360&&yy>6&&yy<45 && status_run)

            {
                // run step by step
                status_run=1;

                    setfillstyle(SOLID_FILL,COLOR(112,112,112));
                    floodfill(1175,8,WHITE);
                    setfillstyle(SOLID_FILL,BLACK);
                    delay(100);
                    floodfill(1175,8,WHITE);
                return status_run;
            }

            else if( xx>280&&xx<320&&yy>650&&yy<690 )
            {
                show_creator();
            }
            else if(xx>910&&xx<1030&&yy>6&&yy<45 && status_run)
            {
                // fetch
                status_fetch=!status_fetch;
                if(status_fetch==0)
                {
                    setfillstyle(SOLID_FILL,BLACK);
                    floodfill(920,8,WHITE);
                    setfillstyle(SOLID_FILL,BLACK);

                    }

                if(status_fetch==1)
                {
                    setfillstyle(SOLID_FILL,RED);
                    floodfill(920,8,WHITE);
                    setfillstyle(SOLID_FILL,WHITE);
                }

            }

            else if(xx>780&&xx<900&&yy>6&&yy<45 && status_run)
            {

                // status graphics
                status_graphics=!status_graphics;
                if(status_graphics==1)
                {
                    setfillstyle(SOLID_FILL,BLACK);
                    floodfill(785,8,WHITE);
                    setfillstyle(SOLID_FILL,WHITE);
                    }

                if(status_graphics==0)
                {
                    setfillstyle(SOLID_FILL,RED);
                    floodfill(785,8,WHITE);
                    setfillstyle(SOLID_FILL,WHITE);
                }

            }
    }
return status_run;
}




int load(string arg)
{
    if(status_graphics)
    {


    setfillstyle(SOLID_FILL,RED);
    if(arg=="a")
    {
        floodfill(302,252,WHITE);
        delay(500);return 0;
    }
    if(arg=="b")
    {
        floodfill(892,252,WHITE);
        delay(500);return 0;
    }
    if(arg=="c")
    {
        floodfill(952,252,WHITE);
        delay(500);return 0;
    }
    if(arg=="d")
    {
        floodfill(892,302,WHITE);
        delay(500);return 0;

    }
    if(arg=="e")
    {
        floodfill(952,302,WHITE);
        delay(500);return 0;
    }
    if(arg=="h")
    {
        floodfill(892,352,WHITE);
        delay(500);return 0;
    }
    if(arg=="l")
    {
        floodfill(952,352,WHITE);
        delay(500);return 0;
    }
    if(arg=="sp")
    {
        floodfill(892,402,WHITE);
        delay(500);return 0;
    }
    if(arg=="pc")
    {
        floodfill(892,452,WHITE);
        delay(500);return 0;
    }
    if(arg=="idl")
    {
        floodfill(892,502,WHITE);
        delay(500);return 0;
    }
    if(arg=="ir")
    {
        floodfill(752,252,WHITE);
        delay(500);return 0;
    }
    if(arg=="flip flop")
    {
        floodfill(602,252,WHITE);
        delay(500);return 0;
    }
    if(arg=="temp")
    {
        floodfill(452,252,WHITE);
        delay(500);return 0;
    }
    if(arg=="addr buffer")
    {
        floodfill(852,602,WHITE);
        delay(500);return 0;
    }
    if(arg=="data buffer")
    {
        floodfill(952,602,WHITE);
        delay(500);return 0;
    }
    if(arg=="inst decoder")
    {
        floodfill(752,352,WHITE);
        delay(500);return 0;
    }
    if(arg=="ale")
    {
        floodfill(412,597,WHITE);
        delay(500);return 0;
    }
    if(arg=="rd")
    {
        floodfill(467,597,WHITE);
        delay(500);return 0;
    }
    if(arg=="wr")
    {
        floodfill(522,597,WHITE);
        delay(500);return 0;
    }
    if(arg=="iom")
    {
        floodfill(577,597,WHITE);
        delay(500);return 0;
    }
    if(arg=="s1")
    {
        floodfill(632,597,WHITE);
        delay(500);return 0;
    }
    if(arg=="s2")
    {
        floodfill(687,597,WHITE);
        delay(500);return 0;
    }
    if(arg=="clock")
    {
        floodfill(742,597,WHITE);
        delay(500);return 0;
    }

delay(500);
    }
return 0;
}



int enable(string arg)
{
    if(status_graphics)
    {


    setfillstyle(SOLID_FILL,GREEN);
    if(arg=="a")
    {
        floodfill(302,252,WHITE);
        delay(500);return 0;
    }
    if(arg=="b")
    {
        floodfill(892,252,WHITE);
        delay(500);return 0;
    }
    if(arg=="c")
    {
        floodfill(952,252,WHITE);
        delay(500);return 0;
    }
    if(arg=="d")
    {
        floodfill(892,302,WHITE);
        delay(500);return 0;

    }
    if(arg=="e")
    {
        floodfill(952,302,WHITE);
        delay(500);return 0;
    }
    if(arg=="h")
    {
        floodfill(892,352,WHITE);
        delay(500);return 0;
    }
    if(arg=="l")
    {
        floodfill(952,352,WHITE);
        delay(500);return 0;
    }
    if(arg=="sp")
    {
        floodfill(892,402,WHITE);
        delay(500);return 0;
    }
    if(arg=="pc")
    {
        floodfill(892,452,WHITE);
        delay(500);return 0;
    }
    if(arg=="idl")
    {
        floodfill(892,502,WHITE);
        delay(500);return 0;
    }
    if(arg=="ir")
    {
        floodfill(752,252,WHITE);
        delay(500);return 0;
    }
    if(arg=="flip flop")
    {
        floodfill(602,252,WHITE);
        delay(500);return 0;
    }
    if(arg=="temp")
    {
        floodfill(452,252,WHITE);
        delay(500);return 0;
    }
    if(arg=="addr buffer")
    {
        floodfill(852,602,WHITE);
        delay(500);return 0;
    }
    if(arg=="data buffer")
    {
        floodfill(952,602,WHITE);
        delay(500);return 0;
    }
    if(arg=="inst decoder")
    {
        floodfill(752,352,WHITE);
        delay(500);return 0;
    }
    if(arg=="ale")
    {
        floodfill(412,597,WHITE);
        delay(500);return 0;
    }
    if(arg=="rd")
    {
        floodfill(467,597,WHITE);
        delay(500);return 0;
    }
    if(arg=="wr")
    {
        floodfill(522,597,WHITE);
        delay(500);return 0;
    }
    if(arg=="iom")
    {
        floodfill(577,597,WHITE);
        delay(500);return 0;
    }
    if(arg=="s1")
    {
        floodfill(632,597,WHITE);
        delay(500);return 0;
    }
    if(arg=="s2")
    {
        floodfill(687,597,WHITE);
        delay(500);return 0;
    }
    if(arg=="clock")
    {
        floodfill(742,597,WHITE);
        delay(500);return 0;
    }
delay(500);
}
return 0;
}

int disable(string arg)
{
    if(status_graphics)
    {


    setfillstyle(SOLID_FILL,BLACK);
    if(arg=="a")
    {
        floodfill(302,252,WHITE);
         return 0;
    }
    if(arg=="b")
    {
        floodfill(892,252,WHITE);
         return 0;
    }
    if(arg=="c")
    {
        floodfill(952,252,WHITE);
         return 0;
    }
    if(arg=="d")
    {
        floodfill(892,302,WHITE);
         return 0;

    }
    if(arg=="e")
    {
        floodfill(952,302,WHITE);
         return 0;
    }
    if(arg=="h")
    {
        floodfill(892,352,WHITE);
         return 0;
    }
    if(arg=="l")
    {
        floodfill(952,352,WHITE);
         return 0;
    }
    if(arg=="sp")
    {
        floodfill(892,402,WHITE);
         return 0;
    }
    if(arg=="pc")
    {
        floodfill(892,452,WHITE);
         return 0;
    }
    if(arg=="idl")
    {
        floodfill(892,502,WHITE);
         return 0;
    }
    if(arg=="ir")
    {
        floodfill(752,252,WHITE);
         return 0;
    }
    if(arg=="flip flop")
    {
        floodfill(602,252,WHITE);
         return 0;
    }
    if(arg=="temp")
    {
        floodfill(452,252,WHITE);
         return 0;
    }
    if(arg=="addr buffer")
    {
        floodfill(852,602,WHITE);
         return 0;
    }
    if(arg=="data buffer")
    {
        floodfill(952,602,WHITE);
         return 0;
    }
    if(arg=="inst decoder")
    {
        floodfill(752,352,WHITE);
         return 0;
    }
    if(arg=="ale")
    {
        floodfill(412,597,WHITE);
         return 0;
    }
    if(arg=="rd")
    {
        floodfill(467,597,WHITE);
         return 0;
    }
    if(arg=="wr")
    {
        floodfill(522,597,WHITE);
         return 0;
    }
    if(arg=="iom")
    {
        floodfill(577,597,WHITE);
         return 0;
    }
    if(arg=="s1")
    {
        floodfill(632,597,WHITE);
         return 0;
    }
    if(arg=="s2")
    {
        floodfill(687,597,WHITE);
         return 0;
    }
    if(arg=="clock")
    {
        floodfill(742,597,WHITE);
         return 0;
    }
  }
 return 0;
}

int cord = 127;
int status_run=1;
std::ifstream infile; //create ofstream object

struct refrence {              // conditional jumps
	string ref_name;
	int addr;
};



void main_graph()
{
    rectangle(300,250,400,300);      //accumulator
    outtextxy(310,255,"Accumulator");      //accumulator
    rectangle(450,250,550,300);      //Temorary register
    outtextxy(460,255,"Temp");
    rectangle(600,250,700,300);      //Flag flip flop
    outtextxy(610,255,"Flag flip flop");
    rectangle(750,250,850,300);      //instruction register
    outtextxy(760,255,"Inst. Reg");
    rectangle(890,250,1010,550);     //register array

    line(890,300,1010,300);          //horizontal
    line(890,350,1010,350);
    line(890,400,1010,400);
    line(890,450,1010,450);
    line(890,500,1010,500);
    line(950,250,950,400);

// made by

circle(300, 670 , 20 );
outtextxy( 290,662 ,"By");

    outtextxy(1150-250,255,"Reg B");
    outtextxy(1206-250,255,"Reg C");
    outtextxy(1150-250,305,"Reg D");
    outtextxy(1206-250,305,"Reg E");
    outtextxy(1150-250,355,"Reg H");
    outtextxy(1206-250,355,"Reg L");
    outtextxy(1155-250,405,"Stack Pointer");
    outtextxy(1148-250,455,"Program Counter");
    outtextxy(1155-250,505,"Inc. Dec. Addr");
// boxex  processor and tool bar
{
    rectangle(450,350,650,400);        //alu
    outtextxy(710-250,360,"A.L.U.");

    rectangle(750,350,850,400);         //instruction decoder
    outtextxy(1005-250,360,"Inst. Decoder");

    rectangle(400,450,800,625);         //timing and control
    outtextxy(725-250,505,"Timing And Control");

    rectangle(410,595,455,620);         //ALE
    outtextxy(665-250,570,"ALE");

    rectangle(465,595,510,620);         // !(RD)
    outtextxy(720-250,570,"!(RD)");

    rectangle(520,595,565,620);         // !(WR)
    outtextxy(775-250,570,"!(WR)");

    rectangle(575,595,620,620);         //IO/!(M)
    outtextxy(825-250,570,"IO/!(M)");

    rectangle(630,595,675,620);         //S1
    outtextxy(890-250,570,"S1");

    rectangle(685,595,730,620);            //S2
    outtextxy(945-250,570,"S2");

    rectangle(740,595,785,620);         //CLOCK
    outtextxy(995-250,570,"CLOCK");

    rectangle(850,600,940,690);         //ADDRESS BUFFER A15-A8
    outtextxy(1102-250,601,"Addr. Buffer");
    outtextxy(1102-250,616,"A15-A8");
    rectangle(940,665,1080,679);

    rectangle(950,600,1040,650);        //ADDRESS BUFFER AD7-AD0
    outtextxy(1202-250,601,"Addr. Buffer");
    outtextxy(1202-250,616,"AD7-AD0");

    rectangle(1040,620,1080,634);

    rectangle(280,140,1050,180);         //8 BIT INTERNAL DATABUS
    outtextxy(590-250,150,"8 BIT INTERNAL DATABUS");

    rectangle(0,0,1300,58);             //TOOLBAR

    rectangle(2,1,1298,55);

    rectangle(11,7,87,42);              //
    rectangle(10,6,90,45);
    outtextxy(280-250,15,"OPEN");


    rectangle(101,7,180,42);
    rectangle(100,6,183,45);
    outtextxy(353-250,15,"ASSEMBLE");

    rectangle(782,7,897,42);    // DISABLE GRAPHICS
    rectangle(780,6,900,45);   // DISABLE GRAPHICS
    outtextxy(783,15,"Disable Graphics");


    rectangle(912,7,1027,42);    // SKIP FETCH
    rectangle(910,6,1030,45);   // SKIP FETCH
    outtextxy(935,15,"SKIP FETCH");

    rectangle(1041,7,1157,42);          //RUN ALL
    rectangle(1040,6,1160,45);          //RUN ALL
    outtextxy(1324-250,15,"RUN ALL");

    rectangle(1171,7,1287,42);          //RUN STEP BY STEP
    rectangle(1170,6,1290,45);          //RUN STEP BY STEP
    outtextxy(1435-250,15,"Step By Step");

}

    ///////////////******** LEFT SIDE OF GRAPHICS ***********//////////////
{
    rectangle(10,75,110,99);            //LABEL ASSEMBLER
    outtextxy(13,78,"ASSEMBLER");

    line(110,75,120,99);
    rectangle(10,100,260,750);          //ASSEMBLER ARRAY

    for(register int i=125;i<=725;i+=25)
    	line(10,i,260,i);

    /////********* VERTICAL LINES **********////////////

    line(60,100,60,750);
    line(110,100,110,750);
    line(160,100,160,750);
    line(210,100,210,750);
    outtextxy(13,103,"Addr.");
    outtextxy(63,103,"Label");
    outtextxy(113,103,"Opcode");
    outtextxy(173,103,"HEX");
    outtextxy(218,103,"TState");

}

    ////////***** Right side of graphics **********///////
    rectangle(1080,100,1280,250);          //REGISTER MAP
    rectangle(1080,75,1180,99);            //LABEL REGISTER
    outtextxy(1340-250,77,"Register");
    outtextxy(1340-250,103,"REG");
    outtextxy(1385-250,103,"Value");
    outtextxy(1440-250,103,"Flag");
    outtextxy(1485-250,103,"Value");
    line(1130,100,1130,250);
    line(1180,100,1180,250);
    line(1230,100,1230,250);
    // registers
    outtextxy(1340-250,103+25,"SP");
    outtextxy(1340-250,103+50,"PSW");
    outtextxy(1340-250,103+75,"PC");
    outtextxy(1335-250,103+100,"CLOCK");
    // flags
    outtextxy(1440-250,103+25,"S");
    outtextxy(1440-250,103+50,"Z");
    outtextxy(1440-250,103+75,"AC");
    outtextxy(1440-250,103+100,"P");
    outtextxy(1440-250,103+125,"CY");

for (register int i = 125; i <= 225; i+=25)
    line(1080,i,1280,i);

    rectangle(1080,325,1280,725);   //MEMORY MAP
    rectangle(1080,300,1280,325);   //LABEL MEMORY
    outtextxy(1085,305,"Memory :");

    line(1130,325,1130,725);
    line(1180,325,1180,725);
    line(1230,325,1230,725);
    outtextxy(1085,330,"Addr");
    outtextxy(1135,330,"Value");
    outtextxy(1185,330,"Addr");
    outtextxy(1235,330,"Value");
for (register int i = 350; i <= 700; i+=25)
    line(1080,i,1280,i);

    rectangle(270,70,1070,129);          //COMMENTS WINDOW
    outtextxy(280,73,"Comments:");
    ///////***************CONNECTION LINES*****//////

//  connection lines and triangele
{

    setfillstyle(SOLID_FILL,COLOR(255,0,0) );
    int poly[8];
    rectangle(346,195,358,235);     //DATABUS TO ACCUMULATOR

    poly[0]=603-250;
    poly[1]=181;
    poly[2]=585-250;
    poly[3]=195;
    poly[4]=621-250;
    poly[5]=195;
    poly[6]=poly[0];
    poly[7]=poly[1];
    drawpoly(4,poly);floodfill(poly[0] ,poly[1]+2,WHITE);


    poly[0]=603-250;
    poly[1]=250;
    poly[2]=585-250;
    poly[3]=235;
    poly[4]=621-250;
    poly[5]=235;
    poly[6]=poly[0];
    poly[7]=poly[1];
    drawpoly(4,poly);floodfill(poly[0] ,poly[1]-2,WHITE);

    rectangle(496,195,508,235);     //DATABUS TO TEMPORARY REGISTER

    poly[0]=752-250;
    poly[1]=181;
    poly[2]=734-250;
    poly[3]=195;
    poly[4]=770-250;
    poly[5]=195;
    poly[6]=poly[0];
    poly[7]=poly[1];
    drawpoly(4,poly);floodfill(poly[0] ,poly[1]+2,WHITE);

    poly[0]=752-250;
    poly[1]=250;
    poly[2]=734-250;
    poly[3]=235;
    poly[4]=770-250;
    poly[5]=235;
    poly[6]=poly[0];
    poly[7]=poly[1];
    drawpoly(4,poly);floodfill(poly[0] ,poly[1]-2,WHITE);

    rectangle(636,195,648,235);     //DATABUSTO FLAG FLIP FLOP

    poly[0]=892-250;
    poly[1]=181;
    poly[2]=874-250;
    poly[3]=195;
    poly[4]=910-250;
    poly[5]=195;
    poly[6]=poly[0];
    poly[7]=poly[1];
    drawpoly(4,poly);floodfill(poly[0] ,poly[1]+2,WHITE);

    poly[0]=892-250;
    poly[1]=250;
    poly[2]=874-250;
    poly[3]=235;
    poly[4]=910-250;
    poly[5]=235;
    poly[6]=poly[0];
    poly[7]=poly[1];
    drawpoly(4,poly);floodfill(poly[0] ,poly[1]-2,WHITE);

    rectangle(796,180,808,235);     //DATABUS TO IR

    poly[0]=1052-250;
    poly[1]=250;
    poly[2]=1034-250;
    poly[3]=235;
    poly[4]=1070-250;
    poly[5]=235;
    poly[6]=poly[0];
    poly[7]=poly[1];
    drawpoly(4,poly);floodfill(poly[0] ,poly[1]-2,WHITE);

    line(615,300,615,350);
    line(620,300,620,350);
    line(625,300,625,350);
    line(630,300,630,350);
    line(635,300,635,350);

    rectangle(496,300,508,335);     //TEMP REGISTER TO ALU

    poly[0]=752-250;
    poly[1]=350;
    poly[2]=734-250;
    poly[3]=335;
    poly[4]=770-250;
    poly[5]=335;
    poly[6]=poly[0];
    poly[7]=poly[1];
    drawpoly(4,poly);floodfill(poly[0] ,poly[1]-2,WHITE);

    rectangle(786,300,798,335);     //IR TO ID

    poly[0]=1042-250;
    poly[1]=350;
    poly[2]=1024-250;
    poly[3]=335;
    poly[4]=1060-250;
    poly[5]=335;
    poly[6]=poly[0];
    poly[7]=poly[1];
    drawpoly(4,poly);floodfill(poly[0] ,poly[1]-2,WHITE);


    rectangle(781,400,795,435);     //ID TO TIME AND CONTROL

    poly[0]=1037-250;
    poly[1]=450;
    poly[2]=1019-250;
    poly[3]=435;
    poly[4]=1055-250;
    poly[5]=435;
    poly[6]=poly[0];
    poly[7]=poly[1];
    drawpoly(4,poly);floodfill(poly[0] ,poly[1]-2,WHITE);


    rectangle(946,200,958,235); //BUS TO REGISTER ARRAY

    poly[0]=1202-250;
    poly[1]=184;
    poly[2]=1186-250;
    poly[3]=199;
    poly[4]=1220-250;
    poly[5]=199;
    poly[6]=poly[0];
    poly[7]=poly[1];
    drawpoly(4,poly);floodfill(poly[0] ,poly[1]+2,WHITE);

    poly[0]=1202-250;
    poly[1]=250;
    poly[2]=1186-250;
    poly[3]=235;
    poly[4]=1220-250;
    poly[5]=235;
    poly[6]=poly[0];
    poly[7]=poly[1];
    drawpoly(4,poly);floodfill(poly[0] ,poly[1]-2,WHITE);


    rectangle(916,550,928,585);     //REG ARRAY TO ADDRESS BUFFER

    poly[0]=1172-250;
    poly[1]=600;
    poly[2]=1154-250;
    poly[3]=585;
    poly[4]=1190-250;
    poly[5]=585;
    poly[6]=poly[0];
    poly[7]=poly[1];
    drawpoly(4,poly);floodfill(poly[0] ,poly[1]-2,WHITE);


    rectangle(976,579,988,585);     //REG ARRAY TO LATCH TO ADD/DATA BUFFE

    poly[0]=1232-250;
    poly[1]=600;
    poly[2]=1214-250;
    poly[3]=585;
    poly[4]=1250-250;
    poly[5]=585;
    poly[6]=poly[0];
    poly[7]=poly[1];
    drawpoly(4,poly);floodfill(poly[0] ,poly[1]-2,WHITE);

    rectangle(928,567,988,579);     //HORIZONTAL LINE FOR ABOVE

    rectangle(1026,195,1038,585);   //BUS TO ADDRESS DATA BUFFER
    //setlinestyle(1,0,1);

    setcolor(0);

    line(976,579,987,579);
    line(928,567,928,579);

    setcolor(WHITE);

    poly[0]=1282-250;
    poly[1]=183;
    poly[2]=1264-250;
    poly[3]=195;
    poly[4]=1300-250;
    poly[5]=195;
    poly[6]=poly[0];
    poly[7]=poly[1];
    drawpoly(4,poly);floodfill(poly[0] ,poly[1]+2,WHITE);

    poly[0]=1282-250;
    poly[1]=600;
    poly[2]=1264-250;
    poly[3]=585;
    poly[4]=1300-250;
    poly[5]=585;
    poly[6]=poly[0];
    poly[7]=poly[1];
    drawpoly(4,poly);floodfill(poly[0] ,poly[1]-2,WHITE);

    rectangle(346,300,358,371);     //ACCUMULATOR TO ALU VERTICAL

    poly[0]=696-250;
    poly[1]=377;
    poly[2]=681-250;
    poly[3]=395;
    poly[4]=681-250;
    poly[5]=359;
    poly[6]=poly[0];
    poly[7]=poly[1];
    drawpoly(4,poly);floodfill(poly[0]-2 ,poly[1],WHITE);

    rectangle(346,371,431,383);     //HORIZONTAL FOR ABOVE


    setcolor(0);

    line(347,371,358,371);
    setcolor(WHITE);

    rectangle( 721 , 199 , 733 , 188+191 ); //BUS TO ALU VERTICAL
    poly[0]=977-250;
    poly[1]=184;
    poly[2]=959-250;
    poly[3]=199;
    poly[4]=995-250;
    poly[5]=199;
    poly[6]=poly[0];
    poly[7]=poly[1];
    drawpoly(4,poly);floodfill(poly[0] ,poly[1]+2,WHITE);
    rectangle(650,367,650+83,379);  //HORIZONTAL FOR ABOVE

    setcolor(0);

    line(721,367,732,367);
    line(721,367,721,378);

    setcolor(WHITE);
}
  //  setfillstyle( 11 ,COLOR(176,224,230));
    setfillstyle( 11 ,COLOR(0,128,128)); // teal
    floodfill(300,400,WHITE);
    floodfill(600,200,WHITE);
    floodfill(945,655,WHITE);
}


class byte1{
public:
	char hex1,hex2;

	byte1 ()
    {
        hex1=hex2=255;
    }// incriment byte1 or extend bite infact alu's most operations
    void show_byte() const
    {
	if(hex1 != 255)
		cout << hex1 ;


	if(hex2 != 255)
		cout<< hex2 ;

	cout<<"\n" ;
    }
	friend ostream & operator << ( ostream & din ,byte  b);
	friend void print_byte(char a , char b ,int x, int cord );

};




struct flag
{
	int s,z ,p,cy,ac;
};


class reg1b {

	public :
	byte1 b;

	reg1b()
	{
		b.hex1     =b.hex2='0';
	}

	reg1b(byte1 a)
	{
		b.hex1=a.hex1  ;   b.hex2=a.hex2;
	}
	reg1b ( int dec )
	{
		char hexa[2];
		hexa[0]=hexa[1]='0';
		int quotient;
    	quotient = dec;
    	int  temp1;
    	int i=0 ;
    	while(quotient!=0)
    	{
        	 temp1 = quotient % 16;

      			if( temp1 < 10)
           			temp1 =temp1 + 48;
      			else
         			temp1 = temp1 + 55;

      		hexa[i++]= temp1;
      		quotient = quotient / 16;
    	}
    	b.hex1=hexa[1];
    	b.hex2=hexa[0];
	}

	friend int returndec_1_byte(reg1b a);

	void display_reg1b(int x =1140 )
	{
		cout << b.hex1 <<b.hex2<< endl;//98713
            char s[100];
		    sprintf(s,"%c",b.hex1);
            outtextxy(x,cord,s);
            sprintf(s,"%c",b.hex2);
            outtextxy(x+10,cord,s);
	}

	flag operator - (reg1b temp)
	{
		int a,t;
		flag f;
		f.ac=0;
		a = returndec_1_byte ( *this );
		t = returndec_1_byte ( temp );
		a -= t;

		if(a<0)
			{
			    f.s=1;
			    a=256+a;
			}
		else
			f.s=0;

		if(a==0)
			f.z=1;
		else
			f.z=0;

		if(a>255)
			f.cy=1;
		else
			f.cy=0;
		////////////////////////////////////////////////////////////////////////////////////////
		char hexa[2];
		hexa[0]=hexa[1]='0';
		int quotient;
    	quotient = a;
    	int  temp1;
    	int i=0;
    	while(quotient!=0)
    	{
        	 temp1 = quotient % 16;

      			if( temp1 < 10)
           			temp1 =temp1 + 48;
      			else
         			temp1 = temp1 + 55;

      		hexa[i++]= temp1;
      		quotient = quotient / 16;
    	}
    b.hex1=hexa[1];
    b.hex2=hexa[0];
    cout<<endl<<b.hex2<<b.hex1<< endl;
    return f;
	}


	flag operator + (reg1b temp)
	{
		int a,t;
		flag f;
		a = returndec_1_byte ( *this );
		t = returndec_1_byte ( temp );

		a+=t;
		if(a<0)
			{
			    f.s=1;
			    a=256+a;
			}
		else
			f.s=0;

		if(a==0)
			f.z=1;
		else
			f.z=0;

		if(a>255)
			f.cy=1;
		else
			f.cy=0;
	////////////////////////////////////////////////////////////////////////////////////////
		char hexa[2];
    	hexa[0]=hexa[1]='0';

    	int quotient = a;
    	int  temp1;
    	int i=0;
    	while(quotient!=0)
    	{
        	 temp1 = quotient % 16;

      			if( temp1 < 10)
           			temp1 =temp1 + 48;
      			else
         			temp1 = temp1 + 55;

      		hexa[i++]= temp1;
      		quotient = quotient / 16;
    	}
    b.hex1=hexa[1];
    b.hex2=hexa[0];
    return f;
	}

    flag operator - (int t)
	{
		int a;
		flag f;
		a = returndec_1_byte ( *this );

		a-=t;
		if(a<0)
			{
			    f.s=1;
                a=256+a;
			}
		else
			f.s=0;

		if(a==0)
			f.z=1;
		else
			f.z=0;

		if(a>255)
			f.cy=1;
		else
			f.cy=0;
		////////////////////////////////////////////////////////////////////////////////////////
		char hexa[2];
    	hexa[0]=hexa[1]='0';

    	int quotient = a;

    	int  temp1;
    	int i=0;
    	while(quotient!=0)
    	{
        	 temp1 = quotient % 16;

      			if( temp1 < 10)
           			temp1 =temp1 + 48;
      			else
         			temp1 = temp1 + 55;

      		hexa[i++]= temp1;
      		quotient = quotient / 16;
    	}
    b.hex1=hexa[1];
    b.hex2=hexa[0];
    return f;
	}

	flag operator + (int t)
	{
		int a;
		flag f;
		a = returndec_1_byte ( *this );

		a+=t;
		if(a<0)
			{
			    f.s=1;
			    a=256+a;
			}
		else
			f.s=0;

		if(a==0)
			f.z=1;
		else
			f.z=0;

		if(a>255)
			f.cy=1;
		else
			f.cy=0;
		////////////////////////////////////////////////////////////////////////////////////////
		char hexa[2];
    	hexa[0]=hexa[1]='0';

    	int quotient = a;
    	int  temp1;
    	int i=0;
    	while(quotient!=0)
    	{
        	 temp1 = quotient % 16;

      			if( temp1 < 10)
           			temp1 =temp1 + 48;
      			else
         			temp1 = temp1 + 55;

      		hexa[i++]= temp1;
      		quotient = quotient / 16;
    	}
    b.hex1=hexa[1];
    b.hex2=hexa[0];
    return f;
	}};

class reg2b {

	public :
	byte1 b[2];
	reg2b()
	{
		b[0].hex1  =         b[0].hex2=     b[1].hex1 =      b[1].hex2='0';
	}

	reg2b( reg2b &a )
	{
		b[0].hex1 = a.b[0].hex1 ;
        b[0].hex2 = a.b[0].hex2 ;
        b[1].hex1 = a.b[1].hex1 ;
        b[1].hex2 = a.b[1].hex2 ;
	}
	void display_reg2b(int x)
	{
		cout << b[0].hex1 <<b[0].hex2<< b[1].hex1 <<b[1].hex2<< endl;


            char s[100];
		    sprintf(s,"%c",b[0].hex1);
            outtextxy(x,cord,s);
            sprintf(s,"%c",b[0].hex2);
            outtextxy(x+10,cord,s);
            sprintf(s,"%c",b[1].hex1);
            outtextxy(x+20,cord,s);
            sprintf(s,"%c",b[1].hex2);
            outtextxy(x+30,cord,s);
	}

	int return_diff(reg1b a, reg1b b)
	{
		int diff=0;
		// first no   b[0].hex1     b[0].hex2     b[1].hex1    b[1].hex2
		// second no  a.b.hex1      a.b.hex2      b.b.hex1     b.b.hex2
		int f_no=0,s_no=0;
		std::map<char, int> m;
		m['0']=0;m['1']=1;m['2']=2;m['3']=3;m['4']=4;m['5']=5;m['6']=6;m['7']=7;m['8']=8;m['9']=9;m['A']=10;m['B']=11;m['C']=12;m['D']=13;m['E']=14;m['F']=15;
		//f_no=m[b[0].hex1]*4096 + m[b[0].hex2]*256 + m[b[1].hex1]*16 +m[b[1].hex2];
		s_no=m[a.b.hex1]*4096 + m[a.b.hex2]*256 + m[b.b.hex1]*16 +m[b.b.hex2];
		return (/*f_no -*/ s_no);
	}};


ostream & operator << ( ostream & dout , byte1 b)
{
	if(b.hex1 > 33 &&  b.hex1 <78)
		{
		    dout << b.hex1 ;
		    char s[100];
		    sprintf(s,"%c",b.hex1);
            outtextxy(180,cord,s);
        }

	if(b.hex2 <78 && b.hex2 >33)
		{
		    dout<< b.hex2 ;
            char s[100];
		    sprintf(s,"%c",b.hex2);
            outtextxy(190,cord,s);
		}
	dout<<"\n" ;
	return dout;
}


reg2b atin_hex(int dec)
{
	reg2b return_wala;
	char hexa[4];
	hexa[0]=hexa[1]=hexa[2]=hexa[3]='0';
		int quotient;
    	quotient = dec;
    	int  temp1;
    	int i=0 ;
    	while(quotient!=0)
    	{
        	 temp1 = quotient % 16;

      			if( temp1 < 10)
           			temp1 =temp1 + 48;
      			else
         			temp1 = temp1 + 55;

      		hexa[i++]= temp1;
      		quotient = quotient / 16;
    	}
    	return_wala.b[0].hex1=hexa[3];
    	return_wala.b[0].hex2=hexa[2];
    	return_wala.b[1].hex1=hexa[1];
    	return_wala.b[1].hex2=hexa[0];

    return return_wala;
}

void print_byte(char a , char b ,int x, int cord )
{

	if( a > 33 &&  a <78)
		{
		    cout << a ;
		    char s[100];
		    sprintf(s,"%c",a);
            outtextxy(x,cord,s);
        }

	if(b <78 && b >33)
		{
		    cout<< b;
            char s[100];
		    sprintf(s,"%c",b);
            outtextxy(x+10,cord,s);
		}
}

class instruction             //  two operand instruction
{
	public:
        string op_code ;
        byte1 b[3]  ;
        //static int cord;
        int  sixed ,
	         var ;
	    int  t_state;
        instruction()
        {
        op_code="APPLE";
        }
 	void show_inst(int k )
		{
		    int i=0;

            if (op_code== "APPLE")
                {
                    return;
                }

			cout<<k;
			char s[100];
			sprintf(s,"%d",k);
			outtextxy(12,cord,s);
			cout<<"\t"<<op_code<<"\t\t";
			sprintf(s,"%s",op_code.c_str());
			outtextxy(112,cord, s );
						cout<<b[0];
            k++;cord+=25;
			for(i=1;i<sixed;i++)
				{
				    cout<<k;char s[100];
			sprintf(s,"%d",k);
			outtextxy(12,cord,s);

				    cout<<"\t\t\t"<<b[i];k++;cord+=25;
				}
		}
	void show_inst_exec(int k ) const
		{	int i=0;

            if (op_code== "APPLE")
                {

                    outtextxy( 300,73,"code jumped into a wrong section *** core dumped  ***\n*** Please contact the system developer ***");
                    throw "CODE DUMPED";
                    return;
                }
			cout<<k;
			char s[100];
			sprintf(s,"%d",k);
			outtextxy(500,73,s);

			cout<<"\t"<<op_code<<"\t\t";

			sprintf(s,"%s",op_code.c_str());
			outtextxy(580,73, s );
			int cord=73;

				print_byte( b[0].hex1 , b[0].hex2,670,73);  //                   //if(var != 0 )cout<<b[0].hex1;
			k++;
            int tempy=90;
			for(i=1;i<sixed;i++)
				{
				    cout<<k;
                    sprintf(s,"%d",k);
                    outtextxy(500,tempy,s);

				    print_byte(b[i].hex1 , b[i].hex2,670,tempy);
				    //cout<<"\t\t\t"<<b[i];

				    k++;
				    tempy+=18;
				}
		}};



int returndec_1_byte(reg1b a)
{
	std::map<char, int> m;
		m['0']=0;m['1']=1;m['2']=2;m['3']=3;m['4']=4;m['5']=5;m['6']=6;m['7']=7;m['8']=8;m['9']=9;m['A']=10;m['B']=11;m['C']=12;m['D']=13;m['E']=14;m['F']=15;
		return m[a.b.hex1]*16 +m[a.b.hex2];}

int returndec_2_1_byte(reg1b a, reg1b b)
{
	std::map<char, int> m;
		m['0']=0;m['1']=1;m['2']=2;m['3']=3;m['4']=4;m['5']=5;m['6']=6;m['7']=7;m['8']=8;m['9']=9;m['A']=10;m['B']=11;m['C']=12;m['D']=13;m['E']=14;m['F']=15;
		return m[a.b.hex1]*4096 + m[a.b.hex2]*256 + m[b.b.hex1]*16 +m[b.b.hex2];}

int returndec(reg2b a)
{
	std::map<char, int> m;
		m['0']=0;m['1']=1;m['2']=2;m['3']=3;m['4']=4;m['5']=5;m['6']=6;m['7']=7;m['8']=8;m['9']=9;m['A']=10;m['B']=11;m['C']=12;m['D']=13;m['E']=14;m['F']=15;
		return m[a.b[0].hex1]*4096 + m[a.b[0].hex2]*256 + m[a.b[1].hex1]*16 +m[a.b[1].hex2];
}


class memory{

	public:

	instruction a[65536];
	reg1b   data [65536];
	refrence  r  [200];
    int ic,ir,    data_count;
	reg2b   mem_start,db_start;

	int int_start;	int int_dbstart;
	memory()
    {
        data_count=0;
    	ir=ic=0;
    }

    void display(int i =1)
    {
    	cout<<"\n\n\tmemory display\n\n\t\t***code segment***\n";
        int k=int_start;
        if(i==1)
        {
            for(;k<ic;k++)
            {
                a[k].show_inst(k);
            }
        }
           cout<<"\t\t***data segment***\n";
           int j= int_dbstart;
           cord = 352;
         for(k=0;k<data_count;k++,j++)
            {
            	cout<<j;
            	char s[100];
                sprintf(s,"%d",j);
                outtextxy( 1085 , cord , s  );


            	cout<<" ";data[j].display_reg1b();
            	cord+=25;
            }
    }
	friend reg2b asbl( memory & , string filename);
};

///////////////////////////////////////////////////////////////////////

class control_unit{

	/* it has timing and controll  */
	public:

	int t_state  ;
	instruction i;
	int ale      ;
	int rd_bar   ;
	int io_m_bar ;

	control_unit()
		{
			t_state=1;
    	}
};

template <class at1> class handshaker : public reg1b
{
    public :
    at1 name;
    handshaker()
    {
        b.hex1=b.hex2='0';
        name = "Handshake Type";
    }
};


class processor{

	 reg1b   a , temp,   b,c,    d,e,   h,l;  // the sevenprogramable regs
	 flag f;
	 instruction ir ;
	 int instruction_pointer;// it keps telling in which instruction is the
	 reg2b sp , pc , inc_latch;
	 control_unit cu;

	 public:
	 	processor()
	 	{
	 	    instruction_pointer=0;
	 		f.s=f.cy=f.z=f.ac=f.p=0;
	 	}
	 	memory m ;
	 	char processor_handshake (reg1b & d)
	 	{
	 	    if (d.b.hex1 == 1)
            {
                throw "Null exception Occured";
            }
    if(d.b.hex1=='0' && d.b.hex2=='0')
    {
        return 'Y';
    }

    return 'N';
    }

char processor_handshake (handshaker<string> d[], int i_hs)
	 	{ int t=0;
	 	int check=0;
	 	for(t=0;t<i_hs;t++){
                if (d[t].b.hex1 == 1)
            {
                throw "Null exception Occured";
            }
    if(d[t].b.hex1=='0' && d[t].b.hex2=='0')
    {
       cout<<"\n\tCONDITION MET FOR HANDSHAKING IN HANDSHAKE_REG #"<<t<<"\n";
       check=1;
    }
    else{ check = 0;} }

    if(check==1)
    {
        return 'Y';
    }

    return 'N';
    }

	 	int assembel(string filename )
	 	{
	 		pc = asbl( m, filename );		//show change in pc;
	 		instruction_pointer =  returndec(m.mem_start);
	 	}

	 	void show_procesor_status()
	 	{   cout<< "\n////////////////////////////////////////////////////////////////\n";

	 		cord=275;
	 		cout <<"\t\t register files\t\nA  --->  ";
	 		a.display_reg1b(340);
	 		cout<<  "B  --->  " ;
	 		b.display_reg1b(1150-250);
	 		cout<<  "C  --->  " ;
	 		c.display_reg1b(1206-250);
	 		cord+=50;
	 		cout<<  "D  --->  " ;
	 		d.display_reg1b(1150-250);
	 		cout<<  "E  --->  " ;
	 		e.display_reg1b(1206-250);
	 		cord+=50;
	 		cout<<  "H  --->  " ;
	 		h.display_reg1b(1150-250);
	 		cout<<  "L  --->  " ;
	 		l.display_reg1b(1206-250);

            pc = atin_hex ( instruction_pointer );
            cord=475;
            pc.display_reg2b(1148-240 );

	 		cout<< "////////////////////////////////////////////////////////////////\n";

	 		cout<<"flag status";
	 		cout<<"\t\ts ="<<f.s<<"    cy ="<<f.cy<<"    z="<<f.z<<"      ac="<<f.ac<<"      p="<<f.p;
	 		char s[10];
	 		//1485-250,103
	 		setfillstyle(SOLID_FILL,WHITE);
	 		sprintf(s,"%d",f.s);
	 		outtextxy(1485-250,127,s);
//bar(1485-250,152,1485-200,102);
	 		sprintf(s,"%d",f.z);
	 		outtextxy(1485-250,152,s);

	 		sprintf(s,"%d",f.ac);
	 		outtextxy(1485-250,177,s);


	 		sprintf(s,"%d",f.p);
	 		outtextxy(1485-250,202,s);

	 		sprintf(s,"%d",f.cy);
	 		outtextxy(1485-250,227,s);

	 		cout<<"\nprogram counter status  = " << instruction_pointer<<endl;
    }

  int execute_microinst()
        {////////////////////////////////     display before exicution   /////////////////////
            //fetch
            int cont=1;

            string send_this;
            while( cont )
            {           show_procesor_status();
                        m.display(0);
            Tstate=1;
            cout<<"\n\n";
            cout<< "\n\t\tfetching \t\t\n";

            setfillstyle(SOLID_FILL,COLOR(0,0,0) );
                ///////////////////////////////////////////////////////////////////////////////////////////////////////
                ///////////////////////////////    fetch    ///////////////////////////////////////////////////////////
                ///////////////////////////////////////////////////////////////////////////////////////////////////////
            if(status_fetch==0)
            {
                setfillstyle(SOLID_FILL,COLOR(0,0,0) );
            bar(470,75,870,129);

                outtextxy(550,73,".Fetching.");
                cu.t_state=1;
                load("clock");
                load("iom");}
                cout<<"\t\n"<<cu.t_state<<"\t\n";
                cu.io_m_bar=0;cu.ale = 1;

               if(status_fetch==0){
                delay(300);
                enable("clock");
                enable("ale");
                enable("idl");
                load("addr buffer");
                load("data buffer");
                move("reg to buffers");

                show_procesor_status();status_run=call_click(status_run,status_fetch);}

                cu.t_state++;//2
                if(status_fetch==0){
                disable("idl");
                disable("addr buffer");
                disable("data buffer");
                load("clock");}
                cout<<"\t\n"<<cu.t_state<<"\t\n";
                cu.rd_bar  = 0;
                if(status_fetch==0){load("rd");
                move("addr to memory");
                delay(300);
                enable("clock");
                move("data from memory");
                enable("data buffer");
                move("ad buffer to bus");
                load("ir");
                move("bus to ir");
                show_procesor_status();status_run=call_click(status_run,status_fetch);}
                cu.t_state++;//3
                if(status_fetch==0){
                load("clock");
                disable("ale");
                disable("iom");}
                cout<<"\t\n"<<cu.t_state<<"\t\n";
                // show that data moves from buffer
                if(status_fetch==0){disable("ir");
                move("ir to id");
                enable("clock");}
                cu.rd_bar =1;
                if(status_fetch==0){disable("rd");
                show_procesor_status();status_run=call_click(status_run,status_fetch);}
                //keep showing that data moves
                // then show that data is in ir now
                cu.t_state++;//4
                cout<<"\t\n"<<cu.t_state<<"\t\n";
                if(status_fetch==0){
                move("id to cu");
                show_procesor_status();status_run=call_click(status_run,status_fetch);}
                // here we tell that tthe instruction is decoded  and it takes delay of t4 to get decoded and in t5 the instrruction will continue
                cout<<instruction_pointer;

                disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");


                setcolor(BLACK);
                bar(550,73,630,90);
                setcolor(WHITE);

                Tstate=4;
                ir =m.a[instruction_pointer];

            setfillstyle(SOLID_FILL,COLOR(0,0,0) );
            bar(470,75,870,129);

                m.a[instruction_pointer].show_inst_exec(instruction_pointer);

                show_procesor_status();status_run=call_click(status_run,status_fetch);

                //cin.get();
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                /////////////////        actual instruction          /////////////////////////////////////////////////////////
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                if(m.a[instruction_pointer].op_code ==  "MOV" )
                    {
                        if(  m.a[instruction_pointer].b[0].hex1 == 'M' )            // reg   ->   mem
                            {        cu.t_state=5 ;
                            load("clock");
                                //
                                cu.io_m_bar=0;             //  show it
                                load("iom");
                                                        //  databus  light it

                                int data_address=returndec_2_1_byte(h,l);
                                switch(m.a[instruction_pointer].b[0].hex2 )
                                {
                                    case 'A':
                                    m.data[data_address] = a;
                                    enable("clock");
                                    enable("a");
                                    move("a to bus");
                                    load("addr buffer");
                                    load("data buffer");
                                    move("bus to ad buffer");
                                    move("data to memory");//////////////

                                    break;

                                    case 'B':
                                    m.data[data_address] = b;
                                    enable("clock");
                                    enable("b");
                                    move("reg to bus");
                                    load("addr buffer");
                                    load("data buffer");
                                    move("bus to ad buffer");
                                    move("data to memory");
                                    break;

                                    case 'C':
                                    m.data[data_address] = c;
                                    enable("clock");
                                    enable("c");
                                    move("reg to bus");
                                    load("addr buffer");
                                    load("data buffer");
                                    move("bus to ad buffer");
                                    move("data to memory");
                                    break;

                                    case 'D':
                                    m.data[data_address] = d;
                                    enable("clock");
                                    enable("d");
                                    move("reg to bus");
                                    load("addr buffer");
                                    load("data buffer");
                                    move("bus to ad buffer");
                                    move("data to memory");
                                    break;

                                    case 'E':
                                    m.data[data_address] = e;
                                    enable("clock");
                                    enable("e");
                                    move("reg to bus");
                                    load("addr buffer");
                                    load("data buffer");
                                    move("bus to ad buffer");
                                    move("data to memory");

                                    break;

                                    case 'H':
                                    m.data[data_address] = h;
                                    enable("clock");
                                    enable("h");
                                    move("reg to bus");
                                    load("addr buffer");
                                    load("data buffer");
                                    move("bus to ad buffer");
                                    move("data to memory");

                                    break;

                                    case 'L':
                                    m.data[data_address] = l;
                                    enable("clock");
                                    enable("l");
                                    move("reg to bus");
                                    load("addr buffer");
                                    load("data buffer");
                                    move("bus to ad buffer");
                                    move("data to memory");

                                    break;
                                }
                                load("clock");
                                delay(400);
                                cu.t_state = 7;
                                enable("clock");
                                disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");

                                show_procesor_status();status_run=call_click(status_run,status_fetch);
                            }

                        else if( m.a[instruction_pointer].b[0].hex2 == 'M' )        // mem   ->   reg
                            {
                                int data_address=returndec_2_1_byte(h,l);
                                switch(m.a[instruction_pointer].b[0].hex1 )
                                {
                                    case 'A':
                                    a = m.data[data_address] ;
                                    enable("clock");
                                    load("a");
                                    move("data from memory");
                                    enable("data buffer");
                                    move("ad buffer to bus");
                                    move("bus to a");

                                    break;

                                    case 'B':
                                    b = m.data[data_address] ;
                                    enable("clock");
                                    load("b");
                                    move("data from memory");
                                    enable("data buffer");
                                    move("ad buffer to bus");
                                    move("bus to reg");

                                    break;

                                    case 'C':
                                    c = m.data[data_address] ;
                                    enable("clock");
                                    load("c");
                                    move("data from memory");
                                    enable("data buffer");
                                    move("ad buffer to bus");
                                    move("bus to reg");
                                    break;

                                    case 'D':
                                    d = m.data[data_address] ;
                                    enable("clock");
                                    load("d");
                                    move("data from memory");
                                    enable("data buffer");
                                    move("ad buffer to bus");
                                    move("bus to reg");

                                    break;

                                    case 'E':
                                    e = m.data[data_address] ;
                                    enable("clock");
                                    load("e");
                                    move("data from memory");
                                    enable("data buffer");
                                    move("ad buffer to bus");
                                    move("bus to reg");

                                    break;

                                    case 'H':
                                    h = m.data[data_address] ;
                                    enable("clock");
                                    load("h");
                                    move("data from memory");
                                    enable("data buffer");
                                    move("ad buffer to bus");
                                    move("bus to reg");

                                    break;

                                    case 'L':
                                    l = m.data[data_address];
                                    enable("clock");
                                    load("l");
                                    move("data from memory");
                                    enable("data buffer");
                                    move("ad buffer to bus");
                                    move("bus to reg");

                                    break;

                                }
                                load("clock");
                                delay(400);
                                cu.t_state = 7;
                                enable("clock");
                                disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");

                                show_procesor_status();status_run=call_click(status_run,status_fetch);

                            }
                        else                                                        // reg -> reg
                            {
                              reg1b src ;
                              switch(m.a[instruction_pointer].b[0].hex2 )
                                   {
                                        case 'A':
                                        src = a;
                                        enable("a");
                                        move("a to bus");
                                        break;

                                        case 'B':
                                        src = b;
                                        enable("b");
                                        move("reg to bus");

                                        break;

                                        case 'C':
                                        src = c;
                                        enable("c");
                                        move("reg to bus");

                                        break;

                                        case 'D':
                                        src = d;
                                        enable("d");
                                        move("reg to bus");

                                        break;

                                        case 'E':
                                        src = e;
                                        enable("e");
                                        move("reg to bus");

                                        break;

                                        case 'H':
                                        src = h;

                                        enable("h");
                                        move("reg to bus");

                                        break;

                                        case 'L':
                                        src = l;
                                        enable("l");
                                        move("reg to bus");

                                        break;
                                   }

                                   switch(m.a[instruction_pointer].b[0].hex1 )
                                   {
                                        case 'A':
                                        a = src ;
                                        load("a");
                                        move("bus to a");
                                        break;

                                        case 'B':
                                        b = src ;
                                        load("b");
                                        move("bus to reg");

                                        break;

                                        case 'C':
                                        c = src ;
                                        load("c");
                                        move("bus to reg");

                                        break;

                                        case 'D':
                                        d = src ;
                                        load("d");
                                        move("bus to reg");

                                        break;

                                        case 'E':
                                        e = src ;
                                        load("e");
                                        move("bus to reg");

                                        break;

                                        case 'H':
                                        h = src ;
                                        load("h");
                                        move("bus to reg");

                                        break;

                                        case 'L':
                                        l = src;
                                        load("l");
                                        move("bus to reg");

                                        break;

                                   }
                                   disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");


                                show_procesor_status();status_run=call_click(status_run,status_fetch);

                            }

                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                        show_procesor_status();status_run=call_click(status_run,status_fetch);
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "MVI" )
                    {
                        cu.t_state=5;
                        load("clock");
                        enable("pc");
                        load("data buffer");
                        load("addr buffer");
                        move("reg to buffer");
                        move("addr to memory");
                        disable("pc");
                        disable("data buffer");
                        disable("addr buffer");
                        move("data from memory");
                        enable("data buffer");
                        move("ad buffer to bus");
                        disable("data buffer");

                        if(m.a[instruction_pointer].b[0].hex1=='M')
                            {   // tstates is 1
                                load("addr buffer");
                                load("data buffer");
                                move("bus to ad buffer");
                                move("data to memory");
                                int address=returndec_2_1_byte(h,l);
                                m.data[address] = m.a[instruction_pointer].b[1] ;
                                enable("clock");   // dont worry the operator in owerloaded
                            }
                        else{

                                   switch(m.a[instruction_pointer].b[0].hex1 )
                                   {
                                        case 'A':
                                        a = m.a[instruction_pointer].b[1] ;
                                        load("a");
                                        move("bus to a");
                                        enable("clock");
                                        break;

                                        case 'B':
                                        b = m.a[instruction_pointer].b[1] ;
                                        load("b");
                                        move("bus to reg");
                                        enable("clock");

                                        break;

                                        case 'C':
                                        c = m.a[instruction_pointer].b[1] ;
                                        load("c");
                                        move("bus to reg");
                                        enable("clock");

                                        break;

                                        case 'D':
                                        d = m.a[instruction_pointer].b[1] ;
                                        load("d");
                                        move("bus to reg");
                                        enable("clock");

                                        break;

                                        case 'E':
                                        e = m.a[instruction_pointer].b[1] ;
                                        load("e");
                                        move("bus to reg");
                                        enable("clock");

                                        break;

                                        case 'H':
                                        h = m.a[instruction_pointer].b[1] ;
                                        load("h");
                                        move("bus to reg");
                                        enable("clock");

                                        break;

                                        case 'L':
                                        l = m.a[instruction_pointer].b[1];
                                        load("l");
                                        move("bus to reg");
                                        enable("clock");

                                        break;
                                   }

                        }

                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                        disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");

                                show_procesor_status();status_run=call_click(status_run,status_fetch);

                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if(m.a[instruction_pointer].op_code=="LDA" )
                    {
                        a=m.data[returndec_2_1_byte(m.a[instruction_pointer].b[1],m.a[instruction_pointer].b[2])];
                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                        load("clock");
                        move("data from memory");
                        enable("data buffer");
                        move("ad buffer to bus");
                        enable("clock");
                        load("a");
                        move("bus to a");
                                           disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");


                                show_procesor_status();status_run=call_click(status_run,status_fetch);

                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "LHLD" )
                    {
                        l = m.data[returndec_2_1_byte(m.a[instruction_pointer].b[1],m.a[instruction_pointer].b[2])     ];
                        load("clock");
                        move("data from memory");
                        enable("data buffer");
                        move("ad buffer to bus");
                        enable("clock");
                        load("l");
                        move("bus to reg");
                        disable("l");
                        h = m.data[returndec_2_1_byte(m.a[instruction_pointer].b[1],m.a[instruction_pointer].b[2])  +1 ];
                        load("clock");
                        move("data from memory");
                        enable("data buffer");
                        move("ad buffer to bus");
                        enable("clock");
                        load("h");
                        move("bus to reg");
                        disable("h");

                        instruction_pointer+= m.a[instruction_pointer].sixed ;


                                            disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");

                                show_procesor_status();status_run=call_click(status_run,status_fetch);

                        continue;

                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if(m.a[instruction_pointer].op_code=="LDAX" )
                    {
                        if(m.a[instruction_pointer].b[0].hex1    ==   'B')
                        {
                    a=m.data[    returndec_2_1_byte (  b , c  )   ];
                            load("clock");
                        move("data from memory");
                        enable("data buffer");
                        move("ad buffer to bus");
                        enable("clock");
                        load("c");
                        move("bus to reg");
                        disable("c");
                        load("clock");
                        move("data from memory");
                        enable("data buffer");
                        move("ad buffer to bus");
                        enable("clock");
                        load("b");
                        move("bus to reg");
                        disable("b");
                        }

                        if(m.a[instruction_pointer].b[0].hex1    ==   'D')
                            {a=m.data[    returndec_2_1_byte (  d , e  )   ];

                            load("clock");
                        move("data from memory");
                        enable("data buffer");
                        move("ad buffer to bus");
                        enable("clock");
                        load("e");
                        move("bus to reg");
                        disable("e");

                        load("clock");
                        move("data from memory");
                        enable("data buffer");
                        move("ad buffer to bus");
                        enable("clock");
                        load("d");
                        move("bus to reg");
                        disable("d");
                            }

                        instruction_pointer+= m.a[instruction_pointer].sixed;
                                           disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");


                                show_procesor_status();status_run=call_click(status_run,status_fetch);

                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( m.a[instruction_pointer].op_code == "LXI" )
                    {    load("clock");
                         enable("ir");
                         move("ir to bus");
                        if(m.a[instruction_pointer].b[0].hex1    ==   'B')
                            {
                                b=m.a[instruction_pointer].b[1]  ;
                                enable("clock");
                                load("b");
                                move("bus to reg");
                                load("clock");
                                disable("b");

                                load("c");
                                move("bus to reg");
                                   c=m.a[instruction_pointer].b[2];
                            }
                        else if(m.a[instruction_pointer].b[0].hex1    ==   'D')
                            {
                                d=m.a[instruction_pointer].b[1]  ;
                                enable("clock");
                                load("d");
                                move("bus to reg");
                                load("clock");
                                disable("d");

                                load("e");
                                move("bus to reg");
                                  e=m.a[instruction_pointer].b[2];
                            }
                        else if(m.a[instruction_pointer].b[0].hex1    ==   'H')
                            {
                                h=m.a[instruction_pointer].b[1]  ;
                                enable("clock");
                                load("h");
                                move("bus to reg");
                                load("clock");
                                disable("h");

                                load("l");
                                move("bus to reg");

                                  l=m.a[instruction_pointer].b[2];
                            }
                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                                           disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");


                                show_procesor_status();status_run=call_click(status_run,status_fetch);

                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "STA" )
                    {
                        m.data[ returndec_2_1_byte( m.a[instruction_pointer].b[1],m.a[instruction_pointer].b[2]  )  ] = a;
                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                        load("clock");
                        enable("idl");
                        move("reg to buffer");
                        move("addr to memory");
                        enable("clock");
                        disable("idl");
                        enable("a");
                        move("a to bus");
                        load("clock");
                        load("data buffer");
                        move("bus to ad buffer");
                        enable("clock");
                        move("data to memory");


                                            disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");

                                show_procesor_status();status_run=call_click(status_run,status_fetch);

                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "STAX" )
                    {
                        load("clock");
                        enable("idl");
                        move("reg to buffer");
                        move("addr to memory");
                        enable("clock");
                        disable("idl");


                        if(m.a[instruction_pointer].b[0].hex1    ==   'B')
                            {
                                m.data[ returndec_2_1_byte( b , c )  ] = a;

                                enable("clock");
                                enable("b");
                                move("reg to bus");
                                load("clock");
                                load("addr buffer");
                                move("bus to ad buffer");
                                disable("b");
                                disable("addr buffer");
                                enable("clock");
                                enable("c");
                                move("reg to bus");
                                disable("c");
                                load("data buffer");
                                move("bus to ad buffer");
                                move("addr to memory");

                            }
                        else if(m.a[instruction_pointer].b[0].hex1    ==   'D')
                            {
                                m.data[ returndec_2_1_byte( d , e )  ] = a;
                                enable("clock");
                                enable("d");
                                move("reg to bus");
                                load("clock");
                                load("addr buffer");
                                move("bus to ad buffer");
                                disable("d");
                                disable("addr buffer");
                                enable("clock");
                                enable("e");
                                move("reg to bus");
                                disable("e");
                                load("data buffer");
                                move("bus to ad buffer");
                                move("addr to memory");

                            }
                        else if(m.a[instruction_pointer].b[0].hex1    ==   'H')
                            {
                                m.data[ returndec_2_1_byte( h , l )  ] = a;
                                enable("clock");
                                enable("h");
                                move("reg to bus");
                                load("clock");
                                load("addr buffer");
                                move("bus to ad buffer");
                                disable("h");
                                disable("addr buffer");
                                enable("clock");
                                enable("l");
                                move("reg to bus");
                                disable("l");
                                load("data buffer");
                                move("bus to ad buffer");
                                move("addr to memory");

                            }
                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                        enable("a");
                        move("a to bus");
                        load("clock");
                        load("data buffer");
                        move("bus to ad buffer");
                        enable("clock");
                        move("data to memory");

                                            disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");


                                show_procesor_status();status_run=call_click(status_run,status_fetch);

                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "SHLD" )
                    {
                        load("clock");
                        m.data[returndec_2_1_byte(m.a[instruction_pointer].b[1],m.a[instruction_pointer].b[2])     ]  = l ;
                        enable("l");
                        load("data buffer");
                        move("reg to buffer");
                        enable("clock");
                        disable("l");
                        disable("data buffer");
                        move("data to memory");

                        m.data[returndec_2_1_byte(m.a[instruction_pointer].b[1],m.a[instruction_pointer].b[2])  +1 ]  = h ;
                        enable("h");
                        load("data buffer");
                        move("reg to buffer");
                        disable("h");
                        disable("data buffer");
                        move("data to memory");

                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                                            disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");


                                show_procesor_status();status_run=call_click(status_run,status_fetch);

                        continue;
                    }
                    ////////////////////////////////////////////////////////////////////////////////////////////////
                if( m.a[instruction_pointer].op_code == "CMP")
                    {
                        int temp , acc = returndec_1_byte(a)  ;
                        if (  m.a[instruction_pointer].b[0].hex1 == 'M' )
                            {
                                temp=returndec_1_byte( m.data[    returndec_2_1_byte (  h , l  )   ] );
                                enable("pc");
                                load("addr buffer");
                                load("data buffer");
                                move("reg to buffer");
                                move("data to memory");
                                disable("pc");
                                disable("data buffer");
                                disable("addr buffer");
                                delay(500);
                                move("data from memory");
                                enable("data buffer");
                                move("ad buffer to bus");
                                load("temp");
                                move("bus to temp");
                                disable("data buffer");

                            }

                        else{
                            reg1b src ;
                              switch(m.a[instruction_pointer].b[0].hex1 )
                                   {
                                        case 'A':
                                        src = a ;
                                        send_this="a";
                                        break;

                                        case 'B':
                                        src = b ;
                                        send_this="b";
                                        break;

                                        case 'C':
                                        src = c ;
                                        send_this="c";
                                        break;

                                        case 'D':
                                        src = d ;
                                        send_this="d";
                                        break;

                                        case 'E':
                                        src = e ;
                                        send_this="e";
                                        break;

                                        case 'H':
                                        src = h ;
                                        send_this="h";
                                        break;

                                        case 'L':
                                        src = l ;
                                        send_this="l";
                                        break;
                                   }

                                   enable(send_this);
                                   if(send_this=="a")
                                   {
                                       move("a to bus");
                                   }
                                   else{ move("reg to bus");}
                                   load("temp");
                                   move("bus to temp");
                                   disable("temp");
                                   disable(send_this);
                                   disable("temp");
                                move("a to alu");
                                move("temp to alu");
                                move("alu to bus");
                                load("a");
                                move("bus to a");

                                   temp = returndec_1_byte(src);
                            }
                            if(acc < temp)
                                f.cy=1;
                            else
                                f.cy=0;

                            if(acc == temp)
                                f.z=1;
                            else
                                f.z=0;

                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                        disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);
                        continue;
                    }

                    ////////////////////////////////////////////////////////////////////////////////////////////////////
                 if( m.a[instruction_pointer].op_code == "ANA"  || m.a[instruction_pointer].op_code == "XRA"  || m.a[instruction_pointer].op_code == "ORA"  )
                    {
                        int temp , acc = returndec_1_byte(a)  ;
                        if (  m.a[instruction_pointer].b[0].hex1 == 'M' )
                            {
                                temp=returndec_1_byte( m.data[    returndec_2_1_byte (  h , l  )   ] );

                                enable("pc");
                                load("addr buffer");
                                load("data buffer");
                                move("reg to buffer");
                                move("data to memory");
                                disable("pc");
                                disable("data buffer");
                                disable("addr buffer");
                                delay(500);
                                move("data from memory");
                                enable("data buffer");
                                move("ad buffer to bus");
                                load("temp");
                                move("bus to temp");
                                disable("data buffer");

                            }

                        else{
                            reg1b src ;
                              switch(m.a[instruction_pointer].b[0].hex1 )
                                   {
                                       case 'A':
                                        src = a ;
                                        send_this="a";
                                        break;

                                        case 'B':
                                        src = b ;
                                        send_this="b";
                                        break;

                                        case 'C':
                                        src = c ;
                                        send_this="c";
                                        break;

                                        case 'D':
                                        src = d ;
                                        send_this="d";
                                        break;

                                        case 'E':
                                        src = e ;
                                        send_this="e";
                                        break;

                                        case 'H':
                                        src = h ;
                                        send_this="h";
                                        break;

                                        case 'L':
                                        src = l ;
                                        send_this="l";
                                        break;
                                   }

                                   temp = returndec_1_byte(src);
                                     enable(send_this);
                if(send_this=="a")
                                   {
                                       move("a to bus");
                                   }
                                   else{ move("reg to bus");}
                                   load("temp");
                                   move("bus to temp");
                                   disable("temp");
                                   disable(send_this);
                                   disable("temp");

                            }
                            if (m.a[instruction_pointer].op_code == "ANA" )
                                acc = acc & temp;
                            else if(m.a[instruction_pointer].op_code == "XRA" )
                                acc = acc ^ temp;
                            else if(m.a[instruction_pointer].op_code == "ORA" )
                                acc = acc | temp;
                 //   put         a=acc; after flag checks

                            if(acc<0)
                                f.s=1;
                            else
                                f.s=0;

                            if(acc==0)
                                f.z=1;
                            else
                                f.z=0;

                            if(acc>255)
                                f.cy=1;
                            else
                                f.cy=0;

                            if(acc<0)//add the following two lines
                                acc+=256;

                            a=acc;
                            move("a to alu");
                                move("temp to alu");
                                move("alu to bus");
                                load("a");
                                move("bus to a");


                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                         disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);

                        continue;
                    }

                    ////////////////////////////////////////////////////////////////////////////////////////////////////
                if( m.a[instruction_pointer].op_code == "ADD" )
                    {
                        if (  m.a[instruction_pointer].b[0].hex1 == 'M' )
                            {
                                temp=m.data[    returndec_2_1_byte (  h , l  )   ];
                                f = a  +  temp ;//flags are afected
                                enable("pc");
                                load("addr buffer");
                                load("data buffer");
                                move("reg to buffer");
                                move("data to memory");
                                disable("pc");
                                disable("data buffer");
                                disable("addr buffer");
                                delay(500);
                                move("data from memory");
                                enable("data buffer");
                                move("ad buffer to bus");
                                load("temp");
                                move("bus to temp");
                                disable("data buffer");

                            }
                        else{

                            reg1b src ;
                              switch(m.a[instruction_pointer].b[0].hex1 )
                                   {
                                       case 'A':
                                        src = a ;
                                        send_this="a";
                                        break;

                                        case 'B':
                                        src = b ;
                                        send_this="b";
                                        break;

                                        case 'C':
                                        src = c ;
                                        send_this="c";
                                        break;

                                        case 'D':
                                        src = d ;
                                        send_this="d";
                                        break;

                                        case 'E':
                                        src = e ;
                                        send_this="e";
                                        break;

                                        case 'H':
                                        src = h ;
                                        send_this="h";
                                        break;

                                        case 'L':
                                        src = l ;
                                        send_this="l";
                                        break;
                                   }
                                   f = a + src;
                                     enable(send_this);
                if(send_this=="a")
                                   {
                                       move("a to bus");
                                   }
                                   else{ move("reg to bus");}
                                   load("temp");
                                   move("bus to temp");
                                   disable("temp");
                                   disable(send_this);
                                   disable("temp");



                            }


                        move("a to alu");
                                move("temp to alu");
                                move("alu to bus");
                                load("a");
                                move("bus to a");
                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                         disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);

                        continue;
                    }

                    ////////////////////////////////////////////////////////////////////////////////////////////////////
                if( m.a[instruction_pointer].op_code == "ANI" || m.a[instruction_pointer].op_code == "XRI" ||  m.a[instruction_pointer].op_code == "ORI" )
                    {int  temp,acc= returndec_1_byte(a);

                            temp = returndec_1_byte( m.a[instruction_pointer].b[1] );

                            if (m.a[instruction_pointer].op_code == "ANI" )
                                acc = acc & temp;
                            else if(m.a[instruction_pointer].op_code == "XRI" )
                                acc = acc ^ temp;
                            else if(m.a[instruction_pointer].op_code == "ORI" )
                                acc = acc | temp;

                            if(acc<0)
                                {
                                    f.s=1;
                                    acc+=256;
                                }
                            else
                                f.s=0;

                            if(acc==0)
                                f.z=1;
                            else
                                f.z=0;

                            if(acc>255)
                                f.cy=1;
                            else
                                f.cy=0;

                            a=acc;
                            enable("pc");
                                load("addr buffer");
                                load("data buffer");
                                move("reg to buffer");
                                move("data to memory");
                                disable("pc");
                                disable("data buffer");
                                disable("addr buffer");
                                delay(500);
                                move("data from memory");
                                enable("data buffer");
                                move("ad buffer to bus");
                                load("temp");
                                move("bus to temp");
                                disable("data buffer");
                                move("a to alu");
                                move("temp to alu");
                                move("alu to bus");
                                load("a");
                                move("bus to a");

                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                         disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);

                        continue;
                    }

                    ////////////////////////////////////////////////////////////////////////////////////////////////////
                if( m.a[instruction_pointer].op_code == "RLC" || m.a[instruction_pointer].op_code == "RRC"  )
                    {
                        int  acc= returndec_1_byte(a);

                            if     (m.a[instruction_pointer].op_code == "RLC" )
                                acc = acc*2;

                            else if(m.a[instruction_pointer].op_code == "RRC" )
                                acc = acc/2;
                            if(acc<0)
                                {
                                    f.s=1;
                                    acc+=256;
                                }

                            else
                                f.s=0;

                            if(acc==0)
                                f.z=1;
                            else
                                f.z=0;

                            if(acc>255)
                                f.cy=1;
                            else
                                f.cy=0;

                            a=acc;
                            move("a to alu");
                            move("alu to bus");
                            load("a");
                            move("bus to a");

                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                         disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);

                        continue;
                    }
                    ////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "INX" )
                    {
                        reg1b aa;
                        aa.b.hex1='1';                      aa.b.hex2='0';

                              switch(m.a[instruction_pointer].b[0].hex1 )
                                   {
                                        case 'B':
                                        { send_this="c";
                                        int temp = returndec_2_1_byte(b,c);

                                                char hexa[4];
                                                hexa[0]=hexa[1]=hexa[2]=hexa[3]='0';

                                                int quotient = temp + 1;
                                                int  temp1;
                                                int i=0;

                                            while(quotient!=0)
                                            {
                                                temp1 = quotient % 16;

                                                    if( temp1 < 10)
                                                        temp1 =temp1 + 48;
                                                    else
                                                        temp1 = temp1 + 55;

                                                hexa[i++]= temp1;
                                                quotient = quotient / 16;
                                            }
                                                b.b.hex1=hexa[3];
                                                b.b.hex2=hexa[2];
                                                c.b.hex1=hexa[1];
                                                c.b.hex2=hexa[0];
                                            }
                                        break ;

                                        case 'D' :
                                            {
                                                send_this="e";



                                        int temp = returndec_2_1_byte(d,e);


                                                char hexa[4];
                                                hexa[0]=hexa[1]=hexa[2]=hexa[3]='0';
                                                int quotient = temp + 1;
                                                int  temp1;
                                                int i=0;

                                            while(quotient!=0)
                                            {
                                                temp1 = quotient % 16;

                                                    if( temp1 < 10)
                                                        temp1 =temp1 + 48;
                                                    else
                                                        temp1 = temp1 + 55;

                                                hexa[i++]= temp1;
                                                quotient = quotient / 16;
                                            }
                                                d.b.hex1=hexa[3];
                                                d.b.hex2=hexa[2];
                                                e.b.hex1=hexa[1];
                                                e.b.hex2=hexa[0];
                                            }
                                        break;

                                        case 'H':
                                        {
                                        send_this="l";

                                        int temp = returndec_2_1_byte(h,l);

                                                char hexa[4];
                                                hexa[0]=hexa[1]=hexa[2]=hexa[3]='0';
                                                int quotient = temp + 1;
                                                int  temp1;
                                                int i=0;

                                            while(quotient!=0)
                                            {
                                                temp1 = quotient % 16;

                                                    if( temp1 < 10)
                                                        temp1 =temp1 + 48;
                                                    else
                                                        temp1 = temp1 + 55;

                                                hexa[i++]= temp1;
                                                quotient = quotient / 16;
                                            }
                                                h.b.hex1=hexa[3];
                                                h.b.hex2=hexa[2];
                                                l.b.hex1=hexa[1];
                                                l.b.hex2=hexa[0];
                                        }

                                        break;

                                   }

                                   enable(send_this);
                                   load("a");
                                   move("reg to bus");
                                   move("bus to a");
                                   disable("a");
                                   disable(send_this);
                                   move("a to alu");
                                   move("alu to bus");
                                   load(send_this);
                                   move("bus to reg");



                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                         disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);

                        continue;
                    }
                    ////////////////////////////////////////////////////////////////////////////////////////////////////
                if( m.a[instruction_pointer].op_code == "DCX" )
                    {
                        reg1b aa;
                        aa.b.hex1='0';                      aa.b.hex2='1';

                              switch(m.a[instruction_pointer].b[0].hex1 )
                                   {
                                        case 'B':
                                        {send_this="c";
                                        int temp = returndec_2_1_byte(b,c);

                                                char hexa[4];
                                                hexa[0]=hexa[1]=hexa[2]=hexa[3]='0';

                                                int quotient = temp - 1;
                                                int  temp1;
                                                int i=0;

                                            while(quotient!=0)
                                            {
                                                temp1 = quotient % 16;

                                                    if( temp1 < 10)
                                                        temp1 =temp1 + 48;
                                                    else
                                                        temp1 = temp1 + 55;

                                                hexa[i++]= temp1;
                                                quotient = quotient / 16;
                                            }
                                                b.b.hex1=hexa[3];
                                                b.b.hex2=hexa[2];
                                                c.b.hex1=hexa[1];
                                                c.b.hex2=hexa[0];
                                            }
                                        break ;

                                        case 'D' :
                                            {send_this="e";

                                        int temp = returndec_2_1_byte(d,e);

                                                char hexa[4];
                                                hexa[0]=hexa[1]=hexa[2]=hexa[3]='0';

                                                int quotient = temp - 1;
                                                int  temp1;
                                                int i=0;

                                            while(quotient!=0)
                                            {
                                                temp1 = quotient % 16;

                                                    if( temp1 < 10)
                                                        temp1 =temp1 + 48;
                                                    else
                                                        temp1 = temp1 + 55;

                                                hexa[i++]= temp1;
                                                quotient = quotient / 16;
                                            }
                                                d.b.hex1=hexa[3];
                                                d.b.hex2=hexa[2];
                                                e.b.hex1=hexa[1];
                                                e.b.hex2=hexa[0];
                                            }
                                        break;

                                        case 'H':
                                        {send_this="l";
                                            int temp = returndec_2_1_byte(h,l);

                                                char hexa[4];
                                                hexa[0]=hexa[1]=hexa[2]=hexa[3]='0';

                                                int quotient = temp - 1;
                                                int  temp1;
                                                int i=0;

                                            while(quotient!=0)
                                            {
                                                temp1 = quotient % 16;

                                                    if( temp1 < 10)
                                                        temp1 =temp1 + 48;
                                                    else
                                                        temp1 = temp1 + 55;

                                                hexa[i++]= temp1;
                                                quotient = quotient / 16;
                                            }
                                                h.b.hex1=hexa[3];
                                                h.b.hex2=hexa[2];
                                                l.b.hex1=hexa[1];
                                                l.b.hex2=hexa[0];
                                        }
                                        break;

                                   }

                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                        enable(send_this);
                                   load("a");
                                   move("reg to bus");
                                   move("bus to a");
                                   disable("a");
                                   disable(send_this);
                                   move("a to alu");
                                   move("alu to bus");
                                   load(send_this);
                                   move("bus to reg");

 disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);

                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( m.a[instruction_pointer].op_code == "INR" )
                    {
                        reg1b aa;
                        aa.b.hex1='0';                      aa.b.hex2='1';
                        if (  m.a[instruction_pointer].b[0].hex1 == 'M' )
                            {
                                f = m.data[    returndec_2_1_byte (  h , l  )   ]  + aa ;
                                                                enable("pc");
                                load("addr buffer");
                                load("data buffer");
                                move("reg to buffer");
                                move("data to memory");
                                disable("pc");
                                disable("data buffer");
                                disable("addr buffer");
                                delay(500);
                                move("data from memory");
                                enable("data buffer");
                                move("ad buffer to bus");
                                load("temp");
                                move("bus to temp");
                                disable("data buffer");
                            }
                        else{

                            reg1b  src ;
                              switch(m.a[instruction_pointer].b[0].hex1 )
                                   {
                                        case 'A':
                                        f=a+aa;
                                        send_this="a";
                                        break;

                                        case 'B':
                                        f=b+aa;
                                        send_this="b";
                                        break;

                                        case 'C':
                                        f=c+aa;
                                        send_this="c";
                                        break;

                                        case 'D':
                                        f=d+aa;
                                        send_this="d";
                                        break;

                                        case 'E':
                                        f=e+aa;
                                        send_this="e";
                                        break;

                                        case 'H':
                                        f=h+aa;
                                        send_this="h";
                                        break;

                                        case 'L':
                                        f=l+aa;
                                        send_this="l";
                                        break;
                                   }
                                    enable(send_this);
                if(send_this=="a")
                                   {
                                       move("a to bus");
                                   }
                                   else{ move("reg to bus");}


                            }

                        instruction_pointer+= m.a[instruction_pointer].sixed ;

                        load("a");
                                   move("reg to bus");
                                   move("bus to a");
                                   disable("a");
                                   disable(send_this);
                                   move("a to alu");
                                   move("alu to bus");
                                   load(send_this);
                                    if(send_this=="a")
                                   {
                                       move("bus to a");
                                   }
                                   else{ move("bus to reg");}

                         disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);

                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( m.a[instruction_pointer].op_code == "DCR" )
                    {
                        reg1b aa;
                        aa.b.hex1='0';                      aa.b.hex2='1';
                        if (  m.a[instruction_pointer].b[0].hex1 == 'M' )
                            {
                                f = m.data[    returndec_2_1_byte (  h , l  )   ]  - aa ;
                                 enable("pc");
                                load("addr buffer");
                                load("data buffer");
                                move("reg to buffer");
                                move("data to memory");
                                disable("pc");
                                disable("data buffer");
                                disable("addr buffer");
                                delay(500);
                                move("data from memory");
                                enable("data buffer");
                                move("ad buffer to bus");
                                load("temp");
                                move("bus to temp");
                                disable("data buffer");
                            }
                        else{

                            reg1b src ;
                              switch(m.a[instruction_pointer].b[0].hex1 )
                                   {
                                        case 'A':
                                        f=a-aa;
                                        send_this="a";
                                        break;

                                        case 'B':
                                        f=b-aa;
                                        send_this="b";
                                        break;

                                        case 'C':
                                        f=c-aa;
                                        send_this="c";
                                        break;

                                        case 'D':
                                        f=d-aa;
                                        send_this="d";
                                        break;

                                        case 'E':
                                        f=e-aa;
                                        send_this="e";
                                        break;

                                        case 'H':
                                        f=h-aa;
                                        send_this="h";
                                        break;

                                        case 'L':
                                        f=l-aa;
                                        send_this="l";
                                        break;
                                   }
                                  // f =  src  -  aa  ;
                                   enable(send_this);
                if(send_this=="a")
                                   {
                                       move("a to bus");
                                   }
                                   else{ move("reg to bus");}
                            }
                            load("a");
                                   move("reg to bus");
                                   move("bus to a");
                                   disable("a");
                                   disable(send_this);
                                   move("a to alu");
                                   move("alu to bus");
                                   load(send_this);
                                    if(send_this=="a")
                                   {
                                       move("bus to a");
                                   }
                                   else{ move("bus to reg");}


                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                         disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);

                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "SUB" )
                    {
                        if (  m.a[instruction_pointer].b[0].hex1 == 'M' )
                            {
                                temp = m.data[    returndec_2_1_byte (  h , l  )   ];
                                f = a  -  temp ;//flags are afected
                                 enable("pc");
                                load("addr buffer");
                                load("data buffer");
                                move("reg to buffer");
                                move("data to memory");
                                disable("pc");
                                disable("data buffer");
                                disable("addr buffer");
                                delay(500);
                                move("data from memory");
                                enable("data buffer");
                                move("ad buffer to bus");
                                load("temp");
                                move("bus to temp");
                                disable("data buffer");

                            }

                        else{

                            reg1b src ;
                              switch(m.a[instruction_pointer].b[0].hex1 )
                                   {
                                        case 'A':
                                        src = a;
                                        send_this="a";
                                        break;

                                        case 'B':
                                        src = b;
                                        send_this="b";
                                        break;

                                        case 'C':
                                        src = c;
                                        send_this="c";
                                        break;

                                        case 'D':
                                        src = d;
                                        send_this="d";
                                        break;

                                        case 'E':
                                        src = e;
                                        send_this="e";
                                        break;

                                        case 'H':
                                        src = h;
                                        send_this="h";
                                        break;

                                        case 'L':
                                        src = l;
                                        send_this="l";
                                        break;
                                   }
                                   //src.display_reg1b();
                                   f = a - src;
                                   if(send_this=="a")
                                   {
                                       move("a to bus");
                                   }
                                   else{ move("reg to bus");}
                                   load("temp");
                                   move("bus to temp");
                                   disable("temp");
                                   disable(send_this);
                                   disable("temp");

                            }


                         move("a to alu");
                                move("temp to alu");
                                move("alu to bus");
                                load("a");
                                move("bus to a");
                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                         disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);

                        continue;
                    }
                    ////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "CPI" )
                    {
                        int acumulator , temp ;
                            acumulator = returndec_1_byte ( a ) ;

                                temp = returndec_1_byte( m.a[instruction_pointer].b[1] ) ;

                            if ( temp == acumulator )
                                    {
                                        f.z=1;

                                    }
                                else if ( temp > acumulator )
                                    {
                                        f.cy=1;
                                    }
                                else if ( temp < acumulator )
                                    {
                                        f.cy = 0;
                                        f.z  = 0;
                                    }

                                     enable("pc");
                                load("addr buffer");
                                load("data buffer");
                                move("reg to buffer");
                                move("data to memory");
                                disable("pc");
                                disable("data buffer");
                                disable("addr buffer");
                                delay(500);
                                move("data from memory");
                                enable("data buffer");
                                move("ad buffer to bus");
                                load("temp");
                                move("bus to temp");
                                disable("data buffer");
                                move("a to alu");
                                move("temp to alu");
                                move("alu to bus");
                                load("a");
                                move("bus to a");

                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                         disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);

                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( m.a[instruction_pointer].op_code == "SBB" )
                    {
                        if (  m.a[instruction_pointer].b[0].hex1 == 'M' )
                            {
                                temp=m.data[    returndec_2_1_byte (  h , l  )   ];
                                enable("pc");
                                load("addr buffer");
                                load("data buffer");
                                move("reg to buffer");
                                move("data to memory");
                                disable("pc");
                                disable("data buffer");
                                disable("addr buffer");
                                delay(500);
                                move("data from memory");
                                enable("data buffer");
                                move("ad buffer to bus");
                                load("temp");
                                move("bus to temp");
                                disable("data buffer");

                                f = a  -  temp ;//flags are afected
                            }

                        else{

                            reg1b src ;
                              switch(m.a[instruction_pointer].b[0].hex1 )
                                   {
                                        case 'A':
                                        src = a;
                                        send_this="a";
                                        break;

                                        case 'B':
                                        src = b;
                                        send_this="b";
                                        break;

                                        case 'C':
                                        src = c;
                                        send_this="c";
                                        break;

                                        case 'D':
                                        src = d;
                                        send_this="d";
                                        break;

                                        case 'E':
                                        src = e;
                                        send_this="e";
                                        break;

                                        case 'H':
                                        src = h;
                                        send_this="h";
                                        break;

                                        case 'L':
                                        src = l;
                                        send_this="l";
                                        break;
                                   }
                                   a-f.cy;
                                   f = a - src;
                                   if(send_this=="a")
                                   {
                                       move("a to bus");
                                   }
                                   else{ move("reg to bus");}
                                   load("temp");
                                   move("bus to temp");
                                   disable("temp");
                                   disable(send_this);
                                   disable("temp");
                            }


                        move("a to alu");
                                move("temp to alu");
                                move("alu to bus");
                                load("a");
                                move("bus to a");
                                disable("a");
                                enable("flip flop");
                                move("flip flop to bus");
                                load("temp");
                                move("bus to temp");
                                disable("temp");
                                disable("flip flop");
                               move("a to alu");
                                move("temp to alu");
                                move("alu to bus");
                                load("a");
                                move("bus to a");
                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                         disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);

                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "ADC" )
                    {
                        if (  m.a[instruction_pointer].b[0].hex1 == 'M' )
                            {
                                temp=m.data[    returndec_2_1_byte (  h , l  )   ];
                                f = a + f.cy ;
                                enable("pc");
                                load("addr buffer");
                                load("data buffer");
                                move("reg to buffer");
                                move("data to memory");
                                disable("pc");
                                disable("data buffer");
                                disable("addr buffer");
                                delay(500);
                                move("data from memory");
                                enable("data buffer");
                                move("ad buffer to bus");
                                load("temp");
                                move("bus to temp");
                                disable("data buffer");

                            f = a  +  temp ;//flags are afected
                            }

                        else{

                            reg1b src ;
                              switch(m.a[instruction_pointer].b[0].hex1 )
                                   {
                                        case 'A':
                                        src = a;
                                        send_this="a";
                                        break;

                                        case 'B':
                                        src = b;
                                        send_this="b";
                                        break;

                                        case 'C':
                                        src = c;
                                        send_this="c";
                                        break;

                                        case 'D':
                                        src = d;
                                        send_this="d";
                                        break;

                                        case 'E':
                                        src = e;
                                        send_this="e";
                                        break;

                                        case 'H':
                                        src = h;
                                        send_this="h";
                                        break;

                                        case 'L':
                                        src = l;
                                        send_this="l";
                                        break;

                                   }
                                   f=a+f.cy;
                                   f = a + src;
                                    if(send_this=="a")
                                   {
                                       move("a to bus");
                                   }
                                   else{ move("reg to bus");}
                                   load("temp");
                                   move("bus to temp");
                                   disable("temp");
                                   disable(send_this);
                                   disable("temp");
                            }


                        move("a to alu");
                                move("temp to alu");
                                move("alu to bus");
                                load("a");
                                move("bus to a");
                                disable("a");
                                enable("flip flop");
                                move("flip flop to bus");
                                load("temp");
                                move("bus to temp");
                                disable("temp");
                                disable("flip flop");
                               move("a to alu");
                                move("temp to alu");
                                move("alu to bus");
                                load("a");
                                move("bus to a");
                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                         disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);

                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////


                if( m.a[instruction_pointer].op_code == "XCHG" )
                    {
                        reg1b temp1,temp2;
                        temp1=d;
                        temp2=e;
                        d=h;
                        e=l;
                        h=temp1;
                        l=temp2;
                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                        enable("l");
                        load("e");
                        move("reg to bus");
                        move("bus to reg");
                        disable("e");
                        disable("l");
                        enable("h");
                        load("d");
                        move("reg to bus");
                        move("bus to reg");
                         disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);

                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "XTHL" )
                    {
                        cout << "top of stack instructio but stack  still not created";
                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                        enable("sp");
                        load("data buffer");
                        load("addr buffer");
                        move("reg to buffer");
                        move("addr to memory");

                        disable("sp");
                        disable("addr buffer");
                        disable("data buffer");
                        move("data from memory");
                        enable("data buffer");
                        move("ad buffer to bus");
                        load("l");
                        move("bus to reg");

                        enable("sp");
                        load("data buffer");
                        load("addr buffer");
                        move("reg to buffer");
                        move("addr to memory");

                        disable("sp");
                        disable("addr buffer");
                        disable("data buffer");
                        move("data from memory");
                        enable("data buffer");
                        move("ad buffer to bus");
                        load("h");
                        move("bus to reg");
                         disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);

                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "SPHL" )
                    {
                        sp.b[0].hex1=l.b.hex1;
                        sp.b[0].hex2=l.b.hex2;
                        sp.b[1].hex1=h.b.hex1;
                        sp.b[1].hex2=h.b.hex2;
                        load("sp");
                        enable("l");
                        move("reg to bus");
                        move("bus to reg");
                        disable("l");
                       enable("h");
                        move("reg to bus");
                        move("bus to reg");

                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                         disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);

                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "CMA" )
                    {
                        temp=a;
                        a-a;
                        f=a-temp;
                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                         disable("a");
                         move("a to alu");
                         move("alu to bus");
                         load("a");
                         move("bus to a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);

                        continue;

                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "STC" )
                    {
                        f.cy=1;
                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                        move("ir to id");
                        move("id to cu");
                        move("bus to flip flop");
                        disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);
                        continue;

                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "CMC" )
                    {
                        if(f.cy==1)
                            f.cy=0;
                        else if(f.cy==0)
                            f.cy=1;

                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                         move("ir to id");
                        move("id to cu");
                        move("bus to flip flop");
                        disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);
                        continue;

                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "HLT" )
                    {
                        cont=0;
                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                        disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);
                        continue;

                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "ADI" )
                    {
                        temp.b.hex1=m.a[instruction_pointer].b[1].hex1;
                        temp.b.hex2=m.a[instruction_pointer].b[1].hex2;
                        f = a+temp;
                        instruction_pointer+= m.a[instruction_pointer].sixed ;

                         enable("pc");
                                load("addr buffer");
                                load("data buffer");
                                move("reg to buffer");
                                move("data to memory");
                                disable("pc");
                                disable("data buffer");
                                disable("addr buffer");
                                delay(500);
                                move("data from memory");
                                enable("data buffer");
                                move("ad buffer to bus");
                                load("temp");
                                move("bus to temp");
                                disable("data buffer");
                                move("a to alu");
                                move("temp to alu");
                                move("alu to bus");
                                load("a");
                                move("bus to a");
                        disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "SUI" )
                    {
                        temp.b.hex1=m.a[instruction_pointer].b[1].hex1;
                        temp.b.hex2=m.a[instruction_pointer].b[1].hex2;
                        f = a-temp;
                        instruction_pointer+= m.a[instruction_pointer].sixed ;

                         enable("pc");
                                load("addr buffer");
                                load("data buffer");
                                move("reg to buffer");
                                move("data to memory");
                                disable("pc");
                                disable("data buffer");
                                disable("addr buffer");
                                delay(500);
                                move("data from memory");
                                enable("data buffer");
                                move("ad buffer to bus");
                                load("temp");
                                move("bus to temp");
                                disable("data buffer");
                                move("a to alu");
                                move("temp to alu");
                                move("alu to bus");
                                load("a");
                                move("bus to a");
                        disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "ACI" )
                    {
                        temp.b.hex1=m.a[instruction_pointer].b[1].hex1;
                        temp.b.hex2=m.a[instruction_pointer].b[1].hex2;
                        f = a+f.cy;
                        f = a+temp;
                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                         enable("pc");
                                load("addr buffer");
                                load("data buffer");
                                move("reg to buffer");
                                move("data to memory");
                                disable("pc");
                                disable("data buffer");
                                disable("addr buffer");
                                delay(500);
                                move("data from memory");
                                enable("data buffer");
                                move("ad buffer to bus");
                                load("temp");
                                move("bus to temp");
                                disable("data buffer");
                                move("a to alu");
                                move("temp to alu");
                                move("alu to bus");
                                load("a");
                                move("bus to a");
                                enable("flip flop");
                                move("flip flop to bus");
                                load("temp");
                                move("bus to temp");
                                disable("temp");
                                disable("flip flop");
                               move("a to alu");
                                move("temp to alu");
                                move("alu to bus");
                                load("a");
                                move("bus to a");

                        disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "SBI" )
                    {
                        temp.b.hex1=m.a[instruction_pointer].b[1].hex1;
                        temp.b.hex2=m.a[instruction_pointer].b[1].hex2;
                        f = a - f.cy;
                        f = a - temp;
                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                        enable("pc");
                                load("addr buffer");
                                load("data buffer");
                                move("reg to buffer");
                                move("data to memory");
                                disable("pc");
                                disable("data buffer");
                                disable("addr buffer");
                                delay(500);
                                move("data from memory");
                                enable("data buffer");
                                move("ad buffer to bus");
                                load("temp");
                                move("bus to temp");
                                disable("data buffer");
                                move("a to alu");
                                move("temp to alu");
                                move("alu to bus");
                                load("a");
                                move("bus to a");
                                enable("flip flop");
                                move("flip flop to bus");
                                load("temp");
                                move("bus to temp");
                                disable("temp");
                                disable("flip flop");
                               move("a to alu");
                                move("temp to alu");
                                move("alu to bus");
                                load("a");
                                move("bus to a");

                        disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "JMP" )
                    {

                        instruction_pointer = returndec_2_1_byte(m.a[instruction_pointer].b[1] ,m.a[instruction_pointer].b[2]  ) ;
                        enable("pc");
                                load("addr buffer");
                                load("data buffer");
                                move("reg to buffer");
                                move("data to memory");
                                disable("pc");
                                disable("data buffer");
                                disable("addr buffer");
                                delay(500);
                                move("data from memory");
                                enable("data buffer");
                                move("ad buffer to bus");
                                load("sp");
                                move("bus to reg");
                                disable("data buffer");

                        disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "JC" )
                    {
                        if (f.cy==1)
                            {instruction_pointer = returndec_2_1_byte(m.a[instruction_pointer].b[1] ,m.a[instruction_pointer].b[2]  ) ;
                            enable("pc");
                                enable("flip flop");
                                move("flip flop to bus");
                                load("ir");
                                move("bus to ir");
                                disable("ir");
                                disable("flip flop");
                                move("ir to id");
                                move("id to cu");
                                load("addr buffer");
                                load("data buffer");
                                move("reg to buffer");
                                move("data to memory");
                                disable("pc");
                                disable("data buffer");
                                disable("addr buffer");
                                delay(500);
                                move("data from memory");
                                enable("data buffer");
                                move("ad buffer to bus");
                                load("sp");
                                move("bus to reg");
                                disable("data buffer");}
                        else
                          {instruction_pointer+= m.a[instruction_pointer].sixed ;}

                        disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "JNC" )
                    {
                        if (f.cy==0)
                            {instruction_pointer = returndec_2_1_byte(m.a[instruction_pointer].b[1] ,m.a[instruction_pointer].b[2]  ) ;
                            enable("pc");
                                enable("flip flop");
                                move("flip flop to bus");
                                load("ir");
                                move("bus to ir");
                                disable("ir");
                                disable("flip flop");
                                move("ir to id");
                                move("id to cu");
                                load("addr buffer");
                                load("data buffer");
                                move("reg to buffer");
                                move("data to memory");
                                disable("pc");
                                disable("data buffer");
                                disable("addr buffer");
                                delay(500);
                                move("data from memory");
                                enable("data buffer");
                                move("ad buffer to bus");
                                load("sp");
                                move("bus to reg");
                                disable("data buffer");}
                        else
                            {instruction_pointer+= m.a[instruction_pointer].sixed ;}
                        disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "JP" )
                    {
                        if (f.s==0)
                            {instruction_pointer = returndec_2_1_byte(m.a[instruction_pointer].b[1] ,m.a[instruction_pointer].b[2]  ) ;
                            enable("pc");
                                enable("flip flop");
                                move("flip flop to bus");
                                load("ir");
                                move("bus to ir");
                                disable("ir");
                                disable("flip flop");
                                move("ir to id");
                                move("id to cu");
                                load("addr buffer");
                                load("data buffer");
                                move("reg to buffer");
                                move("data to memory");
                                disable("pc");
                                disable("data buffer");
                                disable("addr buffer");
                                delay(500);
                                move("data from memory");
                                enable("data buffer");
                                move("ad buffer to bus");
                                load("sp");
                                move("bus to reg");
                                disable("data buffer");}
                        else
                            {instruction_pointer+= m.a[instruction_pointer].sixed ;}
                        disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "JM" )
                    {
                        if (f.s==1)
                            {instruction_pointer = returndec_2_1_byte(m.a[instruction_pointer].b[1] ,m.a[instruction_pointer].b[2]  ) ;
                            enable("pc");
                                enable("flip flop");
                                move("flip flop to bus");
                                load("ir");
                                move("bus to ir");
                                disable("ir");
                                disable("flip flop");
                                move("ir to id");
                                move("id to cu");
                                load("addr buffer");
                                load("data buffer");
                                move("reg to buffer");
                                move("data to memory");
                                disable("pc");
                                disable("data buffer");
                                disable("addr buffer");
                                delay(500);
                                move("data from memory");
                                enable("data buffer");
                                move("ad buffer to bus");
                                load("sp");
                                move("bus to reg");
                                disable("data buffer");}
                        else
                            {instruction_pointer+= m.a[instruction_pointer].sixed ;
                            //cout<<m.a[instruction_pointer].sixed;
                            // remoce this cout statemenrt 98713
                            }
                        disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "JZ" )
                    {
                        if (f.z==1)
                            {instruction_pointer = returndec_2_1_byte(m.a[instruction_pointer].b[1] ,m.a[instruction_pointer].b[2]  ) ;
                            enable("pc");
                                enable("flip flop");
                                move("flip flop to bus");
                                load("ir");
                                move("bus to ir");
                                disable("ir");
                                disable("flip flop");
                                move("ir to id");
                                move("id to cu");
                                load("addr buffer");
                                load("data buffer");
                                move("reg to buffer");
                                move("data to memory");
                                disable("pc");
                                disable("data buffer");
                                disable("addr buffer");
                                delay(500);
                                move("data from memory");
                                enable("data buffer");
                                move("ad buffer to bus");
                                load("sp");
                                move("bus to reg");
                                disable("data buffer");}
                        else
                            {instruction_pointer+= m.a[instruction_pointer].sixed ;}
                        disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "JNZ" )
                    {
                        if (f.z==0)
                            {instruction_pointer = returndec_2_1_byte(m.a[instruction_pointer].b[1] ,m.a[instruction_pointer].b[2]  ) ;
                            enable("pc");
                                enable("flip flop");
                                move("flip flop to bus");
                                load("ir");
                                move("bus to ir");
                                disable("ir");
                                disable("flip flop");
                                move("ir to id");
                                move("id to cu");
                                load("addr buffer");
                                load("data buffer");
                                move("reg to buffer");
                                move("data to memory");
                                disable("pc");
                                disable("data buffer");
                                disable("addr buffer");
                                delay(500);
                                move("data from memory");
                                enable("data buffer");
                                move("ad buffer to bus");
                                load("sp");
                                move("bus to reg");
                                disable("data buffer");}
                        else
                            instruction_pointer+= m.a[instruction_pointer].sixed ;

                        disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( m.a[instruction_pointer].op_code == "JPE" )
                    {
                        if (f.p==1)
                            {instruction_pointer = returndec_2_1_byte(m.a[instruction_pointer].b[1] ,m.a[instruction_pointer].b[2]  ) ;
                            enable("pc");
                                enable("flip flop");
                                move("flip flop to bus");
                                load("ir");
                                move("bus to ir");
                                disable("ir");
                                disable("flip flop");
                                move("ir to id");
                                move("id to cu");
                                load("addr buffer");
                                load("data buffer");
                                move("reg to buffer");
                                move("data to memory");
                                disable("pc");
                                disable("data buffer");
                                disable("addr buffer");
                                delay(500);
                                move("data from memory");
                                enable("data buffer");
                                move("ad buffer to bus");
                                load("sp");
                                move("bus to reg");
                                disable("data buffer");}
                        else
                            {instruction_pointer+= m.a[instruction_pointer].sixed ;}
                        disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( m.a[instruction_pointer].op_code == "JPO" )
                    {
                        if (f.p==0)
                            {instruction_pointer = returndec_2_1_byte(m.a[instruction_pointer].b[1] ,m.a[instruction_pointer].b[2]  ) ;
                            enable("pc");
                                enable("flip flop");
                                move("flip flop to bus");
                                load("ir");
                                move("bus to ir");
                                disable("ir");
                                disable("flip flop");
                                move("ir to id");
                                move("id to cu");
                                load("addr buffer");
                                load("data buffer");
                                move("reg to buffer");
                                move("data to memory");
                                disable("pc");
                                disable("data buffer");
                                disable("addr buffer");
                                delay(500);
                                move("data from memory");
                                enable("data buffer");
                                move("ad buffer to bus");
                                load("sp");
                                move("bus to reg");
                                disable("data buffer");}
                        else
                            {instruction_pointer+= m.a[instruction_pointer].sixed ;}
                        disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////

                if( m.a[instruction_pointer].op_code == "DAD" )
                    {
                            reg1b src ,src2;
                            string send_this2;
                              switch(  m.a[instruction_pointer].b[0].hex2  )
                                   {
                                        case 'B':
                                        src = b;
                                        send_this2="b";
                                        src2 = c;
                                        send_this="c";
                                        break;

                                        case 'D':
                                        src = d;
                                        src2=e;
                                        send_this2="d";
                                        send_this="e";
                                        break;

                                        case 'H':
                                        src = h;
                                        src2 = l;
                                        send_this2="h";
                                        send_this2="l";
                                        break;

                                   }
                                   enable(send_this2);
                                   load("a");
                                   move("reg to bus");
                                   move("bus to a");
                                   disable("a");
                                   disable(send_this2);
                                   enable("h");
                                   load("temp");
                                   move("reg to bus");
                                   move("bus to temp");
                                   move("a to alu");
                                   move("temp to alu");
                                   disable("temp");
                                   disable("h");
                                   move("alu to bus");
                                   load("h");
                                   move("bus to reg");

                                enable(send_this);
                                   load("a");
                                   move("reg to bus");
                                   move("bus to a");
                                   disable("a");
                                   disable(send_this);
                                   enable("l");
                                   load("temp");
                                   move("reg to bus");
                                   move("bus to temp");
                                   move("a to alu");
                                   move("temp to alu");
                                   disable("temp");
                                   disable("l");
                                   move("alu to bus");
                                   load("l");
                                   move("bus to reg");

                               h+src;
                               l+src2;

                        instruction_pointer+= m.a[instruction_pointer].sixed ;
                        disable("a");
disable("b");
disable("c");
disable("d");
disable("e");
disable("h");
disable("l");
disable("sp");
disable("pc");
disable("idl");
disable("ir");
disable("flip flop");
disable("temp");
disable("addr buffer");
disable("data buffer");
disable("inst decoder");
disable("ale");
disable("rd");
disable("wr");
disable("iom");
disable("s1");
disable("s2");
disable("clock");
show_procesor_status();
status_run=call_click(status_run, status_fetch);

                        continue;
                    }
                    cu.t_state++ % 8;
                }
            }


        void display()
        {
            m.display();
        }

};

struct refrence_stack{
	string refrence;
	int which_jump;
};

reg2b asbl( memory & m , string  filename)
{
		int i=0, 	// instruction count
        	ir=0, 	// mem ref count   for conditional jumps
        	k,j=0;
        refrence_stack ref[100];
        int top=-1  ;

	std::ifstream infile( filename.c_str() );      //create a file object

	while( !infile.eof() )
	{	cout<<"\n\t\t\tfile pointer"<<infile<<endl;
        string buffer;
		infile >> buffer;// reading a word from the file well se later what that means in code

        if (  buffer.at ( 0 ) == '/' and buffer.at(1)=='/' )   // .at is a fuunction thqat checks buffers index char in this case its first to check if its a comment
		{
			// it is a comment
            cout <<"\ncomment found\n";
            char scrap[500];
            infile.getline(scrap,500);
            continue;
		}
		if (  buffer.at ( 0 ) == '#'  )   // .at is a fuunction thqat checks buffers index char in this case its first to check if its a comment
		{
			//   it is a begin org or db type command

            if (buffer.at (1) == 'B')
            	{
            		cout   <<"FOUND begin";
            		infile >>  m.mem_start.b[0].hex1 >>  m.mem_start.b[0].hex2 >>  m.mem_start.b[1].hex1>> m.mem_start.b[1].hex2;
        			i = m.int_start = returndec ( m.mem_start ) ;
        		}

            else if(buffer.at(1)=='O')
            	{	cout<<"FOUND org";
            		infile>> m.db_start.b[0].hex1>> m.db_start.b[0].hex2>> m.db_start.b[1].hex1>> m.db_start.b[1].hex2;
                    m.int_dbstart=returndec(m.db_start) ;

            	}
            else if(buffer.at(1)=='D')
            	{cout<<"FOUND db";
            		infile >> m.data_count;
            		int j= m.int_dbstart;
            		for(int i =0; i<m.data_count ; i++,j++)
            			{
            			infile>> m.data[j].b.hex1>> m.data[j].b.hex2;
            			}
						 char a;
                        infile >> a;
            	}

            continue;
		}
        if (  buffer.at( buffer.length() - 1 ) == ':' )//to check a loop thing anything that endes witha ":" is a goto reference in 85 used as a loop
		{
			// it is a mem refrence
            cout << "\n loop refrence found\n" ;
			m.r[ir].ref_name =  buffer;
			m.r[ir].addr     =  i     ;
			ir++;
			continue;
		}// if none of the conditions were met that means its a 85 key-word   so we go look into the dictionary

		////////////////   dictionary   /////////////// no calculation zone ,this is the coa zone
        else{
                m.a[i].op_code = buffer;m.ic++;                     // remember a stores instructions
				////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "MOV" )
                    {
                    	cout<<"\n mov found  \n";
                        m.a[i].sixed =  1 ;
                        m.a[i].var  =  2 ;
                        char coma;
                        infile >> m.a[i].b[0].hex1 >> coma >> m.a[i].b[0].hex2;

					i+= m.a[i].sixed;
                        continue;
					}////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "MVI" )
                    {
                        cout<<"\n found MVI \n";
                        m.a[i].sixed = 2 ;
                        m.a[i].var = 2;
                        char coma;
                        infile >> m.a[i].b[0].hex1 >> coma >> m.a[i].b[1].hex1>> m.a[i].b[1].hex2;
					i+= m.a[i].sixed;
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer =="LDA"  )
                    {
                        cout<< "\n lda found  \n";// one for opcode , 2 for a 16-bit address.
                        m.a[i].sixed = 3 ;
                        m.a[i].var = 1;
                        infile >>   m.a[i].b[1].hex1  >>  m.a[i].b[1].hex2  >>  m.a[i].b[2].hex1  >>  m.a[i].b[2].hex2; // mmemaddress in hex
                    i+= m.a[i].sixed;
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "LHLD")
                    {
                        cout<<"\n found lhld \n";
                        m.a[i].sixed = 3 ;
                        m.a[i].var = 1;
                        infile >>   m.a[i].b[1].hex1  >>  m.a[i].b[1].hex2  >>  m.a[i].b[2].hex1  >>  m.a[i].b[2].hex2; // mmemaddress in hex
                    i+= m.a[i].sixed;
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer =="LDAX" )
                    {
                        cout<< "\n ldax found  \n";
                        m.a[i].sixed=1;             // one for opcode , 2 for a 16-bit address.
                        m.a[i].var=1;
                        infile >>   m.a[i].b[0].hex1;  // register
                        i+= m.a[i].sixed;
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "LXI" )
                    {
                        cout<<"\n found LXI \n";
                        m.a[i].sixed = 3 ;
                        m.a[i].var = 2;char comma;


                        infile >>   m.a[i].b[0].hex1;      // register pair
                        infile >> comma;
                   	    infile >>   m.a[i].b[1].hex1  >>  m.a[i].b[1].hex2  >>  m.a[i].b[2].hex1  >>  m.a[i].b[2].hex2; // mmemaddress in hex
                    i+= m.a[i].sixed;
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "STA" )
                    {
                        cout<<"\n found sta \n";
                        m.a[i].sixed = 3 ;
                        m.a[i].var = 1;
                   		infile >>   m.a[i].b[1].hex1  >>  m.a[i].b[1].hex2  >>  m.a[i].b[2].hex1  >>  m.a[i].b[2].hex2; // mmemaddress in hex
                    i+= m.a[i].sixed;
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "STAX")
                    {
                        cout<<"\n found stax \n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var = 1;
                        infile >> m.a[i].b[0].hex1;
                   	i+= m.a[i].sixed;
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "SHLD")
                    {
                        cout<<"\n found SHLD \n";
                        m.a[i].sixed = 3 ;
                        m.a[i].var  = 1 ;
                   		infile >>   m.a[i].b[1].hex1  >>  m.a[i].b[1].hex2  >>  m.a[i].b[2].hex1  >>  m.a[i].b[2].hex2; // mmemaddress in hex
                    i+= m.a[i].sixed;
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "ADD" )
                    {
                        cout<<"\n found ADD \n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 1 ;

                        infile >> m.a[i].b[0].hex1 ;    // scanning the data
                        //infile >> m.a[i].data[1];
                   	i+= m.a[i].sixed;
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "SUB" )
                    {
                        cout<<"\n found SUB \n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 1 ;
                        infile >> m.a[i].b[0].hex1 ;    // scanning the data
                        //infile >> m.a[i].data[1];
                   	i+= m.a[i].sixed;
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "ADC" )
                    {
                        cout<<"\n found ADC \n";
                        m.a[i].sixed = 2 ;
                        m.a[i].var  = 1 ;
                        infile >> m.a[i].b[0].hex1 ;    // scanning the data
                        //infile >> m.a[i].data[1];
                   	i+= m.a[i].sixed;
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "XCHG")
                    {
                        cout<<"\n found XCHG\n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 0 ;
                   	i+= m.a[i].sixed;
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "RLC" )
                    {
                        cout<<"\n found RLC\n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 0 ;
                   	i+= m.a[i].sixed;
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "RRC" )
                    {
                        cout<<"\n found RRC\n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 0 ;
                   	i+= m.a[i].sixed;
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "XTHL")
                    {
                        cout<<"\n found XTHL\n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 0 ;
                   	i+= m.a[i].sixed;
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "CMA" )
                    {
                        cout<<"\n found cma\n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 0 ;
                   	i+= m.a[i].sixed;
                        continue;

                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "STC" )
                    {
                        cout<<"\n found stc\n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 0 ;
                   	i+= m.a[i].sixed;
                        continue;

                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "CMC" )
                    {
                        cout<<"\n found CMC\n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 0 ;
                   	i+= m.a[i].sixed;
                        continue;

                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "HLT" )
                    {
                        cout<<"\n found HLT\n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 0 ;

                   	i+= m.a[i].sixed;
                        continue;

                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "ADI" )
                    {
                        cout<<"\n found ADI\n";
                        m.a[i].sixed = 2 ;
                        m.a[i].var  = 1 ;
                        infile >> m.a[i].b[1].hex1 >> m.a[i].b[1].hex2;
                   	i+= m.a[i].sixed;
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "SUI" )
                    {
                        cout<<"\n found SUI\n";
                        m.a[i].sixed = 2 ;
                        m.a[i].var  = 1 ;
                        infile >> m.a[i].b[1].hex1 >> m.a[i].b[1].hex2;
                   	i+= m.a[i].sixed;
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "ACI" )
                    {
                        cout<<"\n found ACI\n";
                        m.a[i].sixed = 2 ;
                        m.a[i].var  = 1 ;
                        infile >> m.a[i].b[1].hex1 >> m.a[i].b[1].hex2;
                   	i+= m.a[i].sixed;
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                    /// conditionAL JUMPS

                if( buffer == "JC" || buffer == "JNC"|| buffer == "JP" ||buffer == "JM"|| buffer == "JZ"|| buffer == "JNZ"|| buffer == "JPE" || buffer == "JPO")
                    {
                        cout<<"\n found conditional jumps\n";
                        m.a[i].sixed = 3 ;
                        m.a[i].var  = 1 ;
                        string buffer;
                        infile>>buffer;
                        int address;
                        cout<<"working on jmp";
                        int j=0; int l=0;
                        for(int i=0;i<ir;i++)
                        	{
                        		if (  strncmp(m.r[i].ref_name.c_str()  , buffer.c_str() ,  buffer.length()   ) == 0 )
                        			{
                        			    address=m.r[i].addr;
                        			    cout<< "\n\n"<<i<<m.r[i].ref_name;
                        			    cout<<"\n\nrefrence found in code segment \n\n";
                        			    l=1;
                        			}
                        	}
                        if(l==0)
                        	{
                        		cout << "\n\n*** creating an exception , ####### done 100%% waiting to find this loop refrence later in code\n\n";
                        		top++;
                        		ref[top].refrence=buffer;
                        		ref[top].which_jump=i;

                    			i+= m.a[i].sixed;
                        		continue;
                    		}
						char hexa[4];
						hexa[0]=hexa[1]=hexa[2]=hexa[3]='0';
                        cout<<"\n\nADDRESS EXEPTION : NEW ADDRESS IS "<<address;
    					int quotient = address;
    					int  temp1;
    					int k=0;
    					while(quotient!=0)
    					{
        	 				temp1 = quotient % 16;

 			     			if( temp1 < 10)
           					temp1 =temp1 + 48;
      						else
 		        			temp1 = temp1 + 55;

      						hexa[k++]= temp1;
				      		quotient = quotient / 16;
  					  	}

    					m.a[i].b[1].hex1=hexa[3];
				    	m.a[i].b[1].hex2=hexa[2];
				    	m.a[i].b[2].hex1=hexa[1];
				    	m.a[i].b[2].hex2=hexa[0];

                    cout<<"\n\n jump ka pointing address = "<<m.a[i].b[1].hex1<<m.a[i].b[1].hex2<<m.a[i].b[2].hex1<<m.a[i].b[2].hex2<<endl;
                    m.a[address].show_inst(address);
                        i+= m.a[i].sixed;
                        continue;
                    }
                    ////////////////////////////////////////////////////////////////////////////////////////////////////

                if( buffer == "SPHL")
                    {
                        cout<<"\n found SPHL\n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 0  ;
                        i+= m.a[i].sixed ;
                        continue;
                    }
                    ////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "CMP" )
                    {
                        cout<<"\n found CMP\n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 1  ;
                        infile >> m.a[i].b[0].hex1;
                        i+= m.a[i].sixed ;
                        continue;
                    }
                    ////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "CPI" )
                    {
                        cout<<"\n found CPI\n";
                        m.a[i].sixed = 2 ;
                        m.a[i].var  = 1  ;
                        infile >> m.a[i].b[1].hex1>> m.a[i].b[1].hex2;
                        i+= m.a[i].sixed ;
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "ANI" )
                    {
                        cout<<"\n found ANI\n";
                        m.a[i].sixed = 2 ;
                        m.a[i].var  = 1  ;
                        infile >> m.a[i].b[1].hex1>> m.a[i].b[1].hex2;
                        i+= m.a[i].sixed ;
                        continue;
                    }
                    ////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "XRI" )
                    {
                        cout<<"\n found XRI\n";
                        m.a[i].sixed = 2 ;
                        m.a[i].var  = 1  ;
                        infile >> m.a[i].b[1].hex1>> m.a[i].b[1].hex2;
                        i+= m.a[i].sixed ;
                        continue;
                    }
                    ////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "ORI" )
                    {
                        cout<<"\n found ORI\n";
                        m.a[i].sixed = 2 ;
                        m.a[i].var  = 1  ;
                        infile >> m.a[i].b[1].hex1>> m.a[i].b[1].hex2;
                        i+= m.a[i].sixed ;
                        continue;
                    }
                    ////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "ANA" )
                    {
                        cout<<"\n found ANA\n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 1  ;
                        infile >> m.a[i].b[0].hex1;
                        i+= m.a[i].sixed ;
                        continue;
                    }
                    ////////////////////////////////////////////////////////////////////////////////////////////////////
				if( buffer == "ORA" )
                    {
                        cout<<"\n found ORA\n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 1  ;
                        infile >> m.a[i].b[0].hex1;
                        i+= m.a[i].sixed ;
                        continue;
                    }
                    ////////////////////////////////////////////////////////////////////////////////////////////////////
				if( buffer == "XRA" )
                    {
                        cout<<"\n found XRA\n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 1  ;
                        infile >> m.a[i].b[0].hex1;
                        i+= m.a[i].sixed ;
                        continue;
                    }
                    ////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "DAA" )
                    {
                        cout<<"\n found DAA\n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 0  ;
                        i+= m.a[i].sixed ;
                        continue;
                    }

                    ////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "PCHL")
                    {
                        cout<<"\n found PCHL\n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 0  ;
                        i+= m.a[i].sixed ;
                        continue;
                    }

                    ////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "RST" )
                    {
                        cout<<"\n found RST\n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 1  ;
                        infile >> m.a[i].b[1].hex1;
                        i+= m.a[i].sixed ;
                        continue;
                    }
                    ////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "PUSH")
                    {
                        cout<<"\n found PUSH\n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 1  ;
                        infile >> m.a[i].b[1].hex1;
                        i+= m.a[i].sixed ;
                        continue;
                    }
                    ////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "POP" )
                    {
                        cout<<"\n found POP\n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 1  ;
                        infile >> m.a[i].b[1].hex1;
                        i+= m.a[i].sixed ;
                        continue;
                    }
                    ////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "SBI" )
                    {
                        cout<<"\n found SBI\n";
                        m.a[i].sixed = 2 ;
                        m.a[i].var  = 1 ;
                        infile >> m.a[i].b[1].hex1 >> m.a[i].b[1].hex2;
                   	i+= m.a[i].sixed;
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "SBB" )
                    {
                        cout<<"\n found SBB\n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 1 ;
                        infile >> m.a[i].b[0].hex1 ;
                   	i+= m.a[i].sixed;
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "INR" )
                    {
                        cout<<"\n found INR\n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 1 ;
                        infile >> m.a[i].b[0].hex1 ;
                   	i+= m.a[i].sixed;
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "INX" )
                    {
                        cout<<"\n found INX\n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 1 ;
                        infile >> m.a[i].b[0].hex1 ;
                   	i+= m.a[i].sixed;
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "DCR" )
                    {
                        cout<<"\n found DCR\n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 1 ;
                        infile >> m.a[i].b[0].hex1 ;
                   	i+= m.a[i].sixed;
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
				if( buffer == "DCX" )
                    {
                        cout<<"\n found DCX\n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 1 ;
                        infile >> m.a[i].b[0].hex1 ;
                   	i+= m.a[i].sixed;
                        continue;
                    }////////////////////////////////////////////////////////////////////////////////////////////////////
                if( buffer == "JMP" )
                    {
                        cout<<"\n found JMP\n";
                        m.a[i].sixed = 3 ;
                        m.a[i].var  = 1 ;
                        string buffer;
                        infile>>buffer;
                        int address;
                        cout<<"working on jmp";
                        int j=0; int l=0;
                        for(int i=0;i<ir;i++)
                        	{
                        		if (  strncmp(m.r[i].ref_name.c_str()  , buffer.c_str() ,  buffer.length()   ) == 0 )
                        			{
                        			    //9871301132;
                        			    address=m.r[i].addr;
                        			    cout<< "\n\n"<<i<<m.r[i].ref_name;
                        			    cout<<"\n\nrefrence found in code segment \n\n";
                        			    l=1;
                        			}
                        	}
                        if(l==0)
                        	{
                        		cout << "\n\n*** creating an exception , ####### done 100%% waiting to find this loop refrence later in code\n\n";
                        		top++;
                        		ref[top].refrence=buffer;
                        		ref[top].which_jump=i;

                    			i+= m.a[i].sixed;
                        		continue;
                    		}
						char hexa[4];
   						hexa[0]=hexa[1]=hexa[2]=hexa[3]='0';

                        cout<<"\n\nThe Address is >>  "<<address;
    					int quotient = address;
    					int  temp1;
    					int k=0;
    					while(quotient!=0)
    					{
        	 				temp1 = quotient % 16;

 			     			if( temp1 < 10)
           					temp1 =temp1 + 48;
      						else
 		        			temp1 = temp1 + 55;

      						hexa[k++]= temp1;
				      		quotient = quotient / 16;
  					  	}

    					m.a[i].b[1].hex1=hexa[3];
				    	m.a[i].b[1].hex2=hexa[2];
				    	m.a[i].b[2].hex1=hexa[1];
				    	m.a[i].b[2].hex2=hexa[0];

                    cout<<"\n\n jump ka pointing address = "<<m.a[i].b[1].hex1<<m.a[i].b[1].hex2<<m.a[i].b[2].hex1<<m.a[i].b[2].hex2<<endl;

                        i+= m.a[i].sixed;
                        continue;

                    }
                if( buffer == "DAD" )
                    {
                        cout<<"\n found DAD\n";
                        m.a[i].sixed = 1 ;
                        m.a[i].var  = 1 ;
                        infile >>m.a[i].b[0].hex1;    // scanning the data

                   	i+= m.a[i].sixed;
                        continue;
                    }
                    ////////////////////////////////////////////////////////////////////////////////////////////////////

                else
                    {
                        cout<<"\n command "" "<< buffer <<"""   not found \n\n";
                        cout<<"\n\n\n\n*****PLEASE CHECK YOUR CODE CAREFULLY *****\n\n\n\n";

                        break;
                    } // all instructions library
            }
	}
	m.ic=i;

	while( top != -1 )
		{int address;
			int j=0;
						for(j=0;j<ir;j++)
                        	{
                        	    cout<<m.r[j].ref_name<<endl;
                        	    cout<<ref[top].refrence<<endl;

                        		if (  strncmp( m.r[j].ref_name.c_str() , ref[top].refrence.c_str() ,  m.r[j].ref_name.length() -1  ) == 0 )
                        			{
                        			    address=m.r[j].addr;

                        			    break;
                        			}
                        	}

                if( j == ir)
                {
                	cout<<"code incomplete";
                	break;
                }
                else
                {
                	char hexa[4];
					hexa[0]=hexa[1]=hexa[2]=hexa[3]='0';

    					int quotient = address;
    					int  temp1;
    					int i=0;
    					while(quotient!=0)
    					{
        	 				temp1 = quotient % 16;

 			     			if( temp1 < 10)
           					temp1 =temp1 + 48;
      						else
 		        			temp1 = temp1 + 55;

      						hexa[i++]= temp1;
				      		quotient = quotient / 16;
  					  	}

    					m.a[ ref[top].which_jump ].b[1].hex1=hexa[3];
				    	m.a[ ref[top].which_jump ].b[1].hex2=hexa[2];
				    	m.a[ ref[top].which_jump ].b[2].hex1=hexa[1];
				    	m.a[ ref[top].which_jump ].b[2].hex2=hexa[0];
            	}
			top--;
		}

	cout << "\n\n\nFile read\n";
	return m.mem_start;
}

int main()
{
    handshaker<string> handshake[12];
	processor p;

    string filename;
    string temp;

    while(1)
    {
    char choice;
    cout<<"\n\n\t\t\tD. -> To use the default file.\n\n\n\t\t\tN. -> To use a diffrent file.\n\n\t\t\t\t  ";
    choice=getchare();
        temp="";
        filename="";
        if(choice== 'D' ||choice== 'd' )
            {
                filename = "8085_default.txt";
                temp+="8085_default.txt";
                break;
            }

        else if(choice == 'N' || choice== 'n')
            {
                cout <<"Enter the file location(name) you want to use :";
                temp += "notepad ";
                string a;
                cin>>a;
                filename+=a;
                temp+=a;
                break;
            }
    }
    initwindow( 1300 , 700 );

    logo();
    main_graph();

    int xx=1500,yy=500;
	int assembled=0,read=0;

sos:
    do
    {
       getmouseclick(WM_LBUTTONDOWN,xx,yy);
        if(xx>100&&xx<183&&yy<45&&yy>6 && read )
        {
            p.assembel(filename.c_str());
            cleardevice();
            main_graph();
                    setfillstyle(SOLID_FILL,COLOR(112,112,112));
                    floodfill(105,8,WHITE);
                    setfillstyle(SOLID_FILL,BLACK);
                    delay(100);
                    floodfill(105,8,WHITE);
            assembled=1;
            cord=127;
            p.display();
        }
       else
        if(xx>10 && xx<90 && yy<45 && yy>6)
            {

                    setfillstyle(SOLID_FILL,COLOR(112,112,112));
                    floodfill(15,8,WHITE);
                    setfillstyle(SOLID_FILL,BLACK);
                    delay(100);
                    floodfill(15,8,WHITE);

                system ( temp.c_str() ) ;
                read=1;
                assembled=0;

                goto sos;
            }
           else if(xx>1040&&xx<1160&&yy>6&&yy<45 && assembled)
            {
                // run all
                status_run=0;
                                setfillstyle(SOLID_FILL,BLACK);
                char s[10];
                sprintf(s,"%d",Tstate);
                bar(950,73,1060,90);
                outtextxy(950,73,"T-State");
                outtextxy(1030,73,s);
                Tstate++;

                    setfillstyle(SOLID_FILL,COLOR(112,112,112));
                    floodfill(1045,8,WHITE);
                    setfillstyle(SOLID_FILL,BLACK);
                    delay(100);
                    floodfill(1044,8,WHITE);
                p.execute_microinst();
                break;
            }
            else if(xx>1170 && xx<1300 && yy>6 && yy<45 && assembled)
            {
                // run step by step
                status_run=1;
                                setfillstyle(SOLID_FILL,BLACK);
                char s[10];
                sprintf(s,"%d",Tstate);
                bar(950,73,1060,90);
                outtextxy(950,73,"T-State");
                outtextxy(1030,73,s);
                Tstate++;

                    setfillstyle(SOLID_FILL,COLOR(112,112,112));
                    floodfill(1174,8,WHITE);
                    setfillstyle(SOLID_FILL,BLACK);
                    delay(100);
                    floodfill(1174,8,WHITE);
            	p.execute_microinst();
            	break;
            }

            else if( xx>280&&xx<320&&yy>650&&yy<690 )
            {
                show_creator();
            }

            else if(xx>910&&xx<1030&&yy>6&&yy<45 && status_run)
            {
                // fetch
                status_fetch=!status_fetch;
                if(status_fetch==0)
                {
                    setfillstyle(SOLID_FILL,BLACK);
                    floodfill(920,8,WHITE);
                    setfillstyle(SOLID_FILL,BLACK);

                    }

                if(status_fetch==1)
                {
                    setfillstyle(SOLID_FILL,RED);
                    floodfill(920,8,WHITE);
                    setfillstyle(SOLID_FILL,WHITE);
                }
            }
            else if(xx>780&&xx<900&&yy>6&&yy<45 && status_run)
            {

                // status graphics
                status_graphics=!status_graphics;
                if(status_graphics==1)
                {
                    setfillstyle(SOLID_FILL,BLACK);
                    floodfill(784,8,WHITE);
                    setfillstyle(SOLID_FILL,WHITE);
                    }

                if(status_graphics==0)
                {
                    setfillstyle(SOLID_FILL,RED);
                    floodfill(784,8,WHITE);
                    setfillstyle(SOLID_FILL,WHITE);
                }
            }
    } while(1) ;

return 0;
}
