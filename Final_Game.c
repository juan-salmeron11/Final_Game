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

//#link "city_back1.s"
//#link "city_game_over.s"
//#link "city_victory.s"
//#link "city_back2.s"

extern const byte city_back1_pal[16];
extern const byte city_back1_rle[];
extern const byte city_game_over_rle[];
extern const byte city_victory_rle[];
extern const byte city_back2_rle[];

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
//#link "boatSong.s"
//#link "music_dangerstreets.s"
extern char boatSong_music_data[];
extern char demo_sounds[];
extern char sfx_sounds[];
extern char menu_theme_music_data[];
extern char danger_streets_music_data[];
/**********************************************************/




/*********************************************************************************************************************/

		// 	META SPRITES  

/*********************************************************************************************************************/





/********************************* META SPRITES FOR MOTORCYCLE GAME***************************************************/
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

/********************************* META SPRITES FOR BOAT GAME***************************************************/

// define a 2x4 metasprite for the Boat Player
#define DEF_METASPRITE_BOAT(name,code,pal)\
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
// define a 2x4 metasprite for SUBMARINE ENEMY
#define DEF_METASPRITE_SUBMARINE(name,code,pal)\
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
//Meta Sprite for the TRASH BAG
#define DEF_METASPRITE_BAG(name, code, pal)\
const unsigned char name[]={\
        0,      0,      (code)+0,   pal, \
        0,      8,      (code)+1,   pal, \
        8,      0,      (code)+2,   pal, \
        8,      8,      (code)+3,   pal, \
        128};
//Meta Sprite for CROCODILE ENEMY
#define DEF_METASPRITE_CROC(name, code, pal)\
const unsigned char name[]={\
        0,      0,      (code)+0,   pal, \
        0,      8,      (code)+1,   pal, \
        8,      0,      (code)+2,   pal, \
        8,      8,      (code)+3,   pal, \
        128};


/**********************************METASPRITE ANIMATION SEQUENCES **********************************************************************/



/********************************** MOTORCYCLE METASPRITE ANIMATION SEQUENCES **********************************************************************/


//Meta Sprite for driving animation
DEF_METASPRITE_2x2(playerRRun1, 0x6b, 1);
DEF_METASPRITE_2x2(playerRRun2, 0x73, 1);


//Meta sprite for Driving animation of Van vehicle
DEF_METASPRITE_VAN(vanMove1, 0x5b, 1);
DEF_METASPRITE_VAN(vanMove2, 0x63, 1);

//Meta Sprite for Gas Can
DEF_METASPRITE_GAS(gasCan, 0x7f , 1);

//Meta Sprite for Cone
DEF_METASPRITE_CONE(cone, 0x7b , 1);

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




/***************************** BOAT GAME ANIMATIONS *************************************************************************/

//Boat Movement Sequence
//Meta Sprites for Driving animation of boat
DEF_METASPRITE_BOAT(boatRRun1, 0xcc, 1);
DEF_METASPRITE_BOAT(boatRRun2, 0xec, 1);

//Meta sprite for Driving animation of submarine
DEF_METASPRITE_SUBMARINE(subMove1, 0xc4, 2);		
DEF_METASPRITE_SUBMARINE(subMove2, 0xe4, 2);		

//Meta Sprite for Trash Bag
DEF_METASPRITE_BAG(trashMove1, 0xd4 , 1);
DEF_METASPRITE_BAG(trashMove2, 0xd8 , 1);

//Meta Sprite for Croc
DEF_METASPRITE_CROC(crocMove1, 0xdc , 3);
DEF_METASPRITE_CROC(crocMove2, 0xe0 , 3);

const unsigned char* const boatRunSeq[16] = {
  boatRRun1, boatRRun2, boatRRun1, 
  boatRRun1, boatRRun2, boatRRun1, 
  boatRRun1, boatRRun2,
  boatRRun1, boatRRun2, boatRRun1, 
  boatRRun1, boatRRun2, boatRRun1, 
  boatRRun1, boatRRun2,
};

