.rdata
glabel D_80A4B8A0
    .asciz "../z_en_goma.c"
    .balign 4

glabel D_80A4B8B0
    .asciz "../z_en_goma.c"
    .balign 4

glabel D_80A4B8C0
    .asciz "../z_en_goma.c"
    .balign 4

glabel D_80A4B8D0
    .asciz "../z_en_goma.c"
    .balign 4

glabel D_80A4B8E0
    .asciz "../z_en_goma.c"
    .balign 4

.late_rodata
glabel D_80A4B94C
    .float 3.14159274101

glabel D_80A4B950
    .float 3.14159274101

glabel D_80A4B954
    .float 3.14159274101

glabel D_80A4B958
    .float 3.14159274101

glabel D_80A4B95C
    .float 3.14159274101

glabel D_80A4B960
 .word 0x40490E56
glabel D_80A4B964
 .word 0x41FF3333
glabel D_80A4B968
    .float 0.15

glabel D_80A4B96C
    .float 0.1

glabel D_80A4B970
 .word 0x3F733333
glabel D_80A4B974
 .word 0x3F866666
glabel D_80A4B978
    .float 0.1

glabel D_80A4B97C
    .float 0.15

.text
glabel EnGoma_Draw
/* 02018 80A4AED8 27BDFF88 */  addiu   $sp, $sp, 0xFF88           ## $sp = FFFFFF88
/* 0201C 80A4AEDC AFBF0024 */  sw      $ra, 0x0024($sp)           
/* 02020 80A4AEE0 AFB10020 */  sw      $s1, 0x0020($sp)           
/* 02024 80A4AEE4 AFB0001C */  sw      $s0, 0x001C($sp)           
/* 02028 80A4AEE8 AFA5007C */  sw      $a1, 0x007C($sp)           
/* 0202C 80A4AEEC 8CA50000 */  lw      $a1, 0x0000($a1)           ## 00000000
/* 02030 80A4AEF0 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 02034 80A4AEF4 3C0680A5 */  lui     $a2, %hi(D_80A4B8A0)       ## $a2 = 80A50000
/* 02038 80A4AEF8 24C6B8A0 */  addiu   $a2, $a2, %lo(D_80A4B8A0)  ## $a2 = 80A4B8A0
/* 0203C 80A4AEFC 27A40058 */  addiu   $a0, $sp, 0x0058           ## $a0 = FFFFFFE0
/* 02040 80A4AF00 240707F8 */  addiu   $a3, $zero, 0x07F8         ## $a3 = 000007F8
/* 02044 80A4AF04 0C031AB1 */  jal     Graph_OpenDisps              
/* 02048 80A4AF08 00A08825 */  or      $s1, $a1, $zero            ## $s1 = 00000000
/* 0204C 80A4AF0C 8FAF007C */  lw      $t7, 0x007C($sp)           
/* 02050 80A4AF10 0C024F46 */  jal     func_80093D18              
/* 02054 80A4AF14 8DE40000 */  lw      $a0, 0x0000($t7)           ## 00000000
/* 02058 80A4AF18 860202B8 */  lh      $v0, 0x02B8($s0)           ## 000002B8
/* 0205C 80A4AF1C 1040000A */  beq     $v0, $zero, .L80A4AF48     
/* 02060 80A4AF20 24010001 */  addiu   $at, $zero, 0x0001         ## $at = 00000001
/* 02064 80A4AF24 10410061 */  beq     $v0, $at, .L80A4B0AC       
/* 02068 80A4AF28 24010002 */  addiu   $at, $zero, 0x0002         ## $at = 00000002
/* 0206C 80A4AF2C 104100D8 */  beq     $v0, $at, .L80A4B290       
/* 02070 80A4AF30 3C18DA38 */  lui     $t8, 0xDA38                ## $t8 = DA380000
/* 02074 80A4AF34 24010003 */  addiu   $at, $zero, 0x0003         ## $at = 00000003
/* 02078 80A4AF38 504100EC */  beql    $v0, $at, .L80A4B2EC       
/* 0207C 80A4AF3C 8E0B0308 */  lw      $t3, 0x0308($s0)           ## 00000308
/* 02080 80A4AF40 1000010F */  beq     $zero, $zero, .L80A4B380   
/* 02084 80A4AF44 8FAB007C */  lw      $t3, 0x007C($sp)           
.L80A4AF48:
/* 02088 80A4AF48 C60400BC */  lwc1    $f4, 0x00BC($s0)           ## 000000BC
/* 0208C 80A4AF4C C6060054 */  lwc1    $f6, 0x0054($s0)           ## 00000054
/* 02090 80A4AF50 24180003 */  addiu   $t8, $zero, 0x0003         ## $t8 = 00000003
/* 02094 80A4AF54 A2180117 */  sb      $t8, 0x0117($s0)           ## 00000117
/* 02098 80A4AF58 46062202 */  mul.s   $f8, $f4, $f6              
/* 0209C 80A4AF5C 8FB9007C */  lw      $t9, 0x007C($sp)           
/* 020A0 80A4AF60 C6120028 */  lwc1    $f18, 0x0028($s0)          ## 00000028
/* 020A4 80A4AF64 C60C0024 */  lwc1    $f12, 0x0024($s0)          ## 00000024
/* 020A8 80A4AF68 C72A0264 */  lwc1    $f10, 0x0264($t9)          ## 00000264
/* 020AC 80A4AF6C 8E06002C */  lw      $a2, 0x002C($s0)           ## 0000002C
/* 020B0 80A4AF70 00003825 */  or      $a3, $zero, $zero          ## $a3 = 00000000
/* 020B4 80A4AF74 460A4400 */  add.s   $f16, $f8, $f10            
/* 020B8 80A4AF78 0C034261 */  jal     Matrix_Translate              
/* 020BC 80A4AF7C 46109380 */  add.s   $f14, $f18, $f16           
/* 020C0 80A4AF80 860802B4 */  lh      $t0, 0x02B4($s0)           ## 000002B4
/* 020C4 80A4AF84 3C014700 */  lui     $at, 0x4700                ## $at = 47000000
/* 020C8 80A4AF88 44814000 */  mtc1    $at, $f8                   ## $f8 = 32768.00
/* 020CC 80A4AF8C 44882000 */  mtc1    $t0, $f4                   ## $f4 = 0.00
/* 020D0 80A4AF90 3C0180A5 */  lui     $at, %hi(D_80A4B94C)       ## $at = 80A50000
/* 020D4 80A4AF94 C432B94C */  lwc1    $f18, %lo(D_80A4B94C)($at) 
/* 020D8 80A4AF98 468021A0 */  cvt.s.w $f6, $f4                   
/* 020DC 80A4AF9C 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 020E0 80A4AFA0 46083283 */  div.s   $f10, $f6, $f8             
/* 020E4 80A4AFA4 46125302 */  mul.s   $f12, $f10, $f18           
/* 020E8 80A4AFA8 0C0342DC */  jal     Matrix_RotateX              
/* 020EC 80A4AFAC 00000000 */  nop
/* 020F0 80A4AFB0 860902B6 */  lh      $t1, 0x02B6($s0)           ## 000002B6
/* 020F4 80A4AFB4 3C014700 */  lui     $at, 0x4700                ## $at = 47000000
/* 020F8 80A4AFB8 44813000 */  mtc1    $at, $f6                   ## $f6 = 32768.00
/* 020FC 80A4AFBC 44898000 */  mtc1    $t1, $f16                  ## $f16 = 0.00
/* 02100 80A4AFC0 3C0180A5 */  lui     $at, %hi(D_80A4B950)       ## $at = 80A50000
/* 02104 80A4AFC4 C42AB950 */  lwc1    $f10, %lo(D_80A4B950)($at) 
/* 02108 80A4AFC8 46808120 */  cvt.s.w $f4, $f16                  
/* 0210C 80A4AFCC 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 02110 80A4AFD0 46062203 */  div.s   $f8, $f4, $f6              
/* 02114 80A4AFD4 460A4302 */  mul.s   $f12, $f8, $f10            
/* 02118 80A4AFD8 0C0343B5 */  jal     Matrix_RotateZ              
/* 0211C 80A4AFDC 00000000 */  nop
/* 02120 80A4AFE0 860A00B6 */  lh      $t2, 0x00B6($s0)           ## 000000B6
/* 02124 80A4AFE4 3C014700 */  lui     $at, 0x4700                ## $at = 47000000
/* 02128 80A4AFE8 44812000 */  mtc1    $at, $f4                   ## $f4 = 32768.00
/* 0212C 80A4AFEC 448A9000 */  mtc1    $t2, $f18                  ## $f18 = 0.00
/* 02130 80A4AFF0 3C0180A5 */  lui     $at, %hi(D_80A4B954)       ## $at = 80A50000
/* 02134 80A4AFF4 C428B954 */  lwc1    $f8, %lo(D_80A4B954)($at)  
/* 02138 80A4AFF8 46809420 */  cvt.s.w $f16, $f18                 
/* 0213C 80A4AFFC 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 02140 80A4B000 46048183 */  div.s   $f6, $f16, $f4             
/* 02144 80A4B004 46083302 */  mul.s   $f12, $f6, $f8             
/* 02148 80A4B008 0C034348 */  jal     Matrix_RotateY              
/* 0214C 80A4B00C 00000000 */  nop
/* 02150 80A4B010 860B00B4 */  lh      $t3, 0x00B4($s0)           ## 000000B4
/* 02154 80A4B014 3C014700 */  lui     $at, 0x4700                ## $at = 47000000
/* 02158 80A4B018 44818000 */  mtc1    $at, $f16                  ## $f16 = 32768.00
/* 0215C 80A4B01C 448B5000 */  mtc1    $t3, $f10                  ## $f10 = 0.00
/* 02160 80A4B020 3C0180A5 */  lui     $at, %hi(D_80A4B958)       ## $at = 80A50000
/* 02164 80A4B024 C426B958 */  lwc1    $f6, %lo(D_80A4B958)($at)  
/* 02168 80A4B028 468054A0 */  cvt.s.w $f18, $f10                 
/* 0216C 80A4B02C 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 02170 80A4B030 46109103 */  div.s   $f4, $f18, $f16            
/* 02174 80A4B034 46062302 */  mul.s   $f12, $f4, $f6             
/* 02178 80A4B038 0C0342DC */  jal     Matrix_RotateX              
/* 0217C 80A4B03C 00000000 */  nop
/* 02180 80A4B040 860C00B8 */  lh      $t4, 0x00B8($s0)           ## 000000B8
/* 02184 80A4B044 3C014700 */  lui     $at, 0x4700                ## $at = 47000000
/* 02188 80A4B048 44819000 */  mtc1    $at, $f18                  ## $f18 = 32768.00
/* 0218C 80A4B04C 448C4000 */  mtc1    $t4, $f8                   ## $f8 = 0.00
/* 02190 80A4B050 3C0180A5 */  lui     $at, %hi(D_80A4B95C)       ## $at = 80A50000
/* 02194 80A4B054 C424B95C */  lwc1    $f4, %lo(D_80A4B95C)($at)  
/* 02198 80A4B058 468042A0 */  cvt.s.w $f10, $f8                  
/* 0219C 80A4B05C 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 021A0 80A4B060 46125403 */  div.s   $f16, $f10, $f18           
/* 021A4 80A4B064 46048302 */  mul.s   $f12, $f16, $f4            
/* 021A8 80A4B068 0C0343B5 */  jal     Matrix_RotateZ              
/* 021AC 80A4B06C 00000000 */  nop
/* 021B0 80A4B070 C60C0050 */  lwc1    $f12, 0x0050($s0)          ## 00000050
/* 021B4 80A4B074 C60E0054 */  lwc1    $f14, 0x0054($s0)          ## 00000054
/* 021B8 80A4B078 8E060058 */  lw      $a2, 0x0058($s0)           ## 00000058
/* 021BC 80A4B07C 0C0342A3 */  jal     Matrix_Scale              
/* 021C0 80A4B080 24070001 */  addiu   $a3, $zero, 0x0001         ## $a3 = 00000001
/* 021C4 80A4B084 8E050150 */  lw      $a1, 0x0150($s0)           ## 00000150
/* 021C8 80A4B088 8E06016C */  lw      $a2, 0x016C($s0)           ## 0000016C
/* 021CC 80A4B08C 3C0780A5 */  lui     $a3, %hi(func_80A4ACC0)    ## $a3 = 80A50000
/* 021D0 80A4B090 24E7ACC0 */  addiu   $a3, $a3, %lo(func_80A4ACC0) ## $a3 = 80A4ACC0
/* 021D4 80A4B094 AFB00014 */  sw      $s0, 0x0014($sp)           
/* 021D8 80A4B098 AFA00010 */  sw      $zero, 0x0010($sp)         
/* 021DC 80A4B09C 0C028572 */  jal     SkelAnime_DrawOpa
              
