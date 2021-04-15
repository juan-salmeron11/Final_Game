#include <stdlib.h>
#include <string.h>

#include <stdlib.h>
#include <string.h>

// include NESLIB header
#include "neslib.h"

// include CC65 NES Header (PPU)
#include <nes.h>

// link the pattern table into CHR ROM
//#link "chr_generic.s"
//#link "Level_Select.s"
//#link "River_back.s"

// BCD arithmetic support
#include "bcd.h"
//#link "bcd.c"

// VRAM update buffer
#include "vrambuf.h"
//#link "vrambuf.c"

/********* MUSIC SETTINGS *********************************/
//#link "famitone2.s"
//#link "menu_theme.s"
//#link "sfx.s"
//#link "demosounds.s"
extern char demo_sounds[];
extern char sfx_sounds[];
extern char menu_theme_music_data[];
/**********************************************************/







/**********************************METASPRITES  **********************************************************************/
// define a 2x4 metasprite for the motorcycle
#define DEF_METASPRITE_2x2(name,code,pal)\
const unsigned char name[]={\
        0,      0,      (code)+0,   pal, \
        0,      8,      (code)+1,   pal, \
        8,      0,      (code)+2,   pal, \
        8,      8,      (code)+3,   pal, \
        16,      0,      (code)+4,   pal, \
        16,      8,      (code)+5,   pal, \
        24,      0,      (code)+6,   pal, \
        24,      8,      (code)+7,   pal, \
        128};
// define a 2x4 metasprite for VAN enemy
#define DEF_METASPRITE_VAN(name,code,pal)\
const unsigned char name[]={\
        0,      0,      (code)+0,   pal, \
        0,      8,      (code)+1,   pal, \
        8,      0,      (code)+2,   pal, \
        8,      8,      (code)+3,   pal, \
        16,      0,      (code)+4,   pal, \
        16,      8,      (code)+5,   pal, \
        24,      0,      (code)+6,   pal, \
        24,      8,      (code)+7,   pal, \
        128};
//Meta Sprite for Gas Can
#define DEF_METASPRITE_GAS(name, code, pal)\
const unsigned char name[]={\
        0,      0,      (code)+0,   pal, \
        0,      8,      (code)+1,   pal, \
        8,      0,      (code)+2,   pal, \
        8,      8,      (code)+3,   pal, \
        128};
//Meta Sprite for Gas Can
#define DEF_METASPRITE_CONE(name, code, pal)\
const unsigned char name[]={\
        0,      0,      (code)+0,   pal, \
        0,      8,      (code)+1,   pal, \
        8,      0,      (code)+2,   pal, \
        8,      8,      (code)+3,   pal, \
        128};


/**********************************METASPRITE ANIMATION SEQUENCES **********************************************************************/

//Meta Sprites for Driving animation of the Motorcycle
DEF_METASPRITE_2x2(playerRRun1, 0xcc, 1);
DEF_METASPRITE_2x2(playerRRun2, 0xec, 1);

//Meta sprite for Driving animation of Van vehicle
DEF_METASPRITE_VAN(vanMove1, 0xc4, 2);
DEF_METASPRITE_VAN(vanMove2, 0xe4, 2);

//Meta Sprite for Gas Can
DEF_METASPRITE_GAS(trashMove1, 0xd4 , 1);
DEF_METASPRITE_GAS(trashMove2, 0xd8 , 1);

//Meta Sprite for Cone
DEF_METASPRITE_CONE(crocMove1, 0xdc , 3);
DEF_METASPRITE_CONE(crocMove2, 0xe0 , 3);

//Motorcycle Movement Sequence
const unsigned char* const playerRunSeq[16] = {
  playerRRun1, playerRRun2, playerRRun1, 
  playerRRun1, playerRRun2, playerRRun1, 
  playerRRun1, playerRRun2,
  playerRRun1, playerRRun2, playerRRun1, 
  playerRRun1, playerRRun2, playerRRun1, 
  playerRRun1, playerRRun2,
};

