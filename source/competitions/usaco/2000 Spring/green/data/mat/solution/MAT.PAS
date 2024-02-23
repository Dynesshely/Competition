program mat;

const
  inputfile='mat.in';
  outputfile='mat.out';
  MaxN=151;

type
  matrixtype=array[1..MaxN]of integer;
  increasetype=array[1..MaxN]of record
     x,y:integer;
     end;

var
  f1,f2:text;
  matrix:array[1..MaxN]of ^matrixtype;
  incr:array[1..MaxN]of ^increasetype;
  R,C:byte;
  maxarea:integer;

procedure init;
var i,j:byte;
begin
   assign(f1,inputfile);
   reset(f1);
   assign(f2,outputfile);
   rewrite(f2);

   readln(f1,R,C);

   for i:=1 to R+1 do new(matrix[i]);
   for i:=1 to R   do new(incr[i]);

   for i:=1 to R do
     for j:=1 to C do read(f1,matrix[i]^[j]);
   close(f1);

end;

procedure solve;
var i,j,l,k,m:integer;
begin
  for i:=1 to R do matrix[i]^[C+1]:=-1;
  for j:=1 to C do matrix[R+1]^[j]:=-1;
  for i:=R downto 1 do
    for j:=C downto 1 do
       begin
          incr[i]^[j].x:=1;
          if matrix[i]^[j]<matrix[i]^[j+1] then inc(incr[i]^[j].x,incr[i]^[j+1].x);
          incr[i]^[j].y:=1;
          if matrix[i]^[j]<matrix[i+1]^[j] then inc(incr[i]^[j].y,incr[i+1]^[j].y);
       end;

  maxarea:=0;
  for i:=1 to R do
    for j:=1 to C do
      if incr[i]^[j].x*incr[i]^[j].y>=maxarea then
        for k:=incr[i]^[j].x downto 1 do
         if k*incr[i]^[j].y>=maxarea then
          begin
             m:=incr[i]^[j].y;
             for l:=1 to k-1 do
               if incr[i]^[j+l].y<m then m:=incr[i]^[j+l].y;
             if k*m>=maxarea then
              begin
                l:=1;
                while (l<=m)and(incr[i+l-1]^[j].x>=k) do inc(l);
                l:=l-1;
                if l*k=maxarea then
                  writeln(f2,i,' ',j,' ',l,' ',k);
                if l*k>maxarea then
                  begin
                    rewrite(f2);
                    writeln(f2,i,' ',j,' ',l,' ',k);
                    maxarea:=l*k;
                  end;
              end;
        end;
end;

procedure output;
begin
 close(f2);
end;

begin
  init;
  solve;
  output;
end.