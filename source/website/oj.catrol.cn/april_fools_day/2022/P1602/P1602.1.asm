bits 16
org 256
mov ah,64
mov bx,1
mov cx,720
mov dx,b+16
int 33
mov cx,90
mov si,b+16
c:push cx
mov ah,64
mov bx,1
mov cx,6
mov dx,b
int 33
mov cx,7
a:push cx
mov al,[si]
shr al,4
add al,48
cmp al,58
jb g
add al,39
g:mov [b+8],al
lodsb
and al,15
add al,48
cmp al,58
jb e
add al,39
e:mov [b+9],al
mov ah,64
mov bx,1
mov cx,5
mov dx,b+6
int 33
pop cx
loop a
mov al,[si]
shr al,4
add al,48
cmp al,58
jb h
add al,39
h:mov [b+8],al
lodsb
and al,15
add al,48
cmp al,58
jb n
add al,39
n:mov [b+9],al
mov ah,64
mov bx,1
mov cx,4
mov dx,b+6
int 33
pop cx
loop c
mov ah,64
mov bx,1
mov cx,5
mov dx,b+11
int 33
mov ah,76
int 33
b   db 13,10,' db 0x  ,',13,10,'end'
 db 0x62,0x69,0x74,0x73,0x20,0x31,0x36,0x0d
 db 0x0a,0x6f,0x72,0x67,0x20,0x32,0x35,0x36
 db 0x0d,0x0a,0x6d,0x6f,0x76,0x20,0x61,0x68
 db 0x2c,0x36,0x34,0x0d,0x0a,0x6d,0x6f,0x76
 db 0x20,0x62,0x78,0x2c,0x31,0x0d,0x0a,0x6d
 db 0x6f,0x76,0x20,0x63,0x78,0x2c,0x37,0x32
 db 0x30,0x0d,0x0a,0x6d,0x6f,0x76,0x20,0x64
 db 0x78,0x2c,0x62,0x2b,0x31,0x36,0x0d,0x0a
 db 0x69,0x6e,0x74,0x20,0x33,0x33,0x0d,0x0a
 db 0x6d,0x6f,0x76,0x20,0x63,0x78,0x2c,0x39
 db 0x30,0x0d,0x0a,0x6d,0x6f,0x76,0x20,0x73
 db 0x69,0x2c,0x62,0x2b,0x31,0x36,0x0d,0x0a
 db 0x63,0x3a,0x70,0x75,0x73,0x68,0x20,0x63
 db 0x78,0x0d,0x0a,0x6d,0x6f,0x76,0x20,0x61
 db 0x68,0x2c,0x36,0x34,0x0d,0x0a,0x6d,0x6f
 db 0x76,0x20,0x62,0x78,0x2c,0x31,0x0d,0x0a
 db 0x6d,0x6f,0x76,0x20,0x63,0x78,0x2c,0x36
 db 0x0d,0x0a,0x6d,0x6f,0x76,0x20,0x64,0x78
 db 0x2c,0x62,0x0d,0x0a,0x69,0x6e,0x74,0x20
 db 0x33,0x33,0x0d,0x0a,0x6d,0x6f,0x76,0x20
 db 0x63,0x78,0x2c,0x37,0x0d,0x0a,0x61,0x3a
 db 0x70,0x75,0x73,0x68,0x20,0x63,0x78,0x0d
 db 0x0a,0x6d,0x6f,0x76,0x20,0x61,0x6c,0x2c
 db 0x5b,0x73,0x69,0x5d,0x0d,0x0a,0x73,0x68
 db 0x72,0x20,0x61,0x6c,0x2c,0x34,0x0d,0x0a
 db 0x61,0x64,0x64,0x20,0x61,0x6c,0x2c,0x34
 db 0x38,0x0d,0x0a,0x63,0x6d,0x70,0x20,0x61
 db 0x6c,0x2c,0x35,0x38,0x0d,0x0a,0x6a,0x62
 db 0x20,0x67,0x0d,0x0a,0x61,0x64,0x64,0x20
 db 0x61,0x6c,0x2c,0x33,0x39,0x0d,0x0a,0x67
 db 0x3a,0x6d,0x6f,0x76,0x20,0x5b,0x62,0x2b
 db 0x38,0x5d,0x2c,0x61,0x6c,0x0d,0x0a,0x6c
 db 0x6f,0x64,0x73,0x62,0x0d,0x0a,0x61,0x6e
 db 0x64,0x20,0x61,0x6c,0x2c,0x31,0x35,0x0d
 db 0x0a,0x61,0x64,0x64,0x20,0x61,0x6c,0x2c
 db 0x34,0x38,0x0d,0x0a,0x63,0x6d,0x70,0x20
 db 0x61,0x6c,0x2c,0x35,0x38,0x0d,0x0a,0x6a
 db 0x62,0x20,0x65,0x0d,0x0a,0x61,0x64,0x64
 db 0x20,0x61,0x6c,0x2c,0x33,0x39,0x0d,0x0a
 db 0x65,0x3a,0x6d,0x6f,0x76,0x20,0x5b,0x62
 db 0x2b,0x39,0x5d,0x2c,0x61,0x6c,0x0d,0x0a
 db 0x6d,0x6f,0x76,0x20,0x61,0x68,0x2c,0x36
 db 0x34,0x0d,0x0a,0x6d,0x6f,0x76,0x20,0x62
 db 0x78,0x2c,0x31,0x0d,0x0a,0x6d,0x6f,0x76
 db 0x20,0x63,0x78,0x2c,0x35,0x0d,0x0a,0x6d
 db 0x6f,0x76,0x20,0x64,0x78,0x2c,0x62,0x2b
 db 0x36,0x0d,0x0a,0x69,0x6e,0x74,0x20,0x33
 db 0x33,0x0d,0x0a,0x70,0x6f,0x70,0x20,0x63
 db 0x78,0x0d,0x0a,0x6c,0x6f,0x6f,0x70,0x20
 db 0x61,0x0d,0x0a,0x6d,0x6f,0x76,0x20,0x61
 db 0x6c,0x2c,0x5b,0x73,0x69,0x5d,0x0d,0x0a
 db 0x73,0x68,0x72,0x20,0x61,0x6c,0x2c,0x34
 db 0x0d,0x0a,0x61,0x64,0x64,0x20,0x61,0x6c
 db 0x2c,0x34,0x38,0x0d,0x0a,0x63,0x6d,0x70
 db 0x20,0x61,0x6c,0x2c,0x35,0x38,0x0d,0x0a
 db 0x6a,0x62,0x20,0x68,0x0d,0x0a,0x61,0x64
 db 0x64,0x20,0x61,0x6c,0x2c,0x33,0x39,0x0d
 db 0x0a,0x68,0x3a,0x6d,0x6f,0x76,0x20,0x5b
 db 0x62,0x2b,0x38,0x5d,0x2c,0x61,0x6c,0x0d
 db 0x0a,0x6c,0x6f,0x64,0x73,0x62,0x0d,0x0a
 db 0x61,0x6e,0x64,0x20,0x61,0x6c,0x2c,0x31
 db 0x35,0x0d,0x0a,0x61,0x64,0x64,0x20,0x61
 db 0x6c,0x2c,0x34,0x38,0x0d,0x0a,0x63,0x6d
 db 0x70,0x20,0x61,0x6c,0x2c,0x35,0x38,0x0d
 db 0x0a,0x6a,0x62,0x20,0x6e,0x0d,0x0a,0x61
 db 0x64,0x64,0x20,0x61,0x6c,0x2c,0x33,0x39
 db 0x0d,0x0a,0x6e,0x3a,0x6d,0x6f,0x76,0x20
 db 0x5b,0x62,0x2b,0x39,0x5d,0x2c,0x61,0x6c
 db 0x0d,0x0a,0x6d,0x6f,0x76,0x20,0x61,0x68
 db 0x2c,0x36,0x34,0x0d,0x0a,0x6d,0x6f,0x76
 db 0x20,0x62,0x78,0x2c,0x31,0x0d,0x0a,0x6d
 db 0x6f,0x76,0x20,0x63,0x78,0x2c,0x34,0x0d
 db 0x0a,0x6d,0x6f,0x76,0x20,0x64,0x78,0x2c
 db 0x62,0x2b,0x36,0x0d,0x0a,0x69,0x6e,0x74
 db 0x20,0x33,0x33,0x0d,0x0a,0x70,0x6f,0x70
 db 0x20,0x63,0x78,0x0d,0x0a,0x6c,0x6f,0x6f
 db 0x70,0x20,0x63,0x0d,0x0a,0x6d,0x6f,0x76
 db 0x20,0x61,0x68,0x2c,0x36,0x34,0x0d,0x0a
 db 0x6d,0x6f,0x76,0x20,0x62,0x78,0x2c,0x31
 db 0x0d,0x0a,0x6d,0x6f,0x76,0x20,0x63,0x78
 db 0x2c,0x35,0x0d,0x0a,0x6d,0x6f,0x76,0x20
 db 0x64,0x78,0x2c,0x62,0x2b,0x31,0x31,0x0d
 db 0x0a,0x69,0x6e,0x74,0x20,0x33,0x33,0x0d
 db 0x0a,0x6d,0x6f,0x76,0x20,0x61,0x68,0x2c
 db 0x37,0x36,0x0d,0x0a,0x69,0x6e,0x74,0x20
 db 0x33,0x33,0x0d,0x0a,0x62,0x20,0x20,0x20
 db 0x64,0x62,0x20,0x31,0x33,0x2c,0x31,0x30
 db 0x2c,0x27,0x20,0x64,0x62,0x20,0x30,0x78
 db 0x20,0x20,0x2c,0x27,0x2c,0x31,0x33,0x2c
 db 0x31,0x30,0x2c,0x27,0x65,0x6e,0x64,0x27
end