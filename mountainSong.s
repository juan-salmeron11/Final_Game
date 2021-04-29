FT_DPCM_PTR=$c000
	.export _mountainsong_music_data
_mountainsong_music_data:
	.byte 1
	.word @instruments
	.word @samples-3
	.word @song0ch0,@song0ch1,@song0ch2,@song0ch3,@song0ch4,307,256



@instruments:
	.byte $30 ;instrument 00 (Duty 0)
	.word @env1, @env0, @env0
	.byte $00
	.byte $70 ;instrument 01 (Duty 1)
	.word @env1, @env0, @env0
	.byte $00

@samples:
	.byte $00+.lobyte(FT_DPCM_PTR),$14,$0f	;1 (Sample 1)
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;2 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;3 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;4 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;5 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;6 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;7 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;8 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;9 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;10 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;11 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;12 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;13 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;14 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;15 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;16 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;17 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;18 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;19 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;20 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;21 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;22 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;23 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;24 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;25 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;26 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;27 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;28 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;29 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;30 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;31 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;32 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;33 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;34 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;35 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;36 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;37 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;38 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;39 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;40 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;41 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;42 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;43 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;44 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;45 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;46 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;47 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;48 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;49 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;50 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;51 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;52 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;53 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;54 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;55 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;56 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;57 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;58 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;59 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;60 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;61 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;62 
	.byte $00+.lobyte(FT_DPCM_PTR),$00,$00	;63 

@env0:
	.byte $c0,$7f,$00,$00
@env1:
	.byte $cf,$7f,$00,$00

@song0ch0:
	.byte $fb, $01
@song0ch0loop:
@ref0:
	.byte $82,$32,$f9,$d5,$00,$a7,$32,$81
@ref1:
	.byte $97,$2e,$99,$32,$99,$38,$99,$32,$99,$40,$99,$4a,$d9
@ref2:
	.byte $e7,$00,$99,$4e,$99,$50,$8b,$4e,$8b,$4a,$8b,$00,$8b,$46,$99,$4a,$89
@ref3:
	.byte $f9,$85,$32,$f9,$83
@ref4:
	.byte $d1,$00,$a7,$32,$99,$2e,$99,$32,$99,$38,$99,$32,$91
@ref5:
	.byte $87,$40,$99,$4a,$f9,$c7,$00,$95
@ref6:
	.byte $83,$4e,$99,$50,$8b,$4e,$8b,$4a,$8b,$00,$8b,$54,$99,$4a,$d1,$32,$8b,$38,$8b,$40,$8b,$46,$8b
@ref7:
	.byte $4a,$df,$00,$8b,$4a,$99,$4e,$99,$50,$8b,$4e,$8b,$4a,$99,$58,$9d
@ref8:
	.byte $cf,$5e,$ed,$5c,$a7,$5e,$93
@ref9:
	.byte $93,$62,$b5,$5e,$99,$5c,$8b,$5e,$8b,$5c,$8b,$54,$8b,$58,$dd
@ref10:
	.byte $b9,$00,$8b,$58,$8b,$54,$8b,$50,$8b,$4e,$8b,$4a,$a7,$48,$a7,$4a,$a9
@ref11:
	.byte $8b,$48,$99,$4a,$99,$4e,$99,$50,$ed,$54,$ad
@ref12:
	.byte $87,$4a,$8b,$54,$8b,$58,$8b,$62,$8b,$66,$f9,$ab,$68,$8b,$00,$87
@ref13:
	.byte $83,$66,$f9,$b9,$00,$8b,$32,$8b,$38,$8b,$40,$8b,$46,$8b
	.byte $ff,$10
	.word @ref7
@ref14:
	.byte $cf,$62,$ed,$5e,$a7,$5c,$93
@ref15:
	.byte $93,$5e,$b5,$62,$99,$5c,$8b,$5e,$8b,$5c,$8b,$54,$8b,$58,$dd
	.byte $ff,$11
	.word @ref10
	.byte $ff,$0b
	.word @ref11
@ref16:
	.byte $87,$4a,$8b,$54,$8b,$58,$8b,$62,$8b,$66,$f9,$c3
@ref17:
	.byte $f9,$a3,$00,$a7,$50,$8b,$4e,$8b,$4a,$8b,$00,$8b
@ref18:
	.byte $54,$99,$4a,$f9,$8f,$32,$8b,$38,$8b,$40,$8b,$46,$8b,$4a,$9d
@ref19:
	.byte $f9,$f9,$8b
@ref20:
	.byte $e7,$00,$f9,$9b
