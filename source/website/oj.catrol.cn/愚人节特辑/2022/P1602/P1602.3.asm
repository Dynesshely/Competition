         .model tiny
         .code
         org   0100h

inizio:
         jmp   programma

a_capo   DB    '÷÷         DB    ÷', 00h
stringa  DB    ';Questo programma visualizza il suo codice sorgente.÷;Autore: Luca Caucci (e-mail: caucci@cs.unibo.it)÷÷         .model tiny÷         .code÷         org   0100h÷÷inizio:÷         jmp   programma÷÷a_capo   DB    ÷~÷, 00h÷s¯'
         DB    'tringa  DB    ÷~÷, 00h÷formato  DB    0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 27h÷         DW    OFFSET(a_capo)÷         DB    27h, 0dh, 27h÷         DW    OFFSET(stringa)÷         DW    OFFSET(a_capo)÷         ¯'
         DB    'DB    27h, 0dh, 27h÷         DW    OFFSET(a_capo)÷         DB    27h, 0dh, 27h÷         DW    OFFSET(a_capo)÷         DB    27h, 0dh, 27h÷         DW    OFFSET(a_capo)÷         DB    27h, 0dh, 27h÷         DW    OFFSET(a_¯'
         DB    'capo)÷         DB    27h, 0dh, 27h÷         DW    OFFSET(a_capo)÷         DB    27h, 0dh, 27h÷         DW    OFFSET(a_capo)÷         DB    27h, 0dh, 27h÷         DW    OFFSET(a_capo)÷         DB    27h, 0dh, 27h÷         ¯'
         DB    'DW    OFFSET(a_capo)÷         DB    27h, 0dh, 27h÷         DW    OFFSET(a_capo)÷         DB    27h, 0dh, 27h÷         DW    OFFSET(a_capo)÷         DB    27h, 0dh, 27h÷         DW    OFFSET(a_capo)÷         DB    27h, 0dh¯'
         DB    ', 27h÷         DW    OFFSET(a_capo)÷         DB    27h, 0dh, 27h÷         DW    OFFSET(a_capo)÷         DB    27h, 0dh, 27h÷         DW    OFFSET(a_capo)÷         DB    27h, 0dh, 27h÷         DW    OFFSET(a_capo)÷        ¯'
         DB    ' DB    27h, 0dh, 27h÷         DW    OFFSET(a_capo)÷         DB    27h, 0dh, 27h, 27h, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh÷         DB    0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh÷         DB    0dh, 0d¯'
         DB    'h, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh÷         DB    0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh÷         DB    0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh÷         DB    0dh, 0¯'
         DB    'dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh÷         DB    0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 27h, 0f7h÷         DB    27h, 0dh, 0dh, 27h, 7eh, 27h, 0dh, 0dh, 27h, 0afh, 27h, 0dh÷         DB    0dh¯'
         DB    ', 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh÷         DB    0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 27h, 0afh÷         DB    27h, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh÷         DB    0¯'
         DB    'dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh÷÷programma:÷         lea   ax, [formato]÷         push  ax÷         lea   ax, [stringa]÷         push  ax÷         call  disp_str÷         mov   ah, 4ch÷         int   ¯'
         DB    '21h÷÷disp_str PROC÷__indstr EQU   bp + 04h÷__param  EQU   bp + 06h÷÷         push  bp÷         mov   bp, sp÷         push  bx÷         push  dx÷         push  si÷         push  di÷         cld÷         mov   si, [__indstr¯'
         DB    ']÷         mov   bx, [__param]÷         mov   ah, 02h÷__leggi_carattere:÷         lodsb÷         cmp   al, 00h÷         je    __fine_stringa÷         cmp   al, ÷÷÷÷         je    __caratt_spec÷         cmp   al, ÷÷÷÷     ¯'
         DB    '    je    __stringa÷         cmp   al, ÷÷÷÷         je    __leggi_carattere÷         mov   dl, al÷         int   21h÷         jmp   __leggi_carattere÷__caratt_spec:÷         mov   dl, [bx]÷         inc   bx÷         int  ¯'
         DB    ' 21h÷         cmp   dl, 0dh÷         jne   __leggi_carattere÷         mov   dl, 0ah÷         int   21h÷         jmp   __leggi_carattere÷__stringa:÷         mov   di, [bx]÷         add   bx, 0002h÷__carattere_succ_stringa:¯'
         DB    '÷         mov   dl, [di]÷         inc   di÷         cmp   dl, 00h÷         je    __leggi_carattere÷         int   21h÷         cmp   dl, ÷÷÷÷         jne   __carattere_succ_stringa÷         mov   ax, bx÷         add   ax,¯'
         DB    ' 0002h÷         push  ax÷         push  [bx]÷         call  disp_str÷         mov   bx, ax÷         mov   ah, 02h÷         jmp   __carattere_succ_stringa÷__fine_stringa:÷         mov   ax, bx÷         pop   di÷         po¯'
         DB    'p   si÷         pop   dx÷         pop   bx÷         pop   bp÷         ret   0004h÷disp_str ENDP÷÷         END   inizio÷÷', 00h
