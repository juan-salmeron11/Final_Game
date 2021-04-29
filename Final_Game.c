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
//#link "city_back2.s"
//#link "fruit_background.s"
//#link "game_title.s"

extern const byte city_back1_pal[16];
extern const byte city_back1_rle[];
extern const byte city_back2_rle[];
extern const byte fruit_background_pal[16];
extern const byte fruit_background_rle[];
extern const byte title_rle[];
extern const byte title_pal[16];

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
//#link "forestSong.s"

extern char forestSong_music_data[];
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


/********************************* META SPRITES FOR FRUIT GAME***************************************************/


// define a 2x2 metasprite
#define DEF_METASPRITE_CHAR(name,code,pal)\
const unsigned char name[]={\
        0,      0,      (code)+0,   pal, \
        0,      8,      (code)+1,   pal, \
        8,      0,      (code)+2,   pal, \
        8,      8,      (code)+3,   pal, \
        128};

// define a 2x2 metasprite, flipped horizontally
#define DEF_METASPRITE_CHAR_FLIP(name,code,pal)\
const unsigned char name[]={\
        8,      0,      (code)+0,   (pal)|OAM_FLIP_H, \
        8,      8,      (code)+1,   (pal)|OAM_FLIP_H, \
        0,      0,      (code)+2,   (pal)|OAM_FLIP_H, \
        0,      8,      (code)+3,   (pal)|OAM_FLIP_H, \
        128};

//Metasprite for bear enemy
#define DEF_METASPRITE_B_2x2(name,code,pal)\
const unsigned char name[]={\
        0,      0,      (code)+0,   pal, \
        0,      8,      (code)+1,   pal, \
        8,      0,      (code)+2,   pal, \
        8,      8,      (code)+3,   pal, \
        128};

// define a 2x2 metasprite, flipped horizontally
#define DEF_METASPRITE_B_2x2_FLIP(name,code,pal)\
const unsigned char name[]={\
        8,      0,      (code)+0,   (pal)|OAM_FLIP_H, \
        8,      8,      (code)+1,   (pal)|OAM_FLIP_H, \
        0,      0,      (code)+2,   (pal)|OAM_FLIP_H, \
        0,      8,      (code)+3,   (pal)|OAM_FLIP_H, \
        128};




/*Metasprite for bird enemy***************************COPY HERE (A) ************************/

#define DEF_METASPRITE_C_2x2(name,code,pal)\
const unsigned char name[]={\
        0,      0,      (code)+0,   pal, \
        0,      8,      (code)+1,   pal, \
        8,      0,      (code)+2,   pal, \
        8,      8,      (code)+3,   pal, \
        128};




/********************************/



/******************** META SPRITES FOR MOUNTAIN GAME ************************************************************************/
// Metasprite for climbing character
#define DEF_METASPRITE_CLIMBER(name,code,pal)\
const unsigned char name[]={\
        0,      0,      (code)+0,   pal, \
        0,      8,      (code)+1,   pal, \
        8,      0,      (code)+2,   pal, \
        8,      8,      (code)+3,   pal, \
        128};

// Metasprite for climbing character flipped
#define DEF_METASPRITE_CLIMBER_FLIP(name,code,pal)\
const unsigned char name[]={\
        8,      0,      (code)+0,   (pal)|OAM_FLIP_H, \
        8,      8,      (code)+1,   (pal)|OAM_FLIP_H, \
        0,      0,      (code)+2,   (pal)|OAM_FLIP_H, \
        0,      8,      (code)+3,   (pal)|OAM_FLIP_H, \
        128};

//Metasprite for climber
DEF_METASPRITE_CLIMBER(playerClimb1, 0xa3 , 1);

//Flipped metasprite for climber
DEF_METASPRITE_CLIMBER_FLIP(playerClimb2, 0xa3 , 1);

//Animation sequence for climber

const unsigned char* const climbSeq[16] = {
  playerClimb1, playerClimb2, playerClimb1, 
  playerClimb1, playerClimb2, playerClimb1, 
  playerClimb1, playerClimb2,
  playerClimb1, playerClimb2, playerClimb1, 
  playerClimb1, playerClimb2, playerClimb1, 
  playerClimb1, playerClimb2,
};



