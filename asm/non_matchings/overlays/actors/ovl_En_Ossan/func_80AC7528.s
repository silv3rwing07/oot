.rdata
glabel D_80AC939C
    .asciz "../z_en_oB1.c"
    .balign 4

glabel D_80AC93AC
    .asciz "../z_en_oB1.c"
    .balign 4

.text
glabel func_80AC7528
/* 04888 80AC7528 27BDFF88 */  addiu   $sp, $sp, 0xFF88           ## $sp = FFFFFF88
/* 0488C 80AC752C AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 04890 80AC7530 AFA40078 */  sw      $a0, 0x0078($sp)           
/* 04894 80AC7534 AFA5007C */  sw      $a1, 0x007C($sp)           
/* 04898 80AC7538 AFA60080 */  sw      $a2, 0x0080($sp)           
/* 0489C 80AC753C AFA70084 */  sw      $a3, 0x0084($sp)           
/* 048A0 80AC7540 8C850000 */  lw      $a1, 0x0000($a0)           ## 00000000
/* 048A4 80AC7544 3C0680AD */  lui     $a2, %hi(D_80AC939C)       ## $a2 = 80AD0000
/* 048A8 80AC7548 24C6939C */  addiu   $a2, $a2, %lo(D_80AC939C)  ## $a2 = 80AC939C
/* 048AC 80AC754C 27A4004C */  addiu   $a0, $sp, 0x004C           ## $a0 = FFFFFFD4
/* 048B0 80AC7550 24071060 */  addiu   $a3, $zero, 0x1060         ## $a3 = 00001060
/* 048B4 80AC7554 0C031AB1 */  jal     Graph_OpenDisps              
/* 048B8 80AC7558 AFA5005C */  sw      $a1, 0x005C($sp)           
/* 048BC 80AC755C 93AF008F */  lbu     $t7, 0x008F($sp)           
/* 048C0 80AC7560 8FA8005C */  lw      $t0, 0x005C($sp)           
/* 048C4 80AC7564 8FB80078 */  lw      $t8, 0x0078($sp)           
/* 048C8 80AC7568 51E0008E */  beql    $t7, $zero, .L80AC77A4     
/* 048CC 80AC756C 8FAB0078 */  lw      $t3, 0x0078($sp)           
/* 048D0 80AC7570 8F040000 */  lw      $a0, 0x0000($t8)           ## 00000000
/* 048D4 80AC7574 0C025148 */  jal     func_80094520              
/* 048D8 80AC7578 AFA8005C */  sw      $t0, 0x005C($sp)           
/* 048DC 80AC757C 8FA8005C */  lw      $t0, 0x005C($sp)           
/* 048E0 80AC7580 8FA5007C */  lw      $a1, 0x007C($sp)           
/* 048E4 80AC7584 3C09FA00 */  lui     $t1, 0xFA00                ## $t1 = FA000000
/* 048E8 80AC7588 8D0202B0 */  lw      $v0, 0x02B0($t0)           ## 000002B0
/* 048EC 80AC758C 3C014080 */  lui     $at, 0x4080                ## $at = 40800000
/* 048F0 80AC7590 44811000 */  mtc1    $at, $f2                   ## $f2 = 4.00
/* 048F4 80AC7594 24590008 */  addiu   $t9, $v0, 0x0008           ## $t9 = 00000008
/* 048F8 80AC7598 AD1902B0 */  sw      $t9, 0x02B0($t0)           ## 000002B0
/* 048FC 80AC759C AC490000 */  sw      $t1, 0x0000($v0)           ## 00000000
/* 04900 80AC75A0 8CAD0240 */  lw      $t5, 0x0240($a1)           ## 00000240
/* 04904 80AC75A4 8CB90244 */  lw      $t9, 0x0244($a1)           ## 00000244
/* 04908 80AC75A8 8CAB023C */  lw      $t3, 0x023C($a1)           ## 0000023C
/* 0490C 80AC75AC 31AE00FF */  andi    $t6, $t5, 0x00FF           ## $t6 = 00000000
/* 04910 80AC75B0 8CAD0248 */  lw      $t5, 0x0248($a1)           ## 00000248
/* 04914 80AC75B4 000E7C00 */  sll     $t7, $t6, 16               
/* 04918 80AC75B8 332900FF */  andi    $t1, $t9, 0x00FF           ## $t1 = 00000008
/* 0491C 80AC75BC 000B6600 */  sll     $t4, $t3, 24               
/* 04920 80AC75C0 018FC025 */  or      $t8, $t4, $t7              ## $t8 = 00000000
/* 04924 80AC75C4 00095200 */  sll     $t2, $t1,  8               
/* 04928 80AC75C8 030A5825 */  or      $t3, $t8, $t2              ## $t3 = 00000000
/* 0492C 80AC75CC 31AE00FF */  andi    $t6, $t5, 0x00FF           ## $t6 = 00000000
/* 04930 80AC75D0 016E6025 */  or      $t4, $t3, $t6              ## $t4 = 00000000
/* 04934 80AC75D4 AC4C0004 */  sw      $t4, 0x0004($v0)           ## 00000004
/* 04938 80AC75D8 8D0202B0 */  lw      $v0, 0x02B0($t0)           ## 000002B0
/* 0493C 80AC75DC 3C090401 */  lui     $t1, %hi(D_0400CDC0)                ## $t1 = 04010000
/* 04940 80AC75E0 2529CDC0 */  addiu   $t1, $t1, %lo(D_0400CDC0)           ## $t1 = 0400CDC0
/* 04944 80AC75E4 244F0008 */  addiu   $t7, $v0, 0x0008           ## $t7 = 00000008
/* 04948 80AC75E8 AD0F02B0 */  sw      $t7, 0x02B0($t0)           ## 000002B0
/* 0494C 80AC75EC 3C19FD70 */  lui     $t9, 0xFD70                ## $t9 = FD700000
/* 04950 80AC75F0 AC590000 */  sw      $t9, 0x0000($v0)           ## 00000000
/* 04954 80AC75F4 AC490004 */  sw      $t1, 0x0004($v0)           ## 00000004
/* 04958 80AC75F8 8D0202B0 */  lw      $v0, 0x02B0($t0)           ## 000002B0
/* 0495C 80AC75FC 3C0D0705 */  lui     $t5, 0x0705                ## $t5 = 07050000
/* 04960 80AC7600 35AD0140 */  ori     $t5, $t5, 0x0140           ## $t5 = 07050140
/* 04964 80AC7604 24580008 */  addiu   $t8, $v0, 0x0008           ## $t8 = 00000008
/* 04968 80AC7608 AD1802B0 */  sw      $t8, 0x02B0($t0)           ## 000002B0
/* 0496C 80AC760C 3C0AF570 */  lui     $t2, 0xF570                ## $t2 = F5700000
/* 04970 80AC7610 AC4A0000 */  sw      $t2, 0x0000($v0)           ## 00000000
/* 04974 80AC7614 AC4D0004 */  sw      $t5, 0x0004($v0)           ## 00000004
/* 04978 80AC7618 8D0202B0 */  lw      $v0, 0x02B0($t0)           ## 000002B0
/* 0497C 80AC761C 3C0EE600 */  lui     $t6, 0xE600                ## $t6 = E6000000
/* 04980 80AC7620 3C190703 */  lui     $t9, 0x0703                ## $t9 = 07030000
/* 04984 80AC7624 244B0008 */  addiu   $t3, $v0, 0x0008           ## $t3 = 00000008
/* 04988 80AC7628 AD0B02B0 */  sw      $t3, 0x02B0($t0)           ## 000002B0
/* 0498C 80AC762C AC400004 */  sw      $zero, 0x0004($v0)         ## 00000004
/* 04990 80AC7630 AC4E0000 */  sw      $t6, 0x0000($v0)           ## 00000000
/* 04994 80AC7634 8D0202B0 */  lw      $v0, 0x02B0($t0)           ## 000002B0
/* 04998 80AC7638 3739F800 */  ori     $t9, $t9, 0xF800           ## $t9 = 0703F800
/* 0499C 80AC763C 3C0FF300 */  lui     $t7, 0xF300                ## $t7 = F3000000
/* 049A0 80AC7640 244C0008 */  addiu   $t4, $v0, 0x0008           ## $t4 = 00000008
/* 049A4 80AC7644 AD0C02B0 */  sw      $t4, 0x02B0($t0)           ## 000002B0
/* 049A8 80AC7648 AC590004 */  sw      $t9, 0x0004($v0)           ## 00000004
/* 049AC 80AC764C AC4F0000 */  sw      $t7, 0x0000($v0)           ## 00000000
/* 049B0 80AC7650 8D0202B0 */  lw      $v0, 0x02B0($t0)           ## 000002B0
/* 049B4 80AC7654 3C18E700 */  lui     $t8, 0xE700                ## $t8 = E7000000
/* 049B8 80AC7658 3C0B0005 */  lui     $t3, 0x0005                ## $t3 = 00050000
/* 049BC 80AC765C 24490008 */  addiu   $t1, $v0, 0x0008           ## $t1 = 00000008
/* 049C0 80AC7660 AD0902B0 */  sw      $t1, 0x02B0($t0)           ## 000002B0
/* 049C4 80AC7664 AC400004 */  sw      $zero, 0x0004($v0)         ## 00000004
/* 049C8 80AC7668 AC580000 */  sw      $t8, 0x0000($v0)           ## 00000000
/* 049CC 80AC766C 8D0202B0 */  lw      $v0, 0x02B0($t0)           ## 000002B0
/* 049D0 80AC7670 3C0DF560 */  lui     $t5, 0xF560                ## $t5 = F5600000
/* 049D4 80AC7674 35AD0200 */  ori     $t5, $t5, 0x0200           ## $t5 = F5600200
/* 049D8 80AC7678 244A0008 */  addiu   $t2, $v0, 0x0008           ## $t2 = 00000008
/* 049DC 80AC767C AD0A02B0 */  sw      $t2, 0x02B0($t0)           ## 000002B0
/* 049E0 80AC7680 356B0140 */  ori     $t3, $t3, 0x0140           ## $t3 = 00050140
/* 049E4 80AC7684 AC4B0004 */  sw      $t3, 0x0004($v0)           ## 00000004
/* 049E8 80AC7688 AC4D0000 */  sw      $t5, 0x0000($v0)           ## 00000000
/* 049EC 80AC768C 8D0202B0 */  lw      $v0, 0x02B0($t0)           ## 000002B0
/* 049F0 80AC7690 3C0F0003 */  lui     $t7, 0x0003                ## $t7 = 00030000
/* 049F4 80AC7694 35EFC03C */  ori     $t7, $t7, 0xC03C           ## $t7 = 0003C03C
/* 049F8 80AC7698 244E0008 */  addiu   $t6, $v0, 0x0008           ## $t6 = 00000008
/* 049FC 80AC769C AD0E02B0 */  sw      $t6, 0x02B0($t0)           ## 000002B0
/* 04A00 80AC76A0 3C0CF200 */  lui     $t4, 0xF200                ## $t4 = F2000000
/* 04A04 80AC76A4 3C014180 */  lui     $at, 0x4180                ## $at = 41800000
/* 04A08 80AC76A8 AC4C0000 */  sw      $t4, 0x0000($v0)           ## 00000000
/* 04A0C 80AC76AC AC4F0004 */  sw      $t7, 0x0004($v0)           ## 00000004
/* 04A10 80AC76B0 C7AC0088 */  lwc1    $f12, 0x0088($sp)          
/* 04A14 80AC76B4 44812000 */  mtc1    $at, $f4                   ## $f4 = 16.00
/* 04A18 80AC76B8 C7AE0080 */  lwc1    $f14, 0x0080($sp)          
/* 04A1C 80AC76BC C7B00084 */  lwc1    $f16, 0x0084($sp)          
/* 04A20 80AC76C0 460C2002 */  mul.s   $f0, $f4, $f12             
/* 04A24 80AC76C4 3C01E400 */  lui     $at, 0xE400                ## $at = E4000000
/* 04A28 80AC76C8 8D0202B0 */  lw      $v0, 0x02B0($t0)           ## 000002B0
/* 04A2C 80AC76CC 3C09E100 */  lui     $t1, 0xE100                ## $t1 = E1000000
/* 04A30 80AC76D0 24590008 */  addiu   $t9, $v0, 0x0008           ## $t9 = 00000008
/* 04A34 80AC76D4 AD1902B0 */  sw      $t9, 0x02B0($t0)           ## 000002B0
/* 04A38 80AC76D8 46007180 */  add.s   $f6, $f14, $f0             
/* 04A3C 80AC76DC 46008480 */  add.s   $f18, $f16, $f0            
/* 04A40 80AC76E0 46023202 */  mul.s   $f8, $f6, $f2              
/* 04A44 80AC76E4 4600428D */  trunc.w.s $f10, $f8                  
/* 04A48 80AC76E8 46029102 */  mul.s   $f4, $f18, $f2             
/* 04A4C 80AC76EC 46007201 */  sub.s   $f8, $f14, $f0             
/* 04A50 80AC76F0 44185000 */  mfc1    $t8, $f10                  
/* 04A54 80AC76F4 46024282 */  mul.s   $f10, $f8, $f2             
/* 04A58 80AC76F8 330A0FFF */  andi    $t2, $t8, 0x0FFF           ## $t2 = 00000000
/* 04A5C 80AC76FC 000A6B00 */  sll     $t5, $t2, 12               
/* 04A60 80AC7700 01A15825 */  or      $t3, $t5, $at              ## $t3 = F5600200
/* 04A64 80AC7704 3C013F80 */  lui     $at, 0x3F80                ## $at = 3F800000
/* 04A68 80AC7708 4600218D */  trunc.w.s $f6, $f4                   
/* 04A6C 80AC770C 4600548D */  trunc.w.s $f18, $f10                 
/* 04A70 80AC7710 44815000 */  mtc1    $at, $f10                  ## $f10 = 1.00
/* 04A74 80AC7714 440C3000 */  mfc1    $t4, $f6                   
/* 04A78 80AC7718 46008101 */  sub.s   $f4, $f16, $f0             
/* 04A7C 80AC771C 44189000 */  mfc1    $t8, $f18                  
/* 04A80 80AC7720 3C014480 */  lui     $at, 0x4480                ## $at = 44800000
/* 04A84 80AC7724 460C5483 */  div.s   $f18, $f10, $f12           
/* 04A88 80AC7728 318F0FFF */  andi    $t7, $t4, 0x0FFF           ## $t7 = 00000000
/* 04A8C 80AC772C 016FC825 */  or      $t9, $t3, $t7              ## $t9 = F5600200
/* 04A90 80AC7730 330A0FFF */  andi    $t2, $t8, 0x0FFF           ## $t2 = 00000000
/* 04A94 80AC7734 46022182 */  mul.s   $f6, $f4, $f2              
/* 04A98 80AC7738 44812000 */  mtc1    $at, $f4                   ## $f4 = 1024.00
/* 04A9C 80AC773C 000A6B00 */  sll     $t5, $t2, 12               
/* 04AA0 80AC7740 AC590000 */  sw      $t9, 0x0000($v0)           ## 00000000
/* 04AA4 80AC7744 3C0AF100 */  lui     $t2, 0xF100                ## $t2 = F1000000
/* 04AA8 80AC7748 4600320D */  trunc.w.s $f8, $f6                   
/* 04AAC 80AC774C 46049182 */  mul.s   $f6, $f18, $f4             
/* 04AB0 80AC7750 440C4000 */  mfc1    $t4, $f8                   
/* 04AB4 80AC7754 00000000 */  nop
/* 04AB8 80AC7758 318B0FFF */  andi    $t3, $t4, 0x0FFF           ## $t3 = 00000000
/* 04ABC 80AC775C 01AB7825 */  or      $t7, $t5, $t3              ## $t7 = F5600200
/* 04AC0 80AC7760 AC4F0004 */  sw      $t7, 0x0004($v0)           ## 00000004
/* 04AC4 80AC7764 8D0202B0 */  lw      $v0, 0x02B0($t0)           ## 000002B0
/* 04AC8 80AC7768 4600320D */  trunc.w.s $f8, $f6                   
/* 04ACC 80AC776C 24590008 */  addiu   $t9, $v0, 0x0008           ## $t9 = 00000008
/* 04AD0 80AC7770 AD1902B0 */  sw      $t9, 0x02B0($t0)           ## 000002B0
/* 04AD4 80AC7774 AC400004 */  sw      $zero, 0x0004($v0)         ## 00000004
/* 04AD8 80AC7778 AC490000 */  sw      $t1, 0x0000($v0)           ## 00000000
/* 04ADC 80AC777C 44044000 */  mfc1    $a0, $f8                   
/* 04AE0 80AC7780 8D0202B0 */  lw      $v0, 0x02B0($t0)           ## 000002B0
/* 04AE4 80AC7784 3084FFFF */  andi    $a0, $a0, 0xFFFF           ## $a0 = 00000000
/* 04AE8 80AC7788 24580008 */  addiu   $t8, $v0, 0x0008           ## $t8 = 00000008
/* 04AEC 80AC778C 00046400 */  sll     $t4, $a0, 16               
/* 04AF0 80AC7790 AD1802B0 */  sw      $t8, 0x02B0($t0)           ## 000002B0
/* 04AF4 80AC7794 01846825 */  or      $t5, $t4, $a0              ## $t5 = F2000000
/* 04AF8 80AC7798 AC4D0004 */  sw      $t5, 0x0004($v0)           ## 00000004
/* 04AFC 80AC779C AC4A0000 */  sw      $t2, 0x0000($v0)           ## 00000000
/* 04B00 80AC77A0 8FAB0078 */  lw      $t3, 0x0078($sp)           
.L80AC77A4:
/* 04B04 80AC77A4 3C0680AD */  lui     $a2, %hi(D_80AC93AC)       ## $a2 = 80AD0000
/* 04B08 80AC77A8 24C693AC */  addiu   $a2, $a2, %lo(D_80AC93AC)  ## $a2 = 80AC93AC
/* 04B0C 80AC77AC 27A4004C */  addiu   $a0, $sp, 0x004C           ## $a0 = FFFFFFD4
/* 04B10 80AC77B0 24071077 */  addiu   $a3, $zero, 0x1077         ## $a3 = 00001077
/* 04B14 80AC77B4 0C031AD5 */  jal     Graph_CloseDisps              
/* 04B18 80AC77B8 8D650000 */  lw      $a1, 0x0000($t3)           ## 00000000
/* 04B1C 80AC77BC 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 04B20 80AC77C0 27BD0078 */  addiu   $sp, $sp, 0x0078           ## $sp = 00000000
/* 04B24 80AC77C4 03E00008 */  jr      $ra                        
/* 04B28 80AC77C8 00000000 */  nop