//VAN Movement Sequence
const unsigned char* const VanRunSeq[16] = {
  vanMove1, vanMove2, vanMove1, 
  vanMove1, vanMove2, vanMove1, 
  vanMove1, vanMove2,
  vanMove1, vanMove2, vanMove1, 
  vanMove1, vanMove2, vanMove1, 
  vanMove1, vanMove2,
};

//Croc Movement Sequence
const unsigned char* const CrocSeq[16] = {
  crocMove1, crocMove2, crocMove1, 
  crocMove1, crocMove2, crocMove1, 
  crocMove1, crocMove2,
  crocMove1, crocMove2, crocMove1, 
  crocMove1, crocMove2, crocMove1, 
  crocMove1, crocMove2,
};

//Croc Movement Sequence
const unsigned char* const TrashSeq[16] = {
  trashMove1, trashMove2, trashMove1, 
  trashMove1, trashMove2, trashMove1, 
  trashMove1, trashMove2,
  trashMove1, trashMove2, trashMove1, 
  trashMove1, trashMove2, trashMove1, 
  trashMove1, trashMove2,
};


#define NUM_ACTORS 1
#define NUM_ENEMIES 3

byte actor_x[NUM_ACTORS];
byte actor_y[NUM_ACTORS];
sbyte actor_dx[NUM_ACTORS];
sbyte actor_dy[NUM_ACTORS];

//Gas can coordinates and movement variables
byte gasCan_x[NUM_ACTORS];
byte gasCan_y[NUM_ACTORS];
sbyte gasCan_dx[NUM_ACTORS];
sbyte gasCan_dy[NUM_ACTORS];


//Van vehicle coordinates and movement variables
byte van_x[NUM_ENEMIES];
byte van_y[NUM_ENEMIES];
sbyte van_dx[NUM_ENEMIES];
sbyte van_dy[NUM_ENEMIES];


//Cone coordinates and movement variables
byte cone_x;
byte cone_y;
sbyte cone_dx = -1;
sbyte cone_dy;
//Boat has 3 lives
int lives = 3;
//When number of trash bags collected is 5, you win
int totalBags = 0;
int hit = 0;
bool invis = false;
bool gas_can = false;
int points=0;
bool aa = false;


/*********************************************************/

extern const byte level_select_pal[16];
extern const byte level_select_rle[];
extern const byte river_pal[16];
extern const byte river_rle[];

char pad;	// controller flags
char i;
char oam_id;
int j;
int arrow_x =25;
int arrow_y =70;
bool cleared[4];

/*{pal:"nes",layout:"nes"}*/
const char PALETTE[32] = { 
  0x03,			// screen color

  0x11,0x30,0x27,0x00,	// background palette 0
  0x1C,0x20,0x2C,0x00,	// background palette 1
  0x00,0x10,0x20,0x00,	// background palette 2
  0x06,0x16,0x26,0x00,   // background palette 3

  0x02,0x35,0x11,0x00,	// sprite palette 0
  0x00,0x37,0x25,0x00,	// sprite palette 1
  0x0D,0x2D,0x3A,0x00,	// sprite palette 2
  0x0D,0x27,0x2A	// sprite palette 3
};

// setup PPU and tables
void setup_graphics(void);
void show_title_screen(int x);
void level_screen(const byte* pal, const byte* rle);
void menu_controls(void);
void river(void);
void scroll_background(void);
void show_screen_scrolling(const byte* pal, const byte* rle,const byte* rle2);


void main(void)
{
  for(j = 0;j<4;j++){
    cleared[j] = false;
  }
  
  //Play Menu Theme
  famitone_init(menu_theme_music_data);
  nmi_set_callback(famitone_update);  
  setup_graphics();
  level_screen(level_select_pal,level_select_rle);

  

}


// setup PPU and tables
void setup_graphics() {
  // clear sprites
  oam_hide_rest(0);
  // set palette colors
  pal_all(PALETTE);
  // turn on PPU
  ppu_on_all();
}