//VAN Movement Sequence
const unsigned char* const submarineRunSeq[16] = {
  subMove1, subMove2, subMove1, 
  subMove1, subMove2, subMove1, 
  subMove1, subMove2,
  subMove1, subMove2, subMove1, 
  subMove1, subMove2, subMove1, 
  subMove1, subMove2,
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

//Trash Bag Movement Sequence
const unsigned char* const TrashSeq[16] = {
  trashMove1, trashMove2, trashMove1, 
  trashMove1, trashMove2, trashMove1, 
  trashMove1, trashMove2,
  trashMove1, trashMove2, trashMove1, 
  trashMove1, trashMove2, trashMove1, 
  trashMove1, trashMove2,
};



/********************************* END OF META SPRITES AND ANIMATIONS ************************************************************/

#define NUM_ACTORS 1
#define NUM_ENEMIES 3


/********************************* BIKE GAME DECLARATIONS ****************************/
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



/********************************* BOAT GAME DECLARATIONS ****************************/

// Boat player declaration
byte boat_x[NUM_ACTORS];
byte boat_y[NUM_ACTORS];
sbyte boat_dx[NUM_ACTORS];
sbyte boat_dy[NUM_ACTORS];

//Trash bag declaration
byte bag_x[NUM_ACTORS];
byte bag_y[NUM_ACTORS];
sbyte bag_dx[NUM_ACTORS];
sbyte bag_dy[NUM_ACTORS];


//Submarine vehicle declaration
byte sub_x[NUM_ENEMIES];
byte sub_y[NUM_ENEMIES];
sbyte sub_dx[NUM_ENEMIES];
sbyte sub_dy[NUM_ENEMIES];


//Crocodile declaration
byte croc_x;
byte croc_y;
sbyte croc_dx = -1;
sbyte croc_dy;





//Boat has 3 lives
int lives = 3;
//When number of trash bags collected is 5, you win
int totalBags = 0;
int hit = 0;
bool invis = false;
bool gas_can = false;
bool trash_bag = false;
int points=0;
bool aa = false;


//Motorcycle game global vars
  int fuel = 1000;
  int progress,p = 0;
  int time = 1000;

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

  0x0A,0x28,0x16,0x00,	// sprite palette 0
  0x0f,0x20,0x16,0x00,	// sprite palette 1 
  0x28,0x30,0x21,0x00,	// sprite palette 2 
  0x19,0x30,0x2F	// sprite palette 3
};

// setup PPU and tables
void setup_graphics(void);
void show_title_screen(int x);
void level_screen(const byte* pal, const byte* rle);
void menu_controls(void);
void river(void);
void city(void);
void scroll_background(void);
void scroll_background_city(void);
void show_screen_scrolling(const byte* pal, const byte* rle,const byte* rle2);


void show_game_over(const byte* pal, const byte* rle);
void show_victory(const byte* pal, const byte* rle);
void show_screen(const byte* pal, const byte* rle,const byte* rle2);




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
  famitone_init(menu_theme_music_data);
  nmi_set_callback(famitone_update);
  
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
  music_play(0);
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
    	//vram_adr(NTADR_A(11,14));
  	//vram_write("City Level", 10);
    	city();

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



