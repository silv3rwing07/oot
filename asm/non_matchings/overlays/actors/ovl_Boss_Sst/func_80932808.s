glabel func_80932808
/* 06238 80932808 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 0623C 8093280C AFBF0014 */  sw      $ra, 0x0014($sp)
/* 06240 80932810 00803825 */  or      $a3, $a0, $zero            ## $a3 = 00000000
/* 06244 80932814 84EE001C */  lh      $t6, 0x001C($a3)           ## 0000001C
/* 06248 80932818 3C058093 */  lui     $a1, %hi(D_80937864)       ## $a1 = 80930000
/* 0624C 8093281C AFA70018 */  sw      $a3, 0x0018($sp)
/* 06250 80932820 000E7880 */  sll     $t7, $t6,  2
/* 06254 80932824 00AF2821 */  addu    $a1, $a1, $t7
/* 06258 80932828 8CA57864 */  lw      $a1, %lo(D_80937864)($a1)
/* 0625C 8093282C 2484014C */  addiu   $a0, $a0, 0x014C           ## $a0 = 0000014C
/* 06260 80932830 0C029490 */  jal     Animation_MorphToPlayOnce
/* 06264 80932834 3C064120 */  lui     $a2, 0x4120                ## $a2 = 41200000
/* 06268 80932838 8FA70018 */  lw      $a3, 0x0018($sp)
/* 0626C 8093283C 3C188093 */  lui     $t8, %hi(func_8093285C)    ## $t8 = 80930000
/* 06270 80932840 2718285C */  addiu   $t8, $t8, %lo(func_8093285C) ## $t8 = 8093285C
/* 06274 80932844 A0E00195 */  sb      $zero, 0x0195($a3)         ## 00000195
/* 06278 80932848 ACF80190 */  sw      $t8, 0x0190($a3)           ## 00000190
/* 0627C 8093284C 8FBF0014 */  lw      $ra, 0x0014($sp)
/* 06280 80932850 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 06284 80932854 03E00008 */  jr      $ra
/* 06288 80932858 00000000 */  nop
