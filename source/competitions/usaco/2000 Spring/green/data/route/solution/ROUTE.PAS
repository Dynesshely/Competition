{$M 16384,0,655360}
program route;

const
  inputfile='route.in';
  outputfile='route.out';
  Maxnum=200;

type
  position=record
            x,y:integer;
           end;
  ap=array[1..Maxnum]of position;

var
  f1,f2:text;
  Tp:array[1..Maxnum]of ^ap;
  s :array[1..Maxnum]of set of byte;
  b :array[1..Maxnum]of boolean;
  R,nowr,id :byte;

procedure init;
var i:byte;
begin
   assign(f1,inputfile);
   reset(f1);
   assign(f2,outputfile);
   rewrite(f2);

   readln(f1,R);
   for i:=1 to R do
    begin
       new(Tp[i]);
       fillchar(Tp[i]^,sizeof(Tp[i]^),0);
    end;
   fillchar(s,sizeof(s),0);
   fillchar(b,sizeof(b),0);
end;

procedure solve;
var
    x1,y1:integer;
    i,j,start,dis,last:byte;
    dire:char;
    id2:byte;
begin
  id:=0;
  repeat
    inc(id);
    read(f1,start,dis);
    s[id]:=[start];
    x1:=0;y1:=0;
    while dis<>0 do
      begin
        read(f1,dire);
        while not (dire in['N','E','W','S'])do read(f1,dire);
        read(f1,last);
        case dire of
            'N':y1:=y1+dis;
            'E':x1:=x1+dis;
            'W':x1:=x1-dis;
            'S':y1:=y1-dis;
        end;
        include(s[id],last);
        with Tp[id]^[last] do
          begin x:=x1;y:=y1; end;
        start:=last;
        read(f1,dis);
       end;
          repeat
             id2:=1;
             while (id2<id) and((b[id2]=true)or(s[id2]*s[id]=[]))do inc(id2);
             if id2=id then break;
             for i:=1 to Maxnum do if
               i in s[id2]*s[id] then break;
             for j:=1 to Maxnum do if j in s[id2] then
               begin
                  x1:=Tp[id]^[i].x-(Tp[id2]^[i].x-Tp[id2]^[j].x);
                  y1:=Tp[id]^[i].y-(Tp[id2]^[i].y-Tp[id2]^[j].y);
                  if not(j in s[id]) then
                    begin Tp[id]^[j].x:=x1;Tp[id]^[j].y:=y1; end
                  else
                    if (x1<>Tp[id]^[j].x)or(y1<>Tp[id]^[j].y) then
                       begin dec(id);exit;end;
              end;
             s[id]:=s[id2]+s[id];
             b[id2]:=true;
          until false;
  until id=R;
end;

procedure out;
begin
  close(f1);
  writeln(f2,id);
  close(f2);
end;

begin
  init;
  solve;
  out;
end.