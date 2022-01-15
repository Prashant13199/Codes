declare
a number(5);
b number(5);
c number(5);
d number(5);
begin
a:=&a;
c:=0;
while a>0
loop
b:=mod(a,10);
c:=(c*10)+b;
a:=trunc(a/10);
end loop;
dbms_output.Put_line('reversed number = '||c);
end;
/