void level_screen(const byte* pal, const byte* rle) {
  ppu_off();
  pal_bg(pal);
  vram_adr(0x2000);
  vram_unrle(rle);
  
  for(j = 0;j<4;j++){
    if(cleared[j] == true){
      if(j == 0){
        vram_adr(NTADR_A(5,8));
        vram_write("        ", 8); 
        vram_adr(NTADR_A(5,9));
        vram_write(" CLEAR  ", 8); 
        vram_adr(NTADR_A(5,10));
        vram_write("        ", 8);
      }
      if(j == 1){
        vram_adr(NTADR_A(19,8));
        vram_write("        ", 8); 
        vram_adr(NTADR_A(19,9));
        vram_write(" CLEAR  ", 8); 
        vram_adr(NTADR_A(19,10));
        vram_write("        ", 8);
      }
      if(j == 2){
        vram_adr(NTADR_A(5,20));
        vram_write("        ", 8); 
        vram_adr(NTADR_A(5,21));
        vram_write(" CLEAR  ", 8); 
        vram_adr(NTADR_A(5,22));
        vram_write("        ", 8);
      }
      if(j == 3){
        vram_adr(NTADR_A(19,20));
        vram_write("        ", 8); 
        vram_adr(NTADR_A(19,21));
        vram_write(" CLEAR  ", 8); 
        vram_adr(NTADR_A(19,22));
        vram_write("        ", 8);
      }
    }
  
  
  }
  
  
  ppu_on_all();
  //music_play(0);
  sfx_init(demo_sounds);

  
    while(1) {
    menu_controls();
    oam_id = 0;
    oam_id = oam_spr(arrow_x, arrow_y, 0x3e, 0, oam_id);
        if (oam_id!=0) oam_hide_rest(oam_id);

  }
}

void menu_controls(){
  
  pad = pad_trigger(i);
  
  if (pad & PAD_DOWN && arrow_y == 70) {    
      	sfx_play(2,0);
      	arrow_y = 165;           
    }
    
  if (pad & PAD_UP && arrow_y == 165) {
      	sfx_play(2,0);
      	arrow_y = 70;
    }
  
  if (pad & PAD_LEFT && arrow_x == 138) {
    	sfx_play(2,0);
    	arrow_x = 25;      
    }
    
  if (pad & PAD_RIGHT && arrow_x == 25) {      	
    	sfx_play(2,0);
    	arrow_x = 138;
    }
  
  //Select Choice sfx
  if (pad & PAD_START) {
    	music_stop();
    	sfx_init(sfx_sounds);
      	sfx_play(1,0);
    if (arrow_x == 25 && arrow_y ==70){
      show_title_screen(0);
    
    }
    else if (arrow_x == 138 && arrow_y ==70){
    show_title_screen(1);}
    else if (arrow_x == 25 && arrow_y ==165){
    show_title_screen(2);}
    else{
    show_title_screen(3);}
    }
                   
}


void show_title_screen(int x) {
  ppu_off();
  vram_adr(NAMETABLE_A);
  vram_fill(0,1024);
  oam_clear();
  if(x==0){
    vram_adr(NTADR_A(11,14));
  vram_write("City Level", 10);
  }
  else   if(x==1){
    vram_adr(NTADR_A(10,14));
  vram_write("Forest Level", 12);
  }
  else   if(x==2){
   river();
  }
  else{
    vram_adr(NTADR_A(9,14));
  vram_write("Mountain Level", 14);
  }
  ppu_on_all();
  while(1){
  pad = pad_trigger(i);
  if(pad&PAD_START){
  sfx_init(demo_sounds);
    cleared[x] = true;
  level_screen(level_select_pal,level_select_rle);

  }};
}

void show_screen_scrolling(const byte* pal, const byte* rle,const byte* rle2) {
  // disable rendering
  ppu_off();
  // set palette, virtual bright to 0 (total black)
  pal_bg(pal);
  
  // unpack nametable into the VRAM
  vram_adr(0x2000);
  vram_unrle(rle);
  vram_adr(0x2400);
  vram_unrle(rle2);
  // enable rendering
  ppu_on_all();
}