/********* BOAT GAME *******************************************************************************************/
void scroll_background() {
  int x = 0;   // x scroll position
  int y = 0;   // y scroll position
  int dx = 0;  // y scroll direction
  int lives = 3;
  
  char i;	// actor index
  char oam_id;	// sprite ID
  char pad;	// controller flags
  
  //Place the player in the left fourth of the screen  
  boat_x[0] = 40;
  boat_y[0] = 191;
  boat_dx[0] = 0;
  boat_dy[0] = 0; 
  
    
  //Placeholder for Trash bag
  bag_x[0] = 0;	//Appear from rightmost part of screen
  bag_y[0] = 180;
  bag_dx[0] = 0;
  bag_dy[0] = 0;
  
  //Submarine vehicle placement
  for (i = 0; i < NUM_ENEMIES; i++)
  {
  sub_x[i] = (rand() % (254 + 1 - 150)) + 150;
  sub_y[i] = (rand() % (210 + 1 - 150)) + 150;	//Vans spawn randomly within street range
  sub_dx[i] = 0;
  sub_dy[i] = 0;
    
  }
  
  //Crocodile placement and speed
  croc_x = (rand() % (254 + 1 - 200)) + 200;
  croc_y = (rand() % (210 + 1 - 150)) + 150;
  croc_dx = 0;
  croc_dy = 0;
  
  // infinite loop
  while (1) {
  
      oam_id = 0;
    
    // set player 0/1 velocity based on controller
    for (i=0; i<1; i++) {
      // poll controller i (0-1)
      pad = pad_poll(i);
      
      if (pad&PAD_LEFT && boat_x[i]>10) {
        x-=1;			//Slows down the Background Scrolling
        boat_dx[i] = -1;
      }
      else if (pad&PAD_RIGHT && boat_x[i]<220) {
        x+=2;           	//Speeds up background scrolling
        boat_dx[i] = 1;	//Speed up bike until hits the screen
      }
      
      else{
              boat_dx[i]=0;
              dx =0;
            }
      if (pad&PAD_UP && boat_y[i] > 150)
        boat_y[i] -=1 ;	//Moves player to the up until hits sidewalk
      else if (pad&PAD_DOWN&& boat_y[i] <210) 
        boat_y[i] +=1 ;	//Moves player to the down until hits screen border
        
                
    }  
    
    //Drawing Player character Boat remains fixed to one side of screen
     if(invis == false){
       for (i=0; i<NUM_ACTORS; i++) {
	byte runseq = x & 7;
      if (boat_dx[i] >= 0)
        runseq += 8;
      oam_id = oam_meta_spr(boat_x[i], boat_y[i], oam_id, boatRunSeq[runseq]);	
         //actor_x[0] += actor_dx[0];
    }
      }
    
    
    //Drawing Trash bag
    if(trash_bag == true){						
    for (i=0; i<NUM_ACTORS; i++) {
      
      int framecounter = 0;
      
      if (framecounter%60 == 0)
      oam_id = oam_meta_spr(bag_x[i], bag_y[i], oam_id, TrashSeq[0]);    
      else
	oam_id = oam_meta_spr(bag_x[i], bag_y[i], oam_id, TrashSeq[1]); 
      
      
      if (boat_dx[i] == 0)		//BAG can moves same speed as background
      bag_x[i] += bag_dx[i] - 2;

      else if (boat_dx[i] > 0)
      bag_x[i] += bag_dx[i] - 4;
      else
      bag_x[i] += bag_dx[i] - 1;
      
      framecounter++;
      
    }
    }
    
    
    //Drawing Crocodile
    for (i=0; i<NUM_ACTORS; i++) 
    {	    
      
      if (boat_dx[i] == 0)
      {
        oam_id = oam_meta_spr(croc_x, croc_y, oam_id, CrocSeq[1] );
        croc_x += croc_dx - 2;
      }
      else if (boat_dx[i] > 0)
      {
        oam_id = oam_meta_spr(croc_x, croc_y, oam_id, CrocSeq[2] );	//Crocodile opens mouth when player speeds up
        croc_x += croc_dx - 4;
      }
      else
      	{
        oam_id = oam_meta_spr(croc_x, croc_y, oam_id, CrocSeq[1] );
      	croc_x += croc_dx -1;     
    	}
    }
    
/*******************Drawing submarines*************************************************************************/
    for (i=0; i<NUM_ENEMIES; i++) {
      byte runseq = x & 7;      
      if (x != 0)
        runseq += 8;
      oam_id = oam_meta_spr(sub_x[i], sub_y[i], oam_id, submarineRunSeq[runseq] );
      
      if (boat_dx[0] == 0)		
      sub_x[i] += sub_dx[i] - 1;
      else if (boat_dx[0] > 0)		
      sub_x[i] += sub_dx[i] - 3;  
      else
      sub_x[i] += sub_dx[i] + 1;	      	
      if(sub_x[i] >= 254 && trash_bag == false)				
        points++;
    }
    
    
/*******************Submarine Collision detection******************************************************************************/ 
    if(aa == false){
    for (i=0; i<NUM_ENEMIES; i++){
    if(sub_x[i] > (boat_x[0]) && sub_x[i] < (boat_x[0] + 32) && sub_y[i] < (boat_y[0] + 16) && sub_y[i] > (boat_y[0])) {
      	sfx_play(1,1);	
      	delay(20);
        lives--;
        sub_x[i] = 230;
      	sub_y[i] = (rand() % (208 + 1 - 150)) + 150;
        hit = 75;
        aa = true;
      }
    }}
    
    
/******************** TRASH BAG COLLISION DETECTION AND INCREASE IN POINTS ******************************************************/
    if(trash_bag == true){
    if(bag_x[0] > (boat_x[0]) && bag_x[0] < (boat_x[0] + 32) && bag_y[0] < (boat_y[0] + 16) && bag_y[0] > (boat_y[0])) {
      	trash_bag = false;
      	//gasCan_x[0]=0;
      	sfx_play(0,2);  
      	totalBags = totalBags + 1;
      	points =0;
      }
    }
    
    
    
/******************** Crocodile COLLISION DETECTION AND INCREASE IN POINTS ******************************************************/
    if( (croc_x > (boat_x[0])) && (croc_x < (boat_x[0] + 26)) && (croc_y > boat_y[0]) && (croc_y < boat_y[0] + 6)){
      	sfx_play(1,1);
      	delay(20);
      	hit = 75;
        croc_x = 240;
      	croc_y = (rand() % (208 + 1 - 150)) + 150;
    	lives -= 1;
      }
    else if (croc_x >= 254)
    {
      croc_x = 240;
      croc_y = (rand() % (210 + 1 - 150)) + 150;
    }
    
    
    //Submarine and Crocodile Spawning pattern
    for (i=0; i<NUM_ENEMIES; i++){
    if((sub_x[i]) >= 254)
	sub_y[i]= (rand() % (208 + 1 - 150)) + 150;
    }
    
    // wait for next frame
    ppu_wait_nmi();

    
/************* cOLLECT 5 TRASH BAGS TO WIN ***************************************************/
    if(totalBags == 1){
      cleared[2] = true;
      scroll(0,0);
      music_stop();
    level_screen(level_select_pal,level_select_rle);
    } 
    
    x +=2;
    scroll(x, y);
    
    //Spawn the trash bag after 10 poitns are accumulated
    if(points == 10) trash_bag = true;
    
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
      music_stop();
  	level_screen(level_select_pal,level_select_rle);
    }
    }
}