/* 021E0 80A4B0A0 8FA4007C */  lw      $a0, 0x007C($sp)           
/* 021E4 80A4B0A4 100000B6 */  beq     $zero, $zero, .L80A4B380   
/* 021E8 80A4B0A8 8FAB007C */  lw      $t3, 0x007C($sp)           
.L80A4B0AC:
/* 021EC 80A4B0AC 860E02C0 */  lh      $t6, 0x02C0($s0)           ## 000002C0
/* 021F0 80A4B0B0 3C0140A0 */  lui     $at, 0x40A0                ## $at = 40A00000
/* 021F4 80A4B0B4 44815000 */  mtc1    $at, $f10                  ## $f10 = 5.00
/* 021F8 80A4B0B8 448E3000 */  mtc1    $t6, $f6                   ## $f6 = 0.00
/* 021FC 80A4B0BC 240D0002 */  addiu   $t5, $zero, 0x0002         ## $t5 = 00000002
/* 02200 80A4B0C0 A20D0117 */  sb      $t5, 0x0117($s0)           ## 00000117
/* 02204 80A4B0C4 46803220 */  cvt.s.w $f8, $f6                   
/* 02208 80A4B0C8 3C0180A5 */  lui     $at, %hi(D_80A4B960)       ## $at = 80A50000
/* 0220C 80A4B0CC C430B960 */  lwc1    $f16, %lo(D_80A4B960)($at) 
/* 02210 80A4B0D0 3C014334 */  lui     $at, 0x4334                ## $at = 43340000
/* 02214 80A4B0D4 44813000 */  mtc1    $at, $f6                   ## $f6 = 180.00
/* 02218 80A4B0D8 460A4482 */  mul.s   $f18, $f8, $f10            
/* 0221C 80A4B0DC 00000000 */  nop
/* 02220 80A4B0E0 46109102 */  mul.s   $f4, $f18, $f16            
/* 02224 80A4B0E4 0C0400A4 */  jal     sinf
              