//Metasprite for bear
DEF_METASPRITE_B_2x2(bearRStand, 0x83, 1);
DEF_METASPRITE_B_2x2(bearRRun1, 0x8b, 1);
DEF_METASPRITE_B_2x2(bearRRun2, 0x87, 1);
DEF_METASPRITE_B_2x2(bearRRun3, 0x83, 1);

//Flipped bear Metasprites
DEF_METASPRITE_B_2x2_FLIP(bearLStand, 0x83, 0);
DEF_METASPRITE_B_2x2_FLIP(bearLRun1, 0x8b, 0);
DEF_METASPRITE_B_2x2_FLIP(bearLRun2, 0x87, 0);
DEF_METASPRITE_B_2x2_FLIP(bearLRun3, 0x83, 0);



/****Metasprite for bird******************************COPY HERE (B) ************/

DEF_METASPRITE_C_2x2(birdStand, 0xa7, 3);
DEF_METASPRITE_C_2x2(birdFly1, 0xa7, 3);
DEF_METASPRITE_C_2x2(birdFly2, 0xab, 3);
DEF_METASPRITE_C_2x2(birdFly3, 0xaf, 3);

/*****************************************************COPY HERE (B) ************/




//Meta sprite for player 
DEF_METASPRITE_CHAR(layerRStand, 0x8f, 1);
DEF_METASPRITE_CHAR(layerRRun1, 0x93, 1);
DEF_METASPRITE_CHAR(layerRRun2, 0x97, 1);
DEF_METASPRITE_CHAR(layerRRun3, 0x9b, 1);

DEF_METASPRITE_CHAR_FLIP(layerLStand, 0x8f, 1);
DEF_METASPRITE_CHAR_FLIP(layerLRun1, 0x93, 1);
DEF_METASPRITE_CHAR_FLIP(layerLRun2, 0x97, 1);
DEF_METASPRITE_CHAR_FLIP(layerLRun3, 0x9b, 1);

//Bear movement sequence
const unsigned char* const bearRunSeq[16] = {
  bearLRun1, bearLRun2, bearLRun3, 
  bearLRun1, bearLRun2, bearLRun3, 
  bearLRun1, bearLRun2,
  bearRRun1, bearRRun2, bearRRun3, 
  bearRRun1, bearRRun2, bearRRun3, 
  bearRRun1, bearRRun2,
};




/*****Bird movement sequence********************************* COPY HERE (C) **********/
const unsigned char* const birdFlySeq[16] = {
  birdFly1, birdFly1, birdFly1, 
  birdFly1, birdFly1, birdFly2, 
  birdFly2, birdFly2,
  birdFly2, birdFly3, birdFly3, 
  birdFly3, birdFly3, birdFly2, 
  birdFly2, birdFly2,
};
/**************************************************************COPY HERE (C) ***********/



//Player movement sequence
const unsigned char* const layerRunSeq[16] = {
  layerLRun1, layerLRun2, layerLRun3, 
  layerLRun1, layerLRun2, layerLRun3, 
  layerLRun1, layerLRun2,
  layerRRun1, layerRRun2, layerRRun3, 
  layerRRun1, layerRRun2, layerRRun3, 
  layerRRun1, layerRRun2,
};


/*******************************/
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



///////fruit VARIABLES

// number of actors (1 per interactive Object)
#define NUM_ACTORS 1
#define NUM_FRUITS 5

// actor x/y positions and speed


// enemy BEAR actor
byte enemy_x;
byte enemy_y;
// actor x/y deltas per frame (signed)
sbyte enemy_dx;
sbyte enemy_dy;



/**** enemy BIRD actor****************************** COPY HERE (D) ************************/

byte enemyBird_x;
byte enemyBird_y;
sbyte enemyBird_dx;
sbyte enemyBird_dy;

/********************r****************************** COPY HERE (D) ************************/



typedef struct Fruit{
  bool falling;
  byte _x;		// fruit x/y position
  byte _y;		
  sbyte _dx;		// frui x/y deltas per frame (signed)
  sbyte _dy;
  int sprite;
  int points;
  
};

struct Fruit Fruits[4];


////////

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
bool cleared[3];
int score;

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
void forest(void);
void scroll_background(void);
void scroll_background_city(void);
void show_screen_scrolling(const byte* pal, const byte* rle,const byte* rle2);
void title(void);
void show_screen(const byte* pal, const byte* rle,const byte* rle2);
byte rndint(byte, byte);
void fruit_collision(int,);
void ending(void);