/********* BIKE GAME *******************************************************************************************/
void scroll_background_city() {
  int x = 0;   // x scroll position
  int y = 0;   // y scroll position
  int dx = 0;  // y scroll direction
  int lives = 3;
  



  char i;	// actor index
  char oam_id;	// sprite ID
  char pad;	// controller flags
  
  //Place the player in the left fourth of the screen  
  actor_x[0] = 60;
  actor_y[0] = 191;
  actor_dx[0] = 0;
  actor_dy[0] = 0; 
  
    
  //Placeholder for GasCan
  gasCan_x[0] = 0;	//Appear from rightmost part of screen
  gasCan_y[0] = 180;
  gasCan_dx[0] = 0;
  gasCan_dy[0] = 0;
  
  //Van vehicle placement
  for (i = 0; i < NUM_ENEMIES; i++)
  {
  van_x[i] = (rand() % (254 + 1 - 150)) + 150;
  van_y[i] = (rand() % (210 + 1 - 150)) + 150;	//Vans spawn randomly within street range
  van_dx[i] = 0;
  van_dy[i] = 0;
    
  }
  
  //Cone placement and speed
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
    //Drawing Player character
     if(invis == false){
       for (i=0; i<NUM_ACTORS; i++) {
	byte runseq = x & 7;
      if (actor_dx[i] >= 0)
        runseq += 8;
      oam_id = oam_meta_spr(actor_x[i], actor_y[i], oam_id, playerRunSeq[runseq]);
         actor_x[0] += actor_dx[0];
    }
      }
    
    
    //Drawing Gas can IDEA: spawn gas can in a random y coordinate within the street range
    if(gas_can == true){
    for (i=0; i<NUM_ACTORS; i++) {
      

      oam_id = oam_meta_spr(gasCan_x[i], gasCan_y[i], oam_id, gasCan);    
      
      if (actor_dx[i] == 0)		//Gas can moves same speed as background
      gasCan_x[i] += gasCan_dx[i] - 2;

      else if (actor_dx[i] > 0)
      gasCan_x[i] += gasCan_dx[i] - 4;
      else
      gasCan_x[i] += gasCan_dx[i] - 1;
      
    }
    }
    
    
    //Drawing Cones
    for (i=0; i<NUM_ACTORS; i++) 
    {
      oam_id = oam_meta_spr(cone_x, cone_y, oam_id, cone );      
      
      if (actor_dx[i] == 0)		
        cone_x += cone_dx - 2;

      else if (actor_dx[i] > 0)
        cone_x += cone_dx - 4;

      else
      cone_x += cone_dx -1;     
    }
    
    //Drawing Van enemy
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
    
    
    //VAN Collision detection 
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
      fuel -= 50;
      }
    }}
    
    //Gas Can Collision detection and place holder for where can goes after collision
    if(gas_can == true){
    if(gasCan_x[0] > (actor_x[0]) && gasCan_x[0] < (actor_x[0] + 32) && gasCan_y[0] < (actor_y[0] + 16) && gasCan_y[0] > (actor_y[0])) {
      	gas_can = false;
      //	gasCan_x[0] = -10;	//Change these later
      //	gasCan_y[0] = -10;	//Change these later
      	fuel = 1000;
      	points = 0;
      	sfx_play(0,2);
      }
    }
    //Cone Collision detection 
    if( (cone_x > (actor_x[0])) && (cone_x < (actor_x[0] + 26)) && (cone_y > actor_y[0]) && (cone_y < actor_y[0] + 6)){
      	sfx_play(1,1);
      	delay(20);
        lives--;
      	hit = 75;
        cone_x = 240;
      	cone_y = (rand() % (208 + 1 - 150)) + 150;
    	fuel -= 50;
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
    // update y variable
    //x += dx;
    
    for(i=0;i<fuel/100;i++){
      int s = 2;
        if (fuel < 600 & fuel > 300) s = 1;
      else if (fuel <= 300) s = 3;
    oam_id = oam_spr(10+(i*8), 10, s, 0, oam_id);
      
    }
    if(progress %300 ==0) p+=5;
    if(p == 60)show_victory(city_back1_pal, city_victory_rle);
    oam_id = oam_spr(100+ p, 10, 26, 2, oam_id);// change this sprite to an icon
    oam_id = oam_spr(160, 10, 25, 1, oam_id);
    
    x +=2;
    scroll(x, y);
    fuel -=1;
    time -=1;
    progress +=1;
    
    if(points == 10) gas_can = true;
    
    if (oam_id!=0) oam_hide_rest(oam_id);
    
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
    if (fuel == 0)
      show_game_over(city_back1_pal, city_game_over_rle);
    }
}


