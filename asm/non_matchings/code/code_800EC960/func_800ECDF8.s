glabel func_800ECDF8
/* B63F98 800ECDF8 27BDFFA0 */  addiu $sp, $sp, -0x60
/* B63F9C 800ECDFC AFBF002C */  sw    $ra, 0x2c($sp)
/* B63FA0 800ECE00 AFB50028 */  sw    $s5, 0x28($sp)
/* B63FA4 800ECE04 AFB40024 */  sw    $s4, 0x24($sp)
/* B63FA8 800ECE08 AFB30020 */  sw    $s3, 0x20($sp)
/* B63FAC 800ECE0C AFB2001C */  sw    $s2, 0x1c($sp)
/* B63FB0 800ECE10 AFB10018 */  sw    $s1, 0x18($sp)
/* B63FB4 800ECE14 AFB00014 */  sw    $s0, 0x14($sp)
/* B63FB8 800ECE18 A3A0005B */  sb    $zero, 0x5b($sp)
/* B63FBC 800ECE1C 0C03B36F */  jal   func_800ECDBC
/* B63FC0 800ECE20 A3A00057 */   sb    $zero, 0x57($sp)
/* B63FC4 800ECE24 3C0E8017 */  lui   $t6, %hi(sOcarinaHasStartedSong) # $t6, 0x8017
/* B63FC8 800ECE28 91CEBA29 */  lbu   $t6, %lo(sOcarinaHasStartedSong)($t6)
/* B63FCC 800ECE2C 3C028013 */  lui   $v0, %hi(D_80130F2C) # $v0, 0x8013
/* B63FD0 800ECE30 51C000EB */  beql  $t6, $zero, .L800ED1E0
/* B63FD4 800ECE34 8FBF002C */   lw    $ra, 0x2c($sp)
/* B63FD8 800ECE38 80420F2C */  lb    $v0, %lo(D_80130F2C)($v0)
/* B63FDC 800ECE3C 3C0F8013 */  lui   $t7, %hi(sCurOcarinaBtnVal) # $t7, 0x8013
/* B63FE0 800ECE40 3C188013 */  lui   $t8, %hi(sPrevOcarinaNoteVal) # $t8, 0x8013
/* B63FE4 800ECE44 04410003 */  bgez  $v0, .L800ECE54
/* B63FE8 800ECE48 00401825 */   move  $v1, $v0
/* B63FEC 800ECE4C 10000001 */  b     .L800ECE54
/* B63FF0 800ECE50 00021823 */   negu  $v1, $v0
.L800ECE54:
/* B63FF4 800ECE54 28610015 */  slti  $at, $v1, 0x15
/* B63FF8 800ECE58 14200004 */  bnez  $at, .L800ECE6C
/* B63FFC 800ECE5C 3C1F8017 */   lui   $ra, %hi(sOcarinaSongNotestartIdx) # $ra, 0x8017
/* B64000 800ECE60 3C018013 */  lui   $at, %hi(D_80130F3C) # $at, 0x8013
/* B64004 800ECE64 100000DD */  b     .L800ED1DC
/* B64008 800ECE68 AC200F3C */   sw    $zero, %lo(D_80130F3C)($at)
.L800ECE6C:
/* B6400C 800ECE6C 91EF0F14 */  lbu   $t7, %lo(sCurOcarinaBtnVal)($t7)
/* B64010 800ECE70 93180F18 */  lbu   $t8, %lo(sPrevOcarinaNoteVal)($t8)
/* B64014 800ECE74 3C0E8017 */  lui   $t6, %hi(sOcarinaSongCnt) # $t6, 0x8017
/* B64018 800ECE78 AFAF0040 */  sw    $t7, 0x40($sp)
/* B6401C 800ECE7C 11F80003 */  beq   $t7, $t8, .L800ECE8C
/* B64020 800ECE80 01E0A825 */   move  $s5, $t7
/* B64024 800ECE84 240D00FF */  li    $t5, 255
/* B64028 800ECE88 15AF0003 */  bne   $t5, $t7, .L800ECE98
.L800ECE8C:
/* B6402C 800ECE8C 24190001 */   li    $t9, 1
/* B64030 800ECE90 A3B9005B */  sb    $t9, 0x5b($sp)
/* B64034 800ECE94 240D00FF */  li    $t5, 255
.L800ECE98:
/* B64038 800ECE98 93FFBA2A */  lbu   $ra, %lo(sOcarinaSongNotestartIdx)($ra)
/* B6403C 800ECE9C 91CEBA2B */  lbu   $t6, %lo(sOcarinaSongCnt)($t6)
/* B64040 800ECEA0 3C108017 */  lui   $s0, %hi(sOcarinaAvailSongs) # $s0, 0x8017
/* B64044 800ECEA4 03E03025 */  move  $a2, $ra
/* B64048 800ECEA8 03EE082A */  slt   $at, $ra, $t6
/* B6404C 800ECEAC 102000BE */  beqz  $at, .L800ED1A8
/* B64050 800ECEB0 AFAE0034 */   sw    $t6, 0x34($sp)
/* B64054 800ECEB4 3C148013 */  lui   $s4, %hi(sOcarinaSongs) # $s4, 0x8013
/* B64058 800ECEB8 3C138017 */  lui   $s3, %hi(D_8016BA30) # $s3, 0x8017
/* B6405C 800ECEBC 3C128013 */  lui   $s2, %hi(D_80130F20) # $s2, 0x8013
/* B64060 800ECEC0 3C118017 */  lui   $s1, %hi(D_8016BA90) # $s1, 0x8017
/* B64064 800ECEC4 3C028017 */  lui   $v0, %hi(D_8016BA2E) # $v0, 0x8017
/* B64068 800ECEC8 2442BA2E */  addiu $v0, %lo(D_8016BA2E) # addiu $v0, $v0, -0x45d2
/* B6406C 800ECECC 2631BA90 */  addiu $s1, %lo(D_8016BA90) # addiu $s1, $s1, -0x4570
/* B64070 800ECED0 26520F20 */  addiu $s2, %lo(D_80130F20) # addiu $s2, $s2, 0xf20
/* B64074 800ECED4 2673BA30 */  addiu $s3, %lo(D_8016BA30) # addiu $s3, $s3, -0x45d0
/* B64078 800ECED8 26940F80 */  addiu $s4, %lo(sOcarinaSongs) # addiu $s4, $s4, 0xf80
/* B6407C 800ECEDC 9610BA2C */  lhu   $s0, %lo(sOcarinaAvailSongs)($s0)
.L800ECEE0:
/* B64080 800ECEE0 240F0001 */  li    $t7, 1
/* B64084 800ECEE4 00CF5804 */  sllv  $t3, $t7, $a2
/* B64088 800ECEE8 316BFFFF */  andi  $t3, $t3, 0xffff
/* B6408C 800ECEEC 020BC024 */  and   $t8, $s0, $t3
/* B64090 800ECEF0 1300008E */  beqz  $t8, .L800ED12C
/* B64094 800ECEF4 001F6040 */   sll   $t4, $ra, 1
/* B64098 800ECEF8 3C0E8017 */  lui   $t6, %hi(D_8016BA70) # $t6, 0x8017
/* B6409C 800ECEFC 25CEBA70 */  addiu $t6, %lo(D_8016BA70) # addiu $t6, $t6, -0x4590
/* B640A0 800ECF00 018E4021 */  addu  $t0, $t4, $t6
/* B640A4 800ECF04 95040000 */  lhu   $a0, ($t0)
/* B640A8 800ECF08 93AF005B */  lbu   $t7, 0x5b($sp)
/* B640AC 800ECF0C 3C198017 */  lui   $t9, %hi(D_8016BA50) # $t9, 0x8017
/* B640B0 800ECF10 2739BA50 */  addiu $t9, %lo(D_8016BA50) # addiu $t9, $t9, -0x45b0
/* B640B4 800ECF14 01991821 */  addu  $v1, $t4, $t9
/* B640B8 800ECF18 24850012 */  addiu $a1, $a0, 0x12
/* B640BC 800ECF1C 11E00021 */  beqz  $t7, .L800ECFA4
/* B640C0 800ECF20 A4650000 */   sh    $a1, ($v1)
/* B640C4 800ECF24 30A2FFFF */  andi  $v0, $a1, 0xffff
/* B640C8 800ECF28 2498FFEE */  addiu $t8, $a0, -0x12
/* B640CC 800ECF2C 0058082A */  slt   $at, $v0, $t8
/* B640D0 800ECF30 14200019 */  bnez  $at, .L800ECF98
/* B640D4 800ECF34 0045082A */   slt   $at, $v0, $a1
/* B640D8 800ECF38 14200017 */  bnez  $at, .L800ECF98
/* B640DC 800ECF3C 001FC880 */   sll   $t9, $ra, 2
/* B640E0 800ECF40 026C7821 */  addu  $t7, $s3, $t4
/* B640E4 800ECF44 95F80000 */  lhu   $t8, ($t7)
/* B640E8 800ECF48 033FC821 */  addu  $t9, $t9, $ra
/* B640EC 800ECF4C 0019C940 */  sll   $t9, $t9, 5
/* B640F0 800ECF50 02997021 */  addu  $t6, $s4, $t9
/* B640F4 800ECF54 0018C8C0 */  sll   $t9, $t8, 3
/* B640F8 800ECF58 01D97821 */  addu  $t7, $t6, $t9
/* B640FC 800ECF5C 95F80002 */  lhu   $t8, 2($t7)
/* B64100 800ECF60 023FC821 */  addu  $t9, $s1, $ra
/* B64104 800ECF64 1700000C */  bnez  $t8, .L800ECF98
/* B64108 800ECF68 00000000 */   nop   
/* B6410C 800ECF6C 924E0000 */  lbu   $t6, ($s2)
/* B64110 800ECF70 932F0000 */  lbu   $t7, ($t9)
/* B64114 800ECF74 24D80001 */  addiu $t8, $a2, 1
/* B64118 800ECF78 3C018013 */  lui   $at, %hi(D_80131878) # $at, 0x8013
/* B6411C 800ECF7C 15CF0006 */  bne   $t6, $t7, .L800ECF98
/* B64120 800ECF80 00000000 */   nop   
/* B64124 800ECF84 A0381878 */  sb    $t8, %lo(D_80131878)($at)
/* B64128 800ECF88 3C018013 */  lui   $at, %hi(sOcarinaInpEnabled) # $at, 0x8013
/* B6412C 800ECF8C A0200F0C */  sb    $zero, %lo(sOcarinaInpEnabled)($at)
/* B64130 800ECF90 3C018013 */  lui   $at, %hi(D_80130F3C) # $at, 0x8013
/* B64134 800ECF94 AC200F3C */  sw    $zero, %lo(D_80130F3C)($at)
.L800ECF98:
/* B64138 800ECF98 3C028017 */  lui   $v0, %hi(D_8016BA2E) # $v0, 0x8017
/* B6413C 800ECF9C 10000063 */  b     .L800ED12C
/* B64140 800ECFA0 2442BA2E */   addiu $v0, %lo(D_8016BA2E) # addiu $v0, $v0, -0x45d2
.L800ECFA4:
/* B64144 800ECFA4 94620000 */  lhu   $v0, ($v1)
/* B64148 800ECFA8 2499FFEE */  addiu $t9, $a0, -0x12
/* B6414C 800ECFAC 026C3821 */  addu  $a3, $s3, $t4
/* B64150 800ECFB0 0059082A */  slt   $at, $v0, $t9
/* B64154 800ECFB4 1420004C */  bnez  $at, .L800ED0E8
/* B64158 800ECFB8 001FC880 */   sll   $t9, $ra, 2
/* B6415C 800ECFBC 92420000 */  lbu   $v0, ($s2)
/* B64160 800ECFC0 023F7021 */  addu  $t6, $s1, $ra
/* B64164 800ECFC4 033FC821 */  addu  $t9, $t9, $ra
/* B64168 800ECFC8 51A2000F */  beql  $t5, $v0, .L800ED008
/* B6416C 800ECFCC 94E20000 */   lhu   $v0, ($a3)
/* B64170 800ECFD0 91CF0000 */  lbu   $t7, ($t6)
/* B64174 800ECFD4 020BC026 */  xor   $t8, $s0, $t3
/* B64178 800ECFD8 3C018017 */  lui   $at, %hi(sOcarinaAvailSongs) # $at, 0x8017
/* B6417C 800ECFDC 144F0006 */  bne   $v0, $t7, .L800ECFF8
/* B64180 800ECFE0 00000000 */   nop   
/* B64184 800ECFE4 2401000C */  li    $at, 12
/* B64188 800ECFE8 54C10007 */  bnel  $a2, $at, .L800ED008
/* B6418C 800ECFEC 94E20000 */   lhu   $v0, ($a3)
/* B64190 800ECFF0 10000004 */  b     .L800ED004
/* B64194 800ECFF4 A4600000 */   sh    $zero, ($v1)
.L800ECFF8:
/* B64198 800ECFF8 A438BA2C */  sh    $t8, %lo(sOcarinaAvailSongs)($at)
/* B6419C 800ECFFC 3C108017 */  lui   $s0, %hi(sOcarinaAvailSongs) # $s0, 0x8017
/* B641A0 800ED000 9610BA2C */  lhu   $s0, %lo(sOcarinaAvailSongs)($s0)
.L800ED004:
/* B641A4 800ED004 94E20000 */  lhu   $v0, ($a3)
.L800ED008:
/* B641A8 800ED008 0019C940 */  sll   $t9, $t9, 5
/* B641AC 800ED00C 02993021 */  addu  $a2, $s4, $t9
/* B641B0 800ED010 24490001 */  addiu $t1, $v0, 1
/* B641B4 800ED014 3129FFFF */  andi  $t1, $t1, 0xffff
/* B641B8 800ED018 000270C0 */  sll   $t6, $v0, 3
/* B641BC 800ED01C 00CE2821 */  addu  $a1, $a2, $t6
/* B641C0 800ED020 A4E90000 */  sh    $t1, ($a3)
/* B641C4 800ED024 94B80002 */  lhu   $t8, 2($a1)
/* B641C8 800ED028 000978C0 */  sll   $t7, $t1, 3
/* B641CC 800ED02C 00CF5021 */  addu  $t2, $a2, $t7
/* B641D0 800ED030 A5180000 */  sh    $t8, ($t0)
/* B641D4 800ED034 90B90000 */  lbu   $t9, ($a1)
/* B641D8 800ED038 023F1821 */  addu  $v1, $s1, $ra
/* B641DC 800ED03C 01402025 */  move  $a0, $t2
/* B641E0 800ED040 332E00FF */  andi  $t6, $t9, 0xff
/* B641E4 800ED044 12AE0006 */  beq   $s5, $t6, .L800ED060
/* B641E8 800ED048 A0790000 */   sb    $t9, ($v1)
/* B641EC 800ED04C 020B7826 */  xor   $t7, $s0, $t3
/* B641F0 800ED050 3C018017 */  lui   $at, %hi(sOcarinaAvailSongs) # $at, 0x8017
/* B641F4 800ED054 A42FBA2C */  sh    $t7, %lo(sOcarinaAvailSongs)($at)
/* B641F8 800ED058 3C108017 */  lui   $s0, %hi(sOcarinaAvailSongs) # $s0, 0x8017
/* B641FC 800ED05C 9610BA2C */  lhu   $s0, %lo(sOcarinaAvailSongs)($s0)
.L800ED060:
/* B64200 800ED060 90980000 */  lbu   $t8, ($a0)
/* B64204 800ED064 90B90000 */  lbu   $t9, ($a1)
/* B64208 800ED068 53190008 */  beql  $t8, $t9, .L800ED08C
/* B6420C 800ED06C 95180000 */   lhu   $t8, ($t0)
/* B64210 800ED070 914E0000 */  lbu   $t6, ($t2)
/* B64214 800ED074 15AE0019 */  bne   $t5, $t6, .L800ED0DC
/* B64218 800ED078 00000000 */   nop   
/* B6421C 800ED07C 954F0002 */  lhu   $t7, 2($t2)
/* B64220 800ED080 11E00016 */  beqz  $t7, .L800ED0DC
/* B64224 800ED084 00000000 */   nop   
/* B64228 800ED088 95180000 */  lhu   $t8, ($t0)
.L800ED08C:
/* B6422C 800ED08C 94990002 */  lhu   $t9, 2($a0)
/* B64230 800ED090 94E20000 */  lhu   $v0, ($a3)
/* B64234 800ED094 03197021 */  addu  $t6, $t8, $t9
/* B64238 800ED098 24590001 */  addiu $t9, $v0, 1
/* B6423C 800ED09C A50E0000 */  sh    $t6, ($t0)
/* B64240 800ED0A0 A4F90000 */  sh    $t9, ($a3)
/* B64244 800ED0A4 000278C0 */  sll   $t7, $v0, 3
/* B64248 800ED0A8 0002C0C0 */  sll   $t8, $v0, 3
/* B6424C 800ED0AC 00CF2821 */  addu  $a1, $a2, $t7
/* B64250 800ED0B0 00D82021 */  addu  $a0, $a2, $t8
/* B64254 800ED0B4 90830008 */  lbu   $v1, 8($a0)
/* B64258 800ED0B8 90AE0000 */  lbu   $t6, ($a1)
/* B6425C 800ED0BC 24840008 */  addiu $a0, $a0, 8
/* B64260 800ED0C0 506EFFF2 */  beql  $v1, $t6, .L800ED08C
/* B64264 800ED0C4 95180000 */   lhu   $t8, ($t0)
/* B64268 800ED0C8 15A30004 */  bne   $t5, $v1, .L800ED0DC
/* B6426C 800ED0CC 00000000 */   nop   
/* B64270 800ED0D0 948F0002 */  lhu   $t7, 2($a0)
/* B64274 800ED0D4 55E0FFED */  bnezl $t7, .L800ED08C
/* B64278 800ED0D8 95180000 */   lhu   $t8, ($t0)
.L800ED0DC:
/* B6427C 800ED0DC 3C028017 */  lui   $v0, %hi(D_8016BA2E) # $v0, 0x8017
/* B64280 800ED0E0 10000012 */  b     .L800ED12C
/* B64284 800ED0E4 2442BA2E */   addiu $v0, %lo(D_8016BA2E) # addiu $v0, $v0, -0x45d2
.L800ED0E8:
/* B64288 800ED0E8 2841000A */  slti  $at, $v0, 0xa
/* B6428C 800ED0EC 10200008 */  beqz  $at, .L800ED110
/* B64290 800ED0F0 2418FFFF */   li    $t8, -1
/* B64294 800ED0F4 8FB90040 */  lw    $t9, 0x40($sp)
/* B64298 800ED0F8 3C028017 */  lui   $v0, %hi(D_8016BA2E) # $v0, 0x8017
/* B6429C 800ED0FC A3B80057 */  sb    $t8, 0x57($sp)
/* B642A0 800ED100 A4600000 */  sh    $zero, ($v1)
/* B642A4 800ED104 2442BA2E */  addiu $v0, %lo(D_8016BA2E) # addiu $v0, $v0, -0x45d2
/* B642A8 800ED108 10000008 */  b     .L800ED12C
/* B642AC 800ED10C A2590000 */   sb    $t9, ($s2)
.L800ED110:
/* B642B0 800ED110 020B7026 */  xor   $t6, $s0, $t3
/* B642B4 800ED114 3C018017 */  lui   $at, %hi(sOcarinaAvailSongs) # $at, 0x8017
/* B642B8 800ED118 A42EBA2C */  sh    $t6, %lo(sOcarinaAvailSongs)($at)
/* B642BC 800ED11C 3C108017 */  lui   $s0, %hi(sOcarinaAvailSongs) # $s0, 0x8017
/* B642C0 800ED120 3C028017 */  lui   $v0, %hi(D_8016BA2E) # $v0, 0x8017
/* B642C4 800ED124 2442BA2E */  addiu $v0, %lo(D_8016BA2E) # addiu $v0, $v0, -0x45d2
/* B642C8 800ED128 9610BA2C */  lhu   $s0, %lo(sOcarinaAvailSongs)($s0)
.L800ED12C:
/* B642CC 800ED12C 16000018 */  bnez  $s0, .L800ED190
/* B642D0 800ED130 3C188013 */   lui   $t8, %hi(D_8013187C) # $t8, 0x8013
/* B642D4 800ED134 904F0000 */  lbu   $t7, ($v0)
/* B642D8 800ED138 9318187C */  lbu   $t8, %lo(D_8013187C)($t8)
/* B642DC 800ED13C 01F8082A */  slt   $at, $t7, $t8
/* B642E0 800ED140 54200014 */  bnezl $at, .L800ED194
/* B642E4 800ED144 8FB90034 */   lw    $t9, 0x34($sp)
/* B642E8 800ED148 3C028013 */  lui   $v0, %hi(D_80130F3C) # $v0, 0x8013
/* B642EC 800ED14C 8C420F3C */  lw    $v0, %lo(D_80130F3C)($v0)
/* B642F0 800ED150 3C018013 */  lui   $at, %hi(sOcarinaInpEnabled) # $at, 0x8013
/* B642F4 800ED154 A0200F0C */  sb    $zero, %lo(sOcarinaInpEnabled)($at)
/* B642F8 800ED158 30594000 */  andi  $t9, $v0, 0x4000
/* B642FC 800ED15C 13200009 */  beqz  $t9, .L800ED184
/* B64300 800ED160 001F7080 */   sll   $t6, $ra, 2
/* B64304 800ED164 01DF7021 */  addu  $t6, $t6, $ra
/* B64308 800ED168 000E7140 */  sll   $t6, $t6, 5
/* B6430C 800ED16C 028E7821 */  addu  $t7, $s4, $t6
/* B64310 800ED170 91F80000 */  lbu   $t8, ($t7)
/* B64314 800ED174 3C018013 */  lui   $at, %hi(D_80130F4C) # $at, 0x8013
/* B64318 800ED178 16B80002 */  bne   $s5, $t8, .L800ED184
/* B6431C 800ED17C 00000000 */   nop   
/* B64320 800ED180 A4220F4C */  sh    $v0, %lo(D_80130F4C)($at)
.L800ED184:
/* B64324 800ED184 3C018013 */  lui   $at, %hi(D_80130F3C) # $at, 0x8013
/* B64328 800ED188 10000014 */  b     .L800ED1DC
/* B6432C 800ED18C AC200F3C */   sw    $zero, %lo(D_80130F3C)($at)
.L800ED190:
/* B64330 800ED190 8FB90034 */  lw    $t9, 0x34($sp)
.L800ED194:
/* B64334 800ED194 27FF0001 */  addiu $ra, $ra, 1
/* B64338 800ED198 33FF00FF */  andi  $ra, $ra, 0xff
/* B6433C 800ED19C 03F9082A */  slt   $at, $ra, $t9
/* B64340 800ED1A0 1420FF4F */  bnez  $at, .L800ECEE0
/* B64344 800ED1A4 03E03025 */   move  $a2, $ra
.L800ED1A8:
/* B64348 800ED1A8 93AE005B */  lbu   $t6, 0x5b($sp)
/* B6434C 800ED1AC 3C028017 */  lui   $v0, %hi(D_8016BA2E) # $v0, 0x8017
/* B64350 800ED1B0 3C128013 */  lui   $s2, %hi(D_80130F20) # $s2, 0x8013
/* B64354 800ED1B4 26520F20 */  addiu $s2, %lo(D_80130F20) # addiu $s2, $s2, 0xf20
/* B64358 800ED1B8 15C00008 */  bnez  $t6, .L800ED1DC
/* B6435C 800ED1BC 2442BA2E */   addiu $v0, %lo(D_8016BA2E) # addiu $v0, $v0, -0x45d2
/* B64360 800ED1C0 8FAF0040 */  lw    $t7, 0x40($sp)
/* B64364 800ED1C4 90580000 */  lbu   $t8, ($v0)
/* B64368 800ED1C8 83B90057 */  lb    $t9, 0x57($sp)
/* B6436C 800ED1CC A24F0000 */  sb    $t7, ($s2)
/* B64370 800ED1D0 03197021 */  addu  $t6, $t8, $t9
/* B64374 800ED1D4 25CF0001 */  addiu $t7, $t6, 1
/* B64378 800ED1D8 A04F0000 */  sb    $t7, ($v0)
.L800ED1DC:
/* B6437C 800ED1DC 8FBF002C */  lw    $ra, 0x2c($sp)
.L800ED1E0:
/* B64380 800ED1E0 8FB00014 */  lw    $s0, 0x14($sp)
/* B64384 800ED1E4 8FB10018 */  lw    $s1, 0x18($sp)
/* B64388 800ED1E8 8FB2001C */  lw    $s2, 0x1c($sp)
/* B6438C 800ED1EC 8FB30020 */  lw    $s3, 0x20($sp)
/* B64390 800ED1F0 8FB40024 */  lw    $s4, 0x24($sp)
/* B64394 800ED1F4 8FB50028 */  lw    $s5, 0x28($sp)
/* B64398 800ED1F8 03E00008 */  jr    $ra
/* B6439C 800ED1FC 27BD0060 */   addiu $sp, $sp, 0x60