/* 02228 80A4B0E8 46062303 */  div.s   $f12, $f4, $f6             
/* 0222C 80A4B0EC 3C0180A5 */  lui     $at, %hi(D_80A4B964)       ## $at = 80A50000
/* 02230 80A4B0F0 C428B964 */  lwc1    $f8, %lo(D_80A4B964)($at)  
/* 02234 80A4B0F4 8E2202C0 */  lw      $v0, 0x02C0($s1)           ## 000002C0
/* 02238 80A4B0F8 3C19DB06 */  lui     $t9, 0xDB06                ## $t9 = DB060000
/* 0223C 80A4B0FC 46080282 */  mul.s   $f10, $f0, $f8             
/* 02240 80A4B100 24580008 */  addiu   $t8, $v0, 0x0008           ## $t8 = 00000008
/* 02244 80A4B104 AE3802C0 */  sw      $t8, 0x02C0($s1)           ## 000002C0
/* 02248 80A4B108 37390020 */  ori     $t9, $t9, 0x0020           ## $t9 = DB060020
/* 0224C 80A4B10C AC590000 */  sw      $t9, 0x0000($v0)           ## 00000000
/* 02250 80A4B110 8FA8007C */  lw      $t0, 0x007C($sp)           
/* 02254 80A4B114 00002825 */  or      $a1, $zero, $zero          ## $a1 = 00000000
/* 02258 80A4B118 4600548D */  trunc.w.s $f18, $f10                 
/* 0225C 80A4B11C 8D040000 */  lw      $a0, 0x0000($t0)           ## 00000000
/* 02260 80A4B120 AFA20054 */  sw      $v0, 0x0054($sp)           
/* 02264 80A4B124 44069000 */  mfc1    $a2, $f18                  
/* 02268 80A4B128 00000000 */  nop
/* 0226C 80A4B12C 00063400 */  sll     $a2, $a2, 16               
/* 02270 80A4B130 00063403 */  sra     $a2, $a2, 16               
/* 02274 80A4B134 24C6001F */  addiu   $a2, $a2, 0x001F           ## $a2 = 0000001F
/* 02278 80A4B138 00063400 */  sll     $a2, $a2, 16               
/* 0227C 80A4B13C 0C02539E */  jal     func_80094E78              
/* 02280 80A4B140 00063403 */  sra     $a2, $a2, 16               
/* 02284 80A4B144 8FA30054 */  lw      $v1, 0x0054($sp)           
/* 02288 80A4B148 0C034213 */  jal     Matrix_Push              
/* 0228C 80A4B14C AC620004 */  sw      $v0, 0x0004($v1)           ## 00000004
/* 02290 80A4B150 C60C02D0 */  lwc1    $f12, 0x02D0($s0)          ## 000002D0
/* 02294 80A4B154 3C013F80 */  lui     $at, 0x3F80                ## $at = 3F800000
/* 02298 80A4B158 44818000 */  mtc1    $at, $f16                  ## $f16 = 1.00
/* 0229C 80A4B15C 44066000 */  mfc1    $a2, $f12                  
/* 022A0 80A4B160 24070001 */  addiu   $a3, $zero, 0x0001         ## $a3 = 00000001
/* 022A4 80A4B164 0C0342A3 */  jal     Matrix_Scale              
/* 022A8 80A4B168 460C8383 */  div.s   $f14, $f16, $f12           
/* 022AC 80A4B16C 3C0180A5 */  lui     $at, %hi(D_80A4B968)       ## $at = 80A50000
/* 022B0 80A4B170 C426B968 */  lwc1    $f6, %lo(D_80A4B968)($at)  
/* 022B4 80A4B174 C60402D8 */  lwc1    $f4, 0x02D8($s0)           ## 000002D8
/* 022B8 80A4B178 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 022BC 80A4B17C 46062302 */  mul.s   $f12, $f4, $f6             
/* 022C0 80A4B180 0C034348 */  jal     Matrix_RotateY              
/* 022C4 80A4B184 00000000 */  nop
/* 022C8 80A4B188 3C0180A5 */  lui     $at, %hi(D_80A4B96C)       ## $at = 80A50000
/* 022CC 80A4B18C C42AB96C */  lwc1    $f10, %lo(D_80A4B96C)($at) 
/* 022D0 80A4B190 C60802D8 */  lwc1    $f8, 0x02D8($s0)           ## 000002D8
/* 022D4 80A4B194 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 022D8 80A4B198 460A4302 */  mul.s   $f12, $f8, $f10            
/* 022DC 80A4B19C 0C0343B5 */  jal     Matrix_RotateZ              
/* 022E0 80A4B1A0 00000000 */  nop
/* 022E4 80A4B1A4 3C0180A5 */  lui     $at, %hi(D_80A4B970)       ## $at = 80A50000
/* 022E8 80A4B1A8 C432B970 */  lwc1    $f18, %lo(D_80A4B970)($at) 
/* 022EC 80A4B1AC C60002EC */  lwc1    $f0, 0x02EC($s0)           ## 000002EC
/* 022F0 80A4B1B0 3C0180A5 */  lui     $at, %hi(D_80A4B974)       ## $at = 80A50000
/* 022F4 80A4B1B4 C430B974 */  lwc1    $f16, %lo(D_80A4B974)($at) 
/* 022F8 80A4B1B8 46009301 */  sub.s   $f12, $f18, $f0            
/* 022FC 80A4B1BC 24070001 */  addiu   $a3, $zero, 0x0001         ## $a3 = 00000001
/* 02300 80A4B1C0 46100380 */  add.s   $f14, $f0, $f16            
/* 02304 80A4B1C4 44066000 */  mfc1    $a2, $f12                  
/* 02308 80A4B1C8 0C0342A3 */  jal     Matrix_Scale              
/* 0230C 80A4B1CC 00000000 */  nop
/* 02310 80A4B1D0 3C0180A5 */  lui     $at, %hi(D_80A4B978)       ## $at = 80A50000
/* 02314 80A4B1D4 C426B978 */  lwc1    $f6, %lo(D_80A4B978)($at)  
/* 02318 80A4B1D8 C60402D8 */  lwc1    $f4, 0x02D8($s0)           ## 000002D8
/* 0231C 80A4B1DC 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 02320 80A4B1E0 46062302 */  mul.s   $f12, $f4, $f6             
/* 02324 80A4B1E4 0C0343B5 */  jal     Matrix_RotateZ              
/* 02328 80A4B1E8 46006307 */  neg.s   $f12, $f12                 
/* 0232C 80A4B1EC 3C0180A5 */  lui     $at, %hi(D_80A4B97C)       ## $at = 80A50000
/* 02330 80A4B1F0 C42AB97C */  lwc1    $f10, %lo(D_80A4B97C)($at) 
/* 02334 80A4B1F4 C60802D8 */  lwc1    $f8, 0x02D8($s0)           ## 000002D8
/* 02338 80A4B1F8 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 0233C 80A4B1FC 460A4302 */  mul.s   $f12, $f8, $f10            
/* 02340 80A4B200 0C034348 */  jal     Matrix_RotateY              
/* 02344 80A4B204 46006307 */  neg.s   $f12, $f12                 
/* 02348 80A4B208 44806000 */  mtc1    $zero, $f12                ## $f12 = 0.00
/* 0234C 80A4B20C C60E02F0 */  lwc1    $f14, 0x02F0($s0)          ## 000002F0
/* 02350 80A4B210 24070001 */  addiu   $a3, $zero, 0x0001         ## $a3 = 00000001
/* 02354 80A4B214 44066000 */  mfc1    $a2, $f12                  
/* 02358 80A4B218 0C034261 */  jal     Matrix_Translate              
/* 0235C 80A4B21C 00000000 */  nop
/* 02360 80A4B220 C60C02D4 */  lwc1    $f12, 0x02D4($s0)          ## 000002D4
/* 02364 80A4B224 0C0342DC */  jal     Matrix_RotateX              
/* 02368 80A4B228 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 0236C 80A4B22C 8E2202C0 */  lw      $v0, 0x02C0($s1)           ## 000002C0
/* 02370 80A4B230 3C0ADA38 */  lui     $t2, 0xDA38                ## $t2 = DA380000
/* 02374 80A4B234 354A0003 */  ori     $t2, $t2, 0x0003           ## $t2 = DA380003
/* 02378 80A4B238 24490008 */  addiu   $t1, $v0, 0x0008           ## $t1 = 00000008
/* 0237C 80A4B23C AE2902C0 */  sw      $t1, 0x02C0($s1)           ## 000002C0
/* 02380 80A4B240 AC4A0000 */  sw      $t2, 0x0000($v0)           ## 00000000
/* 02384 80A4B244 8FAB007C */  lw      $t3, 0x007C($sp)           
/* 02388 80A4B248 3C0580A5 */  lui     $a1, %hi(D_80A4B8B0)       ## $a1 = 80A50000
/* 0238C 80A4B24C 24A5B8B0 */  addiu   $a1, $a1, %lo(D_80A4B8B0)  ## $a1 = 80A4B8B0
/* 02390 80A4B250 24060835 */  addiu   $a2, $zero, 0x0835         ## $a2 = 00000835
/* 02394 80A4B254 00408025 */  or      $s0, $v0, $zero            ## $s0 = 00000000
/* 02398 80A4B258 0C0346A2 */  jal     Matrix_NewMtx              
/* 0239C 80A4B25C 8D640000 */  lw      $a0, 0x0000($t3)           ## 00000000
/* 023A0 80A4B260 AE020004 */  sw      $v0, 0x0004($s0)           ## 00000004
/* 023A4 80A4B264 8E2202C0 */  lw      $v0, 0x02C0($s1)           ## 000002C0
/* 023A8 80A4B268 3C0E0600 */  lui     $t6, %hi(D_06002A70)                ## $t6 = 06000000
/* 023AC 80A4B26C 25CE2A70 */  addiu   $t6, $t6, %lo(D_06002A70)           ## $t6 = 06002A70
/* 023B0 80A4B270 244C0008 */  addiu   $t4, $v0, 0x0008           ## $t4 = 00000008
/* 023B4 80A4B274 AE2C02C0 */  sw      $t4, 0x02C0($s1)           ## 000002C0
/* 023B8 80A4B278 3C0DDE00 */  lui     $t5, 0xDE00                ## $t5 = DE000000
/* 023BC 80A4B27C AC4D0000 */  sw      $t5, 0x0000($v0)           ## 00000000
/* 023C0 80A4B280 0C034221 */  jal     Matrix_Pull              
/* 023C4 80A4B284 AC4E0004 */  sw      $t6, 0x0004($v0)           ## 00000004
/* 023C8 80A4B288 1000003D */  beq     $zero, $zero, .L80A4B380   
/* 023CC 80A4B28C 8FAB007C */  lw      $t3, 0x007C($sp)           
.L80A4B290:
/* 023D0 80A4B290 8E2202C0 */  lw      $v0, 0x02C0($s1)           ## 000002C0
/* 023D4 80A4B294 37180003 */  ori     $t8, $t8, 0x0003           ## $t8 = 00000003
/* 023D8 80A4B298 3C0580A5 */  lui     $a1, %hi(D_80A4B8C0)       ## $a1 = 80A50000
/* 023DC 80A4B29C 244F0008 */  addiu   $t7, $v0, 0x0008           ## $t7 = 00000008
/* 023E0 80A4B2A0 AE2F02C0 */  sw      $t7, 0x02C0($s1)           ## 000002C0
/* 023E4 80A4B2A4 AC580000 */  sw      $t8, 0x0000($v0)           ## 00000000
/* 023E8 80A4B2A8 8FB9007C */  lw      $t9, 0x007C($sp)           
/* 023EC 80A4B2AC 24A5B8C0 */  addiu   $a1, $a1, %lo(D_80A4B8C0)  ## $a1 = 80A4B8C0
/* 023F0 80A4B2B0 2406083B */  addiu   $a2, $zero, 0x083B         ## $a2 = 0000083B
/* 023F4 80A4B2B4 00408025 */  or      $s0, $v0, $zero            ## $s0 = 00000000
/* 023F8 80A4B2B8 0C0346A2 */  jal     Matrix_NewMtx              
/* 023FC 80A4B2BC 8F240000 */  lw      $a0, 0x0000($t9)           ## 00000000
/* 02400 80A4B2C0 AE020004 */  sw      $v0, 0x0004($s0)           ## 00000004
/* 02404 80A4B2C4 8E2202C0 */  lw      $v0, 0x02C0($s1)           ## 000002C0
/* 02408 80A4B2C8 3C0A0500 */  lui     $t2, %hi(D_05000530)                ## $t2 = 05000000
/* 0240C 80A4B2CC 254A0530 */  addiu   $t2, $t2, %lo(D_05000530)           ## $t2 = 05000530
/* 02410 80A4B2D0 24480008 */  addiu   $t0, $v0, 0x0008           ## $t0 = 00000008
/* 02414 80A4B2D4 AE2802C0 */  sw      $t0, 0x02C0($s1)           ## 000002C0
/* 02418 80A4B2D8 3C09DE00 */  lui     $t1, 0xDE00                ## $t1 = DE000000
/* 0241C 80A4B2DC AC490000 */  sw      $t1, 0x0000($v0)           ## 00000000
/* 02420 80A4B2E0 10000026 */  beq     $zero, $zero, .L80A4B37C   
/* 02424 80A4B2E4 AC4A0004 */  sw      $t2, 0x0004($v0)           ## 00000004
/* 02428 80A4B2E8 8E0B0308 */  lw      $t3, 0x0308($s0)           ## 00000308
.L80A4B2EC:
/* 0242C 80A4B2EC 51600024 */  beql    $t3, $zero, .L80A4B380     
/* 02430 80A4B2F0 8FAB007C */  lw      $t3, 0x007C($sp)           
/* 02434 80A4B2F4 8E2202C0 */  lw      $v0, 0x02C0($s1)           ## 000002C0
/* 02438 80A4B2F8 3C0DDB06 */  lui     $t5, 0xDB06                ## $t5 = DB060000
/* 0243C 80A4B2FC 35AD0020 */  ori     $t5, $t5, 0x0020           ## $t5 = DB060020
/* 02440 80A4B300 244C0008 */  addiu   $t4, $v0, 0x0008           ## $t4 = 00000008
/* 02444 80A4B304 AE2C02C0 */  sw      $t4, 0x02C0($s1)           ## 000002C0
/* 02448 80A4B308 AC4D0000 */  sw      $t5, 0x0000($v0)           ## 00000000
/* 0244C 80A4B30C 8FAE007C */  lw      $t6, 0x007C($sp)           
/* 02450 80A4B310 8DC40000 */  lw      $a0, 0x0000($t6)           ## 00000000
/* 02454 80A4B314 0C292B98 */  jal     func_80A4AE60              
/* 02458 80A4B318 AFA20040 */  sw      $v0, 0x0040($sp)           
/* 0245C 80A4B31C 8FA30040 */  lw      $v1, 0x0040($sp)           
/* 02460 80A4B320 3C18DA38 */  lui     $t8, 0xDA38                ## $t8 = DA380000
/* 02464 80A4B324 37180003 */  ori     $t8, $t8, 0x0003           ## $t8 = DA380003
/* 02468 80A4B328 AC620004 */  sw      $v0, 0x0004($v1)           ## 00000004
/* 0246C 80A4B32C 8E2202C0 */  lw      $v0, 0x02C0($s1)           ## 000002C0
/* 02470 80A4B330 3C0580A5 */  lui     $a1, %hi(D_80A4B8D0)       ## $a1 = 80A50000
/* 02474 80A4B334 24A5B8D0 */  addiu   $a1, $a1, %lo(D_80A4B8D0)  ## $a1 = 80A4B8D0
/* 02478 80A4B338 244F0008 */  addiu   $t7, $v0, 0x0008           ## $t7 = 00000008
/* 0247C 80A4B33C AE2F02C0 */  sw      $t7, 0x02C0($s1)           ## 000002C0
/* 02480 80A4B340 AC580000 */  sw      $t8, 0x0000($v0)           ## 00000000
/* 02484 80A4B344 8FB9007C */  lw      $t9, 0x007C($sp)           
/* 02488 80A4B348 24060842 */  addiu   $a2, $zero, 0x0842         ## $a2 = 00000842
/* 0248C 80A4B34C 8F240000 */  lw      $a0, 0x0000($t9)           ## 00000000
/* 02490 80A4B350 0C0346A2 */  jal     Matrix_NewMtx              
/* 02494 80A4B354 AFA2003C */  sw      $v0, 0x003C($sp)           
/* 02498 80A4B358 8FA3003C */  lw      $v1, 0x003C($sp)           
/* 0249C 80A4B35C 3C09DE00 */  lui     $t1, 0xDE00                ## $t1 = DE000000
/* 024A0 80A4B360 AC620004 */  sw      $v0, 0x0004($v1)           ## 00000004
/* 024A4 80A4B364 8E2202C0 */  lw      $v0, 0x02C0($s1)           ## 000002C0
/* 024A8 80A4B368 24480008 */  addiu   $t0, $v0, 0x0008           ## $t0 = 00000008
/* 024AC 80A4B36C AE2802C0 */  sw      $t0, 0x02C0($s1)           ## 000002C0
/* 024B0 80A4B370 AC490000 */  sw      $t1, 0x0000($v0)           ## 00000000
/* 024B4 80A4B374 8E0A0308 */  lw      $t2, 0x0308($s0)           ## 00000308
/* 024B8 80A4B378 AC4A0004 */  sw      $t2, 0x0004($v0)           ## 00000004
.L80A4B37C:
/* 024BC 80A4B37C 8FAB007C */  lw      $t3, 0x007C($sp)           
.L80A4B380:
/* 024C0 80A4B380 3C0680A5 */  lui     $a2, %hi(D_80A4B8E0)       ## $a2 = 80A50000
/* 024C4 80A4B384 24C6B8E0 */  addiu   $a2, $a2, %lo(D_80A4B8E0)  ## $a2 = 80A4B8E0
/* 024C8 80A4B388 27A40058 */  addiu   $a0, $sp, 0x0058           ## $a0 = FFFFFFE0
/* 024CC 80A4B38C 24070847 */  addiu   $a3, $zero, 0x0847         ## $a3 = 00000847
/* 024D0 80A4B390 0C031AD5 */  jal     Graph_CloseDisps              
/* 024D4 80A4B394 8D650000 */  lw      $a1, 0x0000($t3)           ## 00000000
/* 024D8 80A4B398 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 024DC 80A4B39C 8FB0001C */  lw      $s0, 0x001C($sp)           
/* 024E0 80A4B3A0 8FB10020 */  lw      $s1, 0x0020($sp)           
/* 024E4 80A4B3A4 03E00008 */  jr      $ra                        
/* 024E8 80A4B3A8 27BD0078 */  addiu   $sp, $sp, 0x0078           ## $sp = 00000000