/**********************************RIVER STAGE*******************************************************************/
void river(){
  delay(60);
  sfx_init(demo_sounds);
  famitone_init(boatSong_music_data);
  nmi_set_callback(famitone_update);
  music_play(0);

  show_screen_scrolling(river_pal, river_rle,river_rle);
  scroll_background();
  
}

/**************************** CITY STAGE ***********************************************************************/
void city(){
  delay(60);
  sfx_init(demo_sounds);
  famitone_init(danger_streets_music_data);
  nmi_set_callback(famitone_update);
  music_play(0);

  show_screen_scrolling(river_pal, city_back1_rle,city_back1_rle);
  scroll_background_city();
  
}


void show_game_over(const byte* pal, const byte* rle){
  int x = 0;   // x scroll position
  char i;	// actor index
  char oam_id;	// sprite ID
  char pad;	// controller flags
  
  music_stop();
  
  fuel = 1000;
  progress,p = 0;
  time = 1000;
  hit = 0;
  invis = false;
  gas_can = false;
  points=0;
  aa = false;
  
  
  
  //Place the player in the left fourth of the screen  
  actor_x[0] = 125;
  actor_y[0] = 160;
  actor_dx[0] = 2;
  actor_dy[0] = 0; 
  
  setup_graphics();
  ppu_off();
  // set palette, virtual bright to 0 (total black)
  pal_bg(pal);
  scroll(0, 0);
  // unpack nametable into the VRAM
  vram_adr(0x2000);
  vram_unrle(rle);
  // enable rendering
  ppu_on_all();

  while(1){          
   pad = pad_trigger(0);
   if(pad & PAD_RIGHT){
     	sfx_play(2,1);
   	actor_x[0]=125;
   }
   if(pad & PAD_LEFT){
   	actor_x[0]=45;
     	sfx_play(2,1);
   }
   if(pad & PAD_START){
     if(actor_x[0] == 45){
       sfx_play(0,0);
       music_play(0);
       show_screen(city_back1_pal, city_back1_rle,city_back1_rle);
       scroll_background();     
   }
   
     else
     {
       	main();    
     	sfx_play(0,0);
     }
     
   }
    
    oam_id =0;
      for (i=0; i<NUM_ACTORS; i++) {
        byte runseq = x & 7;
      if (actor_dx[i] >= 0)
        runseq += 8;
        oam_id = oam_meta_spr(actor_x[i], actor_y[i], oam_id, playerRunSeq[runseq]);
     
    }
          
  }

  
}


void show_victory(const byte* pal, const byte* rle){
  setup_graphics();
  ppu_off();
  // set palette, virtual bright to 0 (total black)
  pal_bg(pal);
  scroll(0, 0);
  // unpack nametable into the VRAM
  vram_adr(0x2000);
  vram_unrle(rle);
  // enable rendering
  ppu_on_all();

  while(1){}
}



void show_screen(const byte* pal, const byte* rle,const byte* rle2) {
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