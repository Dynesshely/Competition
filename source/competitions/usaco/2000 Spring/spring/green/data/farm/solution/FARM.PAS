program farm;

const
  inputfile='farm.in';
  outputfile='farm.out';
  Maxregions=100;

type
  bnum=array[0..50]of byte;
  position=record
            x,y:bnum;
           end;
  region=record
           p1,p2:position;
           color:longint;
         end;
  posi=^position;

var
  f1,f2:text;
  Tp:array[1..Maxregions]of region;
  tregions,max:byte;
  pos1,pos2:posi;

procedure init;
begin
   assign(f1,inputfile);
   reset(f1);
   assign(f2,outputfile);
   rewrite(f2);
end;

procedure Mult(var a:bnum;b:longint);
var i,g,s:integer;
begin
  g:=0;
  for i:=1 to a[0] do
    begin s:=a[i]*b+g;a[i]:=s mod 10;g:=s div 10;end;
  while g>0 do
   begin inc(a[0]);a[a[0]]:=g mod 10;g:=g div 10;end;
end;

procedure Sum_div2(a,b:bnum;var c:bnum);
var i,g,s:integer;
begin
  fillchar(c,sizeof(c),0);
  g:=0;
  for i:=1 to a[0] do
   begin s:=a[i]+b[i]+g;c[i]:=s mod 10;g:=s div 10;end;
  if a[0]<b[0] then
   for i:=a[0]+1 to b[0] do
     begin s:=g+b[i];c[i]:=s mod 10;g:=s div 10;end;
  if a[0]<b[0] then c[0]:=b[0] else c[0]:=a[0];
  while g>0 do
   begin inc(c[0]);c[c[0]]:=g mod 10;g:=g div 10;end;
  g:=0;
  for i:=c[0] downto 1 do
   begin s:=c[i]+g*10;c[i]:=s div 2;g:=s mod 2;end;
  while (c[0]>1)and(c[c[0]]=0)do dec(c[0]);
end;

function same(a,b:bnum):boolean;
var i:byte;
begin
  if a[0]<>b[0] then same:=false
  else
    begin
      for i:=a[0] downto 1 do
        if a[i]<>b[i] then begin same:=false;exit;end;
      same:=true;
    end;
end;

function smaller(a,b:bnum):boolean;
var i:byte;
begin
  if same(a,b) then begin smaller:=false;exit;end;
  if a[0]<b[0] then smaller:=true
  else if a[0]>b[0] then smaller:=false
  else
    begin
      for i:=a[0] downto 1 do
       if a[i]>b[i] then begin smaller:=false;exit;end
       else if a[i]<b[i] then begin smaller:=true;exit;end;
    end;
end;

procedure create(tp1,tp2:posi);
var
  value:longint;
  t :posi;
begin
  readln(f1,value);
  if value=-1 then
    begin
      new(t);
      sum_div2(tp1^.x,tp2^.x,t^.x);t^.y:=tp2^.y;
      create(tp1,t);
      t^.y:=tp1^.y;
      create(t,tp2);
    end
  else if value=-2 then
    begin
      new(t);
      sum_div2(tp1^.y,tp2^.y,t^.y);t^.x:=tp2^.x;
      create(tp1,t);
      t^.x:=tp1^.x;
      create(t,tp2);
    end
  else
    begin
      inc(tregions);
      Tp[tregions].color:=value;
      Tp[tregions].p1:=tp1^;
      Tp[tregions].p2:=tp2^;
    end;
end;

function adj(a,b:byte):boolean;
begin
  if (same(Tp[a].p1.x,Tp[b].p2.x)and smaller(Tp[a].p1.y,Tp[b].p2.y) and
          smaller(Tp[b].p1.y,Tp[a].p2.y))
  or (same(Tp[a].p2.x,Tp[b].p1.x)and smaller(Tp[a].p1.y,Tp[b].p2.y) and
          smaller(Tp[b].p1.y,Tp[a].p2.y))
  or (same(Tp[a].p2.y,Tp[b].p1.y)and smaller(Tp[a].p1.x,Tp[b].p2.x) and
          smaller(Tp[b].p1.x,Tp[a].p2.x))
  or (same(Tp[a].p1.y,Tp[b].p2.y)and smaller(Tp[a].p1.x,Tp[b].p2.x) and
          smaller(Tp[b].p1.x,Tp[a].p2.x))
  then adj:=true
  else adj:=false;
end;

procedure solve;
var
  i,now:byte;
  queue:array[1..Maxregions]of byte;
  fp,rp:byte;
  b    :array[1..Maxregions]of boolean;
  colour:longint;
begin
  tregions:=0;
  new(pos1);new(pos2);
  fillchar(pos1^.x,sizeof(pos1^.x),0);pos1^.x[0]:=1;
  fillchar(pos1^.y,sizeof(pos1^.y),0);pos1^.y[0]:=1;
  pos2^.x[0]:=1;pos2^.x[1]:=1;
  for i:=1 to 10 do Mult(pos2^.x,1024);
  pos2^.y:=pos2^.x;
  Create(pos1,pos2);
  fillchar(b,sizeof(b),0);
  max:=0;
  now:=1;
  repeat
    while (now<=tregions)and(b[now]=true)do inc(now);
    if now>tregions then exit;
    queue[1]:=now;fp:=1;rp:=1;b[now]:=true;
    colour:=Tp[now].color;
    repeat
      for i:=1 to tregions do
        if (b[i]=false)and(Tp[i].color=colour)and(adj(queue[fp],i))
          then begin inc(rp);queue[rp]:=i;b[i]:=true;end;
      inc(fp);
    until fp>rp;
    if rp>max then max:=rp;
  until false;
end;

procedure out;
begin
  writeln(f2,max);
  close(f2);
end;

begin
  init;
  solve;
  out;
end.