void scroll_background() {
  int x = 0;   // x scroll position
  int y = 0;   // y scroll position
  int dx = 0;  // y scroll direction
  int lives = 3;
  
  char i;	// actor index
  char oam_id;	// sprite ID
  char pad;	// controller flags
  
  //Place the player in the left fourth of the screen  
  actor_x[0] = 40;
  actor_y[0] = 191;
  actor_dx[0] = 0;
  actor_dy[0] = 0; 
  
    
  //Placeholder for Trash bag
  gasCan_x[0] = 0;	//Appear from rightmost part of screen
  gasCan_y[0] = 180;
  gasCan_dx[0] = 0;
  gasCan_dy[0] = 0;
  
  //Submarine vehicle placement
  for (i = 0; i < NUM_ENEMIES; i++)
  {
  van_x[i] = (rand() % (254 + 1 - 150)) + 150;
  van_y[i] = (rand() % (210 + 1 - 150)) + 150;	//Vans spawn randomly within street range
  van_dx[i] = 0;
  van_dy[i] = 0;
    
  }
  
  //Crocodile placement and speed
  cone_x = (rand() % (254 + 1 - 200)) + 200;
  cone_y = (rand() % (210 + 1 - 150)) + 150;
  cone_dx = 0;
  cone_dy = 0;
  
  // infinite loop
  while (1) {
  
      oam_id = 0;
    
    // set player 0/1 velocity based on controller
    for (i=0; i<1; i++) {
      // poll controller i (0-1)
      pad = pad_poll(i);
      
      if (pad&PAD_LEFT && actor_x[i]>10) {
        x-=1;			//Slows down the Background Scrolling
        actor_dx[i] = -1;
      }
      else if (pad&PAD_RIGHT && actor_x[i]<220) {
        x+=2;           	//Speeds up background scrolling
        actor_dx[i] = 1;	//Speed up bike until hits the screen
      }
      
      else{
              actor_dx[i]=0;
              dx =0;
            }
      if (pad&PAD_UP && actor_y[i] > 150)
        actor_y[i] -=1 ;	//Moves player to the up until hits sidewalk
      else if (pad&PAD_DOWN&& actor_y[i] <210) 
        actor_y[i] +=1 ;	//Moves player to the down until hits screen border
        
                
    }  
    
    //Drawing Player character Boat remains fixed to one side of screen
     if(invis == false){
       for (i=0; i<NUM_ACTORS; i++) {
	byte runseq = x & 7;
      if (actor_dx[i] >= 0)
        runseq += 8;
      oam_id = oam_meta_spr(actor_x[i], actor_y[i], oam_id, playerRunSeq[runseq]);
         //actor_x[0] += actor_dx[0];
    }
      }
    
    
    //Drawing Trash bag
    if(gas_can == true){
    for (i=0; i<NUM_ACTORS; i++) {
      
      int framecounter = 0;
      
      if (framecounter%60 == 0)
      oam_id = oam_meta_spr(gasCan_x[i], gasCan_y[i], oam_id, TrashSeq[0]);    
      else
	oam_id = oam_meta_spr(gasCan_x[i], gasCan_y[i], oam_id, TrashSeq[1]); 
      
      
      if (actor_dx[i] == 0)		//Gas can moves same speed as background
      gasCan_x[i] += gasCan_dx[i] - 2;

      else if (actor_dx[i] > 0)
      gasCan_x[i] += gasCan_dx[i] - 4;
      else
      gasCan_x[i] += gasCan_dx[i] - 1;
      
      framecounter++;
      
    }
    }
    
    
    //Drawing Crocodile
    for (i=0; i<NUM_ACTORS; i++) 
    {	    
      
      if (actor_dx[i] == 0)
      {
        oam_id = oam_meta_spr(cone_x, cone_y, oam_id, CrocSeq[1] );
        cone_x += cone_dx - 2;
      }
      else if (actor_dx[i] > 0)
      {
        oam_id = oam_meta_spr(cone_x, cone_y, oam_id, CrocSeq[2] );	//Crocodile opens mouth when player speeds up
        cone_x += cone_dx - 4;
      }
      else
      	{
        oam_id = oam_meta_spr(cone_x, cone_y, oam_id, CrocSeq[1] );
      	cone_x += cone_dx -1;     
    	}
    }
    
/*******************Drawing submarines*************************************************************************/
    for (i=0; i<NUM_ENEMIES; i++) {
      byte runseq = x & 7;      
      if (x != 0)
        runseq += 8;
      oam_id = oam_meta_spr(van_x[i], van_y[i], oam_id, VanRunSeq[runseq] );
      
      if (actor_dx[0] == 0)		
      van_x[i] += van_dx[i] - 1;
      else if (actor_dx[0] > 0)		
      van_x[i] += van_dx[i] - 3;  
      else
      van_x[i] += van_dx[i] + 1;	      	
      if(van_x[i] >= 254 && gas_can == false)
        points++;
    }
    
    
/*******************Submarine Collision detection******************************************************************************/ 
    if(aa == false){
    for (i=0; i<NUM_ENEMIES; i++){
    if(van_x[i] > (actor_x[0]) && van_x[i] < (actor_x[0] + 32) && van_y[i] < (actor_y[0] + 16) && van_y[i] > (actor_y[0])) {
      	sfx_play(1,1);	
      	delay(20);
        lives--;
        van_x[i] = 230;
      	van_y[i] = (rand() % (208 + 1 - 150)) + 150;
        hit = 75;
        aa = true;
      }
    }}
    
    
/******************** TRASH BAG COLLISION DETECTION AND INCREASE IN POINTS ******************************************************/
    if(gas_can == true){
    if(gasCan_x[0] > (actor_x[0]) && gasCan_x[0] < (actor_x[0] + 32) && gasCan_y[0] < (actor_y[0] + 16) && gasCan_y[0] > (actor_y[0])) {
      	gas_can = false;
      	//gasCan_x[0]=0;
      	sfx_play(0,2);  
      	totalBags = totalBags + 1;
      	points =0;
      }
    }
    
    
    
/******************** Crocodile COLLISION DETECTION AND INCREASE IN POINTS ******************************************************/
    if( (cone_x > (actor_x[0])) && (cone_x < (actor_x[0] + 26)) && (cone_y > actor_y[0]) && (cone_y < actor_y[0] + 6)){
      	sfx_play(1,1);
      	delay(20);
      	hit = 75;
        cone_x = 240;
      	cone_y = (rand() % (208 + 1 - 150)) + 150;
    	lives -= 1;
      }
    else if (cone_x >= 254)
    {
      cone_x = 240;
      cone_y = (rand() % (210 + 1 - 150)) + 150;
    }
    
    
    //Van and cone Spawning pattern
    for (i=0; i<NUM_ENEMIES; i++){
    if((van_x[i]) >= 254)
	van_y[i]= (rand() % (208 + 1 - 150)) + 150;
    }
    
    // wait for next frame
    ppu_wait_nmi();

    
/************* cOLLECT 5 TRASH BAGS TO WIN ***************************************************/
    if(totalBags == 1){
      cleared[2] = true;
      scroll(0,0);
    level_screen(level_select_pal,level_select_rle);
    } 
    
    x +=2;
    scroll(x, y);
    
    //Spawn the trash bag after 10 poitns are accumulated
    if(points == 10) gas_can = true;
    
    if (oam_id!=0) oam_hide_rest(oam_id);
    
    //INVISIBILITY FRAMES	
    if(hit > 0){ 
      hit--;
      if(invis == false)
        invis = true;
        else invis = false;
    }
    
    if(hit == 0){
      invis = false;
      aa = false;
    }
      
    if (oam_id!=0) oam_hide_rest(oam_id);
    
    //End game when lives run out PLACE HOLDER
    if (lives <= 0){
      scroll(0,0);
  	level_screen(level_select_pal,level_select_rle);
    }
    }
}

void river(){
  show_screen_scrolling(river_pal, river_rle,river_rle);
  scroll_background();
  

}