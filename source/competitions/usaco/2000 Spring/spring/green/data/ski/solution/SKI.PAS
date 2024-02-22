{$N+}
{$M 16384,0,655360}
program ski;

const
  inputname='ski.in';
  outputname='ski.out';
  maxN=200;
  maxM=5000;

type
  node=array[1..maxN]of integer;
  Lnum=array[0..300]of byte;

var
  High:array[1..maxN]of longint;
  Down:array[1..maxN]of byte;
  G:array[1..maxN]of ^node;
  F:array[1..maxN]of Lnum;
  N,M:integer;
  f1,f2:text;

procedure init;
var i,j,v1,v2,temp:integer;
begin
  assign(f1,inputname);
  reset(f1);
  readln(f1,N,M);
  for i:=1 to N do
    begin
      new(G[i]);fillchar(G[i]^,sizeof(G[i]^),0);
      read(f1,High[i]);
      Down[i]:=i;
    end;
  for i:=1 to M do
    begin
      read(f1,v1,v2);
      if High[v1]>High[v2] then
      inc(G[v1]^[v2])
      else inc(G[v2]^[v1]);
    end;
  close(f1);

  for i:=1 to N-1 do
    for j:=i+1 to N do
      if High[Down[i]]<High[Down[j]] then
        begin
          temp:=Down[i];
          Down[i]:=Down[j];
          Down[j]:=temp;
        end;

  assign(f2,outputname);
  rewrite(f2);
end;

procedure Sum(var A:Lnum;B:Lnum;C:integer);
var i,g,s:longint;
begin
  g:=0;
  for i:=1 to B[0] do
    begin
      s:=B[i]*C+g;
      B[i]:=s mod 10;
      g:=s div 10;
    end;
  while g<>0 do
    begin inc(B[0]);B[B[0]]:=g mod 10;g:=g div 10 end;

  if (A[0]=1)and(A[1]=0)then
    begin A:=B;exit; end;

  g:=0;
  for i:=1 to A[0] do
    begin
      s:=A[i]+B[i]+g;
      A[i]:=s mod 10;
      g:=s div 10;
    end;
  if A[0]<B[0] then
    begin
     for i:=A[0]+1 to B[0] do
      begin
         s:=A[i]+B[i]+g;
         A[i]:=s mod 10;
         g:=s div 10;
      end;
     A[0]:=B[0];
    end;
  while g<>0 do
    begin inc(A[0]);A[A[0]]:=g mod 10;g:=g div 10;end;
end;

procedure solve;
var i,j:byte;
begin
  for i:=1 to N do
    begin fillchar(F[i],sizeof(F[i]),0);F[i][0]:=1; end;
  F[1][0]:=1;F[1][1]:=1;
  for i:=2 to N do
     for j:=1 to i-1 do
      if G[Down[j]]^[Down[i]]<>0 then
       Sum(F[i],F[j],G[Down[j]]^[Down[i]]);
end;

procedure output;
var i:integer;
begin
  for i:=F[N][0] downto 1
     do write(f2,F[N][i]);
  writeln(f2);
  close(f2);
end;

begin
  init;
  solve;
  output;
end.