@ref21:
	.byte $c7,$50,$8b,$4e,$8b,$4a,$8b,$00,$8b,$54,$99,$4a,$e1
@ref22:
	.byte $a7,$32,$8b,$38,$8b,$40,$8b,$46,$8b,$4a,$f9,$a3
@ref23:
	.byte $f9,$df,$00,$a3
@ref24:
	.byte $f9,$95,$40,$ed
@ref25:
	.byte $32,$f9,$d5,$00,$a7,$32,$81
	.byte $ff,$0d
	.word @ref1
	.byte $ff,$11
	.word @ref2
	.byte $ff,$05
	.word @ref3
	.byte $ff,$0d
	.word @ref4
	.byte $ff,$08
	.word @ref5
	.byte $ff,$17
	.word @ref6
	.byte $ff,$10
	.word @ref7
	.byte $ff,$07
	.word @ref8
	.byte $ff,$0f
	.word @ref9
	.byte $ff,$11
	.word @ref10
	.byte $ff,$0b
	.word @ref11
	.byte $ff,$10
	.word @ref12
	.byte $ff,$0e
	.word @ref13
	.byte $ff,$10
	.word @ref7
	.byte $ff,$07
	.word @ref14
	.byte $ff,$0f
	.word @ref15
	.byte $ff,$11
	.word @ref10
	.byte $ff,$0b
	.word @ref11
	.byte $ff,$0c
	.word @ref16
	.byte $ff,$0c
	.word @ref17
	.byte $ff,$0f
	.word @ref18
@ref26:
	.byte $f9,$f9,$8b
@ref27:
	.byte $e7,$00,$f9,$9b
	.byte $ff,$0d
	.word @ref21
	.byte $ff,$0c
	.word @ref22
@ref28:
	.byte $f9,$df,$00,$a3
@ref29:
	.byte $f9,$95,$40,$ed
@ref30:
	.byte $32,$f9,$f9,$89
@ref31:
	.byte $f9,$f9,$8b
	.byte $fd
	.word @song0ch0loop

@song0ch1:
@song0ch1loop:
@ref32:
	.byte $82,$32,$f9,$e3,$2e,$9d
@ref33:
	.byte $f9,$c5,$2c,$bd
@ref34:
	.byte $f9,$a5,$2a,$dd
	.byte $ff,$05
	.word @ref3
@ref35:
	.byte $df,$2e,$f9,$a3
@ref36:
	.byte $bf,$2c,$f9,$c3
@ref37:
	.byte $9f,$2a,$f9,$e3
@ref38:
	.byte $8d,$4a,$f9,$8f,$4e,$99,$50,$8b,$4e,$8b,$4a,$99,$58,$8f
@ref39:
	.byte $dd,$5e,$ed,$5c,$a7,$5e,$85
@ref40:
	.byte $a1,$62,$b5,$5e,$99,$5c,$8b,$5e,$8b,$5c,$8b,$54,$8b,$58,$cf
@ref41:
	.byte $c7,$50,$8b,$4e,$8b,$4a,$8b,$46,$8b,$42,$a7,$40,$a7,$42,$a9
@ref42:
	.byte $8b,$40,$99,$42,$99,$46,$99,$4a,$ed,$4e,$ad
@ref43:
	.byte $95,$4a,$8b,$54,$8b,$58,$8b,$62,$8b,$66,$f9,$ab,$68,$87
@ref44:
	.byte $83,$00,$8b,$66,$f9,$c7,$32,$8b,$38,$8b,$40,$8b
@ref45:
	.byte $46,$8b,$4a,$df,$00,$8b,$4a,$99,$4e,$99,$50,$8b,$4e,$8b,$4a,$99,$58,$8f
@ref46:
	.byte $dd,$62,$ed,$5e,$a7,$5c,$85
@ref47:
	.byte $a1,$5e,$b5,$62,$99,$5c,$8b,$5e,$8b,$5c,$8b,$54,$8b,$58,$cf
	.byte $ff,$0f
	.word @ref41
	.byte $ff,$0b
	.word @ref42
@ref48:
	.byte $95,$4a,$8b,$54,$8b,$58,$8b,$62,$8b,$66,$f9,$b5
@ref49:
	.byte $f9,$b1,$00,$a7,$50,$8b,$4e,$8b,$4a,$8b
@ref50:
	.byte $00,$8b,$54,$99,$4a,$f9,$8f,$32,$8b,$38,$8b,$40,$8b,$46,$8b,$4a,$8f
@ref51:
	.byte $f9,$f9,$8b
@ref52:
	.byte $e7,$00,$f9,$9b
@ref53:
	.byte $d5,$50,$8b,$4e,$8b,$4a,$8b,$00,$8b,$54,$99,$4a,$d3