void main(void)
{
  for(j = 0;j<3;j++){
    cleared[j] = false;
  }
  
  //Play Menu Theme
  setup_graphics();
  title();
  famitone_init(menu_theme_music_data);
  nmi_set_callback(famitone_update);  
  
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
      if(cleared[0] ==true  && cleared[1] ==true  && cleared[2] ==true){
        vram_adr(NTADR_A(19,20));
        vram_write("        ", 8); 
        vram_adr(NTADR_A(19,21));
        vram_write(" ENDING  ", 9); 
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
  
  pad = pad_trigger(0);
  
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
    if (arrow_x == 25 && arrow_y ==70){
      music_stop();
      sfx_init(sfx_sounds);
      sfx_play(1,0);
      show_title_screen(0);
    
    }
    else if (arrow_x == 138 && arrow_y ==70){
      music_stop();
    sfx_init(sfx_sounds);
      sfx_play(1,0);
      show_title_screen(1);}
    else if (arrow_x == 25 && arrow_y ==165){
      music_stop();
      sfx_init(sfx_sounds);
      sfx_play(1,0);
      show_title_screen(2);}

      if(cleared[0] ==true  && cleared[1] ==true  && cleared[2] ==true){
        music_stop();
    	sfx_init(sfx_sounds);
      	sfx_play(1,0);
        show_title_screen(3);}
                       }
}


