glabel func_80860068
/* 00A18 80860068 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 00A1C 8086006C AFBF0014 */  sw      $ra, 0x0014($sp)
/* 00A20 80860070 00803025 */  or      $a2, $a0, $zero            ## $a2 = 00000000
/* 00A24 80860074 3C050600 */  lui     $a1, %hi(D_0600316C)                ## $a1 = 06000000
/* 00A28 80860078 24A5316C */  addiu   $a1, $a1, %lo(D_0600316C)           ## $a1 = 0600316C
/* 00A2C 8086007C AFA60018 */  sw      $a2, 0x0018($sp)
/* 00A30 80860080 0C0294BE */  jal     SkelAnime_ChangeAnimDefaultRepeat
/* 00A34 80860084 24840188 */  addiu   $a0, $a0, 0x0188           ## $a0 = 00000188
/* 00A38 80860088 8FA60018 */  lw      $a2, 0x0018($sp)
/* 00A3C 8086008C 240E000A */  addiu   $t6, $zero, 0x000A         ## $t6 = 0000000A
/* 00A40 80860090 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 00A44 80860094 A0CE07C8 */  sb      $t6, 0x07C8($a2)           ## 000007C8
/* 00A48 80860098 3C014120 */  lui     $at, 0x4120                ## $at = 41200000
/* 00A4C 8086009C 44812000 */  mtc1    $at, $f4                   ## $f4 = 10.00
/* 00A50 808600A0 3C0140A0 */  lui     $at, 0x40A0                ## $at = 40A00000
/* 00A54 808600A4 44814000 */  mtc1    $at, $f8                   ## $f8 = 5.00
/* 00A58 808600A8 46040182 */  mul.s   $f6, $f0, $f4
/* 00A5C 808600AC 8FA40018 */  lw      $a0, 0x0018($sp)
/* 00A60 808600B0 44809000 */  mtc1    $zero, $f18                ## $f18 = 0.00
/* 00A64 808600B4 3C058086 */  lui     $a1, %hi(func_808600EC)    ## $a1 = 80860000
/* 00A68 808600B8 849900B6 */  lh      $t9, 0x00B6($a0)           ## 000000B6
/* 00A6C 808600BC 24A500EC */  addiu   $a1, $a1, %lo(func_808600EC) ## $a1 = 808600EC
/* 00A70 808600C0 E4920068 */  swc1    $f18, 0x0068($a0)          ## 00000068
/* 00A74 808600C4 46083280 */  add.s   $f10, $f6, $f8
/* 00A78 808600C8 A4990032 */  sh      $t9, 0x0032($a0)           ## 00000032
/* 00A7C 808600CC 4600540D */  trunc.w.s $f16, $f10
/* 00A80 808600D0 44188000 */  mfc1    $t8, $f16
/* 00A84 808600D4 0C217D94 */  jal     EnTest_SetupAction
/* 00A88 808600D8 AC9807E8 */  sw      $t8, 0x07E8($a0)           ## 000007E8
/* 00A8C 808600DC 8FBF0014 */  lw      $ra, 0x0014($sp)
/* 00A90 808600E0 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 00A94 808600E4 03E00008 */  jr      $ra
/* 00A98 808600E8 00000000 */  nop