@ref54:
	.byte $b5,$32,$8b,$38,$8b,$40,$8b,$46,$8b,$4a,$f9,$95
@ref55:
	.byte $f9,$df,$00,$a3
@ref56:
	.byte $f9,$95,$36,$ed
@ref57:
	.byte $32,$f9,$e3,$2e,$9d
@ref58:
	.byte $f9,$c5,$2c,$bd
@ref59:
	.byte $f9,$a5,$2a,$dd
	.byte $ff,$05
	.word @ref3
@ref60:
	.byte $df,$2e,$f9,$a3
@ref61:
	.byte $bf,$2c,$f9,$c3
@ref62:
	.byte $9f,$2a,$f9,$e3
	.byte $ff,$0e
	.word @ref38
	.byte $ff,$07
	.word @ref39
	.byte $ff,$0f
	.word @ref40
	.byte $ff,$0f
	.word @ref41
	.byte $ff,$0b
	.word @ref42
	.byte $ff,$0e
	.word @ref43
	.byte $ff,$0c
	.word @ref44
	.byte $ff,$12
	.word @ref45
	.byte $ff,$07
	.word @ref46
	.byte $ff,$0f
	.word @ref47
	.byte $ff,$0f
	.word @ref41
	.byte $ff,$0b
	.word @ref42
	.byte $ff,$0c
	.word @ref48
	.byte $ff,$0a
	.word @ref49
	.byte $ff,$11
	.word @ref50
@ref63:
	.byte $f9,$f9,$8b
@ref64:
	.byte $e7,$00,$f9,$9b
	.byte $ff,$0d
	.word @ref53
	.byte $ff,$0c
	.word @ref54
@ref65:
	.byte $f9,$df,$00,$a3
@ref66:
	.byte $f9,$95,$36,$ed
@ref67:
	.byte $32,$f9,$f9,$89
@ref68:
	.byte $f9,$f9,$8b
	.byte $fd
	.word @song0ch1loop

@song0ch2:
@song0ch2loop:
@ref69:
	.byte $80,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$4a,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$28,$89,$00,$2e,$89,$00,$32,$89,$00,$32,$89,$00,$4a,$81
@ref70:
	.byte $87,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$4a,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$28,$89,$00,$2e,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$85
@ref71:
	.byte $83,$00,$24,$89,$00,$3c,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$1a,$89,$00,$20,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$3c,$89
@ref72:
	.byte $00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$1a,$89,$00,$20,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$4a,$89,$00,$32,$89,$00,$32,$89,$00,$32
@ref73:
	.byte $89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$28,$89,$00,$2e,$89,$00,$32,$89,$00,$32,$89,$00,$4a,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$4a,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$83
@ref74:
	.byte $85,$00,$32,$89,$00,$32,$89,$00,$28,$89,$00,$2e,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$3c,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$87
@ref75:
	.byte $81,$00,$1a,$89,$00,$20,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$3c,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$1a,$89,$00,$20,$89,$00
@ref76:
	.byte $2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$42,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$81
@ref77:
	.byte $87,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$42,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$85
@ref78:
	.byte $83,$00,$32,$89,$00,$4a,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$4a,$89
@ref79:
	.byte $00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$3c,$89,$00,$24,$89,$00,$24,$89,$00,$24
@ref80:
	.byte $89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$3c,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$83
@ref81:
	.byte $85,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$24,$89,$00,$28,$89,$00,$28,$89,$00,$28,$89,$00,$28,$89,$00,$28,$89,$00,$28,$89,$00,$40,$89,$00,$28,$89,$00,$28,$89,$00,$28,$89,$00,$28,$89,$00,$28,$89,$00,$28,$89,$00,$28,$87
@ref82:
	.byte $81,$00,$28,$89,$00,$28,$89,$00,$28,$89,$00,$28,$89,$00,$28,$89,$00,$28,$89,$00,$28,$89,$00,$28,$89,$00,$40,$89,$00,$28,$89,$00,$28,$89,$00,$28,$89,$00,$28,$89,$00,$28,$89,$00,$28,$89,$00,$28,$89,$00,$28,$89,$00,$28,$89,$00
	.byte $ff,$38
	.word @ref76
	.byte $ff,$37
	.word @ref77
	.byte $ff,$37
	.word @ref78
	.byte $ff,$38
	.word @ref79
	.byte $ff,$37
	.word @ref80
	.byte $ff,$37
	.word @ref81
	.byte $ff,$38
	.word @ref82
	.byte $ff,$38
	.word @ref76
	.byte $ff,$37
	.word @ref77
	.byte $ff,$37
	.word @ref78
