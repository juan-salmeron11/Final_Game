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
extern char menu_theme_music_data[];


/*********************************************************/

extern const byte level_select_pal[16];
extern const byte level_select_rle[];

char pad;	// controller flags
char i;
int arrow_x =25;
int arrow_y =70;

/*{pal:"nes",layout:"nes"}*/
const char PALETTE[32] = { 
  0x03,			// screen color

  0x11,0x30,0x27,0x0,	// background palette 0
  0x1c,0x20,0x2c,0x0,	// background palette 1
  0x00,0x10,0x20,0x0,	// background palette 2
  0x06,0x16,0x26,0x0,   // background palette 3

  0x16,0x35,0x24,0x0,	// sprite palette 0
  0x00,0x37,0x25,0x0,	// sprite palette 1
  0x0d,0x2d,0x3a,0x0,	// sprite palette 2
  0x0d,0x27,0x2a	// sprite palette 3
};

// setup PPU and tables
void setup_graphics() {
  // clear sprites
  oam_hide_rest(0);
  // set palette colors
  pal_all(PALETTE);
  // turn on PPU
  ppu_on_all();
}

void show_title_screen(const byte* pal, const byte* rle) {
  // disable rendering
  ppu_off();
  // set palette, virtual bright to 0 (total black)
  pal_bg(pal);
  // unpack nametable into the VRAM
  vram_adr(0x2000);
  vram_unrle(rle);
  // enable rendering
  ppu_on_all();
}

void menu_controls(){
  
  pad = pad_trigger(i);
  
  if (pad & PAD_DOWN && arrow_y == 70) {
      arrow_y = 165;           
    }
    
  if (pad & PAD_UP && arrow_y == 165) {
      arrow_y = 70;
    }
  
  if (pad & PAD_LEFT && arrow_x == 138) {
              arrow_x = 25;      
    }
    
  if (pad & PAD_RIGHT && arrow_x == 25) {
            arrow_x = 138;
    }
                   
}



void main(void)
{
  char oam_id;
  //Play Menu Theme
  famitone_init(menu_theme_music_data);
  nmi_set_callback(famitone_update);
  music_play(0);
  
  setup_graphics();
  show_title_screen(level_select_pal,level_select_rle);

  
  ppu_on_all();
  while(1) {
    menu_controls();
    oam_id = 0;
    oam_id = oam_spr(arrow_x, arrow_y, 0x1f, 0, oam_id);
  }
}