formato  DB    0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 27h
         DW    OFFSET(a_capo)
         DB    27h, 0dh, 27h
         DW    OFFSET(stringa)
         DW    OFFSET(a_capo)
         DB    27h, 0dh, 27h
         DW    OFFSET(a_capo)
         DB    27h, 0dh, 27h
         DW    OFFSET(a_capo)
         DB    27h, 0dh, 27h
         DW    OFFSET(a_capo)
         DB    27h, 0dh, 27h
         DW    OFFSET(a_capo)
         DB    27h, 0dh, 27h
         DW    OFFSET(a_capo)
         DB    27h, 0dh, 27h
         DW    OFFSET(a_capo)
         DB    27h, 0dh, 27h
         DW    OFFSET(a_capo)
         DB    27h, 0dh, 27h
         DW    OFFSET(a_capo)
         DB    27h, 0dh, 27h
         DW    OFFSET(a_capo)
         DB    27h, 0dh, 27h
         DW    OFFSET(a_capo)
         DB    27h, 0dh, 27h
         DW    OFFSET(a_capo)
         DB    27h, 0dh, 27h
         DW    OFFSET(a_capo)
         DB    27h, 0dh, 27h
         DW    OFFSET(a_capo)
         DB    27h, 0dh, 27h
         DW    OFFSET(a_capo)
         DB    27h, 0dh, 27h
         DW    OFFSET(a_capo)
         DB    27h, 0dh, 27h
         DW    OFFSET(a_capo)
         DB    27h, 0dh, 27h, 27h, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh
         DB    0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh
         DB    0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh
         DB    0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh
         DB    0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh
         DB    0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh
         DB    0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 27h, 0f7h
         DB    27h, 0dh, 0dh, 27h, 7eh, 27h, 0dh, 0dh, 27h, 0afh, 27h, 0dh
         DB    0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh
         DB    0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 27h, 0afh
         DB    27h, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh
         DB    0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh

programma:
         lea   ax, [formato]
         push  ax
         lea   ax, [stringa]
         push  ax
         call  disp_str
         mov   ah, 4ch
         int   21h

disp_str PROC
__indstr EQU   bp + 04h
__param  EQU   bp + 06h

         push  bp
         mov   bp, sp
         push  bx
         push  dx
         push  si
         push  di
         cld
         mov   si, [__indstr]
         mov   bx, [__param]
         mov   ah, 02h
__leggi_carattere:
         lodsb
         cmp   al, 00h
         je    __fine_stringa
         cmp   al, '÷'
         je    __caratt_spec
         cmp   al, '~'
         je    __stringa
         cmp   al, '¯'
         je    __leggi_carattere
         mov   dl, al
         int   21h
         jmp   __leggi_carattere
__caratt_spec:
         mov   dl, [bx]
         inc   bx
         int   21h
         cmp   dl, 0dh
         jne   __leggi_carattere
         mov   dl, 0ah
         int   21h
         jmp   __leggi_carattere
__stringa:
         mov   di, [bx]
         add   bx, 0002h
__carattere_succ_stringa:
         mov   dl, [di]
         inc   di
         cmp   dl, 00h
         je    __leggi_carattere
         int   21h
         cmp   dl, '¯'
         jne   __carattere_succ_stringa
         mov   ax, bx
         add   ax, 0002h
         push  ax
         push  [bx]
         call  disp_str
         mov   bx, ax
         mov   ah, 02h
         jmp   __carattere_succ_stringa
__fine_stringa:
         mov   ax, bx
         pop   di
         pop   si
         pop   dx
         pop   bx
         pop   bp
         ret   0004h
disp_str ENDP

         END   inizio