@ref83:
	.byte $00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$42,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a
@ref84:
	.byte $89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$42,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$83
@ref85:
	.byte $85,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$2a,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$4a,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$87
@ref86:
	.byte $81,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$4a,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$28,$ed
@ref87:
	.byte $32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$4a,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$28,$89,$00,$2e,$89,$00,$32,$89,$00,$32,$89,$00,$4a,$81
	.byte $ff,$37
	.word @ref70
	.byte $ff,$37
	.word @ref71
	.byte $ff,$38
	.word @ref72
	.byte $ff,$37
	.word @ref73
	.byte $ff,$37
	.word @ref74
	.byte $ff,$38
	.word @ref75
	.byte $ff,$38
	.word @ref76
	.byte $ff,$37
	.word @ref77
	.byte $ff,$37
	.word @ref78
	.byte $ff,$38
	.word @ref79
	.byte $ff,$37
	.word @ref80
	.byte $ff,$37
	.word @ref81
	.byte $ff,$38
	.word @ref82
	.byte $ff,$38
	.word @ref76
	.byte $ff,$37
	.word @ref77
	.byte $ff,$37
	.word @ref78
	.byte $ff,$38
	.word @ref79
	.byte $ff,$37
	.word @ref80
	.byte $ff,$37
	.word @ref81
	.byte $ff,$38
	.word @ref82
	.byte $ff,$38
	.word @ref76
	.byte $ff,$37
	.word @ref77
	.byte $ff,$37
	.word @ref78
	.byte $ff,$38
	.word @ref83
	.byte $ff,$37
	.word @ref84
	.byte $ff,$37
	.word @ref85
	.byte $ff,$22
	.word @ref86
@ref88:
	.byte $32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$89,$00,$32,$f9,$cb
@ref89:
	.byte $f9,$f9,$8b
	.byte $fd
	.word @song0ch2loop

@song0ch3:
@song0ch3loop:
@ref90:
	.byte $80,$5a,$f9,$f9,$89
@ref91:
	.byte $f9,$f9,$8b
@ref92:
	.byte $f9,$f9,$8b
@ref93:
	.byte $f9,$f9,$8b
@ref94:
	.byte $f9,$f9,$8b
@ref95:
	.byte $f9,$f9,$8b
@ref96:
	.byte $f9,$f9,$8b
@ref97:
	.byte $f9,$f9,$8b
@ref98:
	.byte $f9,$f9,$8b
@ref99:
	.byte $f9,$f9,$8b
@ref100:
	.byte $f9,$f9,$8b
@ref101:
	.byte $f9,$f9,$8b
@ref102:
	.byte $f9,$f9,$8b
@ref103:
	.byte $f9,$f9,$8b
@ref104:
	.byte $f9,$f9,$8b
@ref105:
	.byte $f9,$f9,$8b
@ref106:
	.byte $f9,$f9,$8b
@ref107:
	.byte $f9,$f9,$8b
@ref108:
	.byte $f9,$f9,$8b
@ref109:
	.byte $f9,$f9,$8b
@ref110:
	.byte $f9,$f9,$8b
@ref111:
	.byte $f9,$f9,$8b
@ref112:
	.byte $f9,$f9,$8b
@ref113:
	.byte $f9,$f9,$8b
@ref114:
	.byte $f9,$f9,$8b
@ref115:
	.byte $f9,$f9,$8b
@ref116:
	.byte $f9,$f9,$8b
@ref117:
	.byte $f9,$af,$00,$9b,$5a,$b3,$00
@ref118:
	.byte $5a,$f9,$f9,$89
@ref119:
	.byte $f9,$f9,$8b
@ref120:
	.byte $f9,$f9,$8b
@ref121:
	.byte $f9,$f9,$8b
@ref122:
	.byte $f9,$f9,$8b
@ref123:
	.byte $f9,$f9,$8b
@ref124:
	.byte $f9,$f9,$8b
@ref125:
	.byte $f9,$f9,$8b
@ref126:
	.byte $f9,$f9,$8b
@ref127:
	.byte $f9,$f9,$8b
@ref128:
	.byte $f9,$f9,$8b
@ref129:
	.byte $f9,$f9,$8b
@ref130:
	.byte $f9,$f9,$8b
@ref131:
	.byte $f9,$f9,$8b
@ref132:
	.byte $f9,$f9,$8b
@ref133:
	.byte $f9,$f9,$8b
@ref134:
	.byte $f9,$f9,$8b
@ref135:
	.byte $f9,$f9,$8b
@ref136:
	.byte $f9,$f9,$8b
