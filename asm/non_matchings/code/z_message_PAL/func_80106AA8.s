glabel func_80106AA8
/* B7DC48 80106AA8 27BDFFD0 */  addiu $sp, $sp, -0x30
/* B7DC4C 80106AAC 3C010001 */  lui   $at, 1
/* B7DC50 80106AB0 AFBF001C */  sw    $ra, 0x1c($sp)
/* B7DC54 80106AB4 AFB00018 */  sw    $s0, 0x18($sp)
/* B7DC58 80106AB8 00811021 */  addu  $v0, $a0, $at
/* B7DC5C 80106ABC 904E03DC */  lbu   $t6, 0x3dc($v0)
/* B7DC60 80106AC0 00240821 */  addu  $at, $at, $a0
/* B7DC64 80106AC4 00802825 */  move  $a1, $a0
/* B7DC68 80106AC8 25CF0001 */  addiu $t7, $t6, 1
/* B7DC6C 80106ACC A02F03DC */  sb    $t7, 0x3dc($at)
/* B7DC70 80106AD0 905803DC */  lbu   $t8, 0x3dc($v0)
/* B7DC74 80106AD4 2401002E */  li    $at, 46
/* B7DC78 80106AD8 24040001 */  li    $a0, 1
/* B7DC7C 80106ADC 17010019 */  bne   $t8, $at, .L80106B44
/* B7DC80 80106AE0 24B020D8 */   addiu $s0, $a1, 0x20d8
/* B7DC84 80106AE4 0C03B616 */  jal   AudioOcarina_SetInstrument
/* B7DC88 80106AE8 AFA50030 */   sw    $a1, 0x30($sp)
/* B7DC8C 80106AEC 0C03B8F5 */  jal   func_800EE3D4
/* B7DC90 80106AF0 00000000 */   nop   
/* B7DC94 80106AF4 8FA50030 */  lw    $a1, 0x30($sp)
/* B7DC98 80106AF8 3C068015 */  lui   $a2, %hi(D_8014B2F8) # $a2, 0x8015
/* B7DC9C 80106AFC 24C6B2F8 */  addiu $a2, %lo(D_8014B2F8) # addiu $a2, $a2, -0x4d08
/* B7DCA0 80106B00 24B020D8 */  addiu $s0, $a1, 0x20d8
/* B7DCA4 80106B04 26017FFF */  addiu $at, $s0, 0x7fff
/* B7DCA8 80106B08 AC2262B9 */  sw    $v0, 0x62b9($at)
/* B7DCAC 80106B0C A4C00000 */  sh    $zero, ($a2)
/* B7DCB0 80106B10 34018000 */  li    $at, 32768
/* B7DCB4 80106B14 02011821 */  addu  $v1, $s0, $at
/* B7DCB8 80106B18 8C6862B8 */  lw    $t0, 0x62b8($v1)
/* B7DCBC 80106B1C 84D90000 */  lh    $t9, ($a2)
/* B7DCC0 80106B20 3404A000 */  li    $a0, 40960
/* B7DCC4 80106B24 A1190002 */  sb    $t9, 2($t0)
/* B7DCC8 80106B28 0C03B301 */  jal   func_800ECC04
/* B7DCCC 80106B2C AFA30024 */   sw    $v1, 0x24($sp)
/* B7DCD0 80106B30 8FA30024 */  lw    $v1, 0x24($sp)
/* B7DCD4 80106B34 26017FFF */  addiu $at, $s0, 0x7fff
/* B7DCD8 80106B38 946963D4 */  lhu   $t1, 0x63d4($v1)
/* B7DCDC 80106B3C 1000001B */  b     .L80106BAC
/* B7DCE0 80106B40 A42963D3 */   sh    $t1, 0x63d3($at)
.L80106B44:
/* B7DCE4 80106B44 34018000 */  li    $at, 32768
/* B7DCE8 80106B48 02011821 */  addu  $v1, $s0, $at
/* B7DCEC 80106B4C 906A6304 */  lbu   $t2, 0x6304($v1)
/* B7DCF0 80106B50 2401002C */  li    $at, 44
/* B7DCF4 80106B54 24040006 */  li    $a0, 6
/* B7DCF8 80106B58 15410014 */  bne   $t2, $at, .L80106BAC
/* B7DCFC 80106B5C 00000000 */   nop   
/* B7DD00 80106B60 0C03B616 */  jal   AudioOcarina_SetInstrument
/* B7DD04 80106B64 AFA30024 */   sw    $v1, 0x24($sp)
/* B7DD08 80106B68 0C03B8FE */  jal   AudioOcarina_GetDisplayedStaff
/* B7DD0C 80106B6C 00000000 */   nop   
/* B7DD10 80106B70 8FA30024 */  lw    $v1, 0x24($sp)
/* B7DD14 80106B74 3C068015 */  lui   $a2, %hi(D_8014B2F8) # $a2, 0x8015
/* B7DD18 80106B78 26017FFF */  addiu $at, $s0, 0x7fff
/* B7DD1C 80106B7C AC2262B9 */  sw    $v0, 0x62b9($at)
/* B7DD20 80106B80 24C6B2F8 */  addiu $a2, %lo(D_8014B2F8) # addiu $a2, $a2, -0x4d08
/* B7DD24 80106B84 A4C00000 */  sh    $zero, ($a2)
/* B7DD28 80106B88 84CB0000 */  lh    $t3, ($a2)
/* B7DD2C 80106B8C 8C6C62B8 */  lw    $t4, 0x62b8($v1)
/* B7DD30 80106B90 2404000E */  li    $a0, 14
/* B7DD34 80106B94 24050001 */  li    $a1, 1
/* B7DD38 80106B98 0C03B64F */  jal   AudioOcarina_SetSong
/* B7DD3C 80106B9C A18B0002 */   sb    $t3, 2($t4)
/* B7DD40 80106BA0 240D0002 */  li    $t5, 2
/* B7DD44 80106BA4 26017FFF */  addiu $at, $s0, 0x7fff
/* B7DD48 80106BA8 A02D63E8 */  sb    $t5, 0x63e8($at)
.L80106BAC:
/* B7DD4C 80106BAC 0C041A6C */  jal   func_801069B0
/* B7DD50 80106BB0 00000000 */   nop   
/* B7DD54 80106BB4 8FBF001C */  lw    $ra, 0x1c($sp)
/* B7DD58 80106BB8 8FB00018 */  lw    $s0, 0x18($sp)
/* B7DD5C 80106BBC 27BD0030 */  addiu $sp, $sp, 0x30
/* B7DD60 80106BC0 03E00008 */  jr    $ra
/* B7DD64 80106BC4 00000000 */   nop   

