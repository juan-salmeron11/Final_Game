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


/*********************************************************/

extern const byte level_select_pal[16];
extern const byte level_select_rle[];

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
    oam_id = oam_spr(arrow_x, arrow_y, 0x1f, 0, oam_id);
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
    vram_adr(NTADR_A(11,14));
  vram_write("Lake Level", 10);
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