@ref137:
	.byte $f9,$f9,$8b
@ref138:
	.byte $f9,$f9,$8b
@ref139:
	.byte $f9,$f9,$8b
@ref140:
	.byte $f9,$f9,$8b
@ref141:
	.byte $f9,$f9,$8b
@ref142:
	.byte $f9,$f9,$8b
@ref143:
	.byte $f9,$f9,$8b
@ref144:
	.byte $f9,$f9,$8b
	.byte $ff,$07
	.word @ref117
@ref145:
	.byte $5a,$f9,$f9,$89
@ref146:
	.byte $f9,$f9,$8b
	.byte $fd
	.word @song0ch3loop

@song0ch4:
@song0ch4loop:
@ref147:
	.byte $02,$8b,$02,$8b,$02,$b5,$02,$d1,$02,$b5,$02,$99,$02,$81
@ref148:
	.byte $b3,$02,$d1,$02,$8b,$02,$8b,$02,$99,$02,$8b,$02,$8b,$02,$a1
@ref149:
	.byte $93,$02,$d1,$02,$b5,$02,$99,$02,$c1
@ref150:
	.byte $8f,$02,$b5,$02,$8b,$02,$8b,$02,$99,$02,$8b,$02,$8b,$02,$b5,$02,$a9
@ref151:
	.byte $a7,$02,$b5,$02,$99,$02,$b5,$02,$c9
@ref152:
	.byte $87,$02,$8b,$02,$8b,$02,$99,$02,$8b,$02,$8b,$02,$b5,$02,$d1,$02,$95
@ref153:
	.byte $9f,$02,$99,$02,$d1,$02,$b5,$02,$8b,$02,$8b,$02,$8b,$02,$8b
	.byte $ff,$0e
	.word @ref147
	.byte $ff,$0f
	.word @ref148
	.byte $ff,$09
	.word @ref149
	.byte $ff,$11
	.word @ref150
	.byte $ff,$09
	.word @ref151
	.byte $ff,$11
	.word @ref152
	.byte $ff,$0f
	.word @ref153
	.byte $ff,$0e
	.word @ref147
	.byte $ff,$0f
	.word @ref148
	.byte $ff,$09
	.word @ref149
	.byte $ff,$11
	.word @ref150
	.byte $ff,$09
	.word @ref151
	.byte $ff,$11
	.word @ref152
@ref154:
	.byte $9f,$02,$99,$02,$d1,$02,$99,$02,$8b,$02,$8b,$02,$8b,$02,$8b,$02,$8b,$02,$8b
	.byte $ff,$0e
	.word @ref147
	.byte $ff,$0f
	.word @ref148
	.byte $ff,$09
	.word @ref149
	.byte $ff,$11
	.word @ref150
	.byte $ff,$09
	.word @ref151
	.byte $ff,$11
	.word @ref152
@ref155:
	.byte $bb,$02,$8b,$02,$8b,$02,$8b,$02,$8b,$02,$8b,$02,$8b,$02,$b5,$02,$8b,$02,$8b,$02,$99
	.byte $ff,$0e
	.word @ref147
	.byte $ff,$0f
	.word @ref148
	.byte $ff,$09
	.word @ref149
	.byte $ff,$11
	.word @ref150
	.byte $ff,$09
	.word @ref151
	.byte $ff,$11
	.word @ref152
	.byte $ff,$0f
	.word @ref153
	.byte $ff,$0e
	.word @ref147
	.byte $ff,$0f
	.word @ref148
	.byte $ff,$09
	.word @ref149
	.byte $ff,$11
	.word @ref150
	.byte $ff,$09
	.word @ref151
	.byte $ff,$11
	.word @ref152
	.byte $ff,$0f
	.word @ref153
	.byte $ff,$0e
	.word @ref147
	.byte $ff,$0f
	.word @ref148
	.byte $ff,$09
	.word @ref149
	.byte $ff,$11
	.word @ref150
	.byte $ff,$09
	.word @ref151
	.byte $ff,$11
	.word @ref152
	.byte $ff,$13
	.word @ref154
	.byte $ff,$0e
	.word @ref147
	.byte $ff,$0f
	.word @ref148
	.byte $ff,$09
	.word @ref149
	.byte $ff,$11
	.word @ref150
	.byte $ff,$09
	.word @ref151
	.byte $ff,$11
	.word @ref152
	.byte $ff,$15
	.word @ref155
@ref156:
	.byte $02,$8b,$02,$8b,$02,$f9,$e7
@ref157:
	.byte $f9,$f9,$8b
	.byte $fd
	.word @song0ch4loop
