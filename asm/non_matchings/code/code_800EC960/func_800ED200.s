glabel func_800ED200
/* B643A0 800ED200 3C028017 */  lui   $v0, %hi(sCurOcarinaBtnPress) # $v0, 0x8017
/* B643A4 800ED204 8C42BA0C */  lw    $v0, %lo(sCurOcarinaBtnPress)($v0)
/* B643A8 800ED208 27BDFFE0 */  addiu $sp, $sp, -0x20
/* B643AC 800ED20C AFBF001C */  sw    $ra, 0x1c($sp)
/* B643B0 800ED210 304E0020 */  andi  $t6, $v0, 0x20
/* B643B4 800ED214 11C0000B */  beqz  $t6, .L800ED244
/* B643B8 800ED218 AFB00018 */   sw    $s0, 0x18($sp)
/* B643BC 800ED21C 3C0F8013 */  lui   $t7, %hi(sOcarinaAllowedBtnMask) # $t7, 0x8013
/* B643C0 800ED220 8DEF0EFC */  lw    $t7, %lo(sOcarinaAllowedBtnMask)($t7)
/* B643C4 800ED224 3C048013 */  lui   $a0, %hi(D_80130F3E) # $a0, 0x8013
/* B643C8 800ED228 004FC024 */  and   $t8, $v0, $t7
/* B643CC 800ED22C 13000005 */  beqz  $t8, .L800ED244
/* B643D0 800ED230 00000000 */   nop   
/* B643D4 800ED234 0C03B301 */  jal   func_800ECC04
/* B643D8 800ED238 94840F3E */   lhu   $a0, %lo(D_80130F3E)($a0)
/* B643DC 800ED23C 10000082 */  b     .L800ED448
/* B643E0 800ED240 8FBF001C */   lw    $ra, 0x1c($sp)
.L800ED244:
/* B643E4 800ED244 0C03B36F */  jal   func_800ECDBC
/* B643E8 800ED248 00000000 */   nop   
/* B643EC 800ED24C 3C198017 */  lui   $t9, %hi(sOcarinaHasStartedSong) # $t9, 0x8017
/* B643F0 800ED250 9339BA29 */  lbu   $t9, %lo(sOcarinaHasStartedSong)($t9)
/* B643F4 800ED254 3C058013 */  lui   $a1, %hi(sCurOcarinaBtnVal) # $a1, 0x8013
/* B643F8 800ED258 3C0E8013 */  lui   $t6, %hi(sPrevOcarinaNoteVal) # $t6, 0x8013
/* B643FC 800ED25C 5320007A */  beql  $t9, $zero, .L800ED448
/* B64400 800ED260 8FBF001C */   lw    $ra, 0x1c($sp)
/* B64404 800ED264 90A50F14 */  lbu   $a1, %lo(sCurOcarinaBtnVal)($a1)
/* B64408 800ED268 91CE0F18 */  lbu   $t6, %lo(sPrevOcarinaNoteVal)($t6)
/* B6440C 800ED26C 240100FF */  li    $at, 255
/* B64410 800ED270 50AE0075 */  beql  $a1, $t6, .L800ED448
/* B64414 800ED274 8FBF001C */   lw    $ra, 0x1c($sp)
/* B64418 800ED278 10A10072 */  beq   $a1, $at, .L800ED444
/* B6441C 800ED27C 3C028017 */   lui   $v0, %hi(D_8016BA2E) # $v0, 0x8017
/* B64420 800ED280 2442BA2E */  addiu $v0, %lo(D_8016BA2E) # addiu $v0, $v0, -0x45d2
/* B64424 800ED284 904F0000 */  lbu   $t7, ($v0)
/* B64428 800ED288 3C038017 */  lui   $v1, %hi(sOcarinaSongAppendPos) # $v1, 0x8017
/* B6442C 800ED28C 2463BA28 */  addiu $v1, %lo(sOcarinaSongAppendPos) # addiu $v1, $v1, -0x45d8
/* B64430 800ED290 25F80001 */  addiu $t8, $t7, 1
/* B64434 800ED294 331900FF */  andi  $t9, $t8, 0xff
/* B64438 800ED298 2B210009 */  slti  $at, $t9, 9
/* B6443C 800ED29C 14200003 */  bnez  $at, .L800ED2AC
/* B64440 800ED2A0 A0580000 */   sb    $t8, ($v0)
/* B64444 800ED2A4 240E0001 */  li    $t6, 1
/* B64448 800ED2A8 A04E0000 */  sb    $t6, ($v0)
.L800ED2AC:
/* B6444C 800ED2AC 90620000 */  lbu   $v0, ($v1)
/* B64450 800ED2B0 24010008 */  li    $at, 8
/* B64454 800ED2B4 00005825 */  move  $t3, $zero
/* B64458 800ED2B8 1441000F */  bne   $v0, $at, .L800ED2F8
/* B6445C 800ED2BC 00405025 */   move  $t2, $v0
/* B64460 800ED2C0 3C028017 */  lui   $v0, %hi(sCurOcarinaSong) # $v0, 0x8017
/* B64464 800ED2C4 2442BA20 */  addiu $v0, %lo(sCurOcarinaSong) # addiu $v0, $v0, -0x45e0
/* B64468 800ED2C8 00006025 */  move  $t4, $zero
.L800ED2CC:
/* B6446C 800ED2CC 004BC821 */  addu  $t9, $v0, $t3
/* B64470 800ED2D0 256B0001 */  addiu $t3, $t3, 1
/* B64474 800ED2D4 004C7821 */  addu  $t7, $v0, $t4
/* B64478 800ED2D8 91F80001 */  lbu   $t8, 1($t7)
/* B6447C 800ED2DC 316B00FF */  andi  $t3, $t3, 0xff
/* B64480 800ED2E0 29610007 */  slti  $at, $t3, 7
/* B64484 800ED2E4 01606025 */  move  $t4, $t3
/* B64488 800ED2E8 1420FFF8 */  bnez  $at, .L800ED2CC
/* B6448C 800ED2EC A3380000 */   sb    $t8, ($t9)
/* B64490 800ED2F0 10000006 */  b     .L800ED30C
/* B64494 800ED2F4 00000000 */   nop   
.L800ED2F8:
/* B64498 800ED2F8 244E0001 */  addiu $t6, $v0, 1
/* B6449C 800ED2FC 3C028017 */  lui   $v0, %hi(sCurOcarinaSong) # $v0, 0x8017
/* B644A0 800ED300 2442BA20 */  addiu $v0, %lo(sCurOcarinaSong) # addiu $v0, $v0, -0x45e0
/* B644A4 800ED304 A06E0000 */  sb    $t6, ($v1)
/* B644A8 800ED308 31CA00FF */  andi  $t2, $t6, 0xff
.L800ED30C:
/* B644AC 800ED30C 3C038013 */  lui   $v1, %hi(D_80130F2C) # $v1, 0x8013
/* B644B0 800ED310 80630F2C */  lb    $v1, %lo(D_80130F2C)($v1)
/* B644B4 800ED314 3C0B8017 */  lui   $t3, %hi(sOcarinaSongNotestartIdx) # $t3, 0x8017
/* B644B8 800ED318 3C0D8017 */  lui   $t5, %hi(sOcarinaSongCnt) # $t5, 0x8017
/* B644BC 800ED31C 04610003 */  bgez  $v1, .L800ED32C
/* B644C0 800ED320 00602025 */   move  $a0, $v1
/* B644C4 800ED324 10000001 */  b     .L800ED32C
/* B644C8 800ED328 00032023 */   negu  $a0, $v1
.L800ED32C:
/* B644CC 800ED32C 28810015 */  slti  $at, $a0, 0x15
/* B644D0 800ED330 14200005 */  bnez  $at, .L800ED348
/* B644D4 800ED334 004AF821 */   addu  $ra, $v0, $t2
/* B644D8 800ED338 004AF821 */  addu  $ra, $v0, $t2
/* B644DC 800ED33C 240F00FF */  li    $t7, 255
/* B644E0 800ED340 10000002 */  b     .L800ED34C
/* B644E4 800ED344 A3EFFFFF */   sb    $t7, -1($ra)
.L800ED348:
/* B644E8 800ED348 A3E5FFFF */  sb    $a1, -1($ra)
.L800ED34C:
/* B644EC 800ED34C 916BBA2A */  lbu   $t3, %lo(sOcarinaSongNotestartIdx)($t3)
/* B644F0 800ED350 91ADBA2B */  lbu   $t5, %lo(sOcarinaSongCnt)($t5)
/* B644F4 800ED354 3C108017 */  lui   $s0, %hi(sOcarinaAvailSongs) # $s0, 0x8017
/* B644F8 800ED358 3C098013 */  lui   $t1, %hi(sOcarinaNoteValues) # $t1, 0x8013
/* B644FC 800ED35C 016D082A */  slt   $at, $t3, $t5
/* B64500 800ED360 10200038 */  beqz  $at, .L800ED444
/* B64504 800ED364 01606025 */   move  $t4, $t3
/* B64508 800ED368 9610BA2C */  lhu   $s0, %lo(sOcarinaAvailSongs)($s0)
/* B6450C 800ED36C 25290F6C */  addiu $t1, %lo(sOcarinaNoteValues) # addiu $t1, $t1, 0xf6c
.L800ED370:
/* B64510 800ED370 24180001 */  li    $t8, 1
/* B64514 800ED374 0198C804 */  sllv  $t9, $t8, $t4
/* B64518 800ED378 332EFFFF */  andi  $t6, $t9, 0xffff
/* B6451C 800ED37C 020E7824 */  and   $t7, $s0, $t6
/* B64520 800ED380 11E0002B */  beqz  $t7, .L800ED430
/* B64524 800ED384 000BC0C0 */   sll   $t8, $t3, 3
/* B64528 800ED388 3C198013 */  lui   $t9, %hi(sOcarinaSongNotes) # $t9, 0x8013
/* B6452C 800ED38C 27391C00 */  addiu $t9, %lo(sOcarinaSongNotes) # addiu $t9, $t9, 0x1c00
/* B64530 800ED390 030BC021 */  addu  $t8, $t8, $t3
/* B64534 800ED394 03194021 */  addu  $t0, $t8, $t9
/* B64538 800ED398 91060000 */  lbu   $a2, ($t0)
/* B6453C 800ED39C 00001825 */  move  $v1, $zero
/* B64540 800ED3A0 00002825 */  move  $a1, $zero
/* B64544 800ED3A4 18C0001A */  blez  $a2, .L800ED410
/* B64548 800ED3A8 0146082A */   slt   $at, $t2, $a2
/* B6454C 800ED3AC 14200018 */  bnez  $at, .L800ED410
/* B64550 800ED3B0 00067023 */   negu  $t6, $a2
/* B64554 800ED3B4 03EE3821 */  addu  $a3, $ra, $t6
/* B64558 800ED3B8 00002025 */  move  $a0, $zero
/* B6455C 800ED3BC 0103C021 */  addu  $t8, $t0, $v1
.L800ED3C0:
/* B64560 800ED3C0 93190001 */  lbu   $t9, 1($t8)
/* B64564 800ED3C4 00E47821 */  addu  $t7, $a3, $a0
/* B64568 800ED3C8 91E20000 */  lbu   $v0, ($t7)
/* B6456C 800ED3CC 01397021 */  addu  $t6, $t1, $t9
/* B64570 800ED3D0 91CF0000 */  lbu   $t7, ($t6)
/* B64574 800ED3D4 544F0006 */  bnel  $v0, $t7, .L800ED3F0
/* B64578 800ED3D8 24A50001 */   addiu $a1, $a1, 1
/* B6457C 800ED3DC 24630001 */  addiu $v1, $v1, 1
/* B64580 800ED3E0 306300FF */  andi  $v1, $v1, 0xff
/* B64584 800ED3E4 10000003 */  b     .L800ED3F4
/* B64588 800ED3E8 00602025 */   move  $a0, $v1
/* B6458C 800ED3EC 24A50001 */  addiu $a1, $a1, 1
.L800ED3F0:
/* B64590 800ED3F0 30A500FF */  andi  $a1, $a1, 0xff
.L800ED3F4:
/* B64594 800ED3F4 0086082A */  slt   $at, $a0, $a2
/* B64598 800ED3F8 10200005 */  beqz  $at, .L800ED410
/* B6459C 800ED3FC 00000000 */   nop   
/* B645A0 800ED400 14A00003 */  bnez  $a1, .L800ED410
/* B645A4 800ED404 0146082A */   slt   $at, $t2, $a2
/* B645A8 800ED408 5020FFED */  beql  $at, $zero, .L800ED3C0
/* B645AC 800ED40C 0103C021 */   addu  $t8, $t0, $v1
.L800ED410:
/* B645B0 800ED410 14660007 */  bne   $v1, $a2, .L800ED430
/* B645B4 800ED414 25980001 */   addiu $t8, $t4, 1
/* B645B8 800ED418 3C018013 */  lui   $at, %hi(D_80131878) # $at, 0x8013
/* B645BC 800ED41C A0381878 */  sb    $t8, %lo(D_80131878)($at)
/* B645C0 800ED420 3C018013 */  lui   $at, %hi(sOcarinaInpEnabled) # $at, 0x8013
/* B645C4 800ED424 A0200F0C */  sb    $zero, %lo(sOcarinaInpEnabled)($at)
/* B645C8 800ED428 3C018013 */  lui   $at, %hi(D_80130F3C) # $at, 0x8013
/* B645CC 800ED42C AC200F3C */  sw    $zero, %lo(D_80130F3C)($at)
.L800ED430:
/* B645D0 800ED430 256B0001 */  addiu $t3, $t3, 1
/* B645D4 800ED434 316B00FF */  andi  $t3, $t3, 0xff
/* B645D8 800ED438 016D082A */  slt   $at, $t3, $t5
/* B645DC 800ED43C 1420FFCC */  bnez  $at, .L800ED370
/* B645E0 800ED440 01606025 */   move  $t4, $t3
.L800ED444:
/* B645E4 800ED444 8FBF001C */  lw    $ra, 0x1c($sp)
.L800ED448:
/* B645E8 800ED448 8FB00018 */  lw    $s0, 0x18($sp)
/* B645EC 800ED44C 27BD0020 */  addiu $sp, $sp, 0x20
/* B645F0 800ED450 03E00008 */  jr    $ra
/* B645F4 800ED454 00000000 */   nop   