void show_title_screen(int x) {
  ppu_off();
  vram_adr(NAMETABLE_A);
  vram_fill(0,1024);
  oam_clear();
  if(x==0){
    vram_adr(NTADR_A(8,14));
    vram_write("REACH THE GOAL", 14);
    ppu_on_all();
    delay(100);
    city();

  }
  else if(x==1){
    vram_adr(NTADR_A(8,14));
    vram_write("SCORE 30 POINTS", 15);
    vram_adr(NTADR_A(7,15));
    vram_write("BY CATCHING FRUIT", 17);
    ppu_on_all();
    delay(100);
    forest();
  }
  else if(x==2){
    vram_adr(NTADR_A(6,14));
    vram_write("COLLECT 3 TRASH BAGS", 20);
    ppu_on_all();
    delay(100);
    river();
  }
  else if(x==3 && cleared[0] ==true  && cleared[1] ==true  && cleared[2] ==true){
    ending();
  }
  
  ppu_on_all();

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
      
      //Drawing hearts on screen
    for(i=0;i<lives;i++)
      oam_id = oam_spr(10+(i*10), 10, 23, 0, oam_id);
    
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
      

      
       oam_id = oam_meta_spr(bag_x[i], bag_y[i], oam_id, TrashSeq[1]); 
      
      
      if (boat_dx[i] == 0)		//BAG can moves same speed as background
      bag_x[i] += bag_dx[i] - 2;

      else if (boat_dx[i] > 0)
      bag_x[i] += bag_dx[i] - 4;
      else
      bag_x[i] += bag_dx[i] - 1;
      
      
      
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
    if(totalBags >= 3){
      cleared[2] = true;
      scroll(0,0);
      music_stop();
      delay(20);
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
      delay(29);
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
    if(p == 60){
      cleared[0] = true;
      scroll(0,0);
      music_stop();
    level_screen(level_select_pal,level_select_rle);
    } 
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
	{
      	scroll(0,0);
      	music_stop();
  	fuel = 1000;
  	progress,p = 0;
  	time = 1000;
  	level_screen(level_select_pal,level_select_rle);
    	}    
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


/********************* FOREST STAGE **************************************************************************/
char pad2;
bool faceLeft = false;

void forest(){
  sfx_init(demo_sounds);
  delay(60);
   show_screen_scrolling(fruit_background_pal, fruit_background_rle,fruit_background_rle);

  score =0;
  lives = 3;
  
  
  
  // Initialize actor fruits
  for(i=0;i<4;i++){		
    Fruits[i].falling = false;		//Controls when fruit falls
    Fruits[i]._x = rndint(20,230);	//X position
    Fruits[i]._y = rndint(15,70);	//Y position
    Fruits[i]._dy = 0;			//Falling Speed
    Fruits[i].sprite = i+0x29;		//Sprite used
    Fruits[i].points = i+1;		//Points added when collected
  }
  
  
//  famitone_init(effects);
//  sfx_init(effects);
//  nmi_set_callback(famitone_update);
  
  //Place the player in the middle of the screen
    actor_x[0] = 120;
    actor_y[0] = 191;
    actor_dx[0] = 0;
    actor_dy[0] = 0;
  
  
  //Bear enemy on the corner of the screen
    enemy_x = 0;
    enemy_y = 100;
    enemy_dx = 2;
    enemy_dy = 0;

/***************************************************** COPY HERE (E) *****************/
  //Bird enemy on Right corner of the screen 
    enemyBird_x = 250;
    enemyBird_y = 161;
    enemyBird_dx = -3;	//Delta values are placeholder, they need Sin(x) movement
    enemyBird_dy = 1;
  
/***************************************************** COPY HERE (E) *****************/

  
  // Initiate Game loop
  
  famitone_init(forestSong_music_data);
  // set music callback function for NMI
  nmi_set_callback(famitone_update);
  // play music
  music_play(0);
  
  while (1) {
    // start with OAMid/sprite 0
    oam_id = 0;
    
    // set player 0/1 velocity based on controller
    for (i=0; i<1; i++) {
      // poll controller i (0-1)
      pad2 = pad_trigger(i);
      pad = pad_poll(i);
      
      if (pad&PAD_LEFT && actor_x[i]>0){
        actor_dx[i]=-2;
      	faceLeft = true;
      }
   
      else if (pad&PAD_RIGHT && actor_x[i]<240){
        actor_dx[i]=2;	
        faceLeft = false;
      }
      else actor_dx[i]=0;					//Else horizontal acceleration = 0
      
      if (pad2 & PAD_A &&  actor_y[i] == 191)			//Prototype jumping
      { 
        sfx_play(4,0);
        actor_dy[i]=-2;
      }
            
      
    }
    //Fall after Jumping to certain height;
    if (actor_y[0] == 155)
        actor_dy[0] = 2;
    
    //Drawing Player character
    for (i=0; i<NUM_ACTORS; i++) {
      byte runseq = actor_x[i] & 7;
      if (actor_dx[0] >= 0)
        runseq += 8;
      
      if (faceLeft && actor_dx[0] == 0 && actor_y[i] == 191)
      oam_id = oam_meta_spr(actor_x[i], actor_y[i], oam_id, layerLRun2);
      else if (!faceLeft && actor_dx[0] == 0 && actor_y[i] == 191)
      oam_id = oam_meta_spr(actor_x[i], actor_y[i], oam_id, layerRRun2);
      
      else if (!faceLeft && actor_dx[0] != 0 && actor_y[i] < 191)
      oam_id = oam_meta_spr(actor_x[i], actor_y[i], oam_id, layerRRun3);
      
      else if (faceLeft && actor_dx[0] != 0 && actor_y[i] < 191)
      oam_id = oam_meta_spr(actor_x[i], actor_y[i], oam_id, layerLRun3);
      
      else if (faceLeft && actor_dx[0] == 0 && actor_y[i] < 191)
      oam_id = oam_meta_spr(actor_x[i], actor_y[i], oam_id, layerLRun3);
      
      else
      oam_id = oam_meta_spr(actor_x[i], actor_y[i], oam_id, layerRunSeq[runseq]);

      actor_x[i] += actor_dx[i];
      //Protoype for jumping
      if(actor_y[i] <= 191)
      actor_y[i] += actor_dy[i];

      
       //Set actor back on Plane after jumping if he falls too far
      if(actor_y[i] >= 191)
        actor_y[i] = 191;
     
    }
    
    //Drawing BEAR enemy
    if(score > 3){					
      enemy_y=191;
    for (i=0; i<1; i++) {
      byte runseq = enemy_x & 7;
      if (enemy_dx >= 0)
        runseq += 8;
      oam_id = oam_meta_spr(enemy_x, enemy_y, oam_id, bearRunSeq[runseq]);
      enemy_x += enemy_dx;
    }
    }
    
    
/***************************************************** COPY HERE (F) *****************/
    //Drawing BIRD enemy, after score is past 10pts
    
    if(score >= 10){
      
    for (i=0; i<1; i++) {
     
      
      byte runseq = enemyBird_x & 7; 
      if(enemyBird_y == 200)
        enemyBird_dy = -1;
      if(enemyBird_y == 150)
        enemyBird_dy = 1;
      if (enemyBird_dx >= 0)
        runseq += 8;
      oam_id = oam_meta_spr(enemyBird_x, enemyBird_y, oam_id, birdFlySeq[runseq]);
      enemyBird_x += enemyBird_dx + 1;
      enemyBird_y += enemyBird_dy;
      
      
    }
    }
/***************************************************** COPY HERE (F) *****************/
    
    
    
    //Draws and updates hearts for lives
    for(i=0;i<lives;i++)
      oam_id = oam_spr(10+(i*10), 10, 23, 0, oam_id);

    //Draws and updates Scoreboard
    oam_id = oam_spr(232, 10, (score/10%10)+48, 0, oam_id);
    oam_id = oam_spr(240, 10, (score%10)+48, 0, oam_id);
    
    for(i = 0; i<4; i++)
     if(Fruits[i].sprite==20)
     oam_id = oam_spr(Fruits[i]._x, Fruits[i]._y, Fruits[i].sprite, 2, oam_id);
    else
      oam_id = oam_spr(Fruits[i]._x, Fruits[i]._y, Fruits[i].sprite, 1, oam_id);
      

    for(i=0;i<4;i++){
      if(rndint(1,200)==1)		//Fruit Hangs on tree for random set of rime
        Fruits[i].falling = true;
      
      if(Fruits[i].falling)		//Set Fruit Fall speed 
      	Fruits[i]._dy = rndint(1,3);
        
      Fruits[i]._y += Fruits[i]._dy;	//Make Fruit Fall
      fruit_collision(i);		// Check Collsion with Player
    }	
    
    //Enemy bear collision
      if(enemy_y >= 210 || ((enemy_x >= actor_x[0]-4 && enemy_x <= actor_x[0]+8)&& (enemy_y >= actor_y[0]-2 && enemy_y <= actor_y[0]+4))){
       lives--;
       sfx_play(1,0);
       enemy_x = 0;
       delay(20);
      }
    

/***************************************************** COPY HERE (G) *****************/
    //Enemy Bird collision
      if(enemyBird_y >= 210 || ((enemyBird_x >= actor_x[0]-4 && enemyBird_x <= actor_x[0]+8)&& (enemyBird_y >= actor_y[0]-2 && enemyBird_y <= actor_y[0]+4))){
       lives--;
       sfx_play(1,0);
       enemyBird_x = 250;
        delay(20);
      }
    
/***************************************************** COPY HERE (G) *****************/    
    
    // hide rest of sprites
    // if we haven't wrapped oam_id around to 0
    if (oam_id!=0) oam_hide_rest(oam_id);
    // wait for next frame
    ppu_wait_frame();

    
    	//Win Conditions
      if (score >= 25){
        cleared[1] = true;
        delay(20);
  	level_screen(level_select_pal,level_select_rle);
      }
    
      //Lose Conditions
      if (lives == 0){
	delay(20);
  	level_screen(level_select_pal,level_select_rle);
    }
  }
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


/********************************************/
byte rndint(byte a, byte b){
  return (rand() % (b-a)) + a;
}
/*******************************************/


void fruit_collision(int f){
  if(Fruits[f]._y >= 210 || ((Fruits[f]._x >= actor_x[0]-4 && Fruits[f]._x <= actor_x[0]+8)&& (Fruits[f]._y >= actor_y[0]-2 && Fruits[f]._y <= actor_y[0]+4))) //hits floor or collision detected
      {
        if(Fruits[f]._y < 195){
          sfx_play(2,1);
          score += Fruits[f].points;
          Fruits[f]._y = 210;
        }
        Fruits[f].sprite=0; // erase fruit for a bit
      }
  
  if(Fruits[f].sprite == 0 && Fruits[f]._y <= 160 && Fruits[f]._y >= 130 ){// Make fruit reappear on random spot
       	Fruits[f]._x = rndint(20,230);
    	Fruits[f]._y = rndint(10,50);
        Fruits[f]._dy = 0;
    
    //set sprite before reappearing
    switch(f){
      case 0:
        Fruits[f].sprite=41;
        Fruits[f].falling=false;
        break;
      case 1:
        Fruits[f].sprite=42;
        Fruits[f].falling=false;
        break;
      case 2:
        Fruits[f].sprite=43;
        Fruits[f].falling=false;
        break;
      case 3:
        Fruits[f].sprite= 44;
        Fruits[f].falling=false;
        break;
      default:
        break;
 	}
  }
  

}

void title(){ 

  famitone_init(forestSong_music_data);
  nmi_set_callback(famitone_update);
  music_play(0);
  sfx_init(demo_sounds);
   show_screen(title_pal,title_rle,title_rle);
   while(1){
   

   pad = pad_trigger(i);
   if(pad & PAD_START)
   { 
     sfx_play(1,0); 
     ppu_off();
     ppu_wait_frame();
          delay(40);

     break;
    }
  
}
}


int x;




void ending(){ 
	famitone_init(forestSong_music_data);
  	nmi_set_callback(famitone_update); 
  	music_play(0);
  actor_x[0] = 0;
  actor_y[0] = 191;
  actor_dx[0] = 2;
  actor_dy[0] = 0; 
  
  ppu_off();
  // set palette, virtual bright to 0 (total black)
  pal_bg(fruit_background_pal);
  
  // unpack nametable into the VRAM
  vram_adr(0x2000);
  vram_unrle(fruit_background_rle);
          vram_adr(NTADR_A(10,8));
        vram_write(" CREATED BY  ", 13); 
        vram_adr(NTADR_A(10,9));
        vram_write("JUAN SALMERON", 13); 
        vram_adr(NTADR_A(10,10));
        vram_write("DAVID DE LEON", 13);
  // enable rendering
  ppu_on_all();
 
  

  while(actor_x[0] < 235){
    oam_id =0;
    for (i=0; i<NUM_ACTORS; i++) {
      byte runseq = actor_x[i] & 7;
	if (actor_dx[0] >= 0)
        runseq += 8;
      oam_id = oam_meta_spr(actor_x[i], actor_y[i], oam_id, layerRunSeq[runseq]);
        actor_x[0] += 1;
    }
    	ppu_wait_frame();
      	
    }
   

  actor_x[0] = 0;
  actor_y[0] = 191;
  actor_dx[0] = 2;
  actor_dy[0] = 0; 
  
  ppu_off();
  // set palette, virtual bright to 0 (total black)
  pal_bg(city_back1_pal);
  
  // unpack nametable into the VRAM
  vram_adr(0x2000);
  vram_unrle(city_back1_rle);
        vram_adr(NTADR_A(7,21));
        vram_write("SPECIAL THANKS TO", 17); 
        vram_adr(NTADR_A(5,22));
        vram_write("SENIOR PROJECT DISCORD", 22); 

  // enable rendering
  ppu_on_all();
  
    while(actor_x[0] < 235){
    oam_id =0;
    for (i=0; i<NUM_ACTORS; i++) {
      byte runseq = actor_x[i] & 7;
      if (actor_dx[i] >= 0)
        runseq += 8;
      oam_id = oam_meta_spr(actor_x[i], actor_y[i], oam_id, playerRunSeq[runseq]);
        actor_x[0] += actor_dx[0];
    }
    	ppu_wait_frame();
      	
    }
  
  actor_x[0] = 0;
  actor_y[0] = 191;
  actor_dx[0] = 2;
  actor_dy[0] = 0; 
  
  ppu_off();
  // set palette, virtual bright to 0 (total black)
  pal_bg(river_pal);
  
  // unpack nametable into the VRAM
  vram_adr(0x2000);
  vram_unrle(river_rle);
  vram_adr(NTADR_A(7,5));
  vram_write("THANKS FOR PLAYING", 18); 

  // enable rendering
  ppu_on_all();
  
    while(actor_x[0] < 240){
    oam_id =0;
    for (i=0; i<NUM_ACTORS; i++) {
      byte runseq = actor_x[i] & 7;
      if (actor_dx[i] >= 0)
        runseq += 8;
      	oam_id = oam_meta_spr(actor_x[i], actor_y[i], oam_id, boatRunSeq[runseq]);	
        actor_x[0] += actor_dx[0];
    }
    	ppu_wait_frame();
      	
    }
    
  ppu_off();
  delay(1000);
  music_stop();
}

