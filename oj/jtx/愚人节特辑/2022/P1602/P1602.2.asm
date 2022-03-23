         .model tiny
         .code
         org   0100h

inizio:
         jmp   programma

a_capo   DB    'ww         DB    w', 00h
stringa  DB    ';Questo programma visualizza il suo codice sorgente.w;Autore: Caucci Luca (e-mail: caucci@cs.unibo.it)ww         .model tinyw         .codew         org   0100hwwinizio:w         jmp   programmawwa_capo   DB    w~w, 00hws/'
         DB    'tringa  DB    w~w, 00hwformato  DB    0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 27hw         DW    OFFSET(a_capo)w         DB    27h, 0dh, 27hw         DW    OFFSET(stringa)w         DW    OFFSET(a_capo)w         /'
         DB    'DB    27h, 0dh, 27hw         DW    OFFSET(a_capo)w         DB    27h, 0dh, 27hw         DW    OFFSET(a_capo)w         DB    27h, 0dh, 27hw         DW    OFFSET(a_capo)w         DB    27h, 0dh, 27hw         DW    OFFSET(a_/'
         DB    'capo)w         DB    27h, 0dh, 27hw         DW    OFFSET(a_capo)w         DB    27h, 0dh, 27hw         DW    OFFSET(a_capo)w         DB    27h, 0dh, 27hw         DW    OFFSET(a_capo)w         DB    27h, 0dh, 27hw         /'
         DB    'DW    OFFSET(a_capo)w         DB    27h, 0dh, 27hw         DW    OFFSET(a_capo)w         DB    27h, 0dh, 27hw         DW    OFFSET(a_capo)w         DB    27h, 0dh, 27hw         DW    OFFSET(a_capo)w         DB    27h, 0dh/'
         DB    ', 27hw         DW    OFFSET(a_capo)w         DB    27h, 0dh, 27hw         DW    OFFSET(a_capo)w         DB    27h, 0dh, 27hw         DW    OFFSET(a_capo)w         DB    27h, 0dh, 27hw         DW    OFFSET(a_capo)w        /'
         DB    ' DB    27h, 0dh, 27hw         DW    OFFSET(a_capo)w         DB    27h, 0dh, 27h, 27h, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dhw         DB    0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dhw         DB    0dh, 0d/'
         DB    'h, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dhw         DB    0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dhw         DB    0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dhw         DB    0dh, 0/'
         DB    'dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dhw         DB    0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 27h, 0f7hw         DB    27h, 0dh, 0dh, 27h, 7eh, 27h, 0dh, 0dh, 27h, 0afh, 27h, 0dhw         DB    0dh/'
         DB    ', 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dhw         DB    0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 27h, 0afhw         DB    27h, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dhw         DB    0/'
         DB    'dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dh, 0dhwwprogramma:w         lea   ax, [formato]w         push  axw         lea   ax, [stringa]w         push  axw         call  disp_strw         mov   ah, 4chw         int   /'
         DB    '21hwwdisp_str PROCw__indstr EQU   bp + 04hw__param  EQU   bp + 06hww         push  bpw         mov   bp, spw         push  bxw         push  dxw         push  siw         push  diw         cldw         mov   si, [__indstr/'
         DB    ']w         mov   bx, [__param]w         mov   ah, 02hw__leggi_carattere:w         lodsbw         cmp   al, 00hw         je    __fine_stringaw         cmp   al, wwww         je    __caratt_specw         cmp   al, wwww     /'
         DB    '    je    __stringaw         cmp   al, wwww         je    __leggi_caratterew         mov   dl, alw         int   21hw         jmp   __leggi_caratterew__caratt_spec:w         mov   dl, [bx]w         inc   bxw         int  /'
         DB    ' 21hw         cmp   dl, 0dhw         jne   __leggi_caratterew         mov   dl, 0ahw         int   21hw         jmp   __leggi_caratterew__stringa:w         mov   di, [bx]w         add   bx, 0002hw__carattere_succ_stringa:/'
         DB    'w         mov   dl, [di]w         inc   diw         cmp   dl, 00hw         je    __leggi_caratterew         int   21hw         cmp   dl, wwww         jne   __carattere_succ_stringaw         mov   ax, bxw         add   ax,/'
         DB    ' 0002hw         push  axw         push  [bx]w         call  disp_strw         mov   bx, axw         mov   ah, 02hw         jmp   __carattere_succ_stringaw__fine_stringa:w         mov   ax, bxw         pop   diw         po/'
         DB    'p   siw         pop   dxw         pop   bxw         pop   bpw         ret   0004hwdisp_str ENDPww         END   inizioww', 00h
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
         cmp   al, 'w'
         je    __caratt_spec
         cmp   al, '~'
         je    __stringa
         cmp   al, '/'
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
         cmp   dl, '